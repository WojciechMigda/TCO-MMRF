/*******************************************************************************
 * Copyright (c) 2016 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: main.cpp
 *
 * Description:
 *      TCO-MMRF
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2016-12-21   wm              Initial version
 *
 ******************************************************************************/

#include "MMRF.hpp"

#include <boost/program_options.hpp>
#include <boost/any.hpp>

#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <array>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <random>
#include <cmath>
#include <unordered_set>

using size_type = std::size_t;

namespace
{


boost::program_options::variables_map
parse_options(int argc, char **argv)
{
    namespace po = boost::program_options;

    po::variables_map args;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("seed", po::value<int>()->default_value(1), "SEED for RNG")
        ("nfolds", po::value<int>()->default_value(3), "number of folds for cross-validation")

        ("xgboost_params", po::value<bool>()->default_value(false), "XGBoost: override model params")
        ("n_estimators", po::value<int>()->default_value(50), "XGBoost: number of estimators")
        ("booster", po::value<std::string>()->default_value("gbtree"), "XGBoost: booster")
        ("objective", po::value<std::string>()->default_value("rank:mmrf"), "XGBoost: objective")

        ("colsample_bytree", po::value<float>()->default_value(1.0f),
            "XGBoost: [gbtree] subsample ratio of columns when constructing each tree. range: (0,1].")
        ("scale_pos_weight", po::value<float>()->default_value(1.0f),
            "XGBoost: [gbtree] Control the balance of positive and negative weights, useful for unbalanced classes. A typical value to consider: sum(negative cases) / sum(positive cases).")
        ("learning_rate", po::value<float>()->default_value(0.3f),
            "XGBoost: [gbtree] step size shrinkage used in update to prevents overfitting. After each boosting step, we can directly get the weights of new features. and eta actually shrinks the feature weights to make the boosting process more conservative. range: [0,1]")
        ("subsample", po::value<float>()->default_value(1.0f),
            "XGBoost: [gbtree] subsample ratio of the training instance. Setting it to 0.5 means that XGBoost randomly collected half of the data instances to grow trees and this will prevent overfitting. range: (0,1].")
        ("min_child_weight", po::value<float>()->default_value(1.0f),
            "XGBoost: [gbtree] minimum sum of instance weight (hessian) needed in a child. If the tree partition step results in a leaf node with the sum of instance weight less than min_child_weight, then the building process will give up further partitioning. In linear regression mode, this simply corresponds to minimum number of instances needed to be in each node. The larger, the more conservative the algorithm will be. range: [0,∞]")
        ("max_depth", po::value<int>()->default_value(6),
            "XGBoost: [gbtree] maximum depth of a tree, increase this value will make the model more complex / likely to be overfitting. range: [1,∞]")
        ("num_pairsample", po::value<int>()->default_value(1), "XGBoost: num_pairsample")

        ("reg_lambda", po::value<float>()->default_value(0.0f),
            "XGBoost: [gblinear] L2 regularization term on weights, increase this value will make model more conservative.")
        ("reg_alpha", po::value<float>()->default_value(0.0f),
            "XGBoost: [gblinear] L1 regularization term on weights, increase this value will make model more conservative.")
        ("reg_lambda_bias", po::value<float>()->default_value(0.0f),
            "XGBoost: [gblinear] L2 regularization term on bias")
        ;
    try
    {
        po::store(po::parse_command_line(argc, argv, desc), args);
    }
    catch (po::error & ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch (boost::bad_any_cast & ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    po::notify(args);

    if (args.count("help"))
    {
        std::cerr << desc << "\n";
        std::exit(1);
    }

    return args;
}


std::vector<std::string>
read_file(const char * fname)
{
    std::ifstream fcsv(fname);
    std::vector<std::string> vcsv;

    for (std::string line; std::getline(fcsv, line); /* nop */)
    {
        vcsv.push_back(line);
    }
    fcsv.close();

    return vcsv;
}


double score(const std::vector<int> & rank, const std::vector<std::string> & po_vstr)
{
    double score = 0.0;
    double scale = 0.0;

    assert(rank.size() == po_vstr.size());
    const auto SZ = rank.size();

    std::vector<std::pair<int, int>> po_times;

    for (const auto & str : po_vstr)
    {
        int prog = -1;
        int obs = -1;

        const auto comma_pos = str.find(',');

        sscanf(str.c_str(), "%d", &prog);
        sscanf(str.c_str() + comma_pos + 1, "%d", &obs);

        po_times.emplace_back(prog, obs);
    }

    auto signum = [](int x){ return (x > 0) - (x < 0); };

    for (size_type iix{0}; iix < SZ; ++iix)
    {
        for (size_type jix{0}; jix < SZ; ++jix)
        {
            const double Rij = signum(rank[iix] - rank[jix]);
            double wij = 0.0;

            const auto ti = po_times[iix].first;
            const auto tj = po_times[jix].first;
            const auto ui = po_times[iix].second;
            const auto uj = po_times[jix].second;

            if (ti >= 0 && tj >= 0)
            {
                wij = ((double)ti - tj) / (ti + tj);
            }
            else if (tj >= 0 && ui >= 0)
            {
                if (ui > tj)
                {
                    wij = ((double)ui - tj) / (ui + tj);
                }
            }
            else if (ti >= 0 && uj >= 0)
            {
                if (uj > ti)
                {
                    wij = ((double)ti - uj) / (ti + uj);
                }
            }

            score += Rij * wij;
            scale += fabs(wij);
        }
    }

    if (scale > 0.0)
    {
        score /= scale;
    }

    return score;
}


bool verify(const std::vector<int> & y_hat, const int N)
{
    std::unordered_set<int> occurences;

    for (auto ix : y_hat)
    {
        if (ix < 1 || ix > N)
        {
            std::cerr << "[main] y_hat out of range: " << ix << std::endl;
            return false;
        }
        if (occurences.count(ix) != 0)
        {
            std::cerr << "[main] duplicated y_hat: " << ix << std::endl;
            return false;
        }
        occurences.insert(ix);
    }
    return true;
}


std::vector<int> shuffled_fold_indices(size_type const NROWS, int const SEED)
{
    std::vector<int> fold_indices(NROWS);
    std::iota(fold_indices.begin(), fold_indices.end(), 0);
    std::mt19937 g(SEED);
    std::shuffle(fold_indices.begin(), fold_indices.end(), g);

    return fold_indices;
}


std::vector<size_type> linspace(size_type MAX, size_type N)
{
    // numpy.linspace(0, MAX, N, endpoint=True)
    std::vector<size_type> ls(N);

    std::iota(ls.begin(), ls.end(), 0);
    std::transform(ls.begin(), ls.end(), ls.begin(), [&N, &MAX](size_type v){ return std::round((double)v * MAX / (N - 1)); });
    ls.back() = MAX;
    return ls;
}


std::vector<int> stratified_fold_indices(std::vector<std::string> const & vstr, size_type const NFOLDS, int const SEED)
{
    auto const NROWS = vstr.size();
    std::vector<int> prog; // samples with MM progress
    std::vector<int> noprog; // samples without MM progress

    for (size_type ix{0}; ix < NROWS; ++ix)
    {
        if (vstr[ix].find(',') < vstr[ix].find_first_of("0123456789"))
        {
            noprog.push_back(ix);
        }
        else
        {
            prog.push_back(ix);
        }
    }

    std::mt19937 g(SEED);
    std::shuffle(noprog.begin(), noprog.end(), g);
    std::shuffle(prog.begin(), prog.end(), g);


    auto all_ls = linspace(NROWS, NFOLDS + 1);
    auto prog_ls = linspace(prog.size(), NFOLDS + 1);
    decltype(prog_ls) noprog_ls(prog_ls.size());
    std::transform(all_ls.cbegin(), all_ls.cend(), prog_ls.cbegin(), noprog_ls.begin(),
        [](decltype(prog_ls)::value_type all, decltype(prog_ls)::value_type prog){ return all - prog;});

    std::vector<int> fold_indices;
    for (size_type ix {0}; ix < NFOLDS; ++ix)
    {
        std::copy(noprog.begin() + noprog_ls[ix], noprog.begin() + noprog_ls[ix + 1], std::back_inserter(fold_indices));
        std::copy(prog.begin() + prog_ls[ix], prog.begin() + prog_ls[ix + 1], std::back_inserter(fold_indices));
    }

    return fold_indices;
}


std::map<const std::string, const std::string>
build_xgb_params(boost::program_options::variables_map const & args)
{
    std::map<const std::string, const std::string> ret;

    if (args.at("xgboost_params").as<bool>())
    {
        ret.emplace("n_estimators", std::to_string(args.at("n_estimators").as<int>()));
        ret.emplace("booster", args.at("booster").as<std::string>());
        ret.emplace("objective", args.at("objective").as<std::string>());

        ret.emplace("colsample_bytree", std::to_string(args.at("colsample_bytree").as<float>()));
        ret.emplace("scale_pos_weight", std::to_string(args.at("scale_pos_weight").as<float>()));
        ret.emplace("learning_rate", std::to_string(args.at("learning_rate").as<float>()));
        ret.emplace("subsample", std::to_string(args.at("subsample").as<float>()));
        ret.emplace("min_child_weight", std::to_string(args.at("min_child_weight").as<float>()));
        ret.emplace("num_pairsample", std::to_string(args.at("num_pairsample").as<int>()));
        ret.emplace("max_depth", std::to_string(args.at("max_depth").as<int>()));

        ret.emplace("reg_lambda", std::to_string(args.at("reg_lambda").as<float>()));
        ret.emplace("reg_lambda_bias", std::to_string(args.at("reg_lambda_bias").as<float>()));
        ret.emplace("reg_alpha", std::to_string(args.at("reg_alpha").as<float>()));

        // hardcoded
        ret.emplace("silent", "1");
        ret.emplace("cache_opt", "0");
        ret.emplace("missing", "nan");
    }

    return ret;
}

}

////////////////////////////////////////////////////////////////////////////////

enum CHUNK_ID
{
    AVERAGES = 0,
    DIFFERENCES = 1,
    MUTATIONS = 2,
    PO_TIMES = 3
};


int main(int argc, char **argv)
{
    const auto args = parse_options(argc, argv);

    int const SEED = args.at("seed").as<int>();

    const char CPNUM_FNAME[] = "../data/copynumber_example.csv";
    const char EXPR_FNAME[] = "../data/expressions_example.csv";
    const char MUT_FNAME[] = "../data/mutations_example.csv";
    const char TRUTH_FNAME[] = "../data/groundtruth_example.csv";

    std::cerr << "[main] SEED: " << SEED << std::endl;
    std::cerr << "[main] Copynumber CSV: " << CPNUM_FNAME << std::endl;
    std::cerr << "[main] Expressions CSV: " << EXPR_FNAME << std::endl;
    std::cerr << "[main] Mutations CSV: " << MUT_FNAME << std::endl;
    std::cerr << "[main] Ground Truth CSV: " << TRUTH_FNAME << std::endl;

    std::array<std::vector<std::string>, 4> vstr;
    vstr[AVERAGES] = read_file(EXPR_FNAME);
    vstr[DIFFERENCES] = read_file(CPNUM_FNAME);
    vstr[MUTATIONS] = read_file(MUT_FNAME);
    vstr[PO_TIMES] = read_file(TRUTH_FNAME);

    std::cerr << "[main] Read " << vstr[PO_TIMES].size() << " lines\n";

    // extract first row with feature names
    std::array<std::string, 4> headers;
    headers[AVERAGES] = vstr[AVERAGES].front();
    vstr[AVERAGES].erase(vstr[AVERAGES].begin());
    headers[DIFFERENCES] = vstr[DIFFERENCES].front();
    vstr[DIFFERENCES].erase(vstr[DIFFERENCES].begin());
    headers[MUTATIONS] = vstr[MUTATIONS].front();
    vstr[MUTATIONS].erase(vstr[MUTATIONS].begin());
    headers[PO_TIMES] = vstr[PO_TIMES].front();
    vstr[PO_TIMES].erase(vstr[PO_TIMES].begin());

    size_type const NROWS = vstr[PO_TIMES].size();
    std::cerr << "[main] Input dataset has " << NROWS << " rows\n";

    ////////////////////////////////////////////////////////////////////////////

    const int NFOLDS = args.at("nfolds").as<int>();

    MMRF solver(build_xgb_params(args));

    //std::vector<float> CVscores(NFOLDS);

    //auto const fold_indices = shuffled_fold_indices(NROWS, SEED);
    auto const fold_indices = stratified_fold_indices(vstr[PO_TIMES], NFOLDS, SEED);

    const auto ls = linspace(NROWS, NFOLDS + 1);

    std::vector<double> scores;

    for (size_type fold{0}; fold < NFOLDS; ++fold)
    {
        std::array<std::vector<std::string>, 4> train_data;
        std::array<std::vector<std::string>, 4> test_data;
        std::vector<std::pair<int, int>> test_y;

        //std::cerr << "Test fold: [" << linspace[fold] << "," << linspace[fold + 1] << ")\n";
        for (size_type ix{0}; ix < NROWS; ++ix)
        {
            auto rix = fold_indices[ix];
            if (ix >= ls[fold] && ix < ls[fold + 1])
            {
                test_data[AVERAGES].push_back(vstr[AVERAGES][rix]);
                test_data[DIFFERENCES].push_back(vstr[DIFFERENCES][rix]);
                test_data[MUTATIONS].push_back(vstr[MUTATIONS][rix]);
                test_data[PO_TIMES].push_back(vstr[PO_TIMES][rix]);
            }
            else
            {
                train_data[AVERAGES].push_back(vstr[AVERAGES][rix]);
                train_data[DIFFERENCES].push_back(vstr[DIFFERENCES][rix]);
                train_data[MUTATIONS].push_back(vstr[MUTATIONS][rix]);
                train_data[PO_TIMES].push_back(vstr[PO_TIMES][rix]);
            }
        }

        std::cerr << "[main] Train data size: " << train_data[PO_TIMES].size() << std::endl;
        std::cerr << "[main] Test data size: " << test_data[PO_TIMES].size() << std::endl;

        // insert headers
        test_data[AVERAGES].insert(test_data[AVERAGES].begin(), headers[AVERAGES]);
        test_data[DIFFERENCES].insert(test_data[DIFFERENCES].begin(), headers[DIFFERENCES]);
        test_data[MUTATIONS].insert(test_data[MUTATIONS].begin(), headers[MUTATIONS]);

        train_data[AVERAGES].insert(train_data[AVERAGES].begin(), headers[AVERAGES]);
        train_data[DIFFERENCES].insert(train_data[DIFFERENCES].begin(), headers[DIFFERENCES]);
        train_data[MUTATIONS].insert(train_data[MUTATIONS].begin(), headers[MUTATIONS]);
        train_data[PO_TIMES].insert(train_data[PO_TIMES].begin(), headers[PO_TIMES]);

        solver.trainingData(
            MMRF::TEST_HOME,
            train_data[AVERAGES], train_data[DIFFERENCES], train_data[MUTATIONS], train_data[PO_TIMES]);
        const auto y_hat = solver.testingData(test_data[AVERAGES], test_data[DIFFERENCES], test_data[MUTATIONS]);
//        std::cerr << "[main] --- y_hat\n";
//        for (size_type ix{0}; ix < y_hat.size(); ++ix)
//        {
//            std::cerr << y_hat[ix] << ", " << test_data[PO_TIMES][ix] << std::endl;
//        }

        assert(verify(y_hat, NROWS));
        const auto SCORE = score(y_hat, test_data[PO_TIMES]);
        std::cerr << "[main] SCORE[" << fold + 1 << "/" << NFOLDS << "]: " << SCORE << std::endl;

        scores.push_back(SCORE);
    }

    const auto SCORE = std::accumulate(scores.cbegin(), scores.cend(), 0.) / scores.size();

    std::cerr << "\n[main] Final SCORE: " << 1e6 * std::max(SCORE, 0.) << std::endl;
    std::cout << 1e6 * SCORE << std::endl;

    return 0;
}

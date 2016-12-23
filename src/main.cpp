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
            std::cout << "[main] y_hat out of range: " << ix << std::endl;
            return false;
        }
        if (occurences.count(ix) != 0)
        {
            std::cout << "[main] duplicated y_hat: " << ix << std::endl;
            return false;
        }
        occurences.insert(ix);
    }
    return true;
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
    int const SEED = (argc == 2 ? std::atoi(argv[1]) : 1);
    const char CPNUM_FNAME[] = "../data/copynumber_example.csv";
    const char EXPR_FNAME[] = "../data/expressions_example.csv";
    const char MUT_FNAME[] = "../data/mutations_example.csv";
    const char TRUTH_FNAME[] = "../data/groundtruth_example.csv";

    std::cout << "[main] SEED: " << SEED << std::endl;
    std::cout << "[main] Copynumber CSV: " << CPNUM_FNAME << std::endl;
    std::cout << "[main] Expressions CSV: " << EXPR_FNAME << std::endl;
    std::cout << "[main] Mutations CSV: " << MUT_FNAME << std::endl;
    std::cout << "[main] Ground Truth CSV: " << TRUTH_FNAME << std::endl;

    std::array<std::vector<std::string>, 4> vstr;
    vstr[AVERAGES] = read_file(EXPR_FNAME);
    vstr[DIFFERENCES] = read_file(CPNUM_FNAME);
    vstr[MUTATIONS] = read_file(MUT_FNAME);
    vstr[PO_TIMES] = read_file(TRUTH_FNAME);

    std::cout << "[main] Read " << vstr[PO_TIMES].size() << " lines\n";

    // for train data skip first row with feature names
    for (auto & chunk : vstr)
    {
        chunk.erase(chunk.begin());
    }

    size_type const NROWS = vstr[PO_TIMES].size();
    std::cout << "[main] Input dataset has " << NROWS << " rows\n";

    ////////////////////////////////////////////////////////////////////////////

    constexpr int NFOLDS{5};

    MMRF solver;

    std::vector<float> CVscores(NFOLDS);

    std::vector<int> fold_indices(NROWS);
    std::iota(fold_indices.begin(), fold_indices.end(), 0);
    std::mt19937 g(SEED);
    std::shuffle(fold_indices.begin(), fold_indices.end(), g);

    std::array<size_type, NFOLDS + 1> linspace;
    std::iota(linspace.begin(), linspace.end(), 0);
    std::transform(linspace.begin(), linspace.end(), linspace.begin(), [&NFOLDS, &NROWS](size_type v){ return std::round((double)v * NROWS / NFOLDS); });
    linspace.back() = NROWS;

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
            if (ix >= linspace[fold] && ix < linspace[fold + 1])
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

        solver.trainingData(
            MMRF::TEST_HOME,
            train_data[AVERAGES], train_data[DIFFERENCES], train_data[MUTATIONS], train_data[PO_TIMES]);
        const auto y_hat = solver.testingData(test_data[AVERAGES], test_data[DIFFERENCES], test_data[MUTATIONS]);

        assert(verify(y_hat, NROWS));
        const auto SCORE = score(y_hat, test_data[PO_TIMES]);
        std::cout << "[main] SCORE[" << fold + 1 << "]: " << SCORE << std::endl;

        scores.push_back(SCORE);
    }

    const auto SCORE = std::accumulate(scores.cbegin(), scores.cend(), 0.) / scores.size();

    std::cout << "\n[main] Final SCORE: " << 1e6 * std::max(SCORE, 0.) << std::endl;

    return 0;
}

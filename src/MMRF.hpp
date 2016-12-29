/*******************************************************************************
 * Copyright (c) 2016 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: MMRF.hpp
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


#ifndef MMRF_HPP_
#define MMRF_HPP_

#include "num.hpp"
#include "array2d.hpp"
#include "param_store.hpp"

#include "xgboost/c_api.h"

#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <utility>
#include <cctype>
#include <cmath>
#include <cstring>
#include <memory>
#include <iterator>


using real_type = float;
using array_type = num::array2d<real_type>;

using size_type = std::size_t;

constexpr float MISSING{NAN};
constexpr float XGB_MISSING{NAN};


/*
 * Wrapper which returns DMatrixHandle directly and not through out param
 */
DMatrixHandle XGDMatrixCreateFromMat(
    const float *data,
    bst_ulong nrow,
    bst_ulong ncol,
    float missing)
{
    DMatrixHandle dmat{nullptr};

    XGDMatrixCreateFromMat(data, nrow, ncol, missing, &dmat);

    return dmat;
}

/*
 * Wrapper which returns BoosterHandle directly and not through out param
 */
BoosterHandle XGBoosterCreate(const DMatrixHandle dmats[], bst_ulong len)
{
    BoosterHandle booster{nullptr};

    XGBoosterCreate(dmats, len, &booster);

    return booster;
}

namespace XGB
{

template<typename _StopCondition>
std::unique_ptr<void, int (*)(BoosterHandle)>
fit(const array_type & train_data,
    const std::vector<float> & train_y,
    const std::map<const std::string, const std::string> & params,
    _StopCondition stop_condition)
{
    // prepare placeholder for raw matrix later used by xgboost
    std::vector<float> train_vec = train_data.tovector();
    std::cerr << "[MMRF] train_vec size: " << train_vec.size() << std::endl;
//    assert(std::none_of(train_vec.cbegin(), train_vec.cend(), [](float x){return std::isnan(x);}));

    std::unique_ptr<void, int (*)(DMatrixHandle)> tr_dmat(
        XGDMatrixCreateFromMat(
            train_vec.data(),
            train_data.shape().first,
            train_data.shape().second, XGB_MISSING),
        XGDMatrixFree);

    // attach response vector to tr_dmat
    XGDMatrixSetFloatInfo(tr_dmat.get(), "label", train_y.data(), train_y.size());

    const DMatrixHandle cache[] = {tr_dmat.get()};

    // create Booster with attached tr_dmat
    std::unique_ptr<void, int (*)(BoosterHandle)> booster(
            XGBoosterCreate(cache, 1UL),
            XGBoosterFree);

    for (const auto & kv : params)
    {
        std::cerr << kv.first << " => " << kv.second << std::endl;
        XGBoosterSetParam(booster.get(), kv.first.c_str(), kv.second.c_str());
    }


    for (int iter{0}; stop_condition() == false; ++iter)
    {
        XGBoosterUpdateOneIter(booster.get(), iter, tr_dmat.get());
    }

    return booster;
}


std::vector<float>
predict(
    BoosterHandle booster,
    const array_type & test_data)
{
    std::vector<float> test_vec = test_data.tovector();
    std::cerr << "test_vec size: " << test_vec.size() << std::endl;

    std::unique_ptr<void, int (*)(DMatrixHandle)> te_dmat(
        XGDMatrixCreateFromMat(
            test_vec.data(),
            test_data.shape().first,
            test_data.shape().second, XGB_MISSING),
        XGDMatrixFree);

    bst_ulong y_hat_len{0};
    const float * y_hat_proba{nullptr};
    XGBoosterPredict(booster, te_dmat.get(), 0, 0, &y_hat_len, &y_hat_proba);
    std::cerr << "Got y_hat_proba of length " << y_hat_len << std::endl;

    std::vector<float> y_hat(y_hat_proba, y_hat_proba + y_hat_len);

    return y_hat;
}

}


/*
 * Competition mandated class
 */
struct MMRF
{
    enum test_type
    {
        TEST_EXAMPLE = 0,
        TEST_PROVISIONAL = 1,
        TEST_SYSTEM = 2,
        TEST_HOME = 3
    };

    MMRF() = default;

    explicit MMRF(std::map<const std::string, const std::string> && xgb_params)
    {
        m_xgb_params = std::move(xgb_params);
    }

    int trainingData(
        int test_type,
        std::vector<std::string> & expr_avg,
        std::vector<std::string> & expr_diff,
        std::vector<std::string> & mutation,
        std::vector<std::string> & prog_obs_time);

    std::vector<int> testingData(
        std::vector<std::string> & expr_avg,
        std::vector<std::string> & expr_diff,
        std::vector<std::string> & mutation);

    int trainingData(
        int test_type,
        std::vector<std::string> && expr_avg,
        std::vector<std::string> && expr_diff,
        std::vector<std::string> && mutation,
        std::vector<std::string> && prog_obs_time);

    std::vector<int> testingData(
        std::vector<std::string> && expr_avg,
        std::vector<std::string> && expr_diff,
        std::vector<std::string> && mutation);


    enum test_type m_test_type;
    std::vector<std::string> m_expr_avg;
    std::vector<std::string> m_expr_diff;
    std::vector<std::string> m_mutation;
    std::vector<std::string> m_prog_obs_time;
    std::map<const std::string, const std::string> m_xgb_params;
};

#include <sys/time.h>
long int timestamp()
{
    timeval tv;
    gettimeofday(&tv, NULL);

    return tv.tv_sec;// + tv.tv_usec / 1e6;
}


int MMRF::trainingData(
    int test_type,
    std::vector<std::string> & expr_avg,
    std::vector<std::string> & expr_diff,
    std::vector<std::string> & mutation,
    std::vector<std::string> & prog_obs_time)
{
    return trainingData(
        test_type,
        std::move(expr_avg),
        std::move(expr_diff),
        std::move(mutation),
        std::move(prog_obs_time)
    );
}

std::vector<int> MMRF::testingData(
    std::vector<std::string> & expr_avg,
    std::vector<std::string> & expr_diff,
    std::vector<std::string> & mutation)
{
    return testingData(
        std::move(expr_avg),
        std::move(expr_diff),
        std::move(mutation)
    );
}


int MMRF::trainingData(
    int test_type,
    std::vector<std::string> && expr_avg,
    std::vector<std::string> && expr_diff,
    std::vector<std::string> && mutation,
    std::vector<std::string> && prog_obs_time)
{
    m_test_type = static_cast<enum test_type>(test_type);
    m_expr_avg = std::move(expr_avg);
    m_expr_diff = std::move(expr_diff);
    m_mutation = std::move(mutation);
    m_prog_obs_time = std::move(prog_obs_time);

    return 0;
}

std::vector<std::string>
merge_chunks(std::vector<std::string> && avg, std::vector<std::string> && diff, std::vector<std::string> && mut)
{
    std::vector<std::string> vstr = std::move(avg);

    auto const NROWS = vstr.size();

    for (size_type ix{0}; ix < NROWS; ++ix)
    {
        vstr[ix] += ',' + std::move(diff[ix]) + ',' + std::move(mut[ix]);
    }

    return vstr;
}

auto maybe_real_xlt = [](const char * str) -> real_type
{
    const auto SZ = strlen(str);

    if (SZ == 0)
    {
        return MISSING;
    }
    else
    {
        return
            (std::all_of(str, str + SZ, [](char c){ return std::isblank(c);})
                ? MISSING
                : strtod(str, nullptr));
    }
};


std::vector<float> encode_response(std::vector<std::string> && vstr)
{
    const auto NROWS = vstr.size();

    std::vector<float> resp(NROWS);

    using pair_type = std::pair<int, int>;
    std::vector<pair_type> po_times;
    po_times.reserve(NROWS);

    for (const auto & str : vstr)
    {
        int prog = -1;
        int obs = -1;

        const auto comma_pos = str.find(',');

        sscanf(str.c_str(), "%d", &prog);
        sscanf(str.c_str() + comma_pos + 1, "%d", &obs);

        po_times.emplace_back(prog, obs);
    }

    std::transform(po_times.cbegin(), po_times.cend(), resp.begin(),
        [](const pair_type & pair) -> float
        {
            if (pair.first != -1)
            {
                return -(2 * pair.first);
            }
            else if (pair.second != -1)
            {
                return -(2 * pair.second + 1);
            }
            else
            {
                return -1;
            }
        });

    return resp;
}


template<typename Iterator>
std::vector<size_type>
run_rank_estimators(
    const Iterator begin,
    const Iterator end,
    const long int time0,
    const long int MAX_TIME,
    const array_type & train_data,
    const std::vector<float> & train_y,
    const array_type & test_data)
{
    constexpr int   TIME_MARGIN{10};
    const int       MAX_TIMESTAMP = time0 + MAX_TIME - TIME_MARGIN;

    std::cerr << std::endl << "[MMRF] Training " << std::distance(begin, end) << " estimator(s)" << std::endl;
    std::cerr << "[MMRF] Total time limit: " << MAX_TIME << " secs" << std::endl;

    // collection of probabilities predicted by each estimator
    std::vector<std::vector<float>> y_hat_proba_set;

    for (auto it = begin; it != end; ++it)
    {
        const auto & PARAMS_p = *it;

        const int MAX_ITER = std::stoi(PARAMS_p->at("n_estimators"));
        int iter{0};

        auto booster = XGB::fit(train_data, train_y, *PARAMS_p,
            [&iter, MAX_ITER, MAX_TIMESTAMP]() -> bool
            {
                const bool running = (iter < MAX_ITER) && (timestamp() < MAX_TIMESTAMP);
                ++iter;
                return running == false;
            }
        );

        if (iter <= MAX_ITER)
        {
            // time exceeded
            std::cerr << "[MMRF] Exceeded allocated time limit after iteration " << iter << " of " << MAX_ITER << " for estimator [" << y_hat_proba_set.size() + 1 << "]" << std::endl;

            // but we'll make the prediction anyway if it's our first estimator :)
            if (y_hat_proba_set.size() == 0)
            {
                y_hat_proba_set.push_back(XGB::predict(booster.get(), test_data));
            }
            break;
        }

        auto proba = XGB::predict(booster.get(), test_data);

        y_hat_proba_set.push_back(proba);

        std::cerr << "[MMRF] Elapsed time: " << timestamp() - time0 << std::endl;
    }

    // array of propabilities accumulated from completed estimators
    std::vector<float> y_hat_proba_cumm(test_data.shape().first, 0.);

    for (size_type idx{0}; idx < y_hat_proba_set.size(); ++idx)
    {
        std::transform(y_hat_proba_set[idx].cbegin(), y_hat_proba_set[idx].cend(), y_hat_proba_cumm.begin(),
            y_hat_proba_cumm.begin(),
            [](const float x, const float a)
            {
                return a + x;
            });
    }

    // zip accumulated probabilities with rank indices
    std::vector<std::pair<float, size_type>> zipped;
    for (size_type ix{0}; ix < y_hat_proba_cumm.size(); ++ix)
    {
        zipped.emplace_back(y_hat_proba_cumm[ix], ix + 1);
    }
    qsort(zipped.data(), zipped.size(), sizeof (zipped.front()),
        [](const void * avp, const void * bvp)
        {
            auto ap = static_cast<const std::pair<float, size_type> *>(avp);
            auto bp = static_cast<const std::pair<float, size_type> *>(bvp);

            // descending order
            //return (ap->first > bp->first) - (ap->first < bp->first);
            // ascending order
            return (ap->first < bp->first) - (ap->first > bp->first);
        });

    // unzip index into y_hat
    std::vector<size_type> y_hat(test_data.shape().first);

    std::transform(zipped.cbegin(), zipped.cend(), y_hat.begin(),
        [](const std::pair<float, size_type> & p)
        {
            return p.second;
        });

    return y_hat;
}


std::vector<int> MMRF::testingData(
    std::vector<std::string> && i_expr_avg,
    std::vector<std::string> && i_expr_diff,
    std::vector<std::string> && i_mutation)
{
    const auto time0 = timestamp();

    // merge chunks
    auto train_vstr = merge_chunks(std::move(m_expr_avg), std::move(m_expr_diff), std::move(m_mutation));
    auto test_vstr = merge_chunks(std::move(i_expr_avg), std::move(i_expr_diff), std::move(i_mutation));

    m_prog_obs_time.erase(m_prog_obs_time.begin());
    train_vstr.erase(train_vstr.begin());
    test_vstr.erase(test_vstr.begin());

    using loadtxtCfg = num::loadtxtCfg<real_type>;
    const array_type i_train_data =
        num::loadtxt(
            std::move(train_vstr),
            std::move(
                num::loadtxtCfg<real_type>()
                .delimiter(',')
                .converters(loadtxtCfg::converters_type{{loadtxtCfg::GLOBAL_CONVERTER, maybe_real_xlt}})
            )
        );

    const array_type i_test_data =
        num::loadtxt(
            std::move(test_vstr),
            std::move(
                num::loadtxtCfg<real_type>()
                .delimiter(',')
                .converters(loadtxtCfg::converters_type{{loadtxtCfg::GLOBAL_CONVERTER, maybe_real_xlt}})
            )
        );

    std::cerr << "[MMRF] Train data shape " << i_train_data.shape() << std::endl;
    std::cerr << "[MMRF] Test data shape "<< i_test_data.shape() << std::endl;
    std::cerr << "[MMRF] It took " << timestamp() - time0 << " secs to parse text\n";

    std::vector<float> train_y = encode_response(std::move(m_prog_obs_time));

    // placeholder for any feature engineering: i_data -> data
    array_type train_data = std::move(i_train_data);
    array_type test_data = std::move(i_test_data);

    const long int MAX_TIMES[] =
        {
            [MMRF::TEST_EXAMPLE] = 2 * 60,
            [MMRF::TEST_PROVISIONAL] = 3 * 60,
            [MMRF::TEST_SYSTEM] = 4 * 60,
            [MMRF::TEST_HOME] = 20 * 60,
        };

    const std::map<const std::string, const std::string> * BUILTIN_PARAMS_SET[] = {&params::sub01};
    const std::map<const std::string, const std::string> * USER_PARAMS_SET[] = {&m_xgb_params};
    bool const use_user_params = m_xgb_params.size() != 0;

    const auto y_hat = run_rank_estimators(
        use_user_params ? std::begin(USER_PARAMS_SET) : std::begin(BUILTIN_PARAMS_SET),
        use_user_params ? std::end(USER_PARAMS_SET) : std::end(BUILTIN_PARAMS_SET),
        time0, MAX_TIMES[m_test_type], train_data, train_y, test_data);

    ////////////////////////////////////////////////////////////////////////////

    std::vector<int> ranks;

    std::transform(y_hat.cbegin(), y_hat.cend(), std::back_inserter(ranks), [](const size_type sz) -> int { return sz; });

    return ranks;
}



#endif /* MMRF_HPP_ */

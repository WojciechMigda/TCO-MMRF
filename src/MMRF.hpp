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

#include "xgboost/c_api.h"

#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <utility>
#include <cctype>
#include <cmath>
#include <cstring>


using real_type = float;
using array_type = num::array2d<real_type>;

using size_type = std::size_t;

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


    std::vector<std::string> m_expr_avg;
    std::vector<std::string> m_expr_diff;
    std::vector<std::string> m_mutation;
    std::vector<std::string> m_prog_obs_time;
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
    m_expr_avg = std::move(expr_avg);
    m_expr_diff = std::move(expr_diff);
    m_mutation = std::move(mutation);
    m_prog_obs_time = std::move(prog_obs_time);

    return 0;
}

constexpr float MISSING{NAN};
constexpr float XGB_MISSING{NAN};

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
        [](const pair_type & pair)
        {
            union
            {
                uint16_t pair[2];
                float f;
            } pack;
            // paranoid assertions for this to work
            static_assert(sizeof (pack) == 4, "What is happening here?");
            static_assert(((char *)&pack.pair[1] - (char *)&pack.pair[0]) == 2, "What is happening here?");

            pack.pair[0] = pair.first;
            pack.pair[1] = pair.second;

            return pack.f;
        });

    return resp;
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

    std::cout << "[MMRF] Train data shape " << i_train_data.shape() << std::endl;
    std::cout << "[MMRF] Test data shape "<< i_test_data.shape() << std::endl;
    std::cout << "[MMRF] It took " << timestamp() - time0 << " secs to parse text\n";

    std::vector<float> train_y = encode_response(std::move(m_prog_obs_time));

    // placeholder for any feature engineering: i_data -> data
    array_type train_data = std::move(i_train_data);
    array_type test_data = std::move(i_test_data);

//    const std::map<const std::string, const std::string> * PARAMS_SET[] = {/*&params::no::prov47*/};
//
//    const auto y_hat = run_rank_estimators(
//        std::begin(PARAMS_SET), std::end(PARAMS_SET),
//            time0, train_data, train_y, test_data);

    ////////////////////////////////////////////////////////////////////////////

    std::vector<int> ranks;

    ranks.resize(test_vstr.size());
    std::iota(ranks.begin(), ranks.end(), 1);

    return ranks;
}



#endif /* MMRF_HPP_ */

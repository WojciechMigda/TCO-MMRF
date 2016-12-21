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

#include <string>
#include <vector>
#include <algorithm>

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
};

int MMRF::trainingData(
    int test_type,
    std::vector<std::string> & expr_avg,
    std::vector<std::string> & expr_diff,
    std::vector<std::string> & mutation,
    std::vector<std::string> & prog_obs_time)
{
    return 0;
}

std::vector<int> MMRF::testingData(
    std::vector<std::string> & expr_avg,
    std::vector<std::string> & expr_diff,
    std::vector<std::string> & mutation)
{
    std::vector<int> ranks;

    ranks.resize(expr_avg.size());
    std::iota(ranks.begin(), ranks.end(), 1);

    return ranks;
}

#endif /* MMRF_HPP_ */

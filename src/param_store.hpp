/*******************************************************************************
 * Copyright (c) 2016 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: param_store.hpp
 *
 * Description:
 *      Database of parameter sets of the XGBoost estimators
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2016-12-23   wm              Initial version
 *
 ******************************************************************************/


#ifndef PARAM_STORE_HPP_
#define PARAM_STORE_HPP_

#include <map>
#include <string>

namespace params
{


const std::map<const std::string, const std::string> sub01
{
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    {"objective", "rank:pairwise"},

    {"n_estimators", "50"},
    {"reg_alpha", "0"},
    {"colsample_bytree", "0.46035362112038597"},
    {"colsample_bylevel", "1"},
    {"scale_pos_weight", "0.38570090801277784"},
    {"learning_rate", "0.045"},
    {"max_delta_step", "0"},
    {"base_score", "0.5"},
    {"subsample", "0.8723920700026842"},
    {"reg_lambda", "1"},
    {"min_child_weight", "1"},
    {"num_pairsample", "61"},

    {"max_depth", "6"},
};



}  // namespace params


#endif /* PARAM_STORE_HPP_ */

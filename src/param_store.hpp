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

const std::map<const std::string, const std::string> p487427
{
    // reduced, gbtree, log 4
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    {"objective", "rank:mmrf"},
    {"learning_rate", "0.045"},

    {"n_estimators", "1450"},
    {"colsample_bytree", "0.5695947846708151"},
    {"subsample", "0.6224407088745174"},
    {"min_child_weight", "7"},
    {"max_depth", "8"},
};

const std::map<const std::string, const std::string> p474499
{
    // reduced, gbtree, log 4
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    {"objective", "rank:mmrf"},
    {"learning_rate", "0.045"},

    {"n_estimators", "1350"},
    {"colsample_bytree", "0.3650062059202914"},
    {"subsample", "0.8049900350194208"},
    {"min_child_weight", "8"},
    {"max_depth", "6"},
};

const std::map<const std::string, const std::string> p473309
{
    // reduced, gbtree, log 4
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    {"objective", "rank:mmrf"},
    {"learning_rate", "0.045"},

    {"n_estimators", "1550"},
    {"colsample_bytree", "0.8867598973496681"},
    {"subsample", "0.6951107645231182"},
    {"min_child_weight", "4"},
    {"max_depth", "7"},
};

const std::map<const std::string, const std::string> p471278
{
    // reduced, gbtree, log 4
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    {"objective", "rank:mmrf"},
    {"learning_rate", "0.045"},

    {"n_estimators", "1425"},
    {"colsample_bytree", "0.3022991243094779"},
    {"subsample", "0.7569095600459079"},
    {"min_child_weight", "7"},
    {"max_depth", "7"},
};

const std::map<const std::string, const std::string> p468236
{
    // reduced, gbtree, log 4
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    {"objective", "rank:mmrf"},
    {"learning_rate", "0.045"},

    {"n_estimators", "1500"},
    {"colsample_bytree", "0.3030973568933607"},
    {"subsample", "0.567424015678082"},
    {"min_child_weight", "14"},
    {"max_depth", "2"},
};

const std::map<const std::string, const std::string> p467633
{
    // reduced, gbtree, log 3
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    {"objective", "rank:mmrf"},
    {"learning_rate", "0.045"},

    {"n_estimators", "1275"},
    {"colsample_bytree", "0.7395611926146516"},
    {"subsample", "0.6249785521380649"},
    {"min_child_weight", "9"},
    {"max_depth", "5"},
};

const std::map<const std::string, const std::string> p466087
{
    // reduced, gbtree, log 3
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    {"objective", "rank:mmrf"},
    {"learning_rate", "0.045"},

    {"n_estimators", "900"},
    {"colsample_bytree", "0.7325060841092922"},
    {"subsample", "0.5406833896055423"},
    {"min_child_weight", "7"},
    {"max_depth", "7"},
};

const std::map<const std::string, const std::string> p463737
{
    // reduced, gbtree, log 3
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    {"objective", "rank:mmrf"},
    {"learning_rate", "0.045"},

    {"n_estimators", "950"},
    {"colsample_bytree", "0.41090454762036704"},
    {"subsample", "0.6460306760081187"},
    {"min_child_weight", "14"},
    {"max_depth", "5"},
};


////////////////////////////////////////////////////////////////////////////////

const std::map<const std::string, const std::string> subxx
{
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    //{"objective", "rank:pairwise"},
    {"objective", "rank:mmrf"},

    {"n_estimators", "235"},
    {"reg_alpha", "0"},
    {"colsample_bytree", "0.887023367906893"},
    {"colsample_bylevel", "1"},
    {"learning_rate", "0.045"},
    {"max_delta_step", "0"},
    {"base_score", "0.5"},
    {"subsample", "0.35658872517104523"},
    {"reg_lambda", "1"},
    {"min_child_weight", "23"},

    {"max_depth", "4"},
};

const std::map<const std::string, const std::string> sub01
{
    {"missing", "nan"},
    {"seed", "0"},
    {"silent", "1"},
    {"cache_opt", "0"},

    {"booster", "gbtree"},
    {"objective", "rank:mmrf"},

    {"n_estimators", "95"},
    {"reg_alpha", "0."},
    //{"colsample_bytree", "0.36915845533198666"},
    {"colsample_bytree", "0.369158"},
    //{"colsample_bylevel", "1"},
    {"scale_pos_weight", "1."},
    {"learning_rate", "0.012"},
    //{"max_delta_step", "0"},
    //{"base_score", "0.5"},
    //{"subsample", "0.47132337425305915"},
    {"subsample", "0.471323"},
    {"reg_lambda", "0."},
    {"min_child_weight", "30"},

    {"max_depth", "1"},
};

}  // namespace params


#endif /* PARAM_STORE_HPP_ */

#define TCO_XGB
#define DMLC_ENABLE_STD_THREAD 0

#pragma GCC optimize ( "-O2" )

#include "../xgboost/src/c_api/c_api.cc"
#include "../xgboost/src/data/simple_csr_source.cc"
#include "../xgboost/dmlc-core/src/data.cc"
#include "../xgboost/src/data/data.cc"
#include "../xgboost/src/logging.cc"
#include "../xgboost/rabit/src/c_api.cc"
#include "../xgboost/rabit/src/engine.cc"
#include "../xgboost/rabit/src/allreduce_base.cc"
#include "../xgboost/rabit/src/allreduce_robust.cc"
#include "../xgboost/src/c_api/c_api_error.cc"
#include "../xgboost/dmlc-core/src/io.cc"
#include "../xgboost/dmlc-core/src/io/local_filesys.cc"
#include "../xgboost/src/learner.cc"
#include "../xgboost/src/objective/objective.cc"
#include "../xgboost/dmlc-core/src/io/input_split_base.cc"
#include "../xgboost/src/common/common.cc"
#include "../xgboost/src/gbm/gbm.cc"
#include "../xgboost/dmlc-core/src/io/recordio_split.cc"
#include "../xgboost/src/metric/metric.cc"
#include "../xgboost/src/data/simple_dmatrix.cc"
#include "../xgboost/dmlc-core/src/io/line_split.cc"
#include "../xgboost/src/objective/regression_obj.cc"
#include "../xgboost/src/objective/multiclass_obj.cc"
#include "../xgboost/src/metric/elementwise_metric.cc"
#include "../xgboost/src/metric/multiclass_metric.cc"
#include "../xgboost/src/metric/rank_metric.cc"
#include "../xgboost/src/gbm/gbtree.cc"
#include "../xgboost/src/gbm/gblinear.cc"
#include "../xgboost/src/data/sparse_page_raw_format.cc"
#include "../xgboost/src/objective/rank_obj.cc"
#include "../xgboost/src/tree/tree_updater.cc"
#include "../xgboost/src/tree/updater_histmaker.cc"
#include "../xgboost/src/tree/updater_colmaker.cc"
#include "../xgboost/src/tree/updater_skmaker.cc"
#include "../xgboost/src/tree/updater_prune.cc"
#include "../xgboost/src/tree/updater_refresh.cc"
#include "../xgboost/src/tree/updater_sync.cc"
#include "../xgboost/src/tree/tree_model.cc"

#include "MMRF.hpp"

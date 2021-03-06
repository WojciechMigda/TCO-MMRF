################################################################################
project( "TCO-MMRF" C CXX )

cmake_minimum_required( VERSION 2.8.3 )

set( CMAKE_ECLIPSE_VERSION 3.8 )
set( _ECLIPSE_VERSION 3.8 )

set( CMAKE_CXX_COMPILER_ARG1 -std=c++11 ) ### for Eclipse's discovery extra arguments


add_definitions( -DTCO_XGB -DDMLC_ENABLE_STD_THREAD=0 )

#add_definitions( -O0 -ggdb -std=c++11 -Wall -pedantic )
#add_definitions( -O2 -ggdb -std=c++11 -Wall -pedantic -mmmx -msse -msse2 -msse3 -s -pipe -Wno-sign-compare -march=native )
add_definitions( -O2 -unroll-loops -std=c++11 -Wall -pedantic -mmmx -msse -msse2 -msse3 -s -pipe -Wno-sign-compare -march=native )

################################################################################

#find_package( Boost REQUIRED COMPONENTS program_options )

################################################################################

include_directories(
    cpplinq/CppLinq
    src
    xgboost/include
    xgboost/dmlc-core/include
    xgboost/rabit/include
    ${Boost_INCLUDE_DIR}
)

################################################################################

add_library( parse_csv
    src/parse_csv.cpp
)
get_property( parse_csv_flags TARGET parse_csv PROPERTY COMPILE_FLAGS )
set_target_properties( parse_csv PROPERTIES COMPILE_FLAGS "${parse_csv_flags} -O3 -DNDEBUG -g0 -march=native -std=c++11 -unroll-loops" )

add_executable( main
    src/main.cpp

    xgboost/src/c_api/c_api.cc
    xgboost/src/data/simple_csr_source.cc
    xgboost/src/data/data.cc
    xgboost/src/logging.cc
    xgboost/rabit/src/c_api.cc
    xgboost/rabit/src/engine.cc
    xgboost/rabit/src/allreduce_base.cc
    xgboost/rabit/src/allreduce_robust.cc
    xgboost/src/c_api/c_api_error.cc
    # xgboost/dmlc-core/src/io.cc
    # xgboost/dmlc-core/src/io/local_filesys.cc
    xgboost/src/learner.cc
    xgboost/src/objective/objective.cc
    # xgboost/dmlc-core/src/io/input_split_base.cc
    xgboost/src/common/common.cc
    xgboost/src/gbm/gbm.cc
    # xgboost/dmlc-core/src/io/recordio_split.cc
    xgboost/src/metric/metric.cc
    xgboost/src/data/simple_dmatrix.cc
    # xgboost/dmlc-core/src/data.cc
    # xgboost/dmlc-core/src/io/line_split.cc
    xgboost/src/objective/regression_obj.cc
    xgboost/src/objective/multiclass_obj.cc
    xgboost/src/metric/elementwise_metric.cc
    xgboost/src/metric/multiclass_metric.cc
    xgboost/src/metric/rank_metric.cc
    xgboost/src/gbm/gbtree.cc
    xgboost/src/gbm/gblinear.cc
    xgboost/src/data/sparse_page_raw_format.cc
    xgboost/src/objective/rank_obj.cc
    xgboost/src/tree/tree_updater.cc
    xgboost/src/tree/updater_histmaker.cc
    xgboost/src/tree/updater_colmaker.cc
    xgboost/src/tree/updater_skmaker.cc
    xgboost/src/tree/updater_prune.cc
    xgboost/src/tree/updater_refresh.cc
    xgboost/src/tree/updater_sync.cc
    xgboost/src/tree/tree_model.cc
)


#target_link_libraries( main ${Boost_LIBRARIES} )
target_link_libraries( main boost_program_options )

################################################################################

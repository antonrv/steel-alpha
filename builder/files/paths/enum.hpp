#ifndef STEEL_COMPILER_STATE_KEY_PATH_ENUM_HPP
#define STEEL_COMPILER_STATE_KEY_PATH_ENUM_HPP

#include "common/fun_sequences_std17.hpp"

ENUM_DEFINITION( bld, path_require, exist, create, create_force, none )
ENUM_DEFINITION( bld, path_scan, recurse, flat)

#define RUNTIME_MODULE_PATHS \
steel_runtime_modules_ctxt,\
steel_runtime_modules_dep,\
steel_runtime_modules_instrument,\
steel_runtime_modules_policy,\
steel_runtime_modules_safe,\
steel_runtime_modules_task,\
steel_runtime_modules_util,\
steel_runtime_modules_work

#define KEYPATHS \
pwd,\
user_include,\
steel_root,\
steel_builder,\
steel_runtime,\
RUNTIME_MODULE_PATHS, \
steel_runtime_include,\
steel_runtime_test,\
steel_runtime_test_case,\
steel_runtime_instrument,\
steel_builder_test,\
steel_builder_test_suite,\
steel_builder_test_suite_ref,\
steel_builder_test_suite_ref_inspect,\
steel_builder_test_suite_ref_translate,\
steel_builder_test_suite_ref_autogen,\
build_root,\
build_std,\
build_runtime,\
build_runtime_precomp,\
build_runtime_precomp_ctxt,\
build_runtime_precomp_data,\
build_runtime_precomp_dep,\
build_runtime_precomp_instrument,\
build_runtime_precomp_policy,\
build_runtime_precomp_safe,\
build_runtime_precomp_task,\
build_runtime_precomp_util,\
build_runtime_precomp_work,\
build_runtime_gen,\
build_runtime_test,\
build_runtime_test_case,\
build_runtime_test_case_inspect,\
build_runtime_test_case_translate,\
build_runtime_test_case_autogen,\
build_runtime_test_case_precomp,\
build_runtime_test_case_run,\
build_builder_test,\
build_builder_test_suite,\
build_builder_test_suite_inspect,\
build_builder_test_suite_translate,\
build_builder_test_suite_autogen,\
build_app,\
build_app_inspect,\
build_app_translate,\
build_app_autogen,\
build_app_precomp,\
build_app_run,\
build_plat,\
build_plat_autogen,\
build_plat_precomp,\
undefined

ENUM_DEFINITION(bld, key_path, KEYPATHS)
ENABLE_SEQUENCE(bld, key_path, KEYPATHS)



#endif //

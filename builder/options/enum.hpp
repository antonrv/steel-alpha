#ifndef STEEL_COMPILER_COMMON_OPTION_ENUM_HPP
#define STEEL_COMPILER_COMMON_OPTION_ENUM_HPP

#include "common/fun_sequences_std17.hpp"

#define ALL_OPTS \
app, \
plat, \
runtime_test, \
builder_test, \
parser_test, \
log_simplify, \
log_access, \
log_digest_access, \
log_file_record, \
log_module_record, \
log_fun_def_record, \
log_fun_call_record, \
log_fun_loop_record, \
log_fun_ret_record, \
log_fun_ctxt_record, \
log_binop_record, \
log_data_decl_record, \
log_data_use_record, \
print_parse_inspect, \
print_ast_inspect, \
print_ast_translate, \
print_app_graph, \
print_dep_events, \
log_scan, \
log_compile, \
log_link, \
log_steps, \
print_create


ENUM_DEFINITION(bld, opt_kind, ALL_OPTS)
ENABLE_SEQUENCE(bld, opt_kind, ALL_OPTS)

#endif // STEEL_COMPILER_COMMON_OPTION_ENUM_HPP

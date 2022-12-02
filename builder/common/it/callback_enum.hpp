#ifndef STEEL_COMPILER_COMMON_CALLBACK_ENUM_HPP
#define STEEL_COMPILER_COMMON_CALLBACK_ENUM_HPP

#include "common/fun_sequences_std17.hpp"

ENUM_DEFINITION(bld, callback_kind,

function_def,
detect_var_init,
detect_assignment,
detect_comparison,
detect_unary_int,
function_call,
detect_array_access,
detect_pointer_access,
task_decl,
function_loop,
translate_task_def,
translate_task_call,
translate_return_in_task,


translate_var_decl_wrap, // DEPRECATE

function_call_argument, // Translation
function_call_argument_ampsnd, // Translation
function_call_argument_subscript, // Translation

inject_argument_wrap,

register_return_stmt,
register_ctxt,
register_propagated_task_def,

inject_vardecl_wrap,
inject_vardecl_destroy


)


#endif // STEEL_COMPILER_COMMON_CALLBACK_ENUM_HPP

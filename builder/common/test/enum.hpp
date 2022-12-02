#ifndef STEEL_BUILDER_TEST_ENUM_HPP
#define STEEL_BUILDER_TEST_ENUM_HPP

#include "common/fun_sequences_std17.hpp"

#define ALL_TEST_SUITES \
main, \
call_noargs, \
call_copyarg, \
call_copyargs, \
call_copyarg_literal, \
call_const_copyarg, \
call_rw_refarg_init, \
call_rw_refarg_init_void_return, \
call_rw_refarg_param, \
call_rw_refarg_param_void_return, \
multiple_calls, \
access_prop, \
access_0d, \
access_1d, \
access_2d, \
access_3d

ENUM_DEFINITION(bld::test, suite, ALL_TEST_SUITES)

ENABLE_SEQUENCE(bld::test, suite, ALL_TEST_SUITES)


#endif // STEEL_BUILDER_TEST_ENUM_HPP

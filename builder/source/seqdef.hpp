#ifndef STEEL_COMMON_SEQUENCES_HPP
#define STEEL_COMMON_SEQUENCES_HPP

ENUM_DEFINITION(bld::src, indir, ptr, ref, copy, undefined)
ENUM_DEFINITION(bld::src, qual, var, cnst, undefined)

ENUM_DEFINITION(bld::src, access_kind, undefined, read_only, read_write, write_only, init_default, init)

ENUM_DEFINITION(bld::src, loop, for_kw, while_kw, undefined)

#define OBJS fun_def, fun_call, fun_loop, fun_ret, fun_ctxt, bin_op, data_decl, data_use 

ENUM_DEFINITION(bld::src, obj, OBJS)

ENABLE_SEQUENCE(bld::src, obj, OBJS)


ENUM_DEFINITION(bld::src, decl_kind,
body, // For vars declared in the function body
fargument, // For vars declared in the data decl list
return_parameter, // For vars to be reinserted into argument list to make tasks returning void
relaxed_fargument, // For vars declared with [[steel::manage]] tag
loop_variable,
make_implicit // For vars that are to be encapsulated in a data::view, because it denotes a range
)



ENUM_DEFINITION(bld::src::pc, sign, pos, neg)

ENUM_DEFINITION(bld::src::pc, range_limit, min, max, fix, undefined)

ENUM_DEFINITION(bld::src::pc, kind, num, var, fraction, offset, address, binop, loopvar, range, call, cs_list, addends, factors, undefined )
ENUM_DEFINITION(bld::src::pc, opkind, eq, neq, lt, leq, gt, geq, init_default, init, assign, incr, decr, undefined )
ENUM_DEFINITION(bld::src::pc, res, tru, fal, unk)

ENUM_DEFINITION(bld::src::pc, mem_ak, // memory access kind
point,
affine,
non_affine,
indirect
)

ENUM_DEFINITION(bld::src::pc, lv_trait, start, bound, sweep)

ENUM_DEFINITION(bld::src::pc, mem_expr_trans, // memory expr transformation
stat,
dyn
)


#define TOKEN_TESTS \
fail, \
split, \
piece_kind, \
make, \
simplify, \
evaluate, \
factorize, \
affine, \
guard_basic, \
guard_offset, \
guard_range

ENUM_DEFINITION( bld::src::pc, token_test, TOKEN_TESTS )
ENABLE_SEQUENCE( bld::src::pc, token_test, TOKEN_TESTS )


#endif // STEEL_COMMON_SEQUENCES_HPP

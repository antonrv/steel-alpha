#ifndef PARSER_MAKE_TOKEN
#define PARSER_MAKE_TOKEN

#include "source/token/terminal/num.hpp"
#include "source/token/terminal/var.hpp"
#include "source/token/terminal/undef.hpp"
#include "source/token/terminal/loopvar.hpp"
#include "source/token/multiple/addends.hpp"
#include "source/token/multiple/factors.hpp"
#include "source/token/multiple/cs_list.hpp"
#include "source/token/multiple/fraction.hpp"
#include "source/token/multiple/offset.hpp"
#include "source/token/multiple/range.hpp"
#include "source/token/multiple/call.hpp"
#include "source/token/multiple/binop.hpp"

namespace bld::src::pc {

template <kind Kind, typename... ArgsT>
own_token_t<Kind> make_token( ArgsT&&... args ) {
  return std::make_unique< token<Kind> >( std::forward<ArgsT>(args) ... );
}

own_token_t<kind::num> make_num(long n);

own_piece_t make_substract( cpiece_t aPc, cpiece_t bPc );

own_piece_t fold_addends( vec_cpiece_t vec );
own_cpiece_t fold_caddends( vec_cpiece_t vec );

vec_own_piece_t unfold_addends( cpiece_t inputPc );
vec_own_cpiece_t unfold_caddends( cpiece_t inputPc );

own_piece_t fold_factors( vec_cpiece_t vec );
own_cpiece_t fold_cfactors( vec_cpiece_t vec );

own_ctoken_t<kind::range> make_range_plus_one( cpiece_t inputPc );


} // namespace bld::src::pc 

#endif // PARSER_MAKE_TOKEN

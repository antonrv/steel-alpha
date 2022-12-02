#ifndef SOURCE_TOKEN_COMBINE_EXTEND_ARITH_HPP
#define SOURCE_TOKEN_COMBINE_EXTEND_ARITH_HPP


#include "source/token/simplify/interface.hpp"

#include "source/token/make/token.hpp"

#ifndef PARSER_TEST
  #include "source/object/data/transform/interface.hpp"
#endif // PARSER_TEST


namespace bld::src::pc {

#ifdef PARSER_TEST
  vec_own_piece_t align_contexts_to_target( vec_cpiece_t inVec, piece_context targetCtxt );
#endif // PARSER_TEST

template <kind Kind>
own_piece_t extend_arith( vec_cpiece_t inVec, piece_context targetCtxt ) {
  return simplify_piece( make_token< Kind >( align_contexts_to_target( inVec, targetCtxt ) ) ); 
};

template <kind Kind>
own_piece_t extend_arith( cpiece_t inLhs, cpiece_t inRhs, piece_context targetCtxt ) {
  return extend_arith< Kind >( {inLhs, inRhs}, targetCtxt );
};

} // namespace bld::src::pc

#endif // SOURCE_TOKEN_COMBINE_EXTEND_ARITH_HPP

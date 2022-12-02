

#include "source/token/combine/extend_arith.hpp"

#ifdef PARSER_TEST
  #include "source/token/make/copy.hpp"
#endif // PARSER_TEST

namespace bld::src::pc {

#ifdef PARSER_TEST
vec_own_piece_t align_contexts_to_target( vec_cpiece_t inVec, piece_context targetCtxt ) {
  return edit_piece_vector(inVec);
}
#endif // PARSER_TEST

template own_piece_t extend_arith<kind::addends>( vec_cpiece_t inVec, piece_context targetCtxt );
template own_piece_t extend_arith<kind::factors>( vec_cpiece_t inVec, piece_context targetCtxt );
template own_piece_t extend_arith<kind::fraction>( vec_cpiece_t inVec, piece_context targetCtxt );

template own_piece_t extend_arith<kind::addends>( cpiece_t inLhs, cpiece_t inRhs, piece_context targetCtxt );
template own_piece_t extend_arith<kind::factors>( cpiece_t inLhs, cpiece_t inRhs, piece_context targetCtxt );
template own_piece_t extend_arith<kind::fraction>( cpiece_t inLhs, cpiece_t inRhs, piece_context targetCtxt );

} // namespace bld::src::pc


 
#include "source/token/piece.hpp"

#ifndef PARSER_TEST
  #include "source/object/data/transform/interface.hpp"
#else
#include "source/token/make/token.hpp"
#endif // PARSER_TEST

namespace bld::src::pc {

#ifdef PARSER_TEST
own_piece_t align_contexts_to_target( cpiece_t inPc, piece_context targetCtxt ) {
  return edit_piece( inPc );
}
#endif // PARSER_TEST

own_piece_t extend_piece( cpiece_t inPc, piece_context targetCtxt ) {
  return align_contexts_to_target( inPc, targetCtxt );
  // auto newTarget = align_contexts_to_target( inPc, targetCtxt );

  // if (inPc->get_sign() == sign::neg) { newTarget->flip_sign(); }

  // return newTarget;
}

} // namespace bld::src::pc

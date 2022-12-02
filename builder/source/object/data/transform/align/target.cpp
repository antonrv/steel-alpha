

#include "source/object/data/transform/align/aux.hpp"

#include "source/token/make/copy.hpp"

#include "common/util.hpp"

#include <functional>


namespace bld::src {

pc::vec_own_piece_t align_contexts_to_target( pc::vec_cpiece_t inVec, pc::piece_context targetLocalCtxt ) {

  auto ctxtPairs = transform_vec( inVec, [] (pc::cpiece_t pc) { return alignable(pc); } );

  alignable targetAlignable(targetLocalCtxt);

  return transform_vec( ctxtPairs, std::bind( align_to_target, std::placeholders::_1, targetAlignable ) );
}


std::pair<pc::own_piece_t, pc::own_piece_t> align_contexts_to_target( pc::cpiece_t pcA, pc::cpiece_t pcB, pc::piece_context targetLocalCtxt ) {

  auto vec = align_contexts_to_target( {pcA, pcB}, targetLocalCtxt );

  return std::make_pair( edit_piece(vec.front()), edit_piece(vec.back()) );
}

pc::own_piece_t align_contexts_to_target( pc::cpiece_t inPc, pc::piece_context targetLocalCtxt ) {

  alignable inAlign(inPc);
  alignable targetAlign(targetLocalCtxt);

  return align_to_target( inPc, targetAlign );
}

} // namespace bld::src

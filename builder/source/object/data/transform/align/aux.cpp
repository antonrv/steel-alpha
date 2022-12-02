
#include "source/object/data/transform/align/aux.hpp"

#include "source/object/function/definition.hpp"
#include "source/object/function/context.hpp"
#include "source/object/function/call.hpp"
#include "source/object/data/transform/interface.hpp"

#include "source/token/make/copy.hpp"

#include "source/object/state/def.hpp"

namespace bld::src {


alignable::alignable(pc::cpiece_t pc) :
  innerPiece(pc),
  global(static_cast<cso_t<obj::fun_def>>(pc->get_global_context())),
  local(pc->get_local_context())
{}

alignable::alignable(pc::piece_context loc) :
  innerPiece(nullptr),
  global(state<obj::fun_def>::get_containing(loc)),
  local(loc)
{}

pc::cpiece_t alignable::get_piece() const { return innerPiece; }
cso_t<obj::fun_def> alignable::get_global() const { return global; }
pc::piece_context alignable::get_local() const { return local; }





pc::own_piece_t align_to_target( const alignable& inputAlignable, const alignable& targetAlignable ) {

  if (inputAlignable.get_global() == pc::UniversalCtxt and inputAlignable.get_local() == pc::UniversalCtxt) {
    // Plain copy
    return edit_piece( inputAlignable.get_piece() );
  } else if (inputAlignable.get_global() != pc::UniversalCtxt and inputAlignable.get_local() == pc::UniversalCtxt) {
    throw std::runtime_error("align_contexts : Reached uncertain code, toAlignPc global context is " + inputAlignable.get_global()->get_identifier() + " while toAlignPc local is pc::UniversalCtxt. Is this allowed ?");
  } else if (inputAlignable.get_global() == pc::UniversalCtxt and inputAlignable.get_local() != pc::UniversalCtxt) {
    throw std::runtime_error("align_contexts : Reached uncertain code, toAlignPc local context is " + inputAlignable.get_local()->get_identifier() + " while toAlignPc global is pc::UniversalCtxt. Is this allowed ?");
  }

  pc::own_piece_t liftedInGlobal;

  if (inputAlignable.get_global()->get_identifier() != targetAlignable.get_global()->get_identifier()) {
    // Global context mismatch : pieces in different functions. First : Transform to topmost local context.

    auto liftedLocal = transform_to_local_context( inputAlignable.get_piece(), inputAlignable.get_global()->get_body_context() );
#ifdef TRANSFORM_LOG
    std::cout << "---Align : First TO_LOCAL. Bringing \"" << inputAlignable.get_piece()->get_pc_string() << "\" to context : " << inputAlignable.get_global()->get_body_context()->get_identifier() << ". RESULT : " << liftedLocal->get_pc_string() << '\n';
#endif // TRANSFORM_LOG

    // Global context mismatch : pieces in different functions. Second : Transform via a call

    if (targetAlignable.get_local()->get_obj() != obj::fun_call) {
      throw std::logic_error("When aligning to target and there is a global mismatch, target local context must be a call");
    }

    auto fCall = static_cast< cso_t<obj::fun_call> >( targetAlignable.get_local() );

    liftedInGlobal = transform_from_callee_to_call( liftedLocal.get(), fCall );

#ifdef TRANSFORM_LOG
    std::cout << "---Align : CALLEE_TO_CALL. Bringing \"" << liftedLocal.get()->get_pc_string() << "\" to call : " << fCall->get_identifier() << ". RESULT : " << liftedInGlobal->get_pc_string() << '\n';
#endif // TRANSFORM_LOG

  } else {

    // Global context match : pieces in same function context, so just copy the piece.

    liftedInGlobal = edit_piece( inputAlignable.get_piece() );
  }

  auto retPc = transform_to_local_context( liftedInGlobal.get(), targetAlignable.get_local() );
#ifdef TRANSFORM_LOG
  std::cout << "---Align : Final TO_LOCAL. Bringing \"" << liftedInGlobal->get_pc_string() << "\" to context : " << targetAlignable.get_local()->get_identifier() << ". RESULT : " << retPc->get_pc_string() << '\n';
#endif // TRANSFORM_LOG
  return retPc;
}

} // namespace bld::src

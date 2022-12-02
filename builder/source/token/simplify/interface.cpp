
#include "source/token/simplify/interface.hpp"

#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"

#include "source/token/transform/multiple.hpp"


#include "source/token/simplify/steps.hpp"


#include <stdexcept>



namespace bld::src::pc {


///////////////
//
// INTERFACE
//
///////////////

// static unsigned IndentLevel = 0;

void log_change(cpiece_t inputPc, cpiece_t outputPc, std::string opStep) {

  if (inputPc->get_pc_string() != outputPc->get_pc_string()) {
    state::log<opt_kind::log_simplify>("Changed:", inputPc->get_pc_string(), "--->", opStep, "--->", outputPc->get_pc_string(), ":");
  }
  if (inputPc->get_kind() != outputPc->get_kind()) {
    state::log<opt_kind::log_simplify>("Changed Kind:", inputPc->get_pc_string(),inputPc->get_kind(), "--->", opStep, "--->", outputPc->get_pc_string(), ":", outputPc->get_kind());
  }
}

static
own_piece_t this_simplify_piece(cpiece_t inputPc) {
  return simplify_piece(inputPc);
}

own_piece_t simplify_piece_core(cpiece_t inputPc) {

  own_piece_t retOwnPc;

  if (inputPc->is_arith()) {

    if (inputPc->is_terminal()) {
      retOwnPc = edit_piece(inputPc);
    } else if (inputPc->get_kind() == kind::addends) {
      retOwnPc = simplify<kind::addends>::on( static_cast<ctoken_t<kind::addends>>( inputPc ) );
    } else if (inputPc->get_kind() == kind::factors) {
      retOwnPc = simplify<kind::factors>::on( static_cast<ctoken_t<kind::factors>>( inputPc ) );
    } else if (inputPc->get_kind() == kind::fraction) {
      retOwnPc = simplify<kind::fraction>::on( static_cast<ctoken_t<kind::fraction>>( inputPc ) );
    } else {
      throw std::logic_error("Unreachable in simplify_piece. Unhandled arith token : " + inputPc->get_kind_str());
    }

  } else {

    if (inputPc->get_kind() == kind::range) {
      retOwnPc = simplify<kind::range>::on( static_cast<ctoken_t<kind::range>>( inputPc ) );
    } else if (inputPc->is_multiple()) {
     retOwnPc = transform_piece_multiple( static_cast<const multiple*>(inputPc), this_simplify_piece );
    } else {
      retOwnPc = edit_piece(inputPc);
    }
  }

  if (inputPc->get_pc_string() != retOwnPc->get_pc_string()) {
    log_change( inputPc, retOwnPc.get(), "Core change" );
  }

  return retOwnPc;
}

} // namespace bld::src::pc

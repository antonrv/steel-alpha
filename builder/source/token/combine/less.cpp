

#include "source/token/combine/interface.hpp"

#include "source/token/multiple/multiple.hpp"
#include "source/token/terminal/terminal.hpp"



#include <algorithm>

namespace bld::src::pc {

template <typename PieceT>
static
bool less_than_detail(PieceT inLhs, PieceT inRhs);

// Terminals
template <>
bool less_than_detail(cterminal_t inLhs, cterminal_t inRhs) {

  return inLhs->get_pc_string() < inRhs->get_pc_string();
}

// Multiples
template <>
bool less_than_detail(const multiple * inLhs, const multiple * inRhs) {

  auto nToks = inLhs->get_token_count();
  if (nToks != inRhs->get_token_count()) {
    return inLhs->get_token_count() < inRhs->get_token_count();
  }

  auto canonLhs = canonicalize( inLhs->get_tokens() );
  auto canonRhs = canonicalize( inRhs->get_tokens() );

  return std::lexicographical_compare(
    std::begin(canonLhs), std::end(canonLhs),
    std::begin(canonRhs), std::end(canonRhs),
    less_than );
}


///////////////
//
// INTERFACE
//
///////////////
bool less_than(cpiece_t inLhs, cpiece_t inRhs) {

  auto commonPck = inLhs->get_kind();
  if (inRhs->get_kind() != commonPck) {
    // Different category.
    return static_cast<unsigned>(inLhs->get_kind()) < static_cast<unsigned>(inRhs->get_kind());
  }


  if (commonPck == kind::num or commonPck == kind::var) {

    return less_than_detail( static_cast<cterminal_t>(inLhs), static_cast<cterminal_t>(inRhs) );

  } else if (commonPck == kind::addends or commonPck == kind::factors or commonPck == kind::fraction) {

    return less_than_detail( static_cast<const multiple *>(inLhs), static_cast<const multiple *>(inRhs) );

  } else {
    return inLhs->get_pc_string() < inRhs->get_pc_string();
    // throw std::logic_error("Unreachable in  less_than. Could not handle : " + inRhs->get_kind_str());
  }

}


///////////////
//
// INTERFACE
//
///////////////
vec_cpiece_t canonicalize( vec_cpiece_t vec ) {

  std::sort( std::begin(vec), std::end(vec), less_than );

  return vec;
}

} // namespace bld::src::pc

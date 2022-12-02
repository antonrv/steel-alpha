

#include "source/token/multiple/addends.hpp"

namespace bld::src::pc {

void token<kind::addends>::inner_simplify() {

  if (super_type::get_token_count() > 1) {
    // Remove number 0 if it is present.


    auto isZero = [] (const own_piece_t& pc) { if (pc->get_kind() == kind::num) { return static_cast<ctoken_t<kind::num>>(pc.get())->get_value() == 0; } return false; };

    auto& toks = super_type::edit_own_tokens();
    
    toks.erase( std::remove_if(std::begin(toks), std::end(toks), isZero), std::end(toks) );

    if (toks.empty()) {
      toks.push_back( make_num(0) );
    }
  }
}

// TODO
// token<kind::addends>::token(own_piece_t&&... pcs) :
// multiple(std::forward<own_piece_t>(pcs)...)
// {}

token<kind::addends>::token(vec_own_piece_t&& a) :
multiple(std::move(a))
{
  this->inner_simplify();
}

token<kind::addends>::token(const token<kind::addends>& other) :
multiple(other)
{}

kind token<kind::addends>::get_kind() const { return kind::addends; }


std::string token<kind::addends>::get_pc_string() const {
  return multiple::get_pc_string_from('+');
}

sign token<kind::addends>::get_sign() const {
  // Always return pos
  return sign::pos;
}

void token<kind::addends>::flip_sign() {
  for (auto * piece : multiple::edit_tokens()) {
    piece->flip_sign();
  }
}


void token<kind::addends>::append_addend( piece * pc ) {
  multiple::edit_tokens().push_back( pc );
}


} // namespace bld::src::pc

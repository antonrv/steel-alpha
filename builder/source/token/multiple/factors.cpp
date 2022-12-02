
#include "source/token/multiple/factors.hpp"

#include "source/token/terminal/num.hpp"

namespace bld::src::pc {

///////////////// FACTORS  <--- MULTIPLE

void token<kind::factors>::inner_simplify() {

  // Nullify if 0 present

  auto isZero = [] (const own_piece_t& pc) { if (pc->get_kind() == kind::num) { return static_cast<ctoken_t<kind::num>>(pc.get())->get_value() == 0; } return false; };

  auto& toks = super_type::edit_own_tokens();

  if (std::find_if(std::begin(toks), std::end(toks), isZero) != std::end(toks)) {
    toks.clear();
    toks.push_back( make_num(0) );
  }

  if (super_type::get_token_count() > 1) {
    // Remove number 1 is present.

    auto isOne = [] (const own_piece_t& pc) { if (pc->get_kind() == kind::num) { return static_cast<ctoken_t<kind::num>>(pc.get())->get_value() == 1; } return false; };
    
    toks.erase( std::remove_if(std::begin(toks), std::end(toks), isOne), std::end(toks) );

    if (toks.empty()) {
      toks.push_back( make_num(1) );
    }
  }
}

token<kind::factors>::token(vec_own_piece_t&& f) :
super_type(std::move(f))
{
  // Uniformize all tokens to sign::pos
  m_sign = multiple::extract_sign( );

  this->inner_simplify();
}


token<kind::factors>::token(const token<kind::factors>& other) :
super_type(other),
m_sign(other.m_sign)
{
}

std::string token<kind::factors>::get_pc_string() const {
  return super_type::get_pc_string_from('*', m_sign);
}

kind token<kind::factors>::get_kind() const { return kind::factors; }

sign token<kind::factors>::get_sign() const {
  return m_sign;
}


void token<kind::factors>::flip_sign() {
  m_sign = (m_sign == sign::pos ? sign::neg : sign::pos);
}

} // namespace bld::src::pc

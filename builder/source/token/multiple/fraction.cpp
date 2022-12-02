
#include "source/token/multiple/fraction.hpp"

#include "source/token/terminal/terminal.hpp"


namespace bld::src::pc {

///////////////// FRAC  <--- MULTIPLE



token<kind::fraction>::token(vec_own_piece_t&& f, bool isMod) :
binary(std::move(f)),
m_isMod(isMod)
{
  m_sign = multiple::extract_sign();
}

token<kind::fraction>::token(const token<kind::fraction>& other) :
binary(other),
m_isMod(other.m_isMod),
m_sign(other.m_sign)
{ }

std::string token<kind::fraction>::get_pc_string() const {
  return multiple::get_pc_string_from((m_isMod ? '%' : '/'), m_sign);
}


kind token<kind::fraction>::get_kind() const { return kind::fraction; }

sign token<kind::fraction>::get_sign() const {
  return m_sign;

  // if (not this->is_simple()) {
  //   throw std::logic_error("Cannot get sign ot not simple fraction");
  // }
  // auto numSign = static_cast<cterminal_t>(get_numerator())->get_sign();
  // auto denSign = this->has_token<1>() ? static_cast<cterminal_t>(get_denominator())->get_sign() : sign::pos;
  // return (numSign == sign::neg xor denSign == sign::neg) ? sign::neg : sign::pos;
}

void token<kind::fraction>::flip_sign() {
  m_sign = (m_sign == sign::pos ? sign::neg : sign::pos);
}

bool token<kind::fraction>::has_denominator() const {
  return binary::has_token<1>();
}

cpiece_t token<kind::fraction>::get_numerator() const {
  return binary::get_token<0>();
}

cpiece_t token<kind::fraction>::get_denominator() const {
  return binary::get_token<1>();
}

piece * token<kind::fraction>::edit_numerator() {
  return binary::edit_token<0>();
}

piece * token<kind::fraction>::edit_denominator() {
  return binary::edit_token<1>();
}


// bool token<kind::fraction>::is_simple() const {
//   return (not this->get_numerator()->is_multiple()) and this->get_numerator()->get_kind() == this->get_denominator()->get_kind();
// }

bool token<kind::fraction>::is_numeric() const {
  return this->get_numerator()->get_kind() == kind::num and this->get_denominator()->get_kind() == kind::num;
}

bool token<kind::fraction>::is_mod() const {
  return m_isMod;
}


} // namespace bld::src::pc


#include "source/token/terminal/num.hpp"


namespace bld::src::pc {



void validate_name_string(const std::string& str, kind kindKind);

void token<kind::num>::inner_simplify() {
  if (m_value == 0 and terminal::get_sign() == sign::neg) { terminal::flip_sign(); }
}

///////////////// NUM <--- TERMINAL
token<kind::num>::token(unsigned n, sign s) :
  terminal(s),
  m_value(n)
{
  this->inner_simplify();
}


token<kind::num>::token(const token& other) :
  terminal(other),
  m_value(other.m_value)
{
  this->inner_simplify();
}

kind token<kind::num>::get_kind() const { return kind::num; }


unsigned token<kind::num>::get_value() const {
  return m_value;
}

void token<kind::num>::set_value(unsigned v) {
  m_value = v;
}

std::string token<kind::num>::get_pc_string() const {
  if (terminal::get_sign() == sign::neg) {
    return "(-" + std::to_string(m_value) + ")";
  } else {
    return std::to_string(m_value);
  }
}

} // namespace bld::src::pc

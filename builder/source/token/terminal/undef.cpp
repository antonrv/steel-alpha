
#include "source/token/terminal/undef.hpp"

namespace bld::src::pc {

token<kind::undefined>::token() :
terminal()
{}

token<kind::undefined>::token(const std::string& is) :
  terminal(),
  m_name(is)
{}

bool token<kind::undefined>::is_arith() const { return true; }
bool token<kind::undefined>::is_rt() const { return true; } // In general depends on rt. May not.

kind token<kind::undefined>::get_kind() const { return kind::undefined; }

std::string token<kind::undefined>::get_pc_string() const {
  if (terminal::get_sign() == sign::neg) {
    return "(-" + m_name + ")";
  } else {
    return m_name;
  }
}

} // namespace bld::src::pc

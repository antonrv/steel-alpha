
#include "source/token/multiple/address.hpp"

#include "source/token/terminal/var.hpp"
#include "source/token/multiple/cs_list.hpp"

namespace bld::src::pc {

token<kind::address>::token(own_piece_t&& operand) :
super_type(tokens_to_vector(std::move(operand)))
{}

token<kind::address>::token(const token<kind::address>& other) :
super_type(other)
{}


kind token<kind::address>::get_kind() const { return kind::address; }

bool token<kind::address>::is_arith() const {
  return false;
}

std::string token<kind::address>::get_pc_string() const {
  return '&' + this->get_operand()->get_pc_string();
}

cpiece_t token<kind::address>::get_operand() const {
  return super_type::get_token<0>();
}

bool token<kind::address>::is_direct_call_argument() const {

  // Parent is kind::call --> true
  if (this->get_parent()->get_kind() == kind::call) {
    return true;
  }

  // Parent is kind::cs_list --> forward to it
  if (this->get_parent()->get_kind() == kind::cs_list) {
    auto cslistParent = static_cast<ctoken_t<kind::cs_list>>(this->get_parent());
    return cslistParent->is_direct_call_argument();
  }
  return false;
}

} // namespace bld::src::pc

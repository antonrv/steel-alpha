
#include "source/token/multiple/offset.hpp"

#include "source/token/terminal/var.hpp"
#include "source/token/multiple/cs_list.hpp"
#include "source/token/multiple/address.hpp"

namespace bld::src::pc {

///////////////// OFFSET  <--- MULTIPLE

token<kind::offset>::token(own_piece_t&& base, own_piece_t&& index) :
binary(tokens_to_vector(std::move(base), std::move(index)))
{ }

token<kind::offset>::token(vec_own_piece_t&& f) :
binary(std::move(f))
{ }

token<kind::offset>::token(const token<kind::offset>& other) :
binary(other)
{}

kind token<kind::offset>::get_kind() const { return kind::offset; }

bool token<kind::offset>::is_arith() const { return false; }
bool token<kind::offset>::is_rt() const { return true; }

sign token<kind::offset>::get_sign() const { return this->get_base()->get_sign(); }

void token<kind::offset>::flip_sign() { this->edit_base()->flip_sign(); }


std::string token<kind::offset>::get_pc_string() const {
  return this->get_base()->get_pc_string() + "[" + this->get_index()->get_pc_string() + "]";
}


bool token<kind::offset>::has_index() const {
  return binary::has_token<1>();
}

ctoken_t<kind::var> token<kind::offset>::get_base() const {
  auto fst = binary::get_token<0>();
  if (fst->get_kind() != kind::var) {
    throw std::logic_error("Could not get_base of kind::offset : expected kind::var");
  }
  return static_cast<ctoken_t<kind::var>>(fst);
}

cpiece_t token<kind::offset>::get_index() const {
  return binary::get_token<1>();
}

token_t<kind::var> token<kind::offset>::edit_base() {
  auto fst = binary::edit_token<0>();
  if (fst->get_kind() != kind::var) {
    throw std::logic_error("Could not edit_base of kind::offset : expected kind::var");
  }
  return static_cast<token_t<kind::var>>(fst);
}

piece * token<kind::offset>::edit_index() {
  return binary::edit_token<1>();
}


bool token<kind::offset>::is_direct_call_argument() const {
  // Parent is kind::call --> true
  if (this->get_parent()->get_kind() == kind::call) {
    return true;
  }

  // Parent is kind::cs_list --> forward to it
  if (this->get_parent()->get_kind() == kind::cs_list) {
    auto cslistParent = static_cast<ctoken_t<kind::cs_list>>(this->get_parent());
    return cslistParent->is_direct_call_argument();
  } else if (this->get_parent()->get_kind() == kind::address) {
    auto addressParent = static_cast<ctoken_t<kind::address>>(this->get_parent());
    return addressParent->is_direct_call_argument();
  }
  return false;
}

bool token<kind::offset>::is_direct_operator_argument() const {
  // Parent is kind::binop --> true
  if (this->get_parent()->get_kind() == kind::binop) {
    return true;
  }
  return false;
}


} // namespace bld::src::pc

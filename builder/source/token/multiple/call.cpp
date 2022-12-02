
#include "source/token/multiple/call.hpp"

#include "source/token/terminal/var.hpp"
#include "source/token/multiple/cs_list.hpp"


namespace bld::src::pc {

///////////////// OFFSET  <--- MULTIPLE


token<kind::call>::token(vec_own_piece_t&& f) :
binary(std::move(f))
{ }

token<kind::call>::token(const token<kind::call>& other) :
binary(other)
{}

kind token<kind::call>::get_kind() const { return kind::call; }

bool token<kind::call>::is_arith() const { return false; }
bool token<kind::call>::is_rt() const { return true; }

sign token<kind::call>::get_sign() const { return this->get_name()->get_sign(); }
void token<kind::call>::flip_sign() { this->edit_name()->flip_sign(); }


std::string token<kind::call>::get_pc_string() const {
  std::string argStr = (this->has_arguments() ? this->get_arguments()->get_pc_string() : "no-rhs");
  return this->get_name()->get_pc_string() + "(" + argStr + ")";
}



ctoken_t<kind::var> token<kind::call>::get_name() const {
  auto fst = binary::get_token<0>();
  if (fst->get_kind() != kind::var) {
    throw std::logic_error("Could not get name of kind::call : expected kind::var");
  }
  return static_cast<ctoken_t<kind::var>>(fst);
}

bool token<kind::call>::has_arguments() const {
  return binary::has_token<1>();
}

cpiece_t token<kind::call>::get_arguments() const {
  return binary::get_token<1>();
}

cpiece_t token<kind::call>::get_argument(unsigned i) const {
  auto args = this->get_arguments();
  if (args->get_kind() == kind::cs_list) {
    return static_cast<ctoken_t<kind::cs_list>>( args )->get_element(i);
  } else {
    // Not a cs_list
    if (i != 0) {
      throw std::logic_error("Cannot get_argument " + std::to_string(i) + " in token<kind::call> : unique argument, not a cs_list");
    }
    return args;
  }
}

token_t<kind::var> token<kind::call>::edit_name() {
  auto fst = binary::edit_token<0>();
  if (fst->get_kind() != kind::var) {
    throw std::logic_error("Could not get name of kind::call : expected kind::var");
  }
  return static_cast<token_t<kind::var>>(fst);
}

piece_t token<kind::call>::edit_arguments() {
  return binary::edit_token<1>();
}

piece_t token<kind::call>::edit_argument(unsigned i) {
  auto args = this->edit_arguments();
  if (args->get_kind() == kind::cs_list) {
    return static_cast<token_t<kind::cs_list>>( args )->edit_element(i);
  } else {
    // Not a cs_list
    if (i != 0) {
      throw std::logic_error("Cannot get_argument " + std::to_string(i) + " in token<kind::call> : unique argument, not a cs_list");
    }
    return args;
  }
}

} // namespace bld::src::pc

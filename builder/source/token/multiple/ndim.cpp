
#include "source/token/multiple/ndim.hpp"


namespace bld::src::pc {

///////////////// FACTORS  <--- MULTIPLE

token<kind::ndim>::token(vec_own_piece_t&& f) :
multiple(std::move(f))
{ }


token<kind::ndim>::token(const token<kind::ndim>& other) :
multiple(other)
{}

std::string token<kind::ndim>::get_pc_string() const {
  return "ndim string"
}

kind token<kind::ndim>::get_kind() const { return kind::ndim; }


unsigned token<kind::ndim>::get_dimensions() const {
  return multiple::get_token_count();
}

cpiece_t token<kind::ndim>::get_element(unsigned id) const {
  if (id >= this->get_dimensions()) {
    throw std::logic_error("Cannot get element in ndim : " + std::to_string(id) + ", dimensions : " + this->get_dimensions());
  }
  return super_type::get_tokens()[id];
}


} // namespace bld::src::pc


#ifndef MULTIPLE_FACTORS_DECL_HPP_HPP
#define MULTIPLE_FACTORS_DECL_HPP_HPP

#include "source/token/multiple/multiple.hpp"


namespace bld::src::pc {

template <>
class token<kind::ndim> : public multiple {

  using super_type = multiple;

public:

  token(vec_own_piece_t&& f);

  token(const token& other);

  template <typename... OwnPieceTs>
  token(OwnPieceTs&&... args) : multiple(tokens_to_vector( edit_piece(std::forward<OwnPieceTs>(args)) ... )) {}

  virtual kind get_kind() const final override;

  std::string get_pc_string() const final override;

  unsigned get_dimensions() const;

  cpiece_t get_element(unsigned id) const;

};

} // namespace bld::src::pc

#endif // MULTIPLE_FACTORS_DECL_HPP_HPP


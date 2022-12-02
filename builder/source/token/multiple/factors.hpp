#ifndef MULTIPLE_FACTORS_DECL_HPP_HPP
#define MULTIPLE_FACTORS_DECL_HPP_HPP

#include "source/token/multiple/multiple.hpp"


namespace bld::src::pc {

template <>
class token<kind::factors> : public multiple {

  using super_type = multiple;

  sign m_sign = sign::pos;

  void inner_simplify();

public:

  token(vec_own_piece_t&& f);
  // token(vec_own_cpiece_t&& f);

  token(const token& other);

  template <typename... OwnPieceTs>
  token(OwnPieceTs&&... args) : multiple(tokens_to_vector( edit_piece(std::forward<OwnPieceTs>(args)) ... )) {
    m_sign = multiple::extract_sign( );
    this->inner_simplify();
  }

  virtual kind get_kind() const final override;

  sign get_sign() const final override;

  void flip_sign() final override;

  std::string get_pc_string() const final override;

  // void append_factor( piece * pc );
};

} // namespace bld::src::pc

#endif // MULTIPLE_FACTORS_DECL_HPP_HPP

#ifndef MULTIPLE_ADDENDS_DECL_HPP_HPP
#define MULTIPLE_ADDENDS_DECL_HPP_HPP

#include "source/token/multiple/multiple.hpp"

// #include "source/token/token_tuple.hpp"

#include "source/token/make/copy.hpp"



namespace bld::src::pc {

template <>
class token<kind::addends> : public multiple {

  using super_type = multiple;

  void inner_simplify();

public:

  // token(own_piece_t&&... pcs); TODO

  token(vec_own_piece_t&& f);

  token(const token& other);

  template <typename... OwnPieceTs>
  token(OwnPieceTs&&... args) : multiple(tokens_to_vector( edit_piece(std::forward<OwnPieceTs>(args)) ... )) {
    this->inner_simplify();
  }

  kind get_kind() const final override;

  sign get_sign() const final override;

  void flip_sign() final override;

  std::string get_pc_string() const final override;

  void append_addend( piece * pc );
};


} // namespace bld::src::pc

#endif // MULTIPLE_ADDENDS_DECL_HPP_HPP

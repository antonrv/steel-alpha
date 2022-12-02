#ifndef MULTIPLE_OFFSET_DECL_HPP_HPP
#define MULTIPLE_OFFSET_DECL_HPP_HPP

#include "source/token/multiple/multiple.hpp"


namespace bld::src::pc {


template <>
class token<kind::offset> : public binary {


public:
  token(own_piece_t&& arrayBase, own_piece_t&& arrayIdx);

  token(vec_own_piece_t&& f);

  token(const token& other);

  virtual kind get_kind() const final override;

  sign get_sign() const final override;
  void flip_sign() final override;

  bool is_arith() const final override;
  bool is_rt() const final override;

  std::string get_pc_string() const final override;

  bool has_index() const;

  ctoken_t<kind::var> get_base() const;
  token_t<kind::var> edit_base();
  cpiece_t get_index() const;
  piece_t edit_index();

  bool is_direct_call_argument() const;
  bool is_direct_operator_argument() const;

};

} // namespace bld::src::pc

#endif // MULTIPLE_OFFSET_DECL_HPP_HPP

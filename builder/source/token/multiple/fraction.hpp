#ifndef MULTIPLE_FRACTION_DECL_HPP_HPP
#define MULTIPLE_FRACTION_DECL_HPP_HPP

#include "source/token/multiple/multiple.hpp"

#include <iostream>

namespace bld::src::pc {

template <>
class token<kind::fraction> : public binary {

  bool m_isMod = false;

  sign m_sign = sign::pos;


public:
  template <typename PT1, typename PT2>
  token(PT1&& num, PT2&& den, bool isMod = false) :
    binary(tokens_to_vector(edit_piece(num), edit_piece(den))),
    m_isMod(isMod)
  {
    m_sign = multiple::extract_sign();
    // std::cout << "Fraction with sign " << m_sign << '\n';
  }

  // token(own_piece_t&& num, own_piece_t&& den);

  token(vec_own_piece_t&& f, bool isMod = false);

  token(const token& other);

  virtual kind get_kind() const final override;

  sign get_sign() const override;
  void flip_sign() final override;

  std::string get_pc_string() const final override;

  bool has_denominator() const;

  cpiece_t get_numerator() const;
  cpiece_t get_denominator() const;

  piece * edit_numerator();
  piece * edit_denominator();

  // bool is_simple() const;


  bool is_numeric() const;

  bool is_mod() const;

  // template <unsigned Id>
  // piece * edit_fraction_piece() {
  //   return multiple::edit_tokens()[Id];
  // }

  template <unsigned Id>
  cpiece_t get_fraction_piece() const {
    return multiple::get_tokens()[Id];
  }
};

} // namespace bld::src::pc

#endif // MULTIPLE_FRACTION_DECL_HPP_HPP

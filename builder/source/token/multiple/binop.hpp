#ifndef MULTIPLE_BINOP_DECL_HPP_HPP
#define MULTIPLE_BINOP_DECL_HPP_HPP

#include "source/sequences.hpp"

#include "source/token/multiple/multiple.hpp"

#ifndef PARSER_TEST
#include "source/object/typedef.hpp"
#endif // PARSER_TEST


namespace bld::src::pc {

template <>
class token<kind::binop> : public binary {

private:

  opkind m_operationKind = opkind::undefined;

public:

  template <typename PT1, typename PT2>
  token(PT1&& lhs, PT2&& rhs, opkind opk) :
    binary(tokens_to_vector(edit_piece(lhs), edit_piece(rhs))),
    m_operationKind(opk)
  {}

  // token(own_piece_t&& lhs, own_piece_t&& rhs, opkind opk);

  token(own_piece_t&& lhs, opkind opk);

  token(vec_own_piece_t&& , opkind opk);

  token(const token& other);

  // token(cpiece_t lhsPiece, cpiece_t rhsPiece, opkind opk);

  kind get_kind() const final override;

  bool is_arith() const final override;

  std::string get_pc_string() const final override;


  cpiece_t get_lhs() const;
  cpiece_t get_rhs() const;

  void set_opkind(opkind opk);

  opkind get_opkind() const;

  bool has_rhs() const;

  bool is_compare() const;

  bool is_write() const;

  res evaluate() const;

#ifndef PARSER_TEST
  access_kind get_use_access(cso_t<obj::data_use> dUse) const;

private:

  void assert_hold_use(cso_t<obj::data_use> dUse) const;
#endif // PARSER_TEST
};

} // namespace bld::src::pc

#endif // MULTIPLE_BINOP_DECL_HPP_HPP

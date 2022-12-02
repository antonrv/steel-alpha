#ifndef OPERATION_BINARY_HPP
#define OPERATION_BINARY_HPP

#include "source/object/base.hpp"

#include "source/token/multiple/binop.hpp"

#include "source/sequences.hpp"



namespace clang {

  class DeclStmt;
  class BinaryOperator;
  class SourceManager;
  class ASTContext;

} // namespace clang

namespace bld::src {

  template <obj>
  class sobject;

} // bld::src



namespace bld::src {


class piece;


template <>
class sobject<obj::bin_op> : public sobject_base {
public:

  static constexpr obj sobject_kind = obj::bin_op;

  static constexpr opt_kind log_record = opt_kind::log_binop_record;

  using super_type = sobject_base;

private:


  pc::own_token_t<pc::kind::binop> m_ownedPiece = nullptr;

private:


public: 

  // Interface for testing
  // sobject(const std::string& str);

  //////////////////// CUSTOM CONSTRUCTOR to build distinct binary_ops within loop_ops, subject to manipulation
  // sobject(piece * lhsPiece, piece * rhsPiece, pc::opkind opk);

  //////////////////// CONSTRUCTOR FOR:
  // int a = X; ---> pc::opkind::init 
  // int a; ---> pc::opkind::init_default
  sobject(const clang::DeclStmt* declStmt, const clang::SourceManager& sm, const clang::ASTContext & ctxt);


  //////////////////// CONSTRUCTOR FOR:
  // a = X ---> pc::opkind::assign
  // X == Y ---> pc::opkind::eq
  // X != Y ---> pc::opkind::neq
  // X < Y ---> pc::opkind::lt
  // X <= Y ---> pc::opkind::leq
  // X > Y ---> pc::opkind::gt
  // X >= Y ---> pc::opkind::geq
  // X += Y ---> pc::opkind::incr
  // X -= Y ---> pc::opkind::decr
  sobject(const clang::BinaryOperator* binOpCl, const clang::SourceManager& sm, const clang::ASTContext & ctxt);


  //////////////////// CONSTRUCTOR FOR:
  // X++ ---> pc::opkind::plus1 ---> pc::opkind::incr
  // X-- ---> pc::opkind::sub1 ---> pc::opkind::decr
  // In principle not binary, but can be interpretable as a special case of binary incr/decr : X += 1 or X -= 1
  sobject(const clang::UnaryOperator* unOpCl, const clang::SourceManager& sm, const clang::ASTContext & ctxt);


  virtual ~sobject() override;

  obj get_obj() const final override;

  void print(std::ostream& os) const final override;

  std::string serial() const final override;

  pc::ctoken_t<pc::kind::binop> get_operator_piece() const;

//   cpiece_t get_clhs() const;
//   cpiece_t get_crhs() const;
};


} // namespace bld::src

#endif // OPERATION_BINARY_HPP

#include "source/object/function/binary.hpp"

#include "source/token/multiple/binop.hpp"


#include "source/object/data/use.hpp" // XXX DBG

#include <iostream> // XXX  DBG

namespace bld::src {


// sobject<obj::bin_op>::sobject(const std::string& inputStr) :
//   sobject_base(inputStr),
//   m_ownedPiece(make_operation_pieces(inputStr)),
//   m_operationKind(get_binary_operation_kind(inputStr))
// {}

//////////////////// CUSTOM CONSTRUCTOR to build distinct binary_ops within loop_ops, subject to manipulation
// sobject<obj::bin_op>::sobject(piece * lhsPiece, piece * rhsPiece, pc::opkind opk) :
//   sobject_base("synth_binary_op"),
//   m_ownedPiece(std::make_unique<token<pc::kind::binop>>(lhsPiece, rhsPiece)),
//   m_operationKind(opk)
// {}


sobject<obj::bin_op>::~sobject() {}

obj sobject<obj::bin_op>::get_obj() const {
  return obj::bin_op;
}

void sobject<obj::bin_op>::print(std::ostream& os) const {
  super_type::print(os);

  os << "\tLHS : " << this->m_ownedPiece->get_lhs()->get_pc_string() << '\n';
  os << "\tRHS : ";
  if (this->m_ownedPiece->has_rhs()) {
    os << this->m_ownedPiece->get_rhs()->get_pc_string() << '\n';
  } else {
    os << "None\n";
  }
  os << "\tPiece : " << m_ownedPiece->get_pc_string() << '\n';
}

pc::ctoken_t<pc::kind::binop> sobject<obj::bin_op>::get_operator_piece() const {
  return m_ownedPiece.get();
}

} // namespace bld::src

#include "source/object/function/binary.hpp"

#include "source/token/make/piece.hpp"
#include "source/token/make/token.hpp"

#include "source/object/data/decl.hpp"

#include "clang/AST/Decl.h"
#include "clang/AST/Expr.h"
#include "clang/AST/ASTContext.h"

#include "source/object/data/register_bind.hpp"

#include <vector>
#include <algorithm>



namespace bld::src {

// DEPRECATED
// static
// std::string get_last_token(const std::string& inputStr) {
//   // eg: 'const int a' --> returns 'a'
//   std::cout << "get_last_token : " << inputStr << '\n';
//   auto vecTokens = split_string(inputStr, ' ');
//   std::cout << "ret : " << vecTokens.back() << '\n';
//   return vecTokens.back();
// 
// }

//////////////////// CONSTRUCTOR FOR:
// int a = X; ---> pc::opkind::init 
// int a; ---> pc::opkind::init_default
sobject<obj::bin_op>::sobject(const clang::DeclStmt* declStmt, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
  super_type(declStmt, sm, ctxt)
{

  // Register LHS of the initialization
  // std::cout << "obj::bin_op constructor " << this->get_data() << '\n';

  auto vDecl = static_cast<const clang::VarDecl*>( declStmt->getSingleDecl() );

  if (vDecl->hasInit()) {

    // Initialize owned piece
    auto [lhsStr, rhsStr] = get_sides_of_decl_stmt(declStmt, ctxt);

    if (not rhsStr.empty()) {
      // eg int a = b;
      m_ownedPiece = static_unique_pointer_cast<pc::token<pc::kind::binop>>( pc::make_piece( lhsStr + " = " + rhsStr ) ); // XXX new interface
      m_ownedPiece->set_opkind( pc::opkind::init ); // bc pc::make_piece set to pc::opkind::assign
    } else {
      // eg vector<int> a; hasInit() returns true but there is no assigment, as initialization is implicit.
      m_ownedPiece = pc::make_token<pc::kind::binop>( pc::make_piece(lhsStr), pc::opkind::init_default );
    }

  } else {

    // Only lhs initialized.

    auto varName = split_string(sobject_base::m_data, ' ').back();  // from 'const int var' -> m_data is set to 'var'

    m_ownedPiece = pc::make_token<pc::kind::binop>( pc::make_piece(varName), pc::opkind::init_default );
  }
  // std::cout << m_ownedPiece->get_pc_string() << '\n';
  
  register_and_bind( declStmt, sm, ctxt, this, m_ownedPiece->edit_flatten_terminals() );
}


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
sobject<obj::bin_op>::sobject(const clang::BinaryOperator* binOpCl, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
  super_type(binOpCl, sm, ctxt)
{

  m_ownedPiece = static_unique_pointer_cast<pc::token<pc::kind::binop>>( pc::make_piece( sobject_base::get_data() ) );

  // std::cout << "obj::bin_op constructor " << this->get_data() << ". Owned : " << m_ownedPiece->get_pc_string() << '\n';

  auto fTerms = m_ownedPiece->edit_flatten_terminals();

  register_and_bind( binOpCl, sm, ctxt, this, m_ownedPiece->edit_flatten_terminals() );
}


//////////////////// CONSTRUCTOR FOR:
// X++ ---> pc::opkind::plus1 ---> pc::opkind::incr
// X-- ---> pc::opkind::sub1 ---> pc::opkind::decr
sobject<obj::bin_op>::sobject(const clang::UnaryOperator* unOpCl, const clang::SourceManager& sm, const clang::ASTContext & ctxt) :
  super_type(unOpCl, sm, ctxt)
{

  // Register LHS of the initialization
  // std::cout << "obj::bin_op constructor " << this->get_data() << '\n';

  m_ownedPiece = static_unique_pointer_cast<pc::token<pc::kind::binop>>( pc::make_piece( sobject_base::get_data() ) );

  register_and_bind( unOpCl, sm, ctxt, this, m_ownedPiece->edit_flatten_terminals() );
}


} // namespace bld::src

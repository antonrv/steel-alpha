
#include "source/object/data/factory.hpp"

#include "source/object/data/use.hpp"
#include "source/object/data/literal_factory.hpp"

#include "source/object/function/binary.hpp"
#include "source/object/data/decl.hpp"

#include "source/token/make/piece.hpp"


#include "source/object/state/def.hpp"

#include "clang/AST/Stmt.h"
#include "clang/AST/Expr.h"
#include "clang/AST/Decl.h"

namespace bld::src {

void
register_data_uses(const clang::DeclStmt* declStmt, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclCalleeOrOp, pc::vec_terminal_t& flattenTerminals) {

  if (flattenTerminals.empty()) {
    throw std::logic_error("Empty flatten terminals in data_use factory");
  }

  state<obj::data_use>::make( declStmt, sm, ctxt, dDeclCalleeOrOp, flattenTerminals.back() );
  flattenTerminals.pop_back();

  auto vDecl = static_cast<const clang::VarDecl*>( declStmt->getSingleDecl() );
  // auto vDecl = static_cast<const clang::VarDecl*>( declStmt->getSingleDecl() )->getInitializingDeclaration();

  if (vDecl->hasInit() and (not flattenTerminals.empty())) { // hasInit returns true for obj declarations with implicit constructors, but we don't want to register more things in this case

    register_data_uses( vDecl->getInit(), sm, ctxt, dDeclCalleeOrOp, flattenTerminals );
  }
}


// Used by operation_init and operation_assign
void
register_data_uses(const clang::Expr* expr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sob_t dDeclCalleeOrOp, pc::vec_terminal_t& flattenTerminals) {

  if (expr == nullptr) {
    throw std::logic_error("Cannot register_data_uses : expr is nullptr");
  }

  if (flattenTerminals.empty()) {
    throw std::logic_error("Empty flatten terminals in data_use factory");
  }

  if ( clang::DeclRefExpr::classof(expr)) {

    // Eg int a = b;
    
    state<obj::data_use>::make( static_cast<const clang::DeclRefExpr*>(expr), sm, ctxt, dDeclCalleeOrOp, flattenTerminals.back() );
    flattenTerminals.pop_back();

    // std::cout << "Register side : declrefexpr \n";
  
  } else if ( is_castable_to_literal(expr) ) {

    // Eg int a = 42;
    register_from_literal<obj::data_use>( expr, sm, ctxt, dDeclCalleeOrOp, flattenTerminals.back() );
    flattenTerminals.pop_back();

    // std::cout << "Register side : literal \n";

  } else if ( clang::CallExpr::classof(expr)) {

    // std::cout << "Register side : callexpr\n";

    // Eg int a = foo( ... );

    // TODO handle this. Before that, we have to place the callback in a matcher after the matcher that detects all function calls, so here we expect to get the function_call via find_sobject.

    // throw std::runtime_error("Handle initialization from function call : op " + op->get_identifier());
    // std::cout << "WARNING Handle initialization from function call : op " << op->get_identifier() << '\n'; XXX HANDLE THIS XXX XXX XXX

  } else if (clang::ArraySubscriptExpr::classof(expr)) {

    // std::cout << "Registering side of operator as arraysuscexpr\n";

    auto asExpr = static_cast<const clang::ArraySubscriptExpr*>(expr);

    register_data_uses( asExpr->getBase(), sm, ctxt, dDeclCalleeOrOp, flattenTerminals );

    register_data_uses( asExpr->getIdx(), sm, ctxt, dDeclCalleeOrOp, flattenTerminals );

  } else if (clang::BinaryOperator::classof(expr)) {

    // Eg int a = b + 4;
    // std::cout << "Register side : binop\n";

    // Recurse on each side

    auto boExpr = static_cast<const clang::BinaryOperator*>(expr);

    register_data_uses( boExpr->getLHS(), sm, ctxt, dDeclCalleeOrOp, flattenTerminals );

    register_data_uses( boExpr->getRHS(), sm, ctxt, dDeclCalleeOrOp, flattenTerminals );

  } else if ( clang::ParenExpr::classof(expr)) {

    auto pExpr = static_cast<const clang::ParenExpr*>(expr);

    register_data_uses( pExpr->getSubExpr(), sm, ctxt, dDeclCalleeOrOp, flattenTerminals );

  } else if (clang::ImplicitCastExpr::classof(expr)) {

    // std::cout << "Register side : impl cast\n";

    // Recurse
    register_data_uses( static_cast<const clang::ImplicitCastExpr*>(expr)->getSubExpr(), sm, ctxt, dDeclCalleeOrOp, flattenTerminals );

  } else if (clang::UnaryOperator::classof(expr)) {

    // Eg '&'
    auto unOp = static_cast<const clang::UnaryOperator*>(expr);

    // Recurse
    register_data_uses( unOp->getSubExpr(), sm, ctxt, dDeclCalleeOrOp, flattenTerminals );

  } else if (clang::ValueStmt::classof(expr)) {

  } else {

    std::cout << "Warning!!! : Skipped case in data use factory\n";
    // std::cout << "Register side : else\n";

    // throw std::runtime_error("Could not register side of '=' operator");
    // Do nothing instead (eg std::vector<int> a; would fail otherwise, since it has init, but we don't want to process it)
  }
}

// void
// register_call_argument(const clang::Expr* expr, const clang::SourceManager& sm, const clang::ASTContext & ctxt, sobject<obj::data_decl> * dDeclCallee) {
// 
//   // throw std::runtime_error("IMPLEMENT register_call_argument");
// 
//   if ( clang::DeclRefExpr::classof(expr)) {
// 
//     // Eg foo(a);
//     
//     state<obj::data_use>::make( static_cast<const clang::DeclRefExpr*>(expr), sm, ctxt, dDeclCallee );
// 
//     // std::cout << "Registered data_use from dr expr" << expr << '\n';
// 
//   } else if ( is_castable_to_literal(expr) ) {
// 
//     // Eg foo(42);
//     register_from_literal<obj::data_use>( expr, sm, ctxt, dDeclCallee );
// 
// 
//   } else if (clang::ArraySubscriptExpr::classof(expr)) {
// 
// 
//   //   // Eg foo(a[..]);
// 
//   //   // Return argument data_use not needed
//   //   handle_array_subscript( static_cast<const clang::ArraySubscriptExpr*>(expr), sm, ctxt, dDeclCallee );
// 
//   //   // std::cout << "Registered data_use from as expr" << expr << '\n';
// 
//   } else if (clang::ImplicitCastExpr::classof(expr)) {
// 
//     // Recurse
//     register_call_argument( static_cast<const clang::ImplicitCastExpr*>(expr)->getSubExpr(), sm, ctxt, dDeclCallee );
// 
//   } else if (clang::UnaryOperator::classof(expr)) {
// 
//     // Eg '&'
//     auto unOp = static_cast<const clang::UnaryOperator*>(expr);
// 
//     // Recurse
//     register_call_argument( unOp->getSubExpr(), sm, ctxt, dDeclCallee );
// 
//   } else {
// 
//     throw std::runtime_error("Could not register call argument");
//   }
// 
// }

} // namespace bld::src

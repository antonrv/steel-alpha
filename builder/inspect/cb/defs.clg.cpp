
#include "inspect/consumer.clg.hpp"

#include "common/it/matchers.hpp"

#include "source/object/function/call.hpp"
#include "source/object/function/definition.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/function/context.hpp"

#include "source/object/state/def.hpp"

#include "options/state/decl.hpp"

#include <iostream>


namespace bld {


////////////////////////////////////
////////////////////////////////////
//
// FUNCTION_DECL MATCH CALLBACK
//
////////////////////////////////////
////////////////////////////////////

// AST matcher match the function declaration with target function
template <>
void Callback<callback_kind::function_def, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::FunctionDecl *funDecl = Result.Nodes.getNodeAs<clang::FunctionDecl>(mtraits<match_kind::function_def>::s_matchString);

  if (funDecl == nullptr) {
    throw std::runtime_error("Could not get funDecl node in match callback");
  }

  const std::string originalFunName = funDecl->getNameInfo().getAsString();
  const std::string funcName = originalFunName == "main" ? "main_entry" : originalFunName;

  

  //////// Register function_definition element
  auto fDef = src::state<src::obj::fun_def>::make(funDecl, m_sourceManager, m_astContext, funcName);

  //////// Register function_context element
  auto bodyStmt = funDecl->getBody();
  if (bodyStmt == nullptr) { throw std::runtime_error("Function definition without body"); }
  if (not clang::CompoundStmt::classof(bodyStmt)) { throw std::runtime_error("Function body not castable to CompoundStmt"); }
  src::state<src::obj::fun_ctxt>::make( static_cast<const clang::CompoundStmt*>( bodyStmt ), m_sourceManager, m_astContext );


  //////// Register return type as a data decl
  if (not funDecl->getReturnType().getTypePtr()->isVoidType()) {

    fDef->set_return_argument(  src::state<src::obj::data_decl>::make(funDecl->getReturnTypeSourceRange(), m_sourceManager, m_astContext, funDecl->getReturnType()) );
  }

  // ==== 3. Register parameters
  llvm::ArrayRef<clang::ParmVarDecl*> parArray = funDecl->parameters();

  for (const clang::ParmVarDecl* pvDeclPtr : parArray) {
    fDef->add_argument( src::state<src::obj::data_decl>::make(pvDeclPtr, m_sourceManager, m_astContext) );
  }

  if (funcName == "main_entry") {
    if (funDecl->getReturnType().getTypePtr()->isVoidType()) {
      throw std::runtime_error("Main function must return non-void value");
    }
    // std::cout << "Warning. We need to insert manually the call to main_entry\n";
    // create_main_call_element(funDecl, tDef, dShared, funcName); TODO
  }
}

} // namespace bld

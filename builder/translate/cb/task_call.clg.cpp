#include "translate/consumer.clg.hpp"

#include "common/it/matchers.hpp"



/////// Source elements
#include "source/object/function/definition.hpp"
#include "source/object/function/call.hpp"

#include "source/object/state/def.hpp"



#include "common/inject/syntax_def.hpp"

/////// Debug
#include "options/state/decl.hpp"

/////// Clang headers
#include "clang/Rewrite/Core/Rewriter.h"

#include "translate/cb/aux/locate_args.hpp"

/////// Std headers
#include <sstream>
#include <iostream>



namespace bld { 

template <>
void Callback<callback_kind::translate_task_call, step::translate>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {


  const clang::CallExpr *callExpr = Result.Nodes.getNodeAs<clang::CallExpr>(mtraits<match_kind::function_call>::s_matchString);

  const clang::FunctionDecl * funDeclCallee = callExpr->getDirectCallee();

  if (funDeclCallee == nullptr) {
    throw std::runtime_error("call expr does not have direct callee");
  }

  auto fCall = src::state<src::obj::fun_call>::get( callExpr, m_sourceManager, m_astContext );
  if (fCall == nullptr) {
    // Call call something not registered (ie a function without body)
    return;
  }
  if ( not fCall->get_callee()->is_task()) {
    // Callee is not a task. Do nothing
    return;
  }

  // CallExpr first node is the call
  {
    const clang::Expr * calleeExpr = callExpr->getCallee();
    std::ostringstream oss;
    oss << "co_await " << syn::makeasync(syn::str(fCall->get_app_call_translation()));
    m_rewriterRef.ReplaceText(calleeExpr->getSourceRange(), oss.str());
  }

  {
    std::ostringstream oss;
    oss << syn::task_attr_desc_obj() << ".depth + 1";
    std::string argInsert = "";
    if (callExpr->getNumArgs() != 0) {
      oss << ", ";   
    }

    auto [insertLoc, foundStartArg] = locate_start_args(callExpr, m_astContext);
    m_rewriterRef.InsertTextAfter( insertLoc.getLocWithOffset(foundStartArg + 1), oss.str() );
  }

}


} // namespace bld

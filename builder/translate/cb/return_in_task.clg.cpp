
#include "translate/consumer.clg.hpp"

#include "common/it/matchers.hpp"

#include "translate/cb/aux/coro_raii/interface.hpp"

/////// Source elements
#include "source/object/function/return.hpp"
#include "source/object/function/definition.hpp"
#include "source/object/state/def.hpp"


#include "common/inject/syntax_def.hpp"


/////// Clang headers
#include "clang/Rewrite/Core/Rewriter.h"

#include <iostream> // TMP XXX
// #include <sstream>

namespace bld { 


template <>
void Callback<callback_kind::translate_return_in_task, step::translate>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::ReturnStmt *retStmt = Result.Nodes.getNodeAs<clang::ReturnStmt>(mtraits<match_kind::return_stmt_in_function>::s_matchString);

  if (not retStmt) {
    throw std::logic_error("Matching of ReturmStmt failed");
  }

  auto fRet = src::state<src::obj::fun_ret>::get(retStmt, m_sourceManager, m_astContext);
  if (fRet == nullptr) {
    throw std::logic_error("Return stmt not registered");
  }

  // Get the dispatcher in which this retStmt is contained
  auto fDef = src::state<src::obj::fun_def>::get_containing( fRet );

  if (not fDef->is_task()) {
    // Do nothing. This return stmt does not belong to a task, but to a function
    return;
    // throw std::logic_error("Unable to find kernel definition in which return statement is contained");
  }

  auto tDefParentElem = fDef->get_task();


  const clang::Expr * retValueExpr = retStmt->getRetValue();

  if (not tDefParentElem->is_dispatcher()) {
    // Return nothing, because the return type has been replaced by 'void'
    m_rewriterRef.RemoveText(static_cast<const clang::ValueStmt*>(retValueExpr)->getSourceRange());

  } else {
    // Dispatcher

    std::string coroRaiiStr = make_cororaii_destroy( tDefParentElem );

    coroRaiiStr += "\nco_return; // "; 
    // If we just comment the return statement, we would alter the 
    m_rewriterRef.InsertTextBefore(retStmt->getBeginLoc(), coroRaiiStr);
  }

  if (retValueExpr != nullptr and clang::ValueStmt::classof(retValueExpr)) {

    auto varNameSR = static_cast<const clang::ValueStmt*>(retValueExpr)->getSourceRange();
    auto beginFullLoc = m_astContext.getFullLoc(varNameSR.getBegin());
    auto endFullLoc = m_astContext.getFullLoc(varNameSR.getEnd());

    auto varName = std::string(beginFullLoc.getCharacterData(), std::distance(beginFullLoc.getCharacterData(), endFullLoc.getCharacterData() + 1));

    std::stringstream oss; oss << syn::stmt( syn::assign( syn::return_as_param(), syn::str(varName) ) ) << syn::endl();

    m_rewriterRef.InsertTextBefore(retStmt->getReturnLoc(), oss.str());

  } else if (retValueExpr == nullptr) {
    // This is a plain return stmt, do nothing, because we have just commmented it.

  } else {
    // Not null and not a class of ValueStmt
    throw std::logic_error("Dont know how to parse ret value");
  }

}



} // namespace bld

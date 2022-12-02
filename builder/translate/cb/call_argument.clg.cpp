

#include "translate/consumer.clg.hpp"


#include "common/it/matchers.hpp"

/////// Source elements
#include "source/object/function/definition.hpp"
#include "source/object/function/call.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/state/def.hpp"

#include "options/state/decl.hpp"

#include "translate/cb/aux/coro_raii/interface.hpp"

/////// Clang headers
#include "clang/Rewrite/Core/Rewriter.h"

#include <optional>

namespace bld {

static
std::optional<src::cso_t<src::obj::data_use>>
locate_data_use( const clang::Expr * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt ) {

  if ( clang::UnaryOperator::classof(cPtr) ) {

    auto subExpr = static_cast<const clang::UnaryOperator*>(cPtr)->getSubExpr();

    return locate_data_use( subExpr, sm, ctxt );

  } else if ( clang::ArraySubscriptExpr::classof(cPtr) ) {

    auto baseExpr = static_cast<const clang::ArraySubscriptExpr*>(cPtr)->getBase();

    return locate_data_use( baseExpr, sm, ctxt );

  } else if ( clang::ImplicitCastExpr::classof(cPtr) ) {

    auto icExpr = static_cast<const clang::ImplicitCastExpr*>(cPtr)->getSubExpr();

    return locate_data_use( icExpr, sm, ctxt );

  } else if ( clang::DeclRefExpr::classof(cPtr) ) {

    auto drExpr = static_cast<const clang::DeclRefExpr*>(cPtr);
  
    if (src::state<src::obj::data_use>::exists( drExpr, sm, ctxt )) {

      return src::state<src::obj::data_use>::get( drExpr, sm, ctxt );
    }

  }

  return std::optional<src::cso_t<src::obj::data_use>>();

}


template <typename ClangT>
static
void
translate_function_call_argument(const ClangT * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt, clang::Rewriter& rwRef) {

  // std::cout << "Translating function call arg...";

  if (cPtr == nullptr) {
    throw std::logic_error("Node match null");
  }

  auto dUseInCallOpt = locate_data_use( cPtr, sm, ctxt );

  if (not dUseInCallOpt.has_value()) {
      // std::cout << "Translating nothing\n";
      return;
  }

  auto dUseInCall = dUseInCallOpt.value();


  auto fCall = src::state<src::obj::fun_call>::get_containing( dUseInCall );

  auto fDefCallee = fCall->get_callee();

  auto fDefCaller = fCall->get_caller();

  auto dDeclCaller = dUseInCall->get_root_data_decl();

  if (dDeclCaller == nullptr) {
    throw std::logic_error("Could not find dDeclCaller of data_use");
  }

  if ((not fDefCallee->is_task()) and (not fDefCaller->is_task())) {
    // Both are functions, not tasks // Nothing to protect
    return;

  } else if (fDefCaller->is_task() and (not fDefCallee->is_task())) {
    // Caller is a dispatcher, callee is not a task. We may need to protect against this.
    // We will need to block against this call, but not done in this matcher TODO

    std::ostringstream oss;
    oss << dDeclCaller->get_wrap_variable_name() + ".acquire()";

    rwRef.ReplaceText( cPtr->getSourceRange(), oss.str() );


  } else if (fDefCallee->is_task()) {
    // This is a task calling to another task


    if ( dUseInCall->require_emit_backend()) {

      // std::cout << "dUse : " << dUseInCall->get_identifier() << " DOES require emit bnd\n";

      std::ostringstream oss;
      oss << make_emit_bnd( dUseInCall );

      rwRef.ReplaceText( cPtr->getSourceRange(), oss.str() );
    } else {
      // std::cout << "dUse : " << dUseInCall->get_identifier() << " does NOT require emit bnd\n";
      // Nothing to protect
    }

  } else {
    throw std::logic_error("Unreachable at call argument translation callback");
  }

      // std::cout << "DONE\n";
}


//////////// 
// Our only concern in this matcher is to append 'emit_bnd_writer() / emit_bnd_reader()' things to function call arguments
template <>
void Callback<callback_kind::function_call_argument, step::translate>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::DeclRefExpr *callArgExpr = Result.Nodes.getNodeAs<clang::DeclRefExpr>(mtraits<match_kind::function_call_argument>::s_matchString);

  translate_function_call_argument( callArgExpr, m_sourceManager, m_astContext, m_rewriterRef );
}


template <>
void Callback<callback_kind::function_call_argument_ampsnd, step::translate>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::UnaryOperator *unOpAmpsnd = Result.Nodes.getNodeAs<clang::UnaryOperator>(mtraits<match_kind::function_call_argument_ampsnd>::s_matchString);

  // std::cout << "Match fun call arg ampsnd\n";

  if (clang::ArraySubscriptExpr::classof(unOpAmpsnd->getSubExpr())) {

    // std::cout << "Matched UnOp & in call tied to ArraySubscriptExpr\n";

    translate_function_call_argument( unOpAmpsnd, m_sourceManager, m_astContext, m_rewriterRef );

  } else if (clang::DeclRefExpr::classof(unOpAmpsnd->getSubExpr())) {

    // std::cout << "Matched UnOp & in call tied to DeclRefExpr\n";

    // translate_function_call_argument( static_cast<const clang::DeclRefExpr*>(unOpAmpsnd->getSubExpr()), m_sourceManager, m_astContext, m_rewriterRef );
    translate_function_call_argument( unOpAmpsnd, m_sourceManager, m_astContext, m_rewriterRef );

  } else {
    throw std::runtime_error("Could not handle function_call_argument_ampsnd for translation");
  }
}

template <>
void Callback<callback_kind::function_call_argument_subscript, step::translate>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::ArraySubscriptExpr *asExpr = Result.Nodes.getNodeAs<clang::ArraySubscriptExpr>( mtraits<match_kind::function_call_argument_subscript>::s_matchString );

  translate_function_call_argument( asExpr, m_sourceManager, m_astContext, m_rewriterRef );
}

} // namespace bld

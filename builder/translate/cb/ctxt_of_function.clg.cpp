
#include "translate/consumer.clg.hpp"


#include "common/it/matchers.hpp"

/////// Source elements
#include "source/object/function/definition.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/function/context.hpp"
#include "source/object/function/return.hpp"
#include "source/object/state/def.hpp"

#include "translate/cb/aux/coro_raii/interface.hpp"

#include "options/state/decl.hpp"


/////// Clang headers
#include "clang/Rewrite/Core/Rewriter.h"


namespace bld { 

// AST matcher match the function declaration with target function
template <>
void Callback<callback_kind::inject_argument_wrap, step::translate>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::CompoundStmt *cmpStmt = Result.Nodes.getNodeAs<clang::CompoundStmt>(mtraits<match_kind::ctxt_of_function>::s_matchString);

  if (cmpStmt == nullptr) { throw std::runtime_error("Wrong node match in inject_argument_wrap"); }


  // Get function definition. Is this a task and a dispatcher?
  auto fCtxt = src::state<src::obj::fun_ctxt>::get( cmpStmt, m_sourceManager, m_astContext );

  if (not fCtxt->is_top()) {
    throw std::logic_error("Expected topmost context");
  }

  auto fDef = src::state<src::obj::fun_def>::get_containing( fCtxt );


  if ((not fDef->is_task()) or (fDef->is_task() and (not fDef->get_task()->is_dispatcher()))) {
    // Context does not belong to a task, or it is but not a dispatcher. Do not wrap anything
    return;
  }

  auto tDefCaller = fDef->get_task();

  // Function is a task and a dispatcher, so inject argument wrappings for those arguments needing it.

  //////////////////// CORORAII CREATE INJECTION

  auto wrapCreateStr = make_cororaii_create(tDefCaller);

  m_rewriterRef.InsertTextAfter( cmpStmt->getBeginLoc().getLocWithOffset(1), wrapCreateStr);

  //////////////////// CORORAII DESTROY INJECTION
  // All wraps done. Now check if there are return stmts in this context. If there arent, inject cororaii expression at the end of the context

  auto fReturnSet = src::state<src::obj::fun_ret>::get_all();

  auto nReturnsHere = std::count_if( std::begin(fReturnSet), std::end(fReturnSet),
      [fCtxt](src::cso_t<src::obj::fun_ret> fRet) {
        return fRet->get_parent_function_context()->get_identifier() == fCtxt->get_identifier();
      }
    );

  if (nReturnsHere == 0) {
    // No return statements. Then inject the cororaii at the end of this cmp statement

    auto wrapDestroyStr = make_cororaii_destroy(tDefCaller);

    m_rewriterRef.InsertTextBefore( cmpStmt->getEndLoc().getLocWithOffset(0), wrapDestroyStr );

  } else {
    // Do nothing
    // Maybe there are other return stmts in inner contexts, but eventual cororraii injections will be injected before return statements, in other callback
  }
}

} // namespace bld

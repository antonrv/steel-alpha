
#include "translate/consumer.clg.hpp"

#include "common/it/matchers.hpp"

#include "source/object/data/decl.hpp"
#include "source/object/function/context.hpp"

#include "source/object/state/def.hpp"


#include "translate/cb/aux/coro_raii/interface.hpp"


namespace bld { 

template <>
void Callback<callback_kind::inject_vardecl_destroy, step::translate>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::CompoundStmt *cmpStmt = Result.Nodes.getNodeAs<clang::CompoundStmt>(mtraits<match_kind::any_ctxt>::s_matchString);

  // Register just for this purpose (to evaluate 'contains' of a data decl)
  auto fCtxtNested = src::state<src::obj::fun_ctxt>::get(cmpStmt, m_sourceManager, m_astContext);

  if (fCtxtNested->is_top()) {
  // Do nothing. dDecls in topmost have been wrapped/destroyed in other callback
    return;
  }

  auto dDeclsInThisCtxt = src::state<src::obj::data_decl>::get_all_satisfying(
    [fCtxtNested] (const auto& dDecl) {

      auto fCtxtInnermost = src::state<src::obj::fun_ctxt>::get_innermost_of( dDecl.get() );

      if (fCtxtInnermost == nullptr) {
        // Eg a vardecl in a func param list
        return false;
      }

      return fCtxtInnermost->get_identifier() == fCtxtNested->get_identifier();
    }
  );

  // Only those dDecls lying in this ctxt that need wrapping will be incorporated
  auto wrapDestroyStr = make_cororaii_destroy_over_data_decls(dDeclsInThisCtxt);

  if (not wrapDestroyStr.empty()) {

    m_rewriterRef.InsertTextBefore( cmpStmt->getEndLoc().getLocWithOffset(0), wrapDestroyStr );
  }
}

} // namespace bld

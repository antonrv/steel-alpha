#include "translate/consumer.clg.hpp"

#include "common/it/matchers.hpp"

#include "translate/cb/aux/coro_raii/interface.hpp"


/////// Source elements
#include "source/object/data/decl.hpp"
#include "source/object/state/def.hpp"




namespace bld { 

template <>
void Callback<callback_kind::inject_vardecl_wrap, step::translate>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::DeclStmt *declStmt = Result.Nodes.getNodeAs<clang::DeclStmt>(mtraits<match_kind::var_decl>::s_matchString);

  if (declStmt == nullptr) {
    throw std::runtime_error("Wrong match of declstmt");
  }


  if (clang::VarDecl::classof(declStmt->getSingleDecl())) {

    auto vDecl = static_cast<const clang::VarDecl*>( declStmt->getSingleDecl() );

    if (not src::state<src::obj::data_decl>::exists(vDecl, m_sourceManager, m_astContext)) {
      // This dDecl has not been registered, just skip
      return;
    }

    auto dDecl = src::state<src::obj::data_decl>::get(vDecl, m_sourceManager, m_astContext);
  
    if (dDecl->require_wrap()) {

      auto wrapStr = make_wrap(dDecl);

      m_rewriterRef.InsertTextAfter( declStmt->getEndLoc().getLocWithOffset(1), wrapStr );
    }
    
  } else {
    // Skip
    std::cout << "WARNING : unable to interpret single decl of declstmt\n";
  }

}

} // namespace bld

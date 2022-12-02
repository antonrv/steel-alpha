
#include "inspect/consumer.clg.hpp"

#include "common/it/matchers.hpp"

#include "source/object/function/call.hpp"

#include "source/object/state/def.hpp"



// #include <iostream> // debug


namespace bld {


template <>
void Callback<callback_kind::function_call, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::CallExpr *callExpr = Result.Nodes.getNodeAs<clang::CallExpr>(mtraits<match_kind::function_call>::s_matchString);

  src::state<src::obj::fun_call>::make( callExpr, m_sourceManager, m_astContext );

}

} // namespace bld

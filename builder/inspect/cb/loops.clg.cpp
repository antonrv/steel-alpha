
#include "inspect/consumer.clg.hpp"

#include "common/it/matchers.hpp"

#include "source/object/function/loop.hpp"
#include "source/object/state/def.hpp"


#include "options/state/decl.hpp"

namespace bld {

////////////////////////////////////
////////////////////////////////////
//
// FUNCTION_CALL MATCH CALLBACK
//
////////////////////////////////////
////////////////////////////////////

template <>
void Callback<callback_kind::function_loop, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::ForStmt *forStmt = Result.Nodes.getNodeAs<clang::ForStmt>(mtraits<match_kind::function_loop>::s_matchString);

  if (forStmt == nullptr) {
    throw std::runtime_error("Error matching ForStmt ptr : nullptr");
  }

  // Register function_call element. 
  auto fLoop = src::state<src::obj::fun_loop>::make( forStmt, m_sourceManager, m_astContext );

  // Find the innermost loop in which this loop may be nested
  auto fLoopParent = src::state<src::obj::fun_loop>::get_innermost_of( fLoop );

  // Setting could be done in constructor TODO
  if (fLoopParent != nullptr) {

    fLoop->set_parent_loop( fLoopParent );

  } else {
    // Do nothing
  }

}

} // namespace bld

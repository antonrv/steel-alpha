


#include "inspect/consumer.clg.hpp"

#include "common/it/matchers.hpp"


/////// Source elements
#include "source/object/function/return.hpp"
#include "source/object/function/context.hpp"
#include "source/object/function/task.hpp"

#include "source/object/state/def.hpp"

#include "common/inject/syntax_def.hpp"



/////// Clang headers
#include "clang/Rewrite/Core/Rewriter.h"

#include <iostream> // TMP XXX
// #include <sstream>

namespace bld { 


template <>
void Callback<callback_kind::register_return_stmt, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::ReturnStmt *retStmt = Result.Nodes.getNodeAs<clang::ReturnStmt>(mtraits<match_kind::return_stmt_in_function>::s_matchString);

  if (not retStmt) {
    throw std::logic_error("Matching of ReturmStmt failed");
  }

  auto fRet = src::state<src::obj::fun_ret>::make(retStmt, m_sourceManager, m_astContext);

  auto fCtxtParent = src::state<src::obj::fun_ctxt>::get_innermost_of( fRet );

  // Setting could be done in constructor TODO
  if (fCtxtParent != nullptr) {
    fRet->set_parent_function_context( fCtxtParent );
  } else {
    throw std::runtime_error("Could not find innermost context of return stmt");
  }
}


} // namespace bld



#include "inspect/consumer.clg.hpp"

#include "common/it/matchers.hpp"

#include "source/object/function/definition.hpp"
#include "source/object/function/context.hpp"

#include "source/object/state/def.hpp"


namespace bld {

template <>
void Callback<callback_kind::register_ctxt, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::CompoundStmt *cmpStmt = Result.Nodes.getNodeAs<clang::CompoundStmt>(mtraits<match_kind::any_ctxt>::s_matchString);

  if (cmpStmt == nullptr) {
    throw std::runtime_error("Wrong node match in register_ctxt");
  }

  if ( src::state<src::obj::fun_ctxt>::exists(cmpStmt, m_sourceManager, m_astContext) ) {
    // Then this context has been registered as a topmost context while registering its associated function.
    return;
  }

  //////// Register function_definition element
  auto fCtxt = src::state<src::obj::fun_ctxt>::make(cmpStmt, m_sourceManager, m_astContext);

  auto fCtxtParent = src::state<src::obj::fun_ctxt>::get_innermost_of( fCtxt );

  // Setting could be done in constructor TODO
  if (fCtxtParent != nullptr) {
    fCtxt->set_parent_function_context( fCtxtParent );
  } else {
    throw std::runtime_error("Could not find innermost context of function context");
  }

}

} // namespace bld

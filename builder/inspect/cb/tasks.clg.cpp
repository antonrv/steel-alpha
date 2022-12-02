
#include "inspect/consumer.clg.hpp"

#include "common/it/matchers.hpp"

#include "source/object/function/definition.hpp"
#include "source/object/function/call.hpp"

#include "source/object/state/def.hpp"

#include "options/state/decl.hpp"

////////////////////////////////////
////////////////////////////////////
//
// KERNEL DEFINITION MATCH CALLBACK
//
////////////////////////////////////
////////////////////////////////////

// We forbid the explicit use of pointers. Protect against that TODO TODO TODO  UPDATE : Pointer -> mem region inferred
// We forbid polymorphic functions (Eg two funcs with same name and different arguments) TODO


namespace bld {

static
std::tuple<std::string, std::string, std::string>
get_app_identifiers(const clang::FunctionDecl *funDecl) {

  // Set the app::id of this task implementation
  std::string appIdentifier;
  std::string appImplementation;

  std::string funcName = funDecl->getNameInfo().getAsString();

  const auto * attrPtr = funDecl->template getAttr<clang::STEELTaskAttr>();

  if (attrPtr) {

    auto strRefApp = attrPtr->getApp().str();

    if (strRefApp.empty()) {
      // no app::id specified, treat funcName as app::id with a single app::impl
      appIdentifier = funcName;
      appImplementation = funcName;
    } else {
      // app::id specified, treat funcName as app::id with a single app::impl
      appIdentifier = strRefApp;
      appImplementation = funcName;
    }

  } else {

    if (funcName == "main") {
      auto mainName = "main_entry";
      appIdentifier = mainName;
      appImplementation = mainName;
      funcName = mainName;
    } else {
      throw std::runtime_error("Task definition without attributes and not 'main'");
    }
  }

  return {appIdentifier, appImplementation, funcName};
}

// AST matcher match the function declaration with target function
template <>
void Callback<callback_kind::task_decl, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::FunctionDecl *funDecl = Result.Nodes.getNodeAs<clang::FunctionDecl>(mtraits<match_kind::task_decl>::s_matchString);

  if (funDecl == nullptr) {
    throw std::runtime_error("Could not get funDecl node in match callback");
  }

  if (state::options::is_set<opt_kind::print_ast_inspect>()) {
    funDecl->dumpColor();
  }

  auto [appId, appImpl, functionName] = get_app_identifiers(funDecl);

  if (state::options::is_set<opt_kind::print_app_graph>()) {
    std::cout << "\tApp graph : app::id::" << appId << " -> app::impl::" << appImpl << '\n';
  }

  // Find the associated function definition element. Must exist

  auto fDef = src::state<src::obj::fun_def>::edit(funDecl, m_sourceManager, m_astContext);

  // ==== Register the task definition, replacing the function definition
  fDef->set_task( appId, appImpl );

}

} // namespace bld

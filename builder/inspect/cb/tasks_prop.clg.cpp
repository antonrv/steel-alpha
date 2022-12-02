
#include "inspect/consumer.clg.hpp"


#include "common/it/matchers.hpp"


/////// Source elements
#include "source/object/function/definition.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/state/def.hpp"

#include "common/inject/syntax_def.hpp"

#include "options/state/decl.hpp"

/////// Clang headers
#include "clang/Rewrite/Core/Rewriter.h"

#include "translate/cb/aux/locate_args.hpp"

namespace bld { 

static
void set_return_type(src::task_t srcTask, const clang::FunctionDecl * funDecl);

static
void append_arguments(src::task_t srcTask, const clang::FunctionDecl * funDecl, const clang::ASTContext& ctxt);


// AST matcher match the function declaration with target function
template <>
void Callback<callback_kind::register_propagated_task_def, step::inspect>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {


  const clang::FunctionDecl *funDecl = Result.Nodes.getNodeAs<clang::FunctionDecl>(mtraits<match_kind::function_def>::s_matchString);

  auto fDef = src::state<src::obj::fun_def>::edit(funDecl, m_sourceManager, m_astContext);

  if (not fDef->is_task()) {
    // This function is not a task, so do nothing
    return;
  }


  auto srcTask = fDef->edit_task();

  // if (state::options::is_set<opt_kind::print_ast_translate>()) {
  //   funDecl->dumpColor();
  // }

  set_return_type(srcTask, funDecl);


  append_arguments(srcTask, funDecl, m_astContext);

}


static
void set_return_type(src::task_t srcTask, const clang::FunctionDecl * funDecl) {

  if (srcTask) {

    std::string typeStr = "void";

    if (srcTask->is_dispatcher()) {
      // Coroutine with a non-void return type
      
      std::ostringstream oss;
      oss << syn::dispatcher( syn::bracket( syn::nms_app_impl( syn::str(srcTask->get_app_implementation()) ) ) );

      typeStr = oss.str();
    } else {
      // Not dispatcher
    }

    srcTask->set_return_type_str( typeStr );

  } else {
    funDecl->dumpColor();
    throw std::runtime_error("Could not find kernel in translation stage");
  }
}




// All kernels return void, so if this does not return void, pass the ret type as non-const ref in the last function arg.
// This appends a new parameter in the parameter list and replaces the return type by 'void'.
// Serves for both function definition and function declarations
static
void append_arguments(src::task_t srcTask, const clang::FunctionDecl * funDecl, const clang::ASTContext& ctxt) {


  if(srcTask->need_translate_void_return() or srcTask->is_dispatcher()) {

    // ---- Append 'task::attr& attrDesc' parameter
    std::string parentTaskAttr;
    if (srcTask->is_dispatcher()) {
      std::stringstream oss;

      auto attrTypeSyn = syn::task_attr_desc_ref();
      oss << attrTypeSyn << " " << syn::task_attr_desc_obj();

      parentTaskAttr = oss.str();

      // -- To create the fw fun decl in generation stage
      std::stringstream ossTypeParam; ossTypeParam << attrTypeSyn;
      srcTask->add_appended_type_parameter( ossTypeParam.str() );
    }

    // ---- Append 'return type' as a nonconst reference parameter
    std::string retAsArgStr;
    if (srcTask->need_translate_void_return()) {

      if (not srcTask->get_root_function_definition()->get_return_argument()) {
        throw std::logic_error("No return parameter in task definition " + srcTask->get_app_implementation());
      }

      auto retTypeSyn = syn::nonconstref( syn::str(srcTask->get_root_function_definition()->get_return_argument()->get_type_name()) );

      std::stringstream ossTypeParam; ossTypeParam << retTypeSyn;
      srcTask->add_appended_type_parameter( ossTypeParam.str() );

    }

  } else {
    // do nothing
  }

}

} // namespace bld

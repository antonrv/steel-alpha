
#include "translate/consumer.clg.hpp"


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
void append_arguments(src::ctask_t srcTask, const clang::FunctionDecl * funDecl, const clang::ASTContext& ctxt, clang::Rewriter& rwRef );


// AST matcher match the function declaration with target function
template <>
void Callback<callback_kind::translate_task_def, step::translate>::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const clang::FunctionDecl *funDecl = Result.Nodes.getNodeAs<clang::FunctionDecl>(mtraits<match_kind::function_def>::s_matchString);

  auto fDef = src::state<src::obj::fun_def>::get(funDecl, m_sourceManager, m_astContext);

  if (not fDef->is_task()) {
    // This function is not a task, so do nothing
    return;
  }

  auto srcTask = fDef->get_task();

  if (state::options::is_set<opt_kind::print_ast_translate>()) {
    funDecl->dumpColor();
  }


  if(srcTask->is_dispatcher() or not funDecl->getReturnType().getTypePtr()->isVoidType()) {


    m_rewriterRef.ReplaceText(funDecl->getReturnTypeSourceRange(), srcTask->get_return_type_str());
  }

  append_arguments(srcTask, funDecl, m_astContext, m_rewriterRef);

}



// All kernels return void, so if this does not return void, pass the ret type as non-const ref in the last function arg.
// This appends a new parameter in the parameter list and replaces the return type by 'void'.
// Serves for both function definition and function declarations
static
void append_arguments(src::ctask_t srcTask, const clang::FunctionDecl * funDecl, const clang::ASTContext& ctxt, clang::Rewriter& rwRef ) {


  if(srcTask->need_translate_void_return() or srcTask->is_dispatcher()) {

    auto [insertLoc, foundStartArg] = locate_start_args(funDecl, ctxt);

    // ---- Translate function name if it is main
    if (srcTask->get_app_implementation() == "main_entry") {
      // Change name : main -> main_entry
      rwRef.InsertTextBefore( insertLoc.getLocWithOffset(foundStartArg), "_entry" );
    }

    // ---- Append 'task::attr& attrDesc' parameter
    std::string parentTaskAttr;
    if (srcTask->is_dispatcher()) {
      std::stringstream oss;

      auto attrTypeSyn = syn::task_attr_desc_ref();
      oss << attrTypeSyn << " " << syn::task_attr_desc_obj();

      parentTaskAttr = oss.str();

    }

    // ---- Append 'return type' as a nonconst reference parameter
    std::string retAsArgStr;
    if (srcTask->need_translate_void_return()) {

      if (not srcTask->get_root_function_definition()->get_return_argument()) {
        throw std::logic_error("No return parameter in task definition " + srcTask->get_app_implementation());
      }

      std::stringstream oss;
      auto retTypeSyn = syn::nonconstref( syn::str(srcTask->get_root_function_definition()->get_return_argument()->get_type_name()) );

      oss << syn::type_var( std::move(retTypeSyn), syn::return_as_param() );
      retAsArgStr = parentTaskAttr.empty() ? oss.str() : ", " + oss.str();

      // -- To create the fw fun decl in generation stage
    }

    // ---- Make the final insertion
    auto appendStr = parentTaskAttr + retAsArgStr;

    if (not funDecl->parameters().empty()) { appendStr += ", "; }

    rwRef.InsertTextAfter( insertLoc.getLocWithOffset(foundStartArg + 1), appendStr );

  } else {
    // do nothing
  }


}

} // namespace bld

#ifndef STEEL_COMPILER_TRANSLATION_CONSUMER_DECL_HPP
#define STEEL_COMPILER_TRANSLATION_CONSUMER_DECL_HPP


#include "common/step_enum.hpp"
#include "common/it/callback_enum.hpp"
#include "common/it/base_callback.hpp"

#include "files/interface.hpp"

#include "clang/Frontend/FrontendActions.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"




namespace clang {
  class CompilerInstance;
  class SourceManager;
  class ASTContext;
  class Rewriter;
} // namespace clang

namespace bld {

class modifiable_type;

template <callback_kind MatchKind, step SK>
class Callback;

////////////////////////////////////
////////////////////////////////////
//
// TRANSLATION CALLBACKS
//
////////////////////////////////////
////////////////////////////////////

template <callback_kind CbKind, step SK>
class Callback;

template <callback_kind CbKind>
class Callback<CbKind, step::translate> : public clang::ast_matchers::MatchFinder::MatchCallback, public BaseCB {
public:
  Callback(const clang::SourceManager& sm, const clang::ASTContext& ac, clang::Rewriter &rw) : BaseCB(sm, ac), m_rewriterRef(rw) {}

  virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &Result);

private:

  clang::Rewriter &m_rewriterRef;
};



class TranslateASTConsumer : public clang::ASTConsumer {
public:
  TranslateASTConsumer(const clang::SourceManager& sm, const clang::ASTContext& ac, clang::Rewriter &R); 
  void HandleTranslationUnit(clang::ASTContext &Context) override;
private:
  // PASS
  // Callback<callback_kind::tu_with_kernel_body, step::translate> m_tuWithKernelBodyCB; DEPRECATED
  // Callback<callback_kind::task_decl, step::translate> m_kernelDeclCB;
  Callback<callback_kind::translate_task_def, step::translate> m_taskDefCB;
  Callback<callback_kind::translate_task_call, step::translate> m_taskCallCB;
  Callback<callback_kind::function_call_argument, step::translate> m_taskCallArgumentCB;
  Callback<callback_kind::function_call_argument_ampsnd, step::translate> m_taskCallArgumentAmpsndCB;
  Callback<callback_kind::function_call_argument_subscript, step::translate> m_taskCallArgumentSubscriptCB;
  Callback<callback_kind::translate_return_in_task, step::translate> m_returnInTaskCB;
  Callback<callback_kind::inject_argument_wrap, step::translate> m_argumentWrapCB;
  Callback<callback_kind::inject_vardecl_wrap, step::translate> m_vardeclWrapCB;
  Callback<callback_kind::inject_vardecl_destroy, step::translate> m_vardeclDestroyCB;


  // // To wrap variables declared within a task dispatcher
  // Callback<callback_kind::translate_var_decl_wrap, step::translate> m_varDeclWrapCB;

  // // To wrap parameters of a task dispatcher
  // // Callback<callback_kind::insert_parm_decl_wrap, step::translate> m_paramDeclWrapCB;

  // // Callback<callback_kind::async_event_in_return, step::translate> m_varInitFromKernelCallCB;
  // // Callback<callback_kind::assign_op_with_maybe_kernel_dep, step::translate> m_assignOpWithMaybeKernelDepCB;


  // // // PASS
  // // Callback<callback_kind::task_return_stmt, step::translate> m_kernelReturnCB;


  clang::ast_matchers::MatchFinder m_1stMatchFinder;
  clang::ast_matchers::MatchFinder m_2ndMatchFinder;
  // clang::ast_matchers::MatchFinder m_3rdMatchFinder;

//  AsyncMatchCallback m_asyncCallback;
//  clang::ast_matchers::MatchFinder m_asyncMatcher;
};

class TranslateFrontendAction : public clang::ASTFrontendAction {
public:
  TranslateFrontendAction();
  bool BeginSourceFileAction(clang::CompilerInstance& CI) override;
  void EndSourceFileAction() override; 
  std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &CI,
                                               llvm::StringRef file) override; 
private:
  clang::Rewriter m_rewriter;
  modifiable_file * m_translateTargetFile = nullptr;

  key_path m_sourceKeyPath = key_path::undefined;
public:
};


} // namespace bld

#endif //  STEEL_COMPILER_TRANSLATION_CONSUMER_DECL_HPP

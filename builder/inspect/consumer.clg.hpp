#ifndef STEEL_COMPILER_INSPECTION_PASS_FUNCTIONS_DECL_HPP
#define STEEL_COMPILER_INSPECTION_PASS_FUNCTIONS_DECL_HPP


#include "common/step_enum.hpp"
#include "common/it/callback_enum.hpp"
#include "common/it/base_callback.hpp"

#include "files/interface.hpp"

#include "clang/Frontend/FrontendActions.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Frontend/CompilerInstance.h"

namespace bld {



using namespace clang::ast_matchers;

// Fw decl
template <callback_kind CbK, step SK>
class Callback;

////////////////////////////////////
//
// GENERIC CALLBACKS
//
////////////////////////////////////
template <callback_kind CbK>
class Callback<CbK, step::inspect> : public clang::ast_matchers::MatchFinder::MatchCallback, public BaseCB {
public:

  Callback(const clang::SourceManager& sm, const clang::ASTContext& ac) : BaseCB(sm, ac) {}

  virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &Result);
private:
};


////////////////////////////////////
//
// FUNCTIONS AST CONSUMER
//
////////////////////////////////////
class FunctionsASTConsumer : public clang::ASTConsumer {
public:
  FunctionsASTConsumer(const clang::SourceManager& sm, const clang::ASTContext& ac); 
  void HandleTranslationUnit(clang::ASTContext &Context) override;
private:

  Callback<callback_kind::function_def,   step::inspect> m_functionDefCB;
  Callback<callback_kind::detect_var_init,   step::inspect> m_varInitOpCB;
  Callback<callback_kind::detect_assignment,   step::inspect> m_assignOpCB;
  Callback<callback_kind::detect_comparison,   step::inspect> m_compareOpCB;
  Callback<callback_kind::detect_unary_int,   step::inspect> m_unaryIntOpCB;

  Callback<callback_kind::function_call,  step::inspect> m_functionCallCB;
  Callback<callback_kind::function_loop,  step::inspect> m_functionLoopCB;

  // Callback<callback_kind::detect_array_access,  step::inspect> m_arrayAccessCB;
  // Callback<callback_kind::detect_pointer_access,  step::inspect> m_pointerAccessCB;

  // Callback<callback_kind::pointer_region_access, step::inspect> m_pointerRegionAccessCB;
  Callback<callback_kind::task_decl,      step::inspect> m_taskDeclCB;

  Callback<callback_kind::register_ctxt,      step::inspect> m_regCtxtCB;
  Callback<callback_kind::register_return_stmt,      step::inspect> m_regReturnCB;


  std::vector<clang::ast_matchers::MatchFinder> m_sequentialFinders;

};



////////////////////////////////////
////////////////////////////////////
//
// FUNCTIONS FRONTEND ACTION
//
////////////////////////////////////
////////////////////////////////////
class FunctionsFrontendAction : public clang::ASTFrontendAction {
public:
  FunctionsFrontendAction();
  bool BeginSourceFileAction(clang::CompilerInstance& CI) override;
  void EndSourceFileAction() override; 
  std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &CI,
                                               llvm::StringRef file) override; 
private:

  key_path m_sourceKeyPath = key_path::undefined;

};

////////////////////////////////////
//
// SET TASK INFO AST CONSUMER
//
////////////////////////////////////

class SetTaskInfoASTConsumer : public clang::ASTConsumer {
public:
  SetTaskInfoASTConsumer(const clang::SourceManager& sm, const clang::ASTContext& ac); 
  void HandleTranslationUnit(clang::ASTContext &Context) override;
private:

  Callback<callback_kind::register_propagated_task_def, step::inspect> m_taskDefCB;

  clang::ast_matchers::MatchFinder m_lastFinder;

};

////////////////////////////////////
////////////////////////////////////
//
// SET TASK INFO FRONTEND ACTION
//
////////////////////////////////////
////////////////////////////////////
class SetTaskInfoFrontendAction : public clang::ASTFrontendAction {
public:
  SetTaskInfoFrontendAction();
  bool BeginSourceFileAction(clang::CompilerInstance& CI) override;
  void EndSourceFileAction() override; 
  std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &CI,
                                               llvm::StringRef file) override; 
private:

  key_path m_sourceKeyPath = key_path::undefined;
  state::filename m_inputFile;
};

} // namespace bld

#endif // STEEL_COMPILER_INSPECTION_PASS_FUNCTIONS_DECL_HPP

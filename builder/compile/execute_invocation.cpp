#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/CodeGen/CodeGenAction.h"

// Adaptation from clang/lib/FrontendTool/ExecuteCompilerInvocation.cpp

static std::unique_ptr<clang::FrontendAction>
CreateFrontendBaseAction(clang::CompilerInstance &CI) {
  using namespace clang::frontend;
  llvm::StringRef Action("unknown");
  (void)Action;

  switch (CI.getFrontendOpts().ProgramAction) {


//    case EmitAssembly:           return std::make_unique<EmitAssemblyAction>();
    case clang::frontend::ActionKind::EmitBC:                 return std::make_unique<clang::EmitBCAction>();
    case clang::frontend::ActionKind::EmitLLVM:               return std::make_unique<clang::EmitLLVMAction>();
    case clang::frontend::ActionKind::EmitLLVMOnly:           return std::make_unique<clang::EmitLLVMOnlyAction>();
//    case EmitCodeGenOnly:        return std::make_unique<EmitCodeGenOnlyAction>();
//    case EmitObj:                return std::make_unique<EmitObjAction>();

    default:    return nullptr;
  }

}

bool ExecuteCompilerInvocation(clang::CompilerInstance *Clang) {

  // If there were errors in processing arguments, don't do anything else.
  if (Clang->getDiagnostics().hasErrorOccurred())
    return false;
  // Create and execute the frontend action.
  // std::unique_ptr<clang::FrontendAction> Act(CreateFrontendAction(*Clang));
  std::unique_ptr<clang::FrontendAction> Act(CreateFrontendBaseAction(*Clang));
  if (!Act)
    return false;
  bool Success = Clang->ExecuteAction(*Act);
  return Success;
}

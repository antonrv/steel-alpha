#ifndef STEEL_COMPILER_COMPILATION_INTERFACE_CLANG_HPP
#define STEEL_COMPILER_COMPILATION_INTERFACE_CLANG_HPP


#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/CompilerInstance.h"

namespace bld {

class PrecompilationModuleAction : public clang::ASTFrontendAction{
public:
  PrecompilationModuleAction();

  std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(clang::CompilerInstance &CI,
                                        llvm::StringRef ifmoduleFn) override;

  bool BeginSourceFileAction(clang::CompilerInstance &CI) override;

  void EndSourceFileAction() override;

private:
  std::unique_ptr<llvm::raw_pwrite_stream>
  CreateOutputFile(clang::CompilerInstance &CI,
                                         llvm::StringRef ifmoduleFn);
};


} // namespace bld


#endif // STEEL_COMPILER_COMPILATION_INTERFACE_CLANG_HPP

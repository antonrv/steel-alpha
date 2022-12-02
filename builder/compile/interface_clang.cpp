#include "clang/Serialization/ASTWriter.h" // PCHGenerator
#include "clang/Frontend/MultiplexConsumer.h" // MultiplexConsumer
#include "clang/Basic/Diagnostic.h" // Diagnostics
#include "clang/Frontend/FrontendDiagnostic.h"

// #include "runtime.hpp"

#include "compile/interface_clang.hpp"
#include "files/interface.hpp"


namespace bld {


PrecompilationModuleAction::PrecompilationModuleAction() {}

std::unique_ptr<clang::ASTConsumer>
PrecompilationModuleAction::CreateASTConsumer(clang::CompilerInstance &CI,
                                        llvm::StringRef ifmoduleFn) {
  std::unique_ptr<llvm::raw_pwrite_stream> OS = CreateOutputFile(CI, ifmoduleFn);
  if (!OS)
    return nullptr;
        
  std::string OutputFile = CI.getFrontendOpts().OutputFile;
  std::string Sysroot;

  auto Buffer = std::make_shared<clang::PCHBuffer>();
  std::vector<std::unique_ptr<clang::ASTConsumer>> Consumers;
 
  // llvm::outs() << "Creating AST consumers within PrecompilationModuleAction\n";
 
  Consumers.push_back(std::make_unique<clang::PCHGenerator>(
      CI.getPreprocessor(), CI.getModuleCache(), OutputFile, Sysroot, Buffer,
      CI.getFrontendOpts().ModuleFileExtensions,
      /*AllowASTWithErrors=*/false,
      /*IncludeTimestamps=*/true,
      //+CI.getFrontendOpts().BuildingImplicitModule,
      /*ShouldCacheASTInMemory=*/true
      //+CI.getFrontendOpts().BuildingImplicitModule)
      ));
  Consumers.push_back(CI.getPCHContainerWriter().CreatePCHContainerGenerator(
      CI, ifmoduleFn.str(), OutputFile, std::move(OS), Buffer));
  return std::make_unique<clang::MultiplexConsumer>(std::move(Consumers));
}


bool PrecompilationModuleAction::BeginSourceFileAction(
    clang::CompilerInstance &CI) {


  if (!CI.getLangOpts().ModulesTS && !CI.getLangOpts().CPlusPlusModules) {
    CI.getDiagnostics().Report(clang::diag::err_module_interface_requires_cpp_modules);
    return false;
  }


  CI.getLangOpts().setCompilingModule(clang::LangOptions::CMK_ModuleInterface);

  return clang::ASTFrontendAction::BeginSourceFileAction(CI);
}

void PrecompilationModuleAction::EndSourceFileAction() {
  // nothing
//  auto ifElemPtr = state::files<file_kind::compilable>::get_element( currentFile );
//  ifElemPtr->get_yield()->set_effect("-fmodule-file=" + m_pcmElemPtr->get_identifier());
}

std::unique_ptr<llvm::raw_pwrite_stream>
PrecompilationModuleAction::CreateOutputFile(clang::CompilerInstance &CI,
                                         llvm::StringRef ifmoduleFn) {
  // return CI.createDefaultOutputFile(/*Binary=*/true, ifmoduleFn, "pcm"); places pcm in same cppm folder
  
  // return CI.createOutputFile(s_rtCompileState->get_build_dir(), /*binary*/true, /*Remove on signal*/false, ifmoduleFn, "pcm", /*Use temporary*/true, /*Create missing dir*/true);

  // register yield of this Fn, which must exist in stte
  // auto pcmElemPtr = state::register_yield<file_kind::compilable, code::interface>( ifmoduleFn.str() );
  auto ifElemPtr = state::files<file_kind::compilable>::get_file_element<code::interface>( ifmoduleFn.str() );

  auto created = CI.createOutputFile(ifElemPtr->get_yield()->get_identifier(), /*binary*/true, /*Remove on signal*/false, ifmoduleFn, "pcm", /*Use temporary*/false, /*Create missing dir*/false);


  return created;
}


} // namespace bld

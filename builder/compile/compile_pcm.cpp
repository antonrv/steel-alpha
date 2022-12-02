#include "clang/Tooling/CompilationDatabase.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/JSONCompilationDatabase.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Serialization/PCHContainerOperations.h"
// #include "clang/CodeGen/CodeGenAction.h"
#include "llvm/Support/VirtualFileSystem.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/ADT/Twine.h"
#include "llvm/Support/MemoryBuffer.h"
#include "clang/Basic/LLVM.h"


#include "compile/interface_clang.hpp"
#include "compile/base.hpp"
#include "compile/compile_aux.hpp"

#include "files/interface.hpp"

#include "options/state/decl.hpp"
#include "options/state/log.hpp"

// #include "element/set_def.hpp"
// #include "paths/def.hpp"
// #include "state/register_yield.hpp"

#include <string>
#include <vector>


namespace bld {

// class PrecompilationModuleAction;

template <>
void compile::set_initial_flags<code::interface>(compilation_flags_t& compFlags, const dependent_file * fElemPtr) const {
  // cannot go here
  //compFlags.push_back("-triple");
  //compFlags.push_back("-x86_64-unknown-linux-gnu-unknown");
  // compFlags.push_back("-v");
  compFlags.push_back("-std=c++2a");
}

template <>
void compile::set_final_flags<code::interface>(compilation_flags_t& compFlags, const dependent_file * fElemPtr) const {
  // nothing
}

template <>
void compile::run<code::interface>(const state::filename& inputFn, const compilation_flags_t& inEff) {

  state::log<opt_kind::log_compile>("Compiling PCM from",inputFn.get_full_name(),"and flags",inEff);
  // state::log<opt_kind::log_compile>("Compiling PCM from",inputFn.get_full_name(),"and flags");

  // Compilation database
  const std::string pcmPath = state::paths<key_path::build_runtime_precomp>::get_path();
  llvm::Twine pcmPathTwine(pcmPath.c_str());
  clang::tooling::FixedCompilationDatabase moduleCompilationDatabase(pcmPathTwine, inEff);

  // We create these objects to pass to different ClangTool instances, with the hope that precompilationd modules would be automatically detected in memory while compiling translated sources, without relying on disk .pcm representations and -fmodule-file specifications. But it is not working either. Leave it just in case in the future we can hack clang to do it. TODO
  std::shared_ptr<clang::PCHContainerOperations> pchContainerOps = std::make_shared<clang::PCHContainerOperations>();
  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> overlayFS = llvm::vfs::getRealFileSystem();
  llvm::IntrusiveRefCntPtr<clang::FileManager> imFS = new clang::FileManager(clang::FileSystemOptions(), overlayFS);
  std::vector<std::string> inputFiles(1, inputFn.get_full_name());

  clang::tooling::ClangTool ToolModules(moduleCompilationDatabase, inputFiles, pchContainerOps, overlayFS, imFS);

  // For performance reasons. see if we can use the interface of clang::tooling::ClangTool, so that we have a single
  // object as a class member and we just use that interface to modify its state (eg pass another filename) TODO


  ToolModules.run( clang::tooling::newFrontendActionFactory<PrecompilationModuleAction>().get() );
  // Consider running all runtime modules with clang::tooling::AllTUsToolExecutor with a JSON compilation database TODO

}

template <>
void compile::run_all<code::interface>() {

  auto compilableInterfaces = state::files<file_kind::compilable>::get_raw<code::interface>();
  for (auto& fElemPtr : compilableInterfaces) {
    run_if_needed<code::interface>( fElemPtr );
  }
}

} // namespace bld

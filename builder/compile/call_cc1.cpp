// #include "clang/Basic/DiagnosticOptions.h"
// #include "clang/Basic/Stack.h"
// #include "clang/Driver/Driver.h"
// #include "clang/Driver/Compilation.h"
// #include "clang/Driver/DriverDiagnostic.h"
// #include "clang/Driver/Options.h"
// #include "clang/Driver/ToolChain.h"
#include "clang/Frontend/CompilerInvocation.h"
// #include "clang/Frontend/SerializedDiagnosticPrinter.h"
// #include "clang/Frontend/TextDiagnosticPrinter.h"


// #include "llvm/Support/InitLLVM.h"
// #include "llvm/ADT/SmallVector.h"
// #include "llvm/Support/TargetSelect.h"
// #include "llvm/ADT/IntrusiveRefCntPtr.h"
// #include "llvm/Option/ArgList.h"
// #include "llvm/Option/OptTable.h"
// #include "llvm/Option/Option.h"
// #include "llvm/ADT/ArrayRef.h"
// #include "llvm/Support/Timer.h"
// #include "llvm/Support/Program.h"


#include "compile/base.hpp"

#include "options/state/decl.hpp"
#include "options/state/log.hpp"
#include "files/name/decl.hpp"


#include <iostream>

extern int cc1_main(llvm::ArrayRef<const char *> Argv, const char *Argv0,
                    void *MainAddr);

extern void cc1_init();

namespace bld {

std::string GetExecutablePath(const char *Argv0, bool CanonicalPrefixes) {
//  if (!CanonicalPrefixes) {
//    llvm::SmallString<128> ExecutablePath(Argv0);
//    // Do a PATH lookup if Argv0 isn't a valid path.
//    if (!llvm::sys::fs::exists(ExecutablePath))
//      if (llvm::ErrorOr<std::string> P =
//              llvm::sys::findProgramByName(ExecutablePath))
//        ExecutablePath = *P;
//    return ExecutablePath.str();
//  }

  // This just needs to be some symbol in the binary; C++ doesn't
  // allow taking the address of ::main however.
  void *P = (void*) (intptr_t) GetExecutablePath;
  return llvm::sys::fs::getMainExecutable(Argv0, P);
}


void compile::initialize() {
  cc1_init();
}

template <code ImplOrEntry>
void compile::run(const state::filename& inputFn, const std::vector<std::string>& inEff) {

  state::log<opt_kind::log_compile>("Compiling object from:",inputFn.get_full_name(),"and flags", inEff);

  std::vector<const char*> vecArgv;
  std::transform(std::begin(inEff), std::end(inEff), std::back_inserter(vecArgv), [](const std::string& str) { return str.c_str(); });

  llvm::ArrayRef<const char*> Argv(vecArgv);

  const char * execName = "no-exec-name";
  void *GetExecutablePathVP = (void *)(intptr_t) GetExecutablePath;
  
  auto retCC1 = cc1_main(Argv, execName, GetExecutablePathVP);

  if (retCC1 != 0) {
    throw std::runtime_error("Compilation failed for : " + inputFn.get_full_name());
  }
//  cc1_main( );
}


template void compile::run<code::implementation>(const state::filename& , const std::vector<std::string>& );
template void compile::run<code::entry>(const state::filename& , const std::vector<std::string>& );


} // namespace bld

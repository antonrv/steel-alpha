#include "lld/Common/Driver.h"
#include "lld/Common/Memory.h"
//#include "llvm/ADT/STLExtras.h"
//#include "llvm/ADT/SmallVector.h"
//#include "llvm/ADT/StringSwitch.h"
//#include "llvm/ADT/Triple.h"
//#include "llvm/ADT/Twine.h"
//#include "llvm/Support/CommandLine.h"
//#include "llvm/Support/Host.h"
//#include "llvm/Support/InitLLVM.h"
//#include "llvm/Support/Path.h"
//#include <cstdlib>






#include "link/base.hpp"

#include "files/interface.hpp"

#include "options/state/decl.hpp"
#include "options/state/log.hpp"



namespace bld {

void linker::set_initial_flags(compilation_flags_t& compFlags, const target_file * fElemPtr) const {

//  compFlags.push_back("/usr/bin/ld.gold"); NEEDED?????? XXX
  compFlags.push_back("-z");
//  compFlags.push_back("relro");
  compFlags.push_back("--hash-style=gnu");
  compFlags.push_back("--eh-frame-hdr");
  compFlags.push_back("-m");
  compFlags.push_back("elf_x86_64");
  // compFlags.push_back("--nostdlib");
  compFlags.push_back("-dynamic-linker");
  compFlags.push_back("/lib64/ld-linux-x86-64.so.2");
  compFlags.push_back("-o");
  compFlags.push_back(static_cast<const felement<file_kind::compiled, code::entry>*>(fElemPtr)->get_yield()->get_identifier());
}

void linker::set_primary_flags(compilation_flags_t& compFlags) const {

  compFlags.push_back("/usr/lib/gcc/x86_64-linux-gnu/8/../../../x86_64-linux-gnu/crt1.o");
  compFlags.push_back("/usr/lib/gcc/x86_64-linux-gnu/8/../../../x86_64-linux-gnu/crti.o");
  compFlags.push_back("/usr/lib/gcc/x86_64-linux-gnu/8/crtbegin.o");
  compFlags.push_back("-L/usr/lib/gcc/x86_64-linux-gnu/8");
  compFlags.push_back("-L/usr/lib/gcc/x86_64-linux-gnu/8/../../../x86_64-linux-gnu");
  compFlags.push_back("-L/lib/x86_64-linux-gnu");
  compFlags.push_back("-L/lib/../lib64");
  compFlags.push_back("-L/usr/lib/x86_64-linux-gnu");
  compFlags.push_back("-L/usr/lib/gcc/x86_64-linux-gnu/8/../../..");
  compFlags.push_back("-L[LLVM-PROJECT-DIR]/build_release/bin/../lib");
  compFlags.push_back("-L/lib");
  compFlags.push_back("-L/usr/lib");
  compFlags.push_back("-plugin");
  compFlags.push_back("[LLVM-PROJECT-DIR]/build_release/bin/../lib/LLVMgold.so");
  compFlags.push_back("-plugin-opt=mcpu=x86-64");
}

void linker::set_final_flags(compilation_flags_t& compFlags, const target_file * fElemPtr) const {

  compFlags.push_back(fElemPtr->get_identifier());
  const auto& lEffects = fElemPtr->get_in_effects_link();
  compFlags.insert(std::end(compFlags), std::begin(lEffects), std::end(lEffects));

  compFlags.push_back("[LLVM-PROJECT-DIR]/build_release/bin/../lib/libc++.so.1");
  compFlags.push_back("-lc++");
  compFlags.push_back("-lc++abi");
  compFlags.push_back("-lclang-cpp");
  compFlags.push_back("-lstdc++");
  compFlags.push_back("-lm");
  compFlags.push_back("-lgcc_s");
  compFlags.push_back("-lgcc");
  compFlags.push_back("-lc");
  compFlags.push_back("/usr/lib/gcc/x86_64-linux-gnu/8/crtend.o");
  compFlags.push_back("/usr/lib/gcc/x86_64-linux-gnu/8/../../../x86_64-linux-gnu/crtn.o");
}

template <>
void linker::run<code::entry>( const state::filename& inputFn, const compilation_flags_t& inEff ) {

  state::log<opt_kind::log_link>("Linking executable from", inputFn.get_full_name(),"and flags",inEff);


  std::vector<const char *> args;
  std::transform(std::begin(inEff), std::end(inEff), std::back_inserter(args), [](const std::string& str) { return str.c_str(); });
  // int argc = args.size();
  // const char ** argv = args.data();

 // llvm::InitLLVM x(argc, argv);
//
  // auto retLink = lld::elf::link(args, /*Can exit early*/false, llvm::outs(), llvm::errs());

  lld::elf::link(args, /*Can exit early*/false, llvm::outs(), llvm::errs());
}

template <code CodK>
//compilation_flags_t // TODO LINKLIB
void
linker::run_if_needed( cfile_t<file_kind::compiled, CodK> fElemPtr ) {

  auto yieldPtr = fElemPtr->get_yield();

  if (yieldPtr == nullptr) {

    yieldPtr = state::register_yield<file_kind::compiled, CodK>( fElemPtr->get_filename() );
    // std::cout << "  Got yield: " << yieldPtr->get_identifier() << "\n";

    compilation_flags_t inEff;

    this->set_initial_flags(inEff, fElemPtr);
    this->set_primary_flags(inEff);

    // TODO LINKLIB
    // Assumed no link dependencies for the moment (we are not treating libs as link targets yet)
    // auto flags = this->run_dependencies<CodK>(fElemPtr);
    // inEff.insert(std::end(inEff), std::begin(flags), std::end(flags));

    this->set_final_flags(inEff, fElemPtr); 

    // Set unique
    inEff.resize( std::distance(std::begin(inEff), std::unique(std::begin(inEff), std::end(inEff))) );

    if (not yieldPtr->same_in_effects(inEff)) {

      // Trigger the actual compilation
      this->run<CodK>( fElemPtr->get_filename(), inEff );

      // TODO LINKLIB
      // not out effects for the moment
      // yieldPtr->reset_out_effects();
      yieldPtr->reset_in_effects(inEff);
      // yieldPtr->template add_out_effect<CodK>(); TODO LINKLIB
    }

  } else { // Else assumed to be valid, otherwise it would not have been registered in cache
    // std::cout << "  Yield already initialized: " << yieldPtr->get_identifier() << "\n";
  }

  // return yieldPtr->get_out_effects(); TODO LINKLIB

}

template void linker::run_if_needed<code::entry>( cfile_t<file_kind::compiled, code::entry> fElemPtr );




} // namespace bld

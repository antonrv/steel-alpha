// DISCLAIMER. These implementations come from reverse-engineering the clang driver processing. At some point, we would discard the useless flags, and we will make everything platform-, system- and arch-independent so that this also works as a cross-compiler for input programs. We will also not depend on gcc whatsoever, and we will pull from std c++ clang includes and libs, apart from the system includes defined at clang installation.

#include "compile/base.hpp"
#include "compile/compile_aux.hpp"

#include "files/interface.hpp"

#include "options/state/decl.hpp"

#include <string>
#include <vector>

namespace bld {



void compile::initialize_primary_flags() {

  m_vecPrimaryFlags.push_back("-mrelocation-model"); // UNCERTAIN
  m_vecPrimaryFlags.push_back("static"); // UNCERTAIN
  m_vecPrimaryFlags.push_back("-mthread-model"); // MANDATORY
  m_vecPrimaryFlags.push_back("posix"); // MANDATORY
  m_vecPrimaryFlags.push_back("-mframe-pointer=all"); //DEBUG MAYBE USELESS
  m_vecPrimaryFlags.push_back("-fmath-errno"); // DEBUG MAYBE USELESS
  m_vecPrimaryFlags.push_back("-fno-rounding-math"); // MAYBE USELESS
  // m_vecPrimaryFlags.push_back("-masm-verbose"); // DEPRECATED IN CLANG11
  m_vecPrimaryFlags.push_back("-mconstructor-aliases"); // MAYBE USELESS
  m_vecPrimaryFlags.push_back("-munwind-tables"); // DEBUG MAYBE USELESS
  // m_vecPrimaryFlags.push_back("-fuse-init-array"); // DEPRECATED IN CLANG11
//  m_vecPrimaryFlags.push_back("-target-cpu"); // PLAT DEPENDENT
//  m_vecPrimaryFlags.push_back("x86-64"); // PLAT DEPENDENT
  m_vecPrimaryFlags.push_back("-dwarf-column-info");  // MAYBE USELESS
  m_vecPrimaryFlags.push_back("-debugger-tuning=gdb"); // MAYBE USELESS
  //m_vecPrimaryFlags.push_back("--pgo-warn-misexpect"); // PUT TO AVOID FAIL WHILE COMPILING ENTRIES
}

void compile::initialize_system_includes() {
  m_vecSystemIncFlags.push_back("-resource-dir"); // INSTALL DEP
  m_vecSystemIncFlags.push_back("[LLVM-PROJECT-DIR]/build_release/lib/clang/11.0.0"); // INSTALL DEP
  //m_vecSystemIncFlags.push_back("-internal-isystem"); // SYS-DEP
  //m_vecSystemIncFlags.push_back("/usr/lib/gcc/x86_64-linux-gnu/8/../../../../include/c++/8");// SYS-DEP
  //m_vecSystemIncFlags.push_back("-internal-isystem"); // SYS-DEP
  //m_vecSystemIncFlags.push_back("/usr/lib/gcc/x86_64-linux-gnu/8/../../../../include/x86_64-linux-gnu/c++/8");// SYS-DEP
  //m_vecSystemIncFlags.push_back("-internal-isystem");// SYS-DEP
  //m_vecSystemIncFlags.push_back("/usr/lib/gcc/x86_64-linux-gnu/8/../../../../include/c++/8/backward");// SYS-DEP
  m_vecSystemIncFlags.push_back("-internal-isystem");// SYS-DEP
  m_vecSystemIncFlags.push_back("[LLVM-PROJECT-DIR]/build_release/bin/../include/c++/v1/");// SYS-DEP
  m_vecSystemIncFlags.push_back("-internal-isystem");// SYS-DEP
  m_vecSystemIncFlags.push_back("/usr/local/include");// SYS-DEP
  m_vecSystemIncFlags.push_back("-internal-isystem");// SYS-DEP
  m_vecSystemIncFlags.push_back("[LLVM-PROJECT-DIR]/build_release/lib/clang/11.0.0/include");// INSTALL DEP
  m_vecSystemIncFlags.push_back("-internal-externc-isystem");// SYS-DEP
  m_vecSystemIncFlags.push_back("/usr/include/x86_64-linux-gnu");// SYS-DEP
  m_vecSystemIncFlags.push_back("-internal-externc-isystem");// SYS-DEP
  m_vecSystemIncFlags.push_back("/include");// SYS-DEP
  m_vecSystemIncFlags.push_back("-internal-externc-isystem");// SYS-DEP
  m_vecSystemIncFlags.push_back("/usr/include");// SYS-DEP
}

void compile::initialize_secondary_flags() {

  m_vecSecondaryFlags.push_back("-fdeprecated-macro"); // MAYBE USELESS
  m_vecSecondaryFlags.push_back("-fdebug-compilation-dir"); // FILE DEP
  m_vecSecondaryFlags.push_back("[LLVM-PROJECT-DIR]/build_release"); // FILE DEP
  m_vecSecondaryFlags.push_back("-ferror-limit"); // OPTIONAL
  m_vecSecondaryFlags.push_back("19"); // OPTIONAL
  // m_vecSecondaryFlags.push_back("-fmessage-length"); // DEPRECATED IN CLANG11
  // m_vecSecondaryFlags.push_back("0");
  m_vecSecondaryFlags.push_back("-fgnuc-version=4.2.1"); // OPTIONAL

  m_vecSecondaryFlags.push_back("-std=c++2a");
  m_vecSecondaryFlags.push_back("-fmodules");
  m_vecSecondaryFlags.push_back("-fmodule-map-file=[LLVM-PROJECT-DIR]/build_release/bin/../include/c++/v1/module.modulemap");
  m_vecSecondaryFlags.push_back("-fmodule-map-file=[LLVM-PROJECT-DIR]/build_release/lib/clang/11.0.0/include/module.modulemap");
  m_vecSecondaryFlags.push_back("-stdlib=libc++");
  // m_vecSecondaryFlags.push_back("-pthread");

  m_vecSecondaryFlags.push_back("-fmodules-validate-system-headers");
  // m_SecondaryectFlags.push_back("-fobjc-runtime=gcc"); // MAYBE USELESS
  m_vecSecondaryFlags.push_back("-fcxx-exceptions"); // MANDATORY
  m_vecSecondaryFlags.push_back("-fexceptions"); // MANDATORY
  // m_vecSecondaryFlags.push_back("-fdiagnostics-show-option"); // DEPRECATED IN CLANG11
  m_vecSecondaryFlags.push_back("-fcolor-diagnostics"); // MANDATORY
  m_vecSecondaryFlags.push_back("-faddrsig"); // MAYBE USELESS

}

void compile::set_system_includes(compilation_flags_t& compFlags) const {

  compFlags.insert(std::end(compFlags), std::begin(m_vecSystemIncFlags), std::end(m_vecSystemIncFlags));
}

void compile::set_primary_flags(compilation_flags_t& compFlags) const {

  compFlags.insert(std::end(compFlags), std::begin(m_vecPrimaryFlags), std::end(m_vecPrimaryFlags));
}

void compile::set_secondary_flags(compilation_flags_t& compFlags) const {

  compFlags.insert(std::end(compFlags), std::begin(m_vecSecondaryFlags), std::end(m_vecSecondaryFlags));
}


template <code ImplOrEntry>
void compile::set_initial_flags(compilation_flags_t& compFlags, const dependent_file * fElemPtr) const {
  //compFlags.push_back("-triple"); // PLAT DEPENDENT
  //compFlags.push_back("-x86_64-unknown-linux-gnu"); // PLAT DEPENDENT
//  compFlags.push_back("-flto"); //
  // compFlags.push_back("-v"); 
//  compFlags.push_back("-emit-obj"); // MANDATORY

  compFlags.push_back("-emit-llvm-bc"); // MANDATORY
  compFlags.push_back("-flto"); // MANDATORY
  compFlags.push_back("-flto-unit"); // MANDATORY
  // compFlags.push_back("-emit-llvm"); // MANDATORY
//  compFlags.push_back("-mrelax-all"); // UNCERTAIN
  compFlags.push_back("-disable-free"); // UNCERTAIN
  compFlags.push_back("-main-file-name"); // FILE DEP
  compFlags.push_back(fElemPtr->get_identifier()); // FILE DEP XXX dont know if this is only for entries TODO

  compFlags.push_back("-fmodules-cache-path=" + state::paths<key_path::build_std>::get_path());
  // Needed to compile against std modules


  set_primary_flags(compFlags);
  set_system_includes(compFlags);
  set_secondary_flags(compFlags);
}

template <code ImplOrEntry>
void compile::set_final_flags(compilation_flags_t& compFlags, const dependent_file * fElemPtr) const {

  compFlags.push_back("-o");
  compFlags.push_back(static_cast<const felement<file_kind::compilable, ImplOrEntry>*>(fElemPtr)->get_yield()->get_identifier());
  compFlags.push_back("-x");
  compFlags.push_back("c++");
  compFlags.push_back(fElemPtr->get_identifier());

}



template <code ImplOrEntry>
void compile::run_all() {

  auto compilableImplementations = state::files<file_kind::compilable>::get_raw<ImplOrEntry>();
  for (auto& fElemPtr : compilableImplementations) {
    run_if_needed<ImplOrEntry>( fElemPtr );
  }
}

template void compile::set_initial_flags<code::implementation>(compilation_flags_t& compFlags, const dependent_file * fElemPtr) const;
template void compile::set_final_flags<code::implementation>(compilation_flags_t& compFlags, const dependent_file * fElemPtr) const;
template void compile::run_all<code::implementation>();

template void compile::set_initial_flags<code::entry>(compilation_flags_t& compFlags, const dependent_file * fElemPtr) const;
template void compile::set_final_flags<code::entry>(compilation_flags_t& compFlags, const dependent_file * fElemPtr) const;
template void compile::run_all<code::entry>();


} // namespace bld

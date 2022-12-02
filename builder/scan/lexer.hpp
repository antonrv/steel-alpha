#ifndef STEEL_COMPILER_SCAN_LEXER_HPP
#define STEEL_COMPILER_SCAN_LEXER_HPP

// #include "clang/Lex/Lexer.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "clang/Basic/TokenKinds.h"
// #include "clang/Lex/MacroArgs.h"
// #include "clang/Lex/MacroInfo.h"
#include "clang/Lex/HeaderSearch.h"
#include "clang/Lex/HeaderSearchOptions.h"
#include "clang/Lex/ModuleLoader.h"
#include "clang/Lex/Preprocessor.h"
#include "clang/Lex/PreprocessorOptions.h"

// #include "files/name/decl.hpp"

#include "files/enum.hpp"

namespace bld {

namespace state {
  class filename;
} // namespace state


class dependent;

class scan_lexer {

private:

  template <file_kind FK, code CodK>
  void run(const state::filename& inputFn);
public:
  scan_lexer();

  template <file_kind FK, code CodK>
  void run_all();

private:

//  state * m_statePtr;
//  friend class state;

  clang::FileSystemOptions FileMgrOpts;
  clang::FileManager FileMgr;
  llvm::IntrusiveRefCntPtr<clang::DiagnosticIDs> DiagID;
  clang::DiagnosticsEngine Diags;
  clang::SourceManager SourceMgr;
  clang::LangOptions LangOpts;
  std::shared_ptr<clang::TargetOptions> TargetOpts;
  llvm::IntrusiveRefCntPtr<clang::TargetInfo> Target;

//  clang::TrivialModuleLoader ModLoader;
// std::unique_ptr<clang::Preprocessor> m_preprocessorUptr;
};




} // namespace bld


#endif // STEEL_COMPILER_SCAN_LEXER_HPP

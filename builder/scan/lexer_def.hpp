#ifndef STEEL_COMPILER_SCAN_LEXER_DEF_HPP
#define STEEL_COMPILER_SCAN_LEXER_DEF_HPP

#include "scan/lexer.hpp"

#include "files/interface.hpp"

#include "llvm/ADT/Twine.h"
#include "llvm/Support/MemoryBuffer.h"

namespace bld {

// defined in capture.cpp
template <code CodK>
void interpret_token(clang::Token& tok, clang::Lexer& rawLexer, dependent_file * yieldPtr);


template <file_kind FK, code CodK>
void scan_lexer::run(const state::filename& inputFn) {

  // std::cout << "Scanning : " << inputFn << '\n';
  



  static_assert(FK == file_kind::autogen || FK == file_kind::runtime || FK == file_kind::translation);

  clang::FileID FID;
  auto fileEntry = FileMgr.getFile(inputFn.get_full_name());
  if (fileEntry) {
    FID = SourceMgr.createFileID(*fileEntry, clang::SourceLocation(), clang::SrcMgr::C_User);
  } else {
    throw std::runtime_error("Could not get FileEntry from " + inputFn.get_full_name());
  }
 // Lexer::Lexer(FileID FID, const llvm::MemoryBuffer *FromFile,
 //              const SourceManager &SM, const LangOptions &langOpts)

  const llvm::MemoryBuffer *Buf = SourceMgr.getBuffer(FID);
  // llvm::Twine fnTwine(inputFn.c_str());
  // std::unique_ptr<llvm::MemoryBuffer>& memBuffer = llvm::MemoryBuffer::getFile(fnTwine).get();
  clang::Lexer rawLexer(FID, Buf, SourceMgr, LangOpts);

//  clang::Preprocessor& ppRef = *m_preprocessorUptr;
//  ppRef.EnterSourceFile(FID, nullptr, clang::SourceLocation());

  auto yieldPtr = state::register_yield<FK, CodK>(inputFn);

  clang::Token tok;
  do {
    // ppRef.Lex(tok);
    rawLexer.LexFromRawLexer(tok);

    // std::cout << clang::tok::getTokenName(tok.getKind()) << '\n';

    interpret_token<CodK>(tok, rawLexer, yieldPtr);
  } while(tok.isNot(clang::tok::eof));

//  ppRef.EndSourceFile();
}

template <file_kind FK, code CodK>
void scan_lexer::run_all() {
  auto fileElems = state::files<FK>::template get_raw<CodK>();

  for (const auto& fElem : fileElems) {
    this->run<FK, CodK>( fElem->get_filename() );
  }
}

} // namespace bld


#endif // STEEL_COMPILER_SCAN_LEXER_DEF_HPP

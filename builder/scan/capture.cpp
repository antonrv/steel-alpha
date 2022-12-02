// Revisit includes. Not all needed here TODO
// #include "clang/Tooling/CompilationDatabase.h"
// #include "clang/Tooling/CommonOptionsParser.h"
// #include "clang/Tooling/JSONCompilationDatabase.h"
// #include "clang/Tooling/Tooling.h"
// #include "clang/Serialization/PCHContainerOperations.h"
// #include "clang/Frontend/CompilerInstance.h"
// // #include "clang/CodeGen/CodeGenAction.h"
// #include "llvm/Support/VirtualFileSystem.h"
// #include "llvm/Support/CommandLine.h"
// #include "llvm/ADT/Twine.h"
// #include "llvm/Support/MemoryBuffer.h"
// #include "clang/Basic/LLVM.h"
#include "clang/Lex/Lexer.h"
// #include "clang/Basic/Diagnostic.h"
// #include "clang/Basic/DiagnosticOptions.h"
// #include "clang/Basic/FileManager.h"
// #include "clang/Basic/LangOptions.h"
// #include "clang/Basic/SourceLocation.h"
// #include "clang/Basic/SourceManager.h"
// #include "clang/Basic/TargetInfo.h"
// #include "clang/Basic/TargetOptions.h"
#include "clang/Basic/TokenKinds.h"
#include "clang/Lex/HeaderSearch.h"
#include "clang/Lex/HeaderSearchOptions.h"
#include "clang/Lex/MacroArgs.h"
#include "clang/Lex/MacroInfo.h"
#include "clang/Lex/ModuleLoader.h"
#include "clang/Lex/Preprocessor.h"
// #include "clang/Lex/PreprocessorOptions.h"

#include "files/interface.hpp"
#include "files/module/decl.hpp"
#include "files/state/module/decl.hpp"

#include "options/state/decl.hpp"

#include "options/state/log.hpp"

// #include <cstring>
// #include <cstdint>

namespace bld {

static bool
verify_final_module_name(const std::string& name) {
  return (name.front() == '<' && name.back() == '>') || (name.front() != '<' && name.back() != '>');
}


static
std::string get_identifier_name(clang::Token& tok, clang::Lexer& rawLexer) {
  rawLexer.LexFromRawLexer(tok);
  if (tok.getKind() == clang::tok::raw_identifier) {
    //return tok.getIdentifierInfo()->getName().str();
    return tok.getRawIdentifier().str();
  } else if (tok.getKind() == clang::tok::less) {
    return "<";
  }
  return "";
}

static
std::string get_include_header(clang::Token& tok, clang::Lexer& rawLexer) {
  rawLexer.LexFromRawLexer(tok);
  //if (tok.getKind() == clang::tok::string_literal) {
  if (tok.isLiteral()) {
    const char * startData = tok.getLiteralData();
    if (startData[0] == '\"') {
      const char * endData = std::strchr(startData+1, '\"');
      auto d = std::distance(startData, endData);
      std::string retString(startData + 1, d - 1); //(std::intptr_t)endData - (std::intptr_t)startData);
      return retString;
    }
  }
  return "";
}

// This func ensures there is a ';' at the end of the module name and also takes into account '.' separated submodules.
static
void complete_module_name(std::string& name, clang::Token& tok, clang::Lexer& rawLexer) {
  if (tok.isNot(clang::tok::eof)) { 
    rawLexer.LexFromRawLexer(tok);
    while (tok.isOneOf(clang::tok::raw_identifier, clang::tok::period, clang::tok::greater)) {
      // Keep extending module name. We treat the 'dot/period' in module name uniformly
      // (according to modules TS or C++20). To be revisited TODO.
      if (tok.getKind() == clang::tok::period) {
        name += ".";
      } else if (tok.getKind() == clang::tok::greater) {
        name += ">";
      } else { // identifier
        name += tok.getRawIdentifier(); // getIdentifierInfo()->getName().str();
      }
      rawLexer.LexFromRawLexer(tok);
    }
  }
  if (tok.getKind () != clang::tok::semi || not verify_final_module_name(name)) {
    name = ""; // module name is invalid
  } // Else correct, leave the module name the same
}


static
bool verify_identifier(clang::Token& tok, clang::Lexer& rawLexer, const std::string& idName) {
  if (tok.isNot(clang::tok::eof)) { 
    rawLexer.LexFromRawLexer(tok);
    if (tok.getKind() == clang::tok::raw_identifier) {
      // return (tok.getIdentifierInfo()->getName().str() == idName);
      return (tok.getRawIdentifier() == idName);
    }
  }
  return false;
}


static
void capture_module_implementation(clang::Token& tok, clang::Lexer& rawLexer, dependent_file * yieldPtr) {
 
  // Get ModuleName token
  std::string moduleName = get_identifier_name(tok, rawLexer);

  complete_module_name(moduleName, tok, rawLexer);

  if (not moduleName.empty()) {
    // Register module if not existing
    auto mod = state::modules::record(moduleName);
    mod->add_new_implementation(static_cast<felement<file_kind::compilable, code::implementation>*>(yieldPtr));
    // We add the imported module to the implementation so that we can set "-fmodule-file="  with the module interface file pcm.
    yieldPtr->add_imported_module(mod);

    state::log<opt_kind::log_scan>("Module implementation", moduleName, "for file", yieldPtr->get_identifier());
  }
}


static
void capture_module_to_import(clang::Token& tok, clang::Lexer& rawLexer, dependent_file * yieldPtr) {

  // Here we register the module if the following tokens '[import] [ModName] [;]' exist.

  // Get ModuleName token
  std::string moduleName = get_identifier_name(tok, rawLexer);

  complete_module_name(moduleName, tok, rawLexer);

  if (not moduleName.empty()) {
    // Register module if not existing
    auto mod = state::modules::record(moduleName);
    // Add it to this file as a module to be imported
    yieldPtr->add_imported_module(mod);

    state::log<opt_kind::log_scan>("Module import", moduleName, "for file", yieldPtr->get_identifier());
  }
}


static
void capture_module_to_export(clang::Token& tok, clang::Lexer& rawLexer, dependent_file * yieldPtr) {

  // Here we register the module if the following tokens '[export] [module] [ModName] [;]' exist.
  // Here we register the module if the following tokens '[export] [import] [ModName] [;]' exist.
  // We don't want to handle the unsuccessful cases, as they will be properly identified by clang downstream.

  std::string moduleName;

  auto idName = get_identifier_name(tok, rawLexer);

  if (idName == "module") {
    moduleName = get_identifier_name(tok, rawLexer);
  } else if (idName == "import"){
    capture_module_to_import(tok, rawLexer, yieldPtr);
    return;
  }

  complete_module_name(moduleName, tok, rawLexer);
  if (not moduleName.empty()) {
    
    auto mod = state::modules::record(moduleName);
    mod->set_interface( static_cast<felement<file_kind::compilable, code::interface>*>(yieldPtr) );

    state::log<opt_kind::log_scan>("Module export", moduleName, "for file", yieldPtr->get_identifier());
  }
}

static
void capture_include_header(clang::Token& tok, clang::Lexer& rawLexer, dependent_file * yieldPtr) {
  //std::cout << "WITHIN CAPTURE INCLUDE HEADER\n";
  if (verify_identifier(tok, rawLexer, "include")) {
    std::string headerLiteral = get_include_header(tok, rawLexer);

    // This header file must be placed either in any of the user include paths or in the steel include folders. Locate all the folders where it exist and add them as header dependencies

    std::vector<std::string> incdirMatches;
    if (state::paths<key_path::user_include>::is_set()) {
      incdirMatches = state::paths<key_path::user_include>::get_paths_containing_str(headerLiteral);
    }
    // if (state::paths<key_path::steel_runtime_include>::is_set()) { must always be set
      auto incdirMatchesSteelRuntime = state::paths<key_path::steel_runtime_include>::get_paths_containing_str(headerLiteral);
      incdirMatches.insert(std::end(incdirMatches), std::begin(incdirMatchesSteelRuntime), std::end(incdirMatchesSteelRuntime));
    // }

    // auto incdirMatchesSteel = state::paths<key_path::steel_include>::get_paths_containing_str(headerLiteral);
    // incdirMatches.insert(std::end(incdirMatches), std::begin(incdirMatchesSteel), std::end(incdirMatchesSteel));

    if (incdirMatches.empty()) {
      throw std::runtime_error("Could not locate filename " + headerLiteral);
    }

    state::log<opt_kind::log_scan>("Header include", headerLiteral, "for file", yieldPtr->get_identifier());

    for (const auto& p : incdirMatches) {
      yieldPtr->add_include_route(p);

      state::log<opt_kind::log_scan>("Matched in path", p);
    }

  }
}

template <code CodK>
void interpret_token(clang::Token& tok, clang::Lexer& rawLexer, dependent_file * yieldPtr);

template <>
void interpret_token<code::interface>(clang::Token& tok, clang::Lexer& rawLexer, dependent_file * yieldPtr) {

  //std::cout << "interpreting token in interface\n";

  if (tok.getKind() == clang::tok::raw_identifier) {
    // std::string idName = tok.getIdentifierInfo()->getName().str();
    std::string idName = tok.getRawIdentifier().str();
    //std::cout << idName << '\n';
    // if (tok.getIdentifierInfo()->isModulesImport()) {
    if (idName == "import") {
      // Reading line [import] [ModuleName] [;]
      // idName == import
      capture_module_to_import(tok, rawLexer, yieldPtr);
    //} else if (tok.getKind() == clang::tok::kw_export) {
    } else if (idName == "export") {
    //std::cout << "kw_export" << '\n';
      // Reading line [export] [module] [ModuleName] [;]
    capture_module_to_export(tok, rawLexer, yieldPtr);

    // Handle the [export] [import] [ModuleName] [;] TODO
    }
  } else if (tok.getKind() == clang::tok::hash) {
    //std::cout << "hash" << '\n';
    // Reading line  [#] [include] [string_literal]
    capture_include_header(tok, rawLexer, yieldPtr);
  }
}

template <>
void interpret_token<code::implementation>(clang::Token& tok, clang::Lexer& rawLexer, dependent_file * yieldPtr) {

  //std::cout << "interpreting token in implementation\n";

  if (tok.getKind() == clang::tok::raw_identifier) {
    std::string idName = tok.getRawIdentifier().str();
    //if (tok.getIdentifierInfo()->isModulesImport()) {
    if (idName == "import") {
      // Reading line [import] [ModuleName] [;]
      // idName == import
      capture_module_to_import(tok, rawLexer, yieldPtr);
    } else if (idName == "module") {
      // Reading line [module] [ModuleName] [;]
      capture_module_implementation(tok, rawLexer, yieldPtr);
    }
  } else if (tok.getKind() == clang::tok::hash) {
    // Reading line  [#] [include] [string_literal]
    capture_include_header(tok, rawLexer, yieldPtr);
  }
}


template <>
void interpret_token<code::entry>(clang::Token& tok, clang::Lexer& rawLexer, dependent_file * yieldPtr) {

  //std::cout << "interpreting token in entry\n";

  if (tok.getKind() == clang::tok::raw_identifier) {
    std::string idName = tok.getRawIdentifier().str();
    //if (tok.getIdentifierInfo()->isModulesImport()) {
    if (idName == "import") {
      // Reading line [import] [ModuleName] [;]
      // idName == import
      capture_module_to_import(tok, rawLexer, yieldPtr);
    }
  } else if (tok.getKind() == clang::tok::hash) {
    // Reading line  [#] [include] [string_literal]
    capture_include_header(tok, rawLexer, yieldPtr);
  }
}



} // namespace bld

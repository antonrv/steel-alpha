#ifndef STEEL_COMPILER_COMMON_AST_ANALYZER_HPP
#define STEEL_COMPILER_COMMON_AST_ANALYZER_HPP

#include "llvm/Support/CommandLine.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

#include <vector>
#include <string>


namespace bld {

class ast_analyzer {
protected:

  std::vector<std::string> m_sources;

  std::unique_ptr<clang::tooling::FixedCompilationDatabase> m_compilationDatabaseUptr;
  std::unique_ptr<clang::tooling::ClangTool> m_toolUptr;
public:

  ast_analyzer(std::vector<std::string> src);
};

} // namespace steel::conmpiler

#endif // STEEL_COMPILER_COMMON_AST_ANALYZER_HPP

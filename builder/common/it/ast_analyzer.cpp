#include "common/it/ast_analyzer.hpp"


namespace bld {

ast_analyzer::ast_analyzer(std::vector<std::string> src) : m_sources(src) {

    std::vector<std::string> noOpts;

    // Compilation database
    std::string trPath = "./"; //"/tmp/input"; //state::paths<key_path::build_translate>::get_path();
    llvm::Twine trPathTwine(trPath.c_str());
    m_compilationDatabaseUptr = std::make_unique<clang::tooling::FixedCompilationDatabase>(trPathTwine, noOpts);
    m_toolUptr = std::make_unique<clang::tooling::ClangTool>(*m_compilationDatabaseUptr, m_sources);
}

} // namespace bld

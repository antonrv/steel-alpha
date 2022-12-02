#ifndef STEEL_COMPILER_COMMON_BASE_CALLBACK_HPP
#define STEEL_COMPILER_COMMON_BASE_CALLBACK_HPP

namespace clang {
  class SourceManager;
  class ASTContext;
} // namespace clang

namespace bld {

////////////////////////////////////
////////////////////////////////////
//
// MATCH CALLBACKS
//
////////////////////////////////////
////////////////////////////////////
class BaseCB {
public:
  BaseCB(const clang::SourceManager& sm, const clang::ASTContext& ac);
protected:
  const clang::SourceManager& m_sourceManager;
  const clang::ASTContext& m_astContext;
};


} // namespace bld

#endif // STEEL_COMPILER_COMMON_BASE_CALLBACK_HPP

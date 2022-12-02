#ifndef STEEL_CMP_TRANSLATION_CB_AUX_LOCATE_ARGS_HPP
#define STEEL_CMP_TRANSLATION_CB_AUX_LOCATE_ARGS_HPP

namespace bld {

template <typename ClangT>
std::pair<clang::SourceLocation, size_t>
locate_start_args(const ClangT * cPtr, const clang::ASTContext& ctxt) {

  // It seems there is no way in clang::FunctionDecl and inherited classes to directly get the position of the start of the argument list, so we get it manually
  auto insertLoc = cPtr->getBeginLoc();

  auto funSR = cPtr->getSourceRange();
  auto beginFullLoc = ctxt.getFullLoc(funSR.getBegin());
  auto endFullLoc = ctxt.getFullLoc(funSR.getEnd());
  std::string funStr = std::string(beginFullLoc.getCharacterData(), std::distance(beginFullLoc.getCharacterData(), endFullLoc.getCharacterData() + 1));
  auto foundStartArg = funStr.find('(');
  if (foundStartArg == std::string::npos) {
    throw std::logic_error("Could not find parameter left parenthesis in " + funStr);
  }

  return std::make_pair(insertLoc, foundStartArg);
}




} // namespace bld

#endif // STEEL_CMP_TRANSLATION_CB_AUX_LOCATE_ARGS_HPP

#ifndef STEEL_COMPILER_TRANSLATION_TRANSLATOR_HPP
#define STEEL_COMPILER_TRANSLATION_TRANSLATOR_HPP

#include "common/it/ast_analyzer.hpp"

#include "files/name/decl.hpp"

namespace bld {

enum class code : std::size_t;

class translator : public ast_analyzer {
public:

  translator(const std::vector<state::filename>& src);

  void run();
};

} // namespace bld

#endif //  STEEL_COMPILER_TRANSLATION_TRANSLATOR_HPP

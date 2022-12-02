#ifndef STEEL_COMPILER_INSPECTION_INSPECTOR_HPP
#define STEEL_COMPILER_INSPECTION_INSPECTOR_HPP

#include "common/it/ast_analyzer.hpp"

#include "files/name/decl.hpp"

namespace bld {

class inspector : public ast_analyzer {

public:

  inspector(const std::vector<state::filename>& src);

  void run();

};

} // namespace bld

#endif // STEEL_COMPILER_INSPECTION_INSPECTOR_HPP

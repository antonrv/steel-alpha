#ifndef STEEL_COMPILER_ELEMENT_DEPENDENT_FILE_HPP
#define STEEL_COMPILER_ELEMENT_DEPENDENT_FILE_HPP


#include "files/felement/base.hpp"
#include "files/module/decl.hpp"

namespace bld {



// Something that can be compiled
class dependent_file : public base_felement {
private:
  set_cmodule_t m_importedModules;
  std::vector<std::string> m_includeRoutes;
public:

  dependent_file(const state::filename& fn) : base_felement(fn) {}
  dependent_file(const state::filename& fn, std::filesystem::file_time_type ftt) : base_felement(fn, ftt) {}

  void add_imported_module(cmodule_t newMod) {
    m_importedModules.insert( newMod );
  }

  set_cmodule_t get_imported_modules() const {
    return m_importedModules;
  }

  void add_include_route(const std::string incRoute) {
    m_includeRoutes.push_back( incRoute );
  }

  const std::vector<std::string>&
  get_include_routes() const {
    return m_includeRoutes;
  }

};

} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_DEPENDENT_FILE_HPP

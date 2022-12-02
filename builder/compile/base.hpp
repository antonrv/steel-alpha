#ifndef STEEL_COMPILER_BACKEND_BASE_HPP
#define STEEL_COMPILER_BACKEND_BASE_HPP


#include "files/interface.hpp"

#include "files/module/decl.hpp"

#include <string>
#include <vector>

namespace clang {
  class CompilerInstance;
} // namespace clang


namespace bld {


class PrecompilationModuleAction;

class dependent_file;

template <file_kind, code>
class felement;

using compilation_flags_t = std::vector<std::string>;

class compile {

  compilation_flags_t m_vecSystemIncFlags;
  compilation_flags_t m_vecPrimaryFlags;
  compilation_flags_t m_vecSecondaryFlags;

  // pchcontaineroperations already built by default in ci
//  std::unique_ptr<clang::CompilerInstance> m_ciUptr;
//  std::unique_ptr<PrecompilationModuleAction> m_pcmActionUptr;
private:
  void initialize_system_includes();
  void initialize_primary_flags();
  void initialize_secondary_flags();

  void set_system_includes(compilation_flags_t& compFlags) const;
  void set_primary_flags(compilation_flags_t& compFlags) const;
  void set_secondary_flags(compilation_flags_t& compFlags) const;

  template <code CodK>
  void set_initial_flags(compilation_flags_t& compFlags, const dependent_file * fElemPtr) const;

  template <code CodK>
  void set_final_flags(compilation_flags_t& compFlags, const dependent_file * fElemPtr) const;

  void initialize();
private:

  template <code CodK>
  void run(const state::filename& inputFn, const std::vector<std::string>& inputEffects);

  template <code CodK>
  compilation_flags_t
  run_dependencies(const dependent_file * fElemPtr);

  template <code CodK>
  compilation_flags_t
  run_if_needed(const felement<file_kind::compilable, CodK> * fElemPtr);

  void gather_link_dependencies(std::set<std::string>& modulesLinkEff, set_cmodule_t& depModules, cmodule_t inModPtr);


public:

  void set_object_flags();

  compile();

  template <code CodK>
  void run_all();
};

} // namespace bld

#endif // STEEL_COMPILER_BACKEND_BASE_HPP

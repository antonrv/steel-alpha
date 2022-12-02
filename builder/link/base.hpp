#ifndef STEEL_COMPILER_LINKER_BASE_HPP
#define STEEL_COMPILER_LINKER_BASE_HPP

#include "files/interface.hpp"

#include <string>
#include <vector>

namespace bld {

namespace state {
  class filename;
} // namespace state

class target_file;

template <file_kind, code>
class felement;

class linker {
private:

  using compilation_flags_t = std::vector<std::string>;

  void set_initial_flags(compilation_flags_t& compFlags, const target_file * fElemPtr) const;
  void set_primary_flags(compilation_flags_t& compFlags) const;

  void set_final_flags(compilation_flags_t& compFlags, const target_file * fElemPtr) const;


  template <code CodK>
  void run_if_needed( cfile_t<file_kind::compiled, CodK> fElemPtr );

  // template <code CodK>
  // compilation_flags_t // TODO LINKLIB
  // run_if_needed( felement<file_kind::compiled, CodK> * fElemPtr );



  template <code CodK>
  void run( const state::filename& fn, const compilation_flags_t& inEff );
public:

  linker();

  template <code CodK>
  void run_all();

};

} // namespace bld

#endif // STEEL_COMPILER_LINKER_BASE_HPP

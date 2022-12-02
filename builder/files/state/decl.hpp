#ifndef STEEL_COMPILER_STATE_FILES_HPP
#define STEEL_COMPILER_STATE_FILES_HPP

#include "files/typedef.hpp"

#include "files/name/decl.hpp"

#include <string>
#include <tuple>

namespace bld {


template <file_kind FK, code CodK>
class felement;

namespace state {


template <file_kind FK>
class files {
private:

  using own_files_t = std::tuple<
      set_own_file_t<FK, code::interface>,
      set_own_file_t<FK, code::implementation>,
      set_own_file_t<FK, code::entry>
  >;

  static own_files_t s_owned;


private:


  // Private because it returns owned objects. 
  template <code CodK>
  static
  set_own_file_t<FK, CodK> &
  get_owned_files();
  
//  template <code CodK>
//  const set_own_file_t<FK, CodK> &
//  get_owned_files();

public:

  template <code CodK>
  static
  file_t<FK,CodK> record(filename id);

  template <code CodK>
  static
  file_t<FK,CodK> get_file_element(const std::string& id);

  template <code CodK>
  static
  set_file_t<FK, CodK> get_raw();

  static
  void print_elements();

  template <code CodK>
  static
  cfile_t<FK,CodK> find_file(const std::string& id);
  // cfileb_t find_file(const std::string& id);

  static
  cfileb_t get_poly_file(const std::string& id);

  static
  set_cfileb_t get_all_files();

public:
  static
  void record_filename(filename fn);

//  static
//  const base_felement* find(const std::string& id);
};

filename find_filename(const std::string& fullFilenameStr);

} // namespace state

} // namespace bld

#endif // STEEL_COMPILER_STATE_FILES_HPP

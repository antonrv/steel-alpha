#ifndef STEEL_COMPILER_STATE_PATHS_DECL_HPP
#define STEEL_COMPILER_STATE_PATHS_DECL_HPP

#include "files/enum.hpp"
#include "files/paths/dir.hpp"
#include "files/name/decl.hpp"
#include "options/typedef.hpp" // option_map_t

#include <vector>
#include <string>
#include <map>



namespace bld::state {


template <key_path KP>
class paths {
private:
  static dir<KP> s_pathInfo;
public:

  static
  void set_path(std::string p);

  static
  std::string get_path();

  static
  bool is_set();

  static
  void add_path(const std::string& p);

  static
  const std::vector<std::string> get_all_paths();

  static
  std::vector<std::string> 
  get_paths_containing_str(const std::string& strFn);

//  static
//  std::vector<std::string> get_file_paths(const std::string& strFn);
private:


  template <path_scan PS>
  static
  std::vector<filename>
  get_filenames_in_dir(const std::string& targetDir);

public:

  template <path_scan PS>
  static
  std::vector<filename>
  get_filenames();

  static
  bool set_if_existing(const option_map_t& optMap);

  static
  void set_as_derived();
};


void set_all_paths(const option_map_t& optMap);

bool is_valid_path(const std::string& pathFlag);

} // namespace bld::state

#endif // STEEL_COMPILER_STATE_PATHS_DECL_HPP

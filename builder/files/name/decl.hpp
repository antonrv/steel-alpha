#ifndef STEEL_COMPILER_STATE_FILENAME_HPP
#define STEEL_COMPILER_STATE_FILENAME_HPP


#include "files/paths/enum.hpp"


#include <string>

namespace bld {

std::string get_pc_string_path(key_path kp);

  key_path get_key_path( const std::string& keypathStr );

std::string
discard_path(const std::string& fn);

void get_paths_in_dir_containing_str(std::vector<std::string>& retSources, const std::string& strFn, const std::string& targetDir);

bool file_exists(const std::string& strFilename);

std::vector<std::string> get_defined_paths();

} // namespace bld



namespace bld::state {


class filename {
private:
  std::string m_rootPathStr;
  key_path m_rootPath = key_path::undefined;
  std::string m_filename;

public:
  filename() = default;
  filename(const filename&) = default;

  filename(key_path kp, std::string fn, path_require pr);

  filename(std::string kp, std::string fn, path_require pr);

  filename& operator=(const filename&) = default;

  bool operator==(const filename&) const;
  bool operator!=(const filename&) const;

  key_path get_head() const;

  std::string get_head_str() const;

  const std::string& get_tail() const;

  std::string get_stem() const;

  std::string get_full_name() const;
};

} // namespace bld::state

#endif // STEEL_COMPILER_STATE_FILENAME_HPP

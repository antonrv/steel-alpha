#ifndef STEEL_COMPILER_DRIVER_OPTIONS_HPP
#define STEEL_COMPILER_DRIVER_OPTIONS_HPP

#include "options/typedef.hpp"

#include "files/name/decl.hpp"

#include <vector>

namespace bld {


enum class step : std::size_t;

class options {
private:


  const std::string m_binFn;
  const std::vector<std::string> m_vArgs;

  option_map_t m_optionMap;

  std::vector<state::filename> m_files;
  // std::vector<std::string> m_flags;
  std::vector<std::string> m_includes;

private:

  void register_option(const std::string& argElem);

  void validate_flags() const;

public:

  // Constructor for compiling input sources
  options(int argc, const char** argv);

  options(const std::vector<std::string>& args);

  // template <step S>
  // void process();

  const option_map_t& get_map_ref() const;

  std::string get_parsed_info( ) const;

  void reset_state() const;

  std::vector<state::filename> get_input_filenames() const;
};

} // namespace bld

#endif // STEEL_COMPILER_DRIVER_OPTIONS_HPP

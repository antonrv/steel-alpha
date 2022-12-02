#include "options/init.hpp"

// #include "common/options.hpp"
#include "common/aux.hpp"

#include "options/state/decl.hpp"

#include "files/paths/decl.hpp"

#include "common/util.hpp"

// #include "options/state/decl.hpp"

#include <sstream>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <numeric>
#include <iostream>

namespace bld {



static bool is_option(const std::string& str) {
  return str[0] == '-';
}

void options::register_option(const std::string& argElem) {
  if (argElem.find("=") != std::string::npos) {
    auto splitOpt = split_string(argElem, '=');
    if (splitOpt.size() != 2) {
      throw std::runtime_error("Cannot parse option : " + argElem);
    }
    m_optionMap[splitOpt[0]] = splitOpt[1];

  } else if (argElem[1] == 'I') {
    auto userPath = argElem.substr(2);
    append_char(userPath, '/');
    m_includes.push_back(userPath);
    return;
  } else {
    m_optionMap[argElem] = "ENABLED";
    // state::options::enable(argElem); DEPRECATED
    // m_flags.push_back(argElem);
  }
}

void options::reset_state() const {

  // Need to reset state at the beginning of each step

  state::set_all_paths( m_optionMap ); // TODO state::paths::set_all( optionMap );

  state::options::set_all( m_optionMap );

    // Assert XOR opt_kind::app, opt_kind::runtime_test
  auto compatibleConfig =
      static_cast<unsigned>(state::options::is_set<opt_kind::app>()) + 
      static_cast<unsigned>(state::options::is_set<opt_kind::builder_test>()) +
      static_cast<unsigned>(state::options::is_set<opt_kind::runtime_test>());

  if (compatibleConfig != 1) {
    throw std::runtime_error("Options [-app], [-runtime-test] [-builder-test] [-parser-test] must be exclusively set : " + std::to_string(compatibleConfig));
  }


}


void options::validate_flags() const {

  auto undefOpts = state::options::get_undefined( m_optionMap );

  auto s2s = [] (std::string str) { return str; };

  auto invalidFlags = transform_vec_if( undefOpts,
      [] (const std::string& undefOpt) {
        return not state::is_valid_path(undefOpt); // state::paths::is_valid TODO
      },
      s2s
    );

  if (not invalidFlags.empty()) {
    auto errStr = string_from_container( invalidFlags, [] (std::string str) { return "Invalid flag : " + str; } );

    // Show possibilities when --help-paths, --help-opts TODO
    throw std::runtime_error( errStr );
  }

}

// Constructor for compiling input sources
options::options(int argc, const char** argv) :
  m_binFn(argv[0]),
  m_vArgs(argv, argv + argc)
{
  try {

    state::paths<key_path::pwd>::set_if_existing(m_optionMap);

    for (auto argElem : m_vArgs) {
      if (is_option(argElem)) {
        this->register_option(argElem);
      } else if (argElem == m_binFn) {
        // do nothing
      } else if (file_exists(argElem)) {
        m_files.push_back(state::filename(key_path::pwd, argElem, path_require::exist));
      } else {
        throw std::runtime_error("Ignored argument (file exists?): " + argElem);
      }
    }

    this->validate_flags();

    this->reset_state();

  } catch (const std::runtime_error& rte) {
    std::cerr << ":::Driver options. Runtime error caught : " << rte.what() << " V\n" << this->get_parsed_info() << '\n';
  } catch (const std::logic_error& le) {
    std::cerr << ":::Driver options. Logic error caught : " << le.what() << " V\n" << this->get_parsed_info() << '\n';
  } catch (const std::exception& e) {
    std::cerr << ":::Driver options. Generic error caught : " << e.what() << " V\n" << this->get_parsed_info() << '\n';
  } catch (...) {
    std::cerr << ":::Driver options. Unknown error caught.\n" << this->get_parsed_info() << '\n';
  }

}

// Constructor for parser tests
options::options(const std::vector<std::string>& args) :
  m_binFn(args[0]),
  m_vArgs(args)
{

  try {

    for (auto argElem : m_vArgs) {
      if (is_option(argElem)) {
        this->register_option(argElem);
      }
    }

    state::options::set_all( m_optionMap );

    if (not state::options::is_set<opt_kind::parser_test>()) {
      throw std::runtime_error("Option [-parser-test] must be set");
    }

  } catch (const std::runtime_error& rte) {
    std::cerr << ":::Driver options. Runtime error caught : " << rte.what() << " V\n" << this->get_parsed_info() << '\n';
  } catch (const std::logic_error& le) {
    std::cerr << ":::Driver options. Logic error caught : " << le.what() << " V\n" << this->get_parsed_info() << '\n';
  } catch (const std::exception& e) {
    std::cerr << ":::Driver options. Generic error caught : " << e.what() << " V\n" << this->get_parsed_info() << '\n';
  } catch (...) {
    std::cerr << ":::Driver options. Unknown error caught.\n" << this->get_parsed_info() << '\n';
  }
}

std::vector<state::filename> options::get_input_filenames() const {
  return m_files;
}

const option_map_t& options::get_map_ref() const {
  return m_optionMap;
}


std::string options::get_parsed_info( ) const {

  std::string retStr;

  retStr += "Arguments:";
  retStr += std::accumulate(std::begin(m_vArgs), std::end(m_vArgs), std::string(), [] (const std::string& cum, const std::string& arg) { return cum + "\n\t" + arg; } );

  retStr += "\nFilenames:";
  retStr += std::accumulate(std::begin(m_files), std::end(m_files), std::string(), [] (const std::string& cum, const state::filename& fn) { return cum + "\n\t" + fn.get_full_name(); } );

  return retStr;
}


// void print_help() {
//   if(strOpt == "-h" || strOpt.find("help") != std::string::npos ) {
//     std::cerr << s_optionBuildRoot << "=[BUILD_PATH]\n";
//     std::cerr << s_optionSteelRoot << "=[STEEL_ROOT_PATH]\n";
//     std::cerr << s_optionUderRoot << "=[UDER_SOURCES_PATH]\n";
//     std::cerr << s_optionTestRoot << "=[TEST_SOURCES_PATH]\n";
//     std::cerr << "=[UDER_SOURCE_1, UDER_SOURCE_2, ...]\n";
//     std::cerr << "=[-I[PATH_1], -I[PATH_2], ...]\n";
//     return;
//   }
// }



} // namespace bld

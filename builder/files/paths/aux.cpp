// #include "files/paths/decl.hpp"

#include "common/aux.hpp"
#include "files/paths/traits/interface.hpp"

#include "files/paths/decl.hpp"


#include <vector>
#include <string>
#include <map>

#include <sstream>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace bld {


std::vector<std::string> split_dirs(const std::string& input) {
  return split_string(input, ';');
}

std::string
discard_path(const std::string& fn) {
  return std::filesystem::path(fn).filename();
}

void get_paths_in_dir_containing_str(std::vector<std::string>& retSources, const std::string& strFn, const std::string& targetDir) {
  for(auto& p : std::filesystem::recursive_directory_iterator(targetDir)) {
    if (p.path().string().find(strFn) != std::string::npos) {
      retSources.push_back(p.path().parent_path());
    }
  }
}

bool file_exists(const std::string& strFilename) {
  std::ifstream ifs(strFilename.c_str());
  return ifs.good();
}

static
bool check_safe_create(const std::string& str) {

  std::filesystem::path p(str);

  // All file/directory creations must be contained within build
  std::filesystem::path allowedPath( state::paths<key_path::build_root>::get_path() );
  allowedPath = allowedPath.parent_path();

  std::filesystem::path endPath( "/" );

  while (p.parent_path() != endPath) {
    if (p.parent_path() == allowedPath) {
      return true;
    }
    p = p.parent_path();
  }
  return false;
}

static
void clean_bars(std::string& str) {
  auto pos = str.find("//");
  while (pos != std::string::npos) {
    str.replace(pos, 2, "/");
    pos = str.find("//");
  }
}

template <>
void satisfy<path_require::create>(std::string dirStr) {
  clean_bars(dirStr);
  std::filesystem::path p( dirStr );
  std::vector<std::filesystem::path> pendingVec;
  while (not std::filesystem::exists(p)) {
    auto thisStr = p.string(); append_char(thisStr, '/');
    auto nextStr = p.parent_path().string(); append_char(nextStr, '/');
    if (thisStr != nextStr) {
      pendingVec.push_back(p);
    }
    p = p.parent_path();
  }

  for (auto it = pendingVec.rbegin(); it != pendingVec.rend(); ++it) {
    if (not it->has_extension()) {
      // Final check to ensure we are creating sth in a valid place
      if (not check_safe_create(it->string()) ) {
        throw std::logic_error("Tried to create " + it->string() + " in a forbidden directory");
      }

      if (not std::filesystem::create_directory(*it)) {
      // Create directory
        throw std::runtime_error("Could not create directory : " + it->string());
      }

      // if (state::options::is_set<opt_kind::print_create>()) {
      //   std::cout << "\tCreated dir " << it->string() << '\n';
      // }
    } else {
      if (not check_safe_create(it->string()) ) {
        throw std::logic_error("Tried to create " + it->string() + " in a forbidden directory");
      }
      // Create blank file
      std::ofstream ofs(it->string());
      ofs.close();

      // if (state::options::is_set<opt_kind::print_create>()) {
      //   std::cout << "\tCreated file " << it->string() << '\n';
      // }
    }
  }
}

template <>
void satisfy<path_require::create_force>(std::string dirStr) {
  clean_bars(dirStr);

  std::filesystem::path p( dirStr );
  if (not std::filesystem::exists(p)) {
    if (not std::filesystem::create_directory(p)) {
      throw std::runtime_error("Could not create directory : " + dirStr);
    }
  }
}

// template <>
// void satisfy<path_require::undefined>(std::string dirStr) {
//   throw std::runtime_error("Directory must be defined first : " + dirStr);
// }

template <>
void satisfy<path_require::exist>(std::string dirStr) {
  if (dirStr.find(';') != std::string::npos) {
    auto vecDirs = split_dirs(dirStr);
    for (auto dir : vecDirs) {
      if (not std::filesystem::exists(dir)) {
        throw std::runtime_error("Directory must exist : " + dir);
      }
    }
  } else {
    if (not std::filesystem::exists(dirStr)) {
      throw std::runtime_error("Directory must exist : " + dirStr);
    }
  }
}




static
std::string get_pc_string_path_detail(const key_path kp, std::integer_sequence<key_path>) {
  throw std::logic_error("Could not get_pc_string_path of " + std::string(util::enum_convert<key_path>::to_string_rt(kp)));
  return "";
}

template <key_path KP, key_path... KPs>
static
std::string get_pc_string_path_detail(const key_path kp, std::integer_sequence<key_path, KP, KPs...>) {
  if (kp == KP) {
    return state::paths<KP>::get_path();
  } else {
    return get_pc_string_path_detail(kp, std::integer_sequence<key_path, KPs...>{});
  }
}


///////////////
//
// INTERFACE
//
///////////////
std::string get_pc_string_path(key_path kp) {

  return get_pc_string_path_detail(kp, enabled::Sequence_key_path{});
}



static
key_path get_key_path_detail(const std::string& keypathStr, std::integer_sequence<key_path>) {
  return key_path::undefined;
}


template <key_path KP, key_path... KPs>
static
key_path get_key_path_detail(const std::string& keypathStr, std::integer_sequence<key_path, KP, KPs...>) {

  std::string enumValStr = util::enum_convert<key_path>::to_string<KP>();

  if (state::paths<KP>::is_set() and state::paths<KP>::get_path() == keypathStr) {
    return KP;
  } else if (enumValStr == keypathStr) {
    return KP;
  } else {
    return get_key_path_detail(keypathStr, std::integer_sequence<key_path, KPs...>{});
  }
}


///////////////
//
// INTERFACE
//
///////////////
key_path get_key_path( const std::string& keypathStr ) {

  auto kpFound = get_key_path_detail( keypathStr, enabled::Sequence_key_path{} );

  if (kpFound == key_path::undefined) {
    throw std::runtime_error("Could not get_key_path : " + keypathStr);
  }
  return kpFound;
}


static
void get_defined_paths_detail(std::vector<std::string>& vecPaths, std::integer_sequence<key_path>) { }


template <key_path KP, key_path... KPs>
static
void get_defined_paths_detail(std::vector<std::string>& vecPaths, std::integer_sequence<key_path, KP, KPs...>) {

  if (state::paths<KP>::is_set()) {
    vecPaths.push_back( std::string(util::enum_convert<key_path>::to_string<KP>()) + " : " + state::paths<KP>::get_path() );
  }

  get_defined_paths_detail( vecPaths, std::integer_sequence<key_path, KPs...>{} );
}


///////////////
//
// INTERFACE
//
///////////////
std::vector<std::string> get_defined_paths() {

  std::vector<std::string> retVec;

  get_defined_paths_detail( retVec, enabled::Sequence_key_path{} );

  return retVec;
}



namespace state {

template <key_path... KPs>
void set_all_paths_if_existing( const option_map_t& optMap, std::integer_sequence<key_path, KPs...> ) {
  ( state::paths<KPs>::set_if_existing( optMap ), ... );
}


///////////////
//
// INTERFACE
//
///////////////
void set_all_paths(const option_map_t& optMap) {

  set_all_paths_if_existing( optMap, enabled::Sequence_key_path{} );
}


template <key_path... KPs>
bool is_any_valid( const std::string& pathFlag, std::integer_sequence<key_path, KPs...> ) {
  return ( (pathFlag == dir_traits<KPs>::option) || ... );
}

///////////////
//
// INTERFACE
//
///////////////
bool is_valid_path(const std::string& pathFlag) {

  return is_any_valid( pathFlag, enabled::Sequence_key_path{} );
}

} // namespace state

} // namespace bld

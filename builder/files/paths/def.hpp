#ifndef STEEL_COMPILER_STATE_PATHS_DEF_HPP
#define STEEL_COMPILER_STATE_PATHS_DEF_HPP

#include "files/paths/traits/interface.hpp"

#include "files/paths/decl.hpp"
// #include "common/options.hpp"
#include "options/typedef.hpp" // option_map_t
#include "common/aux.hpp"

#include <iostream> // TMP XXX

// Defined in aux.cpp
namespace bld {

  std::vector<std::string> split_dirs(const std::string& input);

  bool is_visible_filename(const std::string& fn);

} // namespace bld


namespace bld::state {

template <key_path KP> dir<KP> paths<KP>::s_pathInfo = dir<KP>();

template <key_path KP>
void paths<KP>::set_path(std::string p) {
  append_char(p, '/');
  s_pathInfo.set(p);
}

template <key_path KP>
std::string paths<KP>::get_path() {
  return s_pathInfo.get();
}

template <key_path KP>
bool paths<KP>::is_set() {
  return s_pathInfo.is_set();
}

template <key_path KP>
const std::vector<std::string> paths<KP>::get_all_paths() {
  return split_dirs( paths<KP>::get_path() );
}

template <key_path KP>
void paths<KP>::add_path(const std::string& p) {
  s_pathInfo.add(p);
}





// template <key_path KP>
// std::vector<std::string> paths<KP>::get_file_paths(const std::string& strFn) {
//   const auto targetDir = paths<KP>::get_path();
//   std::vector<std::string> retSources;
//   for(auto& p : std::filesystem::recursive_directory_iterator(targetDir)) {
//     if (p.path().string().find(strFn) != std::string::npos) {
//       retSources.push_back(p.path().string() + strFn);
//     }
//   }
//   return retSources;
// }

// private
template <key_path KP>
std::vector<std::string> paths<KP>::get_paths_containing_str(const std::string& strFn) {
  std::vector<std::string> retSources;
  if constexpr (dir_traits<KP>::single) {
      get_paths_in_dir_containing_str(retSources, strFn, paths<KP>::get_path());
  } else {
    auto targetDirs = split_dirs( paths<KP>::get_path() );
    for (const auto& targetDir : targetDirs) {
      get_paths_in_dir_containing_str(retSources, strFn, targetDir);
    }
  }
  return retSources;
}


// private
template <key_path KP>
template <path_scan PS>
std::vector<filename>
paths<KP>::get_filenames_in_dir(const std::string& targetDir) {

  std::vector<filename> retSources;

  // std::cout << "Target dir : " << targetDir << '\n';

  using iterator_t = std::conditional_t<PS == path_scan::flat, std::filesystem::directory_iterator, std::filesystem::recursive_directory_iterator>;

  for(auto& p : iterator_t(targetDir)) {
    auto fn = p.path().string();
    if (is_visible_filename(fn)) {
      retSources.push_back(filename(KP, fn, path_require::exist));
    }
  }

  return retSources;
}

// public
template <key_path KP>
template <path_scan PS>
std::vector<filename>
paths<KP>::get_filenames() {

  std::vector<filename> retSources;

  static_assert(dir_traits<KP>::single);

  // if constexpr (not dir_traits<KP>::single) {

  //   auto vecDir = split_dirs( paths<KP>::get_path() );
  //   for (const auto& targetDir : vecDir) {
  //     auto vecFn = get_filenames_in_dir<PS>( targetDir );
  //     retSources.insert(std::end(retSources), std::begin(vecFn), std::end(vecFn));
  //   }

  // } else {
    retSources = get_filenames_in_dir<PS>( paths<KP>::get_path() );
  // }

  return retSources;
}

template  <>
bool paths<key_path::pwd>::set_if_existing(const option_map_t& optMap);

template <key_path KP>
bool paths<KP>::set_if_existing(const option_map_t& optMap) {

  if (paths<KP>::is_set()) {
    return true; // Already set. (not necessarily from optMap)
  }

  if ( not std::string(dir_traits<KP>::option).empty() ) {
    auto foundIt = optMap.find( dir_traits<KP>::option );
    if (foundIt != std::end(optMap)) {
      auto mapped = foundIt->second;
      append_char(mapped, '/');
      paths<KP>::set_path( std::filesystem::absolute(mapped).string() );
      return true;
    }
  }

  // Flag not specified, but maybe root flag has been specified and KP is defined relative to it.
  if constexpr (dir_traits<KP>::root != key_path::undefined) {
    if (paths< dir_traits<KP>::root >::set_if_existing(optMap)) {
      if (std::string(dir_traits<KP>::relative).find("UNDEFINED") == std::string::npos) {
        paths<KP>::set_path( paths< dir_traits<KP>::root >::get_path() + dir_traits<KP>::relative);
        return true;
      }
    }
  }
  return false;
}




template <key_path KP>
void paths<KP>::set_as_derived() {


  if constexpr (not dir_traits<KP>::editable) {
    if (paths<KP>::is_set()) {
      // Not editable and already set, just return
      return;
    }
  } 

  if constexpr (not dir_traits<KP>::single) {
    // Always throw
    throw std::runtime_error("Could not set as derived " + std::string(util::enum_convert<key_path>::to_string<KP>()));
  }

  // std::cout << "PROCEEDING WITH SETTING : " << KP << '\n';

  if constexpr (dir_traits<KP>::root != key_path::undefined) {
    paths< dir_traits<KP>::root >::set_as_derived();
    // if constexpr (not dir_traits<KP>::single) {
    //   auto pathsVec = split_dirs( dir_traits<KP>::relative );
    //   std::string allPaths;
    //   for (auto& relPath : pathsVec) {    
    //     allPaths += paths< dir_traits<KP>::root >::get_path() + relPath + ';';
    //   }
    //   if (not pathsVec.empty()) { allPaths.pop_back(); }
    //   paths<KP>::set_path( allPaths );
    // } else {
    // std::cout << "SETTING " << KP << " : " << paths< dir_traits<KP>::root >::get_path() + dir_traits<KP>::relative << '\n';
    if (std::string(dir_traits<KP>::relative).find("UNDEFINED") == std::string::npos) {
      paths<KP>::set_path( paths< dir_traits<KP>::root >::get_path() + dir_traits<KP>::relative );
    }
    //}
    return;
  }

  throw std::runtime_error("Could not set as derived " + std::string(util::enum_convert<key_path>::to_string<KP>()));
}


} // namespace bld::state

#endif // STEEL_COMPILER_STATE_PATHS_DEF_HPP

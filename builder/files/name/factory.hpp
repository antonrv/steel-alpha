#ifndef STEEL_COMPILER_STATE_PATHS_FILE_FACTORY_HPP
#define STEEL_COMPILER_STATE_PATHS_FILE_FACTORY_HPP

#include "files/name/decl.hpp"
#include "files/paths/traits/interface.hpp"
#include "files/paths/decl.hpp"


#include <fstream>
#include <string>

namespace bld::state {

std::string get_extension(std::string fn);

// std::string replace_custom(std::string retStr, const std::string toReplace, const std::string customPath, const std::string newExtension);

std::string replace_extension(std::string tailPath, const std::string newExtension);


template <file_kind NewFK, file_kind RootFK, code NewCodK>
struct file_factory;



//// SGRAPH <--- INPUT. All CodK. Required by INSPECT stage
template <code NewCodK>
struct file_factory<file_kind::sgraph, file_kind::input, NewCodK> {

  static
  filename make(const filename& rootFn) {

    auto rootHead = rootFn.get_head(); // This is [::pwd] or [::steel_runtime_test_case]
    auto rootTail = rootFn.get_tail(); // This is [-app]

    auto curExt = get_extension(rootTail);

    std::filesystem::path p( rootTail );

    if (rootHead == key_path::pwd ) {
      return filename( key_path::build_app_inspect, replace_extension(p.filename(), etraits<ext::sgraph>::value + curExt), path_require::create );
    } else if (rootHead == key_path::steel_builder_test_suite) {
      return filename( key_path::build_builder_test_suite_inspect, replace_extension(p.filename(), etraits<ext::sgraph>::value + curExt), path_require::create );
    } else if (rootHead == key_path::steel_runtime_test_case) {
      return filename( key_path::build_runtime_test_case_inspect, replace_extension(p.filename(), etraits<ext::sgraph>::value + curExt), path_require::create );
    } else {
      throw std::logic_error("File factory input -> sgraph. Expected ::pwd or ::steel_runtime_test_case as root head, got " + std::string(util::enum_convert<key_path>::to_string_rt(rootHead)));
    }
  }
};



//// INSPECTED <--- SGRAPH. All CodK. Required by INSPECT stage
template <code NewCodK>
struct file_factory<file_kind::inspected, file_kind::sgraph, NewCodK> {

  static
  filename make(const filename& rootFn) {

    // Need to open rootFn to know where is the seed. Then we will have an inspected file subject to translation.
    std::ifstream inFile( rootFn.get_full_name().c_str() );

    if (not inFile.is_open()) {
      throw std::runtime_error("Could not make inspected file : Could not open file where the seed is : " + rootFn.get_full_name());
    } 

    // Format of sgraph files : first line is seed root path, second is filename, third is md5 hash of that seed
    static constexpr unsigned NLines = 2;
    std::array<std::string, NLines> readLines;

    for (auto i = 0u; i < NLines; i++) {
      if (inFile.eof()) { throw std::runtime_error("Could not read file line " + std::to_string(i) + " in : " + rootFn.get_full_name()); }
      std::getline(inFile, readLines[i]);
    }

    return filename( readLines[0], readLines[1], path_require::exist );

    // md5 hash: read 3rd line. If exist and md5 hash passed, check same hash, otherwise throw TODO
    // return filename( readLines[0], readLines[1], path_require::exist, readLines[2] );
  }
};



//// TRANSLATION <--- INSPECTED. All CodK. Required by TRANSLATE stage
template <code NewCodK>
struct file_factory<file_kind::translation, file_kind::inspected, NewCodK> {

  static
  filename make(const filename& rootFn) {
    auto rootHead = rootFn.get_head(); // This is [::pwd] or [::steel_runtime_test_case]
    auto rootTail = rootFn.get_tail(); // This is [-app]

    auto curExt = get_extension(rootTail);

    std::filesystem::path p( rootTail );

    if (rootHead == key_path::pwd) {
      return filename( key_path::build_app_translate, replace_extension(p.filename(), etraits<ext::translation>::value + curExt), path_require::create );
    } else if (rootHead == key_path::steel_builder_test_suite) {
      return filename( key_path::build_builder_test_suite_translate, replace_extension(p.filename(), etraits<ext::translation>::value + curExt), path_require::create );
    } else if (rootHead == key_path::steel_runtime_test_case) {
      return filename( key_path::build_runtime_test_case_translate, replace_extension(p.filename(), etraits<ext::translation>::value + curExt), path_require::create );
    } else {
      throw std::logic_error("File factory inspected -> translation. Expected ::pwd or ::steel_runtime_test_case as root head, got " + std::string(util::enum_convert<key_path>::to_string_rt(rootHead)));
    }
  }
};



//// COMPILABLE <--- TRANSLATION. Required by SCAN stage
template <code NewCodK>
struct file_factory<file_kind::compilable, file_kind::translation, NewCodK> {

  static
  filename make(const filename& rootFn) {
    return filename( rootFn.get_head(), rootFn. get_tail(), path_require::exist );
  }
};



//// COMPILABLE <--- RUNTIME. Required by SCAN stage
template <code NewCodK>
struct file_factory<file_kind::compilable, file_kind::runtime, NewCodK> {

  static
  filename make(const filename& rootFn) {
    return filename( rootFn.get_head(), rootFn. get_tail(), path_require::exist );
  }
};



//// COMPILABLE <--- AUTOGEN. Required by SCAN stage
template <code NewCodK>
struct file_factory<file_kind::compilable, file_kind::autogen, NewCodK> {

  static
  filename make(const filename& rootFn) {
    return filename( rootFn.get_head(), rootFn. get_tail(), path_require::exist );
  }
};




//// COMPILED <--- COMPILABLE. Required by COMPILE stage
template <code NewCodK>
struct file_factory<file_kind::compiled, file_kind::compilable, NewCodK> {


  static
  key_path get_target_path(key_path kp) {

    if ( kp == key_path::steel_runtime_modules_ctxt ) {
      return key_path::build_runtime_precomp_ctxt;
    // } else if ( kp == key_path::steel_runtime_modules_data ) {
    //   return key_path::build_runtime_precomp_data;
    } else if ( kp == key_path::steel_runtime_modules_dep ) {
      return key_path::build_runtime_precomp_dep;
    } else if ( kp == key_path::steel_runtime_modules_instrument ) {
      return key_path::build_runtime_precomp_instrument;
    } else if (  kp == key_path::steel_runtime_modules_policy) {
      return key_path::build_runtime_precomp_policy;
    } else if (  kp == key_path::steel_runtime_modules_safe ) {
      return key_path::build_runtime_precomp_safe;
    } else if (  kp == key_path::steel_runtime_modules_task ) {
      return key_path::build_runtime_precomp_task;
    } else if (  kp == key_path::steel_runtime_modules_util ) {
      return key_path::build_runtime_precomp_util;
    } else if (  kp == key_path::steel_runtime_modules_work ) {
      return key_path::build_runtime_precomp_work;
    } else if (
      kp == key_path::steel_runtime_test or
      kp == key_path::steel_runtime_test_case or
      kp == key_path::build_runtime_gen or
      kp == key_path::build_runtime_test_case or
      kp == key_path::build_runtime_test_case_translate or
      kp == key_path::build_runtime_test_case_autogen
    ) {
      // runtime test source
      return key_path::build_runtime_test_case_precomp;

    } else if (
      kp == key_path::build_app_translate or
      kp == key_path::build_app_autogen
    ) {
      // app source
      return key_path::build_app_precomp;

    } else if ( kp == key_path::build_plat_autogen ) {

      return key_path::build_plat_precomp;

    } else {

      throw std::logic_error("Could not make compiled filename from " + std::string(util::enum_convert<key_path>::to_string_rt(kp)) + ". Unknown destination path");
    }
  }


  static
  filename make(const filename& rootFn) {

    auto rootHead = rootFn.get_head();
    auto rootTail = rootFn.get_tail();

    key_path newKeyPath = get_target_path(rootHead);

    auto newTail = replace_extension( rootTail, etraits< ctraits<NewCodK>::compile_extension >::value );
    
    return filename( newKeyPath, newTail, path_require::create );
  }
};



//// COMPILED <--- COMPILABLE. Required by COMPILE stage
template <>
struct file_factory<file_kind::executable, file_kind::compiled, code::entry> {

  // (defined in file_factory.cpp)
  static
  filename make(const filename& rootFn);
};

} // namespace bld::state

#endif // STEEL_COMPILER_STATE_PATHS_FILE_FACTORY_HPP

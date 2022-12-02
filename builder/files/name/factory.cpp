
#include "files/traits/interface.hpp"

#include "files/name/factory.hpp"

#include <filesystem>

namespace bld::state {

std::string get_extension(std::string fn) {
  std::filesystem::path p(fn);
  return p.extension().string();
}

// std::string replace_custom(std::string retStr, const std::string toReplace, const std::string customPath, const std::string newExtension) {
// 
//   auto foundPos = retStr.find(toReplace);
//   if (foundPos == std::string::npos) {
//     throw std::logic_error("Could not find string [" + toReplace + "] in " + retStr);
//   }
//   auto sizeReplace = toReplace.size();
// 
//   std::filesystem::path inPath( customPath );
// 
//   auto fn = inPath.filename();
//   auto parent = inPath.parent_path();
// 
//   retStr.replace(foundPos, sizeReplace, parent.string());
//   
//   if (not newExtension.empty()) {
//     fn.replace_extension(newExtension);
//   }
//   return retStr + fn.string();
// }


std::string replace_extension(std::string tailPath, const std::string newExtension) {

  std::filesystem::path inPath( tailPath );

  if (not newExtension.empty()) {
    inPath.replace_extension(newExtension);
  }
  return inPath.string();
}

template struct file_factory<file_kind::sgraph, file_kind::input, code::interface>;
template struct file_factory<file_kind::sgraph, file_kind::input, code::implementation>;
template struct file_factory<file_kind::sgraph, file_kind::input, code::entry>;
template struct file_factory<file_kind::inspected, file_kind::sgraph, code::interface>;
template struct file_factory<file_kind::inspected, file_kind::sgraph, code::implementation>;
template struct file_factory<file_kind::inspected, file_kind::sgraph, code::entry>;
template struct file_factory<file_kind::translation, file_kind::inspected, code::interface>;
template struct file_factory<file_kind::translation, file_kind::inspected, code::implementation>;
template struct file_factory<file_kind::translation, file_kind::inspected, code::entry>;
template struct file_factory<file_kind::compiled, file_kind::compilable, code::interface>;
template struct file_factory<file_kind::compiled, file_kind::compilable, code::implementation>;
template struct file_factory<file_kind::compiled, file_kind::compilable, code::entry>;

filename
file_factory<file_kind::executable, file_kind::compiled, code::entry>::make(const filename& rootFn) {

  auto rootHead = rootFn.get_head();
  auto rootTail = rootFn.get_tail();

  auto newTail = replace_extension( rootTail, etraits<ext::executable>::value );

  key_path newKeyPath;

  if (rootHead == key_path::build_runtime_test_case_precomp) {
    newKeyPath = key_path::build_runtime_test_case_run;
  } else if (rootHead == key_path::build_app_precomp) {
    newKeyPath = key_path::build_app_run;
  } else {
    throw std::logic_error("Could not make executable filename from " + std::string(util::enum_convert<key_path>::to_string_rt(rootHead)));
  }

  return filename( newKeyPath, newTail, path_require::create );
}

} // namespace bld::state


#include "files/state/decl.hpp"

#include "files/felement/base.hpp"


namespace bld::state {


filename find_file_named(const std::string& fullFilenameStr, std::integer_sequence<file_kind> ) {

  return filename();
}

template <file_kind FK, file_kind... FKs>
filename find_file_named(const std::string& fullFilenameStr, std::integer_sequence<file_kind, FK, FKs...> ) {

  if constexpr (FK != file_kind::undefined) {

    auto allFiles = files<FK>::get_all_files();

    auto foundIt = std::find_if(std::begin(allFiles), std::end(allFiles), [&fullFilenameStr] (cfileb_t f) { return f->get_filename().get_full_name() == fullFilenameStr; }); 

    if (foundIt != std::end(allFiles)) {
      return (*foundIt)->get_filename();
    }
  }

  return find_file_named( fullFilenameStr, std::integer_sequence<file_kind, FKs...>{} );
}

filename find_filename( const std::string& fullFilenameStr ) {

  auto fn = find_file_named( fullFilenameStr, enabled::Sequence_file_kind{} );
  
  if (fn.get_head() == key_path::undefined) {
    throw std::logic_error("Filename not found : " + fullFilenameStr);
  }

  return fn;
}

} // namespace bld::state

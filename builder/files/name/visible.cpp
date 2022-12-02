
#include "files/traits/interface.hpp"

#include <string>
#include <filesystem>

namespace bld {

template <ext Ext>
static
bool has_visible_extension( const std::string& extStr ) {
  if constexpr ( etraits<Ext>::is_suffix ) {
    return extStr == etraits<Ext>::value;
  } else {
    return false;
  }
}

template <ext... Exts>
static
bool has_any_visible_extension( const std::string& extStr, std::integer_sequence<ext, Exts...> ) {
  return ( has_visible_extension< Exts >( extStr ) || ... );
}

///////////////
//
// INTERFACE
//
///////////////
bool is_visible_filename(const std::string& fnStr) {

  if ((fnStr.find("OMIT") == std::string::npos and fnStr.find("TEST_REF") == std::string::npos and fnStr.find("DEP") == std::string::npos)) {
    std::string extStr = std::filesystem::path(fnStr).extension();
    return has_any_visible_extension( extStr, enabled::Sequence_ext{} );
  }
  return false;
}

} // namespace bld

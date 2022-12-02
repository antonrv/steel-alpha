#include "files/traits/code.hpp"
#include "files/traits/extension.hpp"

namespace bld {

// Source extension to code kind
static
code source_extension_to_code_impl(const std::string& fnExt, std::integer_sequence<code>) {
  return code::undefined;
}

template <code CodK, code... CodeArgs>
static
code source_extension_to_code_impl(const std::string& fnExt, std::integer_sequence<code, CodK, CodeArgs...>) {
  if (fnExt == etraits< ctraits<CodK>::source_extension >::value) {
    return CodK;
  } else {
    using next_seq = std::integer_sequence<code, CodeArgs...>;
    return source_extension_to_code_impl(fnExt, next_seq{});
  }
}

// public interface
code source_extension_to_code(const std::string& fnExt) {
  // Add more if needed
  using allowed_src_ext_seq = std::integer_sequence<code, code::interface, code::implementation, code::entry>;
  return source_extension_to_code_impl(fnExt, allowed_src_ext_seq{});
}

} // namespace bld

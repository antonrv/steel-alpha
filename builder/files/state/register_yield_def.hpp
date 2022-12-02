#ifndef STEEL_COMPILER_REGISTER_YIELD_DEF_HPP
#define STEEL_COMPILER_REGISTER_YIELD_DEF_HPP

#include "files/interface.hpp"

#include "files/paths/enum.hpp"
#include "files/name/decl.hpp"
#include "files/paths/def.hpp"


#include "files/name/factory.hpp"

#include "options/state/log.hpp"


namespace bld::state {



  // Assume fileId exists
template <file_kind FK, code CodK>
typename felement<FK, CodK>::yield_ptr_type 
register_yield(filename fn) {

  state::log<opt_kind::log_file_record>( "Request record of yield of:",fn.get_head(), "-", fn.get_tail(), " (", FK, CodK,")");

  auto originFilePtr = state::files<FK>::template record<CodK>( fn );

  using yield_type = typename felement<FK, CodK>::yield_type;
  static constexpr file_kind YieldFK = yield_type::this_file_kind;
  static constexpr code YieldCodK = yield_type::this_code;

  filename yieldFn = file_factory<YieldFK, FK, YieldCodK>::make( originFilePtr->get_filename() );

  yield_type * yieldElemPtr = state::files<YieldFK>::template record<YieldCodK>( yieldFn );

  originFilePtr->set_yield( yieldElemPtr );

  return yieldElemPtr;
}


template <file_kind FK>
fileb_t register_yield_coarse(filename fn) {

  auto fnExt = std::filesystem::path(fn.get_full_name()).extension();
  code codeKind = source_extension_to_code(fnExt); // Defined in file traits
  fileb_t retPtr = nullptr;

  if (codeKind == code::interface) {
    retPtr = register_yield<FK, code::interface>(fn);
  } else if (codeKind == code::implementation) {
    retPtr = register_yield<FK, code::implementation>(fn);
  } else if (codeKind == code::entry) {
    retPtr = register_yield<FK, code::entry>(fn);
  } else {
    throw std::runtime_error("Could not register_yield_coarse : code kind not identified : " + fn.get_full_name());
    // omit it, do nothing, do not throw std::runtime_error("Could not identify code kind of : " + fileId);
  }
  return retPtr;
}


} // namespace bld::state

#endif // STEEL_COMPILER_REGISTER_YIELD_DEF_HPP


#include "translate/cb/aux/coro_raii/interface.hpp"

#include "source/object/data/decl.hpp"

#include "source/token/region/affine/guard.hpp"
#include "source/token/region/affine/access.hpp"


#include <string>
#include <numeric>
#include <algorithm>
#include <functional>


namespace bld {


std::string make_emit_bnd(src::cso_t<src::obj::data_use> dUseInCall) {

  auto useAccess = dUseInCall->get_access();
  std::string emitBndStr = dUseInCall->get_root_data_decl()->get_wrap_variable_name() + ".emit_bnd_";

  if (useAccess == src::access_kind::read_only) {
    emitBndStr += "reader";
  } else if (useAccess == src::access_kind::read_write or useAccess == src::access_kind::write_only or useAccess == src::access_kind::init) {
    emitBndStr += "writer";
  } else {
    throw std::logic_error("Unhandled src::access_kind while injecting emit_bnd");
  }


  if (dUseInCall->on_address()) {
  
    auto thisAccess = dUseInCall->get_mem_access();

    auto coreGuard = dUseInCall->get_root_data_decl()->get_guard();

    emitBndStr += coreGuard->get_emit_arguments( thisAccess );

  } else {
    // Do nothing, no args
    emitBndStr += "()";
  }

  return emitBndStr;
}


} // namespace bld

#include "link/base.hpp"

#include "driver/interface.hpp"

#include "options/state/decl.hpp"
#include "options/state/log.hpp"


namespace bld {

template <>
void run<step::link>( const options * opt ) {

  state::log<opt_kind::log_steps>("Running", step::link);

  linker linkerInstance;
  
  linkerInstance.run_all<code::entry>();

  //linkerInstance.run_all<code::dynlib>(); may be triggered by entries TODO LINKLIB
}

} // namespace bld

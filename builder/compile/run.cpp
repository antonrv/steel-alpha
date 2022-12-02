#include "compile/base.hpp"

#include "driver/interface.hpp"

#include "options/state/decl.hpp"
#include "options/state/log.hpp"


namespace bld {

template <>
void run<step::compile>( const options * opt ) {

  state::log<opt_kind::log_steps>("Running", step::compile);

  compile compileInstance;


  compileInstance.run_all<code::interface>();
  compileInstance.run_all<code::implementation>();
  compileInstance.run_all<code::entry>();

}

} // namespace bld

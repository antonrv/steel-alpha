
#include "translate/translator.hpp"

#include "files/interface.hpp"

#include "options/interface.hpp"

#include "driver/interface.hpp"

#include "common/test/run.hpp"


namespace bld {

static
set_cfileb_t run_on_source(state::filename src) {

  translator t( {src} );
  t.run();

  auto originFile = state::files<file_kind::inspected>::get_poly_file( src.get_full_name() );

  set_cfileb_t retSet;
  retSet.insert( originFile->get_poly_yield() );

  return retSet;
}


template <>
void run_builder_tests<step::translate>( const options * opt ) {

  opt->reset_state();

  test::run_on_suites( run_on_source, step::translate );
}

} // namespace bld

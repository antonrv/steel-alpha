#include "translate/translator.hpp"

#include "files/interface.hpp"

#include "options/interface.hpp"
#include "options/state/log.hpp"

#include "driver/interface.hpp"

#include "common/util.hpp"


namespace bld {


template <>
void run<step::translate>( const options * opt ) {

  opt->reset_state();

  auto felems = state::files<file_kind::inspected>::get_all_files();

  if (felems.empty()) {
    throw std::runtime_error("No files to translate");
  }

  state::log<opt_kind::log_steps>("Running", step::translate, "on", felems.size(), "sources");

  auto fns = transform_vec( felems, [] (cfileb_t felem) { return felem->get_filename(); } );

  translator translatorInstance(fns);
  translatorInstance.run();
}



} // namespace bld

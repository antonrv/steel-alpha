
#include "files/state/module/decl.hpp"

#include "options/state/log.hpp"

namespace bld::state {

set_own_module_t modules::s_ownModules;

module_t modules::record( const std::string& id ) {

  auto [it, wasInserted] = s_ownModules.emplace( std::make_unique< module >( id ) );

  if (wasInserted) {
    state::log<opt_kind::log_module_record>("Recorded:",(*it)->get_identifier());
  }

  return it->get();

  // auto foundIt = std::find_if(
  //     std::begin(s_ownModules), std::end(s_ownModules),
  //     [&id] (const own_module_t& ownMod) {
  //       return ownMod->get_identifier() == id;
  //     } );

  // if (foundIt == std::end(s_ownModules)) {

  //   s_ownModules.insert( std::make_unique< module >( id ) );

  //   return s_ownModules.back().get();

  // } else {
  //   return foundIt->get();
  // }

}

} // namespace bld::state

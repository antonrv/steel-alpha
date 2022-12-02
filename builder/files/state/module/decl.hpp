#ifndef FILES_STATE_MODULE_DECL_HPP
#define FILES_STATE_MODULE_DECL_HPP

#include "files/typedef.hpp"

#include "files/module/decl.hpp"

namespace bld::state {

class modules {

  static set_own_module_t s_ownModules;

public:

  static module_t record( const std::string& identifier );

};

} // namespace bld::state

#endif // FILES_STATE_MODULE_DECL_HPP

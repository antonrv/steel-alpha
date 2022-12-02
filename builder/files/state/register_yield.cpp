
#include "files/traits/interface.hpp"
#include "files/semantic/interface.hpp"
#include "files/felement/decl.hpp"


#include "files/state/register_yield_def.hpp"

namespace bld::state {

template fileb_t register_yield_coarse<file_kind::input>(filename fn);
template fileb_t register_yield_coarse<file_kind::sgraph>(filename fn);
template fileb_t register_yield_coarse<file_kind::inspected>(filename fn);
template fileb_t register_yield_coarse<file_kind::translation>(filename fn);
template fileb_t register_yield_coarse<file_kind::runtime>(filename fn);
template fileb_t register_yield_coarse<file_kind::autogen>(filename fn);
template fileb_t register_yield_coarse<file_kind::compilable>(filename fn);
// template fileb_t register_yield_coarse<file_kind::compiled>(filename fn);
// template fileb_t register_yield_coarse<file_kind::executable>(filename fn);

template felement<file_kind::compiled, code::entry>::yield_ptr_type register_yield<file_kind::compiled,code::entry>( filename fn );

} // namespace bld::state

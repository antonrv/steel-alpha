
#include "source/object/function/definition.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/function/call.hpp"
#include "source/object/function/loop.hpp"
#include "source/object/function/context.hpp"
#include "source/object/function/return.hpp"
#include "source/object/data/use.hpp"

#include "source/object/state/def.hpp"

namespace bld::src {

template class state<obj::fun_def>;
template class state<obj::fun_call>;
template class state<obj::fun_ctxt>;
template class state<obj::fun_ret>;
template class state<obj::fun_loop>;
template class state<obj::data_decl>;
template class state<obj::data_use>;

} // namespace bld::src

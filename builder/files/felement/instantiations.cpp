
#include "files/traits/interface.hpp"
#include "files/semantic/interface.hpp"

#include "files/felement/def.hpp"

namespace bld {

template class felement<file_kind::input, code::interface>;
template class felement<file_kind::input, code::implementation>;
template class felement<file_kind::input, code::entry>;

template class felement<file_kind::sgraph, code::interface>;
template class felement<file_kind::sgraph, code::implementation>;
template class felement<file_kind::sgraph, code::entry>;

template class felement<file_kind::inspected, code::interface>;
template class felement<file_kind::inspected, code::implementation>;
template class felement<file_kind::inspected, code::entry>;

template class felement<file_kind::translation, code::interface>;
template class felement<file_kind::translation, code::implementation>;
template class felement<file_kind::translation, code::entry>;

template class felement<file_kind::autogen, code::interface>;
template class felement<file_kind::autogen, code::implementation>;
template class felement<file_kind::autogen, code::entry>;

template class felement<file_kind::runtime, code::interface>;
template class felement<file_kind::runtime, code::implementation>;
template class felement<file_kind::runtime, code::entry>;

template class felement<file_kind::compilable, code::interface>;
template class felement<file_kind::compilable, code::implementation>;
template class felement<file_kind::compilable, code::entry>;

template class felement<file_kind::compiled, code::interface>;
template class felement<file_kind::compiled, code::implementation>;
template class felement<file_kind::compiled, code::entry>;

template class felement<file_kind::executable, code::interface>; // Not used. Could be used as a library interface
template class felement<file_kind::executable, code::implementation>; // Not used. Could be used as a library implementation
template class felement<file_kind::executable, code::entry>;

} // namespace bld

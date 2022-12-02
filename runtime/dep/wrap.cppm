export module SteelRT.Dep.Wrap;

export import SteelRT.Dep.Wrap.Region;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

export import SteelRT.Dep.Guard.Frontend;

import <algorithm>;

/////////////// Semantically, when we wrap something is because we want to protect its access against concurrent read-writes.
// * Happening only within the kernel and subkernels (ie we are wrapping a newly created variable) (lifetime::local). Need common RAW/WAR/WAW
// * Happening within the kernel and subkernels AND super kernels (ie we are wrapping a kernel argument that is a reference) (lifetime::external). Need TAR/TAW to protect it.

export
namespace dep {

// enum class lifetime : enum_uint_t { local, external };

// Initialized RO
// Wrapping a const lvalue as ref. The thing to return will make the coroutine not finished (its destruction is deferred) until the reading finalizes.
template <
  typename CT,
  util::req_t< std::conjunction< std::negation<std::is_pointer<CT>> ,std::is_const<CT>> > ...
>
auto wrap(CT& arg) {
  return guard::fnd::readable<CT>(arg);
}


// Initialized RW
// Undefined WO. Treated as RW : auto wrap()
template <
  typename T,
  util::req_t< std::conjunction< std::negation<std::is_pointer<T>>, std::negation< std::is_const<T> >> > ...
>
auto wrap(T& arg) {
  return guard::fnd::writable<T>(arg);
}



template <typename... WrapTs>
bool all_destroyable(WrapTs&... wrapArgs) {
  return (wrapArgs.is_destroyable() && ... );
}


template <typename... UintTs>
ulong_t min(UintTs... vars) {
  return std::min<ulong_t>( {vars...} );
}
template <typename... UintTs>
ulong_t max(UintTs... vars) {
  return std::max<ulong_t>( {vars...} );
}

} // namespace dep

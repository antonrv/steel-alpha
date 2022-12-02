
export module SteelRT.Dep.Region;


export import SteelRT.Dep.Guard.Frontend.Region;
export import SteelRT.Dep.Guard.Frontend.Container;

import SteelRT.Dep.FwDeclarations;
import SteelRT.Util.Types;
import SteelRT.Util.Require;

// import SteelRT.Util.Types;
// import SteelRT.Util.Require;

export
namespace dep {


// A pointer to const data
template <
  guard::fnd::region::mode Mode,
  typename PtrT,
  util::req_t< std::conjunction< std::is_pointer<PtrT>, std::is_const<std::remove_pointer_t<PtrT>> > > ...
>
auto wrap_region(PtrT ptr, uint_t size, uint_t blockSize) {
  return guard::fnd::region::readable<1, Mode, std::remove_pointer_t<PtrT>>(ptr, size, blockSize);
}


// A pointer to nonconst data
template <
  guard::fnd::region::mode Mode,
  typename PtrT,
  util::req_t< std::conjunction< std::is_pointer<PtrT>, std::negation<std::is_const<std::remove_pointer_t<PtrT>>> > > ...
>
auto wrap_region(PtrT ptr, uint_t size, uint_t blockSize) {
  return guard::fnd::region::writable<1, Mode, std::remove_pointer_t<PtrT>>(ptr, size, blockSize);
}

} // namespace dep

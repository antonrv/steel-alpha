
export module SteelRT.Dep.Wrap.Region;


export import SteelRT.Dep.Guard.Frontend.Region;
export import SteelRT.Dep.Guard.Frontend.Container;

import SteelRT.Dep.FwDeclarations;
import SteelRT.Util.Types;
import SteelRT.Util.Require;

// import SteelRT.Util.Types;
// import SteelRT.Util.Require;

export
namespace dep {

template <std::size_t D>
using array_t = typename mesh<D>::array_t;


template <std::size_t D>
using array_range_t = typename mesh<D>::array_range_t;

// A pointer to const data
template <
  std::size_t Dim,
  typename PtrT,
  util::req_t<
    std::conjunction<
      std::is_pointer<PtrT>,
      std::is_const<std::remove_pointer_t<PtrT>>
    >
  > ...
>
auto wrap_mesh(PtrT ptr, array_t<Dim>&& globalEmbeds, array_t<Dim>&& localEmbeds) {
  return guard::fnd::region::readable<Dim, std::remove_pointer_t<PtrT>>(
    ptr,
    std::forward<array_t<Dim>>(globalEmbeds),
    std::forward<array_t<Dim>>(localEmbeds)
  );
}


// A pointer to nonconst data
template <
  std::size_t Dim,
  typename PtrT,
  util::req_t<
    std::conjunction<
      std::is_pointer<PtrT>,
      std::negation<std::is_const<std::remove_pointer_t<PtrT>>>
    >
  > ...
>
auto wrap_mesh(PtrT ptr, array_t<Dim>&& globalEmbeds, array_t<Dim>&& localEmbeds) {
  return guard::fnd::region::writable<Dim, std::remove_pointer_t<PtrT>>(
    ptr,
    std::forward<array_t<Dim>>(globalEmbeds),
    std::forward<array_t<Dim>>(localEmbeds)
  );
}

} // namespace dep

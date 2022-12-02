
export module SteelRT.Dep.Wrap.Region.Direct;

export import SteelRT.Dep.Guard.Frontend.Region;
export import SteelRT.Dep.Guard.Frontend.Container;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Dep.Dim.Types;


export
namespace dep {


// A pointer to const data
template <
  std::size_t Dim,
  mesh MeshKind,
  typename PtrT,
  util::req_t<
    std::conjunction<
      util::same<MeshKind, mesh::direct>,
      std::is_pointer<PtrT>,
      std::is_const<std::remove_pointer_t<PtrT>>
    >
  > ...
>
auto wrap_region(PtrT ptr, dim::array_t<Dim>&& globalEmbeds, dim::array_t<Dim>&& localEmbeds, dim::array_range_t<Dim>&& callRanges) {
  return guard::fnd::region::readable<MeshKind, Dim, std::remove_pointer_t<PtrT>>(
    ptr,
    std::forward<dim::array_t<Dim>>(globalEmbeds),
    std::forward<dim::array_t<Dim>>(localEmbeds),
    std::forward<dim::array_range_t<Dim>>(callRanges)
  );
}


// A pointer to nonconst data
template <
  std::size_t Dim,
  mesh MeshKind,
  typename PtrT,
  util::req_t<
    std::conjunction<
      util::same<MeshKind, mesh::direct>,
      std::is_pointer<PtrT>,
      std::negation<std::is_const<std::remove_pointer_t<PtrT>>>
    >
  > ...
>
auto wrap_region(PtrT ptr, dim::array_t<Dim>&& globalEmbeds, dim::array_t<Dim>&& localEmbeds, dim::array_range_t<Dim>&& callRanges) {
  return guard::fnd::region::writable<MeshKind, Dim, std::remove_pointer_t<PtrT>>(
    ptr,
    std::forward<dim::array_t<Dim>>(globalEmbeds),
    std::forward<dim::array_t<Dim>>(localEmbeds),
    std::forward<dim::array_range_t<Dim>>(callRanges)
  );
}

} // namespace dep

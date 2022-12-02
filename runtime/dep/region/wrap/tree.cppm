

export module SteelRT.Dep.Wrap.Region.Tree;


export import SteelRT.Dep.Guard.Frontend.Region;
export import SteelRT.Dep.Guard.Frontend.Container;

import SteelRT.Dep.Dim.Types;

import SteelRT.Dep.FwDeclarations;
import SteelRT.Util.Types;
import SteelRT.Util.Require;


export
namespace dep {


// A pointer to const data
template <
  std::size_t Dim,
  mesh MeshKind,
  typename PtrT,
  util::req_t<
    std::conjunction<
      util::same<MeshKind, mesh::tree>,
      std::is_pointer<PtrT>,
      std::is_const<std::remove_pointer_t<PtrT>>
    >
  > ...
>
auto wrap_region(PtrT ptr, dim::array_t<Dim>&& globalEmbeds) {
  return guard::fnd::region::readable<MeshKind, Dim, std::remove_pointer_t<PtrT>>(
    ptr,
    std::forward<dim::array_t<Dim>>(globalEmbeds)
  );
}

// A pointer to nonconst data
template <
  std::size_t Dim,
  mesh MeshKind,
  typename PtrT,
  util::req_t<
    std::conjunction<
      util::same<MeshKind, mesh::tree>,
      std::is_pointer<PtrT>,
      std::negation<std::is_const<std::remove_pointer_t<PtrT>>>
    >
  > ...
>
auto wrap_region(PtrT ptr, dim::array_t<Dim>&& globalEmbeds) {
  return guard::fnd::region::writable<MeshKind, Dim, std::remove_pointer_t<PtrT>>(
    ptr,
    std::forward<dim::array_t<Dim>>(globalEmbeds)
  );
}

} // namespace dep

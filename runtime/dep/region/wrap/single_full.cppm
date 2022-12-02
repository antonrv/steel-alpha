
export module SteelRT.Dep.Wrap.Region.SingleFull;

export import SteelRT.Dep.Guard.Frontend.Region;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Dep.MeshEnum;




export
namespace dep {



// A pointer to const data
template <
  std::size_t Dim,
  mesh MeshKind,
  typename PtrT,
  util::req_t<
    std::conjunction<
      std::disjunction<
        util::same<MeshKind, mesh::single>,
        util::same<MeshKind, mesh::full>
      >,
      std::is_pointer<PtrT>,
      std::is_const<std::remove_pointer_t<PtrT>>
    >
  > ...
>
auto wrap_region(PtrT ptr) {
  return guard::fnd::region::readable<MeshKind, Dim, std::remove_pointer_t<PtrT>>( ptr );
}

// A pointer to nonconst data
template <
  std::size_t Dim,
  mesh MeshKind,
  typename PtrT,
  util::req_t<
    std::conjunction<
      std::disjunction<
        util::same<MeshKind, mesh::single>,
        util::same<MeshKind, mesh::full>
      >,
      std::is_pointer<PtrT>,
      std::negation<std::is_const<std::remove_pointer_t<PtrT>>>
    >
  > ...
>
auto wrap_region(PtrT ptr) {
  return guard::fnd::region::writable<MeshKind, Dim, std::remove_pointer_t<PtrT>>( ptr );
}

} // namespace dep


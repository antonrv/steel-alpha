
export module SteelRT.Util.FwDeclarations.Dep;

import SteelRT.Util.Types;

export
namespace dep {

enum class mesh : enum_uint_t;

namespace guard::bnd {

//   template <typename T>
//   struct is;

} // namespace guard::bnd



namespace guard::fnd::region {

// enum class mode : enum_uint_t {
//   disjoint, // Subregions are always disjoint, so no need to calculate partial intersections
//   overlap  // Subregions could overlap, so need to calculate intersections.
// };

template <mesh MeshKind, template <typename> class StateT, typename InputT, typename DimMapperT>
class container;


} // namespace guard::fnd::region

} // namespace dep

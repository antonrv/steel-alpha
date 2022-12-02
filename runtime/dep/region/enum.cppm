
export module SteelRT.Dep.MeshEnum;

import SteelRT.Util.Types;

export
namespace dep {
  enum class mesh : enum_uint_t { direct, tree, single, full }; // O(1), O(logn), O(1) no conflict, O(1) full block,
} // namespace dep

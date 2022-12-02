
export module SteelRT.Task.Descriptor.Init;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Dep.Guard.Backend;


import <cstddef>;
import <utility>;


namespace task {



  template <std::size_t IdxBit>
  void zero_bit(solved_mask_t& retMask) noexcept {
    retMask = retMask ^ (1 << IdxBit); // ie xor to set the IdxBit-th bit to 0
  }
  
  template <std::size_t... IdxBit>
  void zero_solvable_bits(solved_mask_t& retMask, util::sequence::index_t<IdxBit...>) noexcept {
    ( zero_bit<IdxBit>( retMask ), ... );
  }

export
template <typename CallTupleT>
solved_mask_t initialize_solved_mask() noexcept {
  using WrapIdxSeqT = util::tuple::filter_ids_t< util::tuple::as_types_t<CallTupleT>, dep::guard::bnd::is >;
  solved_mask_t retMask = global::AllSolvedMask;
  zero_solvable_bits( retMask, WrapIdxSeqT{} );
  return retMask;
}

} // namespace task

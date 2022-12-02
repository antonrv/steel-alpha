
export module SteelRT.Task.Descriptor.Update;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Util.App;

import SteelRT.Dep.Guard.Backend;

import SteelRT.Task.Descriptor;

// import SteelRT.Instrument;

import <utility>;

export import SteelRT.Util.Assert;
#include "assert.hpp"

namespace task {

  ///////////////// UPDATE THE SOLVED MASK OF THE TASK STATE, to see if all dependencies are ready.


  template <typename CallTupleT>
  bool is_ready(const arg_id_t argId, const CallTupleT& callTuple, util::sequence::index_t<>) {
    ensure(0, "Unreachable in is_ready");
    return false;
  }

  template <typename CallTupleT, std::size_t Id, std::size_t... Ids>
  bool is_ready(const arg_id_t argId, const CallTupleT& callTuple, util::sequence::index_t<Id, Ids...>) {
    if (Id == argId) {
      return std::get<Id>( callTuple ).is_ready(); // Depending on the kind of future, the ready requirements will be different (ie ro, rw...)
    }
    return is_ready(argId, callTuple, util::sequence::index_t<Ids...>{});
  }


export
template <
  app::call AppCall,
  util::req_t< util::sequence::empty< util::tuple::filter_ids_t< typename app::traits<AppCall>::arg_tuple_type, dep::guard::bnd::is > > >... 
>
void update( task::poly_descriptor * descPtr ) {
  // No solvable arguments (ie no wrappers), all ready. Do nothing
}


export
template <
  app::call AppCall,
  util::req_t< std::negation< util::sequence::empty< util::tuple::filter_ids_t< typename app::traits<AppCall>::arg_tuple_type, dep::guard::bnd::is > > > >... // non-zero wrappers
>
void update( task::poly_descriptor * descPtr ) {

  // instr::trace<instr::event::dep_update::start>();

  using CallTupleT = typename app::traits<AppCall>::arg_tuple_type;
  // static constexpr std::size_t NArgs = CallTupleT::size();

  // Filter the arguments according to the wrapper criteria (ie if it is a wrapper it may be unresolved)
  using SolvableIds = util::tuple::filter_ids_t< CallTupleT, dep::guard::bnd::is >;
  static constexpr auto BitPosArray = util::sequence::to_array_v< SolvableIds >;

  using StdCallTupleT = util::tuple::as_std_t< CallTupleT >;
  const StdCallTupleT& callTupleRef = *static_cast<StdCallTupleT const*>( static_cast<task::descriptor<AppCall, StdCallTupleT> const*>( descPtr ) );

  solved_mask_t solvedMask = descPtr->get_solved_mask();

  for (auto i = 0u; i < BitPosArray.size() && solvedMask != global::AllSolvedMask; ++i) {
    arg_id_t bitPos = BitPosArray[i];

    if ((solvedMask & (1 << bitPos)) == 0) { // ie bit in position bitPos is zero -> not ready. Other value -> ready

      // Check dep state
      if (is_ready(bitPos, callTupleRef, SolvableIds{})) {
        // Set to 1 that bit.
        solvedMask = solvedMask | (1 << bitPos); // ie OR previous mask with ..00100.. with the 1 corresponding to that position
      } else {
        // Not ready, do nothing
      }
    }
  }

  if (descPtr->get_solved_mask() != solvedMask) {
    // instr::trace<instr::event::dep_update::end>();
    descPtr->set_solved_mask( solvedMask );
  } else {
    // instr::trace<instr::event::dep_update::no_changes>();
  }
}



} // namespace task

export module SteelRT.Execute.Kernel;

  export import SteelRT.Execute.Forward;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.AppWork;


import SteelRT.Task.Descriptor;

// import SteelRT.Instrument;

// import SteelRT.Util.Assert;
// #include "assert.hpp"



namespace exe {



  // export // needed ?
  template <
    app::impl KernelTargetAppImpl,
    app::call OriginAppCall,
    std::size_t... KernelArgIds
  >
  void run_kernel_detail(app::tuple_std_args_t<OriginAppCall>& callTupleRef, util::sequence::index_t<KernelArgIds...>) {

    using ImplArgTupleT = app::tuple_resolve_t<KernelTargetAppImpl>; // equal to tuple_args_t because KernelTargetAppImpl does not have delegates

    app::kernel_proxy< KernelTargetAppImpl >::run(
        forward_acquire<KernelTargetAppImpl, OriginAppCall, KernelArgIds>( callTupleRef ) ...
      );
  }


export
template <
  app::impl KernelTargetAppImpl, 
  app::call OriginAppCall,
  util::req_t< std::negation<app::has_delegated<KernelTargetAppImpl>> > ...
>
void run_kernel( workload::poly_desc_t polyDesc ) {

  using CallStdTupleT = app::tuple_std_args_t<OriginAppCall>;

  CallStdTupleT& callTupleRef = *static_cast<CallStdTupleT*>( static_cast< task::descriptor<OriginAppCall, CallStdTupleT>* >( polyDesc ) );

  // If Call is associated to an AppImpl that has delegated, this KernelTargetAppImpl is not delegated, but callTupleRef may store initialized delegate parameters which we should not traverse. On the contrary, we must traverse only the 'resolve' parameters associated to the impl of the call.
  // If Call is not associated to an AppImpl that has delegated, this KernelTargetAppImpl is also not delegated, so both call tuple of either impls will be the same, and following sequence will reduce to basic { 0, 1, 2, ... , callTupleArgSize - 1 }. Revisit this TODO

  using CallArgIdSeq = app::seq_resolve_t< app::impl_of_v<OriginAppCall> >;

  using KernelArgIdSeq = app::seq_args_t< KernelTargetAppImpl >; // Equal to seq_resolve_t because no delegates

  // CallArgIdSeq same size of KernelArgIds, and KernelArgIdSeq will pick the successive positions of args in the call tuple via CallArgIdSeq

  // instr::trace_conv<instr::event::dep_execute::kernel_start, KernelTargetAppImpl>();

  run_kernel_detail< KernelTargetAppImpl, OriginAppCall >( callTupleRef, KernelArgIdSeq{} );

  // instr::trace_conv<instr::event::dep_execute::kernel_end, KernelTargetAppImpl>();
}


} // namespace exe

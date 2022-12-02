
export module SteelRT.Execute.Dispatcher;


import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.AppWork;


import SteelRT.Execute.Forward;

import SteelRT.Task.Descriptor;
import SteelRT.Task.Descriptor.Commit;
import SteelRT.Task.Dispatcher;


// import SteelRT.Util.Assert;
// #include "assert.hpp"

namespace exe {

  // export // needed ?
  template <
    app::impl DispatcherTargetAppImpl,
    app::call OriginAppCall,
    std::size_t... DispatcherArgIds
  >
  workload::own_disp_t<DispatcherTargetAppImpl>
  create_dispatcher_detail(task::attr::descriptor& attrDesc, app::tuple_std_args_t<OriginAppCall>& callTupleRef, util::sequence::index_t<DispatcherArgIds...>) {

    return app::dispatcher_proxy<DispatcherTargetAppImpl>::create( attrDesc, forward_acquire<DispatcherTargetAppImpl, OriginAppCall, DispatcherArgIds>(callTupleRef) ... );
  }


export
template <
  app::impl DispatcherTargetAppImpl, 
  app::call OriginAppCall,
  util::req_t< std::negation<app::has_delegated<DispatcherTargetAppImpl>> > ...
>
workload::own_disp_t<DispatcherTargetAppImpl>
create_dispatcher( workload::poly_desc_t polyDesc ) noexcept {
// create_dispatcher( workload::own_poly_desc_t&& ownPolyDesc, const workload::push_poly_desc_fn_t& pushGlobalFn ) noexcept TODO XXX set for generic dispatchers, not lightweight ones

  using CallStdTupleT = app::tuple_std_args_t<OriginAppCall>;

  CallStdTupleT& callTupleRef = *static_cast<CallStdTupleT*>( static_cast<task::descriptor<OriginAppCall, CallStdTupleT>*>( polyDesc ) );

  using DispatcherArgIdSeq = app::seq_args_t< DispatcherTargetAppImpl >; // Equal to seq_resolve_t because no delegates

  // instr::trace_conv<instr::event::dep_dispatch::create_start, DispatcherTargetAppImpl>();

  // Create the dispatcher as a shared object
  auto ownDisp = create_dispatcher_detail< DispatcherTargetAppImpl, OriginAppCall >( *polyDesc, callTupleRef, DispatcherArgIdSeq{} );

  // instr::trace_conv<instr::event::dep_dispatch::create_end, DispatcherTargetAppImpl>();

  // ownDisp->set_owned_descriptor( std::move(ownPolyDesc), &task::set_result<OriginAppCall> );

  // ownDisp->set_push_global( pushGlobalFn ); TODO XXX set for generic dispatchers, not lightweight ones

  return ownDisp;
}

} // namespace exe

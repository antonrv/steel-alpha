

export module SteelRT.Execute.Dispatcher.Delegate;


import SteelRT.Util.Types;
import SteelRT.Util.Sequence;
import SteelRT.Util.Require;
import SteelRT.Util.App;

import SteelRT.Execute.Forward;
import SteelRT.Dep.Commit;

import SteelRT.Task.Descriptor;
import SteelRT.Task.Dispatcher;


import SteelRT.Instrument;


namespace exe {


  template <
    app::impl DispatcherTargetAppImpl,
    app::call OriginAppCall,
    std::size_t... DispatcherArgIds
  >
  workload::own_disp_t<DispatcherTargetAppImpl>
  create_dispatcher_delegate_detail( task::attr::descriptor& attrDesc, app::tuple_std_args_t<OriginAppCall>& callTupleRef, app::tuple_std_delegate_t<DispatcherTargetAppImpl>& delegateTupleRef, util::sequence::index_t<DispatcherArgIds...> ) {

    return app::dispatcher_proxy<DispatcherTargetAppImpl>::create( attrDesc,
        forward_arg<DispatcherTargetAppImpl, OriginAppCall, DispatcherArgIds>( callTupleRef, delegateTupleRef ) ...
      );

  }

// TODO pass not owned, so the deleter can be set with a learn_notify_end function (look at basic)

export
template <
  app::impl DispatcherTargetAppImpl, 
  app::call OriginAppCall,
  util::req_t< app::has_delegated<DispatcherTargetAppImpl> > ...
>
workload::own_disp_t<DispatcherTargetAppImpl>
create_dispatcher_delegate( task::descriptor_delegate_type<DispatcherTargetAppImpl, OriginAppCall>& descDelegateRef, const workload::push_poly_desc_fn_t& pushGlobalFn ) noexcept {

  auto descPtr = descDelegateRef.get_original_descriptor_ptr();

  using CallStdTupleT = app::tuple_std_args_t< OriginAppCall >;

  CallStdTupleT& callTupleRef = *static_cast<CallStdTupleT*>( descPtr );

  using DelegateStdTupleT = app::tuple_std_delegate_t< DispatcherTargetAppImpl >;

  DelegateStdTupleT& delegateTupleRef = static_cast< DelegateStdTupleT& >( descDelegateRef );

  // Create the dispatcher as a shared object
  auto ownDisp = create_dispatcher_detail< DispatcherTargetAppImpl, OriginAppCall >( *ownPolyDesc, callTupleRef, delegateTupleRef, DispatcherArgIdSeq{} );


  ownDisp->set_owned_descriptor( descDelegateRef.yield_original_descriptor(), &dep::commit::set_result<OriginAppCall> );

  ownDisp->set_push_global( pushGlobalFn );

  return ownDisp;
}


} // namespace exe



export module SteelRT.Execute.Kernel.Delegate;

import SteelRT.Util.Types;
import SteelRT.Util.Sequence;
import SteelRT.Util.Require;
import SteelRT.Util.App;

import SteelRT.Execute.Forward;

import SteelRT.Task.Descriptor;

import SteelRT.Instrument;



namespace exe {

/////////////////// RUN KERNEL WITH DELEGATED PARAMETERS



  template <
    app::impl KernelTargetAppImpl,
    app::call OriginAppCall,
    std::size_t... KernelArgIds
  >
  void run_kernel_delegate_detail(app::tuple_std_args_t<OriginAppCall>& callTupleRef, app::tuple_std_delegate_t<KernelTargetAppImpl>& delegateTupleRef, util::sequence::index_t<KernelArgIds...> ) {

    app::kernel_proxy<KernelTargetAppImpl>::run(
        forward_arg<OriginAppImpl, OriginAppImpl, KernelArgIds>( callTupleRef, delegateTupleRef ) ...
      );
  }


export
template <
  app::impl KernelTargetAppImpl, // Has delegated arguments
  app::call OriginAppCall, // May carry delegate arguments of the same or other Impl
  util::req_t< app::has_delegated<KernelTargetAppImpl> > ...
>
void run_kernel_delegate( task::descriptor_delegate_type<KernelTargetAppImpl, OriginAppCall>& descDelegateRef ) {

  auto descPtr = descDelegateRef.get_original_descriptor_ptr();

  using CallStdTupleT = app::tuple_std_args_t< OriginAppCall >;

  CallStdTupleT& callTupleRef = *static_cast<CallStdTupleT*>( descPtr );

  using DelegateStdTupleT = app::tuple_std_delegate_t< KernelTargetAppImpl >;

  DelegateStdTupleT& delegateTupleRef = static_cast< DelegateStdTupleT& >( descDelegateRef );


  run_kernel_delegate_detail< KernelTargetAppImpl, OriginAppCall >( callTupleRef, delegateTupleRef, app::seq_args_t<KernelTargetAppImpl>{} );
}


} // namespace exe

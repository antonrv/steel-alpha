

export module SteelRT.Execute.Load;

  export import SteelRT.Execute.Forward;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.AppWork;


namespace exe {


  // export // needed ?
  template <
    app::impl OriginAppImpl,
    app::call OriginAppCall,
    std::size_t... KernelArgIds
  >
  float estimate_load_detail( app::tuple_std_args_t<OriginAppCall>& callTupleRef, util::sequence::index_t<KernelArgIds...> ) {

    using ImplArgTupleT = app::tuple_resolve_t<OriginAppImpl>; // equal to tuple_args_t because OriginAppImpl does not have delegates

    using AppGroupT = app::group_impl_of_t< OriginAppImpl >;

    return app::load_proxy< AppGroupT::id_value, typename AppGroupT::type >::run( forward_acquire<OriginAppImpl, OriginAppCall, KernelArgIds>( callTupleRef ) ... );
  }


export
template <
  app::call OriginAppCall
>
float estimate_load( workload::poly_desc_t polyDesc ) {

  using CallStdTupleT = app::tuple_std_args_t<OriginAppCall>;

  CallStdTupleT& callTupleRef = *static_cast<CallStdTupleT*>( static_cast< task::descriptor<OriginAppCall, CallStdTupleT>* >( polyDesc ) );

  static constexpr app::impl OriginAppImpl = app::impl_of_v<OriginAppCall>;

  using CallArgIdSeq = app::seq_resolve_t< OriginAppImpl >;

  using KernelArgIdSeq = app::seq_args_t< OriginAppImpl >; // Equal to seq_resolve_t because no delegates

  return estimate_load_detail< OriginAppImpl, OriginAppCall >( callTupleRef, KernelArgIdSeq{} );
}


} // namespace exe

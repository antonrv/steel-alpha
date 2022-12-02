
export module SteelRT.Execute.Forward;

  export import SteelRT.Execute.Acquire;


import SteelRT.Util.Basic;
import SteelRT.Util.Meta;
import SteelRT.Util.App;


export
namespace exe {


template <
  app::impl TargetAppImpl,
  app::call OriginAppCall,
  std::size_t ArgId
>
util::tuple::element_t<ArgId, app::tuple_args_t<TargetAppImpl>>
forward_acquire( app::tuple_std_args_t<OriginAppCall>& callTupleRef ) noexcept {

  using ImplArgTupleT = app::tuple_args_t<TargetAppImpl>;

  // Get the position in which ArgId is present in the call tuple.
  // Note that this call tuple comes from an OriginAppCall which may or may not be associated to TargetAppImpl

  // Regardless of the impl of OriginAppCall and TargetAppImpl being equal, both impls are equivalent, so their seq_resolve_t are isomorphic, following 1-to-1 relation in the same order.
  // Ie : the argument in position X in app::seq_resolve_t of TargetAppImpl corresponds to the argument in position X in app::seq_resolve_t of OriginAppImpl


  static constexpr std::size_t IdInResolveSeqOfTarget = util::sequence::get_index_v< app::seq_resolve_t<TargetAppImpl>, ArgId >;

  static constexpr std::size_t IdInOriginImpl = util::sequence::get_value_in_v< app::seq_resolve_t< app::impl_of_v<OriginAppCall> >, IdInResolveSeqOfTarget >;

  // Since some of the arguments of the OriginAppCall may be defaulted (if are delegated), we must finally locate the argument in call corresponding to the argument in IdInOriginImplTuple
  // The argument in position X in app::seq_resolve_t of OriginAppImpl corresponds to another argument position in the call :

  static constexpr std::size_t IdInCallTuple = util::sequence::get_index_v< app::seq_args_t<app::impl_of_v<OriginAppCall>>, IdInOriginImpl >;

  return exe::acquire<util::tuple::element_t<ArgId, ImplArgTupleT>>( std::get< IdInCallTuple >( callTupleRef ) );
}


// If this arg id is not delegate, pick it from the call tuple.
template <
  app::impl TargetAppImpl,
  app::call OriginAppCall,
  std::size_t ArgId,
  util::req_t<
    std::conjunction<
      app::has_delegated< TargetAppImpl >,
      std::negation< util::sequence::contains<app::seq_delegate_t<TargetAppImpl>, ArgId> >
    >
  > ...
>
util::tuple::element_t<ArgId, app::tuple_args_t<TargetAppImpl>>
forward_arg( app::tuple_std_args_t<OriginAppCall>& callTupleRef, app::tuple_std_delegate_t<TargetAppImpl>& delegateTupleRef ) noexcept {

  return forward_acquire<TargetAppImpl, OriginAppCall, ArgId>( callTupleRef );
}


// If this arg id is a delegate, pick it from the delegate tuple, neglecting origin app call and call tuple
template <
  app::impl TargetAppImpl,
  app::call OriginAppCall,
  std::size_t ArgId,
  util::req_t<
    std::conjunction<
      app::has_delegated< TargetAppImpl >,
      util::sequence::contains<app::seq_delegate_t<TargetAppImpl>, ArgId>
    >
  > ...
>
util::tuple::element_t<util::sequence::get_index_v< app::seq_delegate_t<TargetAppImpl>, ArgId >, app::tuple_std_delegate_t<TargetAppImpl>>
forward_arg( app::tuple_std_args_t<OriginAppCall>& callTupleRef, app::tuple_std_delegate_t<TargetAppImpl>& delegateTupleRef ) noexcept {

  // Get the position in which ArgId is present in the delegate tuple
  static constexpr std::size_t IdInDelegateTuple = util::sequence::get_index_v< app::seq_delegate_t<TargetAppImpl>, ArgId >;

  return std::get< IdInDelegateTuple >( delegateTupleRef );
}


} // namespace exe

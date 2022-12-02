

export module SteelRT.Learn.Interface.Pilot.Aux;


// Need to break circular deps
// import SteelRT.Learn.Agent.Runner.Implementer;

// import SteelRT.Learn.Agent.Pilot.Implementer;
// import SteelRT.Learn.Agent.Pilot.Backend;



import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;


namespace learn::agent::pilot {

  template <plat::processor ProcId, typename AppGroupT, typename NativeT>
  class implementer;

  template <plat::processor ProcId, typename NativeT>
  class threader_single;

  template <intf::msg::ctg MsgCtg, typename AgentT>
  class backend;
} // namespace learn::agent::pilot


export
namespace learn::intf::pilot {


template <typename NativeT>
class aux< msg::ctg::tasking, NativeT > {

private:

  template <plat::processor ProcId>
  struct per {

    // <AG1, AG2, ... , AGn>
    using all_compatible_groups = typename NativeT::template all_compatible_groups<ProcId>;

    ////// --------------------- Backends of PILOT
    template <typename AppGroupT>
    using agent_of_group = agent::pilot::implementer<ProcId, AppGroupT, NativeT>;

    template <typename AppGroupT>
    using backend_of_group = agent::pilot::backend< msg::ctg::tasking, agent_of_group<AppGroupT> >;

    // Tuple of pilot backends for this ProcId
    // tuple< pilot::bnd_impl<P, AG1, NT>, pilot::bnd_impl<P, AG2, NT>, ..., pilot::bnd_impl<P, AGn, NT> >
    using backends = util::tuple::lift_t<all_compatible_groups, backend_of_group>; // XXX



    ////// --------------------- Input states according to RUNNER
    template <typename PilotBackendImplementerT>
    using input_state_type = typename PilotBackendImplementerT::input_state_type;

    // Tuple of input states for this ProcId
    // < in_state_P_AG1, in_state_P_AG2, ..., in_state_P_AGn >
    // util::tuple_t< std::tuple<...>, std::tuple<...>, std::tuple<...> >
    using input_states_backends = util::tuple::lift_t< backends, input_state_type >; // XXX

    static_assert( util::tuple::is_holding_std< input_states_backends >::value );


  };


  // PILOT proxy templates
  template <plat::processor ProcId>
  using input_states_of = typename per<ProcId>::input_states_backends;

  template <plat::processor ProcId>
  using backends_of = typename per<ProcId>::backends;




  // cat_t< <in_state_P0_AG1, in_state_P0_AG2...>, <in_state_P1_AG1, in_state_P1_AG2...>, ... <in_state_P2_AG1, in_state_P2_AG2> > --->


  // using input_states = util::tuple::cat_t< util::tuple::lift_enums_t< typename NativeT::all_proc_ids, input_states_of > >; // DON'T unique
  // Using lift_enums_t metafunction we'd have:
  // input_states_of :: Proc0 -> util::t_P0< std::t, std::t, std::t >
  // After
  // util::t<
  //    util::t_P0< std::t, std::t, std::t >
  //    util::t_P1< std::t, std::t, std::t >
  //    util::t_P2< std::t, std::t, std::t >
  // >
  // We want, the following, so we use lift_enums_flat_t metafunction
  // util::t<
  //   std::t, std::t, std::t
  //   std::t, std::t, std::t
  //   std::t, std::t, std::t
  // >

  // All must be the same from both runner and pilot points of view for type safety
  // static_assert( std::is_same_v<input_states, runner_input_states> ); XXX CHECK OUTSIDE


public:

  // These following types serve for two purposes:
  //  1. Determine the pilot backend associated to the input message.
  //  2. Determine the input_state of a typed message inference_end, hence to fully define msg::typed.

  // < in_state_P0_AG1, in_state_P0_AG2, ..., in_state_P1_AG1, in_state_P1_AG2, ... in_state_P2_AG1, in_state_P2_AG2, ... >
  using input_states = util::tuple::lift_enums_flat_t< typename NativeT::all_proc_ids, input_states_of >;

  static_assert( util::tuple::is_holding_std< input_states >::value );

  using input_states_ids = util::sequence::make_index_t<input_states::size()>;

  // Note that some types may be duplicated in input_states, if different agent implementers have the same input state. That's fine

  // ALL PILOT BACKENDS (to be instantiated from pilot::master)
  // < bnd_impl<P0, AG0>, bnd_impl<P0, AG1>, bnd_impl<P1, AG0>, bnd_impl<P1, AG1>, ... >
  using backends = util::tuple::flat_t< util::tuple::cat_t< util::tuple::lift_enums_t< typename NativeT::all_proc_ids, backends_of > > >;
};




template <typename NativeT>
class aux< msg::ctg::threading, NativeT > {
private:


  template <plat::processor ProcId>
  using agent_of = agent::pilot::threader_single<ProcId, NativeT>;

  // PILOT proxy templates
  template <plat::processor ProcId>
  using backend_of = agent::pilot::backend< msg::ctg::threading, agent_of<ProcId> >;

  template <plat::processor ProcId>
  using input_states_of = typename backend_of<ProcId>::input_state_type;



  template <plat::processor ProcId>
  using input_states_of = typename backend_of<ProcId>::input_state_type;

  // XXX
  // using input_states = util::tuple::cat_t< util::tuple::lift_enums_t< typename NativeT::all_proc_ids, input_states_of > >; // DON'T unique
  // using input_states = util::tuple::cat_t< util::tuple::lift_enums_t< typename NativeT::all_proc_ids, input_states_of > >; // DON'T unique

  // static_assert( util::tuple::is_holding_std< input_states >::value ); XXX 
  // static_assert( util::tuple::is_holding_std< input_states >::value ); XXX

  // All contents must be the same from both runner and pilot points of view for type safety
  /// static_assert( std::is_same_v<input_states, input_states> ); XXX

public:

  using input_states = util::tuple::lift_enums_t< typename NativeT::all_proc_ids, input_states_of >;

  // static_assert( util::tuple::is_holding_std< input_states >::value ); XXX 

  using input_states_ids = util::sequence::make_index_t<input_states::size()>;

  using backends = util::tuple::cat_t< util::tuple::lift_enums_t< typename NativeT::all_proc_ids, backend_of > >;

};


} // namespace learn::intf::pilot

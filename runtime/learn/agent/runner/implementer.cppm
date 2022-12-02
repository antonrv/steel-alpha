
export module SteelRT.Learn.Agent.Runner.Implementer;

  export import SteelRT.Learn.Agent.Common.Implementer;
  export import SteelRT.Learn.Approx.NeuralNet.Policy.Discrete;

import SteelRT.Learn.Interface.Runner.Send;

import SteelRT.Task.Descriptor;

import SteelRT.Util.Basic;
// import SteelRT.Util.Meta;
import SteelRT.Util.AppWork;


namespace learn::agent::runner {


export
template <plat::processor ProcId, typename AppGroupT, typename NativeT>
class implementer : public common::implementer<ProcId, AppGroupT, NativeT> {
private:

  using super_common = agent::common::implementer<ProcId, AppGroupT, NativeT>;

  using this_class = implementer;

  using input_layer_type = feat::layer< typename super_common::tuple_encoders >;

  using actor_t = approx::ann::policy::discrete<
      super_common::NUsers,
      input_layer_type,
      super_common::NHiddenLayers, super_common::NHiddenNeurons,
      typename super_common::actions_seq // Actions
    >;

  using action_t = typename super_common::action_type;

  actor_t m_actor;

public: // This works as the ContextT in the runner. So it must expose the following:

  using input_state_type = typename input_layer_type::state_type;

public:

  implementer( const learn::runner::cfg& runnerCfg ) :
    m_actor( super_common::str_identifier(), runnerCfg ) 
  {}

  template <typename TrueEncoderT>
  void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
    m_actor.initialize_true_encoder( trueEncoderRef );
  }


  template < app::call AppCall >
  action_t choose( uint_t thId, const workload::poly_desc_t polyDesc, float computeLoad ) noexcept {

    // std::cout << "LOAD IN IMPLEMENTER : " << computeLoad << std::endl;


    learn::intf::runner::send<NativeT, learn::intf::msg::ctg::tasking, learn::intf::msg::kind::inference_start, this_class>( polyDesc->youth );

    auto paramVersion = m_actor.get_parameters_version();

    auto chosenAction = m_actor.get_action( thId, static_cast< workload::desc_t<AppCall>* >( polyDesc ) ); 

    learn::intf::runner::send<NativeT, learn::intf::msg::ctg::tasking, learn::intf::msg::kind::inference_end, this_class>( paramVersion, computeLoad, chosenAction, m_actor.copy_input_activations(thId), polyDesc->youth );

    return chosenAction;
  }


  template < app::call AppCall >
  action_t retry_choose( uint_t thId, const workload::poly_desc_t polyDesc ) noexcept {

    // Here we could just resample without redoing the full fwd propagation, but let's recompute everything for the moment to waste more time & to discourage selection of dispatchers on shallow tasks.
    return m_actor.get_action( thId, static_cast< workload::desc_t<AppCall>* >( polyDesc ) ); 
  }

  // template < typename RestrictedActionSeqT, app::call AppCall >
  // action_t choose_restricted( uint_t thId, const workload::poly_desc_t polyDesc ) noexcept {

  //   learn::intf::runner::send<NativeT, learn::intf::msg::ctg::tasking, learn::intf::msg::kind::inference_start, this_class>( polyDesc->youth );

  //   auto chosenAction = m_actor.template get_restricted_action< RestrictedActionSeqT >( thId, static_cast< workload::desc_t<AppCall>* >( polyDesc ) );

  //   learn::intf::runner::send<NativeT, learn::intf::msg::ctg::tasking, learn::intf::msg::kind::inference_end, this_class>( chosenAction, m_actor.copy_input_activations(thId), polyDesc->youth );

  //   return chosenAction;
  // }

};

} // namespace learn::agent::runner

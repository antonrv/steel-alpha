
export module SteelRT.Learn.Agent.Pilot.Implementer;

  export import SteelRT.Learn.Agent.Common.Implementer;

  export import SteelRT.Learn.Approx.NeuralNet.Train.Discrete;
  export import SteelRT.Learn.Approx.NeuralNet.Train.StateValue;

  export import SteelRT.Learn.Agent.Pilot.ActorCritic;


import SteelRT.Util.Basic;
import SteelRT.Util.Meta;


export
namespace learn::agent::pilot {


template <plat::processor ProcId, typename AppGroupT, typename NativeT>
class implementer : public common::implementer<ProcId, AppGroupT, NativeT> {
private: // Useful types

  using super_common = agent::common::implementer<ProcId, AppGroupT, NativeT>;


  template <typename EncoderT>
  using ref_to_editable = typename feat::to_editable< EncoderT >::type;

  using runner_tuple_encoders = typename super_common::tuple_encoders;

  using editable_tuple_encoders = util::tuple::lift_t< runner_tuple_encoders, ref_to_editable >;

  using input_layer_type = feat::layer< editable_tuple_encoders >;

  using actor_type =
    approx::ann::train::discrete<
      input_layer_type,
      super_common::NHiddenLayers, super_common::NHiddenNeurons,
      typename super_common::actions_seq // Actions
    >;

  using critic_type =
    approx::ann::train::state_value<
      input_layer_type,
      super_common::NHiddenLayers, super_common::NHiddenNeurons // Hidden params does not have to be the same as the actor
    >;

  using actor_critic_t = pilot::actor_critic< actor_type, critic_type >;

  actor_critic_t m_actorCritic;

public: // Read by intf::pilot::backend

  static constexpr plat::processor processor_id = ProcId;

  using input_state_type = typename input_layer_type::state_type;

  using action_type = app::impl;


public:


  implementer( const learn::pilot::cfg& pilotCfg ) :
    m_actorCritic( pilotCfg, super_common::str_identifier(), str_t("critic_" + super_common::str_identifier()) )
  {}

  // No need to initialize_true_encoder. All encoders in pilot ANNs are true (ie non-ref)

  // Templated because it may be feat::terminal_state, different from ::input_state_type
  template < typename InputStateT >
  void set_state( const InputStateT& inputState ) {
    m_actorCritic.set_state( inputState );
  }

  // template < typename... Args >
  // pilot::update_info update_step( Args&&... args ) {
  //   return m_actorCritic.update_step( std::forward<Args>(args) ... );
  // }

  template < typename... Args >
  void update_batch( Args&&... args ) {
    m_actorCritic.update_batch( std::forward<Args>(args) ... );
  }


  void trace_learning_summary( ) {
    m_actorCritic.trace_learning_summary();
  }

  version_t get_parameters_version() const noexcept {
    return m_actorCritic.get_parameters_version();
  }

};


} // namespace learn::agent::pilot

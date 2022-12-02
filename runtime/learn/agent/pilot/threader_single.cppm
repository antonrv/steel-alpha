
export module SteelRT.Learn.Agent.Pilot.Threader.Single;

  export import SteelRT.Learn.Agent.Common.Threader.Single;

  export import SteelRT.Learn.Approx.NeuralNet.Train.Continuous;
  export import SteelRT.Learn.Approx.NeuralNet.Train.StateValue;

  export import SteelRT.Learn.Agent.Pilot.ActorCritic;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;


export
namespace learn::agent::pilot {


template <plat::processor ProcId, typename NativeT>
class threader_single : public agent::common::threader_single<ProcId, NativeT> {
private:

  using super_common = agent::common::threader_single<ProcId, NativeT>;

public:

  static constexpr plat::processor processor_id = ProcId;

  using preceeding_proc_sequence = typename super_common::preceeding_proc_sequence;

private:


  // transform ref to real to fully import the input states during training

  template <typename EncoderT>
  using ref_to_real = std::conditional_t< feat::is_editable_encoder<EncoderT>::value, EncoderT, typename EncoderT::reference_encoder_type >;

  using runner_tuple_encoders = typename super_common::tuple_encoders;

  using real_tuple_encoders = util::tuple::lift_t< runner_tuple_encoders, ref_to_real >;

  using input_layer_type = feat::layer< real_tuple_encoders >;

public: // Read by intf::pilot::backend

  using input_state_type = typename input_layer_type::state_type;

  using action_type = thread_count_t;

private:

  using actor_type =
    approx::ann::train::continuous<
      input_layer_type,
      super_common::NHiddenLayers, super_common::NHiddenNeurons, // Hidden layers common
      uint_t, 0, super_common::max_threads // Action space type and range
    >;

  using critic_type =
    approx::ann::train::state_value<
      input_layer_type,
      super_common::NHiddenLayers, super_common::NHiddenNeurons // Hidden params does not have to be the same as the actor
    >;


  using actor_critic_t = pilot::actor_critic< actor_type, critic_type >;

  actor_critic_t m_actorCritic;



public:

  threader_single( const learn::pilot::cfg& pilotCfg ) : 
    m_actorCritic( pilotCfg, super_common::str_identifier(), str_t("critic_" + super_common::str_identifier()) )
  {}


  // NOT NEEDED, no ref encoders
  // template <typename TrueEncoderT>
  // void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
  //   m_actorCritic.initialize_true_encoder( trueEncoderRef );
  // }


  template < typename InputStateT >
  void set_state( const InputStateT& inputState ) {
    m_actorCritic.set_state( inputState );
  }


  // template < typename... Args >
  // learn::pilot::update_info update_step( Args&&... args ) {
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

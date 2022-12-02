
export module SteelRT.Learn.Agent.Runner.Threader.Single;

  export import SteelRT.Learn.Agent.Common.Threader.Single;
  export import SteelRT.Learn.Approx.NeuralNet.Policy.Continuous;

import SteelRT.Learn.Interface.Runner.Send; // NOTE: Dont export

import SteelRT.Util.Basic;
// import SteelRT.Util.Meta;
// import SteelRT.Util.App;



namespace learn::agent::runner {


export
template <plat::processor ProcId, typename NativeT>
class threader_single : public agent::common::threader_single<ProcId, NativeT> {
private:

  using this_class = threader_single;

  using super_common = agent::common::threader_single<ProcId, NativeT>;

public:

  using preceeding_proc_sequence = typename super_common::preceeding_proc_sequence;

private:

  using input_layer_type = feat::layer< typename super_common::tuple_encoders >;

  using actor_t = approx::ann::policy::continuous<
      super_common::NUsers,
      input_layer_type,
      super_common::NHiddenLayers, super_common::NHiddenNeurons, // Hidden layers common
      uint_t, 0, super_common::max_threads // Action space type and range
    >;

  actor_t m_actor;

public: // This works as the ContextT in the runner. So it must expose the following:

  using input_state_type = typename input_layer_type::state_type;

public:

  // Initialize ref encoders
  template <typename TrueEncoderT>
  void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
    m_actor.initialize_true_encoder( trueEncoderRef );
  }



public:

  threader_single( const learn::runner::cfg& runnerCfg ) :
    m_actor( super_common::str_identifier(), runnerCfg )
  {}


  // DISABLED FOR THE MOMENT XXX XXX XXX
  // uint_t choose( thread_id_t thId, float computeLoad ) noexcept {

  //   // std::cout << "LOAD IN THREADER_SINGLE : " << computeLoad << std::endl;

  //   learn::intf::runner::send<NativeT, learn::intf::msg::ctg::threading, learn::intf::msg::kind::inference_start, this_class>( /*no-key*/ );

  //   auto paramVersion = m_actor.get_parameters_version();

  //   auto chosenAction = m_actor.get_action( thId );

  //   learn::intf::runner::send<NativeT, learn::intf::msg::ctg::threading, learn::intf::msg::kind::inference_end, this_class>( paramVersion, computeLoad, chosenAction, m_actor.copy_input_activations(thId) /*no-key*/ );

  //   return chosenAction;
  // }

  uint_t choose( thread_id_t thId, float computeLoad ) noexcept {
    return 0;
  }


};


} // namespace learn::agent::runner

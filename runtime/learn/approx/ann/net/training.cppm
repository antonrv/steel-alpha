

export module SteelRT.Learn.Approx.NeuralNet.Training;

  export import SteelRT.Learn.Approx.NeuralNet.Base;

  export import SteelRT.Learn.Approx.Sampler.Gaussian;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;


import SteelRT.Learn.Types;

// import SteelRT.Instrument;


import <tuple>;
import <array>;

import <fstream>;



namespace learn::approx::ann {

export
template <typename InputLayerT, typename NeuronCountSeq, typename FunSeq>
class training :
public
ann::base< 
  ann::propagate::bwd,
  ann::width::batch,
  InputLayerT,
  util::sequence::pop_back_t< util::sequence::add_front_t<NeuronCountSeq, InputLayerT::need_weights> >,
  NeuronCountSeq,
  FunSeq
>
{

private:

  using super =
    ann::base< 
      ann::propagate::bwd,
      ann::width::batch,
      InputLayerT,
      util::sequence::pop_back_t< util::sequence::add_front_t<NeuronCountSeq, InputLayerT::need_weights> >,
      NeuronCountSeq,
      FunSeq
    >;


  using layers_t = typename super::layers_t;

  layers_t m_layers;

  const str_t& m_weightsTargetDirRef;
  weights_close m_weightsClose;

  // For weights initialization
  sampler<distribution::gaussian> m_gaussianSampler;


  using batch_import_states_t = ann::batch_states_t<typename super::import_input_state>;

private:

  ///////////////
  //
  // Initialize SAMPLE_NORM layer parameters
  //
  ///////////////
  template <
    std::size_t ParametricGlobalId,
    util::req_t<
      util::same<util::tuple::element_t<ParametricGlobalId, typename super::layers_all_types_t>::layer_function, learn::fun::sample_norm>
    > ...
  >
  void initialize_parameters_of( bool doWeightsInit, const learn::pilot::cfg& pilotCfg ) {

    using layer_type = util::tuple::element_t<ParametricGlobalId, typename super::layers_all_types_t>;

    auto& sampleNormLayer = std::get< ParametricGlobalId >( m_layers );

    if (doWeightsInit) {

      static constexpr std::size_t NeuronCount = layer_type::neuron_count;

      array_t<NeuronCount>& meanRef = sampleNormLayer.edit_ipc_parameters_mean();
      array_t<NeuronCount>& varfactorRef = sampleNormLayer.edit_ipc_parameters_varfactor();

      for (auto& meanVal : meanRef) { meanVal = 0.f; }
      for (auto& varfactorVal : varfactorRef) { varfactorVal = 1.f; }

    }

    sampleNormLayer.set_parameters( pilotCfg.expMovAvgDecay );
  }

  ///////////////
  //
  // Initialize BATCH_NORM layer parameters
  //
  ///////////////
  template <
    std::size_t ParametricGlobalId,
    util::req_t<
      util::same<util::tuple::element_t<ParametricGlobalId, typename super::layers_all_types_t>::layer_function, learn::fun::batch_norm>
    > ...
  >
  void initialize_parameters_of( bool doWeightsInit, const learn::pilot::cfg& pilotCfg ) {

    using layer_type = util::tuple::element_t<ParametricGlobalId, typename super::layers_all_types_t>;

    auto& batchNormLayer = std::get< ParametricGlobalId >( m_layers );

    if (doWeightsInit) {

      static constexpr std::size_t NeuronCount = layer_type::neuron_count;

      array_t<NeuronCount>& meanRef = batchNormLayer.edit_ipc_parameters_mean();
      array_t<NeuronCount>& stddevRef = batchNormLayer.edit_ipc_parameters_stddev();

      // auto randNumsMean = m_gaussianSampler.sample_array< NeuronCount >();
      // auto randNumsStddev = m_gaussianSampler.sample_array< NeuronCount >();

      // for (auto j = 0u; j < NeuronCount; j++) {
      //   meanRef[j] = randNumsMean[j];
      //   stddevRef[j] = randNumsStddev[j];
      // }

      for (auto& meanVal : meanRef) { meanVal = 0.f; }
      for (auto& stddevVal : stddevRef) { stddevVal = 1.f; }
    }

    if (super::get_identifier().find("critic") != std::string::npos) { 
      
      batchNormLayer.set_parameters( pilotCfg.criticLearnRate, pilotCfg.adamMoment, pilotCfg.adamSquare );

    } else {

      batchNormLayer.set_parameters( pilotCfg.actorLearnRate, pilotCfg.adamMoment, pilotCfg.adamSquare );
    }
  }


  ///////////////
  //
  // Initialize BIAS layer parameters
  //
  ///////////////
  template <
    std::size_t ParametricGlobalId,
    util::req_t<
      util::same<util::tuple::element_t<ParametricGlobalId, typename super::layers_all_types_t>::layer_function, learn::fun::bias>
    > ...
  >
  void initialize_parameters_of( bool doWeightsInit, const learn::pilot::cfg& pilotCfg ) {

    using layer_type = util::tuple::element_t<ParametricGlobalId, typename super::layers_all_types_t>;

    auto& biasLayer = std::get< ParametricGlobalId >( m_layers );

    if (doWeightsInit) {

      static constexpr std::size_t NeuronCount = layer_type::neuron_count;

      array_t<NeuronCount>& biasRef = biasLayer.edit_ipc_parameters_bias();

      for (auto& biasVal : biasRef) { biasVal = 0.f; }
    }

    if (super::get_identifier().find("critic") != std::string::npos) { 
      
      biasLayer.set_parameters( pilotCfg.criticLearnRate, pilotCfg.adamMoment, pilotCfg.adamSquare );

    } else {

      biasLayer.set_parameters( pilotCfg.actorLearnRate, pilotCfg.adamMoment, pilotCfg.adamSquare );
    }
  }


  ///////////////
  //
  // Initialize MATRIX layer parameters
  //
  ///////////////
  template <
    std::size_t ParametricGlobalId,
    util::req_t<
      util::same<util::tuple::element_t<ParametricGlobalId, typename super::layers_all_types_t>::layer_function, learn::fun::matrix>
    > ...
  >
  void initialize_parameters_of( bool doWeightsInit, const learn::pilot::cfg& pilotCfg ) {

    using layer_type = util::tuple::element_t<ParametricGlobalId, typename super::layers_all_types_t>;

    auto& matrixLayer = std::get< ParametricGlobalId >( m_layers );

    if (doWeightsInit) {

      static constexpr std::size_t BwN = layer_type::bw_neuron_count;
      static constexpr std::size_t FwN = layer_type::fw_neuron_count;

      matrix_net_t<BwN, FwN>& wMatrixRef = matrixLayer.edit_ipc_parameters();
 
      // He et al. (2005) initialization
      fp_t scale = std::sqrtf(2.f/fp_t(BwN));

      auto randNums = m_gaussianSampler.sample_array<FwN * BwN>();

      for (auto f = 0u; f < FwN; f++) {
        for (auto b = 0u; b < BwN; b++) {
          wMatrixRef[ f ][ b ] = randNums[ f * BwN + b ] * scale;
        }
      }
    }

    if (super::get_identifier().find("critic") != std::string::npos) { 
      
      matrixLayer.set_parameters( pilotCfg.regularization, pilotCfg.criticLearnRate, pilotCfg.adamMoment, pilotCfg.adamSquare );

    } else {

      matrixLayer.set_parameters( pilotCfg.regularization, pilotCfg.actorLearnRate, pilotCfg.adamMoment, pilotCfg.adamSquare );
    }
  }

  template < std::size_t... ParametricGlobalIds >
  void initialize_parameters( bool doWeightsInit, const learn::pilot::cfg& pilotCfg, util::sequence::index_t<ParametricGlobalIds...> ) {
    ( initialize_parameters_of<ParametricGlobalIds>( doWeightsInit, pilotCfg ), ... );
  }


public:

  training(const str_t idStr, const learn::pilot::cfg& pilotCfg ) :
    super(idStr),
    m_weightsTargetDirRef( pilotCfg.targetDir ),
    m_weightsClose( pilotCfg.close ),
    m_gaussianSampler( pilotCfg.seed, pilotCfg.seedValue )
  {

    // 1. Bind matrix layers to ipc shmem objects
    super::bind_all_weights( m_layers, typename super::parametric_layers_ids{} );

    // 2. Optionally reuse weights from file
    bool fileInitSuccess = false;
    if (pilotCfg.open == weights_open::reuse or pilotCfg.open == weights_open::try_reuse) {

      fileInitSuccess = super::try_initialize_file_weights();

      if ((not fileInitSuccess) and pilotCfg.open == weights_open::reuse) {
        throw std::logic_error("Could not initialize NN weights from file but it was mandatory");
      }
    }

    // 3. Optionally initialize weights (if not file init success) and set per-layer configuration parameters.
    initialize_parameters( (not fileInitSuccess), pilotCfg, typename super::parametric_layers_ids{} );
  }


  ~training() {
    if (m_weightsClose == weights_close::save) {
      super::save_file_weights();
    }
    // super::dealloc_shmem();
  }


  void compute_forward( const batch_import_states_t& importStates ) noexcept {

    super::compute_forward_from_import( m_layers, importStates );
  }


  // DEPRECATED. Now accessed directly via last layer ref
  // To be called from the critic to get the state value
  // const auto& compute_activations( const batch_import_states_t& importStates ) noexcept {

  //   compute_forward( importStates ); 
  // 
  //   return std::get< super::LastId >( m_layers ).get_activations();
  // }


  void compute_backward( ) noexcept {

    super::compute_backward( m_layers );

    // super::update_version(); XXX TMP
  }

  // To set the source of errors in a particular way from the derived ann
  auto& get_last_layer_ref() noexcept {
    return std::get< super::LastId >( m_layers );
  }

  auto& get_pre_last_layer_ref() noexcept {
    return std::get< super::LastId - 1 >( m_layers );
  }

protected:

  // Not needed: no ref encoders in training.
  // template <typename TrueEncoderT>
  // void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
  //   super::initialize_true_encoder( m_layers, trueEncoderRef );
  // }

  // auto get_last_activations( ) const {
  //   return super::get_last_activations( m_layers );
  // }

};

} // namespace learn::approx::ann


export module SteelRT.Learn.Approx.NeuralNet.Base;

  export import SteelRT.Learn.Approx.NeuralNet.Layer;
  export import SteelRT.Learn.Feat.Layer;

import SteelRT.Learn.IPC;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Instrument;

import <fstream>;

export
namespace learn::approx::ann {

// Transformation of learn::fun::matrix --> learn::fun::matrix_ro, learn::fun::matrix_rw


template <ann::propagate Prop, ann::width Width, typename InputLayerT, typename BwNeuronCountSeq, typename FwNeuronCountSeq, typename FunSeq>
class base;

template <ann::propagate Prop, ann::width Width, typename InputLayerT, std::size_t... BwNeuronCounts, std::size_t... FwNeuronCounts, fun... Funs>
class base < Prop, Width, InputLayerT, util::sequence::index_t<BwNeuronCounts...>, util::sequence::index_t<FwNeuronCounts...>, util::sequence::enum_t<fun, Funs...> > {
private:

  static_assert(sizeof...(BwNeuronCounts) == sizeof...(FwNeuronCounts) and sizeof...(FwNeuronCounts) == sizeof...(Funs));

protected:

  using BwNeuronCountSeq = util::sequence::index_t< BwNeuronCounts... >;
  using FwNeuronCountSeq = util::sequence::index_t< FwNeuronCounts... >;
  using FunSeq = util::sequence::enum_t<fun, fun::input, Funs... >;
  using HiddenFunSeq = util::sequence::enum_t<fun, Funs... >;

  static constexpr std::size_t NOutput = util::sequence::last_v< FwNeuronCountSeq >;


  // Predicate to identify layers that hold parameters to be ipc-shared between runner and pilot
  template <learn::fun Fun> struct is_parametric :
    std::disjunction<
      util::same<Fun, learn::fun::sample_norm>,
      util::same<Fun, learn::fun::batch_norm>,
      util::same<Fun, learn::fun::bias>,
      util::same<Fun, learn::fun::matrix>
    >
  {};

  // We add a +1 index to skip the InputLayerT
  using parametric_layers_ids = util::sequence::satisfy_indexes_t<FunSeq, is_parametric>;


  using layers_all_types_t = util::tuple_t< InputLayerT, ann::layer< Prop, Width, Funs, BwNeuronCounts, FwNeuronCounts > ... >;
  // using layers_parametric_types_t = util::tuple_t< 

  static constexpr std::size_t NLayers = layers_all_types_t::size();

  static constexpr std::size_t FirstId = 0;
  static constexpr std::size_t LastId = NLayers - 1;

  template <std::size_t ParametricLayerId>
  struct bytes_of_layer {
    using type = std::size_t;
    static constexpr std::size_t value = util::tuple::element_t<ParametricLayerId, layers_all_types_t>::bytes_count;
  };
  

  using parametric_layers_bytes = util::sequence::transform_t< parametric_layers_ids, std::size_t, bytes_of_layer >;

  // template <learn::fun Fun> struct is_sample_norm : util::same<Fun, learn::fun::sample_norm> {};

  // using sample_norm_layers_ids = util::sequence::satisfy_indexes_t<FunSeq, is_parametric>;


private:

  std::unique_ptr< ipc::parameters > m_ownShmemParameters = nullptr;
protected:

  // void dealloc_shmem() { // TMP XXX
  //   m_ownShmemParameters.reset();
  // }

protected:

  using layers_t = util::tuple::as_std_t< layers_all_types_t >;

  using input_state = typename InputLayerT::state_type;
  using import_input_state = typename InputLayerT::state_type;


private: // weights to be shared by all users.

  str_t m_identifierStr; // Just for debugging purposes


private:

  template <typename T>
  using vec_t = std::vector<T>;
 
  template <typename ArrayT> 
  static vec_t<typename ArrayT::value_type> array2vec( const ArrayT& arrValues ) {
    vec_t<typename ArrayT::value_type> retVec(arrValues.size());
    for (auto i = 0u; i < arrValues.size(); i++) { retVec[i] = arrValues[i]; }
    return retVec;
  }

  void initialize_shared_weights( ) {

    using seq_parametric_funs = util::sequence::mask_t< FunSeq, parametric_layers_ids >;

    auto perLayerFunction = array2vec( util::sequence::to_array_v< seq_parametric_funs > );

    auto perLayerByteCount = array2vec( util::sequence::to_array_v< parametric_layers_bytes > );


    // lc == 'layer count', b == 'bytes'
    const str_t weightsIdStr = m_identifierStr + "_lc" + std::to_string(parametric_layers_ids::size()) + "_b" + std::to_string( util::sequence::index_sum_v< parametric_layers_bytes > );

    if constexpr (Prop == ann::propagate::bwd) {
      ipc::parameters::pre_remove(weightsIdStr);
    }

    using open_mode_t = std::conditional_t<Prop == ann::propagate::fwd, ipc::parameters::open_only_t, ipc::parameters::create_only_t>;

    m_ownShmemParameters = std::make_unique< ipc::parameters >( perLayerByteCount, perLayerFunction, weightsIdStr, open_mode_t{}, Prop );

    instr::trace<instr::event::weights::init_ipc>( "OK", weightsIdStr );
  } 


protected: // ================ CONSTRUCTOR

  base(const str_t idStr) : m_identifierStr(idStr)
  {
    initialize_shared_weights( );
  }

  base() = delete;
  base(base&&) = delete;
  base(const base&) = delete;

public:

  const str_t& get_identifier() const noexcept {
    return m_identifierStr;
  }

private: // SET WEIGHTS METHODS


  template <std::size_t ParametricGlobalId>
  void bind_weights( layers_t& layersRef ) noexcept {

    static constexpr std::size_t ParametricLocalId = util::sequence::get_index_v< parametric_layers_ids, ParametricGlobalId >;

    std::get< ParametricGlobalId >( layersRef ).template bind_shared_weights< ParametricLocalId >( m_ownShmemParameters.get() );
  }


protected:

  // First function called from ::training and ::inference
  template <std::size_t... ParametricGlobalIds>
  void bind_all_weights( layers_t& layersRef, util::sequence::index_t<ParametricGlobalIds...> ) noexcept {

    ( bind_weights<ParametricGlobalIds>( layersRef ), ... );
  }

private:

  static constexpr const char * s_saveFileExt = ".wgt";

protected:

  
  ///////////////
  //
  // Open weights from file (callable only from training)
  //
  ///////////////
  bool try_initialize_file_weights( ) {

    const str_t fname = m_ownShmemParameters->get_identifier() + s_saveFileExt;
    // Try to open a file with that id
    
    std::ifstream ifsWeights( fname.c_str(), std::ios::in | std::ios::binary );

    if (ifsWeights.is_open()) {

      auto nBytes = m_ownShmemParameters->get_total_size();

      // char -> std::byte ? TODO
      auto dataPtr = static_cast< char * >( m_ownShmemParameters->edit_ptr() );

      ifsWeights.read( dataPtr, nBytes );

      instr::trace<instr::event::weights::init_file>( "OK", fname );
  
      return true;

    } else {

      instr::trace<instr::event::weights::init_file>( "fail", fname );

      return false;
    }
  }


  ///////////////
  //
  // Save weights to file (callable only from training)
  //
  ///////////////
  void save_file_weights( ) {

    try {

      const str_t fname = m_ownShmemParameters->get_identifier() + s_saveFileExt;

      std::ofstream ofsWeights( fname.c_str(), std::ios::out | std::ios::binary | std::ios::trunc );

      if (ofsWeights.is_open()) {

        auto nBytes = m_ownShmemParameters->get_total_size();

        auto dataPtr = static_cast< char const * >( m_ownShmemParameters->get_ptr() );

        ofsWeights.write( dataPtr, nBytes );

        instr::trace<instr::event::weights::fini_save>( "OK", fname );

      } else {

        instr::trace<instr::event::weights::fini_save>( "Could not open file to save weights", fname );
      }

    } catch(...) {

      instr::trace<instr::event::weights::fini_save>( "Error captured while saving file weights" );
      // Do not rethrow whatsoever
    }

  }


protected: // ENCODER REF INITIALIZATION

  template <typename TrueEncoderT>
  static
  void initialize_true_encoder( layers_t& layersRef, const TrueEncoderT& trueEncoderRef ) noexcept {
    std::get< FirstId >( layersRef ).initialize_true_encoder( trueEncoderRef );
  }



private: // FORWARD PROPAGATION METHODS

  template <std::size_t TargetLayerId>
  struct activation_propagable_layer : 
    std::conjunction<
      util::is< bool(TargetLayerId > 0) >,
      util::not_same< std::tuple_element_t<TargetLayerId, layers_t>::layer_function, learn::fun::input >,
      util::not_same< std::tuple_element_t<TargetLayerId, layers_t>::layer_function, learn::fun::encode >
    > {};

  // --- Single pass
  template <
    std::size_t TargetLayerId,
    util::req_t< activation_propagable_layer<TargetLayerId> > ...
  >
  static
  void forward_pass( layers_t& layersRef ) noexcept {
    std::get< TargetLayerId >( layersRef ).set_activations( std::get<TargetLayerId - 1>( layersRef ).get_activations() );
  }

  template <
    std::size_t TargetLayerId,
    util::req_t< std::negation<activation_propagable_layer<TargetLayerId>> > ...
  >
  static
  void forward_pass( layers_t& layersRef ) noexcept {
    // Do nothing
  }

  // === TRIGGER ALL PASSES
  template <std::size_t... TargetLayerIds>
  static
  void trigger_forward_passes( layers_t& layersRef, util::sequence::index_t<TargetLayerIds...> ) noexcept {


    ( forward_pass< TargetLayerIds >( layersRef ), ... ); 
  }


protected:

  // CALLABLE FROM RUNNER
  template <typename... InputArgs>
  static
  void compute_forward_from_args( layers_t& layersRef, InputArgs&&... inputArgs ) noexcept {

    // Maybe membarrier here so that following writes cannot anticipate previous read
    instr::trace<instr::event::weights::fwdprop>( "Setting activations" );

    std::get< FirstId >( layersRef ).set_activations( std::forward<InputArgs>(inputArgs) ... );

    instr::trace<instr::event::weights::fwdprop>( "From args" );

    trigger_forward_passes( layersRef, util::sequence::tail_t< util::sequence::make_index_t< NLayers > >{} );
  }


private: // BACKWARD ERROR PROPAGATION METHODS

  // First layer is never propagable because there is no need to propagate
  // Last layer is never propagable because the errors are set in a custom way
  template <std::size_t TargetLayerId>
  struct error_propagable_layer :
    std::conjunction<
      util::not_same<util::tuple::element_t<TargetLayerId, layers_all_types_t>::layer_function, learn::fun::input>,
      util::not_same<util::tuple::element_t<TargetLayerId, layers_all_types_t>::layer_function, learn::fun::encode>,
      util::is< bool(TargetLayerId < LastId) >
    >
  {};


  template <
    std::size_t TargetLayerId,
    util::req_t< error_propagable_layer<TargetLayerId> > ...
  >
  static
  void backward_error( layers_t& layersRef ) noexcept {

    std::get<TargetLayerId>( layersRef ).set_errors( std::get<TargetLayerId - 1>( layersRef ).get_activations(), std::get<TargetLayerId + 1>( layersRef ).get_errors() );
  }

  // --- Single pass: on the FIRST layer => No need to compute the error bc no further error prop needed
  template <
    std::size_t TargetLayerId,
    util::req_t< std::negation<error_propagable_layer<TargetLayerId>> > ...
  >
  static
  void backward_error( layers_t& layersRef ) noexcept {
    // Do nothing
  }


private: // BACKWARD UPDATE PROPAGATION METHODS

  template <std::size_t TargetLayerId>
  struct updatable_layer :
    std::disjunction<
      util::same<util::tuple::element_t<TargetLayerId, layers_all_types_t>::layer_function, learn::fun::sample_norm>,
      util::same<util::tuple::element_t<TargetLayerId, layers_all_types_t>::layer_function, learn::fun::batch_norm>,
      util::same<util::tuple::element_t<TargetLayerId, layers_all_types_t>::layer_function, learn::fun::bias>,
      util::same<util::tuple::element_t<TargetLayerId, layers_all_types_t>::layer_function, learn::fun::matrix>
    > {};

  // --- Single UPDATE PASS: on a MATRIX OR BNORMALIZE layer => just update the weights
  template <
    std::size_t TargetLayerId,
    util::req_t< updatable_layer<TargetLayerId> > ...
  >
  static
  void backward_update( layers_t& layersRef ) noexcept {

    // Layer transition is a matrix --> need to update the weights with a scale
    std::get<TargetLayerId>( layersRef ).update_weights(
      std::get<TargetLayerId - 1>( layersRef ).get_activations(),
      std::get<TargetLayerId + 1>( layersRef ).get_errors()
    );
  }

  // --- Single UPDATE PASS: on a NON-UPDATABLE => nothing to update
  template <
    std::size_t TargetLayerId,
    util::req_t< std::negation< updatable_layer<TargetLayerId> > > ...
  >
  static
  void backward_update( layers_t& layersRef ) noexcept {
    // Do nothing
  }


  // === TRIGGER ALL BACKWARD PASSES
  template <std::size_t... TargetLayerIds>
  static
  void trigger_backward_passes( layers_t& layersRef, util::sequence::index_t<TargetLayerIds...> ) noexcept {

    instr::trace<instr::event::weights::backprop>( "errors" );

    // 1. Propagate all the errors first
    ( backward_error< TargetLayerIds >( layersRef ), ... ); 

    instr::trace<instr::event::weights::backprop>( "updates" );

    // 2. Update weights, only after all the errors have been propagated
    ( backward_update< TargetLayerIds >( layersRef ), ... );

    // Maybe membarrier to make sure update version write is done after all previous writes
  }


private:

  using batch_input_states_t = ann::values< ann::width::batch, input_state >;


  static void encode_input( layers_t& layersRef, const batch_input_states_t& inputStates ) noexcept {

    auto& featInputLayer = std::get< FirstId >( layersRef );
    auto& encodeInputLayer = std::get< FirstId + 1 >( layersRef );

    const auto batchSize = inputStates.get_batch_size();

    encodeInputLayer.prepare_batch( batchSize );

    for (auto s = 0u; s < batchSize; s++) {

      featInputLayer.import_activations( inputStates.get_values(s) );

      encodeInputLayer.encode_activations( featInputLayer.get_activations(), s );
    }
  }

protected:

  static void compute_forward_from_import( layers_t& layersRef, const batch_input_states_t& inputStates ) noexcept {

    static_assert( Prop == ann::propagate::bwd );

    instr::trace<instr::event::weights::fwdprop>( "Encoding samples", inputStates.get_batch_size() );

    // 1. Fill encode layer for each sample of input state
    encode_input( layersRef, inputStates );

    using forward_seq = util::sequence::make_index_t<NLayers>;

    instr::trace<instr::event::weights::fwdprop>( "From import" );

    trigger_forward_passes( layersRef, forward_seq{} );
  }


  static void compute_backward( layers_t& layersRef ) {

    using backward_seq = util::sequence::reverse_t< util::sequence::make_index_t< NLayers > >;

    trigger_backward_passes( layersRef, backward_seq{} );
  }

  void update_version() const noexcept {
    // 3. All updates done, update version
    m_ownShmemParameters->update_version();
  }


public:

  // static
  // auto get_last_activations( const layers_t& layersRef ) {

  //   return std::get< LastId >( layersRef ).get_activations();
  // }

  version_t get_parameters_version() const noexcept {
    return m_ownShmemParameters->get_version();
  }


};

} // namespace learn::approx::ann

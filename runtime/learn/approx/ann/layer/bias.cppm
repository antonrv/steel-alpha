
export module SteelRT.Learn.Approx.NeuralNet.Layer.Bias;


import SteelRT.Learn.Approx.NeuralNet.Layer.Values;
import SteelRT.Learn.Approx.NeuralNet.Layer.Adam;

import SteelRT.Learn.IPC;


import SteelRT.Util.Types;
import SteelRT.Util.Require;
import SteelRT.Learn.Types;

import SteelRT.Instrument;
import SteelRT.Instrument.Predicates;


import SteelRT.Util.Assert;
#include "assert.hpp"


namespace learn::approx::ann {

//// Forward propagation (SINGLE)
export
template < learn::fun FunBias, std::size_t NeuronCount >
class layer<
  ann::propagate::fwd, ann::width::single, FunBias, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunBias, learn::fun::bias>
  >
>
{
protected:

  using activations_t = values< ann::width::single, array_t<NeuronCount> >;

  activations_t m_activations;

  using shmem_weights_type = ipc::parameters;

  using weights_bias_t = array_t<NeuronCount>;

  std::function< const weights_bias_t&() > m_fetchConstBiasWeights = nullptr;

public:

  static constexpr learn::fun layer_function = FunBias;

  static constexpr std::size_t bytes_count = sizeof(weights_bias_t);

  static constexpr std::size_t neuron_count = NeuronCount;

public:

  template <std::size_t ParamLayerId>
  void bind_shared_weights( const ipc::parameters * ipcShmemParameters ) {

    ensure(m_fetchConstBiasWeights == nullptr, "Bind parameters can only be initialized once");

    m_fetchConstBiasWeights = std::bind( &ipc::parameters::get_cast<weights_bias_t, ParamLayerId, FunBias>, ipcShmemParameters );
  }


  void set_activations( const activations_t& bwActivations ) noexcept {

    const auto& weightsBiases = m_fetchConstBiasWeights();

    for (auto j = 0u; j < NeuronCount; j++) {
      m_activations[j] = bwActivations[j] + weightsBiases[j];
    }
  }

  const activations_t& get_activations() const noexcept {
    return m_activations;
  }


};



//// Forward propagation (BATCH)
export
template < learn::fun FunBias, std::size_t NeuronCount >
class layer<
  ann::propagate::fwd, ann::width::batch, FunBias, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunBias, learn::fun::bias>
  >
>
{

protected:

  using single_activations_t = values< ann::width::single, array_t<NeuronCount> >;

  using activations_t = values< ann::width::batch, array_t<NeuronCount> >;

  activations_t m_activations;

  using shmem_weights_type = ipc::parameters;

  using weights_bias_t = array_t<NeuronCount>;

  std::function< const weights_bias_t&() > m_fetchConstBiasWeights = nullptr;

  uint_t m_layerId = 0; // NOTE: Just for debugging purposes

public:

  static constexpr learn::fun layer_function = learn::fun::bias;

  static constexpr std::size_t bytes_count = sizeof(weights_bias_t);

  static constexpr std::size_t neuron_count = NeuronCount;


public:

  template <std::size_t ParamLayerId>
  void bind_shared_weights( const ipc::parameters * ipcShmemParameters ) {

    m_layerId = ParamLayerId;  // NOTE: Just for debugging purposes

    ensure(m_fetchConstBiasWeights == nullptr, "Bind parameters can only be initialized once");

    m_fetchConstBiasWeights = std::bind( &ipc::parameters::get_cast<weights_bias_t, ParamLayerId, FunBias>, ipcShmemParameters );
  }



  void set_activations( const activations_t& bwActivations ) noexcept {

    const auto& biasWeights = m_fetchConstBiasWeights();

    instr::trace<instr::event::learn_monitor::parameters>( "BiasLayerId", m_layerId, "WeightsBias", biasWeights );

    const auto batchSize = bwActivations.get_batch_size();

    instr::trace<instr::event::training::set_activations>("Bias", "batchSize", batchSize);

    m_activations.resize( batchSize );

    for (auto s = 0u; s < batchSize; s++) {
    
      auto& perSampleFwActivations = m_activations.edit_values(s); 
      const auto& perSampleBwActivations = bwActivations.get_values(s); 
  
      for (auto j = 0u; j < NeuronCount; j++) {
        perSampleFwActivations[j] = perSampleBwActivations[j] + biasWeights[j];
      }

      instr::trace<instr::event::ann_prop::forward>( "sample", s, "bwActiv", perSampleBwActivations, "fwActiv", perSampleFwActivations );
    }

  }


  const activations_t& get_activations() const noexcept {
    return m_activations;
  }

};


//// Backward propagation (BATCH)
export
template < learn::fun FunBias, std::size_t NeuronCount >
class layer<
  ann::propagate::bwd, ann::width::batch, FunBias, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunBias, learn::fun::bias>
  >
>
: public layer< ann::propagate::fwd, ann::width::batch, FunBias, NeuronCount, NeuronCount >
{

private:

  using super_fwd_layer = layer< ann::propagate::fwd, ann::width::batch, FunBias, NeuronCount, NeuronCount >;

  using bw_activations_t = values< ann::width::batch, array_t<NeuronCount> >;

  using fw_errors_t = values< ann::width::batch, array_t<NeuronCount> >;

  using errors_t = values< ann::width::batch, array_t<NeuronCount> >;

  errors_t m_errors;


  using weights_bias_t = typename super_fwd_layer::weights_bias_t; 


  std::function< weights_bias_t&() > m_fetchEditBiasWeights = nullptr;

  ann::adam<NeuronCount> m_adamGradientBias;

  fp_t m_learnRate = 0;

public:

  void set_parameters( fp_t lr, fp_t adamMoment, fp_t adamSquare ) noexcept {
    m_learnRate = lr;

    m_adamGradientBias.set_parameters( adamMoment, adamSquare );
  }


  template <std::size_t ParamLayerId>
  void bind_shared_weights( ipc::parameters * ipcShmemParameters ) {

    super_fwd_layer::template bind_shared_weights<ParamLayerId>( ipcShmemParameters );

    ensure(m_fetchEditBiasWeights == nullptr, "Bind parameters can only be initialized once");

    m_fetchEditBiasWeights = std::bind( &ipc::parameters::edit_cast<weights_bias_t, ParamLayerId, FunBias>, ipcShmemParameters );
  }


  void update_weights( const bw_activations_t& bwActivations, const fw_errors_t& fwErrors ) noexcept {

    ensure( bwActivations.get_batch_size() == fwErrors.get_batch_size(), "Mismatch in batch sizes" );

    const auto batchSize = fwErrors.get_batch_size();


    // 1. Compute gradients
    auto& gradientBias = m_adamGradientBias.edit_gradient();

    gradientBias.fill(0);

    for (auto s = 0u; s < batchSize; s++) {

      const auto& perSampleFwErrors = fwErrors.get_values(s);
      // const auto& perSampleBwActiv = bwActivations.get_values(s);

      for (auto j = 0u; j < NeuronCount; j++) {
        gradientBias[j] += perSampleFwErrors[j];
      }
    }

    // 2. Correct gradients with ADAM algorithm
    m_adamGradientBias.correct_gradient();

    // 3. Update weights
    auto& biasWeights = m_fetchEditBiasWeights();

    for (auto j = 0u; j < NeuronCount; j++) {
      biasWeights[j] += m_learnRate * gradientBias[j];
    }
  }


  void set_errors( const bw_activations_t& bwActivations, const fw_errors_t& fwErrors ) noexcept {

    const auto batchSize = fwErrors.get_batch_size();

    instr::trace<instr::event::training::set_errors>("Bias", "batchSize", fwErrors.get_batch_size());

    // bwActivations not used, but check this
    ensure( bwActivations.get_batch_size() == batchSize, "Mismatch in batch sizes" );

    // const auto& biasWeights = m_fetchEditBiasWeights(); not needed

    m_errors.resize( batchSize );

    for (auto s = 0u; s < batchSize; s++) {

      auto& perSampleBwErrors = m_errors.edit_values(s);
      const auto& perSampleFwErrors = fwErrors.get_values(s);

      for (auto j = 0u; j < NeuronCount; j++) {
        perSampleBwErrors[j] = perSampleFwErrors[j]; // Times 1
        // Error propagation does not depend on biasWeights bc derivative wrt bwActiv does not depend on biasWeights
      }

      instr::trace<instr::event::ann_prop::backward>( "set-errors",s, "bwErrors", m_errors.get_values(s), "bias", "fwErrors", fwErrors.get_values(s) );
    }

  }



  const errors_t& get_errors() const noexcept {
    return m_errors;
  }


  // Expose for initialization
  weights_bias_t& edit_ipc_parameters_bias() noexcept {
    return m_fetchEditBiasWeights();
  }

};


} // namespace learn::approx::ann {

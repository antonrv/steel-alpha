
export module SteelRT.Learn.Approx.NeuralNet.Layer.BatchNorm;


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
template < learn::fun FunBatchNorm, std::size_t NeuronCount >
class layer<
  ann::propagate::fwd, ann::width::single, FunBatchNorm, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunBatchNorm, learn::fun::batch_norm>
  >
>
{

protected:

  using activations_t = values< ann::width::single, array_t<NeuronCount> >;

  activations_t m_activations;

  using shmem_weights_type = ipc::parameters;

  using weights_mean_t = array_t<NeuronCount>;
  using weights_stddev_t = array_t<NeuronCount>;

  std::function< const weights_mean_t&() > m_fetchConstMeanWeights = nullptr;
  std::function< const weights_stddev_t&() > m_fetchConstStddevWeights = nullptr;

public:

  static constexpr learn::fun layer_function = FunBatchNorm;

  static constexpr std::size_t bytes_count = sizeof(weights_mean_t) + sizeof(weights_stddev_t);

  static constexpr std::size_t neuron_count = NeuronCount;

public:

  template <std::size_t ParamLayerId>
  void bind_shared_weights( const ipc::parameters * ipcShmemParameters ) {

    ensure(m_fetchConstMeanWeights == nullptr, "Bind parameters can only be initialized once");
    ensure(m_fetchConstStddevWeights == nullptr, "Bind parameters can only be initialized once");

    m_fetchConstMeanWeights = std::bind( &ipc::parameters::get_partial_cast<weights_mean_t, ParamLayerId, FunBatchNorm, 0>, ipcShmemParameters );

    static constexpr std::size_t ByteShift = sizeof(weights_mean_t);

    m_fetchConstStddevWeights = std::bind( &ipc::parameters::get_partial_cast<weights_stddev_t, ParamLayerId, FunBatchNorm, ByteShift>, ipcShmemParameters );
  }


  void set_activations( const activations_t& bwActivations ) noexcept {

    const auto& weightsMeans = m_fetchConstMeanWeights();
    const auto& weightsStddevs = m_fetchConstStddevWeights();

    for (auto j = 0u; j < NeuronCount; j++) {
      m_activations[j] = bwActivations[j] * weightsStddevs[j] + weightsMeans[j];
    }
  }


  const activations_t& get_activations() const noexcept {
    return m_activations;
  }

};


//// Forward propagation (BATCH)
export
template < learn::fun FunBatchNorm, std::size_t NeuronCount >
class layer<
  ann::propagate::fwd, ann::width::batch, FunBatchNorm, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunBatchNorm, learn::fun::batch_norm>
  >
>
{

protected:

  using single_activations_t = values< ann::width::single, array_t<NeuronCount> >;

  using activations_t = values< ann::width::batch, array_t<NeuronCount> >;

  activations_t m_activations;

  using shmem_weights_type = ipc::parameters;

  using weights_mean_t = array_t<NeuronCount>;
  using weights_stddev_t = array_t<NeuronCount>;


  std::function< const weights_mean_t&() > m_fetchConstMeanWeights = nullptr;
  std::function< const weights_stddev_t&() > m_fetchConstStddevWeights = nullptr;

  uint_t m_layerId = 0; // NOTE: Just for debugging purposes

public:

  static constexpr learn::fun layer_function = learn::fun::batch_norm;

  static constexpr std::size_t bytes_count = sizeof(weights_mean_t) + sizeof(weights_stddev_t);

  static constexpr std::size_t neuron_count = NeuronCount;


public:

  template <std::size_t ParamLayerId>
  void bind_shared_weights( const ipc::parameters * ipcShmemParameters ) {

    m_layerId = ParamLayerId;  // NOTE: Just for debugging purposes

    ensure(m_fetchConstMeanWeights == nullptr, "Bind parameters can only be initialized once");
    ensure(m_fetchConstStddevWeights == nullptr, "Bind parameters can only be initialized once");

    m_fetchConstMeanWeights = std::bind( &ipc::parameters::get_partial_cast<weights_mean_t, ParamLayerId, FunBatchNorm, 0>, ipcShmemParameters  );

    static constexpr std::size_t ByteShift = sizeof(weights_mean_t);

    m_fetchConstStddevWeights = std::bind( &ipc::parameters::get_partial_cast<weights_stddev_t, ParamLayerId, FunBatchNorm, ByteShift>, ipcShmemParameters );
  }



  void set_activations( const activations_t& bwActivations ) noexcept {

    const auto& meanWeights = m_fetchConstMeanWeights();
    const auto& stddevWeights = m_fetchConstStddevWeights();

    instr::trace<instr::event::learn_monitor::parameters>( "BNLayerId", m_layerId, "WeightsMean", meanWeights, "WeightsStddev", stddevWeights );

    const auto batchSize = bwActivations.get_batch_size();

    instr::trace<instr::event::training::set_activations>("BatchNorm", "batchSize", batchSize);

    m_activations.resize( batchSize );

    if (batchSize == 1) {
      // No stddev correction IF BATCHSIZE == 1
      for (auto j = 0u; j < NeuronCount; j++) {
        m_activations.edit_values(0)[j] = bwActivations.get_values(0)[j] + meanWeights[j];
      }
      return;
    }

    for (auto s = 0u; s < batchSize; s++) {
    
      auto& perSampleFwActivations = m_activations.edit_values(s); 
      const auto& perSampleBwActivations = bwActivations.get_values(s); 
  
      for (auto j = 0u; j < NeuronCount; j++) {
        perSampleFwActivations[j] = stddevWeights[j] * perSampleBwActivations[j] + meanWeights[j];
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
template < learn::fun FunBatchNorm, std::size_t NeuronCount >
class layer<
  ann::propagate::bwd, ann::width::batch, FunBatchNorm, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunBatchNorm, learn::fun::batch_norm>
  >
>
: public layer< ann::propagate::fwd, ann::width::batch, FunBatchNorm, NeuronCount, NeuronCount >
{

private:

  using super_fwd_layer = layer< ann::propagate::fwd, ann::width::batch, FunBatchNorm, NeuronCount, NeuronCount >;

  using bw_activations_t = values< ann::width::batch, array_t<NeuronCount> >;

  using fw_errors_t = values< ann::width::batch, array_t<NeuronCount> >;

  using errors_t = values< ann::width::batch, array_t<NeuronCount> >;

  errors_t m_errors;


  using weights_mean_t = typename super_fwd_layer::weights_mean_t; 
  using weights_stddev_t = typename super_fwd_layer::weights_stddev_t; 


  std::function< weights_mean_t&() > m_fetchEditMeanWeights = nullptr;
  std::function< weights_stddev_t&() > m_fetchEditStddevWeights = nullptr;


  ann::adam<NeuronCount> m_adamGradientMean;
  ann::adam<NeuronCount> m_adamGradientStddev;

  fp_t m_learnRate = 0;

public:

  void set_parameters( fp_t lr, fp_t adamMoment, fp_t adamSquare ) noexcept {
    m_learnRate = lr;

    m_adamGradientMean.set_parameters( adamMoment, adamSquare );
    m_adamGradientStddev.set_parameters( adamMoment, adamSquare );
  }


  template <std::size_t ParamLayerId>
  void bind_shared_weights( ipc::parameters * ipcShmemParameters ) {

    super_fwd_layer::template bind_shared_weights<ParamLayerId>( ipcShmemParameters );

    ensure(m_fetchEditMeanWeights == nullptr, "Bind parameters can only be initialized once");
    ensure(m_fetchEditStddevWeights == nullptr, "Bind parameters can only be initialized once");

    m_fetchEditMeanWeights = std::bind( &ipc::parameters::edit_partial_cast<weights_mean_t, ParamLayerId, FunBatchNorm, 0>, ipcShmemParameters );

    static constexpr std::size_t ByteShift = sizeof(weights_mean_t);

    m_fetchEditStddevWeights = std::bind( &ipc::parameters::edit_partial_cast<weights_stddev_t, ParamLayerId, FunBatchNorm, ByteShift>, ipcShmemParameters );

  }


  void update_weights( const bw_activations_t& bwActivations, const fw_errors_t& fwErrors ) noexcept {

    ensure( bwActivations.get_batch_size() == fwErrors.get_batch_size(), "Mismatch in batch sizes" );

    const auto batchSize = fwErrors.get_batch_size();


    // 1. Compute gradients
    auto& gradientMean = m_adamGradientMean.edit_gradient();
    auto& gradientStddev = m_adamGradientStddev.edit_gradient();

    gradientMean.fill(0);
    gradientStddev.fill(0);

    for (auto s = 0u; s < batchSize; s++) {

      const auto& perSampleFwErrors = fwErrors.get_values(s);
      const auto& perSampleBwActiv = bwActivations.get_values(s);

      for (auto j = 0u; j < NeuronCount; j++) {
        gradientMean[j] += perSampleFwErrors[j];
        gradientStddev[j] += perSampleFwErrors[j] * perSampleBwActiv[j];
      }
    }

    // 2. Correct gradients with ADAM algorithm
    m_adamGradientMean.correct_gradient();
    m_adamGradientStddev.correct_gradient();

    // 3. Update weights
    auto& meanWeights = m_fetchEditMeanWeights();
    auto& stddevWeights = m_fetchEditStddevWeights();

    if (batchSize == 1) {
      // UPDATE THE BETAS ONLY IF BATCHSIZE == 1
      for (auto j = 0u; j < NeuronCount; j++) {
        meanWeights[j] += m_learnRate * gradientMean[j];
      }
      return;
    }

    // IF BATCHSIZE > 1:

    for (auto j = 0u; j < NeuronCount; j++) {
      meanWeights[j] += m_learnRate * gradientMean[j];
      stddevWeights[j] += m_learnRate * gradientStddev[j];
    }
  }


  void set_errors( const bw_activations_t& bwActivations, const fw_errors_t& fwErrors ) noexcept {

    const auto batchSize = fwErrors.get_batch_size();

    instr::trace<instr::event::training::set_errors>("BatchNorm", "batchSize", fwErrors.get_batch_size());

    // bwActivations not used, but check this
    ensure( bwActivations.get_batch_size() == batchSize, "Mismatch in batch sizes" );

    // const auto& meanWeights = m_fetchEditMeanWeights(); not needed
    const auto& stddevWeights = m_fetchEditStddevWeights();

    m_errors.resize( batchSize );

    if (batchSize == 1) {
      // PASS THROUGH ERRORS IF BATCHSIZE == 1
      for (auto j = 0u; j < NeuronCount; j++) {
        m_errors.edit_values(0)[j] = fwErrors.get_values(0)[j];
      }

      instr::trace<instr::event::ann_prop::backward>( "set-errors",0, "bwErrors", m_errors.get_values(0), "batch-norm", "fwErrors", fwErrors.get_values(0) );
      return;
    }

    for (auto s = 0u; s < batchSize; s++) {

      auto& perSampleBwErrors = m_errors.edit_values(s);
      const auto& perSampleFwErrors = fwErrors.get_values(s);

      for (auto j = 0u; j < NeuronCount; j++) {
        perSampleBwErrors[j] = perSampleFwErrors[j] * stddevWeights[j];
        // Error propagation does not depend on meanWeights bc derivative wrt bwActiv does not depend on meanWeights
      }

      instr::trace<instr::event::ann_prop::backward>( "set-errors",0, "bwErrors", m_errors.get_values(s), "batch-norm", "fwErrors", fwErrors.get_values(s) );
    }

  }



  const errors_t& get_errors() const noexcept {
    return m_errors;
  }


  // Expose for initialization
  weights_mean_t& edit_ipc_parameters_mean() noexcept {
    return m_fetchEditMeanWeights();
  }

  weights_stddev_t& edit_ipc_parameters_stddev() noexcept {
    return m_fetchEditStddevWeights();
  }

};


} // namespace learn::approx::ann {



export module SteelRT.Learn.Approx.NeuralNet.Layer.SampleNorm;


import SteelRT.Learn.Approx.NeuralNet.Layer.Values;

import SteelRT.Learn.IPC;


import SteelRT.Util.Types;
import SteelRT.Util.Require;
import SteelRT.Learn.Types;

// TMP XXX
import SteelRT.Instrument;
import SteelRT.Instrument.Predicates;


import SteelRT.Util.Assert;
#include "assert.hpp"

import <cmath>;


namespace learn::approx::ann {


//// Forward propagation (for runner --> single )
export
template < learn::fun FunSampleNorm, std::size_t NeuronCount >
class layer<
  ann::propagate::fwd, ann::width::single, FunSampleNorm, NeuronCount, NeuronCount,
  util::req_t< util::same<FunSampleNorm, learn::fun::sample_norm> >
>
{
protected:

  using activations_t = values< ann::width::single, array_t<NeuronCount> >;

  activations_t m_activations;

  // NOTE: emavg : "exponentially moving averages"
  // NOTE: varfactor is 1 / sqrt( stddev^2 + epsilon )

  using emavg_mean_t = array_t<NeuronCount>;
  using emavg_varfactor_t = array_t<NeuronCount>;

  std::function< const emavg_mean_t&() > m_fetchConstMeanParameters = nullptr;
  std::function< const emavg_varfactor_t&() > m_fetchConstVarfactorParameters = nullptr;

protected:

  uint_t m_layerId = 0; // NOTE: Just for debugging purposes

public:

  static constexpr learn::fun layer_function = learn::fun::sample_norm;

  static constexpr std::size_t bytes_count = sizeof(emavg_mean_t) + sizeof(emavg_varfactor_t);

  static constexpr std::size_t neuron_count = NeuronCount;

public:

  template <std::size_t ParamLayerId>
  void bind_shared_weights( const ipc::parameters * ipcShmemParameters ) {

    m_layerId = ParamLayerId;  // NOTE: Just for debugging purposes

    ensure(m_fetchConstMeanParameters == nullptr, "Bind parameters can only be initialized once");
    ensure(m_fetchConstVarfactorParameters == nullptr, "Bind parameters can only be initialized once");

    m_fetchConstMeanParameters = std::bind( &ipc::parameters::get_partial_cast<emavg_mean_t, ParamLayerId, FunSampleNorm, 0>, ipcShmemParameters );

    static constexpr std::size_t ByteShift = sizeof(emavg_mean_t);

    m_fetchConstVarfactorParameters = std::bind( &ipc::parameters::get_partial_cast<emavg_varfactor_t, ParamLayerId, FunSampleNorm, ByteShift>, ipcShmemParameters );

  }


  void set_activations( const activations_t& bwActivations ) noexcept {

    const auto& emavgMeans = m_fetchConstMeanParameters();
    const auto& emavgVarianceFactors = m_fetchConstVarfactorParameters();

    for (auto j = 0u; j < NeuronCount; j++) {
      m_activations[j] = (bwActivations[j] - emavgMeans[j]) * emavgVarianceFactors[j];
    }
  }


  const activations_t& get_activations() const noexcept {
    return m_activations;
  }

  // method to set/get parameters from the ann. Not needed in principle

};


//// Forward propagation (WIDTH BATCH)
export
template < learn::fun FunSampleNorm, std::size_t NeuronCount >
class layer<
  ann::propagate::fwd, ann::width::batch, FunSampleNorm, NeuronCount, NeuronCount,
  util::req_t< util::same<FunSampleNorm, learn::fun::sample_norm> >
>
{
private:


  using activations_t = values< ann::width::batch, array_t<NeuronCount> >;

  activations_t m_activations;




  const fp_t m_epsilon = 1e-8;

protected:

  using emavg_mean_t = array_t<NeuronCount>;
  using emavg_varfactor_t = array_t<NeuronCount>;

  // width::single values always, even though this is a fwd prop on a batch
  array_t< NeuronCount > m_sampledMeans;
  array_t< NeuronCount > m_sampledVarfactors; // 1/sqrt(sigma^2 + epsilon)

  array_t< NeuronCount > m_meanShift; // Auxiliary for backprop

protected:

  uint_t m_layerId = 0; // NOTE: Just for debugging purposes

public:

  static constexpr learn::fun layer_function = learn::fun::sample_norm;

  static constexpr std::size_t bytes_count = sizeof(emavg_mean_t) + sizeof(emavg_varfactor_t);

  static constexpr std::size_t neuron_count = NeuronCount;

public:


  void set_activations( const activations_t& bwActivations ) noexcept {


    ensure( bwActivations.get_batch_size() > 0, "Unexpected batch : Zero samples" );

    const auto batchSize = bwActivations.get_batch_size();

    instr::trace<instr::event::training::set_activations>("SampleNorm", "batchSize", batchSize);

    m_activations.resize( batchSize );

    // PASS THROUGH IF BATCHSIZE == 1 (as if sampled means = 0 and sampled varfactors = 1)
    if (batchSize == 1) {
      m_activations.edit_values(0) = bwActivations.get_values(0);

      instr::trace<instr::event::learn_monitor::parameters>( "SNLayerId", m_layerId, "WeightsMean", m_sampledMeans, "WeightsVarfactor", m_sampledVarfactors );
      return;
    }

    // -------- Compute sampled averages
    m_sampledMeans.fill(0);
    for (auto s = 0u; s < batchSize; s++) {

      const auto& perSampleBwActivations = bwActivations.get_values(s);

      // instr::trace<instr::event::debug::sample>( "BwActiv", s, " ::: ", perSampleBwActivations );

      for (auto j = 0u; j < NeuronCount; j++) {
        m_sampledMeans[j] += perSampleBwActivations[j];
      }
    }

    for (auto j = 0u; j < NeuronCount; j++) {
      m_sampledMeans[j] /= batchSize;
    }

    instr::trace<instr::event::debug::result>( "m_sampledMeans ::: ", m_sampledMeans );


    // -------- Compute sampled inverse stddevs
    m_sampledVarfactors.fill(0);
    m_meanShift.fill(0);
    for (auto s = 0u; s < batchSize; s++) {

      const auto& perSampleBwActivations = bwActivations.get_values(s);

      for (auto j = 0u; j < NeuronCount; j++) {
        auto diff = perSampleBwActivations[j] - m_sampledMeans[j];

        m_sampledVarfactors[j] += diff*diff;

        m_meanShift[j] += diff;
      }
    }

    for (auto j = 0u; j < NeuronCount; j++) {
      // if (m_sampledVarFactors[j] < 1e-5 ) {
      //   m_sampledVarfactors[j] = 1;
      // } else {
      m_sampledVarfactors[j] = 1.f / (std::sqrtf( m_sampledVarfactors[j] / batchSize ) + m_epsilon);
      // }

      m_meanShift[j] /= batchSize;

    }

    instr::trace<instr::event::debug::result>( "m_sampledVarfactors ::: ", m_sampledVarfactors );
    instr::trace<instr::event::debug::result>( "m_meanShift ::: ", m_meanShift );


    // Normalize activations
    for (auto s = 0u; s < batchSize; s++) {

      auto& perSampleFwActivations = m_activations.edit_values(s);
      const auto& perSampleBwActivations = bwActivations.get_values(s);

      for (auto j = 0u; j < NeuronCount; j++) {
        perSampleFwActivations[j] = ( perSampleBwActivations[j] - m_sampledMeans[j] ) * m_sampledVarfactors[j];
      }

      instr::trace<instr::event::ann_prop::forward>( "sample", s, "bwActiv", perSampleBwActivations, "fwActiv", perSampleFwActivations );
      // instr::trace<instr::event::debug::result>( "FwActiv", s, " ::: ", perSampleFwActivations );
    }

    instr::trace<instr::event::learn_monitor::parameters>( "SNLayerId", m_layerId, "WeightsMean", m_sampledMeans, "WeightsVarfactor", m_sampledVarfactors );
  }


  const activations_t& get_activations() const noexcept {
    return m_activations;
  }


  // No need
  // const emavg_mean_t& get_ipc_parameters_mean() const noexcept {
  //   return m_fetchEditMeanWeights();
  // }

  // const emavg_varfactor_t& get_ipc_parameters_varfactor() const noexcept {
  //   return m_fetchEditStddevWeights();
  // }

};


//// Backward propagation (WIDTH BATCH)
export
template < learn::fun FunSampleNorm, std::size_t NeuronCount >
class layer<
  ann::propagate::bwd, ann::width::batch, FunSampleNorm, NeuronCount, NeuronCount,
  util::req_t< util::same<FunSampleNorm, learn::fun::sample_norm> >
>
: public layer< ann::propagate::fwd, ann::width::batch, FunSampleNorm, NeuronCount, NeuronCount >
{
private:

  using emavg_mean_t = array_t<NeuronCount>;
  using emavg_varfactor_t = array_t<NeuronCount>;

  fp_t m_decayFactor = 0;
  fp_t m_oneMinusDecayFactor = 0;
  uint_t m_step = 0;

  std::function< emavg_mean_t&() > m_fetchEditMeanParameters = nullptr;
  std::function< emavg_varfactor_t&() > m_fetchEditVarfactorParameters = nullptr;

  using super_fwd_layer = layer< ann::propagate::fwd, ann::width::batch, FunSampleNorm, NeuronCount, NeuronCount >;

  using bw_activations_t = values< ann::width::batch, array_t<NeuronCount> >;

  using fw_errors_t = values< ann::width::batch, array_t<NeuronCount> >;

  using errors_t = values< ann::width::batch, array_t<NeuronCount> >;

  errors_t m_errors;

public:

  static constexpr std::size_t neuron_count = super_fwd_layer::neuron_count;

public:


  template <std::size_t ParamLayerId>
  void bind_shared_weights( ipc::parameters * ipcShmemParameters ) {

    super_fwd_layer::m_layerId = ParamLayerId;  // NOTE: Just for debugging purposes

    ensure(m_fetchEditMeanParameters == nullptr, "Bind parameters can only be initialized once");
    ensure(m_fetchEditVarfactorParameters == nullptr, "Bind parameters can only be initialized once");

    m_fetchEditMeanParameters = std::bind( &ipc::parameters::edit_partial_cast<emavg_mean_t, ParamLayerId, FunSampleNorm, 0>, ipcShmemParameters );

    static constexpr std::size_t ByteShift = sizeof(emavg_mean_t);

    m_fetchEditVarfactorParameters = std::bind( &ipc::parameters::edit_partial_cast<emavg_varfactor_t, ParamLayerId, FunSampleNorm, ByteShift>, ipcShmemParameters );

  }


  void set_parameters( fp_t decayFactor ) noexcept {
    m_decayFactor = decayFactor;
    m_oneMinusDecayFactor = 1.f - decayFactor;
  }


  // No weights to update, but here we update the exponentially moving averages of means and varfactors.
  // We put arguments here, even though they are not needed, because we need to respect the update_weights argument default interface (required for batch_norm and matrix layers), so that full backward propagation can benefit from static layer polymorphism across all layers.

  void update_weights( const bw_activations_t& , const fw_errors_t& fwErrors ) noexcept {

    ensure(m_decayFactor != 0, "Uninitialized decay factor");
    ensure(m_oneMinusDecayFactor != 0, "Uninitialized decay factor");

    // PASS THROUGH IF BATCHSIZE == 1
    if (fwErrors.get_batch_size() == 1) {
      // Do nothing
      return;
    }

    auto& emavgMeans = m_fetchEditMeanParameters();
    auto& emavgVarfactors = m_fetchEditVarfactorParameters();

    if (m_step > 0) {

      for (auto j = 0u; j < NeuronCount; j++) {
        emavgMeans[j] = m_decayFactor * emavgMeans[j] + m_oneMinusDecayFactor * super_fwd_layer::m_sampledMeans[j];
        emavgVarfactors[j] = m_decayFactor * emavgVarfactors[j] + m_oneMinusDecayFactor * super_fwd_layer::m_sampledVarfactors[j];
      }

    } else {

      // First step, just copy the arrays
      emavgMeans = super_fwd_layer::m_sampledMeans;
      emavgVarfactors = super_fwd_layer::m_sampledVarfactors;
    }

    m_step++;
  }

private:


  array_t<NeuronCount> m_meanErr;
  array_t<NeuronCount> m_varianceErr;
  array_t<NeuronCount> m_meanDiff;

public:

  void set_errors( const bw_activations_t& bwActivations, const fw_errors_t& fwErrors ) noexcept {

    const auto batchSize = fwErrors.get_batch_size();

    instr::trace<instr::event::training::set_errors>("SampleNorm", "batchSize", batchSize);

    ensure( bwActivations.get_batch_size() == batchSize, "Mismatch in batch sizes" );

    m_errors.resize( batchSize );

    // PASS THROUGH IF BATCHSIZE == 1
    if (batchSize == 1) {
      m_errors.edit_values(0) = fwErrors.get_values(0);

      instr::trace<instr::event::ann_prop::backward>( "set-errors",0, "bwErrors", m_errors.get_values(0), "sample-norm", "fwErrors", fwErrors.get_values(0) );
      return;
    }

    const auto& emavgMeans = super_fwd_layer::m_sampledMeans;
    const auto& emavgVarfactors = super_fwd_layer::m_sampledVarfactors;

    const fp_t invBatchSize = 1.f / batchSize;

    // ================ Compute m_varianceErr and m_meanDiff
    m_varianceErr.fill(0);
    m_meanDiff.fill(0);
    for (auto s = 0u; s < batchSize; s++) {

      const auto& fwErrorsThis = fwErrors.get_values(s);
      const auto& bwActivThis = bwActivations.get_values(s);

      for (auto j = 0u; j < NeuronCount; j++) {
        m_varianceErr[j] += (bwActivThis[j] - emavgMeans[j]) * fwErrorsThis[j];

        m_meanDiff[j] += bwActivThis[j] - emavgMeans[j];
      }
    }

    for (auto j = 0u; j < NeuronCount; j++) {
      auto invStddevCube = emavgVarfactors[j] * emavgVarfactors[j] * emavgVarfactors[j];
      m_varianceErr[j] *= invStddevCube * (-0.5f);

      m_meanDiff[j] *= invBatchSize;
    }


    // ================ Compute m_meanErr
    m_meanErr.fill(0);
    for (auto s = 0u; s < batchSize; s++) {

      const auto& fwErrorsThis = fwErrors.get_values(s);
      for (auto j = 0u; j < NeuronCount; j++) {

        m_meanErr[j] += fwErrorsThis[j] * emavgVarfactors[j] * (-1);
      }
    }

    for (auto j = 0u; j < NeuronCount; j++) {
      m_meanErr[j] += m_varianceErr[j] * (-2) * m_meanDiff[j];
    }


    // ================ Final setting
    for (auto s = 0u; s < batchSize; s++) {

      const auto& fwErrorsThis = fwErrors.get_values(s);
      auto& bwErrorsThis = m_errors.edit_values(s);
      const auto& bwActivThis = bwActivations.get_values(s);

      for (auto j = 0u; j < NeuronCount; j++) {

        bwErrorsThis[j] = fwErrorsThis[j] * emavgVarfactors[j] +
                          m_meanErr[j] * invBatchSize +
                          m_varianceErr[j] * 2 * invBatchSize * ( bwActivThis[j] - emavgMeans[j] );
      }
      instr::trace<instr::event::ann_prop::backward>( "set-errors",0, "bwErrors", m_errors.get_values(s), "sample-norm", "fwErrors", fwErrors.get_values(s) );
    }
  }


  // array_t<NeuronCount> m_varianceErr;
  // array_t<NeuronCount> m_meanErr;

  // void set_errors( const bw_activations_t& bwActivations, const fw_errors_t& fwErrors ) noexcept {

  //   const auto batchSize = fwErrors.get_batch_size();

  //   instr::trace<instr::event::training::set_errors>("SampleNorm", "batchSize", batchSize);

  //   ensure( bwActivations.get_batch_size() == batchSize, "Mismatch in batch sizes" );

  //   // instr::trace<instr::event::debug::set_err>("BatchSize", bwActivations.get_batch_size() );

  //   m_errors.resize( batchSize );

  //   // array_t<NeuronCount> m_varianceErr;
  //   m_varianceErr.fill(0);

  //   // instr::trace<instr::event::debug::cache>( "m_sampledVarFactors ::: ", super_fwd_layer::m_sampledVarfactors );

  //   // Compute numerator err and variance err
  //   for (auto s = 0u; s < batchSize; s++) {

  //     auto& bwErrorsPerSample = m_errors.edit_values(s);
  //     const auto& fwErrorsPerSample = fwErrors.get_values(s);

  //     // instr::trace<instr::event::debug::sample>( "FwErr", s, " ::: ", fwErrors.get_values(s) );

  //     for (auto j = 0u; j < NeuronCount; j++) {

  //       auto invStddev = super_fwd_layer::m_sampledVarfactors[ j ];

  //       bwErrorsPerSample[ j ] = fwErrorsPerSample[ j ] * invStddev;

  //       m_varianceErr[j] += fwErrorsPerSample[ j ] * ( -0.5f * invStddev * invStddev * invStddev );
  //     }
  //   }

  //   // instr::trace<instr::event::debug::cache>( "m_meanShift ::: ", super_fwd_layer::m_meanShift );

  //   // Compute mean err
  //   m_meanErr.fill(0);
  //   for (auto s = 0u; s < batchSize; s++) {

  //     const auto& bwErrorsPerSample = m_errors.get_values(s);

  //     for (auto j = 0u; j < NeuronCount; j++) {
  //       m_meanErr[j] += m_varianceErr[ j ] * ( -2 * super_fwd_layer::m_meanShift[j] ) - bwErrorsPerSample[j];
  //     }
  //   }

  //   for (auto s = 0u; s < batchSize; s++) {

  //     auto& bwErrorsPerSample = m_errors.edit_values(s);

  //     const auto& bwActivPerSample = bwActivations.get_values(s);

  //     // instr::trace<instr::event::debug::sample>( "BwActiv", s, " ::: ", bwActivPerSample );

  //     for (auto j = 0u; j < NeuronCount; j++) {

  //       bwErrorsPerSample[j] += m_meanErr[j] / batchSize + m_varianceErr[j] * 2 * bwActivPerSample[j];// CORRECT XXX
  //     }

  //     instr::trace<instr::event::ann_prop::backward>( "sample", s, "bwErrors", bwErrorsPerSample, "fwErrors", fwErrors.get_values(s),"bwActiv", bwActivPerSample );

  //     // instr::trace<instr::event::debug::result>( "BwErr", s, " ::: ", bwErrorsPerSample );
  //   }


  // }


  const errors_t& get_errors() const noexcept {
    return m_errors;
  }


  // Expose for initialization
  emavg_mean_t& edit_ipc_parameters_mean() noexcept {
    return m_fetchEditMeanParameters();
  }

  emavg_varfactor_t& edit_ipc_parameters_varfactor() noexcept {
    return m_fetchEditVarfactorParameters();
  }

};


} // namespace learn::approx::ann


export module SteelRT.Learn.Approx.NeuralNet.Layer.Matrix;

  export import SteelRT.Learn.Approx.Operations.Weights.Forward;

import SteelRT.Learn.Approx.NeuralNet.Layer.Adam;
import SteelRT.Learn.Approx.NeuralNet.Layer.Values;

import SteelRT.Learn.IPC;


import SteelRT.Util.Types;
import SteelRT.Util.Require;
import SteelRT.Learn.Types;


import SteelRT.Instrument;
import SteelRT.Instrument.Predicates;


import SteelRT.Util.Assert;
#include "assert.hpp"


namespace learn::approx::ann {

  // function type-dispatch not put in weights_fwd because it is not aware of what ann::single/batch values are
  template <
    typename ValuesOutT, typename MatrixWeightsT, typename ValuesInT,
    util::req_t<
      std::conjunction<
        std::negation<ann::is_batch_values<ValuesOutT>>,
        std::negation<ann::is_batch_values<ValuesInT>>,
        std::negation<ann::is_single_values<ValuesInT>>
      >
    > ...
  >
  static void set_values_activations( ValuesOutT& outValues, const MatrixWeightsT& matrixWeights, const ValuesInT& inValues ) noexcept {
  
    op::activate( outValues, matrixWeights, inValues );

    if constexpr (is_single_values<ValuesOutT>::value) {
      instr::trace<instr::event::ann_prop::forward>( "input, non-numeric", "function, matrix", "output", outValues.get_values() );
    } else {
      instr::trace<instr::event::ann_prop::forward>( "input", inValues, "function, matrix", "output", outValues );
    }
  }


  template <
    typename ValuesOutT, typename MatrixWeightsT, typename ValuesInT,
    util::req_t<
      std::conjunction<
        std::negation<ann::is_batch_values<ValuesOutT>>,
        ann::is_single_values<ValuesInT>
      >
    > ...
  >
  static void set_values_activations( ValuesOutT& outValues, const MatrixWeightsT& matrixWeights, const ValuesInT& inValues ) noexcept {
  
    op::activate( outValues, matrixWeights, inValues.get_values() );

    if constexpr (is_single_values<ValuesOutT>::value) {
      instr::trace<instr::event::ann_prop::forward>( "input", inValues.get_values(), "function, matrix", "output", outValues.get_values() );
    } else {
      instr::trace<instr::event::ann_prop::forward>( "input", inValues.get_values(), "function, matrix", "output", outValues );
    }
  }
  
  
  template <
    typename ValuesOutT, typename MatrixWeightsT, typename ValuesInT,
    util::req_t<
      std::conjunction<
        ann::is_batch_values<ValuesOutT>,
        ann::is_batch_values<ValuesInT>
      >
    > ...
  >
  static void set_values_activations( ValuesOutT& outValues, const MatrixWeightsT& matrixWeights, const ValuesInT& inValues ) noexcept {
  
    outValues.resize( inValues.get_batch_size() );
  
    for (auto s = 0; s < inValues.get_batch_size(); s++) {
  
      set_values_activations( outValues.edit_values(s), matrixWeights, inValues.get_values(s) );
    }
  }


// --- Partial specialization for matrices: Layer mapping array_t<X> --> array_t<Y>
export
template <ann::width Width, learn::fun FunMatrix, std::size_t BwNeuronCount, std::size_t FwNeuronCount>
class layer<
  ann::propagate::fwd, Width, FunMatrix, BwNeuronCount, FwNeuronCount,
  util::req_t<
    util::same<FunMatrix, learn::fun::matrix>
  >
>
{
protected:

  using fw_activations_t = values< Width, array_t<FwNeuronCount> >;

  fw_activations_t m_activations;


  using weights_matrix_t = matrix_net_t<BwNeuronCount, FwNeuronCount>;


  std::function< const weights_matrix_t&() > m_fetchConstWeights = nullptr;

  uint_t m_layerId = 0; // NOTE: Just for debugging purposes

public:

  static constexpr learn::fun layer_function = learn::fun::matrix;

  static constexpr std::size_t bytes_count = sizeof(weights_matrix_t);

  static constexpr std::size_t bw_neuron_count = BwNeuronCount;
  static constexpr std::size_t fw_neuron_count = FwNeuronCount;

public:

  template <std::size_t ParamLayerId>
  void bind_shared_weights( const ipc::parameters * ipcShmemParameters ) {

    m_layerId = ParamLayerId;  // NOTE: Just for debugging purposes

    ensure(m_fetchConstWeights == nullptr, "Bind parameters can only be initialized once");

    m_fetchConstWeights = std::bind( &ipc::parameters::get_cast<weights_matrix_t, ParamLayerId, FunMatrix>, ipcShmemParameters );
  }


  template <typename BwActivationsT>
  void set_activations( const BwActivationsT& bwActivations ) noexcept {

    if constexpr (Width == ann::width::batch) {
      instr::trace<instr::event::training::set_activations>("Matrix", "batchSize", bwActivations.get_batch_size());

      const auto& ws = m_fetchConstWeights();
      instr::trace<instr::event::learn_monitor::parameters>( "MLayerId", m_layerId, "Weights", ws );
    }
      
    // activ_j =  * w_ji bwActiv_ik
    set_values_activations( m_activations, m_fetchConstWeights(), bwActivations );
  }

  
  const fw_activations_t& get_activations() const noexcept {
    return m_activations;
  }

};


  template <std::size_t BwN, std::size_t FwN>
  static void set_batch_errors( values<ann::width::batch, array_t<BwN>>& bwErrors, const values<ann::width::batch, array_t<FwN>>& fwErrors, const matrix_net_t<BwN, FwN>& matrixWeights ) {
  
    const auto batchSize = fwErrors.get_batch_size();
  
    bwErrors.resize(batchSize);  
  
    for (auto s = 0u; s < batchSize; s++) {
  
      auto& perSampleBwErrors = bwErrors.edit_values(s);
      const auto& perSampleFwErrors = fwErrors.get_values(s);
  
      for (auto b = 0u; b < BwN; b++) {
  
        fp_t cum = 0.f;
        for (auto f = 0u; f < FwN; f++) {
          cum += matrixWeights[f][b] * perSampleFwErrors[f];
        }
        perSampleBwErrors[b] += cum;
  
      }

      instr::trace<instr::event::ann_prop::backward>( "set-errors",s, "bwErrors", bwErrors.get_values(s), "matrix", matrixWeights, "fwErrors", fwErrors.get_values(s) );
    }
  }
  
  
  template <std::size_t BwN, std::size_t FwN>
  static void set_gradient( array_t<BwN * FwN>& outGradient, const values<ann::width::batch, array_t<BwN>>& bwActivations, const values<ann::width::batch, array_t<FwN>>& fwErrors ) {
  
    ensure(fwErrors.get_batch_size() == bwActivations.get_batch_size(), "Mismatch in batch sizes");
  
    outGradient.fill(0);
  
    const auto batchSize = fwErrors.get_batch_size();
  
    for (auto s = 0u; s < batchSize; s++) {
  
      const auto& perSampleBwActivations = bwActivations.get_values(s);
      const auto& perSampleFwErrors = fwErrors.get_values(s);
  
      for (auto f = 0u; f < FwN; f++) {
        for (auto b = 0u; b < BwN; b++) {
  
          outGradient[f*BwN * b] += perSampleBwActivations[b] * perSampleFwErrors[f];
        }
      }
      instr::trace<instr::event::ann_prop::backward>( "set-gradient",s, "fwErrors", fwErrors.get_values(s), "bwActivs", bwActivations.get_values(s) );
    }

    instr::trace<instr::event::ann_prop::backward>( "set-gradient-result", outGradient );
  }



export
template <ann::width Width, learn::fun FunMatrix, std::size_t BwNeuronCount, std::size_t FwNeuronCount>
class layer<
  ann::propagate::bwd, Width, FunMatrix, BwNeuronCount, FwNeuronCount,
  util::req_t<
    util::same<FunMatrix, learn::fun::matrix>
  >
>
: public layer< ann::propagate::fwd, Width, FunMatrix, BwNeuronCount, FwNeuronCount >
{
private:

  using super_fwd_layer = layer< ann::propagate::fwd, Width, FunMatrix, BwNeuronCount, FwNeuronCount >;


  using weights_matrix_t = typename super_fwd_layer::weights_matrix_t;

  std::function< weights_matrix_t&() > m_fetchEditWeights;

  weights_matrix_t m_gradient;

  weights_matrix_t m_adamCorrectMoment;
  weights_matrix_t m_adamCorrectSquare;

  using bw_activations_t = values< Width, array_t<BwNeuronCount> >;

  // using super_activation = typename super_fwd_layer::super_activation;
  using fw_errors_t = values< Width, array_t<FwNeuronCount> >;

  using errors_t =  values< Width, array_t<BwNeuronCount> >; // using super_error = error< BwNeuronCount >;

  errors_t m_errors;

  adam< BwNeuronCount * FwNeuronCount > m_adamGradient;

  fp_t m_regularization = 0; // Default: no regularization
  fp_t m_learnRate = 0;

  uint_t m_layerId = 0; // NOTE: Just for debugging purposes


public:

  void set_parameters( fp_t reg, fp_t lr, fp_t adamMoment, fp_t adamSquare ) noexcept {

    ensure( m_regularization == 0 and m_learnRate == 0, "Expected single initialization" );

    m_regularization = reg;
    m_learnRate = lr;

    m_adamGradient.set_parameters( adamMoment, adamSquare );
  }


  template <std::size_t ParamLayerId>
  void bind_shared_weights( ipc::parameters * ipcShmemParameters ) {

    super_fwd_layer::template bind_shared_weights<ParamLayerId>( ipcShmemParameters );

    ensure(m_fetchEditWeights == nullptr, "Bind parameters can only be initialized once");

    m_fetchEditWeights = std::bind( &ipc::parameters::edit_cast<weights_matrix_t, ParamLayerId, FunMatrix>, ipcShmemParameters );
  }


  void update_weights( const bw_activations_t& bwActivations, const fw_errors_t& fwErrors ) noexcept {

    // 1. Compute gradients
    set_gradient<BwNeuronCount, FwNeuronCount>( m_adamGradient.edit_gradient(), bwActivations, fwErrors );

    // 2. Correct gradients with ADAM algorithm
    m_adamGradient.correct_gradient();

    // 3. Update weights
    auto& weightsRef = m_fetchEditWeights();
    const auto& gradient = m_adamGradient.get_gradient();

    const auto invBatchSize = 1.f / fwErrors.get_batch_size();

    for (auto f = 0u; f < FwNeuronCount; f++) {
      for (auto b = 0u; b < BwNeuronCount; b++) {
        weightsRef[f][b] = (1 - m_learnRate * m_regularization * invBatchSize) * weightsRef[f][b] + m_learnRate * gradient[f*BwNeuronCount + b];
      }
    }
  }


  void set_errors( const bw_activations_t& bwActivations, const fw_errors_t& fwErrors ) noexcept {

    instr::trace<instr::event::training::set_errors>("Matrix", "batchSize", fwErrors.get_batch_size());

    // bwActivations not used

    set_batch_errors( m_errors, fwErrors, super_fwd_layer::m_fetchConstWeights() );
  }

  
  const errors_t& get_errors() const noexcept {
    return m_errors;
  }


  // Expose for initialization
  weights_matrix_t& edit_ipc_parameters() noexcept {
    return m_fetchEditWeights();
  }
};


} // namespace learn::approx::ann

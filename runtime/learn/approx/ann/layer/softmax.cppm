
export module SteelRT.Learn.Approx.NeuralNet.Layer.Softmax;

import SteelRT.Learn.Approx.NeuralNet.Layer.Values;

import SteelRT.Util.Types;
import SteelRT.Util.Tuple;
import SteelRT.Util.Require;

import SteelRT.Learn.Types;
import SteelRT.Learn.Approx.Operations.Scalar;

import SteelRT.Util.Assert;
#include "assert.hpp"

import SteelRT.Instrument;
import SteelRT.Instrument.Predicates;


namespace learn::approx::ann {


  template <typename SingleActivationsT>
  static void set_single_activations( SingleActivationsT& fwActivations, const SingleActivationsT& bwActivations ) noexcept {
  
    const auto activSize = bwActivations.size();
  
    // 1. Max shift to prevent overflow
    fp_t maxValue = std::numeric_limits<fp_t>::min();
    for (auto j = 0u; j < activSize; j++) {
      if (bwActivations[j] > maxValue) { maxValue = bwActivations[j]; }
    }
  
    for (auto j = 0u; j < activSize; j++) {
      fwActivations[j] = bwActivations[j] - maxValue;
    }
  
    // 2. Exponentiate
    op::apply_on<learn::fun::exp, op::eval::direct>( fwActivations, fwActivations );
  
    // 3. Normalize
    auto denValue = 0.f;
    for (auto j = 0u; j < activSize; j++) {
      denValue += fwActivations[j];
    }
  
    for (auto j = 0u; j < activSize; j++) {
      fwActivations[j] /= denValue;
    }
  }
  
  
  template <std::size_t N>
  static void set_single_errors( array_t<N>& singleErrors, const array_t<N>& singleActivations, uint_t chosenIndex, fp_t tdError ) noexcept {
      
    for (auto j = 0u; j < N; j++) {
      singleErrors[ j ] = - singleActivations[ j ];
    }
  
    singleErrors[ chosenIndex ] += 1.f;
  
    for (auto j = 0u; j < N; j++) {
      singleErrors[ j ] *= singleActivations[ j ] * tdError;
    }
  }



//// Forward propagation (SINGLE)
export
template <learn::fun FunSoftmax, std::size_t NeuronCount>
class layer<
  ann::propagate::fwd, ann::width::single, FunSoftmax, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunSoftmax, learn::fun::softmax>
  >
>
{
protected:

  using activations_t = values< ann::width::single, array_t<NeuronCount> >;

  activations_t m_activations;

public:

  static constexpr learn::fun layer_function = learn::fun::softmax;

  void set_activations( const activations_t& bwActivations) noexcept {

    set_single_activations( m_activations, bwActivations );
  }

  const activations_t& get_activations() const noexcept {
    return m_activations;
  }
};


// NOT USED
// //// Backward propagation (SINGLE)
// export
// template <learn::fun FunSoftmax, std::size_t NeuronCount>
// class layer<
//   ann::propagate::bwd, ann::width::single, FunSoftmax, NeuronCount, NeuronCount,
//   util::req_t<
//     util::same<FunSoftmax, learn::fun::softmax>
//   >
// >
// : public layer< ann::propagate::fwd, ann::width::single, FunSoftmax, NeuronCount, NeuronCount >,
// {
// private:
// 
//   using super_fwd_layer = layer< ann::propagate::fwd, ann::width::single, FunSoftmax, NeuronCount, NeuronCount >;
// 
//   using super_activation = typename super_fwd_layer::super_activation;
//  
//   using errors_t = values< ann::width::single, array_t<NeuronCount >; 
//   errors_t m_errors;
// 
//   using chosen_indices_t = values< ann::width::single, array_idx_t<1> >;
// 
// public:
// 
//   void set_errors( const chosen_indices_t& chosenIndices ) noexcept {
// 
//     set_single_errors<NeuronCount>( m_errors.edit_values(), super_fwd_layer::m_activations.get_values(), chosenIndex[0] );
// 
//   }
// };


//// Forward propagation (BATCH)
export
template <learn::fun FunSoftmax, std::size_t NeuronCount>
class layer<
  ann::propagate::fwd, ann::width::batch, FunSoftmax, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunSoftmax, learn::fun::softmax>
  >
>
{

protected:

  using activations_t = values< ann::width::batch, array_t<NeuronCount> >;

  activations_t m_activations;

public:

  static constexpr learn::fun layer_function = learn::fun::softmax;

  void set_activations( const activations_t& bwActivations) noexcept {

    const auto batchSize = bwActivations.get_batch_size();

    instr::trace<instr::event::training::set_activations>("Softmax", "batchSize", batchSize);

    m_activations.resize( batchSize );

    for (auto s = 0u; s < batchSize; s++) {

      instr::trace<instr::event::ann_prop::forward>( s, "input", bwActivations.get_values(s), "function, softmax", "output", m_activations.get_values(s) );

      set_single_activations( m_activations.edit_values(s), bwActivations.get_values(s) );
    }

  }

  const activations_t& get_activations() const noexcept {
    return m_activations;
  }
};


//// Backward propagation (BATCH)
export
template <learn::fun FunSoftmax, std::size_t NeuronCount>
class layer<
  ann::propagate::bwd, ann::width::batch, FunSoftmax, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunSoftmax, learn::fun::softmax>
  >
>
: public layer< ann::propagate::fwd, ann::width::batch, FunSoftmax, NeuronCount, NeuronCount >
{
private:

  using super_fwd_layer = layer< ann::propagate::fwd, ann::width::batch, FunSoftmax, NeuronCount, NeuronCount >;

 
  using errors_t = values< ann::width::batch, array_t<NeuronCount> >; 
  errors_t m_errors;

public:

  using chosen_indices_t = values< ann::width::batch, array_idx_t<1> >;


public:


  void set_errors( const ann::batch_errors_t& tdErrors, const chosen_indices_t& chosenIndices ) noexcept {

    ensure( tdErrors.get_batch_size() == chosenIndices.get_batch_size(), "Mismatch in batch sizes" );

    const auto batchSize = chosenIndices.get_batch_size();

    instr::trace<instr::event::training::set_errors>("Softmax", "batchSize", batchSize);

    m_errors.resize( batchSize );

    // TMP XXX DBG
    for (auto s = 0u; s < batchSize; s++) {

      set_single_errors<NeuronCount>( m_errors.edit_values(s), super_fwd_layer::m_activations.get_values(s), chosenIndices.get_values(s)[0], tdErrors.get_values(s)[0] );

      instr::trace<instr::event::ann_prop::backward>( s, "tdErrs", tdErrors.get_values(s), "function, softmax", "output", m_errors.get_values(s), chosenIndices.get_values(s)[0] );

      instr::trace<instr::event::learn_monitor::evo_softmax>( s, m_errors.get_values(s), super_fwd_layer::m_activations.get_values(s), chosenIndices.get_values(s)[0], tdErrors.get_values(s)[0] );
    }
  }


  const errors_t& get_errors() const noexcept {
    return m_errors;
  }
};



} // namespace learn::approx::ann

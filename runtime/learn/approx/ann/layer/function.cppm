
export module SteelRT.Learn.Approx.NeuralNet.Layer.Function;

import SteelRT.Learn.Approx.NeuralNet.Layer.Values;
import SteelRT.Learn.Approx.Operations.Scalar;

import SteelRT.Util.Types;
import SteelRT.Util.Require;

import SteelRT.Learn.Types;

import SteelRT.Util.Assert;
#include "assert.hpp"

import SteelRT.Instrument;
import SteelRT.Instrument.Predicates;

namespace learn::approx::ann {


  template <learn::fun Fun, op::eval OpEval, typename ValuesT,
    util::req_t< std::negation<is_batch_values<ValuesT>> > ...
  >
  static void apply_function( ValuesT& outValues, const ValuesT& inValues ) noexcept {
  
    op::apply_on<Fun, OpEval>( outValues, inValues );

    if constexpr (is_single_values<ValuesT>::value) {
      instr::trace<instr::event::ann_prop::apply_fun>( "input", inValues.get_values(), "function", (uint_t)Fun, "output", outValues.get_values() );
    } else {
      instr::trace<instr::event::ann_prop::apply_fun>( "input", inValues, "function", (uint_t)Fun, "output", outValues );
    }
  }
  
  template <learn::fun Fun, op::eval OpEval, typename ValuesT,
    util::req_t< is_batch_values<ValuesT> > ...
  >
  static void apply_function( ValuesT& outValues, const ValuesT& inValues ) noexcept {

    outValues.resize( inValues.get_batch_size() );
  
    for (auto s = 0u; s < inValues.get_batch_size(); s++) {
      apply_function<Fun, OpEval>( outValues.edit_values(s), inValues.get_values(s) );
    }
  }
  
  template <
    typename ValuesT,
    util::req_t< std::negation<is_batch_values<ValuesT>> > ...
  >
  static void point_product( ValuesT& outValues, const ValuesT& inValues ) noexcept {
  
    for (auto j = 0u; j < inValues.size(); j++) {
      outValues[j] *= inValues[j];
    }
  }
  
  
  template <
    typename ValuesT,
    util::req_t< is_batch_values<ValuesT> > ...
  >
  static void point_product( ValuesT& outValues, const ValuesT& inValues ) noexcept {

    // No need to resize, previously resized
  
    for (auto s = 0u; s < inValues.get_batch_size(); s++) {

      point_product( outValues.edit_values(s), inValues.get_values(s) );

      instr::trace<instr::event::ann_prop::backward>( "set-errors",s, "bwErrors", outValues.get_values(s), "Fun", "fwErrors", inValues.get_values(s) );
    }
  }



//// Forward propagation
export
template < ann::width Width, learn::fun Fun, std::size_t NeuronCount >
class layer<
  ann::propagate::fwd, Width, Fun, NeuronCount, NeuronCount,
  util::req_t<
    std::conjunction<
      util::not_same<Fun, learn::fun::matrix>,
      util::not_same<Fun, learn::fun::softmax>,
      util::not_same<Fun, learn::fun::sample_norm>,
      util::not_same<Fun, learn::fun::batch_norm>,
      util::not_same<Fun, learn::fun::bias>,
      util::not_same<Fun, learn::fun::encode>
    >
  >
>
{
protected:

  using activations_t = ann::values< Width, array_t<NeuronCount> >;

  activations_t m_activations;


public:

  static constexpr learn::fun layer_function = Fun; 


  void set_activations( const activations_t& bwActivations ) noexcept {

    if constexpr (Width == ann::width::batch) {
      instr::trace<instr::event::training::set_activations>("Function", (uint_t)Fun, "batchSize", bwActivations.get_batch_size());
    }

    apply_function< Fun, op::eval::direct >( m_activations, bwActivations );

  }

  const activations_t& get_activations() const noexcept {
    return m_activations;
  }

};


//// Backward propagation
export
template < ann::width Width, learn::fun Fun, std::size_t NeuronCount >
class layer<
  ann::propagate::bwd, Width, Fun, NeuronCount, NeuronCount,
  util::req_t<
    std::conjunction<
      util::not_same<Fun, learn::fun::matrix>,
      util::not_same<Fun, learn::fun::softmax>,
      util::not_same<Fun, learn::fun::sample_norm>,
      util::not_same<Fun, learn::fun::batch_norm>,
      util::not_same<Fun, learn::fun::bias>,
      util::not_same<Fun, learn::fun::encode>
    >
  >
>
: public layer< ann::propagate::fwd, Width, Fun, NeuronCount, NeuronCount >
{
private:

  using super_fwd_layer = layer< ann::propagate::fwd, Width, Fun, NeuronCount, NeuronCount >;

  using bw_activations_t = typename super_fwd_layer::activations_t;
  using errors_t =   values< Width, array_t<NeuronCount> >;
  using gradient_t = values< Width, array_t<NeuronCount> >;

  errors_t m_errors;
  gradient_t m_gradient;

public:

  void set_errors( const bw_activations_t& bwActivations, const errors_t& fwErrors ) noexcept {

    instr::trace<instr::event::training::set_errors>("Function", (uint_t)Fun, "batchSize", bwActivations.get_batch_size());

    if constexpr (Width == ann::width::batch) {
      ensure( bwActivations.get_batch_size() == fwErrors.get_batch_size(), "Mismatch in batch sizes" );
    }

    apply_function< Fun, op::eval::derivative >( m_errors, bwActivations );

    point_product( m_errors, fwErrors );

  }


  const errors_t& get_errors( ) const noexcept {
    return m_errors;
  }

};

} // namespace learn::approx::ann

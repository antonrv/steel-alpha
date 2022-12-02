

export module SteelRT.Learn.Approx.NeuralNet.Layer.Encode;

import SteelRT.Learn.Approx.NeuralNet.Layer.Values;
import SteelRT.Learn.Approx.Operations.Encode;

import SteelRT.Util.Types;
import SteelRT.Util.Require;

import SteelRT.Learn.Types;

// import SteelRT.Instrument;
// import SteelRT.Instrument.Predicates;


namespace learn::approx::ann {


// This layer is used to encode the structured info in feat::layer (holding an heterogeneous set of encoders) into a set of numeric activations
// Note that this layer is used in training only to be able to encode a batch of input states (ann::values< width::batch, array_t<N> )
// We could use this also in inference too (with width::single) but we instead directly compute the first layer matrix activations from the feat::layer, in order to avoid useless computations, since inference time (in runner) is critical.


//// Forward propagation
export
template < learn::fun FunEncode, std::size_t NeuronCount >
class layer<
  ann::propagate::fwd, ann::width::batch, FunEncode, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunEncode, learn::fun::encode>
  >
>
{
private:

  using activations_t = ann::values< ann::width::batch, array_t<NeuronCount> >;

  activations_t m_activations;

public:

  static constexpr learn::fun layer_function = FunEncode; 

  void prepare_batch( uint_t batchSize ) noexcept {

    m_activations.resize( batchSize );
  }


  template <typename InputLayerT>
  void encode_activations( const InputLayerT& bwActivations, uint_t sampleId ) noexcept {

    // instr::trace<instr::event::training::set_activations>("Encode", "sampleId", sampleId);

    op::encode( m_activations.edit_values(sampleId), bwActivations );
  }


  const activations_t& get_activations() const noexcept {
    return m_activations;
  }

};



// No need to implement anything, since this layer is meant to encode the first structured feat::layer, no error has to be calculated to propagate it forward.
// Note that the activations are used to calculate the error in the next matrix layer, but they are defined in the super type ( layer<fwd...> )
export
template < learn::fun FunEncode, std::size_t NeuronCount >
class layer<
  ann::propagate::bwd, ann::width::batch, FunEncode, NeuronCount, NeuronCount,
  util::req_t<
    util::same<FunEncode, learn::fun::encode>
  >
> : public layer< ann::propagate::fwd, ann::width::batch, FunEncode, NeuronCount, NeuronCount >
{};


} // namespace learn::approx::ann

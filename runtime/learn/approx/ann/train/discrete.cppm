
export module SteelRT.Learn.Approx.NeuralNet.Train.Discrete;

  export import SteelRT.Learn.Approx.NeuralNet.Training;


import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;

import SteelRT.Util.Assert;
#include "assert.hpp"

import SteelRT.Instrument;


namespace learn::approx::ann::train {


export
template <typename InputLayerT, std::size_t NHiddenLayers, std::size_t NHiddenNeurons, typename ActionSeqT>
class discrete : 
public 
  ann::training<
    InputLayerT,
    util::sequence::multi_cat_t<
      util::sequence::index_t<InputLayerT::need_weights>,
      util::sequence::make_copies_t<NHiddenLayers, util::sequence::index_t<NHiddenNeurons, NHiddenNeurons, NHiddenNeurons>>,
      util::sequence::index_t<ActionSeqT::size(), ActionSeqT::size(), ActionSeqT::size()>
    >,
    util::sequence::multi_cat_t<
      util::sequence::enum_t<learn::fun, learn::fun::encode>,
      util::sequence::make_copies_t<NHiddenLayers, util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::bias, learn::fun::relu>>,
      util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::bias, learn::fun::softmax>
    >
  >
{
private:

  using super_ann =
      ann::training<
        InputLayerT,
        util::sequence::multi_cat_t<
          util::sequence::index_t<InputLayerT::need_weights>,
          util::sequence::make_copies_t<NHiddenLayers, util::sequence::index_t<NHiddenNeurons, NHiddenNeurons, NHiddenNeurons>>,
          util::sequence::index_t<ActionSeqT::size(), ActionSeqT::size(), ActionSeqT::size()>
        >,
        util::sequence::multi_cat_t<
          util::sequence::enum_t<learn::fun, learn::fun::encode>,
          util::sequence::make_copies_t<NHiddenLayers, util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::bias, learn::fun::relu>>,
          util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::bias, learn::fun::softmax>
        >
      >;


  using input_state_type = typename InputLayerT::state_type;

public: // Types

  using input_layer_type = InputLayerT;


  using action_type = typename ActionSeqT::value_type;

public: // Methods


  discrete(const str_t& idStr, const learn::pilot::cfg& pilotCfg) :
    super_ann(idStr, pilotCfg)
  {}


  void update( const ann::batch_states_t<input_state_type>& inputStates, const ann::batch_errors_t& tdErrors, const ann::batch_actions_t<action_type>& chosenActions ) {

    // 1. Compute forward
    super_ann::compute_forward( inputStates );

    // 2. Compute backward
    const auto batchSize = inputStates.get_batch_size();

    ensure(batchSize == tdErrors.get_batch_size(), "Mismatch in batch size");
    ensure(batchSize == chosenActions.get_batch_size(), "Mismatch in batch size");


    auto& lastLayerSoftmaxRef = super_ann::get_last_layer_ref();

    using batch_chosen_indices = typename std::remove_reference_t<decltype(lastLayerSoftmaxRef)>::chosen_indices_t;

    batch_chosen_indices chosenIndices(batchSize);

    for (auto s = 0u; s < batchSize; s++) {

      chosenIndices.edit_values(s)[0] = util::sequence::get_index_rt< ActionSeqT >::from_value( chosenActions.get_values(s)[0] );

      // instr::trace<instr::event::learn_monitor::evolution>();
    }

    lastLayerSoftmaxRef.set_errors( tdErrors, chosenIndices );

    super_ann::compute_backward();
  }


  // For outputing the learn summary only
  const auto& get_activations( const ann::batch_states_t<input_state_type>& inputStates ) noexcept {

    // 1. Compute forward
    super_ann::compute_forward( inputStates );

    const auto& lastLayerSoftmaxRef = super_ann::get_last_layer_ref();

    return lastLayerSoftmaxRef.get_activations(); 
  }

};


} // namespace learn::approx::ann::train


export module SteelRT.Learn.Approx.NeuralNet.Train.StateValue;

  export import SteelRT.Learn.Approx.NeuralNet.Training;


import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;

import SteelRT.Instrument;


namespace learn::approx::ann::train {

export
template <typename InputLayerT, std::size_t NHiddenLayers, std::size_t NHiddenNeurons>
class state_value :
public
  ann::training<
    InputLayerT,
    util::sequence::multi_cat_t<
      util::sequence::index_t<InputLayerT::need_weights>,
      util::sequence::make_copies_t<NHiddenLayers, util::sequence::index_t<NHiddenNeurons, NHiddenNeurons, NHiddenNeurons>>,
      util::sequence::index_t<1, 1, 1> // Output is a single value
    >,
    util::sequence::multi_cat_t<
      util::sequence::enum_t<learn::fun, learn::fun::encode>,
      util::sequence::make_copies_t<NHiddenLayers, util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::bias, learn::fun::relu>>,
      util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::bias, learn::fun::relu>
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
          util::sequence::index_t<1, 1, 1> // Output is a single value
        >,
        util::sequence::multi_cat_t<
          util::sequence::enum_t<learn::fun, learn::fun::encode>,
          util::sequence::make_copies_t<NHiddenLayers, util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::bias, learn::fun::relu>>,
          util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::bias, learn::fun::relu>
        >
      >;

public:

  using input_layer_type = InputLayerT;

  using input_state_type = typename InputLayerT::state_type;

public:

  state_value(const str_t& idStr, const learn::pilot::cfg& pilotCfg ) :
    super_ann(idStr, pilotCfg)
  {}


  const ann::batch_state_values_t& get_values( const ann::batch_states_t<input_state_type>& inputStates ) {

    super_ann::compute_forward( inputStates );

    return super_ann::get_last_layer_ref().get_activations();
  }


  void update( const ann::batch_errors_t& tdErrors ) {

    // No need to call compute_forward again
    auto& lastLayerRef = super_ann::get_last_layer_ref();

    const auto& prelastLayerRef = super_ann::get_pre_last_layer_ref();

    lastLayerRef.set_errors( prelastLayerRef.get_activations(), tdErrors );

    // TMP XXX DBG
    for (auto s = 0u; s < tdErrors.get_batch_size(); s++) {
      instr::trace<instr::event::learn_monitor::evo_stateval>(s, lastLayerRef.get_activations().get_values(s)[0], tdErrors.get_values(s)[0] );
    }

    super_ann::compute_backward();
  }

};

} // namespace learn::approx::ann::train

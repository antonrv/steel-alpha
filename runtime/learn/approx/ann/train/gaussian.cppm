
export module SteelRT.Learn.Approx.NeuralNet.Train.Gaussian;

  export import SteelRT.Learn.Approx.NeuralNet.Training;

import SteelRT.Util.Types;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;



export
namespace learn::approx::ann {

template <typename InputLayerT, std::size_t NHiddenLayers, std::size_t NHiddenNeurons>
using training_single_sigmoid = training<
  InputLayerT,
  util::sequence::multi_cat_t<
    util::sequence::index_t<InputLayerT::need_weights>,
    util::sequence::make_copies_t<NHiddenLayers, util::sequence::index_t<NHiddenNeurons, NHiddenNeurons, NHiddenNeurons, NHiddenNeurons>>,
    util::sequence::index_t<1,1,1,1>
  >,
  util::sequence::multi_cat_t<
    util::sequence::enum_t<learn::fun, learn::fun::encode>,
    util::sequence::make_copies_t<NHiddenLayers, util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::sample_norm, learn::fun::batch_norm, learn::fun::relu>>,
    util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::sample_norm, learn::fun::batch_norm, learn::fun::sigmoid> // previously relu
  >
>;


// template <typename InputLayerT, std::size_t NHiddenLayers, std::size_t NHiddenNeurons>
// using training_stddev = training<
//   InputLayerT,
//   util::sequence::cat_t<
//     util::sequence::make_copies_t<NHiddenLayers, util::sequence::index_t<NHiddenNeurons, NHiddenNeurons>>,
//     util::sequence::index_t<1,1>
//   >,
//   util::sequence::cat_t<
//     util::sequence::make_copies_t<NHiddenLayers, util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::relu>>,
//     util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::sigmoid> // previously relu, exp
//   >
// >;

} // namespace learn::approx::ann

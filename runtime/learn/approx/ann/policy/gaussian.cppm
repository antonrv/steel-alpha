
export module SteelRT.Learn.Approx.NeuralNet.Policy.Gaussian;

  export import SteelRT.Learn.Approx.NeuralNet.Inference;

import SteelRT.Util.Types;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;



export
namespace learn::approx::ann {

template <std::size_t NUsers, typename InputLayerT, std::size_t NHiddenLayers, std::size_t NHiddenNeurons>
using inference_single_sigmoid = inference<
  NUsers, InputLayerT,
  util::sequence::cat_t<
      util::sequence::make_copies_t<NHiddenLayers, util::sequence::index_t<NHiddenNeurons, NHiddenNeurons, NHiddenNeurons, NHiddenNeurons>>,
    util::sequence::index_t<1,1,1,1>
  >,
  util::sequence::cat_t<
    util::sequence::make_copies_t<NHiddenLayers, util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::sample_norm, learn::fun::batch_norm, learn::fun::relu>>,
    util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::sample_norm, learn::fun::batch_norm, learn::fun::sigmoid> // previously relu
  >
>;


// template <std::size_t NUsers, typename InputLayerT, std::size_t NHiddenLayers, std::size_t NHiddenNeurons>
// using inference_stddev = inference<
//   NUsers, InputLayerT,
//   util::sequence::cat_t<
//     util::sequence::make_copies_t<NHiddenLayers, util::sequence::index_t<NHiddenNeurons, NHiddenNeurons>>,
//     util::sequence::index_t<1,1>
//   >,
//   util::sequence::cat_t<
//     util::sequence::make_copies_t<NHiddenLayers, util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::relu>>,
//     util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::sigmoid> // previously relu -> exp
//   >
// >;

} // namespace learn::approx::ann

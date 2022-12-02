

export module SteelRT.Learn.Approx.Operations.Weights.Forward;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;

import SteelRT.Learn.Feat.Layer;

import SteelRT.Instrument;


import SteelRT.Util.Assert;
#include "assert.hpp"


namespace learn::approx::op {


template <
  std::size_t WeightStartId,
  typename ArrayWeightsT, typename FeatIdxT,
  util::req_t< std::conjunction< is_fp_array<ArrayWeightsT>, is_index_array<FeatIdxT> > > ...
>
fp_t weight_features( const ArrayWeightsT& arrayWeights, const FeatIdxT activeTiles ) noexcept {

  fp_t ret = 0;
  for (auto a : activeTiles) {
    if (a != global::NoIndex) {

      ensure( WeightStartId + a < size_v<ArrayWeightsT>, "Array bound violation" );

      ret += arrayWeights[ WeightStartId + a ];
    }
  }
  return ret;
}

template <
  std::size_t WeightStartId,
  typename ArrayWeightsT, typename FeatValueT,
  util::req_t< std::conjunction< is_fp_array<ArrayWeightsT>, std::is_unsigned<FeatValueT> > > ...
>
fp_t weight_features( const ArrayWeightsT& arrayWeights, FeatValueT activeTile ) noexcept {

  ensure( WeightStartId + activeTile < size_v<ArrayWeightsT>, "Array bound violation" );

  return arrayWeights[ WeightStartId + activeTile ];
}


template <
  std::size_t WeightStartId,
  typename ArrayWeightsT, typename FeatValuesT,
  util::req_t< std::conjunction< is_fp_array<ArrayWeightsT>, is_fp_array<FeatValuesT> > > ...
>
fp_t weight_features( const ArrayWeightsT& arrayWeights, const FeatValuesT& featValues ) noexcept {

  fp_t ret = 0;
  for (auto i = 0; i < size_v<FeatValuesT>; i++) {
    ensure( WeightStartId + i < size_v<ArrayWeightsT>, "Array bound violation" );
    ret += arrayWeights[ WeightStartId + i ] * featValues[ i ];
  }
  return ret;
}


template <
  std::size_t WeightStartId,
  typename ArrayWeightsT, typename FeatValueT,
  util::req_t< std::conjunction< is_fp_array<ArrayWeightsT>, is_fp<FeatValueT> > > ...
>
fp_t weight_features( const ArrayWeightsT& arrayWeights, FeatValueT featValue ) noexcept {

  static_assert( WeightStartId < size_v<ArrayWeightsT> );

  return arrayWeights[ WeightStartId ] * featValue;
}





///////////////
//
// INTERFACE FOR INPUT LAYER
//
///////////////

  template <
    typename ArrayWeightsT, typename InputLayerT,
    std::size_t... EncoderIds, std::size_t... WeightStartIds
  >
  fp_t collapse_feat_layer( const ArrayWeightsT& arrayWeights, const InputLayerT& inputLayer, util::sequence::index_t<EncoderIds...>, util::sequence::index_t<WeightStartIds...> ) noexcept {
  
    return ( weight_features<WeightStartIds>( arrayWeights, inputLayer.template get_encoded_features<EncoderIds>() ) + ... );
  }


export
template <
  typename OutValuesT, typename MatrixWeightsT, typename InputLayerT,
  util::req_t<
    feat::is_layer<InputLayerT>
  > ...
>
void activate( OutValuesT& outValues, const MatrixWeightsT& matrixWeights, const InputLayerT& inputLayer ) noexcept {

  static_assert( rows_v<MatrixWeightsT> == OutValuesT::element_count );
  static_assert( cols_v<MatrixWeightsT> == InputLayerT::need_weights );

  using feat_encoder_ids = util::sequence::make_index_t< InputLayerT::count_encoders >;

  // instr::trace<instr::event::weights::matrix_fwd>( "input layer", matrixWeights );

  using weight_start_ids = typename InputLayerT::weight_starts;

  for (auto r = 0u; r < rows_v<MatrixWeightsT>; r++) {

    outValues[ r ] = collapse_feat_layer( matrixWeights[ r ], inputLayer, feat_encoder_ids{}, weight_start_ids{} );
  }
}


///////////////
//
// INTERFACE FOR MID/OUTPUT LAYERS
//
///////////////
export
template <
  typename OutValuesT, typename MatrixWeightsT, typename InValuesT,
  util::req_t<
    std::negation< feat::is_layer<InValuesT> >
  > ...
>
void activate( OutValuesT& outValues, const MatrixWeightsT& matrixWeights, const InValuesT& inValues ) noexcept {

  // static_assert( rows_v<MatrixWeightsT> == OutValuesT::element_count );
  static_assert( rows_v<MatrixWeightsT> == size_v<OutValuesT> );
  static_assert( cols_v<MatrixWeightsT> == size_v<InValuesT> );

  // instr::trace<instr::event::weights::matrix_fwd>( "mid layer", matrixWeights );

  for (auto r = 0u; r < rows_v<MatrixWeightsT>; r++) {

    outValues[ r ] = weight_features<0>( matrixWeights[ r ], inValues );
  }
}


} // namespace learn::approx::op

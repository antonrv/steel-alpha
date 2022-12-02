

export module SteelRT.Learn.Approx.Operations.Encode;

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
    typename NumericFeatsT, typename FeatIdxT,
    util::req_t< is_index_array<FeatIdxT> > ...
  >
  void numeric_features( NumericFeatsT& numFeats, const FeatIdxT& featIndices ) noexcept {

    for (auto featIdx : featIndices) {

      ensure( featIdx == global::NoIndex or (featIdx != global::NoIndex and WeightStartId + featIdx < size_v<NumericFeatsT>),
        "Array bound violation" );
  
      numFeats[ WeightStartId + featIdx ] = (featIdx != global::NoIndex) ? 1 : 0;
    }
  }


  template <
    std::size_t WeightStartId,
    typename NumericFeatsT, typename FeatIdxT,
    util::req_t< std::is_unsigned<FeatIdxT> > ...
  >
  void numeric_features( NumericFeatsT& numFeats, const FeatIdxT& featIdx ) noexcept {

    ensure( featIdx == global::NoIndex or (featIdx != global::NoIndex and WeightStartId + featIdx < size_v<NumericFeatsT>),
        "Array bound violation" );
  
    numFeats[ WeightStartId + featIdx ] = (featIdx != global::NoIndex) ? 1 : 0;
  }


  template <
    std::size_t WeightStartId,
    typename NumericFeatsT, typename FeatValuesT,
    util::req_t< is_fp_array<FeatValuesT> > ...
  >
  void numeric_features( NumericFeatsT& numFeats, const FeatValuesT& featValues ) noexcept {

    static_assert( size_v<FeatValuesT> <= size_v<NumericFeatsT> );

    for (auto i = 0; i < size_v<FeatValuesT>; i++) {

      ensure( WeightStartId + i < size_v<NumericFeatsT>, "Array bound violation in numeric_features" );
      numFeats[ WeightStartId + i ] = featValues[ i ];
    }
  }


  template <
    std::size_t WeightStartId,
    typename NumericFeatsT, typename FeatValueT,
    util::req_t< is_fp<FeatValueT> > ...
  >
  void numeric_features( NumericFeatsT& numFeats, FeatValueT featValue ) noexcept {

    static_assert( WeightStartId < size_v<NumericFeatsT> );

    numFeats[ WeightStartId ] = featValue;
  }


  template <
    typename InputLayerT,
    std::size_t... EncoderIds, std::size_t... WeightStartIds
  >
  void convert_to_numeric( array_t< InputLayerT::need_weights >& numFeats, const InputLayerT& inputLayer, util::sequence::index_t<EncoderIds...>, util::sequence::index_t<WeightStartIds...> ) noexcept {

    static_assert( InputLayerT::need_weights != 0 );

    ( numeric_features<WeightStartIds>( numFeats, inputLayer.template get_encoded_features<EncoderIds>() ), ... );
  }


///////////////
//
// INTERFACE (from input layer to single values)
//
///////////////
export
template <
  typename OutValuesT, typename InputLayerT,
  util::req_t<
    feat::is_layer<InputLayerT>
  > ...
>
void encode( OutValuesT& outValues, const InputLayerT& inputLayer ) {

  // static_assert( OutValuesT::element_count == InputLayerT::need_weights );
  static_assert( size_v<OutValuesT> == InputLayerT::need_weights );

  using feat_encoder_ids = util::sequence::make_index_t< InputLayerT::count_encoders >;

  using weight_start_ids = typename InputLayerT::weight_starts;

  convert_to_numeric( outValues, inputLayer, feat_encoder_ids{}, weight_start_ids{} );
}


} // namespace learn::approx::op

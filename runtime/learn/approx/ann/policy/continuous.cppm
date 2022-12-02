
export module SteelRT.Learn.Approx.NeuralNet.Policy.Continuous;

  export import SteelRT.Learn.Approx.NeuralNet.Policy.Gaussian;
  export import SteelRT.Learn.Approx.Sampler.Gaussian;


import SteelRT.Util.Types;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;


// import SteelRT.Instrument;

import SteelRT.Util.Assert;
#include "assert.hpp"

export import <algorithm>; // std::clamp / std::round


// A policy that uses a continuous action space to select a number in a range
// When clang allows c++20 template <float Value> we will be able to use this as a continuous policy (ie with ActionT = float)

namespace learn::approx::ann::policy {



export
template <std::size_t NUsers, typename InputLayerT, std::size_t NHiddenLayers, std::size_t NHiddenNeurons, typename ActionT, ActionT MinRange, ActionT MaxRange>
class continuous {

private:

  using inference_ann_t = inference_single_sigmoid< NUsers, InputLayerT, NHiddenLayers, NHiddenNeurons >;

  inference_ann_t m_annMean;
  inference_ann_t m_annStddev;


  static constexpr ActionT RangeSpan = MaxRange - MinRange;
  static constexpr ActionT HalfRangeSpan = (MaxRange - MinRange)/2;

  using action_type = ActionT;


  // ================ PER-USER SAMPLER
  // Samplers are aligned to cache line
  using gaussian_sampler_t = approx::sampler<approx::distribution::gaussian>;

  using own_gaussian_sampler_t = std::unique_ptr<gaussian_sampler_t>;

  using own_action_samplers_t = std::array< own_gaussian_sampler_t, NUsers >;

  own_action_samplers_t m_ownSamplers; // built with (0,1) params

private:


  template <std::size_t... Ids>
  void initialize_samplers( const learn::runner::cfg& runnerCfg, util::sequence::index_t<Ids...> ) {

    ( (m_ownSamplers[Ids] = std::make_unique<gaussian_sampler_t>( runnerCfg.seed, runnerCfg.seedValue )), ... );
  }


public:

  continuous( const str_t& idStr, const learn::runner::cfg& runnerCfg ) :
    m_annMean(idStr + "_mean"),
    m_annStddev(idStr + "_stddev")
  {
    initialize_samplers( runnerCfg, util::sequence::make_index_t<NUsers>{} );
  }


  template <typename TrueEncoderT>
  void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {

    m_annMean.initialize_true_encoder( trueEncoderRef );
    m_annStddev.initialize_true_encoder( trueEncoderRef );
  }


private:

  template < typename InActionT = ActionT, util::req_t< std::is_same<InActionT, fp_t> > ...  >
  static
  action_type adapt_sampled( fp_t sampledValue ) noexcept {

    return std::clamp( sampledValue, static_cast<fp_t>(MinRange), static_cast<fp_t>(MaxRange) );
  }
  
  template < typename InActionT = ActionT, util::req_t< std::is_integral<InActionT> > ...  >
  static
  action_type adapt_sampled( fp_t sampledValue ) noexcept {
  
    return std::clamp( std::round( sampledValue ), static_cast<fp_t>(MinRange), static_cast<fp_t>(MaxRange) );
  }



public:

  template < typename... InputArgs >
  action_type get_action( uint_t userId, InputArgs&&... inputArgs ) noexcept {

    ensure( userId < NUsers, "Out of bounds in user id" );

    // Activation of ann_mean is in [0,1] (sigmoid output), so sampled mean is in between [MinRange, RangeSpan]
    auto sampledMean = MinRange + RangeSpan*m_annMean.compute_activations( userId, std::forward<InputArgs>(inputArgs) ... )[0];

    // Activation of ann_stddev is in [0,1] (sigmoid output), so sampled stddev is in between [0, RangeSpan]
    // In this way, max stddev will make
    auto sampledStddev = RangeSpan*m_annStddev.compute_activations( userId, std::forward<InputArgs>(inputArgs) ... )[0];

    // instr::trace<instr::event::learn_agent::pick_threads_end>("gaussian[", sampledMean, sampledStddev, "]");

    return adapt_sampled( m_ownSamplers[userId]->sample( sampledMean, sampledStddev ) );
  }


  typename inference_ann_t::input_state copy_input_activations( uint_t userId ) const noexcept {
    return m_annMean.copy_input_activations( userId );
  }


  version_t get_parameters_version() const noexcept {
    return m_annMean.get_parameters_version();
  }

};

} // namespace learn::approx::ann::policy

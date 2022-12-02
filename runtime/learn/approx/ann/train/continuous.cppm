
export module SteelRT.Learn.Approx.NeuralNet.Train.Continuous;

  export import SteelRT.Learn.Approx.NeuralNet.Train.Gaussian;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;

import SteelRT.Instrument;


import SteelRT.Util.Assert;
#include "assert.hpp"



namespace learn::approx::ann::train {

  template <std::size_t MinRange, std::size_t MaxRange>
  static void set_last_errors( fp_t& meanErr, fp_t& stddevErr, fp_t meanOut, fp_t stddevOut, const fp_t tdErr, const uint_t chosenAction ) {
  
    static constexpr std::size_t RangeSpan = (MaxRange - MinRange);
  
    meanOut = meanOut * RangeSpan + MinRange;
    stddevOut = stddevOut * RangeSpan;
  
    auto diffMean = (fp_t)chosenAction - meanOut;
  
    auto invStddevSq = 1.f / (stddevOut * stddevOut);
  
    meanErr = tdErr * ( diffMean * invStddevSq );
  
    stddevErr = tdErr * ( diffMean * diffMean * invStddevSq - 1.f ) / stddevOut;
  }



export
template <typename InputLayerT, std::size_t NHiddenLayers, std::size_t NHiddenNeurons, typename ActionT, ActionT MinRange, ActionT MaxRange>
class continuous {
private:

  using training_ann_t = training_single_sigmoid< InputLayerT, NHiddenLayers, NHiddenNeurons >;

  training_ann_t m_annMean;
  training_ann_t m_annStddev;

  static constexpr ActionT RangeSpan = MaxRange - MinRange;
  static constexpr ActionT HalfRangeSpan = (MaxRange - MinRange)/2;

  using input_state_type = typename InputLayerT::state_type;

public: // Types

  using input_layer_type = InputLayerT;

  using action_type = ActionT;

public: // Methods

  continuous(const str_t& idStr, const learn::pilot::cfg& pilotCfg ) :
    m_annMean(idStr + "_mean", pilotCfg),
    m_annStddev(idStr + "_stddev", pilotCfg)
  { }


  // Not needed
  // template <typename TrueEncoderT>
  // void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {

  //   m_annMean.initialize_true_encoder( trueEncoderRef );
  //   m_annStddev.initialize_true_encoder( trueEncoderRef );
  // }


  void update( const ann::batch_states_t<input_state_type>& inputStates, const ann::batch_errors_t& tdErrors, const ann::batch_actions_t<action_type>& chosenActions ) {

    auto& lastLayerMeanSigmoidRef = m_annMean.get_last_layer_ref();
    auto& lastLayerStddevSigmoidRef = m_annStddev.get_last_layer_ref();

    // 1. Compute forward all batch
    m_annMean.compute_forward( inputStates );
    m_annStddev.compute_forward( inputStates );

    const auto& outMeans = m_annMean.get_last_layer_ref().get_activations();
    const auto& outStddevs = m_annStddev.get_last_layer_ref().get_activations();

    // 2. Calculate errors in the last layer, to be propagated bacwards
    const auto batchSize = inputStates.get_batch_size();

    ensure(batchSize == tdErrors.get_batch_size(), "Mismatch in batch size");
    ensure(batchSize == chosenActions.get_batch_size(), "Mismatch in batch size");

    ann::batch_errors_t meanErrors( batchSize );
    ann::batch_errors_t stddevErrors( batchSize );

    for (auto s = 0u; s < batchSize; s++) {

      set_last_errors<MinRange, MaxRange>( meanErrors.edit_values(s)[0], stddevErrors.edit_values(s)[0], outMeans.get_values(s)[0], outStddevs.get_values(s)[0], tdErrors.get_values(s)[0], chosenActions.get_values(s)[0] );
    }

    const auto& prelastLayerMeanSigmoidRef = m_annMean.get_pre_last_layer_ref();
    const auto& prelastLayerStddevSigmoidRef = m_annStddev.get_pre_last_layer_ref();

    lastLayerMeanSigmoidRef.set_errors( prelastLayerMeanSigmoidRef.get_activations(), meanErrors );
    lastLayerStddevSigmoidRef.set_errors( prelastLayerStddevSigmoidRef.get_activations(), stddevErrors );

    // 3. Compute backward
    m_annMean.compute_backward();
    m_annStddev.compute_backward();
  }


  version_t get_parameters_version() const {
    return m_annMean.get_parameters_version();
  }


  // For outputing the learn summary only. Skipped activations of stddev XXX
  const auto& get_activations( const ann::batch_states_t<input_state_type>& inputStates ) noexcept {

    // 1. Compute forward
    m_annMean.compute_forward( inputStates );
    // m_annStddev.compute_forward( inputStates );

    const auto& lastLayerMeanSigmoidRef = m_annMean.get_last_layer_ref();
    // const auto& lastLayerStddevSigmoidRef = m_annMean.get_last_layer_ref();

    return lastLayerMeanSigmoidRef.get_activations();//, lastLayerStddevSigmoidRef.get_activations()[0] );
  }

};

} // namespace learn::approx::ann::train

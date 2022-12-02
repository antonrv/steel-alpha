
export module SteelRT.Learn.Approx.NeuralNet.Policy.Discrete;

  export import SteelRT.Learn.Approx.NeuralNet.Inference;
  export import SteelRT.Learn.Approx.Sampler.Discrete;


import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;



// import SteelRT.Instrument;

import SteelRT.Util.Assert;
#include "assert.hpp"



namespace learn::approx::ann::policy {


export
template <std::size_t NUsers, typename InputLayerT, std::size_t NHiddenLayers, std::size_t NHiddenNeurons, typename ActionSeqT>
class discrete : 
public 
  ann::inference<
    NUsers, InputLayerT,
    util::sequence::cat_t<
      util::sequence::make_copies_t<NHiddenLayers, util::sequence::index_t<NHiddenNeurons, NHiddenNeurons, NHiddenNeurons, NHiddenNeurons>>,
      util::sequence::index_t<ActionSeqT::size(), ActionSeqT::size(), ActionSeqT::size(), ActionSeqT::size()>
    >,
    util::sequence::cat_t<
      util::sequence::make_copies_t<NHiddenLayers, util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::sample_norm, learn::fun::batch_norm, learn::fun::relu>>,
      util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::sample_norm, learn::fun::batch_norm, learn::fun::softmax>
    >
  >
{
private:

  using super_type_ann = 
    ann::inference<
      NUsers, InputLayerT,
      util::sequence::cat_t<
        util::sequence::make_copies_t<NHiddenLayers, util::sequence::index_t<NHiddenNeurons, NHiddenNeurons, NHiddenNeurons, NHiddenNeurons>>,
        util::sequence::index_t<ActionSeqT::size(), ActionSeqT::size(), ActionSeqT::size(), ActionSeqT::size()>
      >,
      util::sequence::cat_t<
          util::sequence::make_copies_t<NHiddenLayers, util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::sample_norm, learn::fun::batch_norm, learn::fun::relu>>,
          util::sequence::enum_t<learn::fun, learn::fun::matrix, learn::fun::sample_norm, learn::fun::batch_norm, learn::fun::softmax>
        >
      >;


  using action_type = typename ActionSeqT::value_type;
  using action_array_t = util::sequence::to_array_t< ActionSeqT >;
  static constexpr const action_array_t action_array_v = util::sequence::to_array_v<ActionSeqT>;



  // ================ PER-USER SAMPLER
  using discrete_sampler_t = approx::sampler<approx::distribution::discrete>;
  using own_discrete_sampler_t = std::unique_ptr< discrete_sampler_t >;

  using own_action_samplers_t = std::array< own_discrete_sampler_t, NUsers >;

  own_action_samplers_t m_ownSamplers; // built with (0,1) params


private:


  template <std::size_t... Ids>
  void initialize_samplers( const learn::runner::cfg& runnerCfg, util::sequence::index_t<Ids...> ) {

    ( (m_ownSamplers[Ids] = std::make_unique<discrete_sampler_t>( runnerCfg.seed, runnerCfg.seedValue )), ... );
  }

public:

  discrete( const str_t& idStr, const learn::runner::cfg& runnerCfg ) :
    super_type_ann(idStr)
  {
    initialize_samplers( runnerCfg, util::sequence::make_index_t<NUsers>{} );
  }


  template < typename... InputArgs >
  action_type get_action( uint_t userId, InputArgs&&... inputArgs ) noexcept {

    ensure( userId < NUsers, "Out of bounds in user id" );

    const auto& actionProbs = super_type_ann::compute_activations( userId, std::forward<InputArgs>(inputArgs) ... );

    // instr::trace<instr::event::learn_agent::pick_implement_inference_end>("action prob", actionProbs );

    return action_array_v[ m_ownSamplers[ userId ]->sample( actionProbs ) ];
  }



  template <typename TrueEncoderT>
  void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
    super_type_ann::initialize_true_encoder( trueEncoderRef );
  }

  typename super_type_ann::input_state copy_input_activations( uint_t userId ) const noexcept {
    return super_type_ann::copy_input_activations( userId );
  }

  // DEPRECATED This may introduce divergences
  // template < typename RestrictedActionSeqT, typename... InputArgs >
  // action_type get_restricted_action( uint_t userId, InputArgs&&... inputArgs ) noexcept {

  //   ensure( userId < NUsers, "Out of bounds in user id" );

  //   const auto& actionProbs = super_type_ann::compute_activations( userId, std::forward<InputArgs>(inputArgs) ... );

  //   using MaskIdsT = util::sequence::get_mask_t<ActionSeqT, RestrictedActionSeqT>;

  //   auto restrictedActionProbs = op::apply_mask_normalize_array<MaskIdsT>( actionProbs );

  //   instr::trace<instr::event::learn_agent::pick_implement_inference_end>("action prob", restrictedActionProbs );

  //   using restr_action_array_t = util::sequence::to_array_t< RestrictedActionSeqT >;

  //   static constexpr const restr_action_array_t restr_action_array_v = util::sequence::to_array_v<RestrictedActionSeqT>;

  //   return restr_action_array_v[ m_ownSamplers[ userId ]->sample( restrictedActionProbs ) ];
  // }


};


} // namespace learn::approx::ann::policy


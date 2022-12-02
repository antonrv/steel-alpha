

export module SteelRT.Learn.Approx.NeuralNet.Inference;

  export import SteelRT.Learn.Approx.NeuralNet.Base;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;


import SteelRT.Learn.Types;

import <tuple>;
import <array>;


namespace learn::approx::ann {


export
template <std::size_t NUsers, typename InputLayerT, typename NeuronCountSeq, typename FunSeq>
class inference :
public
ann::base<
  ann::propagate::fwd,
  ann::width::single,
  InputLayerT,
  util::sequence::pop_back_t< util::sequence::add_front_t<NeuronCountSeq, InputLayerT::need_weights> >,
  NeuronCountSeq,
  FunSeq
>
{
private:

  using super = ann::base< 
      ann::propagate::fwd,
      ann::width::single,
      InputLayerT,
      util::sequence::pop_back_t< util::sequence::add_front_t<NeuronCountSeq, InputLayerT::need_weights> >,
      NeuronCountSeq,
      FunSeq
    >;


  // ================ PER-USER LAYERS. For concurrent inference. Matrix layers hold a ptr to the weights

  using user_layers_t = std::array< typename super::layers_t, NUsers >; 

  user_layers_t m_layers;

public:

  using input_state = typename super::input_state;


public:

  inference(const str_t idStr) :
    super(idStr)
  {
    for (auto userId = 0; userId < NUsers; userId++) {
      super::bind_all_weights( m_layers[userId], typename super::parametric_layers_ids{} );
    }
  }

  inference(inference&&) = delete;
  inference(const inference&) = delete;


public: // Accessible from an agent, to set the true encoders

  template <typename TrueEncoderT>
  void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
    for (auto userId = 0u; userId < NUsers; userId++) {
      super::initialize_true_encoder( m_layers[userId], trueEncoderRef );
    }
  }


public: // Only callable from a policy / Value function

  template <typename... InputArgs>
  const array_t< super::NOutput >& compute_activations( uint_t userId, InputArgs&&... inputArgs ) noexcept {

    super::compute_forward_from_args( m_layers[userId], std::forward<InputArgs>( inputArgs ) ... );

    return std::get< super::LastId >( m_layers[userId] ).get_activations().get_values();
  }


public:

  input_state copy_input_activations( uint_t userId ) const noexcept {
    return std::get< super::FirstId >( m_layers[userId] ).export_activations();
  }

};


} // namespace learn::approx::ann

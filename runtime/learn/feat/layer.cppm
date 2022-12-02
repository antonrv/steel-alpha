
export module SteelRT.Learn.Feat.Layer;

  export import SteelRT.Learn.Feat.Encoder;

import SteelRT.Learn.Types; // Needed just for learn::fun XXX. Maybe separate enums into a more basic module

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Util.Assert;
#include "assert.hpp"


export
namespace learn::feat {

// Input layer must be aligned to cache line to prevent false sharing across threads



template <typename EncoderT>
struct is_ref_encoder : util::same<EncoderT::feat_kind, feat::kind::ref> {};

template <typename EncoderT>
struct is_editable_encoder : std::negation< is_ref_encoder<EncoderT> > {};

template <typename EncoderT>
struct to_editable {
  using type = EncoderT;
};

template <typename TrueEncoderT>
struct to_editable <feat::encoder<feat::kind::ref, TrueEncoderT>> {
  using type = TrueEncoderT;
};


template < typename TupleFeatEncodersT >
class alignas(64) layer {
public:

  static constexpr std::size_t count_encoders = TupleFeatEncodersT::size();

private:
  template <typename EncoderT>
  using encoded_type_of_t = typename EncoderT::encoded_type;

public:

  using state_type = util::tuple::as_std_t< util::tuple::lift_t< TupleFeatEncodersT, encoded_type_of_t > >;

  static constexpr learn::fun layer_function = learn::fun::input;


private:

  using encoder_ids_t = util::sequence::make_index_t< count_encoders >;

  template <std::size_t EncoderId>
  using encoded_t = typename util::tuple::element_t<EncoderId, TupleFeatEncodersT>::encoded_type;




  using edit_encoder_ids_t = util::tuple::satisfy_indexes_t< TupleFeatEncodersT, is_editable_encoder >;

  using ref_encoder_ids_t = util::tuple::satisfy_indexes_t< TupleFeatEncodersT, is_ref_encoder >;

  using feat_encoders_t = util::tuple::as_std_t< TupleFeatEncodersT >;

  feat_encoders_t m_featEncoders;

  // Number of weights needed by each encoder
  template <typename EncoderT>
  struct need_weights_of { static constexpr std::size_t value = EncoderT::need_weights; };


  using encoder_need_weights = util::sequence::from_tuple_t< TupleFeatEncodersT, need_weights_of >;

private:
  // state_type omiting the ref encoders

  using tuple_import_feat_encoders = util::tuple::filter_t< TupleFeatEncodersT, is_editable_encoder >;

public:

  static constexpr std::size_t need_weights = util::sequence::index_sum_v<encoder_need_weights>;

  using weight_starts =
      util::sequence::add_front_t<
        util::sequence::reverse_t<
          util::sequence::index_aggregate_t<
            util::sequence::reverse_t< 
              util::sequence::pop_back_t<encoder_need_weights> // <2,4,1,5> --> <2,4,1>
            > // <1,4,2>
          > // <7, 6, 2>
        > // <2,6,7>
      , 0>; // <0,2,6,7>


public: //////////////////// INITIALIZE ENCODER REFERENCES

  template <typename TrueEncoderT>
  void initialize_true_encoder( const TrueEncoderT& trueEncoderRef ) noexcept {
    std::get< feat::encoder<feat::kind::ref, TrueEncoderT> >( m_featEncoders ).set_true_encoder( trueEncoderRef );
  }


public: //////////////////// GET ACTIVATIONS INTERFACE


  // Interface for operate weights
  template <std::size_t EncoderId>
  const encoded_t<EncoderId>& get_encoded_features() const noexcept {

    return std::get<EncoderId>( m_featEncoders ).get_encoded_features( );
  }

   
  // Interface for ANN forward
  layer& get_activations() noexcept {
    return (*this);
  }


private: /////////////////// SET ACTIVATIONS INTERFACE

  
  template <std::size_t EditEncoderId, typename... InputArgs>
  void set_activation_in( InputArgs&&... args ) noexcept {
    std::get<EditEncoderId>( m_featEncoders ).set_encoded_features( std::forward<InputArgs>( args) ... );
  }

  template <typename... InputArgs>
  void set_activations_detail( util::sequence::index_t<>, InputArgs&&... args) noexcept {
    // Do nothing
  }

  template <std::size_t EditEncoderId, std::size_t... EditEncoderIds, typename... InputArgs>
  void set_activations_detail( util::sequence::index_t<EditEncoderId, EditEncoderIds...>, InputArgs&&... args) noexcept {

    set_activation_in<EditEncoderId>( std::forward<InputArgs>(args) ... );

    set_activations_detail( util::sequence::index_t<EditEncoderIds...>{}, std::forward<InputArgs>(args) ... );
  }


public:

  // Main interface for INFERENCE within runner context
  // Arguments are perfect-forwarded from the m_actor.get_action( args )
  template <typename... InputArgs>
  void set_activations( InputArgs&&... args ) noexcept {

    set_activations_detail( edit_encoder_ids_t{}, std::forward<InputArgs>(args) ... );
  }


private: // EXPORT ACTIVATIONS : to retrieve the input of an action and build a MDP sequence

  template <std::size_t... EncoderIds>
  state_type export_activations_detail( util::sequence::index_t<EncoderIds...> ) const noexcept {
    return std::make_tuple( std::get<EncoderIds>( m_featEncoders ).get_encoded_features() ... );
  }

public:

  // Main interface for INFERENCE within runner context, to send the state to pilot process
  state_type export_activations( ) const noexcept {

    return export_activations_detail( encoder_ids_t{} );
  }


private: // IMPORT ACTIVATIONS

  // DEPRECATED. No need to verify. All encoders in a input layer belonging to a training ANN are editable (ie non-ref)
  // template <std::size_t... RefEncoderIds>
  // void verify_ref_encoded_detail( const state_type& importValues, util::sequence::index_t<RefEncoderIds...> ) noexcept {
  //   ( std::get< RefEncoderIds >( m_featEncoders ).verify_encoded_features( std::get< RefEncoderIds >( importValues ) ), ... );
  // }

  template <std::size_t... EditEncoderIds>
  void import_activations_detail( const state_type& importValues, util::sequence::index_t<EditEncoderIds...> ) noexcept {
    ( std::get< EditEncoderIds >( m_featEncoders ).import_encoded_features( std::get< EditEncoderIds >( importValues ) ), ... );
  }

public:

  // Main interface for TRAINING within pilot context
  void import_activations( const state_type& importValues ) noexcept {

    // Since the encoders of an input layer belonging to a training neural network are all real (none is ref encoder, the ref_encoder_ids_t sequence must be empty when this is called)
    
    // static_assert( ref_encoder_ids_t::size() == 0 ); // We cannot do this since import_activations is instantiated in runner and pilot contexts
    // So we check that if this is called, it must be called from a pilot context)
    ensure( ref_encoder_ids_t::size() == 0, "No reference encoders can exist when importing activations. All encoders must be editable" );

    // DEPRECATEDVerify the activations (encoded values) associated to constant (ref) encoders.
    // verify_ref_encoded_detail( importValues, ref_encoder_ids_t{} );

    // Only import the activations (encoded values) associated to editable (non-ref) encoders.
    import_activations_detail( importValues, edit_encoder_ids_t{} );
  }

};

template < typename LayerT >
struct is_layer : std::false_type {};

// Rest of layers will hold a traits as its type
template < typename TupleFeatEncodersT >
struct is_layer < layer<TupleFeatEncodersT> > : util::is_tuple<TupleFeatEncodersT> {};


} // namespace learn::feat

// DEPRECATED
// 
// template <std::size_t NeuronEnabled, std::size_t NeuronCount>
// class layer< traits<approx::fun::input_bool, NeuronEnabled, NeuronCount> > : public activation< approx::fun::input_bool, NeuronEnabled > {
// public:
//   // using traits_type = traits<approx::fun::input_bool, NeuronEnabled, NeuronCount>;
//   static constexpr approx::fun layer_function = approx::fun::input_bool;
// };
// 
// 
// template <std::size_t NeuronCount>
// class layer< traits<approx::fun::input_real, NeuronCount, NeuronCount> > : public activation< approx::fun::input_real, NeuronCount > {
// public:
//   // using traits_type = traits<approx::fun::input_real, NeuronCount, NeuronCount>;
//   static constexpr approx::fun layer_function = approx::fun::input_real;
// };

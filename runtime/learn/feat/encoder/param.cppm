
export module SteelRT.Learn.Feat.Encoder.Param;

  export import SteelRT.Learn.Feat.Encoder.Base;
  export import SteelRT.Learn.Feat.Coder.Numeric;

  export import SteelRT.Task.Descriptor.Feed;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;


import SteelRT.Learn.Types;


export
namespace learn::feat {

template <typename TupleFeedT>
struct aux_param {

  using tuple_feed_type = TupleFeedT;

  template <typename ArgT>
  using coder_type = coder::default_numeric< ArgT >;

  using coder_tuple = util::tuple::lift_t< TupleFeedT, coder_type >;

  using encoded_type = std::array<fp_t, TupleFeedT::size()>;
};


template <typename TupleFeedT>
class encoder <feat::kind::app_params, TupleFeedT> :
public encoder_base< typename aux_param<TupleFeedT>::encoded_type >
{
private:

  using super_type = encoder_base< typename aux_param<TupleFeedT>::encoded_type >;

  using coder_tuple = typename aux_param<TupleFeedT>::coder_tuple;

  static constexpr std::size_t NFeed = aux_param<TupleFeedT>::tuple_feed_type::size();

  using id_seq = util::sequence::make_index_t<NFeed>;

  // using return_type = typename aux_param<TupleFeedT>::coder_return_type; // All coders must return the same type

public:

  static constexpr std::size_t need_weights = NFeed;

  static constexpr feat::kind feat_kind = feat::kind::app_params;

private:

  template <std::size_t ArgId, typename StdTupleFeedT>
  void set_feed( typename super_type::encoded_type& encodedValues, const StdTupleFeedT& tupleFeed ) {

    using coder_type = util::tuple::element_t<ArgId, coder_tuple>;

    coder_type::set_encoding( std::get<ArgId>(encodedValues), std::get<ArgId>(tupleFeed) );
  }

  template <std::size_t... ArgIds, typename StdTupleFeedT>
  void set_all_feed( typename super_type::encoded_type& encodedValues, const StdTupleFeedT& tupleFeed, util::sequence::index_t<ArgIds...> ) {

    ( set_feed<ArgIds>( encodedValues, tupleFeed ), ... );
  }


public:

  template <typename DescPtrT>
  void set_encoded_features( const DescPtrT desc ) noexcept {

    // loop on coders for each feed argument
    using coder_param_seq = util::sequence::make_index_t< util::tuple::size_v<coder_tuple> >;

    static constexpr app::call AppCall = std::remove_pointer_t< DescPtrT >::app_call;

    auto tupleFeed = extract_feed<AppCall>( desc );

    set_all_feed( super_type::m_encoded, tupleFeed, id_seq{} );
  }

};

} // namespace learn::feat

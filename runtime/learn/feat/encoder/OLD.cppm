
export module SteelRT.Learn.Feat.Encoder;

import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Sequence;
import SteelRT.Util.Tuple;
import SteelRT.Util.App;
import SteelRT.Util.Work;
import SteelRT.Util.FwDeclarations.Plat;

export import SteelRT.Learn.Feat.TileCoder;

import SteelRT.Task.Descriptor;

export import SteelRT.Learn.Feat.Feed;


export
namespace learn::feat {

enum class kind : enum_uint_t { ref, depth, active_threads, app_call, app_params };

// A input of a policy is a set of feat_categories

// A non-ref encoder must expose this interface:

// using encoded_t = ...
// static constexpr std::size_t need_weights = ....
// static constexpr feat::kind feat_kind = ...
// void set_encoded_features( ... )
// encoded_t get_encoded_features( ) 



template <feat::kind FeatKind>
class encoder_builtin;

template <feat::kind FeatKind, plat::processor ProcId>
class encoder_plat;

template <feat::kind FeatKind, plat::processor ProcId, typename NativeT>
class encoder_app;

template <feat::kind FeatKind, typename AppGroupT, typename NativeT>
class encoder_app_param;



template < feat::kind FeatKind, typename EncoderT >
class encoder;















//// This encoder sets the active tiles corresponding to a specific AppCall
template <plat::processor ProcId, typename NativeT>
class encoder_app <feat::kind::app_call, ProcId, NativeT> {
private:

  using compat_proc_impls = typename NativeT::template compatible_processable_impls<ProcId>; // We just need descriptors here

  //  sequence of calls whose impls are runnable on ProcId
  using compat_proc_calls = app::cat_calls_of_t< compat_proc_impls >;

  // using compat_call_array = util::sequence::to_array_t< compat_proc_calls >;

  // static constexpr const compat_call_array s_callArray = util::sequence::to_array_v< compat_proc_calls >;


  static constexpr std::size_t NCalls = compat_proc_calls::size();

  static constexpr std::size_t NTilings = 1;
  
  using coder = tile_coder< enum_uint_t, 0, NCalls, /*TileSize*/1, rescale::linear, NTilings >; // No generalization, full discrimination

public:

  static constexpr feat::kind feat_kind = feat::kind::app_call;

  static constexpr std::size_t active_space_size = NTilings;

  static constexpr std::size_t full_space_size = coder::full_size;

  template <app::call AppCall>
  static void encode_active_tiles( view<uint_t, NTilings> activeTiles ) {

    // auto thisAppCallIdx = util::sequence::get_index_rt< compat_call_array >::from_value( s_callArray, static_cast<app::call>( polyDesc->appCall ) );

    // Equivalent to: activeTiles[ 0 ] = thisAppCallIdx, because we are fully discriminating among calls, but use the coder for pattern uniformity.
    static constexpr std::size_t ThisAppCallIdx = util::sequence::get_index_v< compat_proc_calls, AppCall>;

    coder::get_active_tiles( activeTiles, ThisAppCallIdx );
  }
};



// One neuron per param
template < typename AppGroupT, typename NativeT >
class encoder_app_param < feat::kind::app_params, AppGroupT, NativeT > {
private:

  // app::seq_feed_t<AppCall> store the indices corresponding to arithmetic parameters

  // app::tuple_feed_t<AppCall> store those types. which can be lifted to default coders


  // Pick the head for example, does not matter as all of them share the same tuple_resolve_t, hence same tuple_feed_t
  using tuple_feed_t = app::tuple_feed_t< util::sequence::head_v< app::impls_of_t<AppGroupT::id_value> > >;


  // In the future, the user will be able to specify the range for a task parameter with an annotation, to let the NN focus concentrate certain range.

  using std_tuple_feed_t = util::tuple::as_std_t<tuple_feed_t>;


  // Create a default log tile coder for each feed parameter
  using coder_tuple = util::tuple::lift_t< default_log_tile_coder, tuple_feed_t >;


  // Extract active_size for each coder and build a sequence
  template <typename CoderT>
  struct extract_active_size { static constexpr std::size_t value = CoderT::active_size; };

  using active_space_sizes_seq = util::sequence::from_tuple_t<coder_tuple, extract_active_size>;  // < 2,4,1,5 >

  static constexpr std::size_t NTilings = util::sequence::index_sum_v< active_space_sizes_seq >;


  // Monotonic seq from prev seq accumulation : <0, 2, 6, 7 >, starting from zero
  using active_space_starts_seq =
    util::sequence::add_front_t<
      util::sequence::reverse_t<
        util::sequence::index_aggregate_t<
          util::sequence::reverse_t< 
            util::sequence::pop_back_t<active_space_sizes_seq> // <2,4,1,5> --> <2,4,1>
          > // <1,4,2>
        > // <7, 6, 2>
      > // <2,6,7>
    , 0>; // <0,2,6,7>


  template <typename CoderT>
  struct extract_full_size { static constexpr std::size_t value = CoderT::full_size; };

  using full_space_sizes_seq = util::sequence::from_tuple_t<coder_tuple, extract_full_size>;  // < 2,4,1,5 >

private:

  template <std::size_t FeedArgId, std::size_t ActiveSpaceSize>
  static void encode_feed_active_tiles( view<uint_t, ActiveSpaceSize> activeTiles, const std_tuple_feed_t& tupleFeed ) {

    using this_coder = util::tuple::element_t<FeedArgId, coder_tuple>;

    // std::cout << "Param encoder : arg id "<< FeedArgId << " value : "  << std::get<FeedArgId>(tupleFeed) << '\n';

    this_coder::get_active_tiles( activeTiles, std::get<FeedArgId>(tupleFeed) );
  }


  template <std::size_t... FeedArgs, std::size_t... ActiveSpaceSizes, std::size_t... StartIds>
  static void encode_active_tiles_detail( view<uint_t, NTilings>& activeTiles, const std_tuple_feed_t& tupleFeed, util::sequence::index_t<FeedArgs...>, util::sequence::index_t<ActiveSpaceSizes...>, util::sequence::index_t<StartIds...> ) {

    ( encode_feed_active_tiles<FeedArgs, ActiveSpaceSizes>( activeTiles.template sub_view<StartIds, ActiveSpaceSizes>(), tupleFeed ), ... );
  }

public:

  static constexpr feat::kind feat_kind = feat::kind::app_params;

  static constexpr std::size_t active_space_size = util::sequence::index_sum_v< active_space_sizes_seq >;

  static constexpr std::size_t full_space_size = util::sequence::index_sum_v< full_space_sizes_seq >;


  template <app::call AppCall>
  static void encode_active_tiles( view<uint_t, NTilings> activeTiles, const workload::poly_desc_t polyDesc ) {

    // loop on coders for each feed argument
    using coder_param_seq = util::sequence::make_index_t< util::tuple::size_v<coder_tuple> >;

    auto tupleFeed = extract_feed<AppCall>( polyDesc );
    
    encode_active_tiles_detail( activeTiles, tupleFeed, coder_param_seq{}, active_space_sizes_seq{}, active_space_starts_seq{} );
  }

};




// // One numeric neuron per param
// template < typename AppGroupT, typename NativeT >
// class encoder_app_param < feat::kind::app_params_compact, AppGroupT, NativeT > {
// private:
// 
// 
//   // Pick the head for example, does not matter as all of them share the same tuple_resolve_t, hence same tuple_feed_t
//   using tuple_feed_t = app::tuple_feed_t< util::sequence::head_v< app::impls_of_t<AppGroupT::id_value> > >;
// 
// 
// public:
// 
//   template <app::call AppCall>
//   static void encode_active_tiles( view<float, NTilings> activeTiles, const workload::poly_desc_t polyDesc ) {
//     
// 
//     auto tupleFeed = extract_feed<AppCall>( polyDesc );
// 
//     encode_active_tiles_detail( activeTiles, tupleFeed, coder_param_seq{}, active_space_sizes_seq{}, active_space_starts_seq{} );
//   }
// 
// 
// };



} // namespace learn::feat

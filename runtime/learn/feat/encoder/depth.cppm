
export module SteelRT.Learn.Feat.Encoder.Depth;

  export import SteelRT.Learn.Feat.Encoder.Base;
  export import SteelRT.Learn.Feat.Coder.Numeric;


import SteelRT.Util.Basic;
import SteelRT.Util.Work;
import SteelRT.Task.Descriptor;



export
namespace learn::feat {

template <typename DepthT>
struct aux_depth {

// This typename DepthT is just a dummy type to respect the encoder template arg interface, but actually no need to pass any type
  static_assert(std::is_same_v<DepthT, depth_t>);

  using coder_type = coder::numeric<depth_t, 0, global::DepthLimit, rescale::linear>;

  using encoded_type = typename coder_type::encoded_type;
};


template < typename DepthT >
class encoder <feat::kind::depth, DepthT> :
public encoder_base< typename aux_depth<DepthT>::encoded_type >
{
private:

  using super_type = encoder_base< typename aux_depth<DepthT>::encoded_type >;

  using coder_type = typename aux_depth<DepthT>::coder_type;

public:

  static constexpr std::size_t need_weights = coder_type::full_size;

  static constexpr feat::kind feat_kind = feat::kind::depth;

  void set_encoded_features( const workload::poly_desc_t polyDesc ) noexcept {
    coder_type::set_encoding( super_type::m_encoded, polyDesc->depth );
  }

};


} // namespace learn::feat

// DEPRECATED
// template <>
// class encoder_builtin <feat::kind::depth> {
// 
//   static constexpr std::size_t NTilings = 2;
// 
//   // Nearest neighbor (+/-1) discrimination/generalization
//   using coder = tile_coder< depth_t, 0, global::DepthLimit, /*TileSize*/2,  rescale::linear, NTilings >; // DL = 8
// 
// public:
// 
//   static constexpr feat::kind feat_kind = feat::kind::depth;
// 
//   static constexpr std::size_t active_space_size = NTilings;
// 
//   static constexpr std::size_t full_space_size = coder::full_size;
// 
//   static void encode_active_tiles( view<uint_t, NTilings> activeTiles, const workload::poly_desc_t polyDesc ) {
// 
//     coder::get_active_tiles( activeTiles, polyDesc->depth );
//   }
// };


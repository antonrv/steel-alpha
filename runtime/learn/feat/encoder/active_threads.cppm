
export module SteelRT.Learn.Feat.Encoder.ActiveThreads;

  export import SteelRT.Learn.Feat.Encoder.Base;
  export import SteelRT.Learn.Feat.Coder.Numeric;

import SteelRT.Util.Types;

export
namespace learn::feat {


template <typename PTraits>
struct aux_active_threads {

  static constexpr std::size_t max_threads = PTraits::max_threads;

  using coder_type = coder::numeric<uint_t, 0, max_threads, rescale::linear>;

  using encoded_type = typename coder_type::encoded_type;

};


template <typename PTraits>
class encoder <feat::kind::active_threads, PTraits> :
public encoder_base< typename aux_active_threads<PTraits>::encoded_type > 
{
private:

  using super_type = encoder_base< typename aux_active_threads<PTraits>::encoded_type >;


  // Nearest neighbor (+/-1) generalization
  // using coder = tile_coder< thread_id_t, 0, plat::ptraits<ProcId>::max_threads, TileSize, rescale::linear, NTilings >;

  using coder_type = typename aux_active_threads<PTraits>::coder_type;

public:

  static constexpr std::size_t need_weights = coder_type::full_size;

  static constexpr feat::kind feat_kind = feat::kind::active_threads;

public:


  void set_encoded_features( uint_t nThreads ) noexcept {
    coder_type::set_encoding( super_type::m_encoded, nThreads );
  }

};

} // namespace learn::feat

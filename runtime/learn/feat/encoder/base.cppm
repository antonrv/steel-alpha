
export module SteelRT.Learn.Feat.Encoder.Base;


import SteelRT.Util.Basic;
import SteelRT.Learn.Types;


export
namespace learn::feat {


enum class kind : enum_uint_t { ref, depth, active_threads, app_call, app_params };

// All specializations but kind::ref will derive from encoder_base
// InfoT will be a type needed to fully define the particular 'Kind' encoder.
template <kind Kind, typename InfoT>
class encoder;


template <typename EncodedT>
class encoder_base {
public:

  using encoded_type = EncodedT;

protected:

  encoded_type m_encoded;

public:


  void initialize() noexcept {

    static_assert(is_index_array<encoded_type>::value or is_fp_array<encoded_type>::value or is_fp<encoded_type>::value or is_uint<encoded_type>::value);

    if constexpr (is_index_array<encoded_type>::value) {
      for (auto& v : m_encoded) {
        v = global::NoIndex;
      }
    } else if constexpr (is_fp_array<encoded_type>::value) {
      for (auto& v : m_encoded) {
        v = 0;
      }
    } else if constexpr (is_fp<encoded_type>::value) {
      m_encoded = 0;

    } else if constexpr (is_uint<encoded_type>::value) {
      m_encoded = 0;
    } else if constexpr (is_int<encoded_type>::value) {
      m_encoded = 0;
    } else {
      // Unreachable due to static assert
    }
  }

  const encoded_type& get_encoded_features() const noexcept {
    return m_encoded;
  }

  void import_encoded_features( const encoded_type& importEncoded ) noexcept {
    m_encoded = importEncoded;
  }

};
  
} // namespace learn::feat

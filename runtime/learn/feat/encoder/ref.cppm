
export module SteelRT.Learn.Feat.Encoder.Reference;

  export import SteelRT.Learn.Feat.Encoder.Base;

import SteelRT.Util.Types;


import SteelRT.Util.Assert;
#include "assert.hpp"

export
namespace learn::feat {

///// Read only encoder
template < typename EncoderT >
class encoder <feat::kind::ref, EncoderT> {
private:

  static_assert( EncoderT::feat_kind != feat::kind::ref );

  const EncoderT * m_encoderPtr = nullptr;

public:

  using reference_encoder_type = EncoderT;

  using encoded_type = typename EncoderT::encoded_type;

  static constexpr std::size_t need_weights = EncoderT::need_weights;

  static constexpr feat::kind feat_kind = feat::kind::ref;


  void set_true_encoder( const EncoderT& trueEncoderRef ) noexcept {

    ensure(m_encoderPtr == nullptr, "true encoder reference must be initialized once");

    m_encoderPtr = &trueEncoderRef;
  }


  const encoded_type& get_encoded_features() const noexcept {

    ensure(m_encoderPtr != nullptr, "true encoder reference not initialized");

    return m_encoderPtr->get_encoded_features();
  }

  void verify_encoded_features(const encoded_type& encodedValues) const noexcept {

    ensure(m_encoderPtr != nullptr, "true encoder reference not initialized");

    ensure( m_encoderPtr->get_encoded_features() == encodedValues, "Verification of encoded features failed in reference encoder failed" );
  }
};

} // namespace learn::feat

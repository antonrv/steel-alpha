
export module SteelRT.Learn.Feat.Coder.Numeric;

  export import SteelRT.Learn.Feat.Coder.Rescale;

import SteelRT.Learn.Types;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;


export
namespace learn::feat::coder {


template <typename T, T InRangeMin, T InRangeMax, rescale Rescale>
class numeric {
private:

  static constexpr T RangeMin = scale_value<Rescale>::Convert( InRangeMin );
  static constexpr T RangeMax = scale_value<Rescale>::Convert( InRangeMax );
  static constexpr T Norm = RangeMax - RangeMin;
  
public:

  static constexpr std::size_t active_size = 1;
  static constexpr std::size_t full_size = 1;
  using return_type = fp_t;

  using encoded_type = fp_t;

  static void set_encoding( encoded_type& encodedValue, const T value ) noexcept {
    encodedValue = (static_cast<fp_t>(scale_value<Rescale>::convert(value)) - static_cast<fp_t>(RangeMin)) / static_cast<fp_t>(Norm);
  }

};


template <typename BasicT>
struct default_numeric;


template <>
struct default_numeric < uint_t > : numeric<uint_t, 1, std::numeric_limits<uint_t>::max(), rescale::log> {};


template <>
struct default_numeric < fp_t > : numeric<uint_t, 0, 1, rescale::linear> {};


} // namespace learn::feat::coder

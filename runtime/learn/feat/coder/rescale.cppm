

export module SteelRT.Learn.Feat.Coder.Rescale;

import SteelRT.Util.Types;


import SteelRT.Util.Assert;
#include "assert.hpp"




export
namespace learn::feat {


enum class rescale : enum_uint_t { linear, log };


template <rescale Rescale>
struct scale_value;

template <>
struct scale_value<rescale::linear> {

  template <typename T>
  static uint_t convert(T value) {
    return value;
  }

  template <typename T>
  static constexpr uint_t Convert(T value) {
    return value;
  }
};

template <>
struct scale_value<rescale::log> {

  template <typename T>
  static uint_t convert(T value) {
    ensure(value > 0, "Cannot log(0)");
    uint_t res = 0;
    while (value >>= 1) { ++res; }
    return res;
  }


  template <typename T>
  static constexpr uint_t Convert(T value) {
    return (value == 1) ? 0 : (value == 2) ? 1 : 1 + Convert(value/2);
  }
};


// FROZEN
// template <typename T, std::size_t N>
// class view {
// private:
//   T * const m_ptr;
// public:
//   view(T * p) : m_ptr(p) {}
//   T& operator[] ( unsigned i ) noexcept {
//     ensure(i < N, "Out of bounds violation in ptr view");
//     return m_ptr[i];
//   }
// 
//   const T& operator[] ( unsigned i ) const noexcept {
//     ensure(i < N, "Out of bounds violation in ptr view");
//     return m_ptr[i];
//   }
// 
//   template <std::size_t Start, std::size_t Range>
//   view<T, Range> sub_view() noexcept {
//     static_assert( Start + Range <= N );
//     return view<T, Range>( m_ptr + Start );
//   }
// };



} // namespace learn::feat

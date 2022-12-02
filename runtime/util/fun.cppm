export module SteelRT.Util.Functions;


// import <cstdint>;
import <cstdio>;

////////////// CONSTEXPR FUNCTIONS

namespace util {


constexpr unsigned log2i_floor(const unsigned a) {
  return (a <= 2 ? a - 1 : 1 + log2i_floor(a / 2));
}

export
constexpr unsigned bits_of(const unsigned nElem) {
  if (nElem > 1 && !(nElem & (nElem-1))) { return log2i_floor(nElem); }
  else { return log2i_floor(nElem) + 1; }
}



} // namespace util

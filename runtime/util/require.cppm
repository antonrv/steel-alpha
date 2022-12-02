export module SteelRT.Util.Require;

import SteelRT.Util.Types;

import <type_traits>;

namespace util {


export
template <typename T>
using req_t = std::enable_if_t<T::value, util::enabler_t>;

export
template <auto Val1, auto Val2>
struct same {
  static constexpr bool value = (Val1 == Val2);
};

export
template <auto Val1, auto Val2>
struct not_same {
  static constexpr bool value = (Val1 != Val2);
};

export
template <bool ExprResult>
struct is {
  static constexpr bool value = ExprResult;
};

} // namespace util

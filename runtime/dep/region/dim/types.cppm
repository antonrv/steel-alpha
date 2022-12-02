
export module SteelRT.Dep.Dim.Types;

import SteelRT.Util.Basic;

export import <array>;


export
namespace dep::dim {

template <std::size_t Dim>
using array_t = std::array<ulong_t, Dim>;

template <std::size_t Dim>
using array_range_t = std::array<range_t, Dim>;

template <std::size_t D>
struct identity {};

} // namespace dep::dim

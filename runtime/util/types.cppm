export module SteelRT.Util.Types;

export import <cstdint>;
export import <cstddef>;
export import <string>;

export
using uint_t = std::uint32_t;


export
using ulong_t = std::uint64_t;

export
using int_t = std::int32_t;

export
using uchar_t = std::uint8_t;

export
using ushort_t = std::uint16_t;

export
struct range_t { ulong_t begin = 0; ulong_t end = 0; };

export
using enum_uint_t = std::uint8_t;

export
using enum_event_t = enum_uint_t;

export
using enum_type_id_t = unsigned; // to univocally identify enum types (a compile time only type)

export
using counter_t = std::uint32_t;

export
using short_counter_t = std::uint8_t;

export
using depth_t = std::uint8_t;

export
using defer_t = std::uint8_t;

export
using thread_id_t = std::uint8_t;

export
using youth_t = counter_t;

export
using greed_t = std::uint8_t;

export
using id_set_t = std::uint32_t; // Encodes upto 32 app ids

export
using n_bits_t = std::uint8_t; // upto 256

export
using solved_mask_t = std::uint8_t; // Upto 8 args. Make it safer TODO

export
using arg_id_t = solved_mask_t;

export
using core_id_t = std::uint8_t;

export
struct err_t {};

export
using str_t = std::string;


namespace util {

export
template <auto... EnumVals>
struct identity {};

export
template <typename... Ts>
struct tuple_t {
  static constexpr std::size_t size() { return sizeof...(Ts); }
};


export
template <typename T>
struct is_tuple : std::false_type {};

export
template <typename... Ts>
struct is_tuple <tuple_t<Ts...>> : std::true_type {};

export
enum class enabler_t {};


} // namespace util


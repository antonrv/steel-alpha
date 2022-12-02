
export module SteelRT.Instrument.Ostream;

import SteelRT.Util.Types;
import SteelRT.Util.Require;
import SteelRT.Util.Sequence;

import SteelRT.Instrument.Predicates;
import SteelRT.Instrument.FwDeclarations;

import <array>;
import <tuple>;
import <vector>;
import <utility>;
import <memory>;
export import <iostream>;

// export
// std::ostream& operator<<(std::ostream& os, std::uint8_t c) {
//   os << static_cast<unsigned>(c);
//   return os;
// }

// export
// template <
//   typename T,
//   util::req_t<
//     std::conjunction<
//       std::is_enum<T>,
//       instr::event::is_instrumentable<T>
//     >
//   >...
// >
// std::ostream& operator<<(std::ostream& os, T c) {
//   os << c);
//   return os;
// }

export
template <typename EnumT, EnumT... EnumVals>
std::ostream& operator<<(std::ostream& os, util::sequence::enum_t<EnumT, EnumVals...>) {
  ((os << instr::event::value<EnumVals>::name << ','), ... );
  return os;
}


export
template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T,N>& arr) {
  // os << "(" << &arr << ")" << '[';
  os << '[';
  for(auto i=0u;i<N; ++i) {
    os << arr[i] << ',';
  }
  os << ']';
  return os;
}

export
template <typename T, typename DT>
std::ostream& operator<<(std::ostream& os, const std::unique_ptr<T,DT>& uptr) {
  os << "upt-" << uptr.get();
  return os;
}

// Overload for tuples
template <typename... TArgs>
std::ostream& operator<<(std::ostream& os, const std::tuple<TArgs...>& t);

template <typename TupleT, std::size_t... Ids>
std::ostream& print_tuple_args(std::ostream& os, const TupleT& tup, std::index_sequence<Ids...>) {
  os << '<';
  ((os << std::get<Ids>(tup) << ','), ... );
  os << '>';
  return os;
}

// Overload for pairs
export
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& t) {
  os << '<' << t.first << ',' << t.second << '>';
  return os;
}

export
template <typename... TArgs>
std::ostream& operator<<(std::ostream& os, const std::tuple<TArgs...>& t) {
  using IdxSeq = std::index_sequence_for<TArgs...>;
  print_tuple_args(os, t, IdxSeq{});
  return os;
}

// NOT WORKING
// template <typename T, util::req_t< std::is_enum<T> > ... >
// std::ostream& operator<<(std::ostream& os, const T enumVal) {
//   os << "En" << static_cast<unsigned>(enumVal);
//   return os;
// }
// 
// template <typename T, util::req_t< std::is_same<T, enum_uint_t> > ... >
// std::ostream& operator<<(std::ostream& os, const T val) {
//   os << "UI8:" << static_cast<unsigned>(val);
//   return os;
// }
// 
// template <typename T, util::req_t< std::is_same<T, std::int8_t> > ... >
// std::ostream& operator<<(std::ostream& os, const T val) {
//   os << "I8:" << static_cast<int>(val);
//   return os;
// }

// template <typename T, util::req_t< std::is_same<T, unsigned char> > ... >
// std::ostream& operator<<(std::ostream& os, const T& val) {
//   os << "UCh:" << static_cast<unsigned>(val);
//   return os;
// }

// template <typename T, util::req_t< std::is_same<T, char> > ... >
// std::ostream& operator<<(std::ostream& os, const T& val) {
//   os << "Ch:" << static_cast<int>(val);
//   return os;
// }

// Overload for vectors
export
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  os << '{';
  for(auto& v : vec) {
    os << v << ',';
  }
  os << '}';
  return os;
}

// Overload for integer sequences of integers
export
template <std::size_t... IdxArgs>
std::ostream& operator<<(std::ostream& os, std::index_sequence<IdxArgs...>) {
  os << "IdS["<< sizeof...(IdxArgs) << "] : <";
  ((os << IdxArgs << ','), ... );
  os << '>';
  return os;
}

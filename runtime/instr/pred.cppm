export module SteelRT.Instrument.Predicates;

  export import SteelRT.Instrument.EnabledEvents;

import SteelRT.Util.Tuple;
import SteelRT.Instrument.FwDeclarations;


import <type_traits>;

export
namespace instr::event {

// template <typename... EnabledTs>

template <typename EventT>
struct is_enabled : util::tuple::contains<EventT, enabled_tuple> {};

template <typename EventT>
struct is_instrumentable {
  static_assert( std::is_enum_v<EventT> );
  static constexpr bool value = type<EventT>::instrumentable;
};

} // namespace instr::event

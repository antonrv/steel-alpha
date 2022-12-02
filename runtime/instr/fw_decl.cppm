export module SteelRT.Instrument.FwDeclarations;

import SteelRT.Util.Types;

export
namespace instr::event {

// enum class ctxt_active : enum_uint_t; not needed

template <typename EnumT> struct type { static constexpr bool instrumentable = false; };
template <auto EnumV> struct value;
// template <typename EventT> struct is_enabled;

} // namespace instr::event

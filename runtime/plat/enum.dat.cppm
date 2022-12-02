export module Plat.EnumDefinitions;
import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Sequence;
import SteelRT.Instrument.FwDeclarations;

export
namespace plat{


//////// processor
enum class processor : enum_uint_t {smp0 = 2};
using enabled_processors = util::sequence::enum_t<processor, processor::smp0>;
}
// namespace plat

export
namespace instr::event{
template <> struct type<plat::processor>{
static constexpr const char * name = "processor";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};
template <> struct value<plat::processor::smp0>{static constexpr const char * name = "smp0"; };
}
// namespace instr::event

export module App.EnumDefinitions;
import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Sequence;
import SteelRT.Instrument.FwDeclarations;
import <cstdio>;

export
namespace app{


//////// call
enum class call : enum_uint_t {ro_region = 2,rw_region = 3};
using enabled_calls = util::sequence::enum_t<call, call::ro_region,call::rw_region>;


//////// id
enum class id : enum_uint_t {ro_region = 2,rw_region = 3};
using enabled_ids = util::sequence::enum_t<id, id::ro_region,id::rw_region>;


//////// impl
enum class impl : enum_uint_t {ro_region = 2,rw_region = 3};
using enabled_impls = util::sequence::enum_t<impl, impl::ro_region,impl::rw_region>;
}
// namespace app

export
namespace instr::event{
template <> struct type<app::call>{
static constexpr const char * name = "call";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};
template <> struct value<app::call::ro_region>{static constexpr const char * name = "ro_region"; };
template <> struct value<app::call::rw_region>{static constexpr const char * name = "rw_region"; };
template <> struct type<app::id>{
static constexpr const char * name = "id";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};
template <> struct value<app::id::ro_region>{static constexpr const char * name = "ro_region"; };
template <> struct value<app::id::rw_region>{static constexpr const char * name = "rw_region"; };
template <> struct type<app::impl>{
static constexpr const char * name = "impl";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};
template <> struct value<app::impl::ro_region>{static constexpr const char * name = "ro_region"; };
template <> struct value<app::impl::rw_region>{static constexpr const char * name = "rw_region"; };
}
// namespace instr::event

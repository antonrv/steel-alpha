//////////////////////////////////////
// 
// Autogenerated file. Do not modify. 
// 
//////////////////////////////////////

export module App.Enum;
import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Sequence;
import SteelRT.Instrument.FwDeclarations;
import <cstdio>;
export
namespace app{enum class call : enum_uint_t {bar_zeeapp_0 = 2};using enabled_calls = util::sequence::enum_t<call,call::bar_zeeapp_0>;}
export
namespace instrument::event{template <> struct type<app::call>{static constexpr const char * name = "call";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};template <> struct value<app::call::bar_zeeapp_0>{static constexpr const char * name = "bar_zeeapp_0";}
;}export
namespace app{enum class id : enum_uint_t {barapp = 2,zeeapp = 3};using enabled_ids = util::sequence::enum_t<id,id::barapp,id::zeeapp>;}
export
namespace instrument::event{template <> struct type<app::id>{static constexpr const char * name = "id";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};template <> struct value<app::id::barapp>{static constexpr const char * name = "barapp";}
;template <> struct value<app::id::zeeapp>{static constexpr const char * name = "zeeapp";}
;}export
namespace app{enum class impl : enum_uint_t {bar = 2,zee = 3};using enabled_impls = util::sequence::enum_t<impl,impl::bar,impl::zee>;}
export
namespace instrument::event{template <> struct type<app::impl>{static constexpr const char * name = "impl";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};template <> struct value<app::impl::bar>{static constexpr const char * name = "bar";}
;template <> struct value<app::impl::zee>{static constexpr const char * name = "zee";}
;}
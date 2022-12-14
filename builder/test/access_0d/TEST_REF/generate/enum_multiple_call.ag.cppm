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
namespace app{enum class call : enum_uint_t {caller1_ro_multiple_call_bar_ro_multiple_call_app_1 = 2,caller1_ro_multiple_call_foo_ro_multiple_call_app_0 = 3,caller1_ro_multiple_call_foo_ro_multiple_call_app_2 = 4,caller1_rw_multiple_call_bar_rw_multiple_call_app_1 = 5,caller1_rw_multiple_call_foo_rw_multiple_call_app_0 = 6,caller1_rw_multiple_call_foo_rw_multiple_call_app_2 = 7,caller2_ro_multiple_call_bar_ro_multiple_call_app_1 = 8,caller2_ro_multiple_call_foo_ro_multiple_call_app_0 = 9,caller2_ro_multiple_call_foo_ro_multiple_call_app_2 = 10,caller2_rw_multiple_call_bar_rw_multiple_call_app_1 = 11,caller2_rw_multiple_call_foo_rw_multiple_call_app_0 = 12,caller2_rw_multiple_call_foo_rw_multiple_call_app_2 = 13};using enabled_calls = util::sequence::enum_t<call,call::caller1_ro_multiple_call_bar_ro_multiple_call_app_1,call::caller1_ro_multiple_call_foo_ro_multiple_call_app_0,call::caller1_ro_multiple_call_foo_ro_multiple_call_app_2,call::caller1_rw_multiple_call_bar_rw_multiple_call_app_1,call::caller1_rw_multiple_call_foo_rw_multiple_call_app_0,call::caller1_rw_multiple_call_foo_rw_multiple_call_app_2,call::caller2_ro_multiple_call_bar_ro_multiple_call_app_1,call::caller2_ro_multiple_call_foo_ro_multiple_call_app_0,call::caller2_ro_multiple_call_foo_ro_multiple_call_app_2,call::caller2_rw_multiple_call_bar_rw_multiple_call_app_1,call::caller2_rw_multiple_call_foo_rw_multiple_call_app_0,call::caller2_rw_multiple_call_foo_rw_multiple_call_app_2>;}
export
namespace instrument::event{template <> struct type<app::call>{static constexpr const char * name = "call";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};template <> struct value<app::call::caller1_ro_multiple_call_bar_ro_multiple_call_app_1>{static constexpr const char * name = "caller1_ro_multiple_call_bar_ro_multiple_call_app_1";}
;template <> struct value<app::call::caller1_ro_multiple_call_foo_ro_multiple_call_app_0>{static constexpr const char * name = "caller1_ro_multiple_call_foo_ro_multiple_call_app_0";}
;template <> struct value<app::call::caller1_ro_multiple_call_foo_ro_multiple_call_app_2>{static constexpr const char * name = "caller1_ro_multiple_call_foo_ro_multiple_call_app_2";}
;template <> struct value<app::call::caller1_rw_multiple_call_bar_rw_multiple_call_app_1>{static constexpr const char * name = "caller1_rw_multiple_call_bar_rw_multiple_call_app_1";}
;template <> struct value<app::call::caller1_rw_multiple_call_foo_rw_multiple_call_app_0>{static constexpr const char * name = "caller1_rw_multiple_call_foo_rw_multiple_call_app_0";}
;template <> struct value<app::call::caller1_rw_multiple_call_foo_rw_multiple_call_app_2>{static constexpr const char * name = "caller1_rw_multiple_call_foo_rw_multiple_call_app_2";}
;template <> struct value<app::call::caller2_ro_multiple_call_bar_ro_multiple_call_app_1>{static constexpr const char * name = "caller2_ro_multiple_call_bar_ro_multiple_call_app_1";}
;template <> struct value<app::call::caller2_ro_multiple_call_foo_ro_multiple_call_app_0>{static constexpr const char * name = "caller2_ro_multiple_call_foo_ro_multiple_call_app_0";}
;template <> struct value<app::call::caller2_ro_multiple_call_foo_ro_multiple_call_app_2>{static constexpr const char * name = "caller2_ro_multiple_call_foo_ro_multiple_call_app_2";}
;template <> struct value<app::call::caller2_rw_multiple_call_bar_rw_multiple_call_app_1>{static constexpr const char * name = "caller2_rw_multiple_call_bar_rw_multiple_call_app_1";}
;template <> struct value<app::call::caller2_rw_multiple_call_foo_rw_multiple_call_app_0>{static constexpr const char * name = "caller2_rw_multiple_call_foo_rw_multiple_call_app_0";}
;template <> struct value<app::call::caller2_rw_multiple_call_foo_rw_multiple_call_app_2>{static constexpr const char * name = "caller2_rw_multiple_call_foo_rw_multiple_call_app_2";}
;}export
namespace app{enum class id : enum_uint_t {bar_ro_multiple_call_app = 2,bar_rw_multiple_call_app = 3,caller1_ro_multiple_call = 4,caller1_rw_multiple_call = 5,caller2_ro_multiple_call = 6,caller2_rw_multiple_call = 7,foo_ro_multiple_call_app = 8,foo_rw_multiple_call_app = 9};using enabled_ids = util::sequence::enum_t<id,id::bar_ro_multiple_call_app,id::bar_rw_multiple_call_app,id::caller1_ro_multiple_call,id::caller1_rw_multiple_call,id::caller2_ro_multiple_call,id::caller2_rw_multiple_call,id::foo_ro_multiple_call_app,id::foo_rw_multiple_call_app>;}
export
namespace instrument::event{template <> struct type<app::id>{static constexpr const char * name = "id";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};template <> struct value<app::id::bar_ro_multiple_call_app>{static constexpr const char * name = "bar_ro_multiple_call_app";}
;template <> struct value<app::id::bar_rw_multiple_call_app>{static constexpr const char * name = "bar_rw_multiple_call_app";}
;template <> struct value<app::id::caller1_ro_multiple_call>{static constexpr const char * name = "caller1_ro_multiple_call";}
;template <> struct value<app::id::caller1_rw_multiple_call>{static constexpr const char * name = "caller1_rw_multiple_call";}
;template <> struct value<app::id::caller2_ro_multiple_call>{static constexpr const char * name = "caller2_ro_multiple_call";}
;template <> struct value<app::id::caller2_rw_multiple_call>{static constexpr const char * name = "caller2_rw_multiple_call";}
;template <> struct value<app::id::foo_ro_multiple_call_app>{static constexpr const char * name = "foo_ro_multiple_call_app";}
;template <> struct value<app::id::foo_rw_multiple_call_app>{static constexpr const char * name = "foo_rw_multiple_call_app";}
;}export
namespace app{enum class impl : enum_uint_t {bar_ro_multiple = 2,bar_rw_multiple_call = 3,caller1_ro_multiple_call = 4,caller1_rw_multiple_call = 5,caller2_ro_multiple_call = 6,caller2_rw_multiple_call = 7,foo_ro_multiple = 8,foo_rw_multiple_call = 9};using enabled_impls = util::sequence::enum_t<impl,impl::bar_ro_multiple,impl::bar_rw_multiple_call,impl::caller1_ro_multiple_call,impl::caller1_rw_multiple_call,impl::caller2_ro_multiple_call,impl::caller2_rw_multiple_call,impl::foo_ro_multiple,impl::foo_rw_multiple_call>;}
export
namespace instrument::event{template <> struct type<app::impl>{static constexpr const char * name = "impl";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};template <> struct value<app::impl::bar_ro_multiple>{static constexpr const char * name = "bar_ro_multiple";}
;template <> struct value<app::impl::bar_rw_multiple_call>{static constexpr const char * name = "bar_rw_multiple_call";}
;template <> struct value<app::impl::caller1_ro_multiple_call>{static constexpr const char * name = "caller1_ro_multiple_call";}
;template <> struct value<app::impl::caller1_rw_multiple_call>{static constexpr const char * name = "caller1_rw_multiple_call";}
;template <> struct value<app::impl::caller2_ro_multiple_call>{static constexpr const char * name = "caller2_ro_multiple_call";}
;template <> struct value<app::impl::caller2_rw_multiple_call>{static constexpr const char * name = "caller2_rw_multiple_call";}
;template <> struct value<app::impl::foo_ro_multiple>{static constexpr const char * name = "foo_ro_multiple";}
;template <> struct value<app::impl::foo_rw_multiple_call>{static constexpr const char * name = "foo_rw_multiple_call";}
;}
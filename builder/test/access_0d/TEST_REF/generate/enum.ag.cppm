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
namespace app{enum class call : enum_uint_t {caller1_ro_multiple_call_bar_ro_multiple_call_app_1 = 2,caller1_ro_multiple_call_foo_ro_multiple_call_app_0 = 3,caller1_ro_multiple_call_foo_ro_multiple_call_app_2 = 4,caller1_ro_multiple_point_foo_ro_multiple_point_app_0 = 5,caller1_ro_multiple_point_foo_ro_multiple_point_app_1 = 6,caller1_ro_multiple_point_foo_ro_multiple_point_app_2 = 7,caller1_rw_multiple_call_bar_rw_multiple_call_app_1 = 8,caller1_rw_multiple_call_foo_rw_multiple_call_app_0 = 9,caller1_rw_multiple_call_foo_rw_multiple_call_app_2 = 10,caller1_rw_multiple_point_foo_rw_multiple_point_app_0 = 11,caller1_rw_multiple_point_foo_rw_multiple_point_app_1 = 12,caller1_rw_multiple_point_foo_rw_multiple_point_app_2 = 13,caller2_ro_multiple_call_bar_ro_multiple_call_app_1 = 14,caller2_ro_multiple_call_foo_ro_multiple_call_app_0 = 15,caller2_ro_multiple_call_foo_ro_multiple_call_app_2 = 16,caller2_ro_multiple_point_foo_ro_multiple_point_app_0 = 17,caller2_ro_multiple_point_foo_ro_multiple_point_app_1 = 18,caller2_ro_multiple_point_foo_ro_multiple_point_app_2 = 19,caller2_rw_multiple_call_bar_rw_multiple_call_app_1 = 20,caller2_rw_multiple_call_foo_rw_multiple_call_app_0 = 21,caller2_rw_multiple_call_foo_rw_multiple_call_app_2 = 22,caller2_rw_multiple_point_foo_rw_multiple_point_app_0 = 23,caller2_rw_multiple_point_foo_rw_multiple_point_app_1 = 24,caller2_rw_multiple_point_foo_rw_multiple_point_app_2 = 25,caller_foo_ro_arit_1_foo_ro_arit_app_0 = 26,caller_foo_ro_arit_2_foo_ro_arit_app_0 = 27,caller_foo_rw_arit_1_foo_rw_arit_app_0 = 28,caller_foo_rw_arit_2_foo_rw_arit_app_0 = 29};using enabled_calls = util::sequence::enum_t<call,call::caller1_ro_multiple_call_bar_ro_multiple_call_app_1,call::caller1_ro_multiple_call_foo_ro_multiple_call_app_0,call::caller1_ro_multiple_call_foo_ro_multiple_call_app_2,call::caller1_ro_multiple_point_foo_ro_multiple_point_app_0,call::caller1_ro_multiple_point_foo_ro_multiple_point_app_1,call::caller1_ro_multiple_point_foo_ro_multiple_point_app_2,call::caller1_rw_multiple_call_bar_rw_multiple_call_app_1,call::caller1_rw_multiple_call_foo_rw_multiple_call_app_0,call::caller1_rw_multiple_call_foo_rw_multiple_call_app_2,call::caller1_rw_multiple_point_foo_rw_multiple_point_app_0,call::caller1_rw_multiple_point_foo_rw_multiple_point_app_1,call::caller1_rw_multiple_point_foo_rw_multiple_point_app_2,call::caller2_ro_multiple_call_bar_ro_multiple_call_app_1,call::caller2_ro_multiple_call_foo_ro_multiple_call_app_0,call::caller2_ro_multiple_call_foo_ro_multiple_call_app_2,call::caller2_ro_multiple_point_foo_ro_multiple_point_app_0,call::caller2_ro_multiple_point_foo_ro_multiple_point_app_1,call::caller2_ro_multiple_point_foo_ro_multiple_point_app_2,call::caller2_rw_multiple_call_bar_rw_multiple_call_app_1,call::caller2_rw_multiple_call_foo_rw_multiple_call_app_0,call::caller2_rw_multiple_call_foo_rw_multiple_call_app_2,call::caller2_rw_multiple_point_foo_rw_multiple_point_app_0,call::caller2_rw_multiple_point_foo_rw_multiple_point_app_1,call::caller2_rw_multiple_point_foo_rw_multiple_point_app_2,call::caller_foo_ro_arit_1_foo_ro_arit_app_0,call::caller_foo_ro_arit_2_foo_ro_arit_app_0,call::caller_foo_rw_arit_1_foo_rw_arit_app_0,call::caller_foo_rw_arit_2_foo_rw_arit_app_0>;}
export
namespace instrument::event{template <> struct type<app::call>{static constexpr const char * name = "call";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};template <> struct value<app::call::caller1_ro_multiple_call_bar_ro_multiple_call_app_1>{static constexpr const char * name = "caller1_ro_multiple_call_bar_ro_multiple_call_app_1";}
;template <> struct value<app::call::caller1_ro_multiple_call_foo_ro_multiple_call_app_0>{static constexpr const char * name = "caller1_ro_multiple_call_foo_ro_multiple_call_app_0";}
;template <> struct value<app::call::caller1_ro_multiple_call_foo_ro_multiple_call_app_2>{static constexpr const char * name = "caller1_ro_multiple_call_foo_ro_multiple_call_app_2";}
;template <> struct value<app::call::caller1_ro_multiple_point_foo_ro_multiple_point_app_0>{static constexpr const char * name = "caller1_ro_multiple_point_foo_ro_multiple_point_app_0";}
;template <> struct value<app::call::caller1_ro_multiple_point_foo_ro_multiple_point_app_1>{static constexpr const char * name = "caller1_ro_multiple_point_foo_ro_multiple_point_app_1";}
;template <> struct value<app::call::caller1_ro_multiple_point_foo_ro_multiple_point_app_2>{static constexpr const char * name = "caller1_ro_multiple_point_foo_ro_multiple_point_app_2";}
;template <> struct value<app::call::caller1_rw_multiple_call_bar_rw_multiple_call_app_1>{static constexpr const char * name = "caller1_rw_multiple_call_bar_rw_multiple_call_app_1";}
;template <> struct value<app::call::caller1_rw_multiple_call_foo_rw_multiple_call_app_0>{static constexpr const char * name = "caller1_rw_multiple_call_foo_rw_multiple_call_app_0";}
;template <> struct value<app::call::caller1_rw_multiple_call_foo_rw_multiple_call_app_2>{static constexpr const char * name = "caller1_rw_multiple_call_foo_rw_multiple_call_app_2";}
;template <> struct value<app::call::caller1_rw_multiple_point_foo_rw_multiple_point_app_0>{static constexpr const char * name = "caller1_rw_multiple_point_foo_rw_multiple_point_app_0";}
;template <> struct value<app::call::caller1_rw_multiple_point_foo_rw_multiple_point_app_1>{static constexpr const char * name = "caller1_rw_multiple_point_foo_rw_multiple_point_app_1";}
;template <> struct value<app::call::caller1_rw_multiple_point_foo_rw_multiple_point_app_2>{static constexpr const char * name = "caller1_rw_multiple_point_foo_rw_multiple_point_app_2";}
;template <> struct value<app::call::caller2_ro_multiple_call_bar_ro_multiple_call_app_1>{static constexpr const char * name = "caller2_ro_multiple_call_bar_ro_multiple_call_app_1";}
;template <> struct value<app::call::caller2_ro_multiple_call_foo_ro_multiple_call_app_0>{static constexpr const char * name = "caller2_ro_multiple_call_foo_ro_multiple_call_app_0";}
;template <> struct value<app::call::caller2_ro_multiple_call_foo_ro_multiple_call_app_2>{static constexpr const char * name = "caller2_ro_multiple_call_foo_ro_multiple_call_app_2";}
;template <> struct value<app::call::caller2_ro_multiple_point_foo_ro_multiple_point_app_0>{static constexpr const char * name = "caller2_ro_multiple_point_foo_ro_multiple_point_app_0";}
;template <> struct value<app::call::caller2_ro_multiple_point_foo_ro_multiple_point_app_1>{static constexpr const char * name = "caller2_ro_multiple_point_foo_ro_multiple_point_app_1";}
;template <> struct value<app::call::caller2_ro_multiple_point_foo_ro_multiple_point_app_2>{static constexpr const char * name = "caller2_ro_multiple_point_foo_ro_multiple_point_app_2";}
;template <> struct value<app::call::caller2_rw_multiple_call_bar_rw_multiple_call_app_1>{static constexpr const char * name = "caller2_rw_multiple_call_bar_rw_multiple_call_app_1";}
;template <> struct value<app::call::caller2_rw_multiple_call_foo_rw_multiple_call_app_0>{static constexpr const char * name = "caller2_rw_multiple_call_foo_rw_multiple_call_app_0";}
;template <> struct value<app::call::caller2_rw_multiple_call_foo_rw_multiple_call_app_2>{static constexpr const char * name = "caller2_rw_multiple_call_foo_rw_multiple_call_app_2";}
;template <> struct value<app::call::caller2_rw_multiple_point_foo_rw_multiple_point_app_0>{static constexpr const char * name = "caller2_rw_multiple_point_foo_rw_multiple_point_app_0";}
;template <> struct value<app::call::caller2_rw_multiple_point_foo_rw_multiple_point_app_1>{static constexpr const char * name = "caller2_rw_multiple_point_foo_rw_multiple_point_app_1";}
;template <> struct value<app::call::caller2_rw_multiple_point_foo_rw_multiple_point_app_2>{static constexpr const char * name = "caller2_rw_multiple_point_foo_rw_multiple_point_app_2";}
;template <> struct value<app::call::caller_foo_ro_arit_1_foo_ro_arit_app_0>{static constexpr const char * name = "caller_foo_ro_arit_1_foo_ro_arit_app_0";}
;template <> struct value<app::call::caller_foo_ro_arit_2_foo_ro_arit_app_0>{static constexpr const char * name = "caller_foo_ro_arit_2_foo_ro_arit_app_0";}
;template <> struct value<app::call::caller_foo_rw_arit_1_foo_rw_arit_app_0>{static constexpr const char * name = "caller_foo_rw_arit_1_foo_rw_arit_app_0";}
;template <> struct value<app::call::caller_foo_rw_arit_2_foo_rw_arit_app_0>{static constexpr const char * name = "caller_foo_rw_arit_2_foo_rw_arit_app_0";}
;}export
namespace app{enum class id : enum_uint_t {bar_ro_multiple_call_app = 2,bar_rw_multiple_call_app = 3,caller1_ro_multiple_call = 4,caller1_ro_multiple_point = 5,caller1_rw_multiple_call = 6,caller1_rw_multiple_point = 7,caller2_ro_multiple_call = 8,caller2_ro_multiple_point = 9,caller2_rw_multiple_call = 10,caller2_rw_multiple_point = 11,caller_foo_ro_arit_1 = 12,caller_foo_ro_arit_2 = 13,caller_foo_rw_arit_1 = 14,caller_foo_rw_arit_2 = 15,foo_ro_arit_app = 16,foo_ro_multiple_call_app = 17,foo_ro_multiple_point_app = 18,foo_rw_arit_app = 19,foo_rw_multiple_call_app = 20,foo_rw_multiple_point_app = 21};using enabled_ids = util::sequence::enum_t<id,id::bar_ro_multiple_call_app,id::bar_rw_multiple_call_app,id::caller1_ro_multiple_call,id::caller1_ro_multiple_point,id::caller1_rw_multiple_call,id::caller1_rw_multiple_point,id::caller2_ro_multiple_call,id::caller2_ro_multiple_point,id::caller2_rw_multiple_call,id::caller2_rw_multiple_point,id::caller_foo_ro_arit_1,id::caller_foo_ro_arit_2,id::caller_foo_rw_arit_1,id::caller_foo_rw_arit_2,id::foo_ro_arit_app,id::foo_ro_multiple_call_app,id::foo_ro_multiple_point_app,id::foo_rw_arit_app,id::foo_rw_multiple_call_app,id::foo_rw_multiple_point_app>;}
export
namespace instrument::event{template <> struct type<app::id>{static constexpr const char * name = "id";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};template <> struct value<app::id::bar_ro_multiple_call_app>{static constexpr const char * name = "bar_ro_multiple_call_app";}
;template <> struct value<app::id::bar_rw_multiple_call_app>{static constexpr const char * name = "bar_rw_multiple_call_app";}
;template <> struct value<app::id::caller1_ro_multiple_call>{static constexpr const char * name = "caller1_ro_multiple_call";}
;template <> struct value<app::id::caller1_ro_multiple_point>{static constexpr const char * name = "caller1_ro_multiple_point";}
;template <> struct value<app::id::caller1_rw_multiple_call>{static constexpr const char * name = "caller1_rw_multiple_call";}
;template <> struct value<app::id::caller1_rw_multiple_point>{static constexpr const char * name = "caller1_rw_multiple_point";}
;template <> struct value<app::id::caller2_ro_multiple_call>{static constexpr const char * name = "caller2_ro_multiple_call";}
;template <> struct value<app::id::caller2_ro_multiple_point>{static constexpr const char * name = "caller2_ro_multiple_point";}
;template <> struct value<app::id::caller2_rw_multiple_call>{static constexpr const char * name = "caller2_rw_multiple_call";}
;template <> struct value<app::id::caller2_rw_multiple_point>{static constexpr const char * name = "caller2_rw_multiple_point";}
;template <> struct value<app::id::caller_foo_ro_arit_1>{static constexpr const char * name = "caller_foo_ro_arit_1";}
;template <> struct value<app::id::caller_foo_ro_arit_2>{static constexpr const char * name = "caller_foo_ro_arit_2";}
;template <> struct value<app::id::caller_foo_rw_arit_1>{static constexpr const char * name = "caller_foo_rw_arit_1";}
;template <> struct value<app::id::caller_foo_rw_arit_2>{static constexpr const char * name = "caller_foo_rw_arit_2";}
;template <> struct value<app::id::foo_ro_arit_app>{static constexpr const char * name = "foo_ro_arit_app";}
;template <> struct value<app::id::foo_ro_multiple_call_app>{static constexpr const char * name = "foo_ro_multiple_call_app";}
;template <> struct value<app::id::foo_ro_multiple_point_app>{static constexpr const char * name = "foo_ro_multiple_point_app";}
;template <> struct value<app::id::foo_rw_arit_app>{static constexpr const char * name = "foo_rw_arit_app";}
;template <> struct value<app::id::foo_rw_multiple_call_app>{static constexpr const char * name = "foo_rw_multiple_call_app";}
;template <> struct value<app::id::foo_rw_multiple_point_app>{static constexpr const char * name = "foo_rw_multiple_point_app";}
;}export
namespace app{enum class impl : enum_uint_t {bar_ro_multiple = 2,bar_rw_multiple_call = 3,caller1_ro_multiple_call = 4,caller1_ro_multiple_point = 5,caller1_rw_multiple_call = 6,caller1_rw_multiple_point = 7,caller2_ro_multiple_call = 8,caller2_ro_multiple_point = 9,caller2_rw_multiple_call = 10,caller2_rw_multiple_point = 11,caller_foo_ro_arit_1 = 12,caller_foo_ro_arit_2 = 13,caller_foo_rw_arit_1 = 14,caller_foo_rw_arit_2 = 15,foo_ro_arit = 16,foo_ro_multiple = 17,foo_ro_multiple_point = 18,foo_rw_arit = 19,foo_rw_multiple_call = 20,foo_rw_multiple_point = 21};using enabled_impls = util::sequence::enum_t<impl,impl::bar_ro_multiple,impl::bar_rw_multiple_call,impl::caller1_ro_multiple_call,impl::caller1_ro_multiple_point,impl::caller1_rw_multiple_call,impl::caller1_rw_multiple_point,impl::caller2_ro_multiple_call,impl::caller2_ro_multiple_point,impl::caller2_rw_multiple_call,impl::caller2_rw_multiple_point,impl::caller_foo_ro_arit_1,impl::caller_foo_ro_arit_2,impl::caller_foo_rw_arit_1,impl::caller_foo_rw_arit_2,impl::foo_ro_arit,impl::foo_ro_multiple,impl::foo_ro_multiple_point,impl::foo_rw_arit,impl::foo_rw_multiple_call,impl::foo_rw_multiple_point>;}
export
namespace instrument::event{template <> struct type<app::impl>{static constexpr const char * name = "impl";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};template <> struct value<app::impl::bar_ro_multiple>{static constexpr const char * name = "bar_ro_multiple";}
;template <> struct value<app::impl::bar_rw_multiple_call>{static constexpr const char * name = "bar_rw_multiple_call";}
;template <> struct value<app::impl::caller1_ro_multiple_call>{static constexpr const char * name = "caller1_ro_multiple_call";}
;template <> struct value<app::impl::caller1_ro_multiple_point>{static constexpr const char * name = "caller1_ro_multiple_point";}
;template <> struct value<app::impl::caller1_rw_multiple_call>{static constexpr const char * name = "caller1_rw_multiple_call";}
;template <> struct value<app::impl::caller1_rw_multiple_point>{static constexpr const char * name = "caller1_rw_multiple_point";}
;template <> struct value<app::impl::caller2_ro_multiple_call>{static constexpr const char * name = "caller2_ro_multiple_call";}
;template <> struct value<app::impl::caller2_ro_multiple_point>{static constexpr const char * name = "caller2_ro_multiple_point";}
;template <> struct value<app::impl::caller2_rw_multiple_call>{static constexpr const char * name = "caller2_rw_multiple_call";}
;template <> struct value<app::impl::caller2_rw_multiple_point>{static constexpr const char * name = "caller2_rw_multiple_point";}
;template <> struct value<app::impl::caller_foo_ro_arit_1>{static constexpr const char * name = "caller_foo_ro_arit_1";}
;template <> struct value<app::impl::caller_foo_ro_arit_2>{static constexpr const char * name = "caller_foo_ro_arit_2";}
;template <> struct value<app::impl::caller_foo_rw_arit_1>{static constexpr const char * name = "caller_foo_rw_arit_1";}
;template <> struct value<app::impl::caller_foo_rw_arit_2>{static constexpr const char * name = "caller_foo_rw_arit_2";}
;template <> struct value<app::impl::foo_ro_arit>{static constexpr const char * name = "foo_ro_arit";}
;template <> struct value<app::impl::foo_ro_multiple>{static constexpr const char * name = "foo_ro_multiple";}
;template <> struct value<app::impl::foo_ro_multiple_point>{static constexpr const char * name = "foo_ro_multiple_point";}
;template <> struct value<app::impl::foo_rw_arit>{static constexpr const char * name = "foo_rw_arit";}
;template <> struct value<app::impl::foo_rw_multiple_call>{static constexpr const char * name = "foo_rw_multiple_call";}
;template <> struct value<app::impl::foo_rw_multiple_point>{static constexpr const char * name = "foo_rw_multiple_point";}
;}
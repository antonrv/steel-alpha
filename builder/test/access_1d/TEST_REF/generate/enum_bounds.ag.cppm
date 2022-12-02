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
namespace app{enum class call : enum_uint_t {caller_geq_sub_foo_geq_sub_0 = 2,caller_gt_sub_foo_gt_sub_0 = 3,caller_leq_add_foo_leq_add_0 = 4,caller_lt_add_foo_lt_add_0 = 5};using enabled_calls = util::sequence::enum_t<call,call::caller_geq_sub_foo_geq_sub_0,call::caller_gt_sub_foo_gt_sub_0,call::caller_leq_add_foo_leq_add_0,call::caller_lt_add_foo_lt_add_0>;}
export
namespace instrument::event{template <> struct type<app::call>{static constexpr const char * name = "call";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};template <> struct value<app::call::caller_geq_sub_foo_geq_sub_0>{static constexpr const char * name = "caller_geq_sub_foo_geq_sub_0";}
;template <> struct value<app::call::caller_gt_sub_foo_gt_sub_0>{static constexpr const char * name = "caller_gt_sub_foo_gt_sub_0";}
;template <> struct value<app::call::caller_leq_add_foo_leq_add_0>{static constexpr const char * name = "caller_leq_add_foo_leq_add_0";}
;template <> struct value<app::call::caller_lt_add_foo_lt_add_0>{static constexpr const char * name = "caller_lt_add_foo_lt_add_0";}
;}export
namespace app{enum class id : enum_uint_t {caller_geq_sub = 2,caller_gt_sub = 3,caller_leq_add = 4,caller_lt_add = 5,foo_geq_sub = 6,foo_gt_sub = 7,foo_leq_add = 8,foo_lt_add = 9};using enabled_ids = util::sequence::enum_t<id,id::caller_geq_sub,id::caller_gt_sub,id::caller_leq_add,id::caller_lt_add,id::foo_geq_sub,id::foo_gt_sub,id::foo_leq_add,id::foo_lt_add>;}
export
namespace instrument::event{template <> struct type<app::id>{static constexpr const char * name = "id";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};template <> struct value<app::id::caller_geq_sub>{static constexpr const char * name = "caller_geq_sub";}
;template <> struct value<app::id::caller_gt_sub>{static constexpr const char * name = "caller_gt_sub";}
;template <> struct value<app::id::caller_leq_add>{static constexpr const char * name = "caller_leq_add";}
;template <> struct value<app::id::caller_lt_add>{static constexpr const char * name = "caller_lt_add";}
;template <> struct value<app::id::foo_geq_sub>{static constexpr const char * name = "foo_geq_sub";}
;template <> struct value<app::id::foo_gt_sub>{static constexpr const char * name = "foo_gt_sub";}
;template <> struct value<app::id::foo_leq_add>{static constexpr const char * name = "foo_leq_add";}
;template <> struct value<app::id::foo_lt_add>{static constexpr const char * name = "foo_lt_add";}
;}export
namespace app{enum class impl : enum_uint_t {caller_geq_sub = 2,caller_gt_sub = 3,caller_leq_add = 4,caller_lt_add = 5,foo_geq_sub = 6,foo_gt_sub = 7,foo_leq_add = 8,foo_lt_add = 9};using enabled_impls = util::sequence::enum_t<impl,impl::caller_geq_sub,impl::caller_gt_sub,impl::caller_leq_add,impl::caller_lt_add,impl::foo_geq_sub,impl::foo_gt_sub,impl::foo_leq_add,impl::foo_lt_add>;}
export
namespace instrument::event{template <> struct type<app::impl>{static constexpr const char * name = "impl";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};template <> struct value<app::impl::caller_geq_sub>{static constexpr const char * name = "caller_geq_sub";}
;template <> struct value<app::impl::caller_gt_sub>{static constexpr const char * name = "caller_gt_sub";}
;template <> struct value<app::impl::caller_leq_add>{static constexpr const char * name = "caller_leq_add";}
;template <> struct value<app::impl::caller_lt_add>{static constexpr const char * name = "caller_lt_add";}
;template <> struct value<app::impl::foo_geq_sub>{static constexpr const char * name = "foo_geq_sub";}
;template <> struct value<app::impl::foo_gt_sub>{static constexpr const char * name = "foo_gt_sub";}
;template <> struct value<app::impl::foo_leq_add>{static constexpr const char * name = "foo_leq_add";}
;template <> struct value<app::impl::foo_lt_add>{static constexpr const char * name = "foo_lt_add";}
;}
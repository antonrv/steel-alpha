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
namespace app{enum class call : enum_uint_t {caller_blocks_foo_1d_blocks_app_0 = 2,caller_low_triangle_foo_low_tri_app_0 = 3,caller_rectangle_foo_rectangle_app_0 = 4,caller_up_triangle_foo_up_tri_app_0 = 5};using enabled_calls = util::sequence::enum_t<call,call::caller_blocks_foo_1d_blocks_app_0,call::caller_low_triangle_foo_low_tri_app_0,call::caller_rectangle_foo_rectangle_app_0,call::caller_up_triangle_foo_up_tri_app_0>;}
export
namespace instrument::event{template <> struct type<app::call>{static constexpr const char * name = "call";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};template <> struct value<app::call::caller_blocks_foo_1d_blocks_app_0>{static constexpr const char * name = "caller_blocks_foo_1d_blocks_app_0";}
;template <> struct value<app::call::caller_low_triangle_foo_low_tri_app_0>{static constexpr const char * name = "caller_low_triangle_foo_low_tri_app_0";}
;template <> struct value<app::call::caller_rectangle_foo_rectangle_app_0>{static constexpr const char * name = "caller_rectangle_foo_rectangle_app_0";}
;template <> struct value<app::call::caller_up_triangle_foo_up_tri_app_0>{static constexpr const char * name = "caller_up_triangle_foo_up_tri_app_0";}
;}export
namespace app{enum class id : enum_uint_t {caller_blocks = 2,caller_low_triangle = 3,caller_rectangle = 4,caller_up_triangle = 5,foo_1d_blocks_app = 6,foo_low_tri_app = 7,foo_rectangle_app = 8,foo_up_tri_app = 9};using enabled_ids = util::sequence::enum_t<id,id::caller_blocks,id::caller_low_triangle,id::caller_rectangle,id::caller_up_triangle,id::foo_1d_blocks_app,id::foo_low_tri_app,id::foo_rectangle_app,id::foo_up_tri_app>;}
export
namespace instrument::event{template <> struct type<app::id>{static constexpr const char * name = "id";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};template <> struct value<app::id::caller_blocks>{static constexpr const char * name = "caller_blocks";}
;template <> struct value<app::id::caller_low_triangle>{static constexpr const char * name = "caller_low_triangle";}
;template <> struct value<app::id::caller_rectangle>{static constexpr const char * name = "caller_rectangle";}
;template <> struct value<app::id::caller_up_triangle>{static constexpr const char * name = "caller_up_triangle";}
;template <> struct value<app::id::foo_1d_blocks_app>{static constexpr const char * name = "foo_1d_blocks_app";}
;template <> struct value<app::id::foo_low_tri_app>{static constexpr const char * name = "foo_low_tri_app";}
;template <> struct value<app::id::foo_rectangle_app>{static constexpr const char * name = "foo_rectangle_app";}
;template <> struct value<app::id::foo_up_tri_app>{static constexpr const char * name = "foo_up_tri_app";}
;}export
namespace app{enum class impl : enum_uint_t {caller_blocks = 2,caller_low_triangle = 3,caller_rectangle = 4,caller_up_triangle = 5,foo_blocks = 6,foo_low_triangle = 7,foo_rectangle = 8,foo_up_triangle = 9};using enabled_impls = util::sequence::enum_t<impl,impl::caller_blocks,impl::caller_low_triangle,impl::caller_rectangle,impl::caller_up_triangle,impl::foo_blocks,impl::foo_low_triangle,impl::foo_rectangle,impl::foo_up_triangle>;}
export
namespace instrument::event{template <> struct type<app::impl>{static constexpr const char * name = "impl";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};template <> struct value<app::impl::caller_blocks>{static constexpr const char * name = "caller_blocks";}
;template <> struct value<app::impl::caller_low_triangle>{static constexpr const char * name = "caller_low_triangle";}
;template <> struct value<app::impl::caller_rectangle>{static constexpr const char * name = "caller_rectangle";}
;template <> struct value<app::impl::caller_up_triangle>{static constexpr const char * name = "caller_up_triangle";}
;template <> struct value<app::impl::foo_blocks>{static constexpr const char * name = "foo_blocks";}
;template <> struct value<app::impl::foo_low_triangle>{static constexpr const char * name = "foo_low_triangle";}
;template <> struct value<app::impl::foo_rectangle>{static constexpr const char * name = "foo_rectangle";}
;template <> struct value<app::impl::foo_up_triangle>{static constexpr const char * name = "foo_up_triangle";}
;}
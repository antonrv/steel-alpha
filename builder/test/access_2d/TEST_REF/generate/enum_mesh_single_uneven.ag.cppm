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
namespace app{enum class call : enum_uint_t {caller_foo_write_mesh_uneven_0 = 2,caller_foo_write_mesh_uneven_1 = 3,caller_foo_write_mesh_uneven_2 = 4,caller_foo_write_mesh_uneven_3 = 5};using enabled_calls = util::sequence::enum_t<call,call::caller_foo_write_mesh_uneven_0,call::caller_foo_write_mesh_uneven_1,call::caller_foo_write_mesh_uneven_2,call::caller_foo_write_mesh_uneven_3>;}
export
namespace instrument::event{template <> struct type<app::call>{static constexpr const char * name = "call";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};template <> struct value<app::call::caller_foo_write_mesh_uneven_0>{static constexpr const char * name = "caller_foo_write_mesh_uneven_0";}
;template <> struct value<app::call::caller_foo_write_mesh_uneven_1>{static constexpr const char * name = "caller_foo_write_mesh_uneven_1";}
;template <> struct value<app::call::caller_foo_write_mesh_uneven_2>{static constexpr const char * name = "caller_foo_write_mesh_uneven_2";}
;template <> struct value<app::call::caller_foo_write_mesh_uneven_3>{static constexpr const char * name = "caller_foo_write_mesh_uneven_3";}
;}export
namespace app{enum class id : enum_uint_t {write_mesh_uneven = 2};using enabled_ids = util::sequence::enum_t<id,id::write_mesh_uneven>;}
export
namespace instrument::event{template <> struct type<app::id>{static constexpr const char * name = "id";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};template <> struct value<app::id::write_mesh_uneven>{static constexpr const char * name = "write_mesh_uneven";}
;}export
namespace app{enum class impl : enum_uint_t {caller_foo = 2,foo = 3};using enabled_impls = util::sequence::enum_t<impl,impl::caller_foo,impl::foo>;}
export
namespace instrument::event{template <> struct type<app::impl>{static constexpr const char * name = "impl";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};template <> struct value<app::impl::caller_foo>{static constexpr const char * name = "caller_foo";}
;template <> struct value<app::impl::foo>{static constexpr const char * name = "foo";}
;}
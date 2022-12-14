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
namespace app{enum class call : enum_uint_t {dot_prod_v2_dot_prod_app_0 = 2,dot_prod_v2_reduce_app_1 = 3};using enabled_calls = util::sequence::enum_t<call,call::dot_prod_v2_dot_prod_app_0,call::dot_prod_v2_reduce_app_1>;}
export
namespace instrument::event{template <> struct type<app::call>{static constexpr const char * name = "call";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};template <> struct value<app::call::dot_prod_v2_dot_prod_app_0>{static constexpr const char * name = "dot_prod_v2_dot_prod_app_0";}
;template <> struct value<app::call::dot_prod_v2_reduce_app_1>{static constexpr const char * name = "dot_prod_v2_reduce_app_1";}
;}export
namespace app{enum class id : enum_uint_t {dot_prod_app = 2,reduce_app = 3};using enabled_ids = util::sequence::enum_t<id,id::dot_prod_app,id::reduce_app>;}
export
namespace instrument::event{template <> struct type<app::id>{static constexpr const char * name = "id";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};template <> struct value<app::id::dot_prod_app>{static constexpr const char * name = "dot_prod_app";}
;template <> struct value<app::id::reduce_app>{static constexpr const char * name = "reduce_app";}
;}export
namespace app{enum class impl : enum_uint_t {dot_prod_v1 = 2,dot_prod_v2 = 3,reduce = 4};using enabled_impls = util::sequence::enum_t<impl,impl::dot_prod_v1,impl::dot_prod_v2,impl::reduce>;}
export
namespace instrument::event{template <> struct type<app::impl>{static constexpr const char * name = "impl";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};template <> struct value<app::impl::dot_prod_v1>{static constexpr const char * name = "dot_prod_v1";}
;template <> struct value<app::impl::dot_prod_v2>{static constexpr const char * name = "dot_prod_v2";}
;template <> struct value<app::impl::reduce>{static constexpr const char * name = "reduce";}
;}
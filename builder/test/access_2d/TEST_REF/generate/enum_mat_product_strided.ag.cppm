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
namespace app{enum class call : enum_uint_t {mat_product_v2_block_strided_mat_product_app_0 = 2};using enabled_calls = util::sequence::enum_t<call,call::mat_product_v2_block_strided_mat_product_app_0>;}
export
namespace instrument::event{template <> struct type<app::call>{static constexpr const char * name = "call";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};template <> struct value<app::call::mat_product_v2_block_strided_mat_product_app_0>{static constexpr const char * name = "mat_product_v2_block_strided_mat_product_app_0";}
;}export
namespace app{enum class id : enum_uint_t {mat_product_app = 2};using enabled_ids = util::sequence::enum_t<id,id::mat_product_app>;}
export
namespace instrument::event{template <> struct type<app::id>{static constexpr const char * name = "id";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};template <> struct value<app::id::mat_product_app>{static constexpr const char * name = "mat_product_app";}
;}export
namespace app{enum class impl : enum_uint_t {mat_product_v1_kernel_strided = 2,mat_product_v2_block_strided = 3};using enabled_impls = util::sequence::enum_t<impl,impl::mat_product_v1_kernel_strided,impl::mat_product_v2_block_strided>;}
export
namespace instrument::event{template <> struct type<app::impl>{static constexpr const char * name = "impl";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};template <> struct value<app::impl::mat_product_v1_kernel_strided>{static constexpr const char * name = "mat_product_v1_kernel_strided";}
;template <> struct value<app::impl::mat_product_v2_block_strided>{static constexpr const char * name = "mat_product_v2_block_strided";}
;}
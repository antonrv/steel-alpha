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
namespace app{enum class call : enum_uint_t {caller1_foo_fooapp_wo_0 = 2,caller2_foo_fooapp_wo_0 = 3,caller3_foo_fooapp_wo_0 = 4,caller_blocks_foo_1d_blocks_app_0 = 5,caller_low_triangle_foo_low_tri_app_0 = 6,caller_rectangle_foo_rectangle_app_0 = 7,caller_up_triangle_foo_up_tri_app_0 = 8,mat_product_v2_block_strided_mat_product_app_0 = 9,mat_product_v3_block_compact_app_pack_3 = 10,mat_product_v3_block_compact_app_pack_4 = 11,mat_product_v3_block_compact_app_pack_5 = 12,mat_product_v3_block_compact_app_unpack_7 = 13,mat_product_v3_block_compact_mat_product_app_6 = 14,mat_product_v3_block_compact_matrix_allocate_0 = 15,mat_product_v3_block_compact_matrix_allocate_1 = 16,mat_product_v3_block_compact_matrix_allocate_2 = 17,mat_product_v3_block_compact_matrix_deallocate_10 = 18,mat_product_v3_block_compact_matrix_deallocate_8 = 19,mat_product_v3_block_compact_matrix_deallocate_9 = 20,mat_vec_v2_mat_vec_app_0 = 21,operate_matrix_v2_app_allocate_matrix_0 = 22,operate_matrix_v2_app_deallocate_matrix_4 = 23,operate_matrix_v2_app_operate_matrix_2 = 24,operate_matrix_v2_app_pack_matrix_1 = 25,operate_matrix_v2_app_unpack_matrix_3 = 26,pack_matrix_caller_matrix_allocate_0 = 27,pack_matrix_caller_matrix_deallocate_2 = 28,pack_matrix_caller_matrix_pack_1 = 29};using enabled_calls = util::sequence::enum_t<call,call::caller1_foo_fooapp_wo_0,call::caller2_foo_fooapp_wo_0,call::caller3_foo_fooapp_wo_0,call::caller_blocks_foo_1d_blocks_app_0,call::caller_low_triangle_foo_low_tri_app_0,call::caller_rectangle_foo_rectangle_app_0,call::caller_up_triangle_foo_up_tri_app_0,call::mat_product_v2_block_strided_mat_product_app_0,call::mat_product_v3_block_compact_app_pack_3,call::mat_product_v3_block_compact_app_pack_4,call::mat_product_v3_block_compact_app_pack_5,call::mat_product_v3_block_compact_app_unpack_7,call::mat_product_v3_block_compact_mat_product_app_6,call::mat_product_v3_block_compact_matrix_allocate_0,call::mat_product_v3_block_compact_matrix_allocate_1,call::mat_product_v3_block_compact_matrix_allocate_2,call::mat_product_v3_block_compact_matrix_deallocate_10,call::mat_product_v3_block_compact_matrix_deallocate_8,call::mat_product_v3_block_compact_matrix_deallocate_9,call::mat_vec_v2_mat_vec_app_0,call::operate_matrix_v2_app_allocate_matrix_0,call::operate_matrix_v2_app_deallocate_matrix_4,call::operate_matrix_v2_app_operate_matrix_2,call::operate_matrix_v2_app_pack_matrix_1,call::operate_matrix_v2_app_unpack_matrix_3,call::pack_matrix_caller_matrix_allocate_0,call::pack_matrix_caller_matrix_deallocate_2,call::pack_matrix_caller_matrix_pack_1>;}
export
namespace instrument::event{template <> struct type<app::call>{static constexpr const char * name = "call";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};template <> struct value<app::call::caller1_foo_fooapp_wo_0>{static constexpr const char * name = "caller1_foo_fooapp_wo_0";}
;template <> struct value<app::call::caller2_foo_fooapp_wo_0>{static constexpr const char * name = "caller2_foo_fooapp_wo_0";}
;template <> struct value<app::call::caller3_foo_fooapp_wo_0>{static constexpr const char * name = "caller3_foo_fooapp_wo_0";}
;template <> struct value<app::call::caller_blocks_foo_1d_blocks_app_0>{static constexpr const char * name = "caller_blocks_foo_1d_blocks_app_0";}
;template <> struct value<app::call::caller_low_triangle_foo_low_tri_app_0>{static constexpr const char * name = "caller_low_triangle_foo_low_tri_app_0";}
;template <> struct value<app::call::caller_rectangle_foo_rectangle_app_0>{static constexpr const char * name = "caller_rectangle_foo_rectangle_app_0";}
;template <> struct value<app::call::caller_up_triangle_foo_up_tri_app_0>{static constexpr const char * name = "caller_up_triangle_foo_up_tri_app_0";}
;template <> struct value<app::call::mat_product_v2_block_strided_mat_product_app_0>{static constexpr const char * name = "mat_product_v2_block_strided_mat_product_app_0";}
;template <> struct value<app::call::mat_product_v3_block_compact_app_pack_3>{static constexpr const char * name = "mat_product_v3_block_compact_app_pack_3";}
;template <> struct value<app::call::mat_product_v3_block_compact_app_pack_4>{static constexpr const char * name = "mat_product_v3_block_compact_app_pack_4";}
;template <> struct value<app::call::mat_product_v3_block_compact_app_pack_5>{static constexpr const char * name = "mat_product_v3_block_compact_app_pack_5";}
;template <> struct value<app::call::mat_product_v3_block_compact_app_unpack_7>{static constexpr const char * name = "mat_product_v3_block_compact_app_unpack_7";}
;template <> struct value<app::call::mat_product_v3_block_compact_mat_product_app_6>{static constexpr const char * name = "mat_product_v3_block_compact_mat_product_app_6";}
;template <> struct value<app::call::mat_product_v3_block_compact_matrix_allocate_0>{static constexpr const char * name = "mat_product_v3_block_compact_matrix_allocate_0";}
;template <> struct value<app::call::mat_product_v3_block_compact_matrix_allocate_1>{static constexpr const char * name = "mat_product_v3_block_compact_matrix_allocate_1";}
;template <> struct value<app::call::mat_product_v3_block_compact_matrix_allocate_2>{static constexpr const char * name = "mat_product_v3_block_compact_matrix_allocate_2";}
;template <> struct value<app::call::mat_product_v3_block_compact_matrix_deallocate_10>{static constexpr const char * name = "mat_product_v3_block_compact_matrix_deallocate_10";}
;template <> struct value<app::call::mat_product_v3_block_compact_matrix_deallocate_8>{static constexpr const char * name = "mat_product_v3_block_compact_matrix_deallocate_8";}
;template <> struct value<app::call::mat_product_v3_block_compact_matrix_deallocate_9>{static constexpr const char * name = "mat_product_v3_block_compact_matrix_deallocate_9";}
;template <> struct value<app::call::mat_vec_v2_mat_vec_app_0>{static constexpr const char * name = "mat_vec_v2_mat_vec_app_0";}
;template <> struct value<app::call::operate_matrix_v2_app_allocate_matrix_0>{static constexpr const char * name = "operate_matrix_v2_app_allocate_matrix_0";}
;template <> struct value<app::call::operate_matrix_v2_app_deallocate_matrix_4>{static constexpr const char * name = "operate_matrix_v2_app_deallocate_matrix_4";}
;template <> struct value<app::call::operate_matrix_v2_app_operate_matrix_2>{static constexpr const char * name = "operate_matrix_v2_app_operate_matrix_2";}
;template <> struct value<app::call::operate_matrix_v2_app_pack_matrix_1>{static constexpr const char * name = "operate_matrix_v2_app_pack_matrix_1";}
;template <> struct value<app::call::operate_matrix_v2_app_unpack_matrix_3>{static constexpr const char * name = "operate_matrix_v2_app_unpack_matrix_3";}
;template <> struct value<app::call::pack_matrix_caller_matrix_allocate_0>{static constexpr const char * name = "pack_matrix_caller_matrix_allocate_0";}
;template <> struct value<app::call::pack_matrix_caller_matrix_deallocate_2>{static constexpr const char * name = "pack_matrix_caller_matrix_deallocate_2";}
;template <> struct value<app::call::pack_matrix_caller_matrix_pack_1>{static constexpr const char * name = "pack_matrix_caller_matrix_pack_1";}
;}export
namespace app{enum class id : enum_uint_t {app_allocate_matrix = 2,app_deallocate_matrix = 3,app_operate_matrix = 4,app_pack = 5,app_pack_matrix = 6,app_unpack = 7,app_unpack_matrix = 8,caller1_foo = 9,caller2_foo = 10,caller3_foo = 11,caller_blocks = 12,caller_low_triangle = 13,caller_rectangle = 14,caller_up_triangle = 15,foo_1d_blocks_app = 16,foo_low_tri_app = 17,foo_rectangle_app = 18,foo_up_tri_app = 19,fooapp_wo = 20,mat_product_app = 21,mat_vec_app = 22,matrix_allocate = 23,matrix_deallocate = 24,matrix_pack = 25,pack_matrix_caller = 26};using enabled_ids = util::sequence::enum_t<id,id::app_allocate_matrix,id::app_deallocate_matrix,id::app_operate_matrix,id::app_pack,id::app_pack_matrix,id::app_unpack,id::app_unpack_matrix,id::caller1_foo,id::caller2_foo,id::caller3_foo,id::caller_blocks,id::caller_low_triangle,id::caller_rectangle,id::caller_up_triangle,id::foo_1d_blocks_app,id::foo_low_tri_app,id::foo_rectangle_app,id::foo_up_tri_app,id::fooapp_wo,id::mat_product_app,id::mat_vec_app,id::matrix_allocate,id::matrix_deallocate,id::matrix_pack,id::pack_matrix_caller>;}
export
namespace instrument::event{template <> struct type<app::id>{static constexpr const char * name = "id";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};template <> struct value<app::id::app_allocate_matrix>{static constexpr const char * name = "app_allocate_matrix";}
;template <> struct value<app::id::app_deallocate_matrix>{static constexpr const char * name = "app_deallocate_matrix";}
;template <> struct value<app::id::app_operate_matrix>{static constexpr const char * name = "app_operate_matrix";}
;template <> struct value<app::id::app_pack>{static constexpr const char * name = "app_pack";}
;template <> struct value<app::id::app_pack_matrix>{static constexpr const char * name = "app_pack_matrix";}
;template <> struct value<app::id::app_unpack>{static constexpr const char * name = "app_unpack";}
;template <> struct value<app::id::app_unpack_matrix>{static constexpr const char * name = "app_unpack_matrix";}
;template <> struct value<app::id::caller1_foo>{static constexpr const char * name = "caller1_foo";}
;template <> struct value<app::id::caller2_foo>{static constexpr const char * name = "caller2_foo";}
;template <> struct value<app::id::caller3_foo>{static constexpr const char * name = "caller3_foo";}
;template <> struct value<app::id::caller_blocks>{static constexpr const char * name = "caller_blocks";}
;template <> struct value<app::id::caller_low_triangle>{static constexpr const char * name = "caller_low_triangle";}
;template <> struct value<app::id::caller_rectangle>{static constexpr const char * name = "caller_rectangle";}
;template <> struct value<app::id::caller_up_triangle>{static constexpr const char * name = "caller_up_triangle";}
;template <> struct value<app::id::foo_1d_blocks_app>{static constexpr const char * name = "foo_1d_blocks_app";}
;template <> struct value<app::id::foo_low_tri_app>{static constexpr const char * name = "foo_low_tri_app";}
;template <> struct value<app::id::foo_rectangle_app>{static constexpr const char * name = "foo_rectangle_app";}
;template <> struct value<app::id::foo_up_tri_app>{static constexpr const char * name = "foo_up_tri_app";}
;template <> struct value<app::id::fooapp_wo>{static constexpr const char * name = "fooapp_wo";}
;template <> struct value<app::id::mat_product_app>{static constexpr const char * name = "mat_product_app";}
;template <> struct value<app::id::mat_vec_app>{static constexpr const char * name = "mat_vec_app";}
;template <> struct value<app::id::matrix_allocate>{static constexpr const char * name = "matrix_allocate";}
;template <> struct value<app::id::matrix_deallocate>{static constexpr const char * name = "matrix_deallocate";}
;template <> struct value<app::id::matrix_pack>{static constexpr const char * name = "matrix_pack";}
;template <> struct value<app::id::pack_matrix_caller>{static constexpr const char * name = "pack_matrix_caller";}
;}export
namespace app{enum class impl : enum_uint_t {allocate_matrix = 2,caller1_foo = 3,caller2_foo = 4,caller3_foo = 5,caller_blocks = 6,caller_low_triangle = 7,caller_rectangle = 8,caller_up_triangle = 9,deallocate_matrix = 10,foo = 11,foo_blocks = 12,foo_low_triangle = 13,foo_rectangle = 14,foo_up_triangle = 15,mat_product_v0_kernel_compact = 16,mat_product_v1_kernel_strided = 17,mat_product_v2_block_strided = 18,mat_product_v3_block_compact = 19,mat_vec_v1 = 20,mat_vec_v2 = 21,operate_matrix_v1 = 22,operate_matrix_v2 = 23,pack_copy_matrix = 24,pack_matrix = 25,pack_matrix_caller = 26,unpack_copy_matrix = 27,unpack_matrix = 28};using enabled_impls = util::sequence::enum_t<impl,impl::allocate_matrix,impl::caller1_foo,impl::caller2_foo,impl::caller3_foo,impl::caller_blocks,impl::caller_low_triangle,impl::caller_rectangle,impl::caller_up_triangle,impl::deallocate_matrix,impl::foo,impl::foo_blocks,impl::foo_low_triangle,impl::foo_rectangle,impl::foo_up_triangle,impl::mat_product_v0_kernel_compact,impl::mat_product_v1_kernel_strided,impl::mat_product_v2_block_strided,impl::mat_product_v3_block_compact,impl::mat_vec_v1,impl::mat_vec_v2,impl::operate_matrix_v1,impl::operate_matrix_v2,impl::pack_copy_matrix,impl::pack_matrix,impl::pack_matrix_caller,impl::unpack_copy_matrix,impl::unpack_matrix>;}
export
namespace instrument::event{template <> struct type<app::impl>{static constexpr const char * name = "impl";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};template <> struct value<app::impl::allocate_matrix>{static constexpr const char * name = "allocate_matrix";}
;template <> struct value<app::impl::caller1_foo>{static constexpr const char * name = "caller1_foo";}
;template <> struct value<app::impl::caller2_foo>{static constexpr const char * name = "caller2_foo";}
;template <> struct value<app::impl::caller3_foo>{static constexpr const char * name = "caller3_foo";}
;template <> struct value<app::impl::caller_blocks>{static constexpr const char * name = "caller_blocks";}
;template <> struct value<app::impl::caller_low_triangle>{static constexpr const char * name = "caller_low_triangle";}
;template <> struct value<app::impl::caller_rectangle>{static constexpr const char * name = "caller_rectangle";}
;template <> struct value<app::impl::caller_up_triangle>{static constexpr const char * name = "caller_up_triangle";}
;template <> struct value<app::impl::deallocate_matrix>{static constexpr const char * name = "deallocate_matrix";}
;template <> struct value<app::impl::foo>{static constexpr const char * name = "foo";}
;template <> struct value<app::impl::foo_blocks>{static constexpr const char * name = "foo_blocks";}
;template <> struct value<app::impl::foo_low_triangle>{static constexpr const char * name = "foo_low_triangle";}
;template <> struct value<app::impl::foo_rectangle>{static constexpr const char * name = "foo_rectangle";}
;template <> struct value<app::impl::foo_up_triangle>{static constexpr const char * name = "foo_up_triangle";}
;template <> struct value<app::impl::mat_product_v0_kernel_compact>{static constexpr const char * name = "mat_product_v0_kernel_compact";}
;template <> struct value<app::impl::mat_product_v1_kernel_strided>{static constexpr const char * name = "mat_product_v1_kernel_strided";}
;template <> struct value<app::impl::mat_product_v2_block_strided>{static constexpr const char * name = "mat_product_v2_block_strided";}
;template <> struct value<app::impl::mat_product_v3_block_compact>{static constexpr const char * name = "mat_product_v3_block_compact";}
;template <> struct value<app::impl::mat_vec_v1>{static constexpr const char * name = "mat_vec_v1";}
;template <> struct value<app::impl::mat_vec_v2>{static constexpr const char * name = "mat_vec_v2";}
;template <> struct value<app::impl::operate_matrix_v1>{static constexpr const char * name = "operate_matrix_v1";}
;template <> struct value<app::impl::operate_matrix_v2>{static constexpr const char * name = "operate_matrix_v2";}
;template <> struct value<app::impl::pack_copy_matrix>{static constexpr const char * name = "pack_copy_matrix";}
;template <> struct value<app::impl::pack_matrix>{static constexpr const char * name = "pack_matrix";}
;template <> struct value<app::impl::pack_matrix_caller>{static constexpr const char * name = "pack_matrix_caller";}
;template <> struct value<app::impl::unpack_copy_matrix>{static constexpr const char * name = "unpack_copy_matrix";}
;template <> struct value<app::impl::unpack_matrix>{static constexpr const char * name = "unpack_matrix";}
;}
//////////////////////////////////////
// 
// Autogenerated file. Do not modify. 
// 
//////////////////////////////////////

export module App.Graph;
export import App.Enum;
import Plat.Enum;
import SteelRT.Util.Sequence;
import SteelRT.Util.Types;
import SteelRT.Util.Tuple;
import SteelRT.Util.FwDeclarations.App;
import SteelRT.Dep.Guard.Backend;
import SteelRT.Dep.Dim.View;
export
namespace app{
template <> struct traits<id::mat_product_app>{using impl_sequence = util::sequence::enum_t<impl,impl::mat_product_v1_kernel_strided,impl::mat_product_v2_block_strided>;};template <> struct traits<impl::mat_product_v1_kernel_strided> {static constexpr impl this_impl = impl::mat_product_v1_kernel_strided;
static constexpr id belonging_id = id::mat_product_app;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_pointer_t<std::add_const_t<float>>,std::add_pointer_t<std::add_const_t<float>>,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned>;
using call_sequence = util::sequence::enum_t<call,call::mat_product_v2_block_strided_mat_product_app_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::mat_product_v2_block_strided> {static constexpr impl this_impl = impl::mat_product_v2_block_strided;
static constexpr id belonging_id = id::mat_product_app;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_pointer_t<std::add_const_t<float>>,std::add_pointer_t<std::add_const_t<float>>,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::mat_product_v2_block_strided_mat_product_app_0>;
};template <> struct traits<call::mat_product_v2_block_strided_mat_product_app_0> {static constexpr call this_call = call::mat_product_v2_block_strided_mat_product_app_0;
static constexpr impl belonging_impl = impl::mat_product_v1_kernel_strided;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<2,float>>,dep::guard::bnd::readable<dep::dim::view<2,const float>>,dep::guard::bnd::readable<dep::dim::view<2,const float>>,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned>;
};}
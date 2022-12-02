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
template <> struct traits<id::matrix_allocate>{using impl_sequence = util::sequence::enum_t<impl,impl::allocate_matrix>;};template <> struct traits<id::matrix_deallocate>{using impl_sequence = util::sequence::enum_t<impl,impl::deallocate_matrix>;};template <> struct traits<id::matrix_pack>{using impl_sequence = util::sequence::enum_t<impl,impl::pack_matrix>;};template <> struct traits<id::pack_matrix_caller>{using impl_sequence = util::sequence::enum_t<impl,impl::pack_matrix_caller>;};template <> struct traits<impl::pack_matrix> {static constexpr impl this_impl = impl::pack_matrix;
static constexpr id belonging_id = id::matrix_pack;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_pointer_t<std::add_const_t<float>>,unsigned,unsigned,unsigned>;
using call_sequence = util::sequence::enum_t<call,call::pack_matrix_caller_matrix_pack_1>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::allocate_matrix> {static constexpr impl this_impl = impl::allocate_matrix;
static constexpr id belonging_id = id::matrix_allocate;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,unsigned,unsigned>;
using call_sequence = util::sequence::enum_t<call,call::pack_matrix_caller_matrix_allocate_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::deallocate_matrix> {static constexpr impl this_impl = impl::deallocate_matrix;
static constexpr id belonging_id = id::matrix_deallocate;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>>;
using call_sequence = util::sequence::enum_t<call,call::pack_matrix_caller_matrix_deallocate_2>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::pack_matrix_caller> {static constexpr impl this_impl = impl::pack_matrix_caller;
static constexpr id belonging_id = id::pack_matrix_caller;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<std::add_const_t<float>>,unsigned,unsigned,unsigned,unsigned>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::pack_matrix_caller_matrix_allocate_0,call::pack_matrix_caller_matrix_pack_1,call::pack_matrix_caller_matrix_deallocate_2>;
};template <> struct traits<call::pack_matrix_caller_matrix_allocate_0> {static constexpr call this_call = call::pack_matrix_caller_matrix_allocate_0;
static constexpr impl belonging_impl = impl::allocate_matrix;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<float*>,unsigned,unsigned>;
};template <> struct traits<call::pack_matrix_caller_matrix_pack_1> {static constexpr call this_call = call::pack_matrix_caller_matrix_pack_1;
static constexpr impl belonging_impl = impl::pack_matrix;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<float*>,dep::guard::bnd::readable<dep::dim::view<2,const float>>,unsigned,unsigned,unsigned>;
};template <> struct traits<call::pack_matrix_caller_matrix_deallocate_2> {static constexpr call this_call = call::pack_matrix_caller_matrix_deallocate_2;
static constexpr impl belonging_impl = impl::deallocate_matrix;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<float*>>;
};}
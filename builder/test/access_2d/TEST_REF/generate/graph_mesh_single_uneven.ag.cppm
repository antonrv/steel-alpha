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
template <> struct traits<id::write_mesh_uneven>{using impl_sequence = util::sequence::enum_t<impl,impl::caller_foo,impl::foo>;};template <> struct traits<impl::foo> {static constexpr impl this_impl = impl::foo;
static constexpr id belonging_id = id::write_mesh_uneven;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>>;
using call_sequence = util::sequence::enum_t<call,call::caller_foo_write_mesh_uneven_0,call::caller_foo_write_mesh_uneven_1,call::caller_foo_write_mesh_uneven_2,call::caller_foo_write_mesh_uneven_3>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_foo> {static constexpr impl this_impl = impl::caller_foo;
static constexpr id belonging_id = id::write_mesh_uneven;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_foo_write_mesh_uneven_0,call::caller_foo_write_mesh_uneven_1,call::caller_foo_write_mesh_uneven_2,call::caller_foo_write_mesh_uneven_3>;
};template <> struct traits<call::caller_foo_write_mesh_uneven_0> {static constexpr call this_call = call::caller_foo_write_mesh_uneven_0;
static constexpr impl belonging_impl = impl::foo;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<2,float>>,unsigned,unsigned,const unsigned>;
};template <> struct traits<call::caller_foo_write_mesh_uneven_1> {static constexpr call this_call = call::caller_foo_write_mesh_uneven_1;
static constexpr impl belonging_impl = impl::foo;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<2,float>>,unsigned,unsigned,const unsigned>;
};template <> struct traits<call::caller_foo_write_mesh_uneven_2> {static constexpr call this_call = call::caller_foo_write_mesh_uneven_2;
static constexpr impl belonging_impl = impl::foo;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<2,float>>,unsigned,unsigned,const unsigned>;
};template <> struct traits<call::caller_foo_write_mesh_uneven_3> {static constexpr call this_call = call::caller_foo_write_mesh_uneven_3;
static constexpr impl belonging_impl = impl::foo;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<2,float>>,unsigned,unsigned,const unsigned>;
};}
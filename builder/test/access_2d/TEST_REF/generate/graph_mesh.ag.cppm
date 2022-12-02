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
template <> struct traits<id::caller1_foo>{using impl_sequence = util::sequence::enum_t<impl,impl::caller1_foo>;};template <> struct traits<id::caller2_foo>{using impl_sequence = util::sequence::enum_t<impl,impl::caller2_foo>;};template <> struct traits<id::caller3_foo>{using impl_sequence = util::sequence::enum_t<impl,impl::caller3_foo>;};template <> struct traits<id::caller4_foo>{using impl_sequence = util::sequence::enum_t<impl,impl::caller4_foo>;};template <> struct traits<id::caller5_foo>{using impl_sequence = util::sequence::enum_t<impl,impl::caller5_foo>;};template <> struct traits<id::fooapp_wo>{using impl_sequence = util::sequence::enum_t<impl,impl::foo>;};template <> struct traits<impl::foo> {static constexpr impl this_impl = impl::foo;
static constexpr id belonging_id = id::fooapp_wo;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>>;
using call_sequence = util::sequence::enum_t<call,call::caller1_foo_fooapp_wo_0,call::caller2_foo_fooapp_wo_0,call::caller3_foo_fooapp_wo_0,call::caller4_foo_fooapp_wo_0,call::caller5_foo_fooapp_wo_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller1_foo> {static constexpr impl this_impl = impl::caller1_foo;
static constexpr id belonging_id = id::caller1_foo;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller1_foo_fooapp_wo_0>;
};template <> struct traits<impl::caller2_foo> {static constexpr impl this_impl = impl::caller2_foo;
static constexpr id belonging_id = id::caller2_foo;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller2_foo_fooapp_wo_0>;
};template <> struct traits<impl::caller3_foo> {static constexpr impl this_impl = impl::caller3_foo;
static constexpr id belonging_id = id::caller3_foo;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller3_foo_fooapp_wo_0>;
};template <> struct traits<impl::caller4_foo> {static constexpr impl this_impl = impl::caller4_foo;
static constexpr id belonging_id = id::caller4_foo;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller4_foo_fooapp_wo_0>;
};template <> struct traits<impl::caller5_foo> {static constexpr impl this_impl = impl::caller5_foo;
static constexpr id belonging_id = id::caller5_foo;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>,std::add_const_t<unsigned>>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller5_foo_fooapp_wo_0>;
};template <> struct traits<call::caller1_foo_fooapp_wo_0> {static constexpr call this_call = call::caller1_foo_fooapp_wo_0;
static constexpr impl belonging_impl = impl::foo;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<2,float>>,const unsigned,const unsigned,unsigned>;
};template <> struct traits<call::caller2_foo_fooapp_wo_0> {static constexpr call this_call = call::caller2_foo_fooapp_wo_0;
static constexpr impl belonging_impl = impl::foo;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<2,float>>,const unsigned,const unsigned,unsigned>;
};template <> struct traits<call::caller3_foo_fooapp_wo_0> {static constexpr call this_call = call::caller3_foo_fooapp_wo_0;
static constexpr impl belonging_impl = impl::foo;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<2,float>>,const unsigned,const unsigned>;
};template <> struct traits<call::caller4_foo_fooapp_wo_0> {static constexpr call this_call = call::caller4_foo_fooapp_wo_0;
static constexpr impl belonging_impl = impl::foo;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<2,float>>,unsigned,unsigned,const unsigned>;
};template <> struct traits<call::caller5_foo_fooapp_wo_0> {static constexpr call this_call = call::caller5_foo_fooapp_wo_0;
static constexpr impl belonging_impl = impl::foo;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<2,float>>,const unsigned>;
};}
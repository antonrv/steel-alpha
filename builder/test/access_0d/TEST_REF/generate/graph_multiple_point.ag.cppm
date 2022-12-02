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
template <> struct traits<id::caller1_ro_multiple_point>{using impl_sequence = util::sequence::enum_t<impl,impl::caller1_ro_multiple_point>;};template <> struct traits<id::caller1_rw_multiple_point>{using impl_sequence = util::sequence::enum_t<impl,impl::caller1_rw_multiple_point>;};template <> struct traits<id::caller2_ro_multiple_point>{using impl_sequence = util::sequence::enum_t<impl,impl::caller2_ro_multiple_point>;};template <> struct traits<id::caller2_rw_multiple_point>{using impl_sequence = util::sequence::enum_t<impl,impl::caller2_rw_multiple_point>;};template <> struct traits<id::foo_ro_multiple_point_app>{using impl_sequence = util::sequence::enum_t<impl,impl::foo_ro_multiple_point>;};template <> struct traits<id::foo_rw_multiple_point_app>{using impl_sequence = util::sequence::enum_t<impl,impl::foo_rw_multiple_point>;};template <> struct traits<impl::foo_ro_multiple_point> {static constexpr impl this_impl = impl::foo_ro_multiple_point;
static constexpr id belonging_id = id::foo_ro_multiple_point_app;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<std::add_const_t<float>>,int>;
using call_sequence = util::sequence::enum_t<call,call::caller1_ro_multiple_point_foo_ro_multiple_point_app_0,call::caller1_ro_multiple_point_foo_ro_multiple_point_app_1,call::caller1_ro_multiple_point_foo_ro_multiple_point_app_2,call::caller2_ro_multiple_point_foo_ro_multiple_point_app_0,call::caller2_ro_multiple_point_foo_ro_multiple_point_app_1,call::caller2_ro_multiple_point_foo_ro_multiple_point_app_2>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller1_ro_multiple_point> {static constexpr impl this_impl = impl::caller1_ro_multiple_point;
static constexpr id belonging_id = id::caller1_ro_multiple_point;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller1_ro_multiple_point_foo_ro_multiple_point_app_0,call::caller1_ro_multiple_point_foo_ro_multiple_point_app_1,call::caller1_ro_multiple_point_foo_ro_multiple_point_app_2>;
};template <> struct traits<impl::caller2_ro_multiple_point> {static constexpr impl this_impl = impl::caller2_ro_multiple_point;
static constexpr id belonging_id = id::caller2_ro_multiple_point;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<int,int,int>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller2_ro_multiple_point_foo_ro_multiple_point_app_0,call::caller2_ro_multiple_point_foo_ro_multiple_point_app_1,call::caller2_ro_multiple_point_foo_ro_multiple_point_app_2>;
};template <> struct traits<impl::foo_rw_multiple_point> {static constexpr impl this_impl = impl::foo_rw_multiple_point;
static constexpr id belonging_id = id::foo_rw_multiple_point_app;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,int>;
using call_sequence = util::sequence::enum_t<call,call::caller1_rw_multiple_point_foo_rw_multiple_point_app_0,call::caller1_rw_multiple_point_foo_rw_multiple_point_app_1,call::caller1_rw_multiple_point_foo_rw_multiple_point_app_2,call::caller2_rw_multiple_point_foo_rw_multiple_point_app_0,call::caller2_rw_multiple_point_foo_rw_multiple_point_app_1,call::caller2_rw_multiple_point_foo_rw_multiple_point_app_2>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller1_rw_multiple_point> {static constexpr impl this_impl = impl::caller1_rw_multiple_point;
static constexpr id belonging_id = id::caller1_rw_multiple_point;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller1_rw_multiple_point_foo_rw_multiple_point_app_0,call::caller1_rw_multiple_point_foo_rw_multiple_point_app_1,call::caller1_rw_multiple_point_foo_rw_multiple_point_app_2>;
};template <> struct traits<impl::caller2_rw_multiple_point> {static constexpr impl this_impl = impl::caller2_rw_multiple_point;
static constexpr id belonging_id = id::caller2_rw_multiple_point;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<int,int,int>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller2_rw_multiple_point_foo_rw_multiple_point_app_0,call::caller2_rw_multiple_point_foo_rw_multiple_point_app_1,call::caller2_rw_multiple_point_foo_rw_multiple_point_app_2>;
};template <> struct traits<call::caller1_ro_multiple_point_foo_ro_multiple_point_app_0> {static constexpr call this_call = call::caller1_ro_multiple_point_foo_ro_multiple_point_app_0;
static constexpr impl belonging_impl = impl::foo_ro_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller1_ro_multiple_point_foo_ro_multiple_point_app_1> {static constexpr call this_call = call::caller1_ro_multiple_point_foo_ro_multiple_point_app_1;
static constexpr impl belonging_impl = impl::foo_ro_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller1_ro_multiple_point_foo_ro_multiple_point_app_2> {static constexpr call this_call = call::caller1_ro_multiple_point_foo_ro_multiple_point_app_2;
static constexpr impl belonging_impl = impl::foo_ro_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller2_ro_multiple_point_foo_ro_multiple_point_app_0> {static constexpr call this_call = call::caller2_ro_multiple_point_foo_ro_multiple_point_app_0;
static constexpr impl belonging_impl = impl::foo_ro_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller2_ro_multiple_point_foo_ro_multiple_point_app_1> {static constexpr call this_call = call::caller2_ro_multiple_point_foo_ro_multiple_point_app_1;
static constexpr impl belonging_impl = impl::foo_ro_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller2_ro_multiple_point_foo_ro_multiple_point_app_2> {static constexpr call this_call = call::caller2_ro_multiple_point_foo_ro_multiple_point_app_2;
static constexpr impl belonging_impl = impl::foo_ro_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller1_rw_multiple_point_foo_rw_multiple_point_app_0> {static constexpr call this_call = call::caller1_rw_multiple_point_foo_rw_multiple_point_app_0;
static constexpr impl belonging_impl = impl::foo_rw_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller1_rw_multiple_point_foo_rw_multiple_point_app_1> {static constexpr call this_call = call::caller1_rw_multiple_point_foo_rw_multiple_point_app_1;
static constexpr impl belonging_impl = impl::foo_rw_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller1_rw_multiple_point_foo_rw_multiple_point_app_2> {static constexpr call this_call = call::caller1_rw_multiple_point_foo_rw_multiple_point_app_2;
static constexpr impl belonging_impl = impl::foo_rw_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller2_rw_multiple_point_foo_rw_multiple_point_app_0> {static constexpr call this_call = call::caller2_rw_multiple_point_foo_rw_multiple_point_app_0;
static constexpr impl belonging_impl = impl::foo_rw_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller2_rw_multiple_point_foo_rw_multiple_point_app_1> {static constexpr call this_call = call::caller2_rw_multiple_point_foo_rw_multiple_point_app_1;
static constexpr impl belonging_impl = impl::foo_rw_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller2_rw_multiple_point_foo_rw_multiple_point_app_2> {static constexpr call this_call = call::caller2_rw_multiple_point_foo_rw_multiple_point_app_2;
static constexpr impl belonging_impl = impl::foo_rw_multiple_point;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<0,float>>,int>;
};}
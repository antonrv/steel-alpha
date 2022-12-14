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
template <> struct traits<id::caller_ro>{using impl_sequence = util::sequence::enum_t<impl,impl::caller_ro>;};template <> struct traits<id::caller_rw>{using impl_sequence = util::sequence::enum_t<impl,impl::caller_rw>;};template <> struct traits<id::foo_portion_ro_app>{using impl_sequence = util::sequence::enum_t<impl,impl::foo_portion_ro>;};template <> struct traits<id::foo_portion_rw_app>{using impl_sequence = util::sequence::enum_t<impl,impl::foo_portion_rw>;};template <> struct traits<id::foo_whole_ro_app>{using impl_sequence = util::sequence::enum_t<impl,impl::foo_whole_ro>;};template <> struct traits<id::foo_whole_rw_app>{using impl_sequence = util::sequence::enum_t<impl,impl::foo_whole_rw>;};template <> struct traits<impl::foo_whole_ro> {static constexpr impl this_impl = impl::foo_whole_ro;
static constexpr id belonging_id = id::foo_whole_ro_app;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<std::add_const_t<float>>,int>;
using call_sequence = util::sequence::enum_t<call,call::caller_ro_foo_whole_ro_app_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_ro> {static constexpr impl this_impl = impl::caller_ro;
static constexpr id belonging_id = id::caller_ro;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<int>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_ro_foo_whole_ro_app_0>;
};template <> struct traits<impl::foo_portion_ro> {static constexpr impl this_impl = impl::foo_portion_ro;
static constexpr id belonging_id = id::foo_portion_ro_app;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<std::add_const_t<float>>,int,int>;
using call_sequence = util::sequence::enum_t<call,call::caller_ro_foo_portion_ro_app_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_ro> {static constexpr impl this_impl = impl::caller_ro;
static constexpr id belonging_id = id::caller_ro;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<int,int>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_ro_foo_portion_ro_app_0>;
};template <> struct traits<impl::foo_whole_rw> {static constexpr impl this_impl = impl::foo_whole_rw;
static constexpr id belonging_id = id::foo_whole_rw_app;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,int>;
using call_sequence = util::sequence::enum_t<call,call::caller_rw_foo_whole_rw_app_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_rw> {static constexpr impl this_impl = impl::caller_rw;
static constexpr id belonging_id = id::caller_rw;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<int>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_rw_foo_whole_rw_app_0>;
};template <> struct traits<impl::foo_portion_rw> {static constexpr impl this_impl = impl::foo_portion_rw;
static constexpr id belonging_id = id::foo_portion_rw_app;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<std::add_const_t<float>>,int,int>;
using call_sequence = util::sequence::enum_t<call,call::caller_rw_foo_portion_rw_app_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_rw> {static constexpr impl this_impl = impl::caller_rw;
static constexpr id belonging_id = id::caller_rw;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<int,int>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_rw_foo_portion_rw_app_0>;
};template <> struct traits<call::caller_ro_foo_whole_ro_app_0> {static constexpr call this_call = call::caller_ro_foo_whole_ro_app_0;
static constexpr impl belonging_impl = impl::foo_whole_ro;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<1,float>>,int>;
};template <> struct traits<call::caller_ro_foo_portion_ro_app_0> {static constexpr call this_call = call::caller_ro_foo_portion_ro_app_0;
static constexpr impl belonging_impl = impl::foo_portion_ro;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<1,float>>,int,int>;
};template <> struct traits<call::caller_rw_foo_whole_rw_app_0> {static constexpr call this_call = call::caller_rw_foo_whole_rw_app_0;
static constexpr impl belonging_impl = impl::foo_whole_rw;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<1,float>>,int>;
};template <> struct traits<call::caller_rw_foo_portion_rw_app_0> {static constexpr call this_call = call::caller_rw_foo_portion_rw_app_0;
static constexpr impl belonging_impl = impl::foo_portion_rw;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<1,float>>,int,int>;
};}
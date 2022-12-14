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
template <> struct traits<id::callee_no_offset_app>{using impl_sequence = util::sequence::enum_t<impl,impl::callee_no_offset>;};template <> struct traits<id::callee_offset_app>{using impl_sequence = util::sequence::enum_t<impl,impl::callee_offset>;};template <> struct traits<id::caller_no_offset>{using impl_sequence = util::sequence::enum_t<impl,impl::caller_no_offset>;};template <> struct traits<id::caller_offset>{using impl_sequence = util::sequence::enum_t<impl,impl::caller_offset>;};template <> struct traits<impl::callee_offset> {static constexpr impl this_impl = impl::callee_offset;
static constexpr id belonging_id = id::callee_offset_app;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>,int>;
using call_sequence = util::sequence::enum_t<call,call::caller_offset_callee_offset_app_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_offset> {static constexpr impl this_impl = impl::caller_offset;
static constexpr id belonging_id = id::caller_offset;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_offset_callee_offset_app_0>;
};template <> struct traits<impl::callee_no_offset> {static constexpr impl this_impl = impl::callee_no_offset;
static constexpr id belonging_id = id::callee_no_offset_app;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>>;
using call_sequence = util::sequence::enum_t<call,call::caller_no_offset_callee_no_offset_app_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_no_offset> {static constexpr impl this_impl = impl::caller_no_offset;
static constexpr id belonging_id = id::caller_no_offset;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<float>>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_no_offset_callee_no_offset_app_0>;
};template <> struct traits<call::caller_offset_callee_offset_app_0> {static constexpr call this_call = call::caller_offset_callee_offset_app_0;
static constexpr impl belonging_impl = impl::callee_offset;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<dep::dim::view<0,float>>,int>;
};template <> struct traits<call::caller_no_offset_callee_no_offset_app_0> {static constexpr call this_call = call::caller_no_offset_callee_no_offset_app_0;
static constexpr impl belonging_impl = impl::callee_no_offset;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<float>>;
};}
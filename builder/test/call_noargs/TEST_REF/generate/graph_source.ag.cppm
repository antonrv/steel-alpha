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
template <> struct traits<id::fooapp>{using impl_sequence = util::sequence::enum_t<impl,impl::foo>;};template <> struct traits<id::main_entry>{using impl_sequence = util::sequence::enum_t<impl,impl::main_entry>;};template <> struct traits<impl::foo> {static constexpr impl this_impl = impl::foo;
static constexpr id belonging_id = id::fooapp;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<>;
using call_sequence = util::sequence::enum_t<call,call::main_entry_fooapp_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::main_entry> {static constexpr impl this_impl = impl::main_entry;
static constexpr id belonging_id = id::main_entry;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_lvalue_reference_t<int>>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::main_entry_fooapp_0>;
};template <> struct traits<call::main_entry_fooapp_0> {static constexpr call this_call = call::main_entry_fooapp_0;
static constexpr impl belonging_impl = impl::foo;
using arg_tuple_type = util::tuple_t<>;
};}
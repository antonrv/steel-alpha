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
template <> struct traits<id::caller_shift_end>{using impl_sequence = util::sequence::enum_t<impl,impl::caller_shift_end>;};template <> struct traits<id::caller_shift_literal>{using impl_sequence = util::sequence::enum_t<impl,impl::caller_shift_literal>;};template <> struct traits<id::caller_shift_start>{using impl_sequence = util::sequence::enum_t<impl,impl::caller_shift_start>;};template <> struct traits<id::caller_shift_start_end>{using impl_sequence = util::sequence::enum_t<impl,impl::caller_shift_start_end>;};template <> struct traits<id::foo_shift_end>{using impl_sequence = util::sequence::enum_t<impl,impl::foo_shift_end>;};template <> struct traits<id::foo_shift_literal>{using impl_sequence = util::sequence::enum_t<impl,impl::foo_shift_literal>;};template <> struct traits<id::foo_shift_start>{using impl_sequence = util::sequence::enum_t<impl,impl::foo_shift_start>;};template <> struct traits<id::foo_shift_start_end>{using impl_sequence = util::sequence::enum_t<impl,impl::foo_shift_start_end>;};template <> struct traits<impl::foo_shift_literal> {static constexpr impl this_impl = impl::foo_shift_literal;
static constexpr id belonging_id = id::foo_shift_literal;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<std::add_const_t<float>>>;
using call_sequence = util::sequence::enum_t<call,call::caller_shift_literal_foo_shift_literal_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_shift_literal> {static constexpr impl this_impl = impl::caller_shift_literal;
static constexpr id belonging_id = id::caller_shift_literal;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<int,std::add_pointer_t<std::add_const_t<float>>>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_shift_literal_foo_shift_literal_0>;
};template <> struct traits<impl::foo_shift_start> {static constexpr impl this_impl = impl::foo_shift_start;
static constexpr id belonging_id = id::foo_shift_start;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<std::add_const_t<float>>,int>;
using call_sequence = util::sequence::enum_t<call,call::caller_shift_start_foo_shift_start_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_shift_start> {static constexpr impl this_impl = impl::caller_shift_start;
static constexpr id belonging_id = id::caller_shift_start;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<int,std::add_pointer_t<std::add_const_t<float>>,int>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_shift_start_foo_shift_start_0>;
};template <> struct traits<impl::foo_shift_end> {static constexpr impl this_impl = impl::foo_shift_end;
static constexpr id belonging_id = id::foo_shift_end;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<std::add_const_t<float>>,int>;
using call_sequence = util::sequence::enum_t<call,call::caller_shift_end_foo_shift_end_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_shift_end> {static constexpr impl this_impl = impl::caller_shift_end;
static constexpr id belonging_id = id::caller_shift_end;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<int,std::add_pointer_t<std::add_const_t<float>>,int>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_shift_end_foo_shift_end_0>;
};template <> struct traits<impl::foo_shift_start_end> {static constexpr impl this_impl = impl::foo_shift_start_end;
static constexpr id belonging_id = id::foo_shift_start_end;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<std::add_pointer_t<std::add_const_t<float>>,int,int>;
using call_sequence = util::sequence::enum_t<call,call::caller_shift_start_end_foo_shift_start_end_0>;
using dispatch_sequence = util::sequence::enum_t<call>;
};template <> struct traits<impl::caller_shift_start_end> {static constexpr impl this_impl = impl::caller_shift_start_end;
static constexpr id belonging_id = id::caller_shift_start_end;
static constexpr plat::arch arch_value = plat::arch::x86_64;
using arg_tuple_type = util::tuple_t<int,int,int>;
using call_sequence = util::sequence::enum_t<call>;
using dispatch_sequence = util::sequence::enum_t<call,call::caller_shift_start_end_foo_shift_start_end_0>;
};template <> struct traits<call::caller_shift_literal_foo_shift_literal_0> {static constexpr call this_call = call::caller_shift_literal_foo_shift_literal_0;
static constexpr impl belonging_impl = impl::foo_shift_literal;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<1,float>>>;
};template <> struct traits<call::caller_shift_start_foo_shift_start_0> {static constexpr call this_call = call::caller_shift_start_foo_shift_start_0;
static constexpr impl belonging_impl = impl::foo_shift_start;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<1,float>>,int>;
};template <> struct traits<call::caller_shift_end_foo_shift_end_0> {static constexpr call this_call = call::caller_shift_end_foo_shift_end_0;
static constexpr impl belonging_impl = impl::foo_shift_end;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<1,float>>,int>;
};template <> struct traits<call::caller_shift_start_end_foo_shift_start_end_0> {static constexpr call this_call = call::caller_shift_start_end_foo_shift_start_end_0;
static constexpr impl belonging_impl = impl::foo_shift_start_end;
using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<dep::dim::view<1,float>>,int,int>;
};}
export module App.Traits;

export import App.EnumDefinitions;

import SteelRT.Util.Sequence;
import SteelRT.Util.Types;
import SteelRT.Util.Tuple;
import SteelRT.Util.App;

import SteelRT.Dep.Guard.Backend;

import SteelRT.Data.View;


import <vector>; // For vii only

export
namespace app {



/////////// ID TRAITS

template <>
struct traits<id::ro_region> {
  using impl_sequence = util::sequence::enum_t<impl, impl::ro_region>;
};

template <>
struct traits<id::rw_region> {
  using impl_sequence = util::sequence::enum_t<impl, impl::rw_region>;
};


/////////// IMPL TRAITS

template <>
struct traits<impl::ro_region> {
  static constexpr impl this_impl = impl::ro_region;
  static constexpr id belonging_id = id::ro_region;
  using arg_tuple_type = util::tuple_t<data::view<1, float>>;
  using call_sequence = util::sequence::enum_t<call, call::ro_region>;
  using dispatch_sequence = util::sequence::enum_t<call>;
};

template <>
struct traits<impl::rw_region> {
  static constexpr impl this_impl = impl::rw_region;
  static constexpr id belonging_id = id::rw_region;
  using arg_tuple_type = util::tuple_t<data::view<1, float>>;
  using call_sequence = util::sequence::enum_t<call, call::rw_region>;
  using dispatch_sequence = util::sequence::enum_t<call>;
};

/////////// CALL TRAITS

template <>
struct traits<call::ro_region> {
  static constexpr impl belonging_impl = impl::ro_region;
  using arg_tuple_type = util::tuple_t<dep::guard::bnd::readable<data::view<1, float>>>;
};

template <>
struct traits<call::rw_region> {
  static constexpr impl belonging_impl = impl::rw_region;
  using arg_tuple_type = util::tuple_t<dep::guard::bnd::writable<data::view<1, float>>>;
};

} // namespace app

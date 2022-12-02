
module RunTestCases;

import App.Graph;

import SteelRT.Test;


import SteelRT.Util.Sequence;
import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.App;

import SteelRT.Task.Descriptor;
import SteelRT.Task.DescriptorState;
import SteelRT.Task.DescriptorPoisonPill;
import SteelRT.Dep.Guard.Backend;
// import App.Traits;

import <vector>;

///////////////////// COMMON STUFF

const depth_t depth = 0;
std::vector<youth_t> recordedYouths;


// --------------------------- check_attr_state

template <app::id AppId, app::impl AppImpl, app::call AppCall>
static
void test_attr_state() {

  task::poly_descriptor newDesc( util::identity<AppId, AppImpl, AppCall>{}, depth, global::AllSolvedMask );


  const auto& attrDesc = static_cast<const task::attr::descriptor&>(newDesc);
  // Check word size
  static_assert( sizeof(attrDesc) <= sizeof(size_t) );

  // Check correct ids
  if (attrDesc.appId != static_cast<enum_uint_t>(AppId)) {
    throw std::logic_error("Wrong runtime app::id");
  }
  if (attrDesc.appCall != static_cast<enum_uint_t>(AppCall)) {
    throw std::logic_error("Wrong runtime app::call");
  }
  if (attrDesc.get_app_index() != static_cast<enum_uint_t>(attrDesc.appId)) {
    throw std::logic_error("Wrong runtime task index");
  }

  // To check increasing youth with app index if it is not poison pill
  if constexpr (AppId != app::id::poison_pill) {
    recordedYouths.push_back(attrDesc.youth);
  }


  const auto& stateDesc = static_cast<const task::state::descriptor&>(newDesc);

  if (stateDesc.get_implementation() != AppImpl) {
    throw std::logic_error("Wrong runtime app::impl");
  }

  if (stateDesc.get_defer() != 0) {
      throw std::logic_error("Wrong initialized defer");
  }
  if (stateDesc.get_solved_mask() != global::AllSolvedMask) {
      throw std::logic_error("Wrong initialized solved mask");
  }
}

static
void test_attr_state_poison_pill() {

  task::poison_pill::descriptor ppDesc;

  const auto& attrDesc = static_cast<const task::attr::descriptor&>(ppDesc);

  // Check word size
  static_assert( sizeof(attrDesc) <= sizeof(size_t) );

  // Check correct ids
  if (attrDesc.appId != global::PoisonPillAppIndex) {
    throw std::logic_error("Wrong runtime app::id");
  }
  if (attrDesc.get_app_index() != static_cast<enum_uint_t>(attrDesc.appId)) {
    throw std::logic_error("Wrong runtime task index");
  }
  if (attrDesc.appCall != global::PoisonPillCallIndex) {
    throw std::logic_error("Wrong runtime app::call");
  }

  const auto& stateDesc = static_cast<const task::state::descriptor&>(ppDesc);

  if (static_cast<enum_uint_t>(stateDesc.get_implementation()) != global::PoisonPillImplIndex) {
    throw std::logic_error("Wrong runtime app::id");
  }
  if (stateDesc.get_defer() != 0) {
      throw std::logic_error("Wrong initialized defer");
  }
  if (stateDesc.get_solved_mask() != global::AllSolvedMask) {
      throw std::logic_error("Wrong initialized solved mask");
  }
}


template <app::id AppId, app::impl AppImpl, app::call... AppCalls>
static
void test_attr_state_all_calls(util::sequence::enum_t<app::call, AppCalls...>) {

  static_assert( not util::sequence::empty_v< typename app::traits<AppImpl>::call_sequence > ); // non empty

  ( test_attr_state<AppId, AppImpl, AppCalls>(), ... );
}

template <app::id AppId, app::impl... AppImpls>
static
void test_attr_state_all_impls(util::sequence::enum_t<app::impl, AppImpls...>) {

  if constexpr (AppId != app::id::poison_pill) {

    static_assert( not util::sequence::empty_v< typename app::traits<AppId>::impl_sequence > ); // non empty

    ( test_attr_state_all_calls<AppId, AppImpls>(typename app::traits<AppImpls>::call_sequence{}), ... );

  } else {

    // No longer. because we have introduced a poison_pill_k implementation artifact
    // static_assert( util::sequence::empty_v< typename app::traits<AppId>::impl_sequence > ); // always empty

    test_attr_state_poison_pill();
  }
}

template <app::id... AppIds>
static
void test_attr_state_all(util::sequence::enum_t<app::id, AppIds...>) {
  ( test_attr_state_all_impls<AppIds>( typename app::traits<AppIds>::impl_sequence{}  ), ... );
}

// --------------------------- tuple_cast

template <app::call AppCall, std::size_t Id>
static
auto init_tuple_arg() {
  return util::tuple::element_t<Id, typename app::traits<AppCall>::arg_tuple_type>();
}

template <app::call AppCall, std::size_t... Ids>
static
void test_tuple_cast(std::index_sequence<Ids...>) {

  using tuple_t = typename app::traits<AppCall>::arg_tuple_type;

  using desc_t = task::descriptor<AppCall, util::tuple::as_std_t<tuple_t>>;

  auto descUPtr = std::make_unique< desc_t >( depth, init_tuple_arg<AppCall, Ids>() ... );

  // Upcast
  auto polyDescPtr = static_cast< task::poly_descriptor* >( descUPtr.get() );

  // Downcast, try upcast
  auto tuplePtr = dynamic_cast< util::tuple::as_std_t<tuple_t>* >( static_cast<desc_t*>( polyDescPtr ) );

  if (not tuplePtr) {
    throw std::logic_error("Casting to call tuple arg failed");
  }
}

template <app::call... AppCalls>
static
void test_tuple_cast_all_calls(util::sequence::enum_t<app::call, AppCalls...>) {

  ( test_tuple_cast<AppCalls>(std::make_index_sequence<app::traits<AppCalls>::arg_tuple_type::size()>{}), ... );
}

template <app::id AppId, app::impl... AppImpls>
static
void test_tuple_cast_all_impls(util::sequence::enum_t<app::impl, AppImpls...>) {

  if constexpr (AppId != app::id::poison_pill) {
    ( test_tuple_cast_all_calls( typename app::traits<AppImpls>::call_sequence{} ), ... );
  }
}

template <app::id... AppIds>
static
void test_tuple_cast_all(util::sequence::enum_t<app::id, AppIds...>) {
  ( test_tuple_cast_all_impls<AppIds>( typename app::traits<AppIds>::impl_sequence{} ), ... );
}



////////////////////////////////// TEST CASES

namespace test {

// --------------------------- check_attr_state

template <>
void runner::run_case<case_id::check_attr_state>() {

  test_attr_state_all( app::enabled_ids{} );
}

template <>
void runner::verify_case<case_id::check_attr_state>() {
  // Verify youths uniqueness

  auto nRecorded = recordedYouths.size();

  recordedYouths.resize(std::distance(std::begin(recordedYouths), std::unique(std::begin(recordedYouths), std::end(recordedYouths))));

  auto nRecordedAfterUnique = recordedYouths.size();

  if (nRecorded != nRecordedAfterUnique) {
    throw std::logic_error("Youths are not unique");
  }
}


// --------------------------- tuple_cast

template <>
void runner::run_case<case_id::tuple_cast>() {
  test_tuple_cast_all( app::enabled_ids{} );
}

template <>
void runner::verify_case<case_id::tuple_cast>() {
  // Nothing more to verify
}

} // namespace test

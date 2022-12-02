

export module SteelRT.Learn.Interface.Message.Typed;


// No need to import Pack.

import SteelRT.Util.Types;
import SteelRT.Util.Require;
import SteelRT.Util.App;

import SteelRT.Learn.Types;


export
namespace learn::intf::msg {


// ======================== DEFINITIONS BASED ON msg::ctg

// Here we can add more traits at will

template <msg::ctg MsgCtg>
struct traits;

// Tasking messages do have a key
template <>
struct traits<msg::ctg::tasking> {
  using key_type = msg::task_id_t;
  using action_type = app::impl;
  key_type keyValue = 0;
  traits() : keyValue(std::numeric_limits<key_type>::max()) {}
  traits(key_type kv) : keyValue(kv) {}
};

// Threading messages don't have a key in principle
template <>
struct traits<msg::ctg::threading> {
  using key_type = void;
  using action_type = thread_count_t;
  traits() {}
};


// ======================= DEFINITIONS BASED ON msg::kind

// These are fixed

template <msg::ctg MsgCtg, msg::kind MsgKind, typename InputStateT>
struct typed;

/////////////////// INFERENCE_START
template <msg::ctg MsgCtg>
struct typed <MsgCtg, msg::kind::inference_start, void> : traits<MsgCtg> {
  using base_traits = traits<MsgCtg>;
  static constexpr msg::kind msg_kind = msg::kind::inference_start;

  template <typename... KeyT> 
  typed(KeyT&&... keyVal) : base_traits(std::forward<KeyT>(keyVal)...) {}
};


/////////////////// INFERENCE_END
template <msg::ctg MsgCtg, typename InputStateT>
struct typed <MsgCtg, msg::kind::inference_end, InputStateT> : traits<MsgCtg> {
  using base_traits = traits<MsgCtg>;
  using key_type = typename base_traits::key_type;
  using action_type = typename base_traits::action_type;
  using input_state_type = InputStateT;
  static constexpr msg::kind msg_kind = msg::kind::inference_end;

  version_t paramVersion; 
  float computeLoad; // Needed to estimate the reward
  action_type actionValue;
  input_state_type stateValue;

  template <typename... KeyT> 
  typed(version_t pv, float cl, action_type av, input_state_type sv, KeyT&&... keyVal) : base_traits(std::forward<KeyT>(keyVal)...), paramVersion(pv), computeLoad(cl), actionValue(av), stateValue(sv) {}
};

/////////////////// END
template <msg::ctg MsgCtg>
struct typed <MsgCtg, msg::kind::end, void> : traits<MsgCtg> {
  using base_traits = traits<MsgCtg>;
  static constexpr msg::kind msg_kind = msg::kind::end;

  template <typename... KeyT> 
  typed(KeyT&&... keyVal) : base_traits(std::forward<KeyT>(keyVal)...) {}
};


// ======================= USEFUL PREDICATES

template <typename MsgTyped>
struct no_key : std::is_same< typename MsgTyped::key_type, void > {};

template <typename MsgTyped>
struct has_key : std::negation< no_key<MsgTyped> > {};


template <typename MsgTyped>
struct has_content : util::same< MsgTyped::msg_kind, msg::kind::inference_end > {};

template <typename MsgTyped>
struct no_content : std::negation< has_content<MsgTyped> > {};

template <typename MsgTyped>
struct is_end : util::same< MsgTyped::msg_kind, msg::kind::end > {};

template <typename MsgTyped>
struct is_inference_start : util::same< MsgTyped::msg_kind, msg::kind::inference_start > {};






} // namespace learn::intf::msg

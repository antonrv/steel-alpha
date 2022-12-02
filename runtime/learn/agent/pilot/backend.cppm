
export module SteelRT.Learn.Agent.Pilot.Backend;

import SteelRT.Learn.Interface.Message.Pack;
import SteelRT.Learn.Interface.Message.Typed;

import SteelRT.Learn.Agent.Pilot.Threader.Single;
import SteelRT.Learn.Agent.Pilot.Implementer;

import SteelRT.Learn.Types;

import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Instrument;

import SteelRT.Util.Assert;
#include "assert.hpp"

import SteelRT.Instrument;

export import <map>;
export import <queue>;

export import <mutex>;
export import <condition_variable>;

///////// Asynchronous interface to refine the weights of MsgCtg decisions


namespace learn::agent::pilot {


export
template <intf::msg::ctg MsgCtg, typename AgentPilotT>
class backend {
private:

  using agent_pilot_t = AgentPilotT;
  // agent::pilot::implementer<ProcId, AppGroupT, NativeT>;
  // agent::pilot::threader_single<ProcId, NativeT>

  agent_pilot_t m_agentPilot;

  using rethrow_callback_t = std::function<void(std::exception_ptr)>;

  rethrow_callback_t m_rethrowCallback = nullptr;


public: // This works as a pilot ContextT, so this must expose the following

  static constexpr plat::processor processor_id = AgentPilotT::processor_id;

  using input_state_type = typename agent_pilot_t::input_state_type;

  using action_type = typename agent_pilot_t::action_type;

  bool m_tearDown = false;


private: //// USEFUL GENERIC TYPES

  template <intf::msg::kind MsgKind> 
  struct this_typed { using type = intf::msg::typed<MsgCtg, MsgKind, void>; };

  template <> 
  struct this_typed<intf::msg::kind::inference_end> { using type = intf::msg::typed<MsgCtg, intf::msg::kind::inference_end, input_state_type>; };

  template <intf::msg::kind MsgKind> 
  using typed_t = typename this_typed<MsgKind>::type;

  template <intf::msg::kind MsgKind>
  using msg_t = std::pair< intf::msg::time_point_t, typed_t<MsgKind> >;

  template <intf::msg::kind MsgKind>
  using msg_batch_t = std::vector< msg_t<MsgKind> >;

  template <typename MsgT>
  struct has_key : intf::msg::has_key< typename MsgT::second_type > {};

  template <typename MsgT>
  struct no_key : std::negation< has_key<MsgT> > {};

  template <typename MsgT>
  struct has_content : intf::msg::has_content< typename MsgT::second_type > {};

  template <typename MsgT>
  struct is_end : intf::msg::is_end< typename MsgT::second_type > {};

  template <typename MsgT>
  struct is_not_end : std::negation< is_end<MsgT> > {};



  template <intf::msg::kind MsgKind, template <intf::msg::kind > class ContT>
  struct message_container {
    using container_t = ContT< MsgKind >;
    container_t containerObj;
    std::mutex mtx;
    std::condition_variable cv;
  };

  template <typename KeyT>
  struct map_of {
    template <intf::msg::kind MsgKind>
    using type = std::map< KeyT, msg_t<MsgKind> >;
  };

  template <intf::msg::kind MsgKind>
  using queue_t = std::queue< msg_t<MsgKind> >;


  using kind_seq = util::sequence::enum_t<intf::msg::kind, intf::msg::kind::inference_start, intf::msg::kind::inference_end, intf::msg::kind::end>;

  template <typename KeyT>
  using key_containers = std::tuple<
      message_container<intf::msg::kind::inference_start, map_of<KeyT>::template type>,
      message_container<intf::msg::kind::inference_end, map_of<KeyT>::template type>,
      message_container<intf::msg::kind::end, queue_t>
    >;

  using no_key_containers = std::tuple<
      message_container<intf::msg::kind::inference_start, queue_t>,
      message_container<intf::msg::kind::inference_end, queue_t>,
      message_container<intf::msg::kind::end, queue_t>
    >;

  using containers_t = std::conditional_t<
      std::is_same_v<typename intf::msg::traits<MsgCtg>::key_type, void>,
      no_key_containers,
      key_containers< typename intf::msg::traits<MsgCtg>::key_type >
    >;

  containers_t m_containers;

  uint_t m_maxBatchSize = 0;


  approx::ann::batch_rewards_t m_batchRewards;
  approx::ann::batch_states_t<input_state_type> m_batchPrevStates;
  approx::ann::batch_actions_t<action_type> m_batchActions;


public:

  backend( const learn::pilot::cfg& pilotCfg, rethrow_callback_t&& rcb ) :
    m_agentPilot(pilotCfg),
    m_maxBatchSize(pilotCfg.miniBatchSize),
    m_batchRewards(m_maxBatchSize),
    m_batchPrevStates(m_maxBatchSize),
    m_batchActions(m_maxBatchSize),
    m_rethrowCallback(rcb)
  {}


  void tear_down() {

    m_tearDown = true;

    // push empty msg just to notify; // Won't be read since m_tearDown will be read first
    push( std::make_pair( intf::msg::time_point_t(), typed_t<intf::msg::kind::end>()) );
  }


private: // aux methods

  template <intf::msg::kind MsgKind> 
  using message_container_of = std::tuple_element_t< util::sequence::get_index_v<kind_seq, MsgKind>, containers_t >;
 
  template <intf::msg::kind MsgKind> 
  auto container_ptr() noexcept {
    return &std::get< message_container_of<MsgKind> >( m_containers ).containerObj;
  }

  template <intf::msg::kind MsgKind> 
  auto container_ptr() const noexcept {
    return &std::get< message_container_of<MsgKind> >( m_containers ).containerObj;
  }

  template <intf::msg::kind MsgKind> 
  std::condition_variable& get_cv_ref() noexcept {
    return std::get< message_container_of<MsgKind> >( m_containers ).cv;
  }

  template <intf::msg::kind MsgKind> 
  auto acquire_container() noexcept {
    return std::make_pair(
        std::unique_lock<std::mutex>( std::get< message_container_of<MsgKind> >( m_containers ).mtx ),
        container_ptr<MsgKind>() );
  }

  template <intf::msg::kind MsgKind> 
  bool has_messages() const noexcept {
    return (not container_ptr<MsgKind>()->empty());
  }

public: /////////////// PUSH functions (to be called main thread)

  template < typename MsgT, util::req_t< std::conjunction<has_key<MsgT>, is_not_end<MsgT>> > ...  >
  void push( MsgT&& pairMsg ) {

    using typed_msg_t = typename MsgT::second_type;
    static constexpr intf::msg::kind MsgKind = typed_msg_t::msg_kind;

    instr::trace<instr::event::ipc_msg_queue::push>("not_end msg, with key", std::get<typed_msg_t>(pairMsg).keyValue);

    auto [uLck, containerPtr] = acquire_container<MsgKind>();
    // Emplace into a std::map
    containerPtr->emplace( std::make_pair( std::get<typed_msg_t>(pairMsg).keyValue, std::forward<msg_t<MsgKind>>(pairMsg) ) );
  }


  template < typename MsgT, util::req_t< std::conjunction<no_key<MsgT>, is_not_end<MsgT>> > ...  >
  void push( MsgT&& pairMsg ) {

    using typed_msg_t = typename MsgT::second_type;
    static constexpr intf::msg::kind MsgKind = typed_msg_t::msg_kind;

    auto [uLck, containerPtr] = acquire_container<MsgKind>();
    // Emplace into a std::queue
    containerPtr->emplace( std::forward<MsgT>( pairMsg ) );
  }
 
 
  template < typename MsgT, util::req_t< is_end<MsgT> > ...  >
  void push( MsgT&& pairMsg ) {

    if constexpr (has_key<MsgT>::value) {
      instr::trace<instr::event::ipc_msg_queue::push>("end msg, with key", pairMsg.second.keyValue);
    } else {
      instr::trace<instr::event::ipc_msg_queue::push>("end msg, no key");
    }

    {
      auto [uLck, containerPtr] = acquire_container<intf::msg::kind::end>();
      // Emplace into a std::queue
      containerPtr->emplace( std::forward<MsgT>( pairMsg ) ); 
    }
    // Notify, because pilot thread may be passively awaiting for this
    get_cv_ref<intf::msg::kind::end>().notify_one();
  }


private: // Called by the pilot thread

  msg_t<intf::msg::kind::end> await_end_message( ) {

    auto [ uLck, containerPtr ] = acquire_container<intf::msg::kind::end>();

    // if (containerPtr->empty() and (not terminate_condition())) {
    if ( containerPtr->empty() ) {
      auto& cvRef = get_cv_ref<intf::msg::kind::end>();

      instr::trace<instr::event::ipc_msg_queue::await_end>();

      // cvRef.wait( uLck, [containerPtr]() { return (not containerPtr->empty()); } );
      cvRef.wait( uLck, [this]() { return has_messages<intf::msg::kind::end>(); } );
    }

    instr::trace<instr::event::ipc_msg_queue::process_end>();

    auto msgToProcess = containerPtr->front();

    containerPtr->pop();

    return msgToProcess;
  }


private: // Called by the pilot thread (only inference_start, inference_end allowed)

  template <intf::msg::kind MsgKind, typename MsgT,
    util::req_t< std::conjunction< is_end<MsgT>, has_key<MsgT>, util::not_same<MsgKind, intf::msg::kind::end> > > ...
  >
  msg_t<MsgKind> find_previous_message( const MsgT& endMsg ) {

    auto [ uLck, containerPtr ] = acquire_container<MsgKind>();

    auto foundIt = containerPtr->find( std::get<typed_t<intf::msg::kind::end>>(endMsg).keyValue );

    if (foundIt == containerPtr->end()) {
      // It may be useful to return an optional and not throw because the IPC queue has fixed size and senders use a try_send semantics, so senders may fail to send some data.
      // However it is unlikely that this queue will be saturated, so we throw just in case
      throw std::runtime_error("Could not find previous message in map with key : " + std::to_string(std::get<typed_t<intf::msg::kind::end>>(endMsg).keyValue));
    }

    msg_t<MsgKind> retMsg = foundIt->second;

    containerPtr->erase( foundIt );

    instr::trace<instr::event::ipc_msg_queue::found_previous>("with key", std::get<typed_t<intf::msg::kind::end>>(endMsg).keyValue );

    return retMsg;
  }


  template <intf::msg::kind MsgKind, typename MsgT,
    util::req_t< std::conjunction< is_end<MsgT>, no_key<MsgT>, util::not_same<MsgKind, intf::msg::kind::end> > > ...
  >
  msg_t<MsgKind> find_previous_message( const MsgT& endMsg ) {

    auto [ uLck, containerPtr ] = acquire_container<MsgKind>();

    if (containerPtr->empty()) {

      throw std::runtime_error("Could not find previous message in queue");
    }

    auto retMsg = containerPtr->front();

    containerPtr->pop();

    return retMsg;
  }


private: // Called by the pilot thread


  void learn_batch( const msg_batch_t<intf::msg::kind::inference_start>& batchInferenceStart, const msg_batch_t<intf::msg::kind::inference_end>& batchInferenceEnd, const msg_batch_t<intf::msg::kind::end>& batchEnd ) {

    const auto batchSize = batchInferenceStart.size();

    if (batchSize < 1) {
      return;
    }

    if (not (batchInferenceStart.size() == batchInferenceEnd.size() and batchInferenceEnd.size() == batchEnd.size())) {
      throw std::logic_error("Batch sizes must have the same number of elements : " + std::to_string(batchInferenceStart.size()) + ", " + std::to_string(batchInferenceEnd.size()) + ", " + std::to_string(batchEnd.size()));
    }

    m_batchRewards.resize( batchSize );
    m_batchPrevStates.resize( batchSize );
    m_batchActions.resize( batchSize );

    for (auto s = 0u; s < batchSize; s++) {

      const msg_t<intf::msg::kind::inference_start>& inferenceStartMsg = batchInferenceStart[s];
      const msg_t<intf::msg::kind::inference_end>& inferenceEndMsg = batchInferenceEnd[s];
      const msg_t<intf::msg::kind::end>& endMsg = batchEnd[s];

      m_batchPrevStates.edit_values(s) = std::get<typed_t<intf::msg::kind::inference_end>>(inferenceEndMsg).stateValue;
      
      m_batchActions.edit_values(s)[0] = std::get<typed_t<intf::msg::kind::inference_end>>(inferenceEndMsg).actionValue;

      intf::msg::delay_t inferenceDelay = std::get<intf::msg::time_point_t>(inferenceEndMsg) - std::get<intf::msg::time_point_t>(inferenceStartMsg);

      intf::msg::delay_t costDelay = std::get<intf::msg::time_point_t>(endMsg) - std::get<intf::msg::time_point_t>(inferenceEndMsg);

      auto computeLoad = std::get<typed_t<intf::msg::kind::inference_end>>(inferenceEndMsg).computeLoad;

      m_batchRewards.edit_values(s)[0] = computeLoad / costDelay.count(); // -1.f*costDelay.count()

        // instr::trace<instr::event::learn_monitor::update_step>( (uint_t)MsgCtg, inputState, (uint_t)chosenAction, reward, inferenceDelay.count(), costDelay.count() );

      // In this kind of RL model (single-step episode) we perform the unique actor-critic update setting first the state ...
    }

    m_agentPilot.update_batch( m_batchRewards, m_batchPrevStates, m_batchActions );

      // instr::trace<instr::event::learn_monitor::update_result>( (uint_t)MsgCtg, updateInfo.tdError, updateInfo.avgReward, updateInfo.prevStateValue, updateInfo.curStateValue );
  }


private: // Called by the pilot thread

  bool terminate_condition() const noexcept {
    // The 'OR' relaxes the termination condition in case of failure in sending messages
    return ((not has_messages<intf::msg::kind::inference_start>()) or (not has_messages<intf::msg::kind::inference_end>())) and m_tearDown;
    // return m_tearDown;
  }


public: // The function on which the worker pilot is spawned into


  void loop ( uint_t thId ) {

    instr::subscribe_thread(thId, "ctg" + std::to_string((uint_t)MsgCtg) + "_th" + std::to_string(thId));

    try {

      msg_batch_t< intf::msg::kind::inference_start > batchInferenceStart;
      msg_batch_t< intf::msg::kind::inference_end > batchInferenceEnd;
      msg_batch_t< intf::msg::kind::end > batchEnd;

      version_t currentVersion = m_agentPilot.get_parameters_version();

      // Quiescent blocking
      batchEnd.push_back( this->await_end_message() );

      while (not terminate_condition()) {

        batchInferenceStart.push_back( find_previous_message<intf::msg::kind::inference_start>( batchEnd.back() ) );

        batchInferenceEnd.push_back( find_previous_message<intf::msg::kind::inference_end>( batchEnd.back() ) );

        if (std::get<typed_t<intf::msg::kind::inference_end>>(batchInferenceEnd.back()).paramVersion != currentVersion) {
          // Message not based on current version, so discard
          batchInferenceStart.pop_back();
          batchInferenceEnd.pop_back();
          batchEnd.pop_back();
        }

        if ( batchInferenceStart.size() == m_maxBatchSize ) {

          learn_batch( batchInferenceStart, batchInferenceEnd, batchEnd );

          batchInferenceStart.clear();
          batchInferenceEnd.clear();
          batchEnd.clear();

          currentVersion = m_agentPilot.get_parameters_version();

        } else {

          // Keep collecting samples
        }

        // Quiescent blocking
        batchEnd.push_back( this->await_end_message() );
      }

      // Process remaining batch
      batchEnd.pop_back(); // Remove termination msg
      learn_batch( batchInferenceStart, batchInferenceEnd, batchEnd );

      m_agentPilot.trace_learning_summary();

    } catch (...) {

      instr::trace<instr::event::ipc_msg_queue::fini>( "rethrowing to master" );
      m_rethrowCallback( std::current_exception() );
    }

    instr::trace<instr::event::ipc_msg_queue::fini>( "joinable" );
  }

};

} // namespace learn::agent::pilot

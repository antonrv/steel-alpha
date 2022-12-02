
export module SteelRT.Learn.Agent.Pilot.ActorCritic;

import SteelRT.Learn.Approx.NeuralNet.Layer.Values;


import SteelRT.Util.Basic;
import SteelRT.Util.Meta;

import SteelRT.Learn.Types;

import SteelRT.Instrument;

export import <set>;

import SteelRT.Util.Assert;
#include "assert.hpp"

export import <cmath>;


namespace learn::agent::pilot {

export
template <typename ActorT, typename CriticT>
class actor_critic {
private:

  using actor_t = ActorT;
  using critic_t = CriticT;

  static_assert( std::is_same_v<typename ActorT::input_layer_type, typename CriticT::input_layer_type> );

  using input_state_t = typename ActorT::input_layer_type::state_type;

  using action_type = typename ActorT::action_type;


private: // members


  actor_t m_actor;

  critic_t m_critic;


  approx::ann::batch_errors_t m_errors;


  // Store a unique set of input states
  std::set< input_state_t > m_summaryInputStates;
  static constexpr std::size_t MaxInputStates = global::MaxBatchSize; // To avoid ubound growth

public:

  actor_critic( const learn::pilot::cfg& pilotCfg, str_t actorIdStr, str_t criticIdStr ) :
    m_actor( actorIdStr, pilotCfg ),
    m_critic( criticIdStr, pilotCfg ),
    m_errors(pilotCfg.miniBatchSize)
  {}



  // Assuming transition to final state
  void update_batch( const approx::ann::batch_rewards_t& rewards, const approx::ann::batch_states_t<input_state_t>& prevStates, const approx::ann::batch_actions_t<action_type>& chosenActions ) {

    const auto batchSize = rewards.get_batch_size();
    ensure(batchSize == prevStates.get_batch_size(), "Mismatch in batch sizes");
    ensure(batchSize == chosenActions.get_batch_size(), "Mismatch in batch sizes");

    // Fwd prop on critic internally done
    const auto& prevStatesValues = m_critic.get_values( prevStates );

    m_errors.resize( batchSize );

    for (auto s = 0u; s < batchSize; s++) {

      ensure( not std::isnan(prevStatesValues.get_values(s)[0]), "Verify fwd prop output");

      m_errors.edit_values(s)[0] = (rewards.get_values(s)[0] - prevStatesValues.get_values(s)[0]);

      instr::trace<instr::event::learn_monitor::backprop_start>( s, prevStates.get_values(s), prevStatesValues.get_values(s)[0], rewards.get_values(s)[0], m_errors.get_values(s)[0] );

      if (m_summaryInputStates.size() < MaxInputStates) {
        m_summaryInputStates.insert( prevStates.get_values(s) );
      }
    }

    // instr::trace<instr::event::training::update_batch>( "ACTOR-UPDATE with batch", batchSize );
 
    // m_actor.update( prevStates, m_errors, chosenActions ); // SKIPPED TO AVOID PLOTTING ACTOR PARAMETERS XXX XXX XXX

    instr::trace<instr::event::training::update_batch>( "CRITIC-UPDATE with batch", batchSize );

    m_critic.update( m_errors );

    // // TMP XXX DBG
    // if (1) {
    //   // TRigger fwd prop again 
    //   m_critic.get_values( prevStates );
    //   for (auto s = 0u; s < batchSize; s++) {
    //     instr::trace<instr::event::learn_monitor::backprop_start>("POS UPDATE CRITIC ACTIV", s, prevStatesValues.get_values(s)[0] );
    //   }
    // }
  }


  version_t get_parameters_version() const noexcept {

    return m_actor.get_parameters_version();
  }


  void trace_learning_summary( ) {

    if (m_summaryInputStates.empty()) {
      instr::trace<instr::event::learn_monitor::summary>( "No stored summary states", 0 );
      return;
    }

    // Create batch
    approx::ann::batch_states_t<input_state_t> uniqueStates( m_summaryInputStates.size() );

    auto s = 0u;
    for (const auto& inputState : m_summaryInputStates) { 
      uniqueStates.edit_values( s ) = inputState; // copy
      s++;
    }

    const auto& stateValues = m_critic.get_values( uniqueStates );

    // const auto& actorActivations = m_actor.get_activations( uniqueStates ); // OMITTED XXX DEBUG

    for (auto s = 0u; s < m_summaryInputStates.size(); s++) {
      // Change "Discrete" depending on actor info (eg tasking/threading) TODO
      // instr::trace<instr::event::learn_monitor::summary>( "Discrete", uniqueStates.get_values(s), stateValues.get_values(s)[0], actorActivations.get_values(s) );
      instr::trace<instr::event::learn_monitor::summary>( "Discrete", uniqueStates.get_values(s), stateValues.get_values(s)[0] );
    }
  }

};


} // namespace learn::agent::pilot

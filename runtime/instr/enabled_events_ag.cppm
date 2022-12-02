export module SteelRT.Instrument.EnabledEvents;

// Need to export, so that they are visible in contexts where trace is called
export import SteelRT.Instrument.AllEvents;

import SteelRT.Util.Types;

namespace instr::event {

export
using enabled_tuple = util::tuple_t<
  ctxt_active,
  ctxt_entry,
  agent_executor,
  agent_cooperator,
  coro_dispatcher,
  coro_promise,
  coro_awaiter,
  queue_container,
  local_descriptor_queue,
  global_descriptor_queue,
  dispatcher_queue,
  policy_queue_compare,
  dep_solver,
  dep_update,
  dep_acquire,
  dep_execute,
  dep_dispatch,
  dep_commit
>;


} // namespace instr::event


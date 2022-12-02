

export module SteelRT.Util.FwDeclarations.Worker;

import SteelRT.Util.Types;
// import SteelRT.Util.Sequence;


export
namespace worker {

// Frozen

enum class opmode : enum_uint_t {
  offline, // Possible output of NN. When state change from offline to any other, a spawn is done.
  standby, // Possible output of NN. Worker awaits on a cv. Master do not wake up when there are threads on this state
  await_for_duty, // Set by worker, read by master. Notifies master to wake up to make a decision on this thread. Worker awaits on a cv.
  on_duty, // Possible output of NN. Normal operation mode. Associated to a workload::mission and a target proc id
  terminate, // Possible output of NN. Oposite of spawn.
  joinable // Set by worker, read by master. Master can join the thread after successful work.
};

enum class duty : enum_uint_t { operate_descriptor, operate_dispatcher_push, operate_dispatcher_extract, migrate_descriptor, migrate_dispatcher, undefined };

// using duty_defined_seq = util::sequence::enum_t< worker::duty, worker::duty::operate_descriptor,  worker::duty::operate_dispatcher_push, worker::duty::operate_dispatcher_extract, worker::duty::migrate_descriptor, worker::duty::migrate_dispatcher >;


enum class fun : enum_uint_t { push, try_pull, operate, operate_push, operate_extract, resumer_push };

enum class target : enum_uint_t { local, remote };

} // namespace worker

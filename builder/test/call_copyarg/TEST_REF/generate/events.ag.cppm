//////////////////////////////////////
// 
// Autogenerated file. Do not modify. 
// 
//////////////////////////////////////

export module SteelRT.Instrument.AllEvents;
import SteelRT.Util.Types;
import SteelRT.Util.Values;
import SteelRT.Util.Sequence;
import SteelRT.Instrument.FwDeclarations;
export
namespace instrument::event{enum class agent_cooperator : enum_uint_t {depleted_dispatcher = 2,end_run = 3,setting_repush_function = 4,setting_resume_function = 5,skipping_repush_function = 6,skipping_resume_function = 7,start_run = 8,trying_resume = 9};using enabled_agent_cooperators = util::sequence::enum_t<agent_cooperator,agent_cooperator::depleted_dispatcher,agent_cooperator::end_run,agent_cooperator::setting_repush_function,agent_cooperator::setting_resume_function,agent_cooperator::skipping_repush_function,agent_cooperator::skipping_resume_function,agent_cooperator::start_run,agent_cooperator::trying_resume>;}
export
namespace instrument::event{template <> struct type<instrument::event::agent_cooperator>{static constexpr const char * name = "agent_cooperator";
static constexpr const enum_type_id_t type_id = 0;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::agent_cooperator::depleted_dispatcher>{static constexpr const char * name = "depleted_dispatcher";}
;template <> struct value<instrument::event::agent_cooperator::end_run>{static constexpr const char * name = "end_run";}
;template <> struct value<instrument::event::agent_cooperator::setting_repush_function>{static constexpr const char * name = "setting_repush_function";}
;template <> struct value<instrument::event::agent_cooperator::setting_resume_function>{static constexpr const char * name = "setting_resume_function";}
;template <> struct value<instrument::event::agent_cooperator::skipping_repush_function>{static constexpr const char * name = "skipping_repush_function";}
;template <> struct value<instrument::event::agent_cooperator::skipping_resume_function>{static constexpr const char * name = "skipping_resume_function";}
;template <> struct value<instrument::event::agent_cooperator::start_run>{static constexpr const char * name = "start_run";}
;template <> struct value<instrument::event::agent_cooperator::trying_resume>{static constexpr const char * name = "trying_resume";}
;}export
namespace instrument::event{enum class agent_executor : enum_uint_t {create_dispatcher_end = 2,create_dispatcher_start = 3,end_run = 4,received_poison_pill = 5,run_kernel_end = 6,run_kernel_start = 7,start_run = 8};using enabled_agent_executors = util::sequence::enum_t<agent_executor,agent_executor::create_dispatcher_end,agent_executor::create_dispatcher_start,agent_executor::end_run,agent_executor::received_poison_pill,agent_executor::run_kernel_end,agent_executor::run_kernel_start,agent_executor::start_run>;}
export
namespace instrument::event{template <> struct type<instrument::event::agent_executor>{static constexpr const char * name = "agent_executor";
static constexpr const enum_type_id_t type_id = 1;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::agent_executor::create_dispatcher_end>{static constexpr const char * name = "create_dispatcher_end";}
;template <> struct value<instrument::event::agent_executor::create_dispatcher_start>{static constexpr const char * name = "create_dispatcher_start";}
;template <> struct value<instrument::event::agent_executor::end_run>{static constexpr const char * name = "end_run";}
;template <> struct value<instrument::event::agent_executor::received_poison_pill>{static constexpr const char * name = "received_poison_pill";}
;template <> struct value<instrument::event::agent_executor::run_kernel_end>{static constexpr const char * name = "run_kernel_end";}
;template <> struct value<instrument::event::agent_executor::run_kernel_start>{static constexpr const char * name = "run_kernel_start";}
;template <> struct value<instrument::event::agent_executor::start_run>{static constexpr const char * name = "start_run";}
;}export
namespace instrument::event{enum class coro_awaiter : enum_uint_t {await_suspend = 2,compatible_task = 3,constructor = 4,destructor = 5,not_compatible_task = 6};using enabled_coro_awaiters = util::sequence::enum_t<coro_awaiter,coro_awaiter::await_suspend,coro_awaiter::compatible_task,coro_awaiter::constructor,coro_awaiter::destructor,coro_awaiter::not_compatible_task>;}
export
namespace instrument::event{template <> struct type<instrument::event::coro_awaiter>{static constexpr const char * name = "coro_awaiter";
static constexpr const enum_type_id_t type_id = 2;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::coro_awaiter::await_suspend>{static constexpr const char * name = "await_suspend";}
;template <> struct value<instrument::event::coro_awaiter::compatible_task>{static constexpr const char * name = "compatible_task";}
;template <> struct value<instrument::event::coro_awaiter::constructor>{static constexpr const char * name = "constructor";}
;template <> struct value<instrument::event::coro_awaiter::destructor>{static constexpr const char * name = "destructor";}
;template <> struct value<instrument::event::coro_awaiter::not_compatible_task>{static constexpr const char * name = "not_compatible_task";}
;}export
namespace instrument::event{enum class coro_dispatcher : enum_uint_t {constructor = 2,destroying_handle = 3,destructor = 4,error = 5,handle_acquired = 6,handle_alive = 7,handle_finalized = 8,handle_released = 9,handle_used = 10,move_constructor = 11,reseting_done = 12,state_size = 13,tried_deque = 14,try_acq_actual = 15,try_acq_new = 16,try_acq_prev = 17,try_reset_new = 18,try_reset_prev = 19,trying_resume = 20};using enabled_coro_dispatchers = util::sequence::enum_t<coro_dispatcher,coro_dispatcher::constructor,coro_dispatcher::destroying_handle,coro_dispatcher::destructor,coro_dispatcher::error,coro_dispatcher::handle_acquired,coro_dispatcher::handle_alive,coro_dispatcher::handle_finalized,coro_dispatcher::handle_released,coro_dispatcher::handle_used,coro_dispatcher::move_constructor,coro_dispatcher::reseting_done,coro_dispatcher::state_size,coro_dispatcher::tried_deque,coro_dispatcher::try_acq_actual,coro_dispatcher::try_acq_new,coro_dispatcher::try_acq_prev,coro_dispatcher::try_reset_new,coro_dispatcher::try_reset_prev,coro_dispatcher::trying_resume>;}
export
namespace instrument::event{template <> struct type<instrument::event::coro_dispatcher>{static constexpr const char * name = "coro_dispatcher";
static constexpr const enum_type_id_t type_id = 3;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::coro_dispatcher::constructor>{static constexpr const char * name = "constructor";}
;template <> struct value<instrument::event::coro_dispatcher::destroying_handle>{static constexpr const char * name = "destroying_handle";}
;template <> struct value<instrument::event::coro_dispatcher::destructor>{static constexpr const char * name = "destructor";}
;template <> struct value<instrument::event::coro_dispatcher::error>{static constexpr const char * name = "error";}
;template <> struct value<instrument::event::coro_dispatcher::handle_acquired>{static constexpr const char * name = "handle_acquired";}
;template <> struct value<instrument::event::coro_dispatcher::handle_alive>{static constexpr const char * name = "handle_alive";}
;template <> struct value<instrument::event::coro_dispatcher::handle_finalized>{static constexpr const char * name = "handle_finalized";}
;template <> struct value<instrument::event::coro_dispatcher::handle_released>{static constexpr const char * name = "handle_released";}
;template <> struct value<instrument::event::coro_dispatcher::handle_used>{static constexpr const char * name = "handle_used";}
;template <> struct value<instrument::event::coro_dispatcher::move_constructor>{static constexpr const char * name = "move_constructor";}
;template <> struct value<instrument::event::coro_dispatcher::reseting_done>{static constexpr const char * name = "reseting_done";}
;template <> struct value<instrument::event::coro_dispatcher::state_size>{static constexpr const char * name = "state_size";}
;template <> struct value<instrument::event::coro_dispatcher::tried_deque>{static constexpr const char * name = "tried_deque";}
;template <> struct value<instrument::event::coro_dispatcher::try_acq_actual>{static constexpr const char * name = "try_acq_actual";}
;template <> struct value<instrument::event::coro_dispatcher::try_acq_new>{static constexpr const char * name = "try_acq_new";}
;template <> struct value<instrument::event::coro_dispatcher::try_acq_prev>{static constexpr const char * name = "try_acq_prev";}
;template <> struct value<instrument::event::coro_dispatcher::try_reset_new>{static constexpr const char * name = "try_reset_new";}
;template <> struct value<instrument::event::coro_dispatcher::try_reset_prev>{static constexpr const char * name = "try_reset_prev";}
;template <> struct value<instrument::event::coro_dispatcher::trying_resume>{static constexpr const char * name = "trying_resume";}
;}export
namespace instrument::event{enum class coro_promise : enum_uint_t {await_transform = 2,building_resumable = 3,captured_error = 4,constructor = 5};using enabled_coro_promises = util::sequence::enum_t<coro_promise,coro_promise::await_transform,coro_promise::building_resumable,coro_promise::captured_error,coro_promise::constructor>;}
export
namespace instrument::event{template <> struct type<instrument::event::coro_promise>{static constexpr const char * name = "coro_promise";
static constexpr const enum_type_id_t type_id = 4;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::coro_promise::await_transform>{static constexpr const char * name = "await_transform";}
;template <> struct value<instrument::event::coro_promise::building_resumable>{static constexpr const char * name = "building_resumable";}
;template <> struct value<instrument::event::coro_promise::captured_error>{static constexpr const char * name = "captured_error";}
;template <> struct value<instrument::event::coro_promise::constructor>{static constexpr const char * name = "constructor";}
;}export
namespace instrument::event{enum class ctxt_active : enum_uint_t {activating = 2,blocked_to_listen = 3,constructor = 4,destructor = 5,doing_local_work = 6,entering_core_loop = 7,error_callback_unset = 8,error_caught = 9,error_forward_to_entry = 10,not_joinable = 11,ready_for_join = 12,share_succeeded = 13,sibling_handshake_end = 14,sibling_handshake_start = 15,steal_succeeded = 16,trying_cooperation_succeeded = 17,trying_to_cooperate = 18,waiting_to_join = 19,with_local_work = 20,without_local_work = 21,woken_up = 22,working_on_dispatchers_end = 23,working_on_dispatchers_start = 24,working_on_enqueued_end = 25,working_on_enqueued_start = 26};using enabled_ctxt_actives = util::sequence::enum_t<ctxt_active,ctxt_active::activating,ctxt_active::blocked_to_listen,ctxt_active::constructor,ctxt_active::destructor,ctxt_active::doing_local_work,ctxt_active::entering_core_loop,ctxt_active::error_callback_unset,ctxt_active::error_caught,ctxt_active::error_forward_to_entry,ctxt_active::not_joinable,ctxt_active::ready_for_join,ctxt_active::share_succeeded,ctxt_active::sibling_handshake_end,ctxt_active::sibling_handshake_start,ctxt_active::steal_succeeded,ctxt_active::trying_cooperation_succeeded,ctxt_active::trying_to_cooperate,ctxt_active::waiting_to_join,ctxt_active::with_local_work,ctxt_active::without_local_work,ctxt_active::woken_up,ctxt_active::working_on_dispatchers_end,ctxt_active::working_on_dispatchers_start,ctxt_active::working_on_enqueued_end,ctxt_active::working_on_enqueued_start>;}
export
namespace instrument::event{template <> struct type<instrument::event::ctxt_active>{static constexpr const char * name = "ctxt_active";
static constexpr const enum_type_id_t type_id = 5;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::ctxt_active::activating>{static constexpr const char * name = "activating";}
;template <> struct value<instrument::event::ctxt_active::blocked_to_listen>{static constexpr const char * name = "blocked_to_listen";}
;template <> struct value<instrument::event::ctxt_active::constructor>{static constexpr const char * name = "constructor";}
;template <> struct value<instrument::event::ctxt_active::destructor>{static constexpr const char * name = "destructor";}
;template <> struct value<instrument::event::ctxt_active::doing_local_work>{static constexpr const char * name = "doing_local_work";}
;template <> struct value<instrument::event::ctxt_active::entering_core_loop>{static constexpr const char * name = "entering_core_loop";}
;template <> struct value<instrument::event::ctxt_active::error_callback_unset>{static constexpr const char * name = "error_callback_unset";}
;template <> struct value<instrument::event::ctxt_active::error_caught>{static constexpr const char * name = "error_caught";}
;template <> struct value<instrument::event::ctxt_active::error_forward_to_entry>{static constexpr const char * name = "error_forward_to_entry";}
;template <> struct value<instrument::event::ctxt_active::not_joinable>{static constexpr const char * name = "not_joinable";}
;template <> struct value<instrument::event::ctxt_active::ready_for_join>{static constexpr const char * name = "ready_for_join";}
;template <> struct value<instrument::event::ctxt_active::share_succeeded>{static constexpr const char * name = "share_succeeded";}
;template <> struct value<instrument::event::ctxt_active::sibling_handshake_end>{static constexpr const char * name = "sibling_handshake_end";}
;template <> struct value<instrument::event::ctxt_active::sibling_handshake_start>{static constexpr const char * name = "sibling_handshake_start";}
;template <> struct value<instrument::event::ctxt_active::steal_succeeded>{static constexpr const char * name = "steal_succeeded";}
;template <> struct value<instrument::event::ctxt_active::trying_cooperation_succeeded>{static constexpr const char * name = "trying_cooperation_succeeded";}
;template <> struct value<instrument::event::ctxt_active::trying_to_cooperate>{static constexpr const char * name = "trying_to_cooperate";}
;template <> struct value<instrument::event::ctxt_active::waiting_to_join>{static constexpr const char * name = "waiting_to_join";}
;template <> struct value<instrument::event::ctxt_active::with_local_work>{static constexpr const char * name = "with_local_work";}
;template <> struct value<instrument::event::ctxt_active::without_local_work>{static constexpr const char * name = "without_local_work";}
;template <> struct value<instrument::event::ctxt_active::woken_up>{static constexpr const char * name = "woken_up";}
;template <> struct value<instrument::event::ctxt_active::working_on_dispatchers_end>{static constexpr const char * name = "working_on_dispatchers_end";}
;template <> struct value<instrument::event::ctxt_active::working_on_dispatchers_start>{static constexpr const char * name = "working_on_dispatchers_start";}
;template <> struct value<instrument::event::ctxt_active::working_on_enqueued_end>{static constexpr const char * name = "working_on_enqueued_end";}
;template <> struct value<instrument::event::ctxt_active::working_on_enqueued_start>{static constexpr const char * name = "working_on_enqueued_start";}
;}export
namespace instrument::event{enum class ctxt_entry : enum_uint_t {streaming_task = 2};using enabled_ctxt_entrys = util::sequence::enum_t<ctxt_entry,ctxt_entry::streaming_task>;}
export
namespace instrument::event{template <> struct type<instrument::event::ctxt_entry>{static constexpr const char * name = "ctxt_entry";
static constexpr const enum_type_id_t type_id = 6;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::ctxt_entry::streaming_task>{static constexpr const char * name = "streaming_task";}
;}export
namespace instrument::event{enum class dep_acquire : enum_uint_t {getting_non_wrapped = 2,getting_wrapped = 3,getting_wrapped_view = 4};using enabled_dep_acquires = util::sequence::enum_t<dep_acquire,dep_acquire::getting_non_wrapped,dep_acquire::getting_wrapped,dep_acquire::getting_wrapped_view>;}
export
namespace instrument::event{template <> struct type<instrument::event::dep_acquire>{static constexpr const char * name = "dep_acquire";
static constexpr const enum_type_id_t type_id = 7;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::dep_acquire::getting_non_wrapped>{static constexpr const char * name = "getting_non_wrapped";}
;template <> struct value<instrument::event::dep_acquire::getting_wrapped>{static constexpr const char * name = "getting_wrapped";}
;template <> struct value<instrument::event::dep_acquire::getting_wrapped_view>{static constexpr const char * name = "getting_wrapped_view";}
;}export
namespace instrument::event{enum class dep_dispatch : enum_uint_t {create_end = 2,create_start = 3};using enabled_dep_dispatchs = util::sequence::enum_t<dep_dispatch,dep_dispatch::create_end,dep_dispatch::create_start>;}
export
namespace instrument::event{template <> struct type<instrument::event::dep_dispatch>{static constexpr const char * name = "dep_dispatch";
static constexpr const enum_type_id_t type_id = 8;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::dep_dispatch::create_end>{static constexpr const char * name = "create_end";}
;template <> struct value<instrument::event::dep_dispatch::create_start>{static constexpr const char * name = "create_start";}
;}export
namespace instrument::event{enum class dep_execute : enum_uint_t {kernel_end = 2,kernel_start = 3};using enabled_dep_executes = util::sequence::enum_t<dep_execute,dep_execute::kernel_end,dep_execute::kernel_start>;}
export
namespace instrument::event{template <> struct type<instrument::event::dep_execute>{static constexpr const char * name = "dep_execute";
static constexpr const enum_type_id_t type_id = 9;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::dep_execute::kernel_end>{static constexpr const char * name = "kernel_end";}
;template <> struct value<instrument::event::dep_execute::kernel_start>{static constexpr const char * name = "kernel_start";}
;}export
namespace instrument::event{enum class dep_release : enum_uint_t {publish_end = 2,publish_error_end = 3,publish_error_start = 4,publish_start = 5};using enabled_dep_releases = util::sequence::enum_t<dep_release,dep_release::publish_end,dep_release::publish_error_end,dep_release::publish_error_start,dep_release::publish_start>;}
export
namespace instrument::event{template <> struct type<instrument::event::dep_release>{static constexpr const char * name = "dep_release";
static constexpr const enum_type_id_t type_id = 10;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::dep_release::publish_end>{static constexpr const char * name = "publish_end";}
;template <> struct value<instrument::event::dep_release::publish_error_end>{static constexpr const char * name = "publish_error_end";}
;template <> struct value<instrument::event::dep_release::publish_error_start>{static constexpr const char * name = "publish_error_start";}
;template <> struct value<instrument::event::dep_release::publish_start>{static constexpr const char * name = "publish_start";}
;}export
namespace instrument::event{enum class dep_solver : enum_uint_t {all_ready = 2,error_while_executing = 3,max_depth_not_reached = 4,max_depth_reached = 5,not_ready = 6,process_as_dispatcher = 7,process_as_kernel = 8,process_as_kernel_or_dispatcher = 9,process_descriptor = 10,received_poison_pill = 11};using enabled_dep_solvers = util::sequence::enum_t<dep_solver,dep_solver::all_ready,dep_solver::error_while_executing,dep_solver::max_depth_not_reached,dep_solver::max_depth_reached,dep_solver::not_ready,dep_solver::process_as_dispatcher,dep_solver::process_as_kernel,dep_solver::process_as_kernel_or_dispatcher,dep_solver::process_descriptor,dep_solver::received_poison_pill>;}
export
namespace instrument::event{template <> struct type<instrument::event::dep_solver>{static constexpr const char * name = "dep_solver";
static constexpr const enum_type_id_t type_id = 11;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::dep_solver::all_ready>{static constexpr const char * name = "all_ready";}
;template <> struct value<instrument::event::dep_solver::error_while_executing>{static constexpr const char * name = "error_while_executing";}
;template <> struct value<instrument::event::dep_solver::max_depth_not_reached>{static constexpr const char * name = "max_depth_not_reached";}
;template <> struct value<instrument::event::dep_solver::max_depth_reached>{static constexpr const char * name = "max_depth_reached";}
;template <> struct value<instrument::event::dep_solver::not_ready>{static constexpr const char * name = "not_ready";}
;template <> struct value<instrument::event::dep_solver::process_as_dispatcher>{static constexpr const char * name = "process_as_dispatcher";}
;template <> struct value<instrument::event::dep_solver::process_as_kernel>{static constexpr const char * name = "process_as_kernel";}
;template <> struct value<instrument::event::dep_solver::process_as_kernel_or_dispatcher>{static constexpr const char * name = "process_as_kernel_or_dispatcher";}
;template <> struct value<instrument::event::dep_solver::process_descriptor>{static constexpr const char * name = "process_descriptor";}
;template <> struct value<instrument::event::dep_solver::received_poison_pill>{static constexpr const char * name = "received_poison_pill";}
;}export
namespace instrument::event{enum class dep_update : enum_uint_t {end = 2,no_changes = 3,start = 4};using enabled_dep_updates = util::sequence::enum_t<dep_update,dep_update::end,dep_update::no_changes,dep_update::start>;}
export
namespace instrument::event{template <> struct type<instrument::event::dep_update>{static constexpr const char * name = "dep_update";
static constexpr const enum_type_id_t type_id = 12;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::dep_update::end>{static constexpr const char * name = "end";}
;template <> struct value<instrument::event::dep_update::no_changes>{static constexpr const char * name = "no_changes";}
;template <> struct value<instrument::event::dep_update::start>{static constexpr const char * name = "start";}
;}export
namespace instrument::event{enum class dispatcher_queue : enum_uint_t {acquired = 2,empty = 3,poping = 4,push = 5,share = 6,try_get = 7,try_share = 8};using enabled_dispatcher_queues = util::sequence::enum_t<dispatcher_queue,dispatcher_queue::acquired,dispatcher_queue::empty,dispatcher_queue::poping,dispatcher_queue::push,dispatcher_queue::share,dispatcher_queue::try_get,dispatcher_queue::try_share>;}
export
namespace instrument::event{template <> struct type<instrument::event::dispatcher_queue>{static constexpr const char * name = "dispatcher_queue";
static constexpr const enum_type_id_t type_id = 13;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::dispatcher_queue::acquired>{static constexpr const char * name = "acquired";}
;template <> struct value<instrument::event::dispatcher_queue::empty>{static constexpr const char * name = "empty";}
;template <> struct value<instrument::event::dispatcher_queue::poping>{static constexpr const char * name = "poping";}
;template <> struct value<instrument::event::dispatcher_queue::push>{static constexpr const char * name = "push";}
;template <> struct value<instrument::event::dispatcher_queue::share>{static constexpr const char * name = "share";}
;template <> struct value<instrument::event::dispatcher_queue::try_get>{static constexpr const char * name = "try_get";}
;template <> struct value<instrument::event::dispatcher_queue::try_share>{static constexpr const char * name = "try_share";}
;}export
namespace instrument::event{enum class error : enum_uint_t {assert_fail = 2};using enabled_errors = util::sequence::enum_t<error,error::assert_fail>;}
export
namespace instrument::event{template <> struct type<instrument::event::error>{static constexpr const char * name = "error";
static constexpr const enum_type_id_t type_id = 14;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::error::assert_fail>{static constexpr const char * name = "assert_fail";}
;}export
namespace instrument::event{enum class global_descriptor_queue : enum_uint_t {acquired = 2,empty = 3,poping = 4,push = 5,try_steal = 6};using enabled_global_descriptor_queues = util::sequence::enum_t<global_descriptor_queue,global_descriptor_queue::acquired,global_descriptor_queue::empty,global_descriptor_queue::poping,global_descriptor_queue::push,global_descriptor_queue::try_steal>;}
export
namespace instrument::event{template <> struct type<instrument::event::global_descriptor_queue>{static constexpr const char * name = "global_descriptor_queue";
static constexpr const enum_type_id_t type_id = 15;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::global_descriptor_queue::acquired>{static constexpr const char * name = "acquired";}
;template <> struct value<instrument::event::global_descriptor_queue::empty>{static constexpr const char * name = "empty";}
;template <> struct value<instrument::event::global_descriptor_queue::poping>{static constexpr const char * name = "poping";}
;template <> struct value<instrument::event::global_descriptor_queue::push>{static constexpr const char * name = "push";}
;template <> struct value<instrument::event::global_descriptor_queue::try_steal>{static constexpr const char * name = "try_steal";}
;}export
namespace instrument::event{enum class local_descriptor_queue : enum_uint_t {acquired = 2,empty = 3,poping = 4,try_front_and_pop = 5};using enabled_local_descriptor_queues = util::sequence::enum_t<local_descriptor_queue,local_descriptor_queue::acquired,local_descriptor_queue::empty,local_descriptor_queue::poping,local_descriptor_queue::try_front_and_pop>;}
export
namespace instrument::event{template <> struct type<instrument::event::local_descriptor_queue>{static constexpr const char * name = "local_descriptor_queue";
static constexpr const enum_type_id_t type_id = 16;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::local_descriptor_queue::acquired>{static constexpr const char * name = "acquired";}
;template <> struct value<instrument::event::local_descriptor_queue::empty>{static constexpr const char * name = "empty";}
;template <> struct value<instrument::event::local_descriptor_queue::poping>{static constexpr const char * name = "poping";}
;template <> struct value<instrument::event::local_descriptor_queue::try_front_and_pop>{static constexpr const char * name = "try_front_and_pop";}
;}export
namespace instrument::event{enum class policy_queue_compare : enum_uint_t {exited_1st = 2,exited_2nd = 3,exited_3rd = 4,exited_4th = 5};using enabled_policy_queue_compares = util::sequence::enum_t<policy_queue_compare,policy_queue_compare::exited_1st,policy_queue_compare::exited_2nd,policy_queue_compare::exited_3rd,policy_queue_compare::exited_4th>;}
export
namespace instrument::event{template <> struct type<instrument::event::policy_queue_compare>{static constexpr const char * name = "policy_queue_compare";
static constexpr const enum_type_id_t type_id = 17;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::policy_queue_compare::exited_1st>{static constexpr const char * name = "exited_1st";}
;template <> struct value<instrument::event::policy_queue_compare::exited_2nd>{static constexpr const char * name = "exited_2nd";}
;template <> struct value<instrument::event::policy_queue_compare::exited_3rd>{static constexpr const char * name = "exited_3rd";}
;template <> struct value<instrument::event::policy_queue_compare::exited_4th>{static constexpr const char * name = "exited_4th";}
;}export
namespace instrument::event{enum class queue_container : enum_uint_t {comparing_lhs = 2,comparing_rhs = 3,has_enqueued_work = 4,requesting_valid = 5,returning = 6,returning_app = 7};using enabled_queue_containers = util::sequence::enum_t<queue_container,queue_container::comparing_lhs,queue_container::comparing_rhs,queue_container::has_enqueued_work,queue_container::requesting_valid,queue_container::returning,queue_container::returning_app>;}
export
namespace instrument::event{template <> struct type<instrument::event::queue_container>{static constexpr const char * name = "queue_container";
static constexpr const enum_type_id_t type_id = 18;
static constexpr bool instrumentable = true;
};template <> struct value<instrument::event::queue_container::comparing_lhs>{static constexpr const char * name = "comparing_lhs";}
;template <> struct value<instrument::event::queue_container::comparing_rhs>{static constexpr const char * name = "comparing_rhs";}
;template <> struct value<instrument::event::queue_container::has_enqueued_work>{static constexpr const char * name = "has_enqueued_work";}
;template <> struct value<instrument::event::queue_container::requesting_valid>{static constexpr const char * name = "requesting_valid";}
;template <> struct value<instrument::event::queue_container::returning>{static constexpr const char * name = "returning";}
;template <> struct value<instrument::event::queue_container::returning_app>{static constexpr const char * name = "returning_app";}
;}
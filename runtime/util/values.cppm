export module SteelRT.Util.Values;

import SteelRT.Util.Types;

export import <limits>;
export import <csignal>;


namespace global {

  export
  inline constexpr const thread_id_t ThreadIdTypeMaxBits = 8; // Thread ids in [0, 63]. This is used to pack a thread id as a bitfield of a structure

  export
  inline constexpr const thread_id_t NullThreadId = 31; // 2^ (minimum value of ThreadIdTypeMaxBits) (fsif ThreadIdTypeMaxBits)

  export
  inline constexpr const thread_id_t MainThreadId = std::numeric_limits<thread_id_t>::max(); // 0xFF; // 1111111

  // export
  // const counter_t MaxAwaiters = std::numeric_limits<std::uint16_t>::max(); // less or equal to :  2^ (min value of nAwaiters bits)  (currently 30)

  export
  const counter_t InitialTaskCounter = 10000; // 7452 = TASK

  export
  const enum_uint_t PoisonPillAppIndex = 0;

  export
  const enum_uint_t PoisonPillImplIndex = 0;

  export
  const enum_uint_t PoisonPillCallIndex = 0;

  export
  inline constexpr const enum_uint_t EntryAppIndex = 1;

  export
  inline constexpr const enum_uint_t EntryAppImpl = 1;

  export
  inline constexpr const enum_uint_t EntryAppCall = 1;

  export
  inline constexpr const std::uintptr_t ErrorPtr = 33333;

  export
  inline constexpr const solved_mask_t AllSolvedMask = std::numeric_limits<solved_mask_t>::max(); // All ones

  export
  const youth_t MaxYouth = std::numeric_limits<youth_t>::max();

  export const n_bits_t MaxAppIds = 32;
  export const n_bits_t MaxAppImpls = 32;
  export const n_bits_t MaxAppCalls = 32;
  export const n_bits_t DepthLimit = 8;

  export const greed_t MaxGreed = std::numeric_limits<greed_t>::max();

  // export const n_bits_t MaxAppArgs = 8; Deprecated

  export const n_bits_t MaxActiveThreads = 8;

  export
  inline constexpr const int ErrorSignal = SIGABRT;

  export
  inline constexpr const uint_t MaxBatchSize = 1024;

  export
  inline constexpr const uint_t NoIndex = std::numeric_limits<uint_t>::max(); //

  class init {
  public:
    static volatile std::sig_atomic_t ErrorSignalStatus;
  };

  export
  void signal_handler(int signal) noexcept;

  export
  void signal_handler_throwing(int signal);

  export
  int get_signal() noexcept;

  export
  bool greed_unsatisfied(greed_t counter, greed_t limit) noexcept;

} // namespace global

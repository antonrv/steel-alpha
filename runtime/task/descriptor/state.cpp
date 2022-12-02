module SteelRT.Task.DescriptorState;

import SteelRT.Util.Basic;

import <atomic>;

namespace task::attr {

std::atomic<counter_t> init::GlobalDescriptorCounter(global::InitialTaskCounter);

} // namespace task::attr

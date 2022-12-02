
module SteelRT.Util.Values;

import SteelRT.Util.Types;

import <csignal>;

namespace global {

volatile std::sig_atomic_t init::ErrorSignalStatus(0);


void signal_handler(int signal) noexcept {
  init::ErrorSignalStatus = signal;
}

void signal_handler_throwing(int signal) {
  init::ErrorSignalStatus = signal;
  throw std::logic_error("Received signal : " + std::to_string(signal)); 
}

int get_signal() noexcept {
  return init::ErrorSignalStatus;
}

bool greed_unsatisfied(greed_t counter, greed_t limit) noexcept {
  return limit == global::MaxGreed or (limit < global::MaxGreed and counter < limit);
}

} // namespace global

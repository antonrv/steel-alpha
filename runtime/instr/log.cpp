module SteelRT.Instrument;

import SteelRT.Util.Types;
import SteelRT.Util.Values;

import SteelRT.Instrument.EnabledEvents;

import <thread>;
import <map>;
import <string>;
import <fstream>;

namespace instr {

std::mutex log::s_logMutex;
std::streambuf* log::s_oldLogBuf;
std::ofstream log::s_newOfs;

char log::s_processId; // Either R or P (Runner or Pilot)

std::map<std::thread::id, std::pair<thread_id_t, std::string>> log::s_subscribedThreads;

raii_instrer initialize(const char processIdentifier, const std::string& instrFn) {
  return log::initialize( processIdentifier, instrFn, event::enabled_tuple() );
}

void subscribe_thread(thread_id_t thId, const std::string sv) {
  log::subscribe_thread(thId, sv);
}

} // namespace instr

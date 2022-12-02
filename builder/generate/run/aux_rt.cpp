
#include "generate/run/enum_map.hpp"
#include "common/aux.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>

namespace bld {


static
value_t format_line(const std::string& line) {
  if (line.find("=") != std::string::npos) {
      auto leftStr = line.substr(0, line.find("="));
      clean(leftStr);
      auto substrVal = line.substr(line.find("=") + 1);
      clean(substrVal);
      return std::make_pair(leftStr, substrVal);
  }
  return std::make_pair(line, "");
}

event_map_t build_map_from_file(std::string filename) {

  const std::string eventKw = "----";
  event_map_t retMap;

  std::ifstream ifs(filename.c_str());

  if (not ifs.is_open()) {
    throw std::runtime_error("Could not open file " + filename);
  }

  std::string line;

  std::string evName;
  while (std::getline(ifs, line)) {

    auto eventPos = line.find(eventKw);

    if (eventPos != std::string::npos) {
      evName = line.substr(eventPos + eventKw.size());
      clean(evName);
      if (retMap.find(evName) != retMap.end()) {
        throw std::runtime_error("Event name duplicated");
      }
      if (evName.empty()) {
        throw std::runtime_error("event with no name");
      }
      retMap[evName] = values_t();

    } else if (not line.empty()) {
      if (evName.empty()) {
        throw std::runtime_error("Event name not set");
      }
      clean(line);
      if (not line.empty()) {
        auto [str, val] = format_line( line );
        retMap[evName].insert( std::make_pair(str,val) );
      } else {
        // empty line, skip
      }
    } else {
      // empty line, skip
    }
  }

  return retMap;
}

} // namespace bld

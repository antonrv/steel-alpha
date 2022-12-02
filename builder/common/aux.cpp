


#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
// #include <iostream> // XXX TMP

namespace bld {


void clean(std::string& line, const char * specChars) {
  const auto lineSize = std::string(specChars).size();
  for (auto id = 0u; id < lineSize; ++id) {
    // line.erase(std::remove(line.begin(), line.end(), &(specChars[id])), line.end());
    line.erase(std::remove(line.begin(), line.end(), specChars[id]), line.end());
  }
}

std::vector<std::string> split_string(const std::string& input, const char div) {

  std::vector<std::string> ret;
  std::istringstream iss(input);
  std::string s;
  // std::cout << input << '\n';
  while(std::getline(iss, s, div)) {
    if (not s.empty()) {
      // std::cout << s << '\n';
      ret.push_back(s);
    }
  }
  return ret;
}

void append_char(std::string& dir, char c) {
  if (dir.back() != c) {
    dir.push_back(c);
  }
}


} // namespace bld

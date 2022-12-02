module SteelRT.Util.Assert;

// import SteelRT.Instrument;
import SteelRT.Util.Values;

import <csignal>;
import <string>;
import <iostream>;

namespace safe {

void assert_fail(const char * assertion, const char * file, unsigned line, const char * func) {
  std::string strSep = "\n\t";
  std::string strErr = strSep + "Assertion : " + assertion + strSep + "File : " + file + strSep + "Line : " + std::to_string(line) + strSep + "Function : " + func;

  std::cerr << strErr << std::endl;
  // instr::trace<instr::event::error::assert_fail>(strErr);

  std::raise(global::ErrorSignal);

  throw std::logic_error(strErr);
}

} // namespace safe

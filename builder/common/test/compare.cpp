

#include "common/step_enum.hpp"
#include "common/test/enum.hpp"

#include "files/paths/aux.hpp"

#include <fstream>
#include <iterator>
#include <string>
#include <filesystem>
#include <numeric>

#include <iostream> //DBG XXX



namespace bld::test {


std::string compare_files( const state::filename yieldFn, const state::filename refFn, const suite testSuite, const step stepVal ) {


  auto yieldFnStr = yieldFn.get_full_name();
  auto refFnStr = refFn.get_full_name();
  state::remove_path_in_string<key_path::pwd>( yieldFnStr );
  state::remove_path_in_string<key_path::pwd>( refFnStr );

  auto testDescStr = std::string(util::enum_convert<suite>::to_string_rt(testSuite)) + " - " + yieldFn.get_tail();

  const std::string failStr = std::string(util::enum_convert<step>::to_string_rt(stepVal)) + " test FAIL from : " + testDescStr + " : ";
  const std::string okStr = std::string(util::enum_convert<step>::to_string_rt(stepVal)) + " test OK : " + testDescStr;
  const std::string headStr = "diff " + yieldFnStr + " " + refFnStr + " : ";

  std::ifstream ifsA(yieldFnStr, std::ifstream::binary | std::ifstream::ate);
  std::ifstream ifsB(refFnStr, std::ifstream::binary | std::ifstream::ate);

  if (ifsA.fail()) {
    return failStr + headStr + "Could not open " + yieldFnStr;
  }
  if (ifsB.fail()) {
    return failStr + headStr + "Could not open " + refFnStr;
    // return "cp " + yieldFnStr + " " + refFnStr;// Batch validation for interface changes
  }

  if (ifsA.tellg() != ifsB.tellg()) {
    return failStr + headStr + "Different files";
  }

  //seek back to beginning and use std::equal to compare contents
  ifsA.seekg(0, std::ifstream::beg);
  ifsB.seekg(0, std::ifstream::beg);
  auto strEqual = std::equal(std::istreambuf_iterator<char>(ifsA.rdbuf()),
                    std::istreambuf_iterator<char>(),
                    std::istreambuf_iterator<char>(ifsB.rdbuf()));

  if (not strEqual) {
    return failStr + headStr + "Different files";
  }

  return okStr;
}

} // namespace bld::test

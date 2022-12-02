


// #include <fstream>
// #include <iterator>
// #include <string>
// #include <filesystem>
// #include <numeric>

#include "common/step_enum.hpp"
#include "common/test/enum.hpp"

#include <string>

namespace bld::state {
  class filename;
} // namespace bld::state


namespace bld::test {

std::string compare_files( const state::filename yieldFn, const state::filename refFn, const suite testSuite, const step stepVal );


// struct mapped {
//   std::string translationFn;
//   std::string referenceFn;
// };
// 
// 
// using key_t = std::string;
// using map_t = std::map<key_t, mapped>;
// using key_value_t = typename map_t::value_type;
// 
// template <step Step, ext RefExt, file_kind SeedFK, code CodK>
// void set_files(map_t& testFiles) {
// 
//   for (auto sourcePtr : state::files<SeedFK>::template get_raw<CodK>()) {
// 
//     std::string testFn = sourcePtr->has_yield() ? sourcePtr->get_yield()->get_identifier() : "null_yield";
// 
//     auto fn = sourcePtr->get_identifier();
//     std::filesystem::path asPath(fn);
//     auto onlyExt = asPath.extension().string();
//     auto onlyStem = asPath.stem().string();
//     auto onlyParentPath = asPath.parent_path().string();
//     std::string referenceFn = onlyParentPath + "/TEST_REF/" + util::enum_convert<step>::to_string<Step>() + "/" + onlyStem + etraits<RefExt>::value + onlyExt;
//     testFiles[ fn ] = { testFn, referenceFn };
//   }
// }



// template <step Step>
// std::string accumulate_compare_diff(const std::string& cumStr, const key_value_t& kvRef) {
// 
//   auto aFn = std::get<mapped>(kvRef).translationFn;
//   auto bFn = std::get<mapped>(kvRef).referenceFn;
//   state::remove_path_in_string<key_path::pwd>( aFn );
//   state::remove_path_in_string<key_path::pwd>( bFn );
// 
//   auto reducedFn = std::get<const key_t>(kvRef);
//   state::remove_path_in_string<key_path::pwd>( reducedFn );
// 
//   const std::string failStr = std::string(util::enum_convert<step>::to_string<Step>()) + " test FAIL from : " + reducedFn + " : ";
//   const std::string okStr = std::string(util::enum_convert<step>::to_string<Step>()) + " test OK : " + reducedFn;
//   const std::string headStr = "diff " + aFn + " " + bFn + " : ";
// 
//   std::ifstream ifsA(aFn, std::ifstream::binary | std::ifstream::ate);
//   std::ifstream ifsB(bFn, std::ifstream::binary | std::ifstream::ate);
// 
//   if (ifsA.fail()) {
//     return cumStr + failStr + headStr + "Could not open " + aFn + "\n";
//   }
//   if (ifsB.fail()) {
//     return cumStr + failStr + headStr + "Could not open " + bFn + "\n";
//     // return "cp " + aFn + " " + bFn + "\n";// Batch validation for interface changes
//   }
// 
//   if (ifsA.tellg() != ifsB.tellg()) {
//     return cumStr + failStr + headStr + "Different files.\n";
//   }
// 
//   //seek back to beginning and use std::equal to compare contents
//   ifsA.seekg(0, std::ifstream::beg);
//   ifsB.seekg(0, std::ifstream::beg);
//   auto strEqual = std::equal(std::istreambuf_iterator<char>(ifsA.rdbuf()),
//                     std::istreambuf_iterator<char>(),
//                     std::istreambuf_iterator<char>(ifsB.rdbuf()));
// 
//   if (not strEqual) {
//     return cumStr + failStr + headStr + "Different files.\n";
//   }
// 
//   return cumStr + okStr + "\n";
// }

} // namespace bld::test


#include "source/token/test/interface.hpp"

#include "source/token/make/piece.hpp"

#include "source/token/region/affine/access.hpp"

#include "source/token/simplify/interface.hpp"

#include "common/util.hpp"


#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace bld::src::pc {


static
std::string vec_to_string(const vec_string_t& vec) {
  std::string retStr;

  for (const auto& str : vec) { retStr += str + ","; }
  if (not retStr.empty()) {retStr.pop_back();}

  return retStr;
}


static
void test_affine(const std::string& inputStr, const unsigned expectDim, const vec_string_t expectLVs, const vec_string_t expectFactors, std::string expectOffset) {

  auto pc = make_piece( inputStr );

  affine_access affPc( pc.get(),
      [] (cpiece_t pivPc) {
        return pivPc->get_kind() == kind::var and pivPc->get_pc_string().find("LV") != std::string::npos;
      });

  // std::cout << "Test affine built : " << affPc.get_pc_string() << '\n';

  auto lvVec = affPc.get_loop_vars().get_vec();
  auto facVec = affPc.get_loop_vars_factors().get_vec();
  auto offsPc = simplify_piece( affPc.get_offset() );

  auto gotLVs = transform_vec(lvVec, [] (ctoken_t<kind::var> lv) { return lv->get_pc_string(); });

  auto gotFactors = transform_vec(facVec, [] (cpiece_t lvFac) { return simplify_piece( lvFac )->get_pc_string(); });

  // Validate dimensions
  if (expectDim != affPc.get_dimensions()) {
    throw std::runtime_error("test_affine failed -unexpected dimensions for \"" + inputStr + "\". Got : " + std::to_string(affPc.get_dimensions()) + ". Expected : " + std::to_string(expectDim));
  }

  // Validate LVs
  if (expectLVs != gotLVs) {
    throw std::runtime_error("test_affine failed -unexpected LVs for \"" + inputStr + "\". Got : " + vec_to_string(gotLVs) + ". Expected : " + vec_to_string(expectLVs));
  }

  // Validate LV factors
  if (expectFactors != gotFactors) {
    throw std::runtime_error("test_affine failed -unexpected Factors for \"" + inputStr + "\". Got : " + vec_to_string(gotFactors) + ". Expected : " + vec_to_string(expectFactors));
  }

  // Validate Offset
  if (expectOffset != offsPc->get_pc_string()) {
    throw std::runtime_error("test_affine failed -unexpected offset for \"" + inputStr + "\". Got : " + offsPc->get_pc_string() + ". Expected : " + expectOffset);
  }

}



template <>
void run_tests<token_test::affine>() {


  test_affine(
    "iiLV", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"1"},  // Correct order of factors
    "0" // offset
  );

  test_affine(
    "iiLV + iiLV", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"2"},  // Correct order of factors
    "0" // offset
  );

  test_affine(
    "2*iiLV*a + iiLV", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"(1+(2*a))"},  // Correct order of factors
    "0" // offset
  );

  test_affine(
    "offVar + iiLV", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"1"},  // Correct order of factors
    "offVar" // offset
  );

  test_affine(
    "a*(offVar + iiLV)", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"a"},  // Correct order of factors
    "(a*offVar)" // offset
  );

  test_affine(
    "a/b*(offVar + iiLV)", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"(a/b)"},  // Correct order of factors
    "((a*offVar)/b)" // offset
  );

  test_affine(
    "(a + b)*(offVar + iiLV)", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"(a+b)"},  // Correct order of factors
    "((a*offVar)+(b*offVar))" // offset
  );

  test_affine(
    "rLV*(nRows/nRowBlocks)*nCols + cLV*(nCols/nColBlocks)",
    2, 
    {"rLV","cLV"},  // Correct order of LVs
    {"((nCols*nRows)/nRowBlocks)", "(nCols/nColBlocks)"},
    "0" // offset
  );

  test_affine(
    "stride_a*jjLV + iiLV", // Input
    2, // Expect dims
    {"jjLV","iiLV"},  // Correct order of LVs
    {"stride_a","1"},  // Correct order of factors
    "0" // offset
  );

  test_affine(
    "iiLV", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"1"},  // Correct order of factors
    "0" // offset
  );

  test_affine(
    "27 + iiLV", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"1"},  // Correct order of factors
    "27" // offset
  );

  test_affine(
    "a*(27 + iiLV)", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"a"},  // Correct order of factors
    "(27*a)" // offset
  );

  test_affine(
    "a/b*(27 + iiLV)", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"(a/b)"},  // Correct order of factors
    "((27*a)/b)" // offset
  );

  test_affine(
    "(a + b)*(27 + iiLV)", // Input
    1, // Expect dims
    {"iiLV"},  // Correct order of LVs
    {"(a+b)"},  // Correct order of factors
    "((27*a)+(27*b))" // offset
  );

  test_affine(
    "stride_a*jjLV + iiLV", // Input
    2, // Expect dims
    {"jjLV","iiLV"},  // Correct order of LVs
    {"stride_a","1"},  // Correct order of factors
    "0" // offset
  );

  test_affine(
    "j1_LV*stride*j1_Bs + i1_LV*i1_Bs",
    2, // Expect dims
    {"j1_LV","i1_LV"},  // Correct order of LVs
    {"(j1_Bs*stride)","i1_Bs"},  // Correct order of factors
    "0" // offset
  );

  test_affine(
    "stride_a*jjLV + iiLV + offVar", // Input
    2, // Expect dims
    {"jjLV","iiLV"},  // Correct order of LVs
    {"stride_a","1"},  // Correct order of factors
    "offVar" // offset
  );

  test_affine(
    "jLV*nBlockCols*chunkRows*chunkCols + iLV*chunkCols", // Input
    2, // Expect dims
    {"jLV","iLV"},  // Correct order of LVs
    {"(chunkCols*chunkRows*nBlockCols)","chunkCols"},  // Correct order of factors
    "0" // offset
  );

  test_affine(
    "(((cLV*nCols)/nColBlocks) + (chunkRowsCaller*nCols*rLV))", // Input
    2, // Expect dims
    {"rLV","cLV"},  // Correct order of LVs
    {"(chunkRowsCaller*nCols)","(nCols/nColBlocks)"}, // Correct order of factors
    "0" // offset
  );

  test_affine(
    "stride_b*stride_a*kkLV + stride_a*jjLV + iiLV", // Input
    3, // Expect dims
    {"kkLV","jjLV","iiLV"},  // Correct order of LVs
    {"(stride_a*stride_b)","stride_a","1"},  // Correct order of factors
    "0" // offset
  );

  // More 3dim tests TODO
}

} // namespace bld::src::pc

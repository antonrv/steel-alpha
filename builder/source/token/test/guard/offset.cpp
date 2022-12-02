
#include "source/token/test/interface.hpp"

#include <vector>
#include <string>

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// More complex local coords and local offsets


namespace bld::src::pc {

void test_guard(
  const std::vector<std::string> inputAffineStrs,
  const std::vector<std::string> expectGlobalEmbeds,
  const unsigned expectDescriptorsCount,
  const std::vector<std::vector<std::string>> expectAffineLocalEmbeds,
  const std::vector<std::vector<std::string>> expectAffineLocalCoords,
  const std::vector<std::string> expectAffineLocalOffsets);


template <>
void run_tests<token_test::guard_offset>() {


  // One 1-dim affine expression with offset
  test_guard(
    { // Affine exprs
      "iLV + off" // 1D
    },
    // Expected global embeddings
    {"1"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1"}
    },
    { // Expected local coords
      {"(iLV+off)"}
      // {"iLV"} // Because ge = ge = 1 --> default case: capture coords and offsets from raw access
    },
    // Expected local offsets
    {"0"}
  );

  // One 1-dim affine expression with offset on LV
  test_guard(
    { // Affine exprs
      "iLV*iBs + off*iBs" // 1D
    },
    // Expected global embeddings
    {"iBs"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1"},
    },
    { // Expected local coords
      {"(iLV+off)"}
    },
    // Expected local offsets
    {"0"}
  );

  // One 1-dim affine expression with offset
  test_guard(
    { // Affine exprs
      "iLV*iBs + off1*iBs + off2" // 1D
    },
    // Expected global embeddings
    {"iBs"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1"},
    },
    { // Expected local coords
      {"(iLV+off1)"}
    },
    // Expected local offsets
    {"off2"}
  );

  // Two 1-dim affine expression with offset
  test_guard(
    { // Affine exprs
      "i1_LV + off1", // 1D
      "i2_LV + off2" // 1D
    },
    // Expected global embeddings
    {"1"},
    // Expected access descriptors (2, because they have different ranges) 1 if we dont consider the ranges
    1,
    { // Expected local embeddings
      {"1"},
      {"1"}
    },
    { // Expected local coords
      {"(i1_LV+off1)"},
      {"(i2_LV+off2)"}
    },
    // Expected local offsets
    {
      "0",
      "0"
    }
  );

  // Two 1-dim affine expression with offset on LV
  test_guard(
    { // Affine exprs
      "i1_LV*i1_Bs + off*i1_Bs", // 1D
      "i2_LV*i2_Bs + off*i2_Bs" // 1D
    },
    // Expected global embeddings
    {"1"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1"},
      {"1"}
    },
    { // Expected local coords
      {"(i1_LV+off)"}, // global embeddings in digest are i1_Bs, i2_Bs TODO
      {"(i2_LV+off)"}
    },
    // Expected local offsets
    {"0","0"}
  );

  // Two 1-dim affine expression with offsets
  test_guard(
    { // Affine exprs
      "i1_LV*iBs + off1*iBs + off2", // 1D
      "i2_LV*iBs + off3*iBs + off4" // 1D
    },
    // Expected global embeddings
    {"iBs"},
    // Expected access descriptors  (2, because they have different ranges) 1 if we dont consider the ranges
    1,
    { // Expected local embeddings
      {"1"},
      {"1"},
    },
    { // Expected local coords
      {"(i1_LV+off1)"}, // global embeddings in digest are iBs in both TODO
      {"(i2_LV+off3)"}
    },
    // Expected local offsets
    {
      "off2",
      "off4"
    }
  );

  // // One 2-dim affine expression and one 0-dim access.
  test_guard(
    { // Affine exprs
      "jLV*stride + iLV",
      "27*stride",
    },
    // Expected global embeddings
    {"stride","1"},
    // Expected access descriptors (2, because they have different ranges) 1 if we dont consider the ranges
    1,
    { // Expected local embeddings 
      {"1","1"},
      {"1","1"},
    },
    { // Expected local coords
      {"jLV","iLV"},
      {"27","0"}
    },
    // Expected local offsets
    {
      "0",
      "0"
    }
  );

  // One 2-dim affine expression and one 0-dim access.
  test_guard(
    { // Affine exprs
      "jLV*stride + iLV",
      "27*stride + 4",
    },
    // Expected global embeddings
    {"stride","1"},
    // Expected access descriptors (2, because they have different ranges) 1 if we dont consider the ranges
    1,
    { // Expected local embeddings
      {"1","1"},
      {"1","1"},
    },
    { // Expected local coords
      {"jLV","iLV"},
      {"27","4"}
    },
    // Expected local offsets
    {
      "0",
      "0"
    }
  );

  // One 2-dim affine expression and one 0-dim access.
  test_guard(
    { // Affine exprs
      "jLV*stride + iLV",
      "off",
    },
    // Expected global embeddings
    {"stride","1"},
    // Expected access descriptors (2, because they have different ranges) 1 if we dont consider the ranges
    1,
    { // Expected local embeddings
      {"1","1"},
      {"1","1"},
    },
    { // Expected local coords
      {"jLV","iLV"},
      {"0","off"}
    },
    // Expected local offsets
    {
      "0",
      "0"
    }
  );

  // One 2-dim affine expression and one 0-dim access.
  test_guard(
    { // Affine exprs
      "jLV*iBs*iNb*jBs + iLV*iBs",
      "off",
    },
    // Expected global embeddings
    {"(iBs*iNb*jBs)","iBs"},
    // Expected access descriptors (2, because they have different ranges) 1 if we dont consider the ranges
    1,
    { // Expected local embeddings
      {"1","1"},
      {"1","1"},
    },
    { // Expected local coords
      {"jLV","iLV"},
      {"0","0"}
    },
    // Expected local offsets
    {
      "0",
      "off"}
  );

//////
//////
//////

  test_guard(
    { // Affine exprs
      "kLV*A*B*C + jLV*A*B + iLV*A + z*A*B*C + y*A*B + x*A + off"
    },
    // Expected global embeddings
      {"(A*B*C)","(A*B)", "A"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1","1", "1"}
    },
    { // Expected local coords
      {"(kLV+z)","(jLV+y)","(iLV+x)"}
    },
    // Expected local offsets
    {"off"}
  );

  test_guard(
    { // Affine exprs
      "lLV*A*B*C*D + kLV*A*B*C + jLV*A*B + iLV*A + z*A*B*C*D + y*A*B*C + x*A*B + w*A + off"
    },
    // Expected global embeddings
    {"(A*B*C*D)","(A*B*C)","(A*B)", "A"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1","1","1", "1"}
    },
    { // Expected local coords
      {"(lLV+z)","(kLV+y)","(jLV+x)","(iLV+w)"},
    },
    // Expected local offsets
    {"off"}
  );

}

} // namespace bld::src::pc

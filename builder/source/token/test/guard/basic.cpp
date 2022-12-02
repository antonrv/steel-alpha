
#include "source/token/test/interface.hpp"

#include "source/token/typedef.hpp"

#include <vector>
#include <string>

namespace bld::src::pc {

void test_guard(
  const std::vector<std::string> inputAffineStrs,
  const std::vector<std::string> expectGlobalEmbeds,
  const unsigned expectDescriptorsCount,
  const std::vector<std::vector<std::string>> expectAffineLocalEmbeds,
  const std::vector<std::vector<std::string>> expectAffineLocalCoords,
  const std::vector<std::string> expectAffineLocalOffsets);


template <>
void run_tests<token_test::guard_basic>() {

  test_guard(
    { // Affine exprs
      "27",
    },
    // Expected global embeddings
    {},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {},
    },
    { // Expected local coords
      {},
    },
    // Expected local offsets
    {"27"}
  );

  // One 1-dim Affine expressions mapping to one 1-dim descriptor
  test_guard(
    { // Affine exprs
      "iLV",
    },
    // Expected global embeddings
    {"1"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1"},
    },
    { // Expected local coords
      {"iLV"},
    },
    // Expected local offsets
    {"0"}
  );


  // One 1-dim Affine expressions mapping to one 1-dim descriptor
  test_guard(
    { // Affine exprs
      "iLV*iBs",
    },
    // Expected global embeddings
    {"iBs"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1"},
    },
    { // Expected local coords
      {"iLV"},
    },
    // Expected local offsets
    {"0"}
  );


  // Two 1-dim Affine expressions mapping to one 1-dim descriptor
  test_guard(
    { // Affine exprs
      "i1_LV",
      "i2_LV",
    },
    // Expected global embeddings
    {"1"},
    // Expected access descriptors (two, because they have different ranges)
    1,
    { // Expected local embeddings
      {"1"},
      {"1"},
    },
    { // Expected local coords
      {"i1_LV"},
      {"i2_LV"},
    },
    // Expected local offsets
    {"0","0"}
  );



  // One 2-dim Affine expressions mapping to one 2-dim descriptor
  test_guard(
    { // Affine exprs
      "jLV*stride + iLV",
    },
    // Expected global embeddings
    {"stride","1"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1","1"},
    },
    { // Expected local coords
      {"jLV","iLV"},
    },
    // Expected local offsets
    {"0"}
  );

  // One 2-dim Affine expressions mapping to one 2-dim descriptor. Same but stride factorized
  test_guard(
    { // Affine exprs
      "jLV*str*ide + iLV",
    },
    // Expected global embeddings
    {"(ide*str)","1"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1","1"},
    },
    { // Expected local coords
      {"jLV","iLV"},
    },
    // Expected local offsets
    {"0"}
  );


  // Two 2-dim Affine expressions mapping to one 2-dim descriptor
  test_guard(
    { // Affine exprs
      "i1_LV + j1_LV*stride",
      "i2_LV + j2_LV*stride",
    },
    // Expected global embeddings
    {"stride","1"},
    // Expected access descriptors (two, because they have different ranges)
    1,
    { // Expected local embeddings
      {"1","1"},
      {"1","1"}
    },
    { // Expected local coords
      {"j1_LV","i1_LV"},
      {"j2_LV","i2_LV"}
    },
    // Expected local offsets
    {"0","0"}
  );

  // Three 2-dim Affine expressions mapping to one 2-dim descriptor
  test_guard(
    { // Affine exprs
      "j1_LV*stride + i1_LV",
      "i2_LV + j2_LV*stride",
      "j3_LV*stride + i3_LV",
    },
    // Expected global embeddings
    {"stride","1"},
    // Expected access descriptors (three, because they have different ranges)
    1,
    { // Expected local embeddings
      {"1","1"},
      {"1","1"},
      {"1","1"}
    },
    { // Expected local coords
      {"j1_LV","i1_LV"},
      {"j2_LV","i2_LV"},
      {"j3_LV","i3_LV"}
    },
    // Expected local offsets
    {"0","0","0"}
  );

  // Two 2-dim Affine expressions mapping to two 2-dim descriptors
  test_guard(
    { // Affine exprs
      "j1_LV*i1_Nb*i1_Bs*j1_Bs + i1_LV*i1_Bs",
      "j2_LV*i2_Nb*i2_Bs*j2_Bs + i2_LV*i2_Bs",
    },
    // Expected global embeddings
    {"1","1"},
    // Expected access descriptors
    2,
    { // Expected local embeddings
      {"(i1_Bs*i1_Nb*j1_Bs)","i1_Bs"},
      {"(i2_Bs*i2_Nb*j2_Bs)","i2_Bs"},
    },
    { // Expected local coords
      {"j1_LV","i1_LV"},
      {"j2_LV","i2_LV"}
    },
    // Expected local offsets
    {"0","0"}
  );

  // Two 2-dim Affine expressions mapping to two 2-dim descriptors
  test_guard(
    { // Affine exprs
      "j1_LV*stride*j1_Bs + i1_LV*i1_Bs", // 'stride' will have the expression of i1_Nb*i1_Bs locally
      "j2_LV*stride*j2_Bs + i2_LV*i2_Bs", // 'stride' will have the expression of i2_Nb*i2_Bs locally
    },
    // Expected global embeddings
    {"stride","1"},
    // Expected access descriptors
    2,
    { // Expected local embeddings
      {"j1_Bs","i1_Bs"},
      {"j2_Bs","i2_Bs"},
    },
    { // Expected local coords
      {"(j1_Bs*j1_LV)","(i1_Bs*i1_LV)"},
      {"(j2_Bs*j2_LV)","(i2_Bs*i2_LV)"}
    },
    // Expected local offsets
    {"0","0"}
  );

  // Three 2-dim Affine expressions mapping to two 2-dim descriptors
  test_guard(
    { // Affine exprs
      "j1_LV*i1_Nb*i1_Bs*j1_Bs + i1_LV*i1_Bs", // 'stride' will have the expression of i1_Nb*i1_Bs locally
      "j2_LV*i2_Nb*i2_Bs*j2_Bs + i2_LV*i2_Bs", // 'stride' will have the expression of i2_Nb*i2_Bs locally
      "j3_LV*i2_Nb*i2_Bs*j2_Bs + i3_LV*i2_Bs", // 'stride' will have the expression of i2_Nb*i2_Bs locally. REPEATED
    },
    // Expected global embeddings 
    {"1","1"},
    // Expected access descriptors  (three, because they have different ranges). 2 if we dont consider the ranges
    2,
    { // Expected local embeddings
      {"(i1_Bs*i1_Nb*j1_Bs)","i1_Bs"},
      {"(i2_Bs*i2_Nb*j2_Bs)","i2_Bs"},
      {"(i2_Bs*i2_Nb*j2_Bs)","i2_Bs"}
    },
    { // Expected local coords
      {"j1_LV","i1_LV"},
      {"j2_LV","i2_LV"},
      {"j3_LV","i3_LV"}
    },
    // Expected local offsets
    {"0","0","0"}
  );

  // Three 2-dim Affine expressions mapping to one 2-dim descriptors
  test_guard(
    { // Affine exprs
      "j1_LV*i_Bs*i_Nb*j_Bs + i1_LV*i_Bs", // 'stride' will have the expression of i_Nb*i_Bs locally
      "j2_LV*i_Bs*i_Nb*j_Bs + i2_LV*i_Bs", // 'stride' will have the expression of i_Nb*i_Bs locally
      "j3_LV*i_Bs*i_Nb*j_Bs + i3_LV*i_Bs", // 'stride' will have the expression of i_Nb*i_Bs locally. REPEATED
    },
    // Expected global embeddings
    {"(i_Bs*i_Nb*j_Bs)","i_Bs"},
    // Expected access descriptors  (three, because they have different ranges)
    1,
    { // Expected local embeddings
      {"1","1"},
      {"1","1"},
      {"1","1"}
    },
    { // Expected local coords
      {"j1_LV","i1_LV"},
      {"j2_LV","i2_LV"},
      {"j3_LV","i3_LV"}
    },
    // Expected local offsets
    {"0","0","0"}
  );

  // Three 2-dim Affine expressions mapping to three 2-dim descriptors
  test_guard(
    { // Affine exprs
      "j1_LV*stride*j1_Bs + i1_LV*i1_Bs", // 'stride' will have the expression of i1_Nb*i1_Bs locally
      "j2_LV*stride*j2_Bs + i2_LV*i2_Bs", // 'stride' will have the expression of i2_Nb*i2_Bs locally
      "j3_LV*stride*j3_Bs + i3_LV*i3_Bs", // 'stride' will have the expression of i3_Nb*i3_Bs locally
    },
    // Expected global embeddings
    {"stride","1"},
    // Expected access descriptors
    3,
    { // Expected local embeddings
      {"j1_Bs","i1_Bs"},
      {"j2_Bs","i2_Bs"},
      {"j3_Bs","i3_Bs"}
    },
    { // Expected local coords
      {"(j1_Bs*j1_LV)","(i1_Bs*i1_LV)"},
      {"(j2_Bs*j2_LV)","(i2_Bs*i2_LV)"},
      {"(j3_Bs*j3_LV)","(i3_Bs*i3_LV)"}
    },
    // Expected local offsets
    {"0","0","0"}
  );



  // Two 3-dim Affine expressions mapping to one 3-dim descriptors
  test_guard(
    { // Affine exprs
      "k1_LV*i_Bs*i_Nb*j_Bs*j_Nb*k_Bs + j1_LV*i_Bs*i_Nb*j_Bs + i1_LV*i_Bs", // 'stride_X' will have the expression of i_Bs*i_Nb locally. stride_Y will have the expression of j_Bs*j_Nb
      "k2_LV*i_Bs*i_Nb*j_Bs*j_Nb*k_Bs + j2_LV*i_Bs*i_Nb*j_Bs + i2_LV*i_Bs", // 'stride_X' will have the expression of i_Bs*i_Nb locally. stride_Y will have the expression of j_Bs*j_Nb
    },
    // Expected global embeddings
    {"(i_Bs*i_Nb*j_Bs*j_Nb*k_Bs)","(i_Bs*i_Nb*j_Bs)","i_Bs"},
    // Expected access descriptors (two, because they have different ranges)
    1,
    { // Expected local embeddings
      {"1","1","1"},
      {"1","1","1"}
    },
    { // Expected local coords
      {"k1_LV","j1_LV","i1_LV"},
      {"k2_LV","j2_LV","i2_LV"}
    },
    // Expected local offsets
    {"0","0"}
  );

  // Two 3-dim Affine expressions mapping to two 3-dim descriptors. 
  // Test that should not pass, since the sorting orther would not be stride_XY < stride_X, since lexicog compare is done.
  // Note that this will sort stride_X  before stride_XY which would be wrong. In practice though, stride_XY would be expressed properly after transformations (body2lparam)
  test_guard(
    { // Affine exprs
      "k1_LV*stride_X*stride_Y*k1_Bs + j1_LV*stride_X*j1_Bs + i1_LV*i1_Bs", // 'stride_X' will have the expression of i1_Nb*i1_Bs locally
      "k2_LV*stride_X*stride_Y*k2_Bs + j2_LV*stride_X*j2_Bs + i2_LV*i2_Bs", // 'stride_X' will have the expression of i2_Nb*i2_Bs locally
    },
    // Expected global embeddings
    {"(stride_X*stride_Y)","stride_X","1"},
    // Expected access descriptors
    2,
    { // Expected local embeddings
      {"k1_Bs","j1_Bs","i1_Bs"},
      {"k2_Bs","j2_Bs","i2_Bs"}
    },
    { // Expected local coords
      {"(k1_Bs*k1_LV)","(j1_Bs*j1_LV)","(i1_Bs*i1_LV)"},
      {"(k2_Bs*k2_LV)","(j2_Bs*j2_LV)","(i2_Bs*i2_LV)"}
    },
    // Expected local offsets
    {"0","0"}
  );

  // Two 3-dim Affine expressions mapping to two 3-dim descriptors. Same but strides factorized
  test_guard(
    { // Affine exprs
      "k1_LV*i1_Bs*i1_Nb*j1_Bs*j1_Nb*k1_Bs + j1_LV*i1_Bs*i1_Nb*j1_Bs + i1_LV*i1_Bs", // 'stride_X' will have the expression of i1_Nb*i1_Bs locally
      "k2_LV*i2_Bs*i2_Nb*j2_Bs*j2_Nb*k2_Bs + j2_LV*i2_Bs*i2_Nb*j2_Bs + i2_LV*i2_Bs", // 'stride_X' will have the expression of i2_Nb*i2_Bs locally
    },
    // Expected global embeddings
    {"1","1","1"},
    // Expected access descriptors 
    2,
    { // Expected local embeddings
      {"(i1_Bs*i1_Nb*j1_Bs*j1_Nb*k1_Bs)","(i1_Bs*i1_Nb*j1_Bs)","i1_Bs"},
      {"(i2_Bs*i2_Nb*j2_Bs*j2_Nb*k2_Bs)","(i2_Bs*i2_Nb*j2_Bs)","i2_Bs"}
    },
    { // Expected local coords
      {"k1_LV","j1_LV","i1_LV"},
      {"k2_LV","j2_LV","i2_LV"}
    },
    // Expected local offsets
    {"0","0"}
  );

  // Multiple 3-dim Affine expressions mapping to multiple 3-dim descriptors
  test_guard(
    { // Affine exprs
      "k1_LV*i1_Bs*i1_Nb*j1_Bs*j1_Nb*k1_Bs + i1_Bs*i1_Nb*j1_Bs*j1_LV + i1_LV*i1_Bs", // 'stride_X' will have the expression of i1_Nb*i1_Bs locally
      "k2_LV*i2_Bs*i2_Nb*j2_Bs*j2_Nb*k2_Bs + i2_Bs*i2_Nb*j2_Bs*j2_LV + i2_LV*i2_Bs", // 'stride_X' will have the expression of i2_Nb*i2_Bs locally
      "k3_LV*i3_Bs*i3_Nb*j3_Bs*j3_Nb*k3_Bs + i3_Bs*i3_Nb*j3_Bs*j3_LV + i3_LV*i3_Bs", // 'stride_X' will have the expression of i3_Nb*i3_Bs locally
      "k4_LV*i4_Bs*i4_Nb*j4_Bs*j4_Nb*k4_Bs + i4_Bs*i4_Nb*j4_Bs*j4_LV + i4_LV*i4_Bs", // 'stride_X' will have the expression of i4_Nb*i4_Bs locally
      "k5_LV*i5_Bs*i5_Nb*j5_Bs*j5_Nb*k5_Bs + i5_Bs*i5_Nb*j5_Bs*j5_LV + i5_LV*i5_Bs", // 'stride_X' will have the expression of i5_Nb*i5_Bs locally
    },
    // Expected global embeddings
    {"1","1","1"},
    // Expected access descriptors
    5,
    { // Expected local embeddings
      {"(i1_Bs*i1_Nb*j1_Bs*j1_Nb*k1_Bs)","(i1_Bs*i1_Nb*j1_Bs)","i1_Bs"},
      {"(i2_Bs*i2_Nb*j2_Bs*j2_Nb*k2_Bs)","(i2_Bs*i2_Nb*j2_Bs)","i2_Bs"},
      {"(i3_Bs*i3_Nb*j3_Bs*j3_Nb*k3_Bs)","(i3_Bs*i3_Nb*j3_Bs)","i3_Bs"},
      {"(i4_Bs*i4_Nb*j4_Bs*j4_Nb*k4_Bs)","(i4_Bs*i4_Nb*j4_Bs)","i4_Bs"},
      {"(i5_Bs*i5_Nb*j5_Bs*j5_Nb*k5_Bs)","(i5_Bs*i5_Nb*j5_Bs)","i5_Bs"}
    },
    { // Expected local coords
      {"k1_LV","j1_LV","i1_LV"},
      {"k2_LV","j2_LV","i2_LV"},
      {"k3_LV","j3_LV","i3_LV"},
      {"k4_LV","j4_LV","i4_LV"},
      {"k5_LV","j5_LV","i5_LV"}
    },
    { // Expected local offsets
      {"0"},
      {"0"},
      {"0"},
      {"0"},
      {"0"}
    }
  );

  // Multiple 3-dim Affine expressions mapping to a single 3-dim descriptors
  test_guard(
    { // Affine exprs
      "k1_LV*i_Bs*i_Nb*j_Bs*j_Nb*k_Bs + i_Bs*i_Nb*j1_LV*j_Bs + i1_LV*i_Bs", // 'stride_X' will have the expression of i_Nb*i_Bs locally
      "k2_LV*i_Bs*i_Nb*j_Bs*j_Nb*k_Bs + i_Bs*i_Nb*j2_LV*j_Bs + i2_LV*i_Bs", // 'stride_X' will have the expression of i_Nb*i_Bs locally
      "k3_LV*i_Bs*i_Nb*j_Bs*j_Nb*k_Bs + i_Bs*i_Nb*j3_LV*j_Bs + i3_LV*i_Bs", // 'stride_X' will have the expression of i_Nb*i_Bs locally
      "k4_LV*i_Bs*i_Nb*j_Bs*j_Nb*k_Bs + i_Bs*i_Nb*j4_LV*j_Bs + i4_LV*i_Bs", // 'stride_X' will have the expression of i_Nb*i_Bs locally
      "k5_LV*i_Bs*i_Nb*j_Bs*j_Nb*k_Bs + i_Bs*i_Nb*j5_LV*j_Bs + i5_LV*i_Bs", // 'stride_X' will have the expression of i_Nb*i_Bs locally
    },
    // Expected global embeddings
    {"(i_Bs*i_Nb*j_Bs*j_Nb*k_Bs)","(i_Bs*i_Nb*j_Bs)","i_Bs"},
    // Expected access descriptors
    1,
    { // Expected local embeddings
      {"1","1","1"},
      {"1","1","1"},
      {"1","1","1"},
      {"1","1","1"},
      {"1","1","1"},
    },
    { // Expected local coords
      {"k1_LV","j1_LV","i1_LV"},
      {"k2_LV","j2_LV","i2_LV"},
      {"k3_LV","j3_LV","i3_LV"},
      {"k4_LV","j4_LV","i4_LV"},
      {"k5_LV","j5_LV","i5_LV"}
    },
    // Expected local offsets
    {"0","0","0","0","0"}
  );


}


} // namespace bld::src::pc

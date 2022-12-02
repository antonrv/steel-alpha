
#include "source/token/test/interface.hpp"

#include "source/token/make/piece.hpp"

#include "source/token/region/affine/access.hpp"
#include "source/token/region/affine/guard.hpp"

#include "source/token/multiple/range.hpp"
#include "common/util.hpp"

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iostream>

namespace bld::src::pc {

struct str_range {
  std::string min;
  std::string max;

  bool operator==(const str_range& other) const {
    return other.min == this->min and other.max == this->max;
  }
};

using str_ranges_t = std::vector<str_range>;

static
bool lv_pivot(cpiece_t pivPc) {
  return pivPc->get_kind() == kind::var and pivPc->get_pc_string().find("LV") != std::string::npos;
}

static
std::string vec_to_string(const vec_string_t& vec) {
  std::string retStr;
  for (const auto& str : vec) { retStr += str + ","; }
  if (not retStr.empty()) {retStr.pop_back();}
  return retStr;
}

static
std::string ranges_to_string(const str_ranges_t& rngs) {
  std::string retStr;

  return std::accumulate(std::begin(rngs), std::end(rngs), std::string(),
    [] (const std::string& cum, const str_range& rng) {
      return cum + "["  + rng.min + "," + rng.max + "], ";
    }
  );

  return retStr;
}

static
std::string vec_ranges_to_string(const std::vector<str_ranges_t>& rngs) {

  return std::accumulate( std::begin(rngs), std::end(rngs), std::string(), [] (const std::string& cum, const str_ranges_t& rs) { return cum + ranges_to_string(rs); } );
}


static
str_ranges_t printable_ranges(const vec_ctoken_t<kind::range> rngs) {

  return transform_vec( rngs, 
      [] (ctoken_t<kind::range> rng) {
        return str_range({rng->get_limit<range_limit::min>()->get_pc_string(), rng->get_limit<range_limit::max>()->get_pc_string()});
      });

}

static
str_ranges_t affine_to_ranges(const affine_access * affAcc, const affine_guard * affGuard) {

  return printable_ranges( affGuard->get_local_mem_ranges( affAcc ).get_vec() );
}


void test_guard_range(
  std::string callerAffStr,
  const vec_string_t dsAffineStrs,
  const std::vector<str_ranges_t> expectedRangesDS,
  const str_ranges_t expectedRangesFullDS,
  const str_ranges_t expectedRangesCaller,
  const str_ranges_t expectedRangesFullCaller) {

  if (dsAffineStrs.size() != expectedRangesDS.size()) {
    throw std::logic_error("Test ill-formed for\"" + callerAffStr + "\" and " + vec_to_string(dsAffineStrs) + " : expected same # of ds affine expressions and expected downstream ranges");
  }

  // std::cout << "Testing : " << callerAffStr << '\n';


  // Build all the DS affines
  auto dsAffPcs = transform_vec(dsAffineStrs, [] (const std::string& affStr) { return std::make_unique< const affine_access >( make_piece( affStr ).get(), lv_pivot ); });

  auto dsAffPcsRaw = transform_vec(dsAffPcs, [] (const auto& aff) { return static_cast<const affine_access*>(aff.get()); } );

  // Build ds guard ...
  auto dsAffGuard = std::make_unique< const affine_guard >( dsAffPcsRaw ); 

  // Check DS ranges
  {
    auto gotRangesDS = transform_vec(dsAffPcsRaw, std::bind(affine_to_ranges, std::placeholders::_1, dsAffGuard.get()));

    if (gotRangesDS != expectedRangesDS) {
      auto gotStr = vec_ranges_to_string(gotRangesDS);
      auto expectedStr = vec_ranges_to_string(expectedRangesDS);
      throw std::runtime_error("test_guard_ranges failed -unexpected DS ranges for \"" + callerAffStr + "\" and \"" + vec_to_string(dsAffineStrs) + "\". Got : " + gotStr + ". Expected : " + expectedStr);
    }
  }

  // Check DS full ranges
  {
    auto gotRangesFullDS = printable_ranges( dsAffGuard->get_global_mem_ranges().get_vec() );

    if (gotRangesFullDS != expectedRangesFullDS) {
      throw std::runtime_error("test_guard_ranges failed -unexpected Full DS ranges for \"" + callerAffStr + "\" and " + vec_to_string(dsAffineStrs) + ". Got : " + ranges_to_string(gotRangesFullDS) + ". Expected : " + ranges_to_string(expectedRangesFullDS));
    }
  }


  // Build caller affine...
   auto callerAffine = std::make_unique< affine_access >( make_piece( callerAffStr ).get(), lv_pivot );

  // ... set callerAffine ds guard ...
  callerAffine->set_downstream_guard( dsAffGuard.get() );

  // ... and set caller guard from a single affine.
  std::vector<const affine_access*> guardConstructorArg({static_cast<const affine_access*>(callerAffine.get()) });
  auto callerAffGuard = std::make_unique< affine_guard >( guardConstructorArg );


  // Check caller range
  {
    auto gotRangesCaller = affine_to_ranges( callerAffine.get(), callerAffGuard.get() );

    if (gotRangesCaller != expectedRangesCaller) {
      throw std::runtime_error("test_guard_ranges failed -unexpected Caller ranges for \"" + callerAffStr + "\" and " + vec_to_string(dsAffineStrs) + ". Got : " + ranges_to_string(gotRangesCaller) + ". Expected : " + ranges_to_string(expectedRangesCaller));

    }
  }


  // Check caller full ranges
  {
    auto gotRangesFullCaller = printable_ranges( callerAffGuard->get_global_mem_ranges().get_vec() );

    if (gotRangesFullCaller != expectedRangesFullCaller) {
      throw std::runtime_error("test_guard_ranges failed -unexpected Full Caller ranges for \"" + callerAffStr + "\" and " + vec_to_string(dsAffineStrs) + ". Got : " + ranges_to_string(gotRangesFullCaller) + ". Expected : " + ranges_to_string(expectedRangesFullCaller));

    }
  }

}



template <>
void run_tests<token_test::guard_range>() {

  ///////////////////////////////////
  /////////////////
  ///////////////// 0D IN CALLER - 0D IN CALLEE
  /////////////////
  ///////////////////////////////////
  // Point in caller, 1 access 1d in callee
  test_guard_range(
    // Caller affine expr
    "0",
    { // Downstream affine exprs
      "0",
    },
    { // Expected vec of downstream ranges
      {/*range_t*/}
    },
    { // Expected full downstream ranges
    },
    { // Expected caller ranges
    },
    { // Expected full caller ranges
    }
  );

  ///////////////////////////////////
  /////////////////
  ///////////////// 0D IN CALLER - 0D IN CALLEE
  /////////////////
  ///////////////////////////////////
  // Point in caller, 1 access 1d in callee
  test_guard_range(
    // Caller affine expr
    "a",
    { // Downstream affine exprs
      "0",
    },
    { // Expected vec of downstream ranges
      {}
    },
    { // Expected full downstream ranges
    },
    { // Expected caller ranges
    },
    { // Expected full caller ranges
    }
  );

  ///////////////////////////////////
  /////////////////
  ///////////////// 0D IN CALLER - 1D IN CALLEE
  /////////////////
  ///////////////////////////////////

  // Point in caller, 1 access 1d in callee
  test_guard_range(
    // Caller affine expr
    "0",
    { // Downstream affine exprs
      "iLV",
    },
    { // Expected vec of downstream ranges
      {/*range_t*/{"min(iLV)","max(iLV)"}}
    },
    { // Expected full downstream ranges
      {"min(iLV)", "max(iLV)"}
    },
    { // Expected caller ranges
      {"min(iLV)", "max(iLV)"}
    },
    { // Expected full caller ranges
      {"min(iLV)", "max(iLV)"}
    }
  );

  // Point in caller, 1 access 1d in callee, with offset
  test_guard_range(
    // Caller affine expr
    "0",
    { // Downstream affine exprs
      "iLV + offs",
    },
    { // Expected vec of downstream ranges
      {/*range_t*/{"(min(iLV)+offs)","(max(iLV)+offs)"}}
    },
    { // Expected full downstream ranges
      {"(min(iLV)+offs)", "(max(iLV)+offs)"}
    },
    { // Expected caller ranges
      {"(min(iLV)+offs)", "(max(iLV)+offs)"}
    },
    { // Expected full caller ranges
      {"(min(iLV)+offs)", "(max(iLV)+offs)"}
    }
  );


  // Point in caller, 2 accesses 1d in callee
  test_guard_range(
    // Caller affine expr
    "0",
    { // Downstream affine exprs
      "iLV",
      "jLV",
    },
    { // Expected vec of downstream ranges
      {/*range_t*/{"min(iLV)","max(iLV)"}},
      {/*range_t*/{"min(jLV)","max(jLV)"}}
    },
    { // Expected full downstream ranges
      {"(min(iLV),min(jLV))", "(max(iLV),max(jLV))"}
    },
    { // Expected caller ranges
      {"(min(iLV),min(jLV))", "(max(iLV),max(jLV))"}
    },
    { // Expected full caller ranges
      {"(min(iLV),min(jLV))", "(max(iLV),max(jLV))"}
    }
  );

  // Point in caller, 3 accesses 1d in callee
  test_guard_range(
    // Caller affine expr
    "0",
    { // Downstream affine exprs
      "iLV",
      "jLV",
      "kLV",
    },
    { // Expected vec of downstream ranges
      {/*range_t*/{"min(iLV)","max(iLV)"}},
      {/*range_t*/{"min(jLV)","max(jLV)"}},
      {/*range_t*/{"min(kLV)","max(kLV)"}}
    },
    { // Expected full downstream ranges
      {"(min(iLV),min(jLV),min(kLV))", "(max(iLV),max(jLV),max(kLV))"}
    },
    { // Expected caller ranges
      {"(min(iLV),min(jLV),min(kLV))", "(max(iLV),max(jLV),max(kLV))"}
    },
    { // Expected full caller ranges
      {"(min(iLV),min(jLV),min(kLV))", "(max(iLV),max(jLV),max(kLV))"}
    }
  );

  ///////////////////////////////////
  /////////////////
  ///////////////// 1D IN CALLER - 1D IN CALLEE
  /////////////////
  ///////////////////////////////////

  //////////////////////  Same as before with an expression in caller

  // 1d in caller, 1 access 1d in callee
  test_guard_range(
    // Caller affine expr
    "iLVc",
    { // Downstream affine exprs
      "iLV",
    },
    { // Expected vec of downstream ranges
      {/*range_t*/{"min(iLV)","max(iLV)"}}
    },
    { // Expected full downstream ranges
      {"min(iLV)", "max(iLV)"}
    },
    { // Expected caller ranges
      {"(iLVc+min(iLV))", "(iLVc+max(iLV))"}
    },
    { // Expected full caller ranges
      {"(min(iLV)+min(iLVc))", "(max(iLV)+max(iLVc))"}
    }
  );

  // 1d in caller, 1 access 1d in callee, with offset
  test_guard_range(
    // Caller affine expr
    "iLVc",
    { // Downstream affine exprs
      "iLV + offs",
    },
    { // Expected vec of downstream ranges
      {/*range_t*/{"(min(iLV)+offs)","(max(iLV)+offs)"}}
    },
    { // Expected full downstream ranges
      {"(min(iLV)+offs)", "(max(iLV)+offs)"}
    },
    { // Expected caller ranges
      {"(iLVc+min(iLV)+offs)", "(iLVc+max(iLV)+offs)"}
    },
    { // Expected full caller ranges
      {"(min(iLV)+min(iLVc)+offs)", "(max(iLV)+max(iLVc)+offs)"}
    }
  );


  // 1d in caller, 2 accesses 1d in callee
  test_guard_range(
    // Caller affine expr
    "iLVc",
    { // Downstream affine exprs
      "iLV",
      "jLV",
    },
    { // Expected vec of downstream ranges
      {/*range_t*/{"min(iLV)","max(iLV)"}},
      {/*range_t*/{"min(jLV)","max(jLV)"}}
    },
    { // Expected full downstream ranges
      {"(min(iLV),min(jLV))", "(max(iLV),max(jLV))"}
    },
    { // Expected caller ranges
      {"(iLVc+(min(iLV),min(jLV)))", "(iLVc+(max(iLV),max(jLV)))"}
    },
    { // Expected full caller ranges
      {"(min(iLVc)+(min(iLV),min(jLV)))", "(max(iLVc)+(max(iLV),max(jLV)))"}
    }
  );

  // 1d in caller, 3 accesses 1d in callee
  test_guard_range(
    // Caller affine expr
    "iLVc",
    { // Downstream affine exprs
      "iLV",
      "jLV",
      "kLV",
    },
    { // Expected vec of downstream ranges
      {/*range_t*/{"min(iLV)","max(iLV)"}},
      {/*range_t*/{"min(jLV)","max(jLV)"}},
      {/*range_t*/{"min(kLV)","max(kLV)"}}
    },
    { // Expected full downstream ranges
      {"(min(iLV),min(jLV),min(kLV))", "(max(iLV),max(jLV),max(kLV))"}
    },
    { // Expected caller ranges
      {"(iLVc+(min(iLV),min(jLV),min(kLV)))", "(iLVc+(max(iLV),max(jLV),max(kLV)))"}
    },
    { // Expected full caller ranges
      {"(min(iLVc)+(min(iLV),min(jLV),min(kLV)))", "(max(iLVc)+(max(iLV),max(jLV),max(kLV)))"}
    }
  );


  ///////////////////////////////////
  /////////////////
  ///////////////// 2D IN CALLER - 2D IN CALLEE
  /////////////////
  ///////////////////////////////////

  // 1 access 2d in caller, 1 access 2d in callee
  test_guard_range(
    // Caller affine expr
    "jLVc*stride + iLVc",
    { // Downstream affine exprs
      "jLV*stride + iLV",
    },
    { // Expected vec of downstream ranges
      {
        {"min(jLV)","max(jLV)"}, // 1st dim
        {"min(iLV)","max(iLV)"}  // 2nd dim
      }
    },
    { // Expected full downstream ranges
        {"min(jLV)","max(jLV)"}, // 1st dim
        {"min(iLV)","max(iLV)"}  // 2nd dim
    },
    { // Expected caller ranges
      {"(jLVc+min(jLV))", "(jLVc+max(jLV))"}, // 1st dim
      {"(iLVc+min(iLV))", "(iLVc+max(iLV))"} // 2nd dim
    },
    { // Expected full caller ranges
      {"(min(jLV)+min(jLVc))", "(max(jLV)+max(jLVc))"}, // 1st dim
      {"(min(iLV)+min(iLVc))", "(max(iLV)+max(iLVc))"} // 2nd dim
    }
  );

  // 1 block access 2d in caller, 1 access 2d in callee
  test_guard_range(
    // Caller affine expr
    "jLVc*bSj*nBi*bSi + iLVc*bSi",
    { // Downstream affine exprs
      "jLV*nBi*bSi + iLV",
    },
    { // Expected vec of downstream ranges
      {
        {"min(jLV)","max(jLV)"}, // 1st dim
        {"min(iLV)","max(iLV)"}  // 2nd dim
      }
    },
    { // Expected full downstream ranges
        {"min(jLV)","max(jLV)"}, // 1st dim
        {"min(iLV)","max(iLV)"}  // 2nd dim
    },
    { // Expected caller ranges
      {"(min(jLV)+(bSj*jLVc))", "(max(jLV)+(bSj*jLVc))"}, // 1st dim
      {"(min(iLV)+(bSi*iLVc))", "(max(iLV)+(bSi*iLVc))"} // 2nd dim
    },
    { // Expected full caller ranges
      {"(min(jLV)+(bSj*min(jLVc)))", "(max(jLV)+(bSj*max(jLVc)))"}, // 1st dim
      {"(min(iLV)+(bSi*min(iLVc)))", "(max(iLV)+(bSi*max(iLVc)))"} // 2nd dim
    }
  );

  ///////////////////////////////////
  /////////////////
  ///////////////// 2D IN CALLER - 2D IN CALLEE
  /////////////////
  ///////////////////////////////////

  // 1 access 3d in caller, 1 access 3d in callee
  test_guard_range(
    // Caller affine expr
    "kLVc*stride_i*stride_j + jLVc*stride_i + iLVc",
    { // Downstream affine exprs
      "kLV*stride_i*stride_j + jLV*stride_i + iLV",
    },
    { // Expected vec of downstream ranges
      {
        {"min(kLV)","max(kLV)"}, // 1st dim
        {"min(jLV)","max(jLV)"}, // 2nd dim
        {"min(iLV)","max(iLV)"}  // 3rd dim
      }
    },
    { // Expected full downstream ranges
        {"min(kLV)","max(kLV)"},  // 1st dim
        {"min(jLV)","max(jLV)"}, // 2nd dim
        {"min(iLV)","max(iLV)"}  // 3rd dim
    },
    { // Expected caller ranges
      {"(kLVc+min(kLV))", "(kLVc+max(kLV))"}, // 1st dim
      {"(jLVc+min(jLV))", "(jLVc+max(jLV))"}, // 2nd dim
      {"(iLVc+min(iLV))", "(iLVc+max(iLV))"} // 3rd dim
    },
    { // Expected full caller ranges
      {"(min(kLV)+min(kLVc))", "(max(kLV)+max(kLVc))"}, // 1st dim
      {"(min(jLV)+min(jLVc))", "(max(jLV)+max(jLVc))"}, // 2nd dim
      {"(min(iLV)+min(iLVc))", "(max(iLV)+max(iLVc))"} // 3rd dim
    }
  );


  // 1 block access 3d in caller, 1 access 3d in callee
  test_guard_range(
    // Caller affine expr
    "kLVc*bSk*nBj*bSj*nBi*bSi + jLVc*bSj*nBi*bSi + iLVc*bSi",
    { // Downstream affine exprs
      "kLV*nBj*bSj*nBi*bSi + jLV*nBi*bSi + iLV",
    },
    { // Expected vec of downstream ranges
      {
        {"min(kLV)","max(kLV)"}, // 1st dim
        {"min(jLV)","max(jLV)"}, // 2nd dim
        {"min(iLV)","max(iLV)"}  // 3rd dim
      }
    },
    { // Expected full downstream ranges
        {"min(kLV)","max(kLV)"}, // 1st dim
        {"min(jLV)","max(jLV)"}, // 2nd dim
        {"min(iLV)","max(iLV)"}  // 3rd dim
    },
    { // Expected caller ranges
      {"(min(kLV)+(bSk*kLVc))", "(max(kLV)+(bSk*kLVc))"}, // 1st dim
      {"(min(jLV)+(bSj*jLVc))", "(max(jLV)+(bSj*jLVc))"}, // 2nd dim
      {"(min(iLV)+(bSi*iLVc))", "(max(iLV)+(bSi*iLVc))"} // 3rd dim
    },
    { // Expected full caller ranges
      {"(min(kLV)+(bSk*min(kLVc)))", "(max(kLV)+(bSk*max(kLVc)))"}, // 1st dim
      {"(min(jLV)+(bSj*min(jLVc)))", "(max(jLV)+(bSj*max(jLVc)))"}, // 2nd dim
      {"(min(iLV)+(bSi*min(iLVc)))", "(max(iLV)+(bSi*max(iLVc)))"} // 3rd dim
    }
  );
}

} // namespace bld::src::pc

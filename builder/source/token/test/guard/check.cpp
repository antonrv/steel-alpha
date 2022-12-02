

#include "source/token/make/piece.hpp"

#include "source/token/region/affine/access.hpp"
#include "source/token/region/affine/guard.hpp"

#include "source/token/multiple/range.hpp"

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
std::string vecvec_to_string(const std::vector<vec_string_t>& vv) {
  std::string retStr;
  for (const auto& v : vv) { retStr += vec_to_string(v) + " ; "; }
  return retStr;
}

static
bool lv_pivot(cpiece_t pivPc) {
  return pivPc->get_kind() == kind::var and pivPc->get_pc_string().find("LV") != std::string::npos;
}


void test_guard(
  const vec_string_t inputAffineStrs,
  const vec_string_t expectGlobalEmbeds,
  const unsigned expectDescriptorsCount,
  const std::vector<vec_string_t> expectAffineLocalEmbeds,
  const std::vector<vec_string_t> expectAffineLocalCoords,
  const vec_string_t expectAffineLocalOffsets)
{
  const auto inputStr = vec_to_string(inputAffineStrs);

  // std::cout << "Testing : " << inputStr << '\n';

  if (inputAffineStrs.size() != expectAffineLocalEmbeds.size() or expectAffineLocalEmbeds.size() != expectAffineLocalCoords.size()) {
    throw std::logic_error("Test ill-formed for \"" + inputStr + "\" : expected same # of affine exprs, local embeddings and affine local coords");
  }

  const auto nAffineExprs = inputAffineStrs.size();

  // Build all the affines
  auto affPcs = transform_vec(inputAffineStrs, [] (const std::string& affStr) { return std::make_unique< const affine_access >( make_piece( affStr ).get(), lv_pivot ); });

  // std::cout << "Affine pcs : " << affPcs.size() << '\n';
  // std::cout << "Built affine " << affPcs.front()->get_pc_string() << '\n'; 

  auto affPcsRaw = transform_vec( affPcs, [] (const auto& ownAff) { return ownAff.get(); } );

  auto affGuard = std::make_unique< const affine_guard >( affPcsRaw ); 

  auto embedPcs = affGuard->get_global_embeddings().get_vec();
  auto gotGlobalEmbeds = transform_vec(embedPcs, [] (cpiece_t embedPc) { return embedPc->get_pc_string(); });


  // ============ Verify affGuard global embeds
  if (gotGlobalEmbeds != expectGlobalEmbeds) {
    throw std::runtime_error("test_guard failed -unexpected guard global embeddings for \"" + inputStr + "\". Got : " + vec_to_string(gotGlobalEmbeds) + ". Expected : " + vec_to_string(expectGlobalEmbeds));
  }
  

  // ============ Verify guard descriptors count
  auto gotDescriptorsCount = affGuard->get_vec_string_unique_local_embeds().size();
  if (gotDescriptorsCount != expectDescriptorsCount) {
    throw std::runtime_error("test_guard failed -wrong descriptors count for  \"" + inputStr + "\". Got : " + std::to_string(gotDescriptorsCount) + ". Expected : " + std::to_string(expectDescriptorsCount));
  }

  // ============ Verify affine local embeddings
  {
    std::vector<vec_string_t> gotAffineLocalEmbeds(nAffineExprs);

    for (auto i = 0u; i < nAffineExprs; i++) {

      auto affFactors = affGuard->get_local_embeddings( affPcs[i].get() );

      std::transform( std::begin(affFactors), std::end(affFactors), std::back_inserter(gotAffineLocalEmbeds[i]),
          [] (cpiece_t pc) { return pc->get_pc_string(); } );
    }

    if (gotAffineLocalEmbeds != expectAffineLocalEmbeds) {
      auto gotStr = vecvec_to_string(gotAffineLocalEmbeds);
      auto expectStr = vecvec_to_string(expectAffineLocalEmbeds);

      throw std::runtime_error("test_guard failed -unexpected affine local embeddings for \"" + inputStr + "\". Got : " + gotStr + ". Expected : " + expectStr);
    }
  }

  // ============ Verify affine local coords
  {
    std::vector<vec_string_t> gotAffineLocalCoords(nAffineExprs);

    for (auto i = 0u; i < nAffineExprs; i++) {

      auto affCoords = affGuard->get_local_coordinates( affPcs[i].get() );

      std::transform( std::begin(affCoords), std::end(affCoords), std::back_inserter(gotAffineLocalCoords[i]),
        [] (cpiece_t pc) { return pc->get_pc_string(); } );
    }

    if (gotAffineLocalCoords != expectAffineLocalCoords) {
      auto gotStr = vecvec_to_string(gotAffineLocalCoords);
      auto expectStr = vecvec_to_string(expectAffineLocalCoords);

      throw std::runtime_error("test_guard failed -unexpected affine local coordinates for \"" + inputStr + "\". Got : " + gotStr + ". Expected : " + expectStr);
    }
  }

  // ============ Verify affine local offsets
  {
    vec_string_t gotAffineLocalOffsets;

    for (auto i = 0u; i < nAffineExprs; i++) {

      auto affOffset = affGuard->get_local_offset( affPcs[i].get() );
      gotAffineLocalOffsets.push_back( affOffset->get_pc_string() );
    }

    if (gotAffineLocalOffsets != expectAffineLocalOffsets) {
      auto gotStr = vec_to_string(gotAffineLocalOffsets);
      auto expectStr = vec_to_string(expectAffineLocalOffsets);

      throw std::runtime_error("test_guard failed -unexpected affine local offsets for \"" + inputStr + "\". Got : " + gotStr + ". Expected : " + expectStr);
    }
  }
}

} // namespace bld::src::pc

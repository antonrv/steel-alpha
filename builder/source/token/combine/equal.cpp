

#include "source/token/combine/interface.hpp"

#include "source/token/multiple/multiple.hpp"
#include "source/token/terminal/var.hpp"
#include "source/token/terminal/num.hpp"

#ifndef PARSER_TEST
#include "source/object/data/decl.hpp"
#include "source/object/data/use.hpp"
#include "source/object/data/transform/interface.hpp"
#endif // PARSER_TEST

#include <algorithm>

namespace bld::src::pc {



template <typename T>
bool are_equal_detail(T inLhs, T inRhs);

template <>
bool are_equal_detail(ctoken_t<kind::num> inLhs, ctoken_t<kind::num> inRhs) {
  return inLhs->get_value() == inRhs->get_value();
}

template <>
bool are_equal_detail(ctoken_t<kind::var> inLhs, ctoken_t<kind::var> inRhs) {
#ifdef PARSER_TEST
  return inLhs->get_unsigned_name() == inRhs->get_unsigned_name();
#else
  return inLhs->get_data_use()->get_root_data_decl()->get_identifier() == inRhs->get_data_use()->get_root_data_decl()->get_identifier();
#endif // PARSER_TEST
}



template <>
bool are_equal_detail(const multiple * inLhs, const multiple * inRhs) {

  auto nToks = inLhs->get_token_count();

  if (nToks != inRhs->get_token_count()) {
    return false;
  }

  auto canonLhs = canonicalize( inLhs->get_tokens() );
  auto canonRhs = canonicalize( inRhs->get_tokens() );

  using pair_t = std::pair<cpiece_t, cpiece_t>;
  std::vector<pair_t> pairs;
  for (auto i = 0u; i < nToks; i++) {
    pairs.push_back( std::make_pair( canonLhs.at(i), canonRhs.at(i) ) );
  }

  return std::all_of( std::begin(pairs), std::end(pairs), [] (const pair_t& p) { return are_equal(p.first, p.second); } );
}

#ifdef PARSER_TEST
std::pair<own_piece_t, own_piece_t> align_contexts_uniform( cpiece_t inLhs, cpiece_t inRhs) {
  throw std::logic_error("No need to call align_contexts_uniform in PARSER_TEST mode");
}
#endif // PARSER_TEST


static
bool are_equal_same_global(cpiece_t inLhs, cpiece_t inRhs) {

  if (not on_same_global_context(inLhs, inRhs)) {
    throw std::logic_error("are_equal_same_global only callable when both pieces have different global contexts");
  }

  auto commonPck = inLhs->get_kind();
  if (inRhs->get_kind() != commonPck) {
// #ifndef PARSER_TEST
//    INVALID. TRIGGERS INFINITE RECURSION
//     auto funTest = [] (cpiece_t lhs, cpiece_t rhs) {
//         return are_equal_same_global( lhs, rhs );
//       };
//     return test_on_multiple_local_contexts( inLhs, inRhs, false,[](const bool v){return v}, funTest );
// #else // PARSER_TEST
     return false;
// #endif // PARSER_TEST
  }

  if (commonPck == kind::num) {
    return are_equal_detail( static_cast<ctoken_t<kind::num>>(inLhs), static_cast<ctoken_t<kind::num>>(inRhs) );
  } else if (commonPck == kind::var) {
    return are_equal_detail( static_cast<ctoken_t<kind::var>>(inLhs), static_cast<ctoken_t<kind::var>>(inRhs) );
  } else if (commonPck == kind::addends or commonPck == kind::factors or commonPck == kind::fraction) {
    return are_equal_detail( static_cast<const multiple *>(inLhs), static_cast<const multiple *>(inRhs) );
  } else {
    throw std::logic_error("Unreachable in  are_equal. Could not handle : " + std::string(util::enum_convert<kind>::to_string_rt(inRhs->get_kind())));
  }
}


static
bool are_equal_different_global(cpiece_t inLhs, cpiece_t inRhs) {


  if (not on_same_global_context(inLhs, inRhs)) {

    auto [trLhs, trRhs] = align_contexts_uniform( inLhs, inRhs );

    return are_equal_same_global( trLhs.get(), trRhs.get() );
    
  } else {
    throw std::logic_error("are_equal_different_global only callable when both pieces have different global contexts");
  }

}

///////////////
//
// INTERFACE
//
///////////////
bool are_equal(cpiece_t inLhs, cpiece_t inRhs) {

  if ((not inLhs->is_arith()) or (not inRhs->is_arith())) {
    throw std::logic_error("Cannot are_equal on pieces. Require arithmetic pieces : " + inLhs->get_kind_str() + ", " + inRhs->get_kind_str());
  }

  if (not on_same_global_context(inLhs, inRhs)) {
    return are_equal_different_global( inLhs, inRhs );
  } else {
    return are_equal_same_global( inLhs, inRhs );
  }

}

///////////////
//
// INTERFACE
//
///////////////
bool on_same_global_context(cpiece_t inLhs, cpiece_t inRhs) {

  auto gcLhs = inLhs->get_global_context();
  auto gcRhs = inRhs->get_global_context();

  return gcLhs == UniversalCtxt or gcRhs == UniversalCtxt or gcLhs == gcRhs;
}

} // namespace bld::src::pc

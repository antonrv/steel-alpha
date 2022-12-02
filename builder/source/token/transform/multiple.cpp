
#include "source/token/transform/multiple.hpp"

#include "source/token/make/token.hpp"

#include "common/util.hpp"


namespace bld::src::pc {


///////////////
//
// INTERFACE
//
///////////////
std::unique_ptr<multiple> transform_piece_multiple( const multiple * inputMulPc, std::function<own_piece_t(cpiece_t)>&& lambdaRecurse ) {

  auto tokensCst = inputMulPc->get_tokens();

  auto newPieces = transform_vec( tokensCst, lambdaRecurse );

  std::unique_ptr<multiple> newPc;

  if (inputMulPc->get_kind() == kind::addends) {
    newPc = make_token< kind::addends >( std::move(newPieces) );
  } else if (inputMulPc->get_kind() == kind::factors) {
    newPc = make_token< kind::factors >( std::move(newPieces) );
    if (inputMulPc->get_sign() == sign::neg) { newPc->flip_sign(); }
  } else if (inputMulPc->get_kind() == kind::fraction) {
    auto isMod = static_cast<ctoken_t<kind::fraction>>(inputMulPc)->is_mod();
    newPc = make_token< kind::fraction >( std::move(newPieces), isMod );
    if (inputMulPc->get_sign() == sign::neg) { newPc->flip_sign(); }
  } else if (inputMulPc->get_kind() == kind::offset) {
    newPc = make_token< kind::offset >( std::move(newPieces) );
    if (inputMulPc->get_sign() == sign::neg) { newPc->flip_sign(); }
  } else if (inputMulPc->get_kind() == kind::range) {
    newPc = make_token< kind::range >( std::move(newPieces) );
  } else if (inputMulPc->get_kind() == kind::cs_list) {
    newPc = make_token< kind::cs_list >( std::move(newPieces) );
  } else {
    throw std::logic_error("Unreachable in transform piece chain : PCK: " + std::string(util::enum_convert<kind>::to_string_rt(inputMulPc->get_kind())));
  }


  return newPc;
}

} // namespace bld::src::pc

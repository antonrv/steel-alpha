#ifndef PARSER_TRANSFORM_MULTIPLE_HPP
#define PARSER_TRANSFORM_MULTIPLE_HPP


// To transitively include the basic pieces
#include "source/token/terminal/num.hpp"
#include "source/token/terminal/var.hpp"
#include "source/token/terminal/loopvar.hpp"
#include "source/token/multiple/addends.hpp"
#include "source/token/multiple/factors.hpp"
#include "source/token/multiple/fraction.hpp"
#include "source/token/multiple/offset.hpp"
#include "source/token/multiple/cs_list.hpp"
#include "source/token/multiple/range.hpp"


namespace bld::src::pc {

std::unique_ptr<multiple> transform_piece_multiple( const multiple * inputPcMul, std::function<own_piece_t(cpiece_t)>&& lambdaRecurse);

} // namespace bld::src::pc

#endif // PARSER_TRANSFORM_MULTIPLE_HPP

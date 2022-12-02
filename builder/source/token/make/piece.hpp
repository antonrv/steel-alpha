#ifndef ARIT_PIECE_MAKE_HPP
#define ARIT_PIECE_MAKE_HPP

// To transitively include the basic pieces
#include "source/token/terminal/var.hpp"
#include "source/token/terminal/num.hpp"
#include "source/token/terminal/undef.hpp"
#include "source/token/multiple/addends.hpp"
#include "source/token/multiple/factors.hpp"
#include "source/token/multiple/cs_list.hpp"
#include "source/token/multiple/fraction.hpp"
#include "source/token/multiple/address.hpp"
#include "source/token/multiple/offset.hpp"
#include "source/token/multiple/call.hpp"
#include "source/token/multiple/binop.hpp"

#include <string>


namespace bld::src::pc {

class piece;

own_piece_t make_piece(std::string str);


} // namespace bld::src::pc

#endif // ARIT_PIECE_MAKE_HPP

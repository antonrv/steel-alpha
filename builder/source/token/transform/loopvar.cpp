

#include "source/token/transform/loopvar.hpp"

#include "source/token/transform/range.hpp"

#include "source/token/terminal/num.hpp"
#include "source/token/terminal/loopvar.hpp"
#include "source/token/multiple/addends.hpp"

#include "source/token/make/token.hpp"

#include <iostream> // DBG XXX
#include <sstream>

namespace bld::src::pc {


template <range_limit RL, opkind OpK>
struct defining_operation;


template <> struct defining_operation<range_limit::min, opkind::leq> {
  static constexpr lv_trait loopOpKind = lv_trait::start;
  static constexpr const char * bound_string = "";
};
template <> struct defining_operation<range_limit::min, opkind::lt> {
  static constexpr lv_trait loopOpKind = lv_trait::start;
  static constexpr const char * bound_string = "";
};
template <> struct defining_operation<range_limit::min, opkind::geq> {
  static constexpr lv_trait loopOpKind = lv_trait::bound;
  static constexpr const char * bound_string = "";
};
template <> struct defining_operation<range_limit::min, opkind::gt> {
  static constexpr lv_trait loopOpKind = lv_trait::bound;
  static constexpr const char * bound_string = "1";
};
template <> struct defining_operation<range_limit::max, opkind::leq> {
  static constexpr lv_trait loopOpKind = lv_trait::bound;
  static constexpr const char * bound_string = "1"; // "0"
};
template <> struct defining_operation<range_limit::max, opkind::lt> {
  static constexpr lv_trait loopOpKind = lv_trait::bound;
  static constexpr const char * bound_string = ""; // -1
};
template <> struct defining_operation<range_limit::max, opkind::geq> {
  static constexpr lv_trait loopOpKind = lv_trait::start;
  static constexpr const char * bound_string = "1"; 
};
template <> struct defining_operation<range_limit::max, opkind::gt> {
  static constexpr lv_trait loopOpKind = lv_trait::start;
  static constexpr const char * bound_string = "";
};

template <opkind OpK>
struct loop_count;

template <> struct loop_count<opkind::lt> {
  static constexpr const char * count_string = "";
};
template <> struct loop_count<opkind::gt> {
  static constexpr const char * count_string = "";
};
template <> struct loop_count<opkind::leq> {
  static constexpr const char * count_string = "1";
};
template <> struct loop_count<opkind::geq> {
  static constexpr const char * count_string = "1";
};



template <range_limit RL>
static
std::string deduce_bound_str(opkind opk) {

  if (opk == opkind::leq) {
    return defining_operation<RL, opkind::leq>::bound_string;
  } else if (opk == opkind::lt) {
    return defining_operation<RL, opkind::lt>::bound_string;
  } else if (opk == opkind::geq) {
    return defining_operation<RL, opkind::geq>::bound_string;
  } else if (opk == opkind::gt) {
    return defining_operation<RL, opkind::gt>::bound_string;
  } else {
    throw std::logic_error("Unhandled opkind in deduce_bound_str : " + std::string(util::enum_convert<opkind>::to_string_rt(opk)));
  }
}

///////////////
//
// INTERFACE
//
///////////////
std::string deduce_count_str(opkind opk) {
  if (opk == opkind::leq) {
    return loop_count<opkind::leq>::count_string;
  } else if (opk == opkind::lt) {
    return loop_count<opkind::lt>::count_string;
  } else if (opk == opkind::geq) {
    return loop_count<opkind::geq>::count_string;
  } else if (opk == opkind::gt) {
    return loop_count<opkind::gt>::count_string;
  } else {
    throw std::logic_error("Unhandled opkind in deduce_count_str : " + std::string(util::enum_convert<opkind>::to_string_rt(opk)));
  }
}

///////////////
//
// INTERFACE
//
///////////////
template <range_limit RL>
cpiece_t
deduce_piece(cloopvar_t loopVar, const opkind opk) {

  if (opk == opkind::leq) {
    return loopVar->get_expression< defining_operation<RL, opkind::leq>::loopOpKind >();
  } else if (opk == opkind::lt) {
    return loopVar->get_expression< defining_operation<RL, opkind::lt>::loopOpKind >();
  } else if (opk == opkind::geq) {
    return loopVar->get_expression< defining_operation<RL, opkind::geq>::loopOpKind >();
  } else if (opk == opkind::gt) {
    return loopVar->get_expression< defining_operation<RL, opkind::gt>::loopOpKind >();
  } else {
    throw std::logic_error("Unhandled opkind in deduce_piece : " + std::string(util::enum_convert<opkind>::to_string_rt(opk)));
  }
}

///////////////
//
// INTERFACE
//
///////////////
template <range_limit RL>
own_piece_t make_piece_limit(cloopvar_t loopVar) {

  static_assert( RL == range_limit::min or RL == range_limit::max ); // Deprecate range_limit::fix TODO

  if (not loopVar->all_defined()) {
#ifdef PARSER_TEST
    // Do not compute anything if lv is not fully defined, just return it back
    std::string rlStr = util::enum_convert<range_limit>::to_string<RL>();
    return std::make_unique< raw_str >( rlStr + "(" + loopVar->get_pc_string() + ")" );
#else // PARSER_TEST
    throw std::logic_error("make_piece_limit on loopVar expects loopVar to be defined : " + loopVar->get_info());
#endif
  }

  auto opkindBound = loopVar->get_opkind<lv_trait::bound>();

  auto pcLimit = deduce_piece< RL >( loopVar, opkindBound );

  auto retPc = transform_range_limit< RL >( pcLimit );

  auto boundStr = deduce_bound_str< RL >( opkindBound );

  if (boundStr.empty()) {
    return retPc;
  } else {
    vec_own_piece_t adds;
    adds.push_back( std::move(retPc) );
    adds.push_back( make_num(std::stoi(boundStr)) );
    
    return make_token< kind::addends >( std::move(adds) );
  }
}

template own_piece_t make_piece_limit<range_limit::min>( cloopvar_t loopVar );
template own_piece_t make_piece_limit<range_limit::max>( cloopvar_t loopVar );



} // namespace bld::src::pc


#include "source/token/multiple/binop.hpp"

#include "source/token/make/copy.hpp"

#include "source/token/multiple/compare_ops.hpp"


#ifndef PARSER_TEST
  #include "source/token/combine/test_on_local_contexts.hpp"
  #include "source/object/data/use.hpp"
#endif // PARSER_TEST


namespace bld::src::pc {


///////////////// PC_BINOP  <--- MULTIPLE

token<kind::binop>::token(own_piece_t&& lhs, opkind opk) :
binary(tokens_to_vector(std::move(lhs))),
m_operationKind(opk)
{}


token<kind::binop>::token(vec_own_piece_t&& f, opkind opk) :
binary(std::move(f)),
m_operationKind(opk)
{}

token<kind::binop>::token(const token<kind::binop>& other) :
binary(other),
m_operationKind(other.get_opkind())
{}

// token<kind::binop>::token(cpiece_t lhsPiece, cpiece_t rhsPiece, opkind opk) :
// binary(edit_piece(lhsPiece), edit_piece(rhsPiece)),
// m_operationKind(opk)
// {}


kind token<kind::binop>::get_kind() const { return kind::binop; }

bool token<kind::binop>::is_arith() const {
  return false;
}


std::string token<kind::binop>::get_pc_string() const {
  std::string rhsStr = (this->has_rhs() ? this->get_rhs()->get_pc_string() : "no-rhs");
  return get_lhs()->get_pc_string() + " " + util::enum_convert<opkind>::to_string_rt(m_operationKind)  + " " + rhsStr;
}


void token<kind::binop>::set_opkind(opkind opk) {
  m_operationKind = opk;
}

opkind token<kind::binop>::get_opkind() const {
  return m_operationKind;
}

bool token<kind::binop>::has_rhs() const {
  return binary::has_token<1>();
}

cpiece_t token<kind::binop>::get_lhs() const {
  return binary::get_token<0>();
}

cpiece_t token<kind::binop>::get_rhs() const {
  return binary::get_token<1>();
}

bool token<kind::binop>::is_compare() const {
  return
    m_operationKind == opkind::eq or
    m_operationKind == opkind::neq or
    m_operationKind == opkind::lt or
    m_operationKind == opkind::leq or
    m_operationKind == opkind::gt or
    m_operationKind == opkind::geq;
}

bool token<kind::binop>::is_write() const {
  return not this->is_compare() and m_operationKind != opkind::undefined;
}


res token<kind::binop>::evaluate() const {

  if (not this->is_compare()) {
    throw std::logic_error("Cannot compare a not-compare binary operation");
  }

  if (this->is_rt()) {
    // At least one piece depends on a runtime parameter
    return res::unk;
  }

#ifndef PARSER_TEST
  return test_on_multiple_local_contexts< res >( this->get_lhs(), this->get_rhs(),
      res::unk,
      [] (res retVal) {
        if (retVal != res::unk) {
          return true; // early exit on the first 'not res::unk' case.
        }
        return false;
      },
      std::bind( try_pipeline, std::placeholders::_1, std::placeholders::_2, m_operationKind )
    );
    

#else // PARSER_TEST
  return try_pipeline( this->get_lhs(), this->get_rhs(), m_operationKind );
#endif // PARSER_TEST
}

#ifndef PARSER_TEST
// private
void token<kind::binop>::assert_hold_use(cso_t<obj::data_use> dUse) const {

  bool inLHS = this->get_lhs()->find_data_use(dUse);
  bool inRHS = false;

  if (not inLHS and this->has_rhs()) {
    inRHS = this->get_rhs()->find_data_use(dUse);
  }
  if ((not inLHS) and (not inRHS)) {
    throw std::logic_error("Data use not contained in kind::binop");
  }
}

access_kind token<kind::binop>::get_use_access(cso_t<obj::data_use> dUse) const {

  this->assert_hold_use(dUse);

  // Here we are sure that dUse has a terminal whose parent is (this) kind::binop, so we can directly infer the access_kind in the following

  if (this->is_compare()) {

    // Compare operations read only any use
    return access_kind::read_only;

  } else if (this->is_write()) {

    if (not dUse->get_terminal()->is_direct_operator_argument()) {
      // If not direct, does not matter if it is in lhs or rhs -> read_only
      return access_kind::read_only;
    }

    if (this->get_lhs()->find_data_use(dUse)) {


      // Is write and a direct LHS argument
    
      if (m_operationKind == opkind::assign) {

        return access_kind::write_only;

      } else if (m_operationKind == opkind::init) {

        return access_kind::init;

      } else if (m_operationKind == opkind::init_default) {

        return access_kind::init_default;

      } else if (m_operationKind == opkind::incr or m_operationKind == opkind::decr) {

        return access_kind::read_write;
      } 
    } else {
      // Is write and a direct RHS argument
      return access_kind::read_only;
    }
  }


  throw std::logic_error("Unreachable, cannot get use access of data_use in pc_binop : " + dUse->get_identifier() + ". Binop : " + get_lhs()->get_pc_string() + " --- " + get_rhs()->get_pc_string());
  // return access_kind::undefined;
}

#endif // PARSER_TEST


} // namespace bld::src::pc

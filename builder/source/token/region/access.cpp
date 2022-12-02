
#include "source/token/region/access.hpp"

#include "source/token/make/copy.hpp"

#include "source/token/transform/range.hpp"

#ifndef PARSER_TEST
#include "source/object/data/use.hpp"
#include "source/object/data/decl.hpp"
#include "source/object/data/transform/interface.hpp"
#endif // PARSER_TEST

namespace bld::src::pc {

own_piece_t identity(cpiece_t pc) {
  return edit_piece(pc);
}


access::access( cpiece_t origPc, cso_t<obj::data_use> dUse ) :
m_originalPc( edit_piece(origPc) )
#ifndef PARSER_TEST
,m_dUseRoot(dUse)
#endif // PARSER_TEST
{}

access::access(const access& other) :
m_originalPc(edit_piece(other.get_original()))
#ifndef PARSER_TEST
,m_dUseRoot(other.m_dUseRoot)
#else // PARSER_TEST
,m_downstreamGuard(other.m_downstreamGuard)
#endif
{}


access::~access() {}

cpiece_t access::get_original() const {
  return m_originalPc.get();
}

mem_expr_trans
access::get_mem_expr_transformation() const {
#ifndef PARSER_TEST
  if (is_statically_defined( this->get_original() )) {
    return mem_expr_trans::stat;
  } else {
    return mem_expr_trans::dyn;
  }
#else
  return mem_expr_trans::stat;
#endif // PARSER_TEST
}


// TODO
// own_cpiece_t<kind::range> access::get_original_range() const {
//   if (this->get_mem_expr_transformation == mem_expr_trans::dyn) {
//     throw std::logic_error("Cannot access::get_range : pc not statically transformable");
//   }
// 
//   return transform_to_range( this->get_original() );
// }


#ifndef PARSER_TEST


std::string access::get_info() const {

  if (this->get_root_data_use() != nullptr) {
    return "\tRoot data use : " + this->get_root_data_use()->get_identifier() + '\n';
  }
  return "";
}

cso_t<obj::data_use> access::get_root_data_use() const {
  return m_dUseRoot;
}

void access::set_root_data_use( cso_t<obj::data_use> dUseRoot) {
  m_dUseRoot = dUseRoot;
}

const guard * access::get_downstream_guard() const {
  auto dUseRoot = this->get_root_data_use();
  if (dUseRoot->is_direct_call_argument() and dUseRoot->on_callee_address()) {
    return dUseRoot->get_callee_data_decl()->get_guard();
  }
  return nullptr;
}

piece_context access::get_local_context() const {
  return m_dUseRoot->get_local_context();
}

piece_context access::get_highest_local_context() const {
  return this->get_root_data_use()->get_root_data_decl()->get_local_context();
}


bool access::is_task_ref_argument() const {
  return this->get_root_data_use()->is_task_ref_argument();
}


bool access::is_on_call_within_loop() const {
  return this->get_root_data_use()->is_direct_call_argument_within_loop();
}


#else // PARSER_TEST enabled


std::string access::get_info() const {
  return "";
}

const guard * access::get_downstream_guard() const {
  return m_downstreamGuard;
}

void access::set_downstream_guard(const guard * dsGuard) {
  m_downstreamGuard = dsGuard;
}

piece_context access::get_local_context() const {
  return UniversalCtxt;
}

piece_context access::get_highest_local_context() const {
  return UniversalCtxt;
}

bool access::is_task_ref_argument() const {
  return false;
}


#endif // PARSER_TEST


} // namespace bld::src::pc


#include "source/token/region/guard.hpp"
#include "source/token/make/copy.hpp"

#ifndef PARSER_TEST

  #include "source/object/data/transform/interface.hpp" // transform_to_local_context
  #include "source/object/data/decl.hpp"
#endif // PARSER_TEST

namespace bld::src::pc {

own_piece_t identity(cpiece_t);

guard::guard( cso_t<obj::data_decl> dDecl )
#ifndef PARSER_TEST
:
m_dDeclRoot(dDecl)
#endif // PARSER_TEST
{}

guard::~guard() {}




#ifdef PARSER_TEST

piece_context guard::get_local_context() const {
  return UniversalCtxt;
}

// source_context guard::get_highest_local_context() const {
//   return UniversalCtxt;
// }

#else 

piece_context guard::get_local_context() const {
  if (m_dDeclRoot == nullptr) {
    throw std::logic_error("Cannot guard::get_local_context : dDecl is nullptr");
  }
  return m_dDeclRoot->get_local_context();
}

// piece_context access::get_highest_local_context() const {
//   return m_dDeclRoot->get_local_context();
// }


#endif // PARSER_TEST

} // namespace bld::src::pc

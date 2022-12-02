#ifndef STEEL_COMPILER_ELEMENT_SOURCE_HPP
#define STEEL_COMPILER_ELEMENT_SOURCE_HPP

#include "source/sequences.hpp"

#include "source/object/typedef.hpp"

#include "options/enum.hpp" // Used by derivation declarations

#include "files/interface.hpp"

#include <array>


namespace clang {
  class SourceManager;
  class ASTContext;
  class SourceRange;
  class Decl;
  class ValueDecl;
  class VarDecl;
  class ParmVarDecl;
  class ForStmt;
  class DeclStmt;
  class ArraySubscriptExpr;
  class DeclRefExpr;
  class ImplicitCastExpr;
  class CompoundStmt;
  class BinaryOperator;
  class UnaryOperator;
  class Expr;

  class IntegerLiteral;
  class FixedPointLiteral;
  class FloatingLiteral;
  class ImaginaryLiteral;
  class CharacterLiteral;
  class StringLiteral;
  class CXXBoolLiteralExpr;
  class CXXNullPtrLiteralExpr;
} // namespace clang


namespace bld::src {

bool is_castable_to_literal(const clang::Expr * litExpr);

std::string set_literal_data(const clang::Expr * litExpr, const clang::ASTContext& astCtxt);

std::string get_name_as_string(const clang::VarDecl * vd);


std::pair<std::string, std::string>
get_sides_of_decl_stmt(const clang::DeclStmt * cPtr, const clang::ASTContext & ctxt);



class sobject_base {
private:

  const object_id_t m_identifier;

  state::filename m_filename;

  enum class pos : unsigned {line=0, column=1};

  u_pair_t m_begin;
  u_pair_t m_end;


protected:

  std::string m_data;

private:

  void set_source_filename();


public:

  state::filename get_source_filename() const;


  // Constructor to build source src-objects from user code
  template <typename ClangT>
  sobject_base(const ClangT * cPtr, const clang::SourceManager& sm, const clang::ASTContext & ctxtPtr);

  sobject_base(const clang::SourceRange& sr, const clang::SourceManager& sm, const clang::ASTContext & ctxt);

  // Deserialization constructor
  sobject_base( const std::string& serialStr, const serial_map_t& serialMap );

  virtual ~sobject_base() = 0;

  virtual obj get_obj() const = 0;

  virtual void print(std::ostream& os) const;

  virtual std::string serial() const;

  bool is_synthetic() const;

  template <typename ClangT>
  static object_id_t build_id(const ClangT * cPtr, const clang::SourceManager& sm, const clang::ASTContext& ctxt);

  const object_id_t& get_identifier() const;

  const std::string& get_data() const;
  // void set_data(const std::string d);

  bool contains(const sobject_base * srcLoc) const;

  bool is_before(const sobject_base * srcLoc) const;

  std::string get_info() const;


};



template <obj Obj>
bool compare_own_source_objects<Obj>::operator() (const own_so_t<Obj>& lhs, const own_so_t<Obj>& rhs) const {
  if (lhs.get() == nullptr) { throw std::logic_error("Could not compare source objects. Lhs is nullptr"); }
  if (rhs.get() == nullptr) { throw std::logic_error("Could not compare source objects. Rhs is nullptr"); }
  return lhs->get_identifier() < rhs->get_identifier();
}

} // namespace bld::src


std::ostream& operator<<(std::ostream& ofs, const bld::src::sobject_base& elem);

#endif // STEEL_COMPILER_ELEMENT_SOURCE_HPP

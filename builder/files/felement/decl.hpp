#ifndef STEEL_COMPILER_FELEMENT_DECL_HPP
#define STEEL_COMPILER_FELEMENT_DECL_HPP

#include "files/traits/code.hpp"

#include "files/traits/extension.hpp"

#include "files/felement/decl.hpp"

#include "files/name/decl.hpp"

namespace bld {

template <file_kind FK, code CodK>
class felement;


template <file_kind FK>
struct ftraits;


template <code CodK>
class felement<file_kind::undefined, CodK> : public undefined_file {};

template <file_kind FK, code CodK>
using derived_super_type =
  std::conditional_t<
    not ftraits<FK>::base_type_overridable || not ctraits<CodK>::base_type_overrides,
    typename ftraits<FK>::base_type,
    typename ctraits<CodK>::base_type
  >;

template <file_kind FK, code CodK>
class felement : public derived_super_type<FK, CodK> {

  using super_type = derived_super_type<FK, CodK>;

  using top_super_type = base_felement;

public:
  static constexpr file_kind this_file_kind = FK;
  static constexpr code this_code = CodK;

 

public:
  using yield_type = std::conditional_t<
      ftraits<FK>::yield != file_kind::undefined,
      felement< ftraits<FK>::yield, CodK>,
      felement< ctraits<CodK>::yield, CodK>
    >;
  using yield_ptr_type = std::add_pointer_t<yield_type>;



private:

  yield_ptr_type m_yieldPtr = nullptr;


public: // non-static
  felement(const state::filename& fn);
  felement(const state::filename& fn, std::filesystem::file_time_type ftt);


  void set_yield(yield_ptr_type yPtr);

  bool has_yield() const;

  const yield_ptr_type get_yield() const;

  yield_ptr_type get_yield();

  const top_super_type * get_poly_yield() const final override;

};


} // namespace bld

// template <bld::file_kind FK, bld::code CodK>
// std::ostream& operator<<(std::ostream& ofs, const bld::felement<FK, CodK>& elem) {
//   ofs << elem.get_identifier() << " as " << FK << ", " << CodK;
//   return ofs;
// }


#endif // STEEL_COMPILER_FELEMENT_DECL_HPP

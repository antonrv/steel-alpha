#ifndef SOURCE_STATE_DECL_HPP
#define SOURCE_STATE_DECL_HPP

#include "source/object/base.hpp"

namespace bld::src {

template <obj Obj>
class state {
protected:

  using own_set_t = set_own_so_t<Obj>;

  using iter_t = typename own_set_t::iterator;

  static own_set_t s_owned;

public:

  // Make new
  template <typename... ArgTs>
  static
  so_t<Obj> make(ArgTs&&... args); // make (make)


  // Retrieve existing
  template <typename... ArgTs>
  static bool exists(ArgTs&&... args);

  static set_cso_t<Obj> get_all();
  static set_so_t<Obj> edit_all();

  template <typename... ArgTs>
  static iter_t get_found_iterator(ArgTs&&... args);

  template <typename... ArgTs>
  static cso_t<Obj> get(ArgTs&&... args); // prev find

  template <typename... ArgTs>
  static so_t<Obj> edit(ArgTs&&... args); // prev find

  //////// Containment relation
  // Single
  static cso_t<Obj> get_containing(csob_t base);
  static so_t<Obj> edit_containing(csob_t base);

  static cso_t<Obj> get_contained_by(csob_t base);
  static so_t<Obj> edit_contained_by(csob_t base);

  // All
  static set_cso_t<Obj> get_all_containing(csob_t base);
  static set_so_t<Obj> edit_all_containing(csob_t base);

  static set_cso_t<Obj> get_all_contained_by(csob_t base);
  static set_so_t<Obj> edit_all_contained_by(csob_t base);

  static cso_t<Obj> get_innermost_of(csob_t srcObj);
  // static so_t<Obj> edit_innermost_of(csob_t srcObj);

  //////// Satisfaction relation
  // Single
  template <typename PredT>
  static bool exist_satisfying(PredT&& pred);
  template <typename PredT>
  static cso_t<Obj> get_satisfying(PredT&& pred);
  template <typename PredT>
  static so_t<Obj> edit_satisfying(PredT&& pred);

  // All
  template <typename PredT>
  static set_cso_t<Obj> get_all_satisfying(PredT&& pred);
  template <typename PredT>
  static set_so_t<Obj> edit_all_satisfying(PredT&& pred);

  // static void print();
};


} // namespace bld::src

#endif // SOURCE_STATE_DECL_HPP

#ifndef SOURCE_STATE_DEF_HPP
#define SOURCE_STATE_DEF_HPP


#include "options/state/log.hpp"

#include "source/object/state/set.hpp"

#include "source/object/state/decl.hpp"

#include "common/util.hpp"

#include <iostream>

namespace nms_state = bld::state;

namespace bld::src {


template <obj Obj>
typename state<Obj>::own_set_t state<Obj>::s_owned = state<Obj>::own_set_t();


template <obj Obj>
template <typename... ArgTs>
so_t<Obj>
state<Obj>::make(ArgTs&&... args) {

  auto [insertIt, wasInserted] = s_owned.emplace( std::make_unique< sobject<Obj> >(std::forward<ArgTs>(args)...) );

  if (wasInserted) {
    nms_state::log_if< sobject<Obj>::log_record >( "first", *(*insertIt) ); // Instantiate << op of sobject_base
  }

  return insertIt->get();
}


template <obj Obj>
template <typename... ArgTs>
typename state<Obj>::iter_t
state<Obj>::get_found_iterator(ArgTs&&... args) {

  auto id = sobject_base::build_id(args...);

  return std::find_if(std::begin(s_owned), std::end(s_owned),
      [id](const own_so_t<Obj>& srcObj){
        return srcObj->get_identifier() == id;
      }
    );
}

template <obj Obj>
template <typename... ArgTs>
bool
state<Obj>::exists(ArgTs&&... args) {

  return get_found_iterator( std::forward<ArgTs>(args)... ) != std::end(s_owned);
}

template <obj Obj>
template <typename... ArgTs>
cso_t<Obj>
state<Obj>::get(ArgTs&&... args) {

  auto errId = sobject_base::build_id(args...);

  auto foundIter = get_found_iterator( std::forward<ArgTs>(args)... );

  if (foundIter != std::end(s_owned)) {
    return static_cast<cso_t<Obj>>(foundIter->get());
  } else {
    throw std::logic_error("Could not get sobject. Not existing : " + errId);
  }
}

template <obj Obj>
template <typename... ArgTs>
so_t<Obj>
state<Obj>::edit(ArgTs&&... args) {

  auto errId = sobject_base::build_id(args...);

  auto foundIter = get_found_iterator( std::forward<ArgTs>(args)... );

  if (foundIter != std::end(s_owned)) {
    return static_cast<so_t<Obj>>(foundIter->get());
  } else {
    throw std::logic_error("Could not edit sobject. Not existing : " + errId);
  }
}


// GET/EDIT CONTAINING

template <obj Obj>
cso_t<Obj>
state<Obj>::get_containing(csob_t srcObj) {

  return get_satisfying( [srcObj] (const own_so_t<Obj>& own) { return own->contains( srcObj ); } );
}

template <obj Obj>
so_t<Obj>
state<Obj>::edit_containing(csob_t srcObj) {

  return edit_satisfying( [srcObj] (const own_so_t<Obj>& own) { return own->contains( srcObj ); } );
}


// GET/EDIT CONTAINED_BY
template <obj Obj>
cso_t<Obj>
state<Obj>::get_contained_by(csob_t srcObj) {

  return get_satisfying( [srcObj] (const own_so_t<Obj>& own) { return srcObj->contains( own.get() ); } );
}

template <obj Obj>
so_t<Obj>
state<Obj>::edit_contained_by(csob_t srcObj) {

  return edit_satisfying( [srcObj] (const own_so_t<Obj>& own) { return srcObj->contains( own.get() ); } );
}


// GET/EDIT ALL CONTAINING
template <obj Obj>
set_cso_t<Obj>
state<Obj>::get_all_containing(csob_t srcObj) {
  return get_all_satisfying( [srcObj] (const own_so_t<Obj>& own) { return own->contains( srcObj ); } );
}

template <obj Obj>
set_so_t<Obj>
state<Obj>::edit_all_containing(csob_t srcObj) {
  return edit_all_satisfying( [srcObj] (const own_so_t<Obj>& own) { return own->contains( srcObj ); } );
}


// GET/EDIT ALL CONTAINED_BY
template <obj Obj>
set_cso_t<Obj>
state<Obj>::get_all_contained_by(csob_t srcObj) {
  return get_all_satisfying( [srcObj] (const own_so_t<Obj>& own) { return own->contains( srcObj ); } );
}

template <obj Obj>
set_so_t<Obj>
state<Obj>::edit_all_contained_by(csob_t srcObj) {
  return edit_all_satisfying( [srcObj] (const own_so_t<Obj>& own) { return own->contains( srcObj ); } );
}


// GET/EDIT SATISFYING

template <obj Obj>
template <typename PredT>
bool
state<Obj>::exist_satisfying(PredT&& pred) {
  return std::find_if( std::begin(s_owned), std::end(s_owned), pred ) != std::end(s_owned);
}

template <obj Obj>
template <typename PredT>
cso_t<Obj>
state<Obj>::get_satisfying(PredT&& pred) {
  auto foundIter = std::find_if( std::begin(s_owned), std::end(s_owned), pred );
  if (foundIter != std::end(s_owned)) {
    return static_cast<cso_t<Obj>>(foundIter->get());
  }
  return nullptr;
}

template <obj Obj>
template <typename PredT>
so_t<Obj>
state<Obj>::edit_satisfying(PredT&& pred) {
  auto foundIter = std::find_if( std::begin(s_owned), std::end(s_owned), pred );
  if (foundIter != std::end(s_owned)) {
    return static_cast<so_t<Obj>>(foundIter->get());
  }
  return nullptr;
}


template <obj Obj>
template <typename PredT>
set_cso_t<Obj>
state<Obj>::get_all_satisfying(PredT&& pred) {

  set_cso_t<Obj> retSet;

  transform_if(std::begin(s_owned), std::end(s_owned), std::inserter(retSet, std::end(retSet)),
    pred,
    [](const own_so_t<Obj>& uptr) {
      return static_cast<cso_t<Obj>>(uptr.get());
    }
  );

  return retSet;
}

template <obj Obj>
template <typename PredT>
set_so_t<Obj>
state<Obj>::edit_all_satisfying(PredT&& pred) {

  set_so_t<Obj> retSet;

  transform_if(std::begin(s_owned), std::end(s_owned), std::inserter(retSet, std::end(retSet)),
    pred,
    [](const own_so_t<Obj>& uptr) {
      return static_cast<so_t<Obj>>(uptr.get());
    }
  );

  return retSet;
}

// GET/EDIT INNERMOST OF

template <obj Obj>
cso_t<Obj>
state<Obj>::get_innermost_of(csob_t srcObj) {

  auto funCtxtSet = get_all_containing( srcObj );

  if (srcObj->get_obj() == Obj) { funCtxtSet.erase( static_cast<cso_t<Obj>>(srcObj) ); }

  if (not funCtxtSet.empty()) {
    // Since fun contexts are ordered in the order of appearance, we get the last ctxt as the innermost
    return *funCtxtSet.rbegin();
  } else {
    return nullptr;
  }
}


// template <obj Obj>
// so_t<Obj>
// state<Obj>::edit_innermost_of(csob_t srcObj) {
// 
//   auto funCtxtSet = edit_all_containing( srcObj );
// 
//   if (srcObj->get_obj() == Obj) { funCtxtSet.erase( funCtxtSet.find(static_cast<cso_t<Obj>>(srcObj)) ); }
// 
//   if (not funCtxtSet.empty()) {
//     // Since fun contexts are ordered in the order of appearance, we get the last ctxt as the innermost
//     return *funCtxtSet.rbegin();
//   } else {
//     return nullptr;
//   }
// }




// GET/EDIT ALL

template <obj Obj>
set_cso_t<Obj>
state<Obj>::get_all() {

  set_cso_t<Obj> retSet;

  std::transform(std::begin(s_owned), std::end(s_owned),
    std::inserter(retSet, std::end(retSet)),
    [](const own_so_t<Obj>& uptr) {
      return static_cast<cso_t<Obj>>(uptr.get());
    });

  return retSet;
}


template <obj Obj>
set_so_t<Obj>
state<Obj>::edit_all() {

  set_so_t<Obj> retSet;

  std::transform(std::begin(s_owned), std::end(s_owned),
    std::inserter(retSet, std::end(retSet)),
    [](const own_so_t<Obj>& uptr) {
      return static_cast<so_t<Obj>>(uptr.get());
    });

  return retSet;
}


// PRINT

// template <obj Obj>
// void state<Obj>::print() {
//   std::cout << "Printing state of " << Obj << "\n";
//   for (const auto& ptr : s_owned) {
//     if (ptr->get_obj() == Obj) {
//       std::cout << *ptr << '\n';
//     }
//   }
// }


} // namespace bld::src

#endif // SOURCE_STATE_DEF_HPP

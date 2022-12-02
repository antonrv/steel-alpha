#ifndef STEEL_COMPILER_STATE_FILES_DEF_HPP
#define STEEL_COMPILER_STATE_FILES_DEF_HPP


#include "files/state/decl.hpp"

#include "files/traits/interface.hpp"
#include "files/semantic/interface.hpp"

#include "files/felement/compare_def.hpp"


#include "files/felement/decl.hpp"

#include "files/name/decl.hpp"
// #include "files/felement.hpp"

#include "options/state/log.hpp"

#include <filesystem>
#include <iostream>
#include <algorithm>

namespace bld::state {


template <file_kind FK>
typename files<FK>::own_files_t files<FK>::s_owned = files<FK>::own_files_t();

template <file_kind FK>
template <code CodK>
file_t<FK,CodK>
files<FK>::record(filename id) {

  using red_set_t = set_own_file_t<FK,CodK>;

  red_set_t& redSet = files<FK>::template get_owned_files<CodK>();

  // std::cout << "Registering file " << id << " as " << FK << ", " << CodK << '\n';
  auto itPair = redSet.insert( std::make_unique< felement<FK, CodK> >( id ) );

  state::log<opt_kind::log_file_record>("Recorded:", id.get_head(),"-",id.get_tail(),"(",FK,CodK,")");

  return std::get<0>(itPair)->get();
}

template <file_kind FK>
template <code CodK>
file_t<FK,CodK>
files<FK>::get_file_element(const std::string& id) {

  using red_set_t = set_own_file_t<FK,CodK>;
  using own_ptr_t = own_file_t<FK, CodK>;

  red_set_t& redSet = files<FK>::template get_owned_files<CodK>();
  

  auto foundIt = std::find_if(std::begin(redSet), std::end(redSet), [id](const own_ptr_t& ownPtr) { return ownPtr->get_identifier() == id; });
  if (foundIt == std::end(redSet)) {
    throw std::logic_error("Element not found : " + id);
  }

  return foundIt->get();
}


template <file_kind FK>
template <code CodK>
set_file_t<FK, CodK>
files<FK>::get_raw() {
  const auto& ownElems = files<FK>::template get_owned_files<CodK>();
  using own_ptr_t = own_file_t<FK, CodK>;

  set_file_t<FK, CodK> rawElems;
  std::transform(std::begin(ownElems), std::end(ownElems),
      std::inserter(rawElems, std::end(rawElems)),
      [](const own_ptr_t& uPtr) { return uPtr.get(); }
    );

  return rawElems;
}


// Private because it returns owned objects. 
template <file_kind FK>
template <code CodK>
set_own_file_t<FK,CodK> &
files<FK>::get_owned_files() {
  using own_set_t = set_own_file_t<FK,CodK>;
  return std::get<own_set_t>( s_owned );
}

// template <file_kind FK>
// template <code CodK>
// const set_own_file_t<FK,CodK> &
// files<FK>::get_owned_files() {
//   using own_set_t = set_own_file_t<FK,CodK>;
//   return std::get<own_set_t>( s_owned );
// }


template <file_kind FK>
void files<FK>::record_filename(filename fn) {
  auto fnExt = std::filesystem::path(fn.get_full_name()).extension();
  code codeKind = source_extension_to_code(fnExt); // Defined in file traits
  if (codeKind == code::interface) {
    files<FK>::record<code::interface>(fn);
  } else if (codeKind == code::implementation) {
    files<FK>::record<code::implementation>(fn);
  } else if (codeKind == code::entry) {
    files<FK>::record<code::entry>(fn);
  } else {
    // std::cout << "Not registered " << fn.get_tail() << " : could not identify code kind\n";
  }
}

template <file_kind FK>
void files<FK>::print_elements() {
  std::cout << "Printing files TODO" << FK << '\n';
  // std::cout << "\t" << code::interface << '\n';
  // print(std::get<owned_element_set_t<felement<FK, code::interface>>>(s_owned));
  // std::cout << "\t" << code::implementation << '\n';
  // print(std::get<owned_element_set_t<felement<FK, code::implementation>>>(s_owned));
  // std::cout << "\t" << code::entry << '\n';
  // print(std::get<owned_element_set_t<felement<FK, code::entry>>>(s_owned));
}


template <file_kind FK>
template <code CodK>
cfile_t<FK,CodK>
files<FK>::find_file(const std::string& id) {

  set_own_file_t<FK,CodK>& ownedRef = std::get<set_own_file_t<FK,CodK>>(s_owned);

  auto foundIter = std::find_if(std::begin(ownedRef), std::end(ownedRef),[id](const auto& elemPtr){return elemPtr->get_identifier() == id;} );
  if (foundIter != std::end(ownedRef)) {
    return foundIter->get();
  }
  return nullptr;
}

template <file_kind FK>
cfileb_t files<FK>::get_poly_file(const std::string& id) {

  auto foundInterface = files<FK>::find_file<code::interface>( id );
  auto foundImplementation = files<FK>::find_file<code::implementation>( id );
  auto foundEntry = files<FK>::find_file<code::entry>( id );

  if ((foundInterface != nullptr and (foundImplementation != nullptr or foundEntry != nullptr)) or
      (foundImplementation != nullptr and (foundInterface != nullptr or foundEntry != nullptr))) {

    throw std::runtime_error("Could not get_poly_file : " + id + ". Multiple found with different codes");
  }
  if (foundInterface == nullptr and foundImplementation == nullptr and foundEntry == nullptr) {
    throw std::runtime_error("Could not get_poly_file : " + id + ". Not found");
  }

  if (foundInterface != nullptr) { return foundInterface; }
  else if (foundImplementation != nullptr) { return foundImplementation; }
  else { return foundEntry; }

}

template <file_kind FK>
set_cfileb_t files<FK>::get_all_files() {

  set_cfileb_t retSet;

  auto intf = files<FK>::get_raw<code::interface>();
  std::copy(std::begin(intf), std::end(intf), std::inserter(retSet, std::end(retSet)));
  auto impl = files<FK>::get_raw<code::implementation>();
  std::copy(std::begin(impl), std::end(impl), std::inserter(retSet, std::end(retSet)));
  auto entr = files<FK>::get_raw<code::entry>();
  std::copy(std::begin(entr), std::end(entr), std::inserter(retSet, std::end(retSet)));

  return retSet;
}

// template <file_kind FK>
// cfileb_t
// files<FK>::find(const std::string& id) {
// 
//   if (auto fPtr = find_file<code::interface>(id)) {
//     return fPtr;
//   } else if (auto fPtr = find_file<code::implementation>(id)) {
//     return fPtr;
//   } else if (auto fPtr = find_file<code::entry>(id)) {
//     return fPtr;
//   } else {
//     return nullptr;
//   }
// }

} // namespace bld::state

#endif // STEEL_COMPILER_STATE_FILES_DEF_HPP

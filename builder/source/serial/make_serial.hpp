#ifndef SOURCE_OBJECT_STATE_SERIAL_INTERFACE_HPP
#define SOURCE_OBJECT_STATE_SERIAL_INTERFACE_HPP

#include "common/typedef.hpp"

#include "common/util.hpp"

#include "source/object/typedef.hpp"

#include "source/serial/serialize_decl.hpp"

#include "source/serial/is_serializable.hpp"
#include "source/serial/indent.hpp"

// #include <iostream> // DBG XXX

namespace bld::src {



template <typename FieldT> struct clean { using type = std::remove_const_t<std::remove_pointer_t<std::remove_reference_t<std::remove_cv_t<std::remove_reference_t<FieldT>>>>>; };
template <typename FieldT> using clean_t = typename clean<FieldT>::type;

////// Lower unique -> raw ptr if unique
template < typename FieldT,
  req_t<
    is_unique_ptr< clean_t<FieldT> >
  >...
  >
auto lower_own_ptr( FieldT&& own ) {
  return own.get();
}

////// Forward type if it is not unique
template < typename FieldT,
  req_t<
    std::negation< is_unique_ptr< clean_t<FieldT> > >
  >...
>
auto lower_own_ptr( FieldT&& ptr ) {
  return std::forward<FieldT>( ptr );
}

////// Use ::serial internal method if ClassT has it
template <
  typename PtrT,
  req_t<
    std::conjunction<
      std::is_pointer< PtrT >,
      is_serializable< std::remove_pointer_t<PtrT>, std::string()>
    >
  > ...
>
std::string fwd_serial_fun( PtrT ptr ) {
  if (ptr == nullptr) {
    return "NULL";
  }
  return ptr->serial();
}

////// Use builtin enum -> string conversion if it is an enumeration
template <
  typename EnumT,
  req_t< std::is_enum<EnumT> > ...
>
std::string fwd_serial_fun( EnumT val ) {
  return util::enum_convert< EnumT >::to_string_rt( val );
}


template <typename FieldT>
std::string serialize_single( const std::string& keyField, FieldT&& field);

////// Use container (vector,set) -> string conversion if it is a container
template <
  typename ContT,
  req_t< is_container<ContT> > ...
>
std::string fwd_serial_fun( const ContT& inCont ) {

  std::string retStr;

  unsigned elemPos = 0;

  retStr = string_from_container( inCont,
    [&elemPos] (const typename ContT::value_type& elem) {
      return serialize_single(std::to_string(elemPos++) + ":", elem);
    }
  );

  return retStr + indent_raii::get_nl_ind_str();
}


////// Do not use ::serial internal method if ClassT does not have it. Instead, forward to custom serialize< ClassT >::serial declared in header
template <
  typename ValT,
  req_t<
    std::conjunction<
      std::negation< std::is_pointer< ValT > >,
      std::negation< is_serializable<ValT, std::string()> >,
      std::negation< is_container<ValT> >,
      std::negation< std::is_enum<ValT> >
    >
  > ...
>
std::string fwd_serial_fun( ValT&& val ) {
  return serialize< clean_t<ValT> >::serial( std::forward<ValT>(val) );
}

static inline
void verify_key_format(const std::string& keyStr) {
  if (not keyStr.empty()) {
    if (keyStr.back() != ':') {
      throw std::logic_error("Could not serialize.. Expected ':' at the end of every key field : " + keyStr);
    }
  } else {
    // Can be empty when we are serializing vector elements
  }
}


//////// Serialize a single field
template <typename FieldT>
std::string serialize_single( const std::string& keyField, FieldT&& field) {

  verify_key_format(keyField);

  indent_raii indRaii;

  return indent_raii::get_nl_ind_str() + keyField + '[' + fwd_serial_fun( lower_own_ptr( std::forward<FieldT>(field) ) ) + "];";
}


//////// Serialize all with fold expression
template <unsigned N, typename... Fields, std::size_t... Ids>
static
std::string serialize_all( const arr_str_t<N>& keyFields,  std::index_sequence<Ids...>, Fields&&... fields ) {
  return ( serialize_single( std::get<Ids>(keyFields), std::forward< Fields >(fields) ) + ... ) + indent_raii::get_nl_ind_str();
}




///////////////
//
// INTERFACE
//
///////////////
// Called from objects ::serial methods
template <unsigned N, typename... Fields>
std::string make_serial( arr_str_t<N> keyFields, Fields&&... fields) {

  // CHECK : Make sure there are as many key fields as arguments
  if (N != sizeof...(Fields)) {
    throw std::logic_error("Could not serialize : # of key fields and # argument fields not matching");
  }

  // CHECK : Make sure no duplicates in keyfields:
  {
    auto tmpKeyFields = keyFields;
    std::sort(std::begin(tmpKeyFields), std::end(tmpKeyFields));
    if (std::adjacent_find( std::begin(tmpKeyFields), std::end(tmpKeyFields), std::equal_to<>()) != std::end(tmpKeyFields) ) {
      throw std::logic_error("Could not serializ. key fields must be unique"); 
    }
  }

  using idx_seq = std::make_index_sequence<N>;

  return serialize_all<N>( keyFields, idx_seq{}, std::forward<Fields>(fields) ... );
}


} // namespace bld::src

#endif // SOURCE_OBJECT_STATE_SERIAL_INTERFACE_HPP

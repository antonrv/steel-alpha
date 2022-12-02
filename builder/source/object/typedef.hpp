#ifndef COMMON_IT_SOURCE_DECL_HPP
#define COMMON_IT_SOURCE_DECL_HPP

#include "source/sequences.hpp"

#include "source/token/typedef.hpp"

#include <array>
#include <set>
#include <vector>
#include <map>
#include <memory>


namespace bld::src {

class sobject_base;

class task;

template <obj>
class sobject;

// Base

using object_id_t = std::string;
using u_pair_t = std::array<unsigned, 2>;

template <unsigned N>
using arr_str_t = std::array<std::string, N>;

using serial_map_t = std::map<object_id_t, std::string>;

using sob_t = std::add_pointer_t<sobject_base>;
using csob_t = std::add_pointer_t<std::add_const_t<sobject_base>>;

// Not needed in principle
// using own_sob_t = std::unique_ptr<sobject_base>;
// using own_csob_t = std::unique_ptr<std::add_const_t<sobject_base>>;

// Derived specializations

template <obj Obj>
using so_t = std::add_pointer_t<sobject<Obj>>;

template <obj Obj>
using cso_t = std::add_pointer_t<std::add_const_t<sobject<Obj>>>;

template <obj Obj>
using own_so_t = std::unique_ptr<sobject<Obj>>;

template <obj Obj>
using own_cso_t = std::unique_ptr<std::add_const_t<sobject<Obj>>>;


//////////// Sets


struct compare_base_source_objects {
  bool operator() (csob_t lhs, csob_t rhs) const;
};

using set_csob_t = std::set<csob_t, compare_base_source_objects>;

template <obj Obj>
struct compare_source_objects {
  bool operator() (cso_t<Obj> lhs, cso_t<Obj> rhs) const;
};

template <obj Obj>
using set_so_t = std::set<so_t<Obj>, compare_base_source_objects>;

template <obj Obj>
using set_cso_t = std::set<cso_t<Obj>, compare_base_source_objects>;

// template <obj Obj>
// using set_so_t = std::set<so_t<Obj>, compare_source_objects<Obj>>;
// 
// template <obj Obj>
// using set_cso_t = std::set<cso_t<Obj>, compare_source_objects<Obj>>;


template <obj Obj>
struct compare_own_source_objects {
  bool operator() (const own_so_t<Obj>& lhs, const own_so_t<Obj>& rhs) const;
};

template <obj Obj>
using set_own_so_t = std::set<own_so_t<Obj>, compare_own_source_objects<Obj>>;

using task_t = std::add_pointer_t<task>;
using ctask_t = std::add_pointer_t<std::add_const_t<task>>;
using own_task_t = std::unique_ptr<task>;
using vec_ctask_t = std::vector<ctask_t>;



} // namespace bld::src

#endif // COMMON_IT_SOURCE_DECL_HPP

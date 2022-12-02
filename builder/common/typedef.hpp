#ifndef COMMON_TYPEDEFS_HPP
#define COMMON_TYPEDEFS_HPP


#include <type_traits>
#include <memory>
#include <vector>
#include <set>

namespace bld::src {


///// Aux types to build generic interfaces for edit_piece, const_piece, simplify_piece
enum class enabler_t {};

template <typename T>
using req_t = std::enable_if_t<T::value, enabler_t>;

template <class T> struct is_unique_ptr : std::false_type {};
template <class T, class D> struct is_unique_ptr<std::unique_ptr<T, D>> : std::true_type {};

template <class T> struct is_container : std::false_type {};
template <class T, class A> struct is_container<std::vector<T, A>> : std::true_type {};
template <class T, class C, class A> struct is_container<std::set<T, C, A>> : std::true_type {};


} // namespace bld::src

namespace bld {

using vec_bool_t = std::vector<bool>;

} // namespace bld

#endif // COMMON_TYPEDEFS_HPP

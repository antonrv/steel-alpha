#ifndef STEEL_COMPILER_COMMON_INJECT_SYNTAX_HPP
#define STEEL_COMPILER_COMMON_INJECT_SYNTAX_HPP


// #include <sstream>
// #include <type_traits>
#include <utility>
#include <iostream>

namespace bld::syn {

enum class ik : std::size_t;

template <ik IK>
class injection;


// Derived types

template <typename T>
class paren : public T {
public:
  explicit paren(T&& in) : T(std::move(in)) {}
};

template <typename T>
class sq_bracket : public T {
public:
  explicit sq_bracket(T&& in) : T(std::move(in)) {}
};



template <typename T>
class constref : public T {
public:
  explicit constref(T&& in) : T(std::move(in)) {}
};

template <typename T>
class nonconstref : public T {
public:
  explicit nonconstref(T&& in) : T(std::move(in)) {}
};

template <typename T>
class stmt : public T {
public:
  explicit stmt(T&& in) : T(std::move(in)) {}
};

template <typename T>
class coyield : public T {
public:
  explicit coyield(T&& in) : T(std::move(in)) {}
};

template <typename T>
class nms_cmp : public T {
public:
  nms_cmp(T&& in) : T(std::move(in)) {}
};

template <typename T>
class nms_rt : public T {
public:
  explicit nms_rt(T&& in) : T(std::move(in)) {}
};

template <typename T>
class nms_usr : public T {
public:
  explicit nms_usr(T&& in) : T(std::move(in)) {}
};

template <typename T>
class enum_kernel : public T {
public:
  explicit enum_kernel(T&& in) : T(std::move(in)) {}
};

template <typename T>
class move : public T {
public:
  explicit move(T&& in) : T(std::move(in)) {}
};

template <typename T>
class declt : public T {
public:
  explicit declt(T&& in) : T(std::move(in)) {}
};

template <typename T>
class sequence {
  const T m_seqRef;  
public:
  explicit sequence(const T& inSeq) : m_seqRef(inSeq) {}
  explicit sequence(sequence&&) = default;

  const T& inner() const { return m_seqRef; }
};

template <typename T>
class stmt_sequence {
  const T m_seqRef;  
public:
  explicit stmt_sequence(const T& inSeq) : m_seqRef(inSeq) {}
  explicit stmt_sequence(stmt_sequence&&) = default;

  const T& inner() const { return m_seqRef; }
};

template <typename T>
class ptr_sequence {
  const T m_seqRef;  
public:
  explicit ptr_sequence(const T& inSeq) : m_seqRef(inSeq) {}
  explicit ptr_sequence(ptr_sequence&&) = default;

  const T& inner() const { return m_seqRef; }
};

template <typename T1, typename T2>
class type_var : public T1, public T2 {
public:
  explicit type_var(T1&& in1, T2&& in2) : T1(std::move(in1)), T2(std::move(in2)) {}
};

template <typename T1, typename T2>
class pair : public T1, public T2 {
public:
  explicit pair(T1&& in1, T2&& in2) : T1(std::move(in1)), T2(std::move(in2)) {}
};

template <typename T1, typename T2>
class assign : public T1, public T2 {
public:
  explicit assign(T1&& in1, T2&& in2) : T1(std::move(in1)), T2(std::move(in2)) {}
};

template <typename... Ts>
class cat : public Ts... {
public:
  explicit cat(Ts&&... args) : Ts(std::move(args))... {}
  explicit cat(cat&&) = default;
};


///////////// NEW RT. Many things above to be deprecated

template <typename T>
class bracket : public T {
public:
  explicit bracket(T&& in) : T(std::move(in)) {}
};

template <typename T>
class curl_bracket : public T {
public:
  explicit curl_bracket(T&& in) : T(std::move(in)) {}
};

template <typename T>
class cm_string : public T {
public:
  explicit cm_string(T&& in) : T(std::move(in)) {}
};

template <typename T1, typename T2>
class assignop : public T1, public T2 {
public:
  explicit assignop(T1&& in1, T2&& in2) : T1(std::move(in1)), T2(std::move(in2)) {}
};

template <typename T>
class auto_kw : public T {
public:
  explicit auto_kw(T&& in) : T(std::move(in)) {}
};

template <typename T>
class coawait : public T {
public:
  explicit coawait(T&& in) : T(std::move(in)) {}
};

template <typename T>
class makeasync : public T {
public:
  explicit makeasync(T&& in) : T(std::move(in)) {}
};

template <typename T>
class dispatcher : public T {
public:
  explicit dispatcher(T&& in) : T(std::move(in)) {}
};

template <typename T>
class cororaii : public T {
public:
  explicit cororaii(T&& in) : T(std::move(in)) {}
};

template <typename T>
class nms : public T {
public:
  explicit nms(T&& in) : T(std::move(in)) {}
};

template <typename T>
class nms_app_id : public T {
public:
  explicit nms_app_id(T&& in) : T(std::move(in)) {}
};

template <typename T>
class nms_app_impl : public T {
public:
  explicit nms_app_impl(T&& in) : T(std::move(in)) {}
};

template <typename T>
class nms_app_call : public T {
public:
  explicit nms_app_call(T&& in) : T(std::move(in)) {}
};

template <typename T>
class exp_module : public T {
public:
  explicit exp_module(T&& in) : T(std::move(in)) {}
};

template <typename T>
class exp_imp_module : public T {
public:
  explicit exp_imp_module(T&& in) : T(std::move(in)) {}
};

template <typename T>
class imp_module : public T {
public:
  explicit imp_module(T&& in) : T(std::move(in)) {}
};

template <typename T>
class impl_module : public T {
public:
  explicit impl_module(T&& in) : T(std::move(in)) {}
};


// DEPRECATED FOR THE MOMENT
// // Base types
// template <typename T>
// class base {
//   //using hold_t = std::conditional_t<std::is_trivial_v<T>, const T, const T&>;
//   // hold_t m_hold;
// 
//   const T m_hold;
// public:
//   // explicit base(const T& c) : m_hold(c) {}
//   explicit base(T&& c) : m_hold(std::move(c)) {}
// //  explicit base(const T& c) : m_hold(c) {}
// //  explicit base(const base&) = default;
//   explicit base(base&&) = default;
//   ~base() = default;
// 
//   const T& inner() const { return m_hold; }
// };

/// template <>
/// class base<str> {
/// private:
///   const str m_str;
/// public:
///   explicit base(str&& s) : m_str(std::move(s)) {}
///   // explicit base(const base&) = default;
///   explicit base(base&&) = default;
///   const str& inner() const { return m_str; }
/// };
/// 
/// template <ik IK>
/// class base <injection<IK>> {
/// private:
///   const injection<IK>& m_ref;
/// public:
///   explicit base(const injection<IK>& r) : m_ref(r) {}
///   explicit base(const base&) = default;
///   explicit base(base&&) = default;
///   const base& inner() const { return m_ref; }
/// };


} // namespace bld::syn

// std::ostream& operator<<(std::ostream& os, const bld::syn::str& inNode );
// template <typename T> std::ostream& operator<<(std::ostream& os, const bld::syn::paren<T> inNode );
// template <typename T> std::ostream& operator<<(std::ostream& os, const bld::syn::sq_bracket<T> inNode );
// template <typename T> std::ostream& operator<<(std::ostream& os, const bld::syn::bracket<T> inNode );
// template <typename T> std::ostream& operator<<(std::ostream& os, const bld::syn::stmt<T> inNode );
// template <typename T> std::ostream& operator<<(std::ostream& os, const bld::syn::coyield<T> inNode );
// // template <typename T> std::ostream& operator<<(std::ostream& os, const bld::syn::nms_cmp<T> inNode );
// template <typename T> std::ostream& operator<<(std::ostream& os, const bld::syn::nms_rt<T> inNode );
// template <typename T> std::ostream& operator<<(std::ostream& os, const bld::syn::move<T> inNode );
// template <typename T> std::ostream& operator<<(std::ostream& os, const bld::syn::declt<T> inNode );
// template <typename T> std::ostream& operator<<(std::ostream& os, const bld::syn::sequence<T> inNode );
// template <typename T1, typename T2> std::ostream& operator<<(std::ostream& os, const bld::syn::type_var<T1, T2> inNode );
// template <typename T1, typename T2> std::ostream& operator<<(std::ostream& os, const bld::syn::pair<T1, T2> inNode );
// template <typename T1, typename T2> std::ostream& operator<<(std::ostream& os, const bld::syn::assign<T1, T2> inNode );
// template <typename... T> std::ostream& operator<<(std::ostream& os, const bld::syn::cat<T...> inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::paren<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::sq_bracket<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::curl_bracket<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::cm_string<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::constref<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nonconstref<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::stmt<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::coyield<T>& inNode );


template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_cmp<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_rt<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_usr<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::enum_kernel<T>& inNode );


template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::move<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::declt<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::sequence<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::stmt_sequence<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::ptr_sequence<T>& inNode );

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const bld::syn::type_var<T1, T2>& inNode );

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const bld::syn::pair<T1, T2>& inNode );

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const bld::syn::assign<T1, T2>& inNode );

template <typename... T>
std::ostream& operator<<(std::ostream& os, const bld::syn::cat<T...>& inNode );


///////////// NEW RT. Many things above to be deprecated

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::bracket<T>& inNode );

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const bld::syn::assignop<T1, T2>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::auto_kw<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::coawait<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::makeasync<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::cororaii<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::dispatcher<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_app_id<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_app_impl<T>& inNode );

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_app_call<T>& inNode );

#endif // STEEL_COMPILER_COMMON_INJECT_SYNTAX_HPP

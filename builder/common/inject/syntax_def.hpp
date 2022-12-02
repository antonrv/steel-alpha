#ifndef STEEL_COMPILER_COMMON_INJECT_SYNTAX_DEF_HPP
#define STEEL_COMPILER_COMMON_INJECT_SYNTAX_DEF_HPP

#include "common/inject/syntax.hpp"

#include "common/inject/syntax_str.hpp"

// template <typename T>
// std::ostream& operator<<(std::ostream& os, bld::syn::str&& inNode ) {
//   os <<& inNode.inner();
//   return os;
// }
// 
// template <typename T>
// std::ostream& operator<<(std::ostream& os, bld::syn::str inNode ) {
//   os <<& inNode.inner();
//   return os;
// }


// std::ostream& operator<<(std::ostream& os, const bld::syn::str inNode ) {
//   os << inNode.inner();
//   return os;
// }


template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::paren<T>& inNode ) {
  os << "(" << static_cast<const T&>(inNode) << ")";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::sq_bracket<T>& inNode ) {
  os << "[" << static_cast<const T&>(inNode) << "]";
  return os;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::constref<T>& inNode ) {
  os << "const " << static_cast<const T&>(inNode) << "&";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nonconstref<T>& inNode ) {
  os << static_cast<const T&>(inNode) << "&";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::stmt<T>& inNode ) {
  os << static_cast<const T&>(inNode) << ";";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms<T>& inNode ) {
  // os << "bld::" << static_cast<const T&>(inNode);
  os << "export\nnamespace " << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::coyield<T>& inNode ) {
  os << "co_yield " << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_cmp<T>& inNode ) {
  // os << "bld::" << static_cast<const T&>(inNode);
  os << "bld::" << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_rt<T>& inNode ) {
  os << "steel::rt::" << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_usr<T>& inNode ) {
  os << "steel::user::" << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::enum_kernel<T>& inNode ) {
  os << "kernel::" << static_cast<const T&>(inNode);
  return os;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::move<T>& inNode ) {
  os << "std::move(" << static_cast<const T&>(inNode) << ")";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::declt<T>& inNode ) {
  os << "decltype(" << static_cast<const T&>(inNode) << ")";
  return os;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::sequence<T>& inNode ) {
  for(const auto& elem : inNode.inner()) {
    os << elem << ",";
  }
  os.seekp(-1, os.cur);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::stmt_sequence<T>& inNode ) {
  for(const auto& elem : inNode.inner()) {
    os << elem << ";";
  }
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::ptr_sequence<T>& inNode ) {
  // Assumed inner is a set of pointers
  for(const auto& elem : inNode.inner()) {
    os << (*elem) << ",";
  }
  os.seekp(-1, os.cur);
  return os;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const bld::syn::type_var<T1, T2>& inNode ) {
  os << static_cast<const T1&>(inNode) << " " << static_cast<const T2&>(inNode);
  return os;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const bld::syn::pair<T1, T2>& inNode ) {
  os << static_cast<const T1&>(inNode) << ", " << static_cast<const T2&>(inNode);
  return os;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const bld::syn::assign<T1, T2>& inNode ) {
  os << static_cast<const T1&>(inNode) << " = " << static_cast<const T2&>(inNode);
  return os;
}

template <typename... T>
std::ostream& operator<<(std::ostream& os, const bld::syn::cat<T...>& inNode ) {
  // ((os << ... << static_cast<const T&>(inNode));
  ((os << static_cast<const T&>(inNode)), ...);
  // ((oss << args << ','), ...); works

  return os;
}

///////////// NEW RT. Many things above to be deprecated

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::bracket<T>& inNode ) {
  os << "<" << static_cast<const T&>(inNode) << ">";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::curl_bracket<T>& inNode ) {
  os << "{" << static_cast<const T&>(inNode) << "}";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::cm_string<T>& inNode ) {
  os << "\"" << static_cast<const T&>(inNode) << "\"";
  return os;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const bld::syn::assignop<T1, T2>& inNode ) {
  os << static_cast<const T1&>(inNode) << " = " << static_cast<const T2&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::auto_kw<T>& inNode ) {
  os << "auto " << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::coawait<T>& inNode ) {
  os << "co_await " << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::makeasync<T>& inNode ) {
  os << "task::make_async<app::call::" << static_cast<const T&>(inNode) << ">";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::cororaii<T>& inNode ) {

  os << "while (not dep::all_destroyable(" << static_cast<const T&>(inNode) << ")) { co_await task::coro::suspend(); }";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::dispatcher<T>& inNode ) {
  os << "task::coro::dispatcher" << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_app_id<T>& inNode ) {
  os << "app::id::" << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_app_impl<T>& inNode ) {
  os << "app::impl::" << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::nms_app_call<T>& inNode ) {
  os << "app::call::" << static_cast<const T&>(inNode);
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::exp_module<T>& inNode ) {
  os << "export module " << static_cast<const T&>(inNode) << ";";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::exp_imp_module<T>& inNode ) {
  os << "export import " << static_cast<const T&>(inNode) << ";";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::imp_module<T>& inNode ) {
  os << "import " << static_cast<const T&>(inNode) << ";";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const bld::syn::impl_module<T>& inNode ) {
  os << "module " << static_cast<const T&>(inNode);
  return os;
}



#endif // STEEL_COMPILER_COMMON_INJECT_SYNTAX_DEF_HPP




#ifdef NDEBUG

#define ensure(e, msg) (void)0

#else


#define ensure(e, msg)   \
  ((e) ? (void)0 :  \
  safe::assert_fail(#e" "#msg, __FILE__, __LINE__, __PRETTY_FUNCTION__))

#endif


// #endif // STEEL_RT_SAFE_HPP

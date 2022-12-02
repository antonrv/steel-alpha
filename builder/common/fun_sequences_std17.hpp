// WARNINGGGGGGGGGGG
// WARNINGGGGGGGGGGG
// WARNINGGGGGGGGGGG
// WARNINGGGGGGGGGGG
// Avoid the use of this hpp. No exceptions, nested namespaces, concepts or modules

#ifndef ENABLE_IMPLEMENTS_MACROS_HPP
#define ENABLE_IMPLEMENTS_MACROS_HPP

/////////////// ARG COUNTER ///////////////

#define VARCOUNT(...) PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...) PP_ARG_N(__VA_ARGS__)
#define PP_ARG_N( \
         _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,_64,_65,_66,_67,_68,_69,_70, \
         _71,_72,_73,_74,_75,_76,_77,_78,_79,_80, \
         _81,_82,_83,_84,_85,_86,_87,_88,_89,_90, \
         _91,_92,_93,_94,_95,_96,_97,_98,_99,_100, \
         _101,_102,_103,  N, ...) N
#define PP_RSEQ_N() \
    103,102,101,100,               \
    99,98,97,96,95,94,93,92,91,90, \
    89,88,87,86,85,84,83,82,81,80, \
    79,78,77,76,75,74,73,72,71,70, \
    69,68,67,66,65,64,63,62,61,60, \
    59,58,57,56,55,54,53,52,51,50, \
    49,48,47,46,45,44,43,42,41,40, \
    39,38,37,36,35,34,33,32,31,30, \
    29,28,27,26,25,24,23,22,21,20, \
    19,18,17,16,15,14,13,12,11,10, \
     9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define GLUE(X,Y) GLUE_I(X,Y)
#define GLUE_I(X,Y) X##Y
#define FIRST(X,...) X

#define TUPLE_TAIL(X,...) __VA_ARGS__

#define SEQUENCE(NAME_, ...) GLUE(SEQUENCE_, VARCOUNT(__VA_ARGS__))(NAME_, __VA_ARGS__)
#define SEQUENCE_1(NAME_, ARGS_) NAME_ ARGS_
#define SEQUENCE_2(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_1(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_3(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_2(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_4(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_3(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_5(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_4(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_6(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_5(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_7(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_6(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_8(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_7(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_9(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_8(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_10(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_9(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_11(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_10(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_12(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_11(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_13(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_12(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_14(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_13(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_15(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_14(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_16(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_15(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_17(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_16(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_18(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_17(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_19(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_18(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_20(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_19(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_21(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_20(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_22(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_21(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_23(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_22(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_24(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_23(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_25(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_24(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_26(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_25(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_27(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_26(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_28(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_27(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_29(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_28(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_30(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_29(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_31(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_30(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_32(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_31(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_33(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_32(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_34(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_33(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_35(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_34(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_36(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_35(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_37(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_36(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_38(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_37(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_39(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_38(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_40(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_39(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_41(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_40(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_42(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_41(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_43(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_42(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_44(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_43(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_45(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_44(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_46(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_45(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_47(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_46(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_48(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_47(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_49(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_48(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_50(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_49(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_51(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_50(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_52(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_51(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_53(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_52(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_54(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_53(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_55(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_54(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_56(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_55(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_57(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_56(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_58(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_57(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_59(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_58(NAME_, TUPLE_TAIL(__VA_ARGS__))
#define SEQUENCE_60(NAME_, ...) NAME_ FIRST(__VA_ARGS__), SEQUENCE_59(NAME_, TUPLE_TAIL(__VA_ARGS__))


// USE CASE ================
// compile example: g++ -std=c++17 main.cpp -o m -DIMPL1=foo -DIMPL2=bar -DIMPL3=zee -g
// enum class impl { SEQUENCE(,IMPL1, IMPL2, IMPL3)  };
// 
// template <impl... IArgs>
// using impl_sequence = std::integer_sequence<impl, IArgs...>;
// 
// using enabled_implement = impl_sequence< SEQUENCE(impl::, IMPL1) >;
// using enabled_implement_9 = impl_sequence< SEQUENCE(impl::, IMPL1, IMPL2, IMPL3, IMPL1, IMPL2, IMPL3, IMPL1, IMPL2, IMPL3) >;
// 
// template <impl... IArgs>
// void db_seq(impl_sequence<IArgs...>) {
//   return;
// }
// 
// int main(void) {
// 
//   db_seq(enabled_implement_9{});
// }
//
#define STRINGIFY(X) #X
#define STRINGIFY_FIRST(X,...) #X
 
#define STRINGIFY_SEQ(...) GLUE(STRINGIFY_SEQ_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define STRINGIFY_SEQ_1(ARG_) STRINGIFY(ARG_)
#define STRINGIFY_SEQ_2(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_1(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_3(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_2(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_4(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_3(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_5(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_4(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_6(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_5(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_7(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_6(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_8(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_7(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_9(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_8(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_10(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_9(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_11(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_10(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_12(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_11(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_13(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_12(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_14(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_13(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_15(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_14(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_16(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_15(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_17(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_16(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_18(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_17(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_19(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_18(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_20(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_19(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_21(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_20(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_22(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_21(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_23(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_22(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_24(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_23(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_25(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_24(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_26(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_25(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_27(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_26(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_28(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_27(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_29(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_28(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_30(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_29(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_31(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_30(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_32(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_31(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_33(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_32(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_34(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_33(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_35(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_34(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_36(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_35(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_37(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_36(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_38(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_37(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_39(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_38(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_40(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_39(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_41(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_40(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_42(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_41(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_43(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_42(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_44(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_43(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_45(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_44(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_46(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_45(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_47(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_46(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_48(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_47(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_49(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_48(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_50(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_49(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_51(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_50(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_52(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_51(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_53(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_52(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_54(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_53(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_55(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_54(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_56(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_55(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_57(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_56(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_58(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_57(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_59(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_58(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_60(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_59(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_61(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_60(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_62(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_61(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_63(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_62(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_64(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_63(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_65(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_64(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_66(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_65(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_67(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_66(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_68(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_67(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_69(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_68(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_70(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_69(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_71(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_70(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_72(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_71(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_73(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_72(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_74(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_73(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_75(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_74(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_76(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_75(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_77(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_76(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_78(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_77(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_79(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_78(TUPLE_TAIL(__VA_ARGS__))
#define STRINGIFY_SEQ_80(...) STRINGIFY_FIRST(__VA_ARGS__), STRINGIFY_SEQ_79(TUPLE_TAIL(__VA_ARGS__))


#include <cstddef>
#include <algorithm>
#include <string>
#include <vector>
#include <array>

// ================= MACRO TO DEFINE ENUMERATIONS WITH STRING CONVERSIONS ==============

// requires forward declaration of the following, which is in util/types.hpp
// template <typename EnumT>
// requires std::is_enum_v<EnumT>
// struct enum_convert;
// ENUM_DEFINITION CANNOT BE IN ANY NAMESPACE.
// The definitions are the following:
//    Creates the enum class
//    The enum_convert structure to convert enums to index and strings
//    Templated sequences
// needed forward declarations  

namespace util {
  template <typename EnumT>     
  struct enum_convert;
} // namespace util                 

    // FROZEN

#define ENUM_DEFINITION(InputEnumNamespace, InputEnumName, ...) \
  namespace InputEnumNamespace { enum class InputEnumName : std::size_t { __VA_ARGS__ }; } \
  namespace util { \
    static constexpr std::array<const char*, VARCOUNT(__VA_ARGS__) > EnumNames_##InputEnumName = { STRINGIFY_SEQ(__VA_ARGS__) }; \
  template <> struct enum_convert<InputEnumNamespace :: InputEnumName> { \
    static constexpr const char* enum_name = #InputEnumName; \
    static constexpr std::size_t enum_count = VARCOUNT(__VA_ARGS__); \
    template <InputEnumNamespace :: InputEnumName Val> static constexpr std::size_t to_index() { return static_cast<std::size_t>(Val); } \
    template <InputEnumNamespace :: InputEnumName Val> static constexpr const char* to_string() { return EnumNames_##InputEnumName[to_index<Val>()]; } \
    static std::size_t to_index_rt(const InputEnumNamespace :: InputEnumName val) { return static_cast<std::size_t>(val); } \
    static const char* to_string_rt(const InputEnumNamespace :: InputEnumName val) { return EnumNames_##InputEnumName[to_index_rt(val)]; } \
    static InputEnumNamespace :: InputEnumName index_to_enum_rt(const std::size_t id) { \
      return static_cast< InputEnumNamespace :: InputEnumName >(id); \
    } \
    static InputEnumNamespace :: InputEnumName string_to_enum_rt(const std::string& str) { \
      auto it = std::find_if(std::begin( EnumNames_##InputEnumName ), std::end( EnumNames_##InputEnumName ), [str](const char* cstr) {return str == cstr;} ); \
      if (it != std::end( EnumNames_##InputEnumName ) ) { return index_to_enum_rt(std::distance(std::begin( EnumNames_##InputEnumName ), it)); } \
      else { return index_to_enum_rt(0); /*failure*/ } \
    } \
  }; \
  template <InputEnumNamespace :: InputEnumName ... EnumValArgs> \
  using GLUE(InputEnumName,_sequence) = std::integer_sequence<InputEnumNamespace :: InputEnumName, EnumValArgs...>; \
  } // namespace util 


// ============== MACRO TO DEFINE LOGGING/TRACING/INSTRUMENTATION ENUMERATIONS WITH STRING CONVERSIONGS ========
// We define the enumeration in steel::instrument namespace AND define an additional struct derived from enum_convert.
// We have to add some non-const char* and unsigned int static variables because otherwise Extrae would complain.
// requires fw declaration of enum_traits in steel::instrument

#if ENABLE_TRACE_EXTRAE != 1
#define ENUM_TRACE_DEFINITION(InputIndexIdentifier, InputEnumName, ...) \
    ENUM_DEFINITION(steel::instrument, InputEnumName, __VA_ARGS__) \
    namespace steel::instrument { \
      template <> struct enum_traits<InputEnumName> : util::enum_convert<InputEnumName> { \
        static constexpr std::size_t enum_identifier = InputIndexIdentifier; \
        static constexpr bool value = true; \
      };\
    }
#else
#define ENUM_TRACE_DEFINITION(InputIndexIdentifier, InputEnumName, ...) \
    ENUM_DEFINITION(steel::instrument, InputEnumName, __VA_ARGS__) \
    namespace steel::instrument { \
      template <> struct enum_traits<InputEnumName> : util::enum_convert<InputEnumName> { \
        static constexpr std::size_t enum_identifier = InputIndexIdentifier; \
        static constexpr std::array<char*, enum_count> NamesForExtrae = { STRINGIFY_SEQ(__VA_ARGS__) }; \
        static constexpr unsigned int IdentifierForExtrae = enum_identifier; \
        static constexpr bool value = true; \
      };\
    }
#endif // ENABLE_TRACE_EXTRAE


// ================= MACRO TO DEFINE COMPILE TIME SEQUENCES OF ENUMERATION VALUES ==============
// This macro is useful to define the user- and system-enabled features.
// Can be defined in any memory space
#define ENABLE_SEQUENCE( InputEnumNamespace, InputEnumName, ... ) \
  namespace enabled { \
    using Sequence_##InputEnumName = util:: GLUE(InputEnumName,_sequence)< SEQUENCE(InputEnumNamespace :: InputEnumName ::,__VA_ARGS__)>; \
  }


template <typename EnumT>
std::enable_if_t<std::is_enum_v<EnumT>, std::ostream&>
operator<<(std::ostream& ofs, const EnumT enumV) {
  ofs << util::enum_convert<EnumT>::enum_name << "::" << util::enum_convert<EnumT>::to_string_rt(enumV);
  return ofs;
}

#include <sstream>

template <typename EnumT>
std::enable_if_t<std::is_enum_v<EnumT>, std::string>
to_string(const EnumT enumV) {
  std::stringstream ss;
  ss << enumV;
  return ss.str();
}




// // ========= USE CASE for ENUM_DEFINITION AND ENABLE_SEQUENCE =========
// // g++-8 main.cpp -o m -std=c++17 -fconcepts -DUSER_SEQUENCE="foo, bar, zee, gadsfh, sdgsd, sdg, sdfg4, dfs524fdsw"
//    
// #include <iostream>
// #include <array>
// 
// namespace util {
// 
// template <typename EnumT>
// requires std::is_enum_v<EnumT>
// struct enum_convert;
// 
// } // util
// 
// 
// ENUM_DEFINITION(steel::app, impl, USER_SEQUENCE)
// 
// namespace mynamespace {
// 
// ENABLE_SEQUENCE(steel::app, impl, USER_SEQUENCE);
// 
// } // mynamespace
// 
// template <typename T, T... EnumVals>
// std::ostream& operator<<(std::ostream& ofs, std::integer_sequence<T, EnumVals...>) {
//   ofs << "Printing sequence of enumerations " << util::enum_convert<T>::enum_name << ": \n";
//   ((ofs << util::enum_convert<T>::template to_index<EnumVals>() << '\n'), ... );
//   ((ofs << util::enum_convert<T>::template to_string<EnumVals>() << '\n'), ... );
//   return ofs;
// }
// 
// int main(void) {
// 
//   using myseq = mynamespace::EnabledSequence_impl;
// 
//   // print_seq(std::cout, myseq{});
// 
//   std::cout << myseq{};
// }


#endif // define ENABLE_IMPLEMENTS_MACROS_HPP

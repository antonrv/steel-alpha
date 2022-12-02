
export module SteelRT.Util.Sequence;

import SteelRT.Util.Types;

import <type_traits>;
import <cstdint>;
import <utility>;


// Substitute std::index_sequence stuff by util::sequence::index_t TODO

// namespace app {
// 
// } // namespace app

namespace util::sequence {

// ==== enum_t

// Not used std::integer_sequence because clang poses some problems using enum types.
export
template <typename EnumT, EnumT... EnumVals>
struct enum_t {
  using value_type = EnumT;
  static constexpr enum_uint_t size() { return sizeof...(EnumVals); }
};

// ==== to_variadic

  template <typename SeqT, template <typename SeqT::value_type...> class VariadicTemplType>
  struct to_variadic;
  
  template <typename EnumT, EnumT... EnumArgs, template <EnumT...> class VariadicTemplType>
  struct to_variadic<sequence::enum_t<EnumT, EnumArgs...>, VariadicTemplType> {
    using type = VariadicTemplType<EnumArgs...>;
  };

export
template <typename SeqT, template <typename SeqT::value_type...> class VariadicTemplType>
using to_variadic_t = typename to_variadic<SeqT, VariadicTemplType>::type;

export
template <std::size_t... Ids>
using index_t = enum_t< std::size_t, Ids... >;



// ==== empty

  template <typename SeqT>
  struct empty;
 
export 
template <typename SeqT>
struct empty : std::false_type {};

export
template <typename T>
struct empty < sequence::enum_t<T> > : std::true_type {};

export 
template <typename SeqT>
inline constexpr bool empty_v = empty<SeqT>::value;

// ==== contains_v
export
template <typename SeqT, typename SeqT::value_type Val>
struct contains;
  
export
template <typename T, T Val, T... Args>
struct contains<sequence::enum_t<T, Args...>, Val> {
  static constexpr bool value = ((Args == Val) || ...);
};

export
template <typename SeqT, typename SeqT::value_type Val>
inline constexpr bool contains_v = contains<SeqT, Val>::value;



// ============================= SEQUENCE CONCATENATION
  template <typename SeqTypeA, typename SeqTypeB>
  struct cat;
  
  template <typename T, T... IndicesA, T... IndicesB>
  struct cat<sequence::enum_t<T, IndicesA...>, sequence::enum_t<T, IndicesB...>> {
     using type = sequence::enum_t<T, IndicesA..., IndicesB...>;
  };

  template <std::size_t... IndicesA, std::size_t... IndicesB>
  struct cat<sequence::index_t<IndicesA...>, sequence::index_t<IndicesB...>> {
     using type = sequence::index_t<IndicesA..., IndicesB...>;
  };

export
template <typename SeqTypeA, typename SeqTypeB>
using cat_t = typename cat<SeqTypeA, SeqTypeB>::type;


// --------------------------- multi-SEQUENCE CONCATENATION
  template <typename... Sequences>
  struct multi_cat;
  
  template <typename T, T... IndicesA>
  struct multi_cat<sequence::enum_t<T, IndicesA...>> {
    using type = sequence::enum_t<T, IndicesA...>;
  };
  
  template <typename FirstSeqT, typename SecondSeqT, typename... TailSequences>
  struct multi_cat<FirstSeqT, SecondSeqT, TailSequences...> {
    using this_type = cat_t<FirstSeqT, SecondSeqT>;
    using type = typename multi_cat<this_type, TailSequences...>::type;
  };

export
template <typename... Sequences>
using multi_cat_t = typename multi_cat<Sequences...>::type;

// ================ sequence filter ==========================
  template <typename SeqT, template <typename SeqT::value_type Val> class IncludePredT>
  struct filter;
  
  template <typename VT, template <VT Val> class IncludeUnaryPredT>
  struct filter<sequence::enum_t<VT>, IncludeUnaryPredT> {
    using type = sequence::enum_t<VT>;
  };
  
  template <typename VT, VT HeadVal, VT... TailArgs, template <VT> class IncludeUnaryPredT>
  struct filter<sequence::enum_t<VT, HeadVal, TailArgs...>, IncludeUnaryPredT > {
    using this_seq = std::conditional_t<IncludeUnaryPredT<HeadVal>::value, sequence::enum_t<VT, HeadVal>, sequence::enum_t<VT>>;
    using type = cat_t<this_seq, typename filter<sequence::enum_t<VT, TailArgs...>, IncludeUnaryPredT>::type>;
  };

export
template <typename SeqT, template <typename SeqT::value_type Val> class IncludePredT>
using filter_t = typename filter<SeqT, IncludePredT>::type;


// ================ sequence count (count elements satisfying predicate) ==========================

export
template <typename SeqT, template <typename SeqT::value_type Val> class IncludePredT>
inline constexpr std::size_t count_v = filter_t<SeqT, IncludePredT>::size();

// ========================== sequence intersect

  template <typename SeqA, typename SeqB>
  struct intersect;
  
  // End case
  template <typename EnumTA, typename SeqB>
  struct intersect<sequence::enum_t<EnumTA>, SeqB> {
    using type = sequence::enum_t<EnumTA>;
  };

  // General case
  template <typename EnumTA, EnumTA EnumValA, EnumTA... TailA,
            typename SeqB>
  struct intersect<sequence::enum_t<EnumTA, EnumValA, TailA...>, SeqB> {
  
    using this_sequence = std::conditional_t<contains_v<SeqB, EnumValA>, sequence::enum_t<EnumTA, EnumValA>, sequence::enum_t<EnumTA>>;
  
    using type = cat_t<
        this_sequence,
        typename intersect<sequence::enum_t<EnumTA, TailA...>, SeqB>::type>;
  };

export template <typename SeqA, typename SeqB>
using intersect_t = typename intersect<SeqA, SeqB>::type;


// ========================== sequence single element

export
template <typename SeqT>
struct singleton {
  static constexpr bool value = SeqT::size() == 1;
};

export
template <typename SeqT>
inline constexpr bool singleton_v = singleton<SeqT>::value;




// =================================== SEQUENCE UNIQUE =========================
// eliminate repeated elements in a compile-time sequence (integer_sequence) of ElemType values
  template <typename SeqT>
  struct unique;
  
  // deepest case
  template <typename ElemType>
  struct unique<sequence::enum_t<ElemType>> {
    using type = sequence::enum_t<ElemType>;
  };
  // general case
  template <typename ElemType, ElemType Val, ElemType... ValArgs>
  struct unique<sequence::enum_t<ElemType, Val, ValArgs...>> {
   
    // use std::disjuntion better TODO 
  //  static constexpr bool are_equal(ElemType A, ElemType B) { return A == B; }
    static constexpr bool is_in_tail = ((Val == ValArgs) || ...);
  
    using this_type = std::conditional_t<is_in_tail, sequence::enum_t<ElemType>, sequence::enum_t<ElemType, Val>>;
    using next_type = typename unique<sequence::enum_t<ElemType, ValArgs...>>::type;
  
    using type = cat_t<this_type, next_type>;
  };

export
template <typename SeqT>
using unique_t = typename unique<SeqT>::type;

export
template <typename SeqT>
inline constexpr bool is_unique_v = std::is_same_v<SeqT, unique_t<SeqT>>;



// =================================== SEQUENCE REVERSE =========================

  template <typename SeqT>
  struct reverse;
  
  template <typename T>
  struct reverse< sequence::enum_t<T> > {
    using type = sequence::enum_t<T>;
  };
  
  template <typename T, T Val, T... Args>
  struct reverse<sequence::enum_t<T, Val, Args...>> {
  
    using next_seq = typename reverse< sequence::enum_t<T, Args...> >::type;
    using this_seq = sequence::enum_t<T, Val>;
  
    using type = sequence::cat_t<next_seq, this_seq>;
  };

export
template <typename SeqT>
using reverse_t = typename reverse<SeqT>::type;


// =================================== SEQUENCE REMOVE =========================

  template <typename SequenceT, typename SequenceT::value_type EnumV>
  struct remove;
  
  template <typename EnumT, EnumT EnumVal>
  struct remove<sequence::enum_t<EnumT>, EnumVal> {
    using type = sequence::enum_t<EnumT>;
  };
  
  template <typename EnumT, EnumT EnumVal, EnumT EnumHead, EnumT... EnumTailArgs>
  struct remove<sequence::enum_t<EnumT, EnumHead, EnumTailArgs...>, EnumVal> {
    using next_seq = sequence::cat_t<sequence::enum_t<EnumT, EnumHead>, typename remove<sequence::enum_t<EnumT, EnumTailArgs...>, EnumVal>::type>;
    using type =  std::conditional_t< EnumVal == EnumHead, //condition
                      sequence::enum_t<EnumT, EnumTailArgs...>, // true type. just skip the head and return the tail
                      next_seq // false type.
                  >;
  };

export
template <typename SequenceT, typename SequenceT::value_type EnumV>
using remove_t = typename remove<SequenceT, EnumV>::type;


// =================================== SEQUENCE TRANSFORM =========================
  template <typename SeqT, typename OutputT, template <typename SeqT::value_type > class TransTemplT>
  struct transform;
  
  
  template <typename InputT, InputT... InputVals, typename OutputT, template <InputT> class TransTemplT>
  struct transform< sequence::enum_t<InputT, InputVals...>, OutputT, TransTemplT > {
    static_assert( std::conjunction_v< std::is_same< OutputT, typename TransTemplT<InputVals>::type > ... > );
  
    using type = util::sequence::enum_t< OutputT, TransTemplT<InputVals>::value ... >;
  };

export
template <typename SeqT, typename OutputT, template <typename SeqT::value_type > class TransTemplT>
using transform_t = typename transform<SeqT, OutputT, TransTemplT>::type;



// ========================== SEQUENCE_HEAD / FIRST ==============
  template <typename SeqT>
  struct head;

  template <typename ElemT, ElemT Arg, ElemT... Args>
  struct head<sequence::enum_t<ElemT, Arg, Args...>>
  { 
    using type = sequence::enum_t<ElemT, Arg>;
    static constexpr ElemT value = Arg;
  };

export
template <typename SeqT>
using head_t = typename head<SeqT>::type;

export
template <typename SeqT>
inline constexpr typename SeqT::value_type head_v = head<SeqT>::value;

export
template <typename SeqT>
inline constexpr typename SeqT::value_type first_v = head<SeqT>::value;


// ========================== SEQUENCE_TAIL ==============
  template <typename SeqT>
  struct tail;
  
  template <typename ElemT, ElemT Arg, ElemT... Args>
  struct tail<sequence::enum_t<ElemT, Arg, Args...>>
  { 
    using type = sequence::enum_t<ElemT, Args...>;
  };

export
template <typename SeqT>
using tail_t = typename tail<SeqT>::type;

// ========================== SEQUENCE_LAST ==============
  template <typename SeqT>
  struct last;

  template <typename ElemT, ElemT Arg>
  struct last< sequence::enum_t<ElemT, Arg> > {
    using type = sequence::enum_t<ElemT, Arg>;
  };
  
  template <typename ElemT, ElemT Arg, ElemT Arg2, ElemT... Args>
  struct last< sequence::enum_t<ElemT, Arg, Arg2, Args...> > { 
    using type = typename last< sequence::enum_t<ElemT, Arg2, Args...> >::type;
  };

export
template <typename SeqT>
using last_t = typename last<SeqT>::type;

export
template <typename SeqT>
inline constexpr typename SeqT::value_type last_v = head_v< last_t<SeqT> >;


// ========================== MAKE SEQUENCE_TAIL ==============
export
template <std::size_t N>
using make_index_tail = tail_t<std::make_index_sequence<N>>;

// // ========================== INDEX SEQUENCE FOR TAIL ==============
// export
// template <typename... Args>
// using index_for_tail = tail_t<sequence::index_t_for<Args...>>;


// ========================== SEQUENCE SUBSTRACT ==============

  template <typename BiggerSeqT, typename SmallerSeqT>
  struct sub;
  
  template <typename SmallerSeqT >
  struct sub < enum_t< typename SmallerSeqT::value_type >, SmallerSeqT > {
    using type = enum_t< typename SmallerSeqT::value_type >;
  };
  
  template <typename SmallerSeqT, typename SmallerSeqT::value_type HeadBigVal, typename SmallerSeqT::value_type... TailBigVals >
  struct sub < enum_t< typename SmallerSeqT::value_type, HeadBigVal, TailBigVals... >, SmallerSeqT  > {
  
    using val_type = typename SmallerSeqT::value_type;
  
    using this_type = std::conditional_t< contains_v<SmallerSeqT, HeadBigVal>, enum_t< val_type >, enum_t< val_type, HeadBigVal > >;
  
    using type = cat_t< this_type, typename sub< enum_t<val_type, TailBigVals...>, SmallerSeqT >::type >;
  };

export
template <typename BiggerSeqT, typename SmallerSeqT>
using sub_t = typename sub<BiggerSeqT, SmallerSeqT>::type;


// ========================== to array

  template <typename T>
  struct to_array;
  
  template <typename ElemT, ElemT... Args>
  struct to_array<sequence::enum_t<ElemT, Args...>> {
    using type = std::array<ElemT, sizeof...(Args)>;
    static constexpr const type value = {Args...};
  };

  template <std::size_t... Ids>
  struct to_array<sequence::index_t<Ids...>> {
    using type = std::array<std::size_t, sizeof...(Ids)>;
    static constexpr const type value = {Ids...};
  };

export
template <typename SeqT>
using to_array_t = typename to_array<SeqT>::type;

export
template <typename SeqT>
inline constexpr to_array_t<SeqT> to_array_v = to_array<SeqT>::value;

// =================== get_value_in: retrieve a specific value in position Idx
  template <typename SeqT, std::size_t Idx>
  struct get_value_in;

  template <typename T, T Head, T... TailArgs>
  struct get_value_in< sequence::enum_t<T, Head, TailArgs...>, 0 > {
    static constexpr T value = Head;
  };

  template <typename T, std::size_t Idx, T Head, T... TailArgs>
  struct get_value_in< sequence::enum_t<T, Head, TailArgs...>, Idx > {
    static constexpr T value = get_value_in< sequence::enum_t<T, TailArgs...>, Idx - 1 >::value;
  };

export
template <typename SeqT, std::size_t Idx>
inline constexpr typename SeqT::value_type get_value_in_v = get_value_in< SeqT, Idx >::value;


// =================== get_index
  template <typename SeqT, typename SeqT::value_type Val>
  struct get_index;
  
  template <typename T, T Val>
  struct get_index<sequence::enum_t<T>, Val> {
    static constexpr std::size_t value = 0;
  };
  
  template <typename T, T Val, T Head, T... TailArgs>
  struct get_index< sequence::enum_t<T, Head, TailArgs...>, Val > {
    // static_assert( sequence::contains_v< sequence::enum_t<T, Head, TailArgs...>, Val > ); assert is unique also
    static constexpr std::size_t value = Head == Val ? 0 : 1 + get_index< sequence::enum_t<T, TailArgs...>, Val >::value;
  };

export
template <typename SeqT, typename SeqT::value_type Val>
inline constexpr std::size_t get_index_v = get_index<SeqT, Val>::value;


// =================== add_front / add_back
  template <typename SeqT, typename SeqT::value_type Val>
  struct add_front {
    using type = cat_t< sequence::enum_t< typename SeqT::value_type, Val >, SeqT >;
  };
  
  template <typename SeqT, typename SeqT::value_type Val>
  struct add_back {
    using type = cat_t< SeqT, sequence::enum_t< typename SeqT::value_type, Val > >;
  };

export
template <typename SeqT, typename SeqT::value_type Val>
using add_front_t = typename add_front<SeqT, Val>::type;

export
template <typename SeqT, typename SeqT::value_type Val>
using add_back_t = typename add_back<SeqT, Val>::type;

// =================== pop_front / pop_back

  template <typename SeqT>
  struct pop_front;

  template <typename T, T Head, T... TailArgs>
  struct pop_front< sequence::enum_t<T, Head, TailArgs...> > {
    using type = sequence::enum_t<T, TailArgs...>;
  };

export
template <typename SeqT>
using pop_front_t = typename pop_front<SeqT>::type;


  template <typename SeqT>
  struct pop_back;

  template <typename T, T Last>
  struct pop_back< sequence::enum_t<T, Last> > {
    using type = sequence::enum_t<T>;
  };

  template <typename T, T First, T Second, T... TailArgs>
  struct pop_back< sequence::enum_t<T, First, Second, TailArgs...> > {
    using type = sequence::cat_t< sequence::enum_t<T, First>, typename pop_back< sequence::enum_t<T, Second, TailArgs...> >::type >;
  };


export
template <typename SeqT>
using pop_back_t = typename pop_back<SeqT>::type;

export
template <typename SeqT>
using pop_front_back_t = pop_front_t< pop_back_t<SeqT> >;



// =================== TRIM TAIL FROM position
  template <typename SeqT, std::size_t Pos>
  struct trim_tail_from;
  
  template <typename SeqT>
  struct trim_tail_from< SeqT, 0 > {
    using type = sequence::enum_t<typename SeqT::value_type>;
  };
  
  template <typename SeqT, std::size_t Pos>
  struct trim_tail_from {
  
    using type = sequence::cat_t< head_t<SeqT>, typename trim_tail_from< tail_t<SeqT>, Pos - 1 >::type >;
  };

export
template <typename SeqT, std::size_t Pos>
using trim_tail_from_t = typename trim_tail_from<SeqT, Pos>::type;


// =================== Add NTimes copies of CopySeqT to TargetSeqT

  template <std::size_t NTimes, typename TargetSeqT, typename CopySeqT>
  struct add_to_target;

  // Put 0 copies of CopySeqT into TargetSeqT
  template <typename TargetSeqT, typename CopySeqT>
  struct add_to_target<0, TargetSeqT, CopySeqT> {
    using type = TargetSeqT;
  };

  // Put 1 copy of CopySeqT into TargetSeqT
  template <typename TargetSeqT, typename CopySeqT>
  struct add_to_target<1, TargetSeqT, CopySeqT> {
    using type = sequence::cat_t<TargetSeqT, CopySeqT>;
  };

  template <std::size_t NTimes, typename TargetSeqT, typename CopySeqT>
  struct add_to_target {
    using type = typename add_to_target< NTimes - 1, sequence::cat_t<TargetSeqT, CopySeqT>, CopySeqT >::type;
  };

export
template <std::size_t NTimes, typename TargetSeqT, typename CopySeqT>
using add_to_target_t = typename add_to_target<NTimes, TargetSeqT, CopySeqT>::type;


// =================== Copy sequence N times

  template <std::size_t NTimes, typename SeqT>
  struct make_copies;

  // 0 copies -> empty sequence
  template <typename SeqT>
  struct make_copies<0, SeqT> {
    using type = sequence::enum_t< typename SeqT::value_type >; // Empty
  };

  // 1 copies -> same sequence
  template <typename SeqT>
  struct make_copies<1, SeqT> {
    using type = SeqT;
  };

  template <std::size_t NTimes, typename SeqT>
  struct make_copies {
    using type  = sequence::add_to_target_t< NTimes - 1, SeqT, SeqT >;
  };

export
template <std::size_t NTimes, typename SeqT>
using make_copies_t = typename make_copies<NTimes, SeqT>::type;


// =================== Sum of indices

  template <typename IndexSeqT>
  struct index_sum;

  template <std::size_t... Ids>
  struct index_sum< sequence::index_t<Ids...> > {
    static constexpr std::size_t value = (Ids + ...);
  };


export  
template <typename IndexSeqT>
inline constexpr std::size_t index_sum_v = index_sum<IndexSeqT>::value;

// =================== Aggregation of indices. Creates another sequence with same size, with cumulative indexes

  template <typename IndexSeqT>
  struct index_aggregate;

    template <>
    struct index_aggregate< sequence::index_t<> > {
      using type = sequence::index_t<>;
    };
  
    template <std::size_t Id, std::size_t... Ids>
    struct index_aggregate< sequence::index_t<Id, Ids...> > {
  
      static constexpr std::size_t this_value = index_sum_v< sequence::index_t<Id, Ids...> >;
      
      using type = sequence::cat_t< sequence::index_t< this_value >, typename index_aggregate< sequence::index_t<Ids...> >::type >;
    };

export
template <typename IndexSeqT>
using index_aggregate_t = typename index_aggregate<IndexSeqT>::type;


// ============== aggregate a constant index

  template <typename IndexSeqT, std::size_t Value>
  struct index_add_constant;

  template <std::size_t Value, std::size_t... Ids>
  struct index_add_constant< sequence::index_t<Ids...>, Value > {
    using type = sequence::index_t< (Value + Ids) ... >;
  };

export
template <typename IndexSeqT, std::size_t Value>
using index_add_constant_t = typename index_add_constant<IndexSeqT, Value>::type;




// ============== uniform index sequence

  template <std::size_t N, auto Val>
  struct uniform;
  
  template <auto Val>
  struct uniform<0,Val> {
    using type = sequence::enum_t<decltype(Val)>;
  };
  
  template <std::size_t N, auto Val>
  struct uniform {
    using value_type = decltype(Val);
    using type = sequence::cat_t< sequence::enum_t<value_type, Val>, typename uniform<N-1, Val>::type >;
  };


export
template <std::size_t N, auto Val>
using make_uniform = typename uniform<N, Val>::type;



// ============== uniform array

  template <std::size_t N, auto Value>
  struct make_uniform_array {
    using seq_type = make_uniform<N, Value>;
    using array_type = sequence::to_array_t< seq_type >;
    static constexpr array_type value = to_array_v< seq_type >;
  };

export
template <std::size_t N, auto Value>
using make_uniform_array_v = typename make_uniform_array<N, Value>::value;



//////////////////////////// From tuple. Builds a sequence of enum values from a tuple of types

  template <typename TupleT, template <typename> class TemplT>
  struct from_tuple;
  
  template <typename T, typename... Ts, template <typename> class TemplT>
  struct from_tuple < tuple_t<T, Ts...>, TemplT> {
    using type = sequence::enum_t<std::remove_const_t<decltype(TemplT<T>::value)>, TemplT<T>::value, TemplT<Ts>::value ... >;
  };

export
template <typename TupleT, template <typename> class TemplT>
using from_tuple_t = typename from_tuple<TupleT, TemplT>::type;


///////////////////////// make index

  template <std::size_t N>
  struct make_index;
  
  template <>
  struct make_index <0> {
    using type = index_t<>;
  };
  
  template <std::size_t N>
  struct make_index {
    using type = cat_t< typename make_index<N-1>::type, index_t<N-1>>;
  };

export
template <std::size_t N>
using make_index_t = typename make_index< N >::type;

// ============= get indices of elements satisfying a predicate

  template <typename SeqT, typename IndexSeqT, template <typename SeqT::value_type> class PredT >
  struct satisfy_indexes_detail;
  
  template <typename InputT, template <InputT > class PredT >
  struct satisfy_indexes_detail < sequence::enum_t<InputT>, sequence::index_t<> , PredT > {
    using type = sequence::index_t<>;
  };
  
  template <typename InputT, InputT HeadV, InputT... TailVs, std::size_t HeadId, std::size_t... TailIds, template <InputT > class PredT >
  struct satisfy_indexes_detail < sequence::enum_t<InputT, HeadV, TailVs...>, sequence::index_t<HeadId, TailIds...>, PredT > {
  
    using this_type = std::conditional_t< PredT<HeadV>::value, sequence::index_t< HeadId >, sequence::index_t<> >;
  
    using type = sequence::cat_t<
        this_type,
        typename satisfy_indexes_detail< sequence::enum_t<InputT, TailVs...>, sequence::index_t<TailIds...>, PredT >::type
      >;
  };


export
template < typename SeqT, template <typename SeqT::value_type> class PredT >
using satisfy_indexes_t = typename satisfy_indexes_detail< SeqT, make_index_t<SeqT::size()>, PredT >::type;


// =================================== GET MAX VALUE

  template <typename SeqT>
  struct max;
  
  template <>
  struct max <index_t<>> {
    static constexpr std::size_t value = 0;
  };
  
  template <std::size_t Id, std::size_t... Ids>
  struct max <index_t<Id, Ids...>> {
    static constexpr std::size_t value = (max<index_t<Ids...>>::value < Id) ? Id : max<index_t<Ids...>>::value;
  };

export
template <typename SeqT>
inline constexpr std::size_t max_v = max<SeqT>::value;

// =================================== GET MIN VALUE

  template <typename SeqT>
  struct min;
  
  template <>
  struct min <index_t<>> {
    using value_type = index_t<>::value_type;
    static constexpr std::size_t value = std::numeric_limits<value_type>::max();
  };
  
  template <std::size_t Id, std::size_t... Ids>
  struct min <index_t<Id, Ids...>> {
    static constexpr std::size_t value = (min<index_t<Ids...>>::value > Id) ? Id : min<index_t<Ids...>>::value;
  };

export
template <typename SeqT>
inline constexpr std::size_t min_v = min<SeqT>::value;


// =================================== MASK. Get another sequence with only the values referred in the indices

  template <typename SeqT, typename SeqIdxT>
  struct mask;

  template <typename SeqT, std::size_t... Ids>
  struct mask <SeqT, sequence::index_t<Ids...> > {
    using value_type = typename SeqT::value_type;
    using type = sequence::enum_t<value_type, get_value_in_v<SeqT, Ids> ... >;
  };


export
template <typename SeqT, typename SeqIdxT>
using mask_t = typename mask<SeqT, SeqIdxT>::type;


// =================================== GET_MASK. Get another sequence with only the values referred in the indices

  template <typename SeqT, typename RestrictSeqT>
  struct get_mask;

  template <typename SeqT, typename SeqT::value_type... RestrictVals>
  struct get_mask < SeqT, sequence::enum_t<typename SeqT::value_type, RestrictVals...> > {
    static_assert( sizeof...(RestrictVals) > 0 );
    static_assert( sizeof...(RestrictVals) < SeqT::size() );
    using type = sequence::index_t< get_index_v<SeqT, RestrictVals> ... >;
  };

export
template <typename SeqT, typename RestrictSeqT>
using get_mask_t = typename get_mask<SeqT, RestrictSeqT>::type;


///////////////////////// get_index_rt (O(n), unless a minimal perfect hash function is provided

export
template <typename T>
struct get_index_rt;

/////////// Specialization for arrays
export
template <typename ElemT, std::size_t N>
struct get_index_rt< std::array<ElemT, N> > {

  using container_t = std::array<ElemT, N>;

  static uint_t from_value(const container_t& arr, const ElemT val) noexcept {
    for (auto i = 0u; i < N; ++i) {
      if (arr[i] == val) { return i; }
    }
    return N; // Error. maybe use assert here
  }

  
  static bool exists_in(const container_t& arr, const ElemT val) noexcept {
    for (auto i = 0u; i < N; ++i) {
      if (arr[i] == val) { return true; }
    }
    return false;
  }
};

/////////// General form for sequences
export
template <typename SeqT>
struct get_index_rt {

  using elem_t = typename SeqT::value_type;
  using array_t = sequence::to_array_t< SeqT >;
  static constexpr array_t array_v = sequence::to_array_v<SeqT>;

  static uint_t from_value(const elem_t val) noexcept {
    return get_index_rt< array_t >::from_value( array_v, val );
  }

  static bool exists_in(const elem_t val) noexcept {
    return get_index_rt< array_t >::exists_in( array_v, val );
  }
};



// ========================== sequence to bits


  template <std::size_t NB, typename EnumT>
  void to_bits_detail(id_set_t& ret, sequence::enum_t<EnumT>) {}
  
  template <std::size_t NB, typename EnumT, EnumT ThisEn, EnumT... EnArgs>
  void to_bits_detail(id_set_t& ret, sequence::enum_t<EnumT, ThisEn, EnArgs...>) {
    static_assert(static_cast<id_set_t>(ThisEn) < NB);
    // reverse order would be : // ret |= (1 << (static_cast<id_set_t>(ThisEn) - NB));
    // We set the bit to 1 corresponding to the enum value.
    ret |= (1 << ((NB - 1) - static_cast<id_set_t>(ThisEn))); 
    to_bits_detail<NB>(ret, sequence::enum_t<EnumT, EnArgs...>{});
  }

export
template <std::size_t NB, typename EnSeqT>
id_set_t to_bits() {
  static_assert(8 >= NB);
  id_set_t ret = 0;
  to_bits_detail<NB>(ret, EnSeqT{});
  return ret;
}

// ==== contains runtime version
export
template <typename SeqT>
bool contains_rt(const typename SeqT::value_type val) noexcept {
  static constexpr auto seqArr = sequence::to_array_v<SeqT>;
  for (enum_uint_t i=0; i < SeqT::size(); ++i) {
    if (seqArr[i] == val) { return true; }
  }
  return false;
}

} // namespace util::sequence

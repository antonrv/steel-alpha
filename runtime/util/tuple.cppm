

export module SteelRT.Util.Tuple;

import SteelRT.Util.Sequence;

import SteelRT.Util.Types;


import <type_traits>;
import <cstdint>;
import <tuple>;

namespace util {


export
template <typename T1, typename T2>
struct pair_t {
  using first_type = T1;
  using second_type = T1;
};

namespace tuple {

export
template <typename TupleT>
struct is : std::false_type{};

export
template <typename... Ts>
struct is <tuple_t<Ts...>> : std::true_type{};

export
template <typename TupleT>
struct is_std : std::false_type{};

export
template <typename... Ts>
struct is_std <std::tuple<Ts...>> : std::true_type{};

// Whether it is a tuple_t olding std tuples or not
export
template <typename T>
struct is_holding_std : std::false_type {};

export
template <typename... StdTuples>
struct is_holding_std < tuple_t<StdTuples...> > {
  static constexpr bool value = std::conjunction_v< is_std<StdTuples> ... >;
};

export
template <typename T>
struct is_holding_typed : std::false_type {};

export
template <typename... Tuples>
struct is_holding_typed < tuple_t<Tuples...> > {
  static constexpr bool value = std::conjunction_v< is<Tuples> ... >;
};


///////////////////// size

  template <typename TupleT>
  struct size;
  
  template <typename... Ts>
  struct size <tuple_t<Ts...>>{
    static constexpr std::size_t value = sizeof...(Ts);
  };

export
template <typename TupleT>
inline constexpr std::size_t size_v = size<TupleT>::value;

///////////////////// empty
  export
  template <typename TupleT>
  struct empty;

  export
  template <typename... Ts>
  struct empty <tuple_t<Ts...>> {
    static constexpr bool value = ( sizeof...(Ts) == 0 );
  };

export
template <typename TupleT>
inline constexpr bool empty_v = empty<TupleT>::value;


///////////////////// element type

  template <std::size_t Id, typename TupleT>
  struct element;
  
  template <std::size_t Id, typename T>
  struct element< Id, tuple_t<T> > {
    using type = std::conditional_t<Id == 0, T, err_t>; // False case means error
  };
  
  template <std::size_t Id, typename T, typename... Ts>
  struct element< Id, tuple_t<T, Ts...> > {
    using type = std::conditional_t<Id == 0, T, typename element<Id - 1, tuple_t<Ts...>>::type>;
  };


  template <std::size_t Id, typename... Ts>
  struct element< Id, std::tuple<Ts...> > {
    using type = std::tuple_element_t< Id, std::tuple<Ts...> >;
  };

export
template <std::size_t Id, typename TupleT>
using element_t = typename element<Id, TupleT>::type;

///////////////////// as_std (ie tuple_t ---> std::tuple)


  template <typename TupleT>
  struct as_std;
  
  template <typename... Ts>
  struct as_std < tuple_t<Ts...> > {
    using type = std::tuple<Ts...>;
  };

export
template <typename TupleT>
using as_std_t = typename as_std<TupleT>::type;

///////////////////// as_types (ie std::tuple ---> tuple_t)

  template <typename TupleT>
  struct as_types;
  
  template <typename... Ts>
  struct as_types < std::tuple<Ts...> > {
    using type = tuple_t<Ts...>;
  };

export
template <typename TupleT>
using as_types_t = typename as_types<TupleT>::type;

// ==== lift_enums

  template <typename SequenceT, template <typename SequenceT::value_type> typename TemplT>
  struct lift_enums;
  
  template <typename ElemT, ElemT... ElemArgs, template <ElemT> typename TemplT>
  struct lift_enums<sequence::enum_t<ElemT, ElemArgs...>, TemplT> {
    using type = tuple_t< TemplT<ElemArgs> ... >;
  };

export
template <typename SequenceT, template <typename SequenceT::value_type> typename TemplT>
using lift_enums_t = typename lift_enums<SequenceT, TemplT>::type;

// ==== lift_bienums

  template <typename SequenceAT, typename SequenceBT, template <typename SequenceAT::value_type, typename SequenceBT::value_type> typename TemplT>
  struct lift_bienums;

  template <typename ElemAT, ElemAT... ElemArgsA, typename ElemBT, ElemBT... ElemArgsB, template <ElemAT, ElemBT> typename TemplT>
  struct lift_bienums<sequence::enum_t<ElemAT, ElemArgsA...>, sequence::enum_t<ElemBT, ElemArgsB...>, TemplT> {
    using type = tuple_t< TemplT<ElemArgsA, ElemArgsB> ... >;
  };

export
template <typename SequenceAT, typename SequenceBT, template <typename SequenceAT::value_type, typename SequenceBT::value_type> typename TemplT>
using lift_bienums_t = typename lift_bienums<SequenceAT, SequenceBT, TemplT>::type;


// ==== lift_types

  template <template <typename > typename TemplT, typename... Ts>
  struct lift_types;

  template <template <typename > typename TemplT, typename... Ts>
  struct lift_types {
    using type = tuple_t< TemplT<Ts> ... >;
  };

export
template <template <typename > typename TemplT, typename... Ts>
using lift_types_t = typename lift_types<TemplT, Ts...>::type;


// ==== lift (lift types of a tuple into a variadic-typed template)

  template <typename TupleT, template <typename > typename TemplT>
  struct lift;

  template <template <typename > typename TemplT, typename... Ts>
  struct lift< tuple_t<Ts...>, TemplT > {
    using type = lift_types_t< TemplT, Ts... >;
  };

  template <template <typename > typename TemplT, typename... Ts>
  struct lift< std::tuple<Ts...>, TemplT > {
    using type = as_std_t< lift_types_t< TemplT, Ts... > >;
  };

export
template <typename TupleT, template <typename > typename TemplT>
using lift_t = typename lift<TupleT, TemplT>::type;



// ==================== TUPLE CONTAINS

export
template <typename T, typename TupleType>
struct contains; // better not defined : std::false_type{};

export
template <typename T, typename... Ts>
struct contains<T, tuple_t<Ts...>> : std::disjunction<std::is_same<T, Ts>...> {};

export
template <typename T, typename TupleType>
inline constexpr bool contains_v = contains<T, TupleType>::value;

export
template <typename TupleT>
struct contains_pred {

  template <typename T>
  using type_value = contains<T, TupleT>;
};

// ====================== Tuple pair concatenation

  template <typename T, typename U>
  struct cat_pair;
  
  template <typename... TArgs, typename... UArgs>
  struct cat_pair<tuple_t<TArgs...>, tuple_t<UArgs...>> {
    using type = tuple_t<TArgs..., UArgs...>;
  };
  template <typename T1, typename T2, typename... UArgs>
  struct cat_pair<pair_t<T1, T2>, tuple_t<UArgs...>> {
    using type = tuple_t<T1, T2, UArgs...>;
  };
  template <typename T1, typename T2, typename... UArgs>
  struct cat_pair<tuple_t<UArgs...>, pair_t<T1, T2>> {
    using type = tuple_t<UArgs..., T1, T2>;
  };
  
  template <typename T1, typename... UArgs>
  struct cat_pair<T1, tuple_t<UArgs...>> {
    using type = tuple_t<T1, UArgs...>;
  };
  
  template <typename T1, typename TupB>
  using cat_pair_t = typename cat_pair<T1, TupB>::type;

// ========================= Tuple variadic concatenation

  template <typename... Args>
  struct cat_type;
  
  // identity
  template <typename... TArgs>
  struct cat_type<tuple_t<TArgs...>> {
    using type = tuple_t<TArgs...>;
  };
  
  // a pair
  template <typename T, typename U>
  struct cat_type<T, U> {
    using type = cat_pair_t<T, U>;
  };
  
  // several tuples
  template <typename T, typename U, typename... VArgs>
  struct cat_type<T, U, VArgs...> { 
    using type = typename cat_type< cat_pair_t<T, U>, VArgs... >::type;
  };

export
template <typename... Args>
using cat_t = typename cat_type<Args...>::type;


// ==================== LIFT AND FLATS

  template <typename SeqT, template <typename SeqT::value_type> typename TemplT>
  struct lift_enums_flat;
  
  template <typename ElemT, ElemT... ElemArgs, template <ElemT> typename TemplT>
  struct lift_enums_flat<sequence::enum_t<ElemT, ElemArgs...>, TemplT> {
    static_assert( is_holding_typed< tuple_t< TemplT<ElemArgs> ... > >::value );
    using type = cat_t< TemplT<ElemArgs> ... >;
  };

export
template <typename SeqT, template <typename SeqT::value_type> typename TemplT>
using lift_enums_flat_t = typename lift_enums_flat<SeqT, TemplT>::type;





// ==================== TUPLE FLATTENING

  template <typename T>
  struct flat;

  template <typename T>
  struct flat {
    using type = T;
  };

  template <typename... Args>
  struct flat <tuple_t<tuple_t<Args...>>> {
    using type = typename flat< tuple_t<Args...> >::type;
  };

export
template <typename T>
using flat_t = typename flat<T>::type;


// ==================== TUPLE UNIQUE

  template <typename T>
  struct unique;
  
  template <>
  struct unique<tuple_t<>> {
    using type = tuple_t<>;
  };

  template <typename T, typename... TArgs>
  struct unique<tuple_t<T, TArgs...>> {
  
    static constexpr bool is_in_tail = contains_v<T, tuple_t<TArgs...>>;
    using this_type = std::conditional_t<is_in_tail, tuple_t<>, tuple_t<T>>;
    using next_type = typename tuple::unique<tuple_t<TArgs...>>::type;
  
    using type = tuple::cat_t<this_type, next_type>;
  };

export
template <typename T>
using unique_t = typename unique<T>::type;

// ==================== TUPLE IS_UNIQUE

export
template <typename T>
inline constexpr bool is_unique_v = std::is_same_v< tuple::unique_t<T>, T >;

// ==================== TUPLE INTERSECT

  template <typename TupleA, typename TupleB>
  struct intersect;

  // End case
  template <typename TupleB>
  struct intersect< tuple_t<>, TupleB > {
    using type = tuple_t<>;
  };

  // General case
  template <typename TA, typename... TailA,
            typename TupleB>
  struct intersect<tuple_t<TA, TailA...>, TupleB> {
  
    using this_tuple = std::conditional_t<contains_v<TA, TupleB>, tuple_t<TA>, tuple_t<> >;
  
    using type = cat_t<
        this_tuple,
        typename intersect<tuple_t<TailA...>, TupleB>::type>;
  };

export
template <typename TupleA, typename TupleB>
using intersect_t = typename intersect<TupleA, TupleB>::type;


// =================================== FILTER_TUPLE_TYPES ACCORDING TO A PREDICATE AND RETURN THOSE IDS THAT SATISFY THE PRED

  template <std::size_t Idx, std::size_t N, typename TupleT, template <typename T> typename PredT>
  struct filter_ids_detail;
  
  template <std::size_t N, typename TupleT, template <typename T> typename PredT>
  struct filter_ids_detail<N, N, TupleT, PredT> {
    using type = sequence::index_t<>;
  };
  
  template <std::size_t Idx, std::size_t N, typename TupleT, template <typename T> typename PredT>
  struct filter_ids_detail {
    using this_seq =
      std::conditional_t<
        PredT<tuple::element_t<Idx, TupleT>>::value,
        sequence::index_t<Idx>,
        sequence::index_t<>
      >;
    using next_seq = typename filter_ids_detail<Idx+1, N, TupleT, PredT>::type;
  
    using type = sequence::cat_t<this_seq, next_seq>;
  };

export
template <typename TupleT, template <typename T> typename PredT>
using filter_ids_t = typename filter_ids_detail<0, tuple::size_v<TupleT>, TupleT, PredT>::type;

// =================================== FILTER_TUPLE_TYPES ACCORDING TO A PREDICATE AND RETURN ANOTHER TUPLE WITH TYPES SATISFYING THE PRED

  template <std::size_t Idx, std::size_t N, typename TupleT, template <typename T> typename PredT>
  struct filter_detail;
  
  template <std::size_t N, typename TupleT, template <typename T> typename PredT>
  struct filter_detail<N, N, TupleT, PredT> {
    using type = tuple_t<>;
  };
  
  template <std::size_t Idx, std::size_t N, typename TupleT, template <typename T> typename PredT>
  struct filter_detail {
    using this_tuple =
      std::conditional_t<
        PredT< tuple::element_t<Idx, TupleT> >::value,
        tuple_t< tuple::element_t<Idx, TupleT> >,
        tuple_t<>
      >;
    using next_tuple = typename filter_detail<Idx+1, N, TupleT, PredT>::type;
  
    using type = tuple::cat_t<this_tuple, next_tuple>;
  };

export
template <typename TupleT, template <typename T> typename PredT>
using filter_t = typename filter_detail<0, tuple::size_v<TupleT>, TupleT, PredT>::type;

// =================================== GET THE INDEX OF THE TYPE IN THE TUPLE

  template <std::size_t Idx, typename T, typename TupleT>
  struct index;
  
  template <std::size_t Idx, typename T>
  struct index <Idx, T, tuple_t<>> {
    static constexpr std::size_t value = Idx; // Error case
  };
  
  template <std::size_t Idx, typename T, typename HeadT, typename... Ts>
  struct index <Idx, T, tuple_t<HeadT, Ts...>> {
    static constexpr std::size_t value = std::is_same_v<T, HeadT> ? Idx : index<Idx + 1, T, tuple_t<Ts...>>::value;
  };

export
template <typename T, typename TupleT>
inline constexpr std::size_t index_v = index<0, T, TupleT>::value;


// ============= get indices of elements satisfying a predicate
  template <typename TupleT, typename IndexSeqT, template <typename T> class PredT >
  struct satisfy_indexes_detail;

  template <typename TupleT, template <typename T> class PredT >
  struct satisfy_indexes_detail <TupleT, sequence::index_t<> , PredT> {
    using type = sequence::index_t<>;
  };

  template <typename TupleT, std::size_t HeadId, std::size_t... TailIds, template <typename T> class PredT >
  struct satisfy_indexes_detail <TupleT, sequence::index_t<HeadId, TailIds...>, PredT> {
  
    using this_type = std::conditional_t< PredT<element_t<HeadId, TupleT>>::value, sequence::index_t< HeadId >, sequence::index_t<> >;

    using type = sequence::cat_t<
        this_type,
        typename satisfy_indexes_detail< TupleT, sequence::index_t<TailIds...>, PredT >::type
      >;
  };

export
template < typename TupleT, template <typename T> class PredT >
using satisfy_indexes_t = typename satisfy_indexes_detail< TupleT, sequence::make_index_t<size_v<TupleT>>, PredT >::type;



// =================================== MASK. Get another tuple with only the types referred in the indices

  template <typename TupleT, typename SeqIdxT>
  struct mask;

  template <typename TupleT, std::size_t... Ids>
  struct mask <TupleT, sequence::index_t<Ids...> > {
    using type = tuple_t< element_t<Ids, TupleT> ... >;
  };

export
template <typename TupleT, typename SeqIdxT>
using mask_t = typename mask<TupleT, SeqIdxT>::type;

// =================================== Filter

} // namespace tuple

} // namespace util

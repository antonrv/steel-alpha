
export module SteelRT.Util.Indexable;


import SteelRT.Util.Sequence;

export import <tuple>;

export import SteelRT.Util.Assert;
#include "assert.hpp"


export
namespace util {

template <typename SeqT, typename ContainerT>
class indexable {
protected:
  using seq_t = SeqT;

  using seq_value_t = typename SeqT::value_type;

  using container_t = ContainerT;

  using seq_array_t = sequence::to_array_t<seq_t>;

  static constexpr seq_array_t s_arrayIdx = sequence::to_array_v<seq_t>;

  container_t m_content;

public:
  // An enum sequence

  indexable() = default;
  indexable(const indexable& i) : m_content(i.m_content) {}


/////////////////////// getters
  // Non-const version
  template <seq_value_t Val>
  auto& get() noexcept {
    return std::get<sequence::get_index_v<SeqT, Val>>(m_content);
  }

  // Const version
  template <seq_value_t Val>
  const auto& get() const noexcept {
    return std::get<sequence::get_index_v<SeqT, Val>>(m_content);
  }

  
/////////////////////// setters
  template <seq_value_t Val, typename T>
  void set(T&& val) noexcept {
    std::get<sequence::get_index_v<SeqT, Val>>(m_content) = std::move(val);
  }

};


template <typename SeqT, typename ElemT>
class indexable_array : public indexable<SeqT, std::array<ElemT, SeqT::size()>> {

  using super_type = indexable<SeqT, std::array<ElemT, SeqT::size()>>;
  using seq_value_t = typename super_type::seq_value_t;
  using seq_array_t = typename super_type::seq_array_t;
public:

/////////////////////// getters

  auto& get_rt(const seq_value_t arrVal) noexcept { // macro optionally noexcept depending on NDEBUG TODO
    auto idx = sequence::get_index_rt<seq_array_t>::from_value(super_type::s_arrayIdx, arrVal);
    ensure(idx < super_type::m_content.size(), "Unreachable. Out of bounds");
    return super_type::m_content[ idx ];
  }

  const auto& get_rt(const seq_value_t arrVal) const noexcept {
    auto idx = sequence::get_index_rt<seq_array_t>::from_value(super_type::s_arrayIdx, arrVal);
    ensure(idx < super_type::m_content.size(), "Unreachable. Out of bounds");
    return super_type::m_content[ idx ];
  }

/////////////////////// setters

  void set_rt(const seq_value_t arrVal, ElemT&& newElem) noexcept {
    super_type::m_content[ sequence::get_index_rt<seq_array_t>::from_value(super_type::s_arrayIdx, arrVal) ] = std::forward<ElemT>(newElem);
  }
};


template <typename SeqA, typename SeqB, typename ElemT>
class indexable_2d_array : 
  public indexable <
      util::sequence::make_index_t< SeqA::size() * SeqB::size() >,
      std::array<ElemT, SeqA::size() * SeqB::size() >
    > 
{

  using super_type = indexable < util::sequence::make_index_t< SeqA::size() * SeqB::size() >, std::array<ElemT, SeqA::size() * SeqB::size() > >;

  using seq_value_a_t = typename SeqA::value_type;
  using seq_value_b_t = typename SeqB::value_type;

  using array_a_t = util::sequence::to_array_t< SeqA >;
  using array_b_t = util::sequence::to_array_t< SeqB >;

  static constexpr array_a_t s_arrayA = util::sequence::to_array_v< SeqA >;
  static constexpr array_b_t s_arrayB = util::sequence::to_array_v< SeqB >;

  static constexpr std::size_t seq_size_b = SeqB::size();

public:



  template <seq_value_a_t SeqValueA, seq_value_b_t SeqValueB>
  const auto& get() const noexcept {

    static constexpr std::size_t IdA = sequence::get_index_v<SeqA, SeqValueA>;
    static constexpr std::size_t IdB = sequence::get_index_v<SeqB, SeqValueB>;

    return std::get< seq_size_b * IdA + IdB >( super_type::m_content );
  }


  template <seq_value_a_t SeqValueA, seq_value_b_t SeqValueB>
  auto& get_ref() noexcept {

    static constexpr std::size_t IdA = sequence::get_index_v<SeqA, SeqValueA>;
    static constexpr std::size_t IdB = sequence::get_index_v<SeqB, SeqValueB>;

    return std::get< seq_size_b * IdA + IdB >( super_type::m_content );
  }


  template <seq_value_a_t SeqValueA, seq_value_b_t SeqValueB>
  void set( ElemT&& elem ) noexcept {

    static constexpr std::size_t IdA = sequence::get_index_v<SeqA, SeqValueA>;
    static constexpr std::size_t IdB = sequence::get_index_v<SeqB, SeqValueB>;

    std::get< seq_size_b * IdA + IdB  >( super_type::m_content ) = elem;
  }


  const auto& get_rt( seq_value_a_t seqValueA, seq_value_b_t seqValueB ) const noexcept {

    auto idA = sequence::get_index_rt< array_a_t >::from_value( s_arrayA, seqValueA );
    auto idB = sequence::get_index_rt< array_b_t >::from_value( s_arrayB, seqValueB );

    return super_type::m_content[ seq_size_b * idA + idB ];
  }
};


// template <typename SeqT, template <typename SeqT::value_type> typename TupleTemplT>
// class indexable_tuple : public indexable<SeqT, tuple::as_std_t< tuple::lift_enums_t<SeqT, TupleTemplT> > > {
// private:
// 
// public:
//   // TODO
// 
// };


template <typename SeqT, typename ElemT>
using indexable_array_t = indexable_array<SeqT, ElemT>;

// template <typename SeqT, template <typename SeqT::value_type> typename TupleTemplT>
// using indexable_tuple_t = indexable_tuple<SeqT, TupleTemplT>;

} // namespace util

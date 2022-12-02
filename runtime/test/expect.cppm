export module SteelRT.Test.Expect;

import SteelRT.Util.Types;
import SteelRT.Instrument.FwDeclarations;
// import SteelRT.Instrument.AllEvents;

import <string>;

namespace test {

export
enum class amount {more_than, more_or_equal_than, less_than, less_or_equal_than, equal, not_equal};

export
template <auto EnumVal, amount Am, unsigned Count = 0>
class expect {
private:
  const std::string m_eventStringToMatch;
  const std::string m_containedStr;

public:

  using event_type = decltype(EnumVal);
  static constexpr event_type event_value = EnumVal;

  static constexpr enum_type_id_t event_type_value = instr::event::type<event_type>::type_id;
  static constexpr unsigned expected_count = Count;

public:

  expect() :
    m_eventStringToMatch("event::" + std::string(instr::event::type<event_type>::name) + "::" + std::string(instr::event::value<event_value>::name))
  {}

  expect(std::string s) :
    m_eventStringToMatch("event::" + std::string(instr::event::type<event_type>::name) + "::" + std::string(instr::event::value<event_value>::name)),
    m_containedStr(s)
  {}

  bool matched_event(const std::string& line) const noexcept {
    return line.find(m_eventStringToMatch) != std::string::npos;
  }

  bool need_string_check() const noexcept {
    return not m_containedStr.empty();
  }

  bool check_string(const std::string& realLine) const noexcept {
    return realLine.find(m_containedStr) != std::string::npos;
  }

  const std::string& get_string() const noexcept {
    return m_containedStr;
  }


  bool check_number(const unsigned realCount) const noexcept {
    if constexpr (Am == amount::more_than) {
      return realCount > expected_count;
    } else if constexpr (Am == amount::more_or_equal_than) {
      return realCount >= expected_count;
    } else if constexpr (Am == amount::less_than) {
      return realCount < expected_count;
    } else if constexpr (Am == amount::less_or_equal_than) {
      return realCount <= expected_count;
    } else if constexpr (Am == amount::equal) {
      return realCount == expected_count;
    } else if constexpr (Am == amount::not_equal) {
      return realCount != expected_count;
    }
  }

  std::string compare_str() const noexcept {
    if constexpr (Am == amount::more_than) {
      return " more than ";
    } else if constexpr (Am == amount::more_or_equal_than) {
      return " more or equal than ";
    } else if constexpr (Am == amount::less_than) {
      return " less than ";
    } else if constexpr (Am == amount::less_or_equal_than) {
      return " less or equal than ";
    } else if constexpr (Am == amount::equal) {
      return " equal to ";
    } else if constexpr (Am == amount::not_equal) {
      return " not equal to ";
    }
  }

  const std::string& get_match_string() const noexcept {
    return m_eventStringToMatch;
  }
};

} // namespace test

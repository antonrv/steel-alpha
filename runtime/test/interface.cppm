export module SteelRT.Test;

export import SteelRT.Test.Expect;

export import SteelRT.Test.MockCtxt;

export import SteelRT.Instrument.AllEvents;

import SteelRT.Util.Types;


import <algorithm>;
import <string>;
import <tuple>;
import <stdexcept>;
import <optional>;
import <map>;
export import <vector>;
export import <numeric>;
export import <fstream>;


namespace test {

using line_no_t = unsigned;
using line_t = std::string;;
using reg_event_value_t = std::tuple<enum_type_id_t, enum_event_t, line_no_t, line_t>;
using opt_reg_event_value_t = std::optional<reg_event_value_t>;
using mapped_t = std::vector< reg_event_value_t >;
using key_event_type_t = enum_type_id_t;
using reg_map_t = std::map<key_event_type_t, mapped_t>;


template <typename ExpectT>
void validate_single(const mapped_t& mappedVals, const ExpectT& expected) {
  using EventT = typename ExpectT::event_type;

  /////////// Verify the expected number of events

  std::function<unsigned(unsigned cum, const reg_event_value_t&)> cumLambda;

  if (not expected.need_string_check()) {

    cumLambda = [](unsigned cum, const reg_event_value_t& reg) {
      if (std::get<enum_event_t>(reg) == static_cast<enum_event_t>(ExpectT::event_value)) {
        return cum + 1;
      } else {
        return cum;
      }
    };
  } else {
    cumLambda = [&expected](unsigned cum, const reg_event_value_t& reg) {
      if (std::get<enum_event_t>(reg) == static_cast<enum_event_t>(ExpectT::event_value) and expected.check_string(std::get<line_t>(reg))) {
        return cum + 1;
      } else {
        return cum;
      }
    };
  }

  auto totalEvents = std::accumulate(std::begin(mappedVals), std::end(mappedVals), 0, cumLambda);

  if (not expected.check_number(totalEvents)) {
    throw std::runtime_error("Testing:::Fail for " + expected.get_match_string() + ". Discrepancy : " + std::to_string(totalEvents) + " expected" + expected.compare_str() + std::to_string(ExpectT::expected_count));
  }

  // DEPRECATED. String check included in previous total event counting
  // /////////// If expected object initialized with a string, check occurrence of that string in the line. If not match, accumulate the wrong strings and throw an exception with them.
  // if (expected.need_string_check()) {
  //   auto checkStringLambda = [&expected](std::string notMatched, const reg_event_value_t& reg) {
  //     if (not expected.check_string(std::get<line_t>(reg))) {
  //       return notMatched + "\nIn line : " + std::get<line_t>(reg) + ", Expected match : " + expected.get_string();
  //     } else {
  //       return std::string();
  //     }
  //   };
  //   auto sumMismatches = std::accumulate(std::begin(mappedVals), std::end(mappedVals), std::string(), checkStringLambda);

  //   if (not sumMismatches.empty()) {
  //     throw std::runtime_error("Testing:::Fail for " + expected.get_match_string() + sumMismatches);
  //   }
  // }
}

template <typename TupleT, std::size_t... Ids>
void validate(const reg_map_t& scannedLogMap, const TupleT& expTuple, std::index_sequence<Ids...>) {
  ( validate_single(scannedLogMap.at(std::tuple_element_t<Ids, TupleT>::event_type_value), std::get<Ids>(expTuple)), ... );
}

template <typename ExpectT>
opt_reg_event_value_t match_event(const std::string& line, const line_no_t lineNo, const ExpectT& expect)
{
  if (expect.matched_event(line)) {
    return opt_reg_event_value_t( reg_event_value_t(ExpectT::event_type_value, static_cast<enum_event_t>(ExpectT::event_value), lineNo ,line) );
  }
  // Empty optional
  return opt_reg_event_value_t();
}

template <typename TupleT>
opt_reg_event_value_t find_match_event(const line_t& line, const line_no_t lineNo, const TupleT& expectTuple, std::index_sequence<>) {
  return opt_reg_event_value_t();
}

template <typename TupleT, std::size_t Id, std::size_t... Ids>
opt_reg_event_value_t find_match_event(const line_t& line, const line_no_t lineNo, const TupleT& expectTuple, std::index_sequence<Id, Ids...>) {
  auto retOpt = match_event(line, lineNo, std::get<Id>(expectTuple));
  if (retOpt.has_value()) {
    return retOpt;
  } else {
    return find_match_event(line, lineNo, expectTuple, std::index_sequence<Ids...>{});
  }
}

template <typename ExpectT>
void init_map( reg_map_t& scannedLogMap ) {
  scannedLogMap[ExpectT::event_type_value] = mapped_t();
}

// This is the single entry point
export
template <typename... ExpectationsT>
void validate_log(const std::string& logFn, ExpectationsT&&... expectations) {

  auto expTuple = std::make_tuple(expectations...);

  // Open file
  std::ifstream ifs(logFn.c_str());

  if (not ifs.is_open()) {
    throw std::runtime_error("Testing:::Could not open file " + logFn);
  }

  line_t line;

  reg_map_t scannedLogMap;
  ( init_map<ExpectationsT>(scannedLogMap), ... );

  using index_tuple = std::index_sequence_for<ExpectationsT...>;

  // Depending on decltypes of EnumVal of expectations, traverse the file gathering events of these types. Gathering also the lines (ordering)
  line_no_t lineNo = 0;
  while (std::getline(ifs, line)) {
    auto optTuple = find_match_event(line, lineNo++, expTuple, index_tuple{});
    if (optTuple.has_value()) {
      auto tupleVal = optTuple.value();
      scannedLogMap[std::get<0>(tupleVal)].push_back( tupleVal );
    } else {
      // This line has not matched against any expected events, so skip
    }
  }

  // Cross check previous with expTuple
  validate(scannedLogMap, expTuple, index_tuple{});
}


} // namespace test

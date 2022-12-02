#ifndef STEEL_COMPILER_GENERATION_ENUM_MAP_HPP
#define STEEL_COMPILER_GENERATION_ENUM_MAP_HPP

#include <string>
#include <tuple>
#include <set>
#include <map>

#include <algorithm>

namespace bld {


using key_str_t = std::string;
using enum_value_name_t = std::string;
using enum_value_def_t = std::string;
using value_t = std::pair<enum_value_name_t, enum_value_def_t>;
using values_t = std::set<value_t>;

using event_map_t = std::map<key_str_t, values_t>;


template <typename InputVecT, typename InsertFunT>
static
void insert_to_map(event_map_t& retMap, const std::string keyMap, const InputVecT& inputVec, InsertFunT&& insertFun) {

  if (retMap.find(keyMap) != retMap.end()) {
    throw std::logic_error("Key map already inserted : " + keyMap);
  }

  retMap.insert({keyMap, values_t()});

  values_t& fillSet = retMap.at(keyMap);

  std::transform( std::begin(inputVec), std::end(inputVec), std::inserter(fillSet, std::end(fillSet)), insertFun );
}


} // namespace bld

#endif // STEEL_COMPILER_GENERATION_ENUM_MAP_HPP

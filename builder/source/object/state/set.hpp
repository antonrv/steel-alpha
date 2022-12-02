#ifndef SOURCE_STATE_SET_HPP
#define SOURCE_STATE_SET_HPP

#include <algorithm>

namespace bld::src {



template <typename SetObjT, typename SoT>
unsigned get_position( const SetObjT& sobjSet, SoT sObj) {

  auto foundIt = std::find(std::begin(sobjSet), std::end(sobjSet), sObj);

  if (foundIt != std::end(sobjSet)) {
    return std::distance(std::begin(sobjSet), foundIt);
  } else {
    for (auto o : sobjSet) {
      std::cout << o->get_identifier() << '\n';
    }
    throw std::logic_error("Could not retrieve sobject id from " + sObj->get_identifier());
  }
}


template <typename SetObjT>
typename SetObjT::value_type
get_in_position(const SetObjT& elemSet, const unsigned id) {

  if (id >= elemSet.size()) {
    throw std::logic_error("Could not retrieve element " + std::to_string(id) + " from set of size " + std::to_string(elemSet.size()));
  }

  auto count = 0u;
  for (const auto& elem : elemSet) {
    if (count == id) { return elem; }
    ++count;
  }
  return nullptr;
}

} // namespace bld::src

#endif // SOURCE_STATE_SET_HPP

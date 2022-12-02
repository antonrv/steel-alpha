
#include "source/token/tokenize.hpp"

namespace bld::src::pc {

std::string maybe_erase_neg(const std::string& inputStr) {

  auto str = preprocess(inputStr);

  if (str[0] == '-') {
    return str.substr(1);
  } else {
    return str;
  }
}


} // namespace bld::src::pc


#include <string>

namespace bld {

void replace_keyword(std::string& targetStr, const char * kwToReplace, const std::string& newContent) {

  const auto len = std::string(kwToReplace).size();

  auto findPos = targetStr.find(kwToReplace);
  while (findPos != std::string::npos) {
    targetStr.replace(findPos, len, newContent);
    findPos = targetStr.find(kwToReplace, findPos + 1);
  }
}

} // namespace bld

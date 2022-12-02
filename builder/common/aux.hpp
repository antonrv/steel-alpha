#ifndef STEEL_COMPILER_COMMON_AUX_HPP
#define STEEL_COMPILER_COMMON_AUX_HPP

#include <vector>
#include <string>


namespace bld {

void clean(std::string& line, const char * specChars = " ,;./?!`\\-\"");

std::vector<std::string> split_string(const std::string& input, const char div);

void append_char(std::string& dir, char c);

} // namespace bld


#endif // STEEL_COMPILER_COMMON_AUX_HPP

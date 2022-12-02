#ifndef TOKENIZE_HPP
#define TOKENIZE_HPP

#include "source/token/typedef.hpp"


namespace bld::src::pc {


static const char * ErrStrParen = "parenthesis";
static const char * ErrStrUnbalancedParen = "Unbalanced parenthesis";
static const char * ErrStrUnmatchedParen = "Unmatched parenthesis";
static const char * ErrStrContiguousOp = "Contiguous operator chars";

unsigned find_rparen_pos(const std::string& inputStr, unsigned initPos = 0);
unsigned find_rbracket_pos(const std::string& inputStr, unsigned initPos = 0);

std::string preprocess(const std::string& str);

void clean_spaces(std::string& str);

unsigned get_nest_level(const std::string& str, unsigned pos);

std::vector<unsigned> filter_main_positions(const std::string& str, const std::vector<unsigned>& positions);

std::vector<unsigned> get_positions_of_char(const std::string& str, std::function<bool(char)>&& lambdaChar);

vec_string_t split_by_position(const std::string& input, const std::vector<unsigned>& positions);

template <kind Kind>
std::string get_token(const std::string& inputStr);

} // namespace bld::src::pc

#endif // TOKENIZE_HPP

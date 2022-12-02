
#include "source/token/tokenize.hpp"

#include <set>

#include <stdexcept>
#include <algorithm>

#include <iostream> // DBG XXX



namespace bld::src::pc {

static
void verify_legal_paren(const std::string& str, char openCh, char closeCh) {

  auto lParenPos = get_positions_of_char(str, [openCh] (char c) { return c == openCh; });
  auto rParenPos = get_positions_of_char(str, [closeCh] (char c) { return c == closeCh; });

  using open_t = bool;
  using pair_t = std::pair<unsigned, open_t>;

  std::set<pair_t> orderedParens;
  std::transform(std::begin(lParenPos), std::end(lParenPos), std::inserter(orderedParens, std::end(orderedParens)), [] (unsigned p) { return pair_t({p, true}); });
  std::transform(std::begin(rParenPos), std::end(rParenPos), std::inserter(orderedParens, std::end(orderedParens)), [] (unsigned p) { return pair_t({p, false}); });

  signed count = 0u;
  for (const auto& p : orderedParens) {
    count += std::get<open_t>(p) ? 1 : -1;
    if (count < 0) {
      throw std::runtime_error(std::string(ErrStrUnmatchedParen) + " in expr : " + str);
    }
  }

  if (count != 0) {
    throw std::runtime_error(std::string(ErrStrUnbalancedParen) + " in expr : " + str);
  }
}


static
void verify_legal(const std::string& str) {

  // if (str[0] == '*' or str[0] == '/') {
  //   throw std::runtime_error("Ilegal : " + str);
  // }
  verify_legal_paren(str, '(', ')');
  verify_legal_paren(str, '[', ']');
  

  // no two ops together
  const char * opStr = "+-*/";
  auto posOp = str.find_first_of(opStr);
  while (posOp != std::string::npos) {
    auto posOpNext = str.find_first_of(opStr, posOp + 1);
    if (posOpNext == posOp + 1 and (str[posOp] != str[posOpNext] or (str[posOp] == str[posOpNext] and str[posOp] != '+' and str[posOp] != '-'))) {
      throw std::runtime_error(std::string(ErrStrContiguousOp) + " in expr : " + str);
    }
    posOp = posOpNext;
  }
}


void clean_spaces(std::string& str) {

  // Erase white spaces
  auto pos = str.find(' ', 0);
  while (pos != std::string::npos) {
    str.erase(pos, 1);
    pos = str.find(' ', pos);
  }

  // Erase carriage return
  pos = str.find('\n', 0);
  while (pos != std::string::npos) {
    str.erase(pos, 1);
    pos = str.find('\n', pos);
  }
}

// static
// void clean_ampsnd(std::string& str) {
//   // Erase & chars
//   auto pos = str.find('&', 0);
//   while (pos != std::string::npos) {
//     str.erase(pos, 1);
//     pos = str.find('&', pos);
//   }
// }

unsigned get_nest_level(const std::string& str, unsigned pos) {
  auto nestLevel = 0u;
  // Compute nest level wrt parens
  for (auto p = 0u; p < pos; ++p) {
    if (str[p] == '(') { nestLevel++; }
    else if (str[p] == ')') { nestLevel--; }
  }
  // Compute nest level wrt brackets
  if (nestLevel == 0) {
    for (auto p = 0u; p < pos; ++p) {
      if (str[p] == '[') { nestLevel++; }
      else if (str[p] == ']') { nestLevel--; }
    }
  }
  return nestLevel;
}

///////// INTERFACE
std::vector<unsigned> filter_main_positions(const std::string& str, const std::vector<unsigned>& positions) {

  std::vector<unsigned> retPositions;

  std::copy_if(std::begin(positions), std::end(positions), std::back_inserter(retPositions), [str] (unsigned pos) { return get_nest_level(str,pos) == 0; } );

  return retPositions;
}


unsigned find_rparen_pos(const std::string& inputStr, unsigned initPos) {

  unsigned lvl = 1;

  auto nextPos = inputStr.find_first_of("()", initPos + 1);
  while (lvl > 0) {
    if (nextPos == std::string::npos) {
      throw std::runtime_error("Unbalanced parenthesis in find_rparen_pos " + inputStr + " from pos " + std::to_string(initPos));
    } else if (inputStr[nextPos] == '(') {
      lvl++;
    } else if (inputStr[nextPos] == ')') {
      lvl--;
    }
    if (lvl > 0) {
      nextPos = inputStr.find_first_of("()", nextPos + 1);
    }
  }
  return nextPos;
}

unsigned find_rbracket_pos(const std::string& inputStr, unsigned initPos) {

  unsigned lvl = 1;

  auto nextPos = inputStr.find_first_of("[]", initPos + 1);
  while (lvl > 0) {
    if (nextPos == std::string::npos) {
      throw std::runtime_error("Unbalanced brackets in find_rparen_pos " + inputStr + " from pos " + std::to_string(initPos));
    } else if (inputStr[nextPos] == '[') {
      lvl++;
    } else if (inputStr[nextPos] == ']') {
      lvl--;
    }
    if (lvl > 0) {
      nextPos = inputStr.find_first_of("[]", nextPos + 1);
    }
  }
  return nextPos;
}



static
std::string clean_main_parens(const std::string& inputStr) {
  std::string str = inputStr;

  // Erase main '(' or ')'
  bool erased = true;

  while (erased) {
    erased = false;
    if (str[0] == '(' and find_rparen_pos(inputStr) == str.size() - 1) {
      str.erase(str.size() - 1, 1);
      str.erase(0, 1);
      erased = true;
    }
  }
  return str;
}


////////// INTERFACE
std::vector<unsigned> get_positions_of_char(const std::string& str, std::function<bool(char)>&& lambdaChar) {

  std::vector<unsigned> positions;

  for (auto p = 0u; p < str.size(); ++p) {
    if (lambdaChar(str[p])) {
      positions.push_back(p);
    }
  }

  return positions;
}

////////// INTERFACE
vec_string_t split_by_position(const std::string& input, const std::vector<unsigned>& positions) {

  vec_string_t retStrings;

  auto pBefore = 0u;
  for (auto p : positions) {
    auto substr = input.substr(pBefore, p - pBefore);
    if (not substr.empty()) {
      retStrings.push_back( substr );
    }
    pBefore = p;
  }
  retStrings.push_back( input.substr(pBefore, input.size() - pBefore) );

  return retStrings;
}



////////////////////////
//
// INTERFACE (test)
//
////////////////////////
std::string preprocess(const std::string& str) {

  auto retStr = str;

  clean_spaces(retStr);

  // clean_ampsnd(retStr);

  auto prevStr = retStr;

  auto cpStr = clean_main_parens(retStr);

  while (cpStr != prevStr) {
    prevStr = cpStr;
    cpStr = clean_main_parens(prevStr);
  }

  verify_legal(cpStr);

  return cpStr;
}


template <>
std::string get_token<kind::num>(const std::string& inputStr) {
  return inputStr.substr(0, inputStr.find_first_not_of("0123456789u", 0) - 0);
}

template <>
std::string get_token<kind::var>(const std::string& inputStr) {
  return inputStr.substr(0, inputStr.find_first_not_of("01234567890_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 0));
}

} // namespace bld::src::pc

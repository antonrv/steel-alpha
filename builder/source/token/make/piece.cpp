

#include "source/token/make/piece.hpp"
#include "source/token/make/copy.hpp"
#include "source/token/make/token.hpp"


#include "source/token/tokenize.hpp"


#include <algorithm>
#include <functional>
#include <iostream>

namespace bld::src::pc {


static const char * OpsStr = "+-*/%";
static const char * VarStr = "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char * NumStr = "0123456789";

static const char * BinOpStr = "!=<>";
static const char * SqBrStr = "[]";

static
bool is_single_var(const std::string& str) {
  // Starts by _aA. Without any operator, without any BinOpStr
  return
    str.find_first_of(VarStr) == 0 and
    str.find_first_of(OpsStr) == std::string::npos and
    str.find_first_of(BinOpStr) == std::string::npos and
    str.find_first_of('(') == std::string::npos and
    str.find_first_of(',') == std::string::npos;
}

static
bool is_single_num(const std::string& str) {
  // Starts by 0-9. Without any operator. Can have u
  return str.find_first_of(NumStr) == 0 and str.find_first_of(OpsStr) == std::string::npos;
}

static
bool has_brackets(const std::string& inputStr) {
  auto openBraPos = inputStr.find("<");
  auto closeBraPos = inputStr.find(">");

  return openBraPos != std::string::npos and closeBraPos != std::string::npos and openBraPos < closeBraPos;
}

static
bool is_call(const std::string& str) {
  // Starts by _aA09, 
  auto strPos = str.find_first_of(VarStr);

  if (strPos != 0) {
    return false;
  }

  // followed by a '('
  auto nextParen = str.find_first_of('(', strPos+1);
  auto nextBinOp = str.find_first_of(BinOpStr, strPos+1);
  auto nextOp = str.find_first_of(OpsStr, strPos+1);
  auto nextSqBr = str.find_first_of(SqBrStr, strPos+1);

  return
    nextParen != std::string::npos and (
      // (has_brackets(str) and (nextParen < nextSqBr)) or we could detect fun<TemplParam>(args) as a call, but we need to allow kind::call objects to hold not a kind::var as the name. TODO
      ((not has_brackets(str)) and (nextParen < nextBinOp) and (nextParen < nextOp) and (nextParen < nextSqBr))
    );

}

static
bool is_negation(const std::string& str) {
  return str[0] == '-';
}

static
bool has_comma_separated_args(const std::string& str) {

  auto addSubPositions = get_positions_of_char( str, [] (char c) { return c == ','; } );

  for (auto pos : addSubPositions) {
    if (pos != 0 and get_nest_level(str, pos) == 0) {
      return true;
    }
  }
  return false;
}

static
bool has_main_addends(const std::string& str) {

  auto addSubPositions = get_positions_of_char( str, [] (char c) { return c == '+' or c == '-'; } );

  for (auto pos : addSubPositions) {
    if (pos != 0 and get_nest_level(str, pos) == 0) {
      return true;
    }
  }
  return false;
}

static
bool has_main_factors(const std::string& str) {

  auto mulPositions = filter_main_positions( str, get_positions_of_char( str, [] (char c) { return c == '*'; } ) );

  if (has_brackets(str)) { return false; }

  for (auto pos : mulPositions) {
    if (pos != 0) {
      return true;
    }
  }
  return false;
}

static
bool has_ampersand(const std::string& str) {
  return str.find('&') != std::string::npos;
}


static
bool is_division(const std::string& str) {

  // A single / or % operator. No * ops
  // Left side can be anything
  // Right side can be anything

  auto divPositions = filter_main_positions( str, get_positions_of_char( str, [] (char c) { return c == '/' or c == '%'; } ) );

  if (divPositions.size() != 1) {
    return false;
  }
  auto pos = divPositions.front();

  return pos != 0 and pos != str.size() - 1 and get_nest_level(str, pos) == 0;
}


static
bool is_binary(const std::string& inputStr) {

  auto hasOp = 
    (inputStr.find("==") != std::string::npos) or
    (inputStr.find("!=") != std::string::npos) or
    (inputStr.find("<=") != std::string::npos) or
    (inputStr.find("<")  != std::string::npos) or
    (inputStr.find(">=") != std::string::npos) or
    (inputStr.find(">")  != std::string::npos) or
    (inputStr.find("+=") != std::string::npos) or
    (inputStr.find("-=") != std::string::npos) or
    (inputStr.find("=")  != std::string::npos) or
    (inputStr.find("++") != std::string::npos) or
    (inputStr.find("--") != std::string::npos);

  if (hasOp and (inputStr.find("=")  == std::string::npos) and has_brackets(inputStr)) {
    // Has both < and >. Probably a template.
    return false;
  }
  return hasOp;
}

static
std::tuple<std::string, std::string, opkind>
get_binary_triple(const std::string& inputStr) {

  if (not is_binary(inputStr)) {
    throw std::runtime_error("Could not make a binary operator out of " + inputStr);
  }

  if (inputStr.find("==") != std::string::npos) {
    auto opPos = inputStr.find("==");
    return std::make_tuple( inputStr.substr(0, opPos), inputStr.substr(opPos + 2), opkind::eq );
  } else if (inputStr.find("!=") != std::string::npos) {
    auto opPos = inputStr.find("!=");
    return std::make_tuple( inputStr.substr(0, opPos), inputStr.substr(opPos + 2), opkind::neq );
  } else if (inputStr.find("<=") != std::string::npos) {
    auto opPos = inputStr.find("<=");
    return std::make_tuple( inputStr.substr(0, opPos), inputStr.substr(opPos + 2), opkind::leq );
  } else if (inputStr.find(">=") != std::string::npos) {
    auto opPos = inputStr.find(">=");
    return std::make_tuple( inputStr.substr(0, opPos), inputStr.substr(opPos + 2), opkind::geq );
  } else if (inputStr.find("+=") != std::string::npos) {
    auto opPos = inputStr.find("+=");
    return std::make_tuple( inputStr.substr(0, opPos), inputStr.substr(opPos + 2), opkind::incr );
  } else if (inputStr.find("-=") != std::string::npos) {
    auto opPos = inputStr.find("-=");
    return std::make_tuple( inputStr.substr(0, opPos), inputStr.substr(opPos + 2), opkind::decr );
  } else if (inputStr.find("=") != std::string::npos) {
    auto opPos = inputStr.find("=");
    return std::make_tuple( inputStr.substr(0, opPos), inputStr.substr(opPos + 1), opkind::assign );
  } else if (inputStr.find("<") != std::string::npos) {
    auto opPos = inputStr.find("<");
    return std::make_tuple( inputStr.substr(0, opPos), inputStr.substr(opPos + 1), opkind::lt );
  } else if (inputStr.find(">") != std::string::npos) {
    auto opPos = inputStr.find(">");
    return std::make_tuple( inputStr.substr(0, opPos), inputStr.substr(opPos + 1), opkind::gt );
  } else if (inputStr.find("++") != std::string::npos) {
    auto opPos = inputStr.find("++");
    return std::make_tuple( inputStr.substr(0, opPos), "1", opkind::incr );
  } else if (inputStr.find("--") != std::string::npos) {
    auto opPos = inputStr.find("--");
    return std::make_tuple( inputStr.substr(0, opPos), "-1", opkind::decr );
  } else {
    throw std::runtime_error("Could not infer operation kind in : " + inputStr);
  }

}


// Unify with is_call
static
bool has_square_brackets(const std::string& str) {

  // Starts by _aA09, 
  auto strPos = str.find_first_of(VarStr);


  if (strPos != 0) {
    return false;
  }

  // followed by a '['
  auto nextSqBracket = str.find_first_of('[', strPos+1);
  auto closeBracket = str.find_first_of(']', strPos+1);
  auto nextBinOp = str.find_first_of(BinOpStr, strPos+1);
  auto nextOp = str.find_first_of(OpsStr, strPos+1);
  auto nextSqBr = str.find_first_of(SqBrStr, nextSqBracket + 1);

  return
      (nextSqBracket != std::string::npos) and
      (nextSqBracket < nextBinOp) and
      (nextSqBracket < nextOp) and
      (nextSqBracket < nextSqBr) and
      (closeBracket == str.size() - 1);

}

static unsigned RecurseLevel = 0;

own_piece_t make_piece(std::string inputMakeStr) {

  RecurseLevel++;

  std::string indentStr(RecurseLevel*2, ' ');

  // std::cout << indentStr << "INP : " << inputMakeStr << '\n';

  const auto str = preprocess(inputMakeStr);

  own_piece_t retPiece;

  if (str.empty()) {

    retPiece = make_num(0);

  } else if (is_binary(str)) {


    auto [lhsStr, rhsStr, opk] = get_binary_triple(str);

    retPiece = make_token< kind::binop >(
        make_piece( lhsStr ),
        make_piece( rhsStr ),
        opk
      );

  } else if (is_call(str)) {


    auto parenOpenPos = str.find_first_of('(');
    auto parenClosePos = find_rparen_pos(str, parenOpenPos);
    if (parenClosePos != str.size() - 1) {
      throw std::logic_error("Expected make_piece kind::call but close paren in unexpected position : " + str);
    }
    auto argsStr = str.substr(parenOpenPos + 1, parenClosePos - (parenOpenPos + 1));

    if (argsStr.empty()) {
      retPiece = make_token< kind::call >( make_piece( str.substr(0, parenOpenPos) ) );
    } else {
      retPiece = make_token< kind::call >( make_piece( str.substr(0, parenOpenPos) ), make_piece(argsStr) );
    }

  } else if (has_comma_separated_args(str)) {


    auto commaPos = filter_main_positions( str, get_positions_of_char( str, [] (char c) { return c == ','; } ) );

    auto commaTokens = split_by_position(str, commaPos);

    for (auto& kind : commaTokens) { if (kind[0] == ',') { kind.erase(0,1); } }

    auto commaPcs = transform_vec( commaTokens, [] (const std::string& strTk) { return make_piece(strTk); } );


    retPiece = make_token< kind::cs_list >( std::move(commaPcs) );

  } else if (has_ampersand(str)) {

    auto withoutAddrStr = str.substr( str.find('&') + 1 );

    retPiece = make_token<kind::address>( make_piece(withoutAddrStr) );

  } else if (has_square_brackets(str)) {


    // auto sqBracketPositions = filter_main_positions( str, get_positions_of_char( str, [] (char c) { return c == '[' or c == ']'; } ) );

    // auto arrayTokens = split_by_position(str, sqBracketPositions);
    // arrayTokens[1].erase(0,1); // erase '['

    auto bracketOpenPos = str.find_first_of('[');
    auto bracketClosePos = find_rbracket_pos(str, bracketOpenPos);
    if (bracketClosePos != str.size() - 1) {
      throw std::logic_error("Expected make_piece kind::call but close bracket in unexpected position : " + str);
    }
    auto idxStr = str.substr(bracketOpenPos + 1, bracketClosePos - (bracketOpenPos + 1));


    retPiece = make_token< kind::offset >( make_piece( str.substr(0, bracketOpenPos) ), make_piece(idxStr) );


  } else if (is_single_var(str)) {


    retPiece = make_token< kind::var >( get_token<kind::var>(str) );

  } else if (is_single_num(str)) {


    retPiece = make_num( std::stoi( get_token<kind::num>(str) ) );


  } else if (has_main_addends(str)) {


    // Split +-, and for each make piece. Preserve -

    auto addSubPos = filter_main_positions( str, get_positions_of_char( str, [] (char c) { return c == '+' or c == '-'; } ) );

    auto addendTokens = split_by_position(str, addSubPos);

    for (auto& kind : addendTokens) { if (kind[0] == '+') { kind.erase(0,1); } } // Preserve -

    auto addendPcs = transform_vec( addendTokens, [] (const std::string& strTk) { return make_piece(strTk); } );

    retPiece = make_token< kind::addends >( std::move(addendPcs) );

  } else if (has_main_factors(str)) {

    // Split *, and for each make_piece.


    auto mulPos = filter_main_positions(str, get_positions_of_char( str, [] (char c) { return c == '*'; } ));

    auto factorTokens = split_by_position(str, mulPos);

    for (auto& kind : factorTokens) { if (kind[0] == '*') { kind.erase(0,1); } }

    auto factorPcs = transform_vec( factorTokens, [] (const std::string& strTk) { return make_piece(strTk); } );

    retPiece = make_token< kind::factors >( std::move(factorPcs) );

  } else if (is_division(str)) {


    auto divPos = filter_main_positions( str, get_positions_of_char( str, [] (char c) { return c == '/' or c == '%'; } ) );

    auto fracTokens = split_by_position(str, divPos);
    bool isMod = (fracTokens.back()[0] == '%');
    fracTokens.back().erase(0,1); // pop first '/' or '%'

    retPiece = make_token< kind::fraction >( make_piece(fracTokens.front()), make_piece(fracTokens.back()), isMod );

  } else if (is_negation(str)) {


    auto nextPc = make_piece(str.substr(1));

    nextPc->flip_sign();

    retPiece = std::move(nextPc);

  } else {

    retPiece = make_token< kind::undefined >( str );
    // throw std::logic_error("Unreachable. Cannot make piece from : " + str);
  }

  RecurseLevel--;

  // std::cout << indentStr << "OUT : " << retPiece->get_kind_str() << " : " << retPiece->get_pc_string() << "\n";

  return retPiece;
}

} // namespace bld::src::pc

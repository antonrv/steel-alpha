#include "source/serial/indent.hpp"

#include <stdexcept>

namespace bld::src {

unsigned indent_raii::IndentLevel = 0;

indent_raii::indent_raii() {
  IndentLevel++;
}
indent_raii::~indent_raii() {
  IndentLevel--;
}

std::string indent_raii::get_ind_str() {
  if (IndentLevel > 40) {
    throw std::logic_error("source serialization : Unexpected indent level : " + std::to_string(IndentLevel));
  }
  return std::string(IndentLevel*2, ' ');
}

std::string indent_raii::get_nl_ind_str() {
  if (IndentLevel > 40) {
    throw std::logic_error("source serialization : Unexpected indent level : " + std::to_string(IndentLevel));
  }
  return "\n" + get_ind_str();
}
std::string indent_raii::get_nl_str() {
  return "\n";
}


} // namespace bld::src 

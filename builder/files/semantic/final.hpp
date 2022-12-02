#ifndef STEEL_COMPILER_ELEMENT_FINAL_FILE_HPP
#define STEEL_COMPILER_ELEMENT_FINAL_FILE_HPP

#include "files/semantic/bitcode.hpp"

namespace bld {

// A final file is the output of the link stage, and could express either an executable or a library (dyn or static) TODO LINKLIB
// Probably we would need to add input link dependencies like a vector of cat::library in a final_file, when we have a way to express libraries as compilation targets and executables depending on them.

class final_file : public bitcode_file {
private:

public:

  final_file(const state::filename& fn) : bitcode_file(fn) {}
  final_file(const state::filename& fn, std::filesystem::file_time_type ftt) : bitcode_file(fn, ftt) {}

};

} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_FINAL_FILE_HPP

#ifndef STEEL_COMPILER_ELEMENT_FILE_BASE_HPP
#define STEEL_COMPILER_ELEMENT_FILE_BASE_HPP

#include "files/typedef.hpp"

#include "files/enum.hpp"

#include "files/name/decl.hpp"

#include <string>
#include <filesystem>

namespace bld {


class base_felement {
private:
  const std::string m_identifier;

  state::filename m_filename;
  std::filesystem::file_time_type m_lastModificationTime;

protected:

public:

  base_felement(const state::filename& fn);

  base_felement(const state::filename& fn, std::filesystem::file_time_type ftt);
  virtual ~base_felement() = 0;

  const std::string& get_identifier() const;
  const state::filename& get_filename() const;

  void update_modification_time();

  virtual const base_felement * get_poly_yield() const = 0;
};





} // namespace bld

#endif // STEEL_COMPILER_ELEMENT_FILE_BASE_HPP

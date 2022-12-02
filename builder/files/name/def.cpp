#include "files/name/decl.hpp"

#include <filesystem>

namespace bld {

  template <path_require PR>
  void satisfy(std::string dirStr);
 
} // namespace bld

namespace bld::state {

static
void simplify_path(std::string& fn) {
  const std::string dotsStr = "/../";
  const auto dotsSize = dotsStr.size();

  auto posDots = fn.find(dotsStr);
  while (posDots != std::string::npos) {
    auto prevDirPos = fn.rfind("/", posDots - 1);
    fn.replace(prevDirPos, posDots + dotsSize - prevDirPos, "/");

    posDots = fn.find(dotsStr);
  }
}


static
std::string make_tail_filename(key_path kp, std::string fn, path_require pr) {

  std::string relFn;
  if (pr == path_require::exist) {

    std::filesystem::path p(fn);

    auto fullFn = p.is_relative() ? get_pc_string_path(kp) + fn : fn;

    satisfy<path_require::exist>(fullFn);

    relFn = std::filesystem::relative(fullFn, get_pc_string_path(kp));

  } else if (pr == path_require::create) {

    auto fullFn = get_pc_string_path(kp) + fn;
    satisfy<path_require::create>(fullFn);
    satisfy<path_require::exist>(fullFn);

    relFn = std::filesystem::relative(fullFn, get_pc_string_path(kp));

  } else if (pr == path_require::none) {

    if (kp != key_path::undefined) {
      throw std::logic_error("Cannot make_tail_filename. Got path_require::none but root path is not undefined");
    }

    relFn = fn;

  } else {
    throw std::logic_error("Cannot make_tail_filename " + fn);
  }

  // std::cout << "Returning filename " << relFn << " from " << kp << " " << fn << " " << pr << '\n';
  return relFn;
}





filename::filename(key_path kp, std::string fn, path_require pr) :
  m_rootPathStr(get_pc_string_path(kp)),
  m_rootPath(kp),
  m_filename(make_tail_filename(kp, fn, pr))
{}

filename::filename(std::string kp, std::string fn, path_require pr) :
  m_rootPathStr(get_pc_string_path(get_key_path(kp))),
  m_rootPath(get_key_path(kp)),
  m_filename(make_tail_filename(m_rootPath, fn, pr))
{}


key_path filename::get_head() const {
  return m_rootPath;
}

std::string filename::get_head_str() const {
  return m_rootPathStr;
}

const std::string& filename::get_tail() const {
  return m_filename;
}

std::string filename::get_stem() const {
  return std::filesystem::path(m_filename).stem().string();
}

std::string filename::get_full_name() const {
  auto retFn = m_rootPathStr + m_filename;
  simplify_path(retFn);
  return retFn;
}

bool filename::operator==(const filename& other) const {
  return this->m_rootPathStr == other.m_rootPathStr and this->m_filename == other.m_filename;
}

bool filename::operator!=(const filename& other) const {
  return this->m_rootPathStr != other.m_rootPathStr or this->m_filename != other.m_filename;
}

} // namespace bld::state

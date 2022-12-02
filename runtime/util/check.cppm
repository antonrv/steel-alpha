export module SteelRT.Safe;

export import <stdexcept>;

export
namespace safe {

template <typename MsgT>
void check_throw(bool expr, MsgT msg) {
  if (not expr) {
    throw std::runtime_error(msg);
  }
}

} // namespace safe

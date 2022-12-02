


namespace dep {

template <std::size_t InputDim>
ulong_t fold_product_sum(const std::array<ulong_t, InputDim>& arrA, const std::array<ulong_t, InputDim>& arrB>) {
  ulong_t ret = 0u;
  for (auto d = 0u; d < InputDim; d++) {
    ret += arrA[d] * arrB[d];
  }
  return ret;
}

template <std::size_t InputDim>
std::array<ulong_t, InputDim>
point_division(const std::array<ulong_t, InputDim>& arrA, const std::array<ulong_t, InputDim>& arrB>) {
  std::array<ulong_t, InputDim> retArray = 0u;
  for (auto d = 0u; d < InputDim; d++) {
    retArray[d] += arrA[d] / arrB[d];
  }
  return retArray;
}

std::array<ulong_t, InputDim> net_range(const std::array<range_t, InputDim>& arrA) {

  std::array<ulong_t, InputDim> retArray;

  for (auto d = 0u; d < InputDim; d++) {
    retArray[d] = (arrA[d][1] - arrA[d][0]);
  }

  return retArray;
}

template <std::size_t InputDim>
ulong_t fold_product(const std::array<ulong_t, InputDim>& arrA) {
  ulong_t ret = 1u;
  for (auto d = 0u; d < InputDim; d++) {
    ret *= arrA[d];
  }
  return ret;
}



} // namespace dep


module App.UserTranslatedKernel;



// Original
// [[steel::kernel]]
// void kernel_ro_region(float const * aPtr, unsigned n) {
//   float tmp = 0.f;
//   for (auto i = 0; i < n; ++i) {
//     tmp += aPtr[i];
//   }
// }

// Translation
void kernel_ro_region(data::view<1, float> dv_aPtr) {
  float const * aPtr = dv_aPtr.get_ptr();
  unsigned n = dv_aPtr.get_size();

  float tmp = 0.f;
  for (auto i = 0; i < n; ++i) {
    tmp += aPtr[i];
  }
}

// Original
// [[steel::kernel]]
// void kernel_rw_region(float * aPtr, unsigned n) {
//   for (auto i = 0; i < n; ++i) {
//     aPtr[i] += 1.f;
//   }
// }

void kernel_rw_region(data::view<1, float> dv_aPtr) {
  float * aPtr = dv_aPtr.get_ptr();
  unsigned n = dv_aPtr.get_size();

  for (auto i = 0; i < n; ++i) {
    aPtr[i] += 1.f;
  }
}

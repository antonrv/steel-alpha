
[[steel::task("init_app")]]
void init_v0(float * res, float val) {
  res[0] = val;
}

void init_caller_v0( float * res, const unsigned n) {

  float val = 13;

  for (unsigned i = 0; i < n; i++) {
    init_v0( &res[i], val );
  }
}

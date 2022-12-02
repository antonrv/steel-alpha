
[[steel::task("callee_offset_app")]]
void callee_offset(float * bbb, int i) {
  float r;
  bbb[i] = r;
}

void caller_offset(float * ptr) {

  int a = 15;

  callee_offset( ptr, a );
}

[[steel::task("callee_no_offset_app")]]
void callee_no_offset(float * bbb) {
  float r;
  bbb[0] = r;
}

void caller_no_offset(float * ptr) {

  int a = 15;

  callee_no_offset( ptr );
}

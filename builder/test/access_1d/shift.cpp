
////
[[steel::task("foo_shift_literal")]]
void foo_shift_literal(const float * bbb) {
  float r;
  for (int ii = 0; ii < 42; ii++) {
    r = bbb[ii];
  }
}

void caller_shift_literal(int shift, const float * bbb) {
  float * ppp;
  foo_shift_literal( &ppp[shift] );
}

////
[[steel::task("foo_shift_start")]]
void foo_shift_start(const float * bbb, int sn) {
  float r;
  for (int ii = sn; ii < 42; ii++) {
    r = bbb[ii];
  }
}

void caller_shift_start(int shift, const float * bbb, int snCaller) {
  float * ppp;
  foo_shift_start( &ppp[shift], snCaller );
}

////
[[steel::task("foo_shift_end")]]
void foo_shift_end(const float * bbb, int en) {
  float r;
  for (int ii = 0; ii < en; ii++) {
    r = bbb[ii];
  }
}

void caller_shift_end(int shift, const float * bbb, int enCaller) {
  float * ppp;
  foo_shift_end( &ppp[shift], enCaller );
}


////
[[steel::task("foo_shift_start_end")]]
void foo_shift_start_end(const float * bbb, int sn, int en) {
  float r;
  for (int ii = sn; ii < en; ii++) {
    r = bbb[ii];
  }
}

void caller_shift_start_end(int shift, int snCaller, int enCaller) {
  float * ppp;
  foo_shift_start_end(&ppp[shift], snCaller, enCaller);
}

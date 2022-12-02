

//// 'foo' application
[[steel::task("foo")]]
void foo_k1(int a) { }

[[steel::task("foo")]]
void foo_k2(int a) { }

[[steel::task("foo")]]
void foo_d1(int a) {

  int param = a + 4;

  foo_k1(a); // call::foo_k1_c1 ---> call::foo_d1_foo_k1_0
}

[[steel::task("foo")]]
void foo_d2(int a) {

  int param = a + 27;

  foo_k2(a); // call::foo_k2_c ---> call::foo_d2_foo_k2_0

}

//// 'bar' application
[[steel::task("bar")]]
void bar_k(const int& a) { }

[[steel::task("bar")]]
void bar_d(const int& a) {

  bar_k(a); // call::bar_k_c ---> call::bar_d_bar_k_0
}

//// 'zee' application
[[steel::task("zee")]]
void zee_k(int& a) {
  a++;
}

[[steel::task("zee")]]
void zee_d(int& a) {

  zee_k(a); // call::zee_k_c ---> call::zee_d_zee_k_0
}

//// 'unb' application
[[steel::task("unb")]]
void unb_d(const int& param) {

  unb_d(param); // call::unb_d_c ---> call::unb_d_unb_d_0
}

// Just to instantiate the rest of the needed calls.
int main() {

  {
    int a;
    foo_k1(a); // call::foo_k1_c2 ---> call::main_entry_foo_k1_0
  }
  {
    int a;
    foo_d1(a); // call::foo_d1_c ---> call::main_entry_foo_d1_1
  }
  {
    int a;
    foo_d2(a); // call::foo_d2_c ---> call::main_entry_foo_d2_2
  }
  {
    int a;
    bar_d(a); // call::bar_d_c ---> call::main_entry_bar_d_3
  }
  {
    int a;
    zee_d(a); // call::zee_d_c ---> call::main_entry_zee_d_4
  }
}



// ----call
// foo_k1_c1 OK
// foo_k1_c2 MAIN
// foo_k2_c  OK
// foo_d1_c  MAIN
// foo_d2_c  MAIN
// bar_k_c   OK
// bar_d_c   MAIN
// zee_k_c   OK
// zee_d_c   MAIN
// unb_d_c   OK


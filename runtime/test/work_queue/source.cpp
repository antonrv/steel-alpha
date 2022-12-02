
[[steel::task("foo")]]
void foo_k(int a, float b, char c) {

}

[[steel::task("bar")]]
void bar_k(int a, float b, char c) {

}

[[steel::task("zee")]]
void zee_k(int a, float b, char c) {

}

[[steel::task("poison_pill")]]
void poison_pill_k(int a) {}

// Caller function just to instantiate the calls
int caller() {

  int a; float b; char c;

  foo_k(a, b, c);
  bar_k(a, b, c);
  zee_k(a, b, c);

  return 0;
}

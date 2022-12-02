

// [[steel::task]]
// void ent(int argc, const char ** argv) {
// 
// }

[[steel::task("foo")]]
void foo1(int a) {
  foo1(a);
}

[[steel::task("foo")]]
void foo2(int a) {
  foo2(a);
}

[[steel::task("bar")]]
void bar1(int a) {
  bar1(a);
}
[[steel::task("bar")]]
void bar2(int a) {
  bar2(a);
}
[[steel::task("zee")]]
void zee1(int a) {
  zee1(a);
}
[[steel::task("zee")]]
void zee2(int a) {
  zee2(a);
}

[[steel::task("poison_pill")]]
void poison_pill_k(int a) {

}

// [[steel::task("foo")]]
// void foo2(long int a) {
// 
// }
// 
// [[steel::task]]
// void bar(float f) {
// 
// }
// 
// [[steel::task]]
// void zee(std::string s) {
// 
// }

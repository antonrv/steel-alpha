[[steel::task("zeeapp")]]
void zee(int& a) {

  int c = 13;
  a = c;
}


[[steel::task("barapp")]]
void bar(int a) {

  int b = a;

  zee(b);
}

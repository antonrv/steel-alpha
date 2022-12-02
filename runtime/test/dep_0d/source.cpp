
[[steel::task("foo")]]
void kernel_foo_ro(int a) {
  // Reads a
}

[[steel::task("bar")]]
void kernel_bar_rw(int& a) {
  a += 1;
}

[[steel::task("kuu")]]
void kernel_kuu_wo(int& a) {
  a = 13;
}


int main() {
  {
    int a = 4;
    kernel_bar_rw(a); // bar_rw_unres -> main_entry_bar_0
    kernel_foo_ro(a); // foo_ro_unres -> main_entry_foo_1
  }

  {
    int a = 4;
    kernel_kuu_wo(a); // kuu_wo_unres -> main_entry_kuu_2
  }

  return 0;
}

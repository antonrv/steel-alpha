


#include <vector>

[[steel::task("foo")]]
void kernel_foo_ro(int a) {
}

[[steel::task("bar")]]
void kernel_bar_rw(int& a) {
  a += 1;
}

[[steel::task("zee")]]
void kernel_zee_ro_r(const int& a) {
  // do nothing
}

[[steel::task("kuu")]]
void kernel_kuu_wo(int& a) {
  a = 13;
}

[[steel::task("vii")]]
void kernel_vii_rw(std::vector<int>& a) {

  a.push_back(13);
  a.push_back(42);
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

  {
    std::vector<int> b;
    kernel_vii_rw(b); // vii_rw_unres -> main_entry_vii_3
  }

  {
    int a = 4;
    kernel_bar_rw(a); // bar_rw_unres -> main_entry_bar_4
    kernel_zee_ro_r(a); // zee_ro_unres_nonconst -> main_entry_zee_5
  }

  {
    const int a = 4;
    kernel_zee_ro_r(a); // zee_ro_unres -> main_entry_zee_6
  }

  {
    int a = 4;
    kernel_foo_ro(a); // foo_ro_res -> main_entry_foo_7
  }
  return 0;
}

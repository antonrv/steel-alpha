//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

[[steel::task("foo_ro_multiple_call_app")]]
void foo_ro_multiple(const float * bbb, int i) {
  float r;
  r = bbb[i];
}
[[steel::task("bar_ro_multiple_call_app")]]
void bar_ro_multiple(const float * bbb, int i) {
  float r;
  r = bbb[i];
}

task::coro::dispatcher<app::impl::caller1_ro_multiple_call> caller1_ro_multiple_call(task::attr::descriptor&  attrDesc) {
  int j = 4;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller1_ro_multiple_call_foo_ro_multiple_call_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/j), j);
  co_await task::make_async<app::call::caller1_ro_multiple_call_bar_ro_multiple_call_app_1>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/j), j);
  co_await task::make_async<app::call::caller1_ro_multiple_call_foo_ro_multiple_call_app_2>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/j), j);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller2_ro_multiple_call> caller2_ro_multiple_call(task::attr::descriptor&  attrDesc, int k) {
  int j = k;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller2_ro_multiple_call_foo_ro_multiple_call_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/j), j);
  co_await task::make_async<app::call::caller2_ro_multiple_call_bar_ro_multiple_call_app_1>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/j), j);
  co_await task::make_async<app::call::caller2_ro_multiple_call_foo_ro_multiple_call_app_2>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/j), j);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

[[steel::task("foo_rw_multiple_call_app")]]
void foo_rw_multiple_call(float * bbb, int i) {
  float r;
  bbb[i] = r;
}
[[steel::task("bar_rw_multiple_call_app")]]
void bar_rw_multiple_call(float * bbb, int i) {
  float r;
  bbb[i] = r;
}

task::coro::dispatcher<app::impl::caller1_rw_multiple_call> caller1_rw_multiple_call(task::attr::descriptor&  attrDesc) {
  int j = 4;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller1_rw_multiple_call_foo_rw_multiple_call_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/j), j);
  co_await task::make_async<app::call::caller1_rw_multiple_call_bar_rw_multiple_call_app_1>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/j), j);
  co_await task::make_async<app::call::caller1_rw_multiple_call_foo_rw_multiple_call_app_2>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/j), j);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller2_rw_multiple_call> caller2_rw_multiple_call(task::attr::descriptor&  attrDesc, int k) {
  int j = k;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller2_rw_multiple_call_foo_rw_multiple_call_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/j), j);
  co_await task::make_async<app::call::caller2_rw_multiple_call_bar_rw_multiple_call_app_1>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/j), j);
  co_await task::make_async<app::call::caller2_rw_multiple_call_foo_rw_multiple_call_app_2>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/j), j);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

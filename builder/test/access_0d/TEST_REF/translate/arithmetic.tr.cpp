//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

[[steel::task("foo_ro_arit_app")]]
void foo_ro_arit(const float * bbb, int i) {
  int ii = i + 3;
  float r;
  r = bbb[ii + 99 + 7*ii + 425];
}

task::coro::dispatcher<app::impl::caller_foo_ro_arit_1> caller_foo_ro_arit_1(task::attr::descriptor&  attrDesc) {
  int j = 11;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller_foo_ro_arit_1_foo_ro_arit_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/(548+(8*j))), j);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller_foo_ro_arit_2> caller_foo_ro_arit_2(task::attr::descriptor&  attrDesc, int k) {
  int j = k;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller_foo_ro_arit_2_foo_ro_arit_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/(548+(8*j))), j);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

[[steel::task("foo_rw_arit_app")]]
void foo_rw_arit(float * bbb, int i) {
  int ii = i + 3;
  float r;
  bbb[ii + 99 + 7*ii + 425] = r;
}

task::coro::dispatcher<app::impl::caller_foo_rw_arit_1> caller_foo_rw_arit_1(task::attr::descriptor&  attrDesc) {
  int j = 11;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller_foo_rw_arit_1_foo_rw_arit_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/(548+(8*j))), j);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller_foo_rw_arit_2> caller_foo_rw_arit_2(task::attr::descriptor&  attrDesc, int k) {
  int j = k;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller_foo_rw_arit_2_foo_rw_arit_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/(548+(8*j))), j);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

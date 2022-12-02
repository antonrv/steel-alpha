//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;
//// READ ONLY
[[steel::task("foo_ro_multiple_point_app")]]
void foo_ro_multiple_point(const float * bbb, int i) {
  float r;
  r = bbb[i];
}

task::coro::dispatcher<app::impl::caller1_ro_multiple_point> caller1_ro_multiple_point(task::attr::descriptor&  attrDesc) {
  int a = 15;
  int b = 23;
  int c = 37;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller1_ro_multiple_point_foo_ro_multiple_point_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/a), a);
  co_await task::make_async<app::call::caller1_ro_multiple_point_foo_ro_multiple_point_app_1>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/b), b);
  co_await task::make_async<app::call::caller1_ro_multiple_point_foo_ro_multiple_point_app_2>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/c), c);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller2_ro_multiple_point> caller2_ro_multiple_point(task::attr::descriptor&  attrDesc, int i, int j, int k) {
  int a = i;
  int b = j;
  int c = k;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller2_ro_multiple_point_foo_ro_multiple_point_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/a), a);
  co_await task::make_async<app::call::caller2_ro_multiple_point_foo_ro_multiple_point_app_1>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/b), b);
  co_await task::make_async<app::call::caller2_ro_multiple_point_foo_ro_multiple_point_app_2>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader(0, /*ds-off*/c), c);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}


//// READ WRITE
[[steel::task("foo_rw_multiple_point_app")]]
void foo_rw_multiple_point(float * bbb, int i) {
  float r;
  bbb[i] = r;
}

task::coro::dispatcher<app::impl::caller1_rw_multiple_point> caller1_rw_multiple_point(task::attr::descriptor&  attrDesc) {
  int a = 15;
  int b = 23;
  int c = 37;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller1_rw_multiple_point_foo_rw_multiple_point_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/a), a);
  co_await task::make_async<app::call::caller1_rw_multiple_point_foo_rw_multiple_point_app_1>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/b), b);
  co_await task::make_async<app::call::caller1_rw_multiple_point_foo_rw_multiple_point_app_2>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/c), c);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller2_rw_multiple_point> caller2_rw_multiple_point(task::attr::descriptor&  attrDesc, int i, int j, int k) {
  int a = i;
  int b = j;
  int c = k;
  float * ppp;
auto wrap_ppp = dep::wrap_region<0>(ppp);

  co_await task::make_async<app::call::caller2_rw_multiple_point_foo_rw_multiple_point_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/a), a);
  co_await task::make_async<app::call::caller2_rw_multiple_point_foo_rw_multiple_point_app_1>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/b), b);
  co_await task::make_async<app::call::caller2_rw_multiple_point_foo_rw_multiple_point_app_2>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer(0, /*ds-off*/c), c);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

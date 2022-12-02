//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;
//// READ ONLY
[[steel::task("foo_ro_multiple_point_app")]]
void foo_ro_multiple_point(const float * bbb, int s, int e) {
  float r;
  for (int i = s; i < e; i++) {
    r = bbb[i];
  }
}

task::coro::dispatcher<app::impl::caller_res_ro_multiple_point> caller_res_ro_multiple_point(task::attr::descriptor&  attrDesc) {
  int s1 = 15;
  int e1 = 18;
  int s2 = 23;
  int e2 = 26;
  int s3 = 33;
  int e3 = 39;
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::tree>(ppp, {/*embeds*/1});

  co_await task::make_async<app::call::caller_res_ro_multiple_point_foo_ro_multiple_point_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({s1, e1})}), s1, e1);
  co_await task::make_async<app::call::caller_res_ro_multiple_point_foo_ro_multiple_point_app_1>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({s2, e2})}), s2, e2);
  co_await task::make_async<app::call::caller_res_ro_multiple_point_foo_ro_multiple_point_app_2>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({s3, e3})}), s3, e3);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller_unres_ro_multiple_point> caller_unres_ro_multiple_point(task::attr::descriptor&  attrDesc, int s1Caller, int e1Caller, int s2Caller, int e2Caller, int s3Caller, int e3Caller) {
  int s1 = s1Caller;
  int e1 = e1Caller;
  int s2 = s2Caller;
  int e2 = e2Caller;
  int s3 = s3Caller;
  int e3 = e3Caller;
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::tree>(ppp, {/*embeds*/1});

  co_await task::make_async<app::call::caller_unres_ro_multiple_point_foo_ro_multiple_point_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({s1, e1})}), s1, e1);
  co_await task::make_async<app::call::caller_unres_ro_multiple_point_foo_ro_multiple_point_app_1>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({s2, e2})}), s2, e2);
  co_await task::make_async<app::call::caller_unres_ro_multiple_point_foo_ro_multiple_point_app_2>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({s3, e3})}), s3, e3);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

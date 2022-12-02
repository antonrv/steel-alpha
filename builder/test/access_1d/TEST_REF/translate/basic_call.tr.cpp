//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

////
[[steel::task("foo_whole_ro_app")]]
void foo_whole_ro(const float * bbb, int nn) {
  float r;
  for (int ii = 0; ii < nn; ii++) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_ro> caller_ro(task::attr::descriptor&  attrDesc, int nCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});

  int nCall = nCaller;
  co_await task::make_async<app::call::caller_ro_foo_whole_ro_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({0, nCall})}), nCall);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_portion_ro_app")]]
void foo_portion_ro(const float * bbb, int sn, int en) {
  float r;
  for (int ii = sn; ii < en; ii++) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_ro> caller_ro(task::attr::descriptor&  attrDesc, int snCaller, int enCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});

  int snCall = snCaller;
  int enCall = enCaller;
  co_await task::make_async<app::call::caller_ro_foo_portion_ro_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({snCall, enCall})}), snCall, enCall);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_whole_rw_app")]]
void foo_whole_rw(float * bbb, int nn) {
  float r;
  for (int ii = 0; ii < nn; ii++) {
    bbb[ii] = r;
  }
}

task::coro::dispatcher<app::impl::caller_rw> caller_rw(task::attr::descriptor&  attrDesc, int nCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});

  int nCall = nCaller;
  co_await task::make_async<app::call::caller_rw_foo_whole_rw_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_writer({/*coord*/0},{/*ranges*/range_t({0, nCall})}), nCall);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_portion_rw_app")]]
void foo_portion_rw(const float * bbb, int sn, int en) {
  float r;
  for (int ii = sn; ii < en; ii++) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_rw> caller_rw(task::attr::descriptor&  attrDesc, int snCaller, int enCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});

  int snCall = snCaller;
  int enCall = enCaller;
  co_await task::make_async<app::call::caller_rw_foo_portion_rw_app_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/0},{/*ranges*/range_t({snCall, enCall})}), snCall, enCall);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

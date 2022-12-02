//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

////
[[steel::task("foo_shift_literal")]]
void foo_shift_literal(const float * bbb) {
  float r;
  for (int ii = 0; ii < 42; ii++) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_shift_literal> caller_shift_literal(task::attr::descriptor&  attrDesc, int shift, const float * bbb) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});
  co_await task::make_async<app::call::caller_shift_literal_foo_shift_literal_0>(attrDesc.depth + 1,  wrap_ppp.emit_bnd_reader({/*coord*/shift},{/*ranges*/range_t({shift, (42+shift)})}) );

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_shift_start")]]
void foo_shift_start(const float * bbb, int sn) {
  float r;
  for (int ii = sn; ii < 42; ii++) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_shift_start> caller_shift_start(task::attr::descriptor&  attrDesc, int shift, const float * bbb, int snCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});
  co_await task::make_async<app::call::caller_shift_start_foo_shift_start_0>(attrDesc.depth + 1,  wrap_ppp.emit_bnd_reader({/*coord*/shift},{/*ranges*/range_t({(shift+snCaller), (42+shift)})}), snCaller );

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

////
[[steel::task("foo_shift_end")]]
void foo_shift_end(const float * bbb, int en) {
  float r;
  for (int ii = 0; ii < en; ii++) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_shift_end> caller_shift_end(task::attr::descriptor&  attrDesc, int shift, const float * bbb, int enCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});
  co_await task::make_async<app::call::caller_shift_end_foo_shift_end_0>(attrDesc.depth + 1,  wrap_ppp.emit_bnd_reader({/*coord*/shift},{/*ranges*/range_t({shift, (enCaller+shift)})}), enCaller );

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}


////
[[steel::task("foo_shift_start_end")]]
void foo_shift_start_end(const float * bbb, int sn, int en) {
  float r;
  for (int ii = sn; ii < en; ii++) {
    r = bbb[ii];
  }
}

task::coro::dispatcher<app::impl::caller_shift_start_end> caller_shift_start_end(task::attr::descriptor&  attrDesc, int shift, int snCaller, int enCaller) {
  float * ppp;
auto wrap_ppp = dep::wrap_region<1,dep::mesh::single>(ppp, {/*embeds*/1});
  co_await task::make_async<app::call::caller_shift_start_end_foo_shift_start_end_0>(attrDesc.depth + 1, wrap_ppp.emit_bnd_reader({/*coord*/shift},{/*ranges*/range_t({(shift+snCaller), (enCaller+shift)})}), snCaller, enCaller);

while (not dep::all_destroyable(wrap_ppp)) { co_await task::coro::suspend(); }
}

//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

[[steel::task("fooapp_3d")]]
void foo(float * ptr, const unsigned nX, const unsigned nY, const unsigned nZ, const unsigned localStrideY, const unsigned localStrideZ) {
  float init = 13;
  for (unsigned kk = 0; kk < nZ; kk++) {
    for (unsigned jj = 0; jj < nY; jj++) {
      for (unsigned ii = 0; ii < nX; ii++) {
        ptr[kk*localStrideZ*localStrideY + jj*localStrideY + ii] = init;
      }
    }
  }
}

task::coro::dispatcher<app::impl::caller1_foo> caller1_foo(task::attr::descriptor&  attrDesc, float * ptr, const unsigned nBlockX, const unsigned nBlockY, const unsigned nBlockZ, const unsigned bSizeX, const unsigned bSizeY, const unsigned bSizeZ) {
auto wrap_ptr = dep::wrap_region<3,dep::mesh::direct>(ptr, {/*embeds*/(bSizeX*bSizeY*nBlockX*nBlockY),(bSizeX*nBlockX),1}, {/*embeds*/bSizeZ,bSizeY,bSizeX}, {/*ranges*/range_t({0, nBlockZ}),range_t({0, nBlockY}),range_t({0, nBlockX})});

  for (unsigned bk = 0; bk < nBlockZ; bk++) {
    for (unsigned bj = 0; bj < nBlockY; bj++) {
      for (unsigned bi = 0; bi < nBlockX; bi++) {
        co_await task::make_async<app::call::caller1_foo_fooapp_3d_0>(attrDesc.depth + 1,  wrap_ptr.emit_bnd_writer({/*coord*/(bSizeZ*bk),(bSizeY*bj),(bSizeX*bi)},{/*ranges*/range_t({(bSizeZ*bk), (bSizeZ+(bSizeZ*bk))}),range_t({(bSizeY*bj), (bSizeY+(bSizeY*bj))}),range_t({(bSizeX*bi), (bSizeX+(bSizeX*bi))})}), bSizeX, bSizeY, bSizeZ, bSizeX*nBlockX, bSizeY*nBlockY );
      }
    }
  }

while (not dep::all_destroyable(wrap_ptr)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller2_foo> caller2_foo(task::attr::descriptor&  attrDesc, float * ptr, const unsigned nBlockX, const unsigned nBlockY, const unsigned nBlockZ, const unsigned bSizeX, const unsigned bSizeY, const unsigned bSizeZ) {
auto wrap_ptr = dep::wrap_region<3,dep::mesh::direct>(ptr, {/*embeds*/(bSizeX*bSizeY*nBlockX*nBlockY),(bSizeX*nBlockX),1}, {/*embeds*/bSizeZ,bSizeY,bSizeX}, {/*ranges*/range_t({0, nBlockZ}),range_t({0, nBlockY}),range_t({0, nBlockX})});

  unsigned strideY = bSizeX*nBlockX;
  unsigned strideZ = bSizeY*nBlockY;

  for (unsigned bk = 0; bk < nBlockZ; bk++) {
    for (unsigned bj = 0; bj < nBlockY; bj++) {
      for (unsigned bi = 0; bi < nBlockX; bi++) {
        co_await task::make_async<app::call::caller2_foo_fooapp_3d_0>(attrDesc.depth + 1,  wrap_ptr.emit_bnd_writer({/*coord*/((bSizeX*bSizeY*bSizeZ*bk*nBlockX*nBlockY)/(strideY*strideZ)),((bSizeX*bSizeY*bj*nBlockX)/strideY),(bSizeX*bi)},{/*ranges*/range_t({((bSizeX*bSizeY*bSizeZ*bk*nBlockX*nBlockY)/(strideY*strideZ)), (bSizeZ+((bSizeX*bSizeY*bSizeZ*bk*nBlockX*nBlockY)/(strideY*strideZ)))}),range_t({((bSizeX*bSizeY*bj*nBlockX)/strideY), (bSizeY+((bSizeX*bSizeY*bj*nBlockX)/strideY))}),range_t({(bSizeX*bi), (bSizeX+(bSizeX*bi))})}), bSizeX, bSizeY, bSizeZ, strideY, strideZ );
      }
    }
  }

while (not dep::all_destroyable(wrap_ptr)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller3_foo> caller3_foo(task::attr::descriptor&  attrDesc, float * ptr, const unsigned nBlockX, const unsigned nBlockY, const unsigned nBlockZ, const unsigned bSizeX, const unsigned bSizeY, const unsigned bSizeZ) {
auto wrap_ptr = dep::wrap_region<3,dep::mesh::direct>(ptr, {/*embeds*/(bSizeX*bSizeY*nBlockX*nBlockY),(bSizeX*nBlockX),1}, {/*embeds*/bSizeZ,bSizeY,bSizeX}, {/*ranges*/range_t({0, nBlockZ}),range_t({0, nBlockY}),range_t({0, nBlockX})});

  unsigned strideY = bSizeX*nBlockX;
  unsigned strideYZ = bSizeX*nBlockX*bSizeY*nBlockY;

  for (unsigned bk = 0; bk < nBlockZ; bk++) {
    for (unsigned bj = 0; bj < nBlockY; bj++) {
      for (unsigned bi = 0; bi < nBlockX; bi++) {
        co_await task::make_async<app::call::caller3_foo_fooapp_3d_0>(attrDesc.depth + 1,  wrap_ptr.emit_bnd_writer({/*coord*/((bSizeZ*bk*strideYZ)/(bSizeX*bSizeY*nBlockX*nBlockY)),((bSizeY*bj*strideY)/(bSizeX*nBlockX)),(bSizeX*bi)},{/*ranges*/range_t({((bSizeZ*bk*strideYZ)/(bSizeX*bSizeY*nBlockX*nBlockY)), (bSizeZ+((bSizeZ*bk*strideYZ)/(bSizeX*bSizeY*nBlockX*nBlockY)))}),range_t({((bSizeY*bj*strideY)/(bSizeX*nBlockX)), (bSizeY+((bSizeY*bj*strideY)/(bSizeX*nBlockX)))}),range_t({(bSizeX*bi), (bSizeX+(bSizeX*bi))})}), bSizeX, bSizeY, bSizeZ, bSizeX*nBlockX, bSizeY*nBlockY );
      }
    }
  }

while (not dep::all_destroyable(wrap_ptr)) { co_await task::coro::suspend(); }
}

task::coro::dispatcher<app::impl::caller4_foo> caller4_foo(task::attr::descriptor&  attrDesc, float * ptr, const unsigned nBlockX, const unsigned nBlockY, const unsigned nBlockZ, const unsigned bSizeX, const unsigned bSizeY, const unsigned bSizeZ) {
auto wrap_ptr = dep::wrap_region<3,dep::mesh::direct>(ptr, {/*embeds*/(bSizeX*bSizeY*nBlockX*nBlockY),(bSizeX*nBlockX),1}, {/*embeds*/bSizeZ,bSizeY,bSizeX}, {/*ranges*/range_t({0, nBlockZ}),range_t({0, nBlockY}),range_t({0, nBlockX})});

  unsigned strideY = bSizeX*nBlockX;
  unsigned strideYZ = bSizeX*nBlockX*bSizeY*nBlockY;

  for (unsigned bk = 0; bk < nBlockZ; bk++) {
    for (unsigned bj = 0; bj < nBlockY; bj++) {
      for (unsigned bi = 0; bi < nBlockX; bi++) {
        co_await task::make_async<app::call::caller4_foo_fooapp_3d_0>(attrDesc.depth + 1,  wrap_ptr.emit_bnd_writer({/*coord*/((bSizeZ*bk*strideYZ)/(bSizeY*nBlockY*strideY)),(bSizeY*bj),(bSizeX*bi)},{/*ranges*/range_t({((bSizeZ*bk*strideYZ)/(bSizeY*nBlockY*strideY)), (bSizeZ+((bSizeZ*bk*strideYZ)/(bSizeY*nBlockY*strideY)))}),range_t({(bSizeY*bj), (bSizeY+(bSizeY*bj))}),range_t({(bSizeX*bi), (bSizeX+(bSizeX*bi))})}), bSizeX, bSizeY, bSizeZ, strideY, bSizeY*nBlockY );
      }
    }
  }

while (not dep::all_destroyable(wrap_ptr)) { co_await task::coro::suspend(); }
}

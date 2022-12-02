//////////////////////////////////////
// 
// Translation file. Do not modify. 
// 
//////////////////////////////////////

module App.Proxy;

#include <vector>
#include <cstdlib> 

[[steel::task("matrix_allocate")]]
void allocate_matrix(float *& packMatrix, unsigned nRows, unsigned nCols) {
  packMatrix = static_cast<float*>(std::malloc(nRows*nCols*sizeof(float)));
  // packMatrix = (float*)std::malloc(nRows*nCols*sizeof(float)); HANDLE with pck::undefined TODO
}

[[steel::task("matrix_deallocate")]]
void deallocate_matrix(float * packMatrix) {
  std::free(packMatrix);
}

[[steel::task("mat_product_app")]]
void mat_product_v0_kernel_compact(
  float * outMat, float const * inMatA, float const * inMatB,
  unsigned mSize, unsigned nSize, unsigned kSize)
{
  for (unsigned mm = 0; mm < mSize; mm++) {
    for (unsigned nn = 0; nn < nSize; nn++) {
      for (unsigned kk = 0; kk < kSize; kk++) {
        outMat[mm * nSize + nn] += inMatA[mm * kSize + kk] * inMatB[kk * nSize + nn];
      }
    }
  }
}


[[steel::task("app_pack")]]
void pack_matrix(
  float * packMatrix, float const * unpackMatrix,
  unsigned nRows, unsigned nCols, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      packMatrix[jj*nCols + ii] = unpackMatrix[jj*stride + ii];
    }
  }
}

[[steel::task("app_unpack")]]
void unpack_matrix(
  float * unpackMatrix, float const * packMatrix,
  unsigned nRows, unsigned nCols, unsigned stride)
{
  for (unsigned jj = 0; jj < nRows; jj++) {
    for (unsigned ii = 0; ii < nCols; ii++) {
      unpackMatrix[jj*stride + ii] = packMatrix[jj*nCols + ii];
    }
  }
}


[[steel::task("mat_product_app")]] // [[steel::manage("mBlocks=divisor(mSize)")]] [[steel::manage("nBlocks=divisor(nSize)")]] [[steel::manage("kBlocks=divisor(kSize)")]]
task::coro::dispatcher<app::impl::mat_product_v3_block_compact> mat_product_v3_block_compact(task::attr::descriptor&  attrDesc, 
  float * outMat, float const * inMatA, float const * inMatB,
  unsigned mSize, unsigned nSize, unsigned kSize,
  unsigned mBlocks, unsigned nBlocks, unsigned kBlocks)
{
auto wrap_outMat = dep::wrap_region<2,dep::mesh::direct>(outMat, {/*embeds*/nSize,1}, {/*embeds*/(mSize/mBlocks),(nSize/nBlocks)}, {/*ranges*/range_t({0, mBlocks}),range_t({0, nBlocks})});
auto wrap_inMatA = dep::wrap_region<2,dep::mesh::direct>(inMatA, {/*embeds*/kSize,1}, {/*embeds*/(mSize/mBlocks),(kSize/kBlocks)}, {/*ranges*/range_t({0, mBlocks}),range_t({0, kBlocks})});
auto wrap_inMatB = dep::wrap_region<2,dep::mesh::direct>(inMatB, {/*embeds*/nSize,1}, {/*embeds*/(kSize/kBlocks),(nSize/nBlocks)}, {/*ranges*/range_t({0, kBlocks}),range_t({0, nBlocks})});

  std::vector<float*> outCompact;
  outCompact.resize(mBlocks*nBlocks);
  float ** outCompactPtr = outCompact.data();
auto wrap_outCompactPtr = dep::wrap_region<2,dep::mesh::direct>(outCompactPtr, {/*embeds*/nBlocks,1}, {/*embeds*/1,1}, {/*ranges*/range_t({0, mBlocks}),range_t({0, nBlocks})});

  std::vector<float*> inACompact;
  inACompact.resize(mBlocks*kBlocks);
  float ** inACompactPtr = inACompact.data();
auto wrap_inACompactPtr = dep::wrap_region<2,dep::mesh::direct>(inACompactPtr, {/*embeds*/kBlocks,1}, {/*embeds*/1,1}, {/*ranges*/range_t({0, mBlocks}),range_t({0, kBlocks})});

  std::vector<float*> inBCompact;
  inBCompact.resize(kBlocks*nBlocks);
  float ** inBCompactPtr = inBCompact.data();
auto wrap_inBCompactPtr = dep::wrap_region<2,dep::mesh::direct>(inBCompactPtr, {/*embeds*/nBlocks,1}, {/*embeds*/1,1}, {/*ranges*/range_t({0, kBlocks}),range_t({0, nBlocks})});

  unsigned mBlockSize = mSize / mBlocks;
  unsigned nBlockSize = nSize / nBlocks;
  unsigned kBlockSize = kSize / kBlocks;

  unsigned outStride = nBlockSize*nBlocks;
  unsigned inAStride = kBlockSize*kBlocks;
  unsigned inBStride = nBlockSize*nBlocks;

  ////////////
  //
  // MATRIX ALLOCATION
  //
  ////////////
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      co_await task::make_async<app::call::mat_product_v3_block_compact_matrix_allocate_0>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/mb,nb},{/*ranges*/range_t({mb, (1+mb)}),range_t({nb, (1+nb)})}), mBlockSize, nBlockSize );
    }
  }

  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned kb = 0; kb < kBlocks; kb++) {
      co_await task::make_async<app::call::mat_product_v3_block_compact_matrix_allocate_1>(attrDesc.depth + 1,  wrap_inACompactPtr.emit_bnd_writer({/*coord*/mb,kb},{/*ranges*/range_t({mb, (1+mb)}),range_t({kb, (1+kb)})}), mBlockSize, kBlockSize );
    }
  }

  for (unsigned kb = 0; kb < kBlocks; kb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      co_await task::make_async<app::call::mat_product_v3_block_compact_matrix_allocate_2>(attrDesc.depth + 1,  wrap_inBCompactPtr.emit_bnd_writer({/*coord*/kb,nb},{/*ranges*/range_t({kb, (1+kb)}),range_t({nb, (1+nb)})}), kBlockSize, nBlockSize );
    }
  }

  ////////////
  //
  // MATRIX PACKING
  //
  ////////////

  // OUT : Strided -> compact
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      co_await task::make_async<app::call::mat_product_v3_block_compact_app_pack_3>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/mb,nb},{/*ranges*/range_t({mb, (1+mb)}),range_t({nb, (1+nb)})}), wrap_outMat.emit_bnd_reader({/*coord*/(mBlockSize*mb),(nBlockSize*nb)},{/*ranges*/range_t({(mBlockSize*mb), (mBlockSize+(mBlockSize*mb))}),range_t({(nBlockSize*nb), (nBlockSize+(nBlockSize*nb))})}), mBlockSize, nBlockSize, outStride );
    }
  }

  // INA : Strided -> compact
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned kb = 0; kb < kBlocks; kb++) {
      co_await task::make_async<app::call::mat_product_v3_block_compact_app_pack_4>(attrDesc.depth + 1,  wrap_inACompactPtr.emit_bnd_writer({/*coord*/mb,kb},{/*ranges*/range_t({mb, (1+mb)}),range_t({kb, (1+kb)})}), wrap_inMatA.emit_bnd_reader({/*coord*/(mBlockSize*mb),(kBlockSize*kb)},{/*ranges*/range_t({(mBlockSize*mb), (mBlockSize+(mBlockSize*mb))}),range_t({(kBlockSize*kb), (kBlockSize+(kBlockSize*kb))})}), mBlockSize, kBlockSize, inAStride );
    }
  }

  // INB : Strided -> compact
  for (unsigned nb = 0; nb < nBlocks; nb++) {
    for (unsigned kb = 0; kb < kBlocks; kb++) {
      co_await task::make_async<app::call::mat_product_v3_block_compact_app_pack_5>(attrDesc.depth + 1,  wrap_inBCompactPtr.emit_bnd_writer({/*coord*/kb,nb},{/*ranges*/range_t({kb, (1+kb)}),range_t({nb, (1+nb)})}), wrap_inMatB.emit_bnd_reader({/*coord*/(kBlockSize*kb),(nBlockSize*nb)},{/*ranges*/range_t({(kBlockSize*kb), (kBlockSize+(kBlockSize*kb))}),range_t({(nBlockSize*nb), (nBlockSize+(nBlockSize*nb))})}), kBlockSize, nBlockSize, inBStride );
    }
  }

  ////////////
  //
  // MATRIX COMPACT BLOCK PRODUCT
  //
  ////////////
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      for (unsigned kb = 0; kb < kBlocks; kb++) {
        co_await task::make_async<app::call::mat_product_v3_block_compact_mat_product_app_6>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/mb,nb},{/*ranges*/range_t({mb, (1+mb)}),range_t({nb, (1+nb)})}), wrap_inACompactPtr.emit_bnd_reader({/*coord*/mb,kb},{/*ranges*/range_t({mb, (1+mb)}),range_t({kb, (1+kb)})}), wrap_inBCompactPtr.emit_bnd_reader({/*coord*/kb,nb},{/*ranges*/range_t({kb, (1+kb)}),range_t({nb, (1+nb)})}), mBlockSize, nBlockSize, kBlockSize );
      }
    }
  }


  ////////////
  //
  // MATRIX UNPACKING
  //
  ////////////

  // OUT : Compact -> strided
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      co_await task::make_async<app::call::mat_product_v3_block_compact_app_unpack_7>(attrDesc.depth + 1,  wrap_outMat.emit_bnd_writer({/*coord*/(mBlockSize*mb),(nBlockSize*nb)},{/*ranges*/range_t({(mBlockSize*mb), (mBlockSize+(mBlockSize*mb))}),range_t({(nBlockSize*nb), (nBlockSize+(nBlockSize*nb))})}), wrap_outCompactPtr.emit_bnd_reader({/*coord*/mb,nb},{/*ranges*/range_t({mb, (1+mb)}),range_t({nb, (1+nb)})}), mBlockSize, nBlockSize, outStride );
    }
  }

  ////////////
  //
  // MATRIX DEALLOCATION
  //
  ////////////
  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      co_await task::make_async<app::call::mat_product_v3_block_compact_matrix_deallocate_8>(attrDesc.depth + 1,  wrap_outCompactPtr.emit_bnd_writer({/*coord*/mb,nb},{/*ranges*/range_t({mb, (1+mb)}),range_t({nb, (1+nb)})}) );
    }
  }

  for (unsigned mb = 0; mb < mBlocks; mb++) {
    for (unsigned kb = 0; kb < kBlocks; kb++) {
      co_await task::make_async<app::call::mat_product_v3_block_compact_matrix_deallocate_9>(attrDesc.depth + 1,  wrap_inACompactPtr.emit_bnd_writer({/*coord*/mb,kb},{/*ranges*/range_t({mb, (1+mb)}),range_t({kb, (1+kb)})}) );
    }
  }

  for (unsigned kb = 0; kb < kBlocks; kb++) {
    for (unsigned nb = 0; nb < nBlocks; nb++) {
      co_await task::make_async<app::call::mat_product_v3_block_compact_matrix_deallocate_10>(attrDesc.depth + 1,  wrap_inBCompactPtr.emit_bnd_writer({/*coord*/kb,nb},{/*ranges*/range_t({kb, (1+kb)}),range_t({nb, (1+nb)})}) );
    }
  }

while (not dep::all_destroyable(wrap_outMat,wrap_inMatA,wrap_inMatB,wrap_outCompactPtr,wrap_inACompactPtr,wrap_inBCompactPtr)) { co_await task::coro::suspend(); }
}


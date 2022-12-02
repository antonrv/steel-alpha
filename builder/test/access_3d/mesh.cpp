
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

void caller1_foo(float * ptr, const unsigned nBlockX, const unsigned nBlockY, const unsigned nBlockZ, const unsigned bSizeX, const unsigned bSizeY, const unsigned bSizeZ) {

  for (unsigned bk = 0; bk < nBlockZ; bk++) {
    for (unsigned bj = 0; bj < nBlockY; bj++) {
      for (unsigned bi = 0; bi < nBlockX; bi++) {
        foo( &ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ + bj*bSizeX*nBlockX*bSizeY + bi*bSizeX], bSizeX, bSizeY, bSizeZ, bSizeX*nBlockX, bSizeY*nBlockY );
      }
    }
  }
}

void caller2_foo(float * ptr, const unsigned nBlockX, const unsigned nBlockY, const unsigned nBlockZ, const unsigned bSizeX, const unsigned bSizeY, const unsigned bSizeZ) {

  unsigned strideY = bSizeX*nBlockX;
  unsigned strideZ = bSizeY*nBlockY;

  for (unsigned bk = 0; bk < nBlockZ; bk++) {
    for (unsigned bj = 0; bj < nBlockY; bj++) {
      for (unsigned bi = 0; bi < nBlockX; bi++) {
        foo( &ptr[bk*bSizeX*nBlockX*bSizeY*nBlockY*bSizeZ + bj*bSizeX*nBlockX*bSizeY + bi*bSizeX], bSizeX, bSizeY, bSizeZ, strideY, strideZ );
      }
    }
  }
}

void caller3_foo(float * ptr, const unsigned nBlockX, const unsigned nBlockY, const unsigned nBlockZ, const unsigned bSizeX, const unsigned bSizeY, const unsigned bSizeZ) {

  unsigned strideY = bSizeX*nBlockX;
  unsigned strideYZ = bSizeX*nBlockX*bSizeY*nBlockY;

  for (unsigned bk = 0; bk < nBlockZ; bk++) {
    for (unsigned bj = 0; bj < nBlockY; bj++) {
      for (unsigned bi = 0; bi < nBlockX; bi++) {
        foo( &ptr[bk*strideYZ*bSizeZ + bj*strideY*bSizeY + bi*bSizeX], bSizeX, bSizeY, bSizeZ, bSizeX*nBlockX, bSizeY*nBlockY );
      }
    }
  }
}

void caller4_foo(float * ptr, const unsigned nBlockX, const unsigned nBlockY, const unsigned nBlockZ, const unsigned bSizeX, const unsigned bSizeY, const unsigned bSizeZ) {

  unsigned strideY = bSizeX*nBlockX;
  unsigned strideYZ = bSizeX*nBlockX*bSizeY*nBlockY;

  for (unsigned bk = 0; bk < nBlockZ; bk++) {
    for (unsigned bj = 0; bj < nBlockY; bj++) {
      for (unsigned bi = 0; bi < nBlockX; bi++) {
        foo( &ptr[bk*strideYZ*bSizeZ + bj*strideY*bSizeY + bi*bSizeX], bSizeX, bSizeY, bSizeZ, strideY, bSizeY*nBlockY );
      }
    }
  }
}

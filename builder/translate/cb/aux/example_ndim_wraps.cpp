
// ----
// Loop var: i
// Range : iRange
{
  for (int i = 0; i < iRange; i++) {
    a[i];
  }
}

// ----
// Loop var: i
// Range : iRange - 0 // From loop range
// Pad : jump // From i factor
// ----
// Loop var: j
// Range : jRange - 0 // From loop range
// Pad : iPad // From j factor
{
  for (int j = 0; j < jRange; j++) {
    for (int i = 0; i < iRange; i++) {
      a[i*jump + j*iPad];
    }
  }
}



foo(float a*, int iRange) {
  for (int i = 0; i < iRange; i++) {
    a[i];
  }
}

caller (float * a, int jRange) {

  dep::wrap_mesh<1>(a, {jRange}, {iPad}, /*Callee interval*/{0, iRange - 1});

  for (int j = 0; j < jRange; j++) {
    foo( &a[j*iPad], iRange ); // make_async<foo>( wrap_a.emit_bnd<1>(j), iRange );
  }
}

// ----
// Loop var: i
// Range : iRange - 0
// ----
// Loop var: j
// Range : jRange - 0 // From loop range
// Pad : iPad // From j factor
// ----
// Loop var: k
// Range : kRange - 0 // From loop range
// Pad : jPad*iPad // From k factor
{
  for (int k = 0; k < kRange; k++) {
    for (int j = 0; j < jRange; j++) {
      for (int i = 0; i < iRange; i++) {
        a[i*jump + j*iPad + k*iPad*jPad];
      }
    }
  }
}

/// calls foo ^
{
  auto wrap_a = dep::wrap_mesh<2>(a, {jRange, kRange}, {iPad, iPad*jPad}, /*Callee interval*/{0, iRange - 1});

  for (int k = 0; k < kRange; k++) {
    for (int j = 0; j < jRange; j++) {
      foo( &a[j*iPad + k*iPad*jPad], iRange ); // make_async<foo>( wrap_a.emit_bnd<2>(j,k), iRange );
    }
  }
}

bar(float * a, int jRange, int iRange) {
  for (int j = 0; j < jRange; j++) {
    for (int i = 0; i < iRange; i++) {
      a[i*jump + j*iPad + k*iPad*jPad];
    }
  }
}

{
  auto wrap_a = dep::wrap_mesh<1>(a, {kRange}, {iPad*jPad}, /*Callee interval*/ {0, iPad*jPad - 1});
  for (int k = 0; k < kRange; k++) {
    bar( &a[k*iPad*jPad], jRange, iRange ); // make_async<bar>( wrap_a.emit_bnd<1>(k), jRange, iRange );
  }
}



// ----
// Loop var: i
// Range : iRange - 0
// ----
// Loop var: j
// Range : jRange - 0 // From loop range
// Pad : iPad // From j factor
// ----
// Loop var: k
// Range : kRange - 0 // From loop range
// Pad : jPad*iPad // From k factor
// ----
// Loop var: l
// Range : lRange - 0 // From loop range
// Pad : iPad*jPad*kPad // From l factor
{
  for (int l = 0; l < lRange; l++) {
    for (int k = 0; k < kRange; k++) {
      for (int j = 0; j < jRange; j++) {
        for (int i = 0; i < iRange; i++) {
          a[i*jump + j*iPad + k*iPad*jPad + k*iPad*jPad*kPad];
        }
      }
    }
  }
}

// Total region : jump * iPad * jPad * kPad.
// Mesh : (0,iRange), (0,jRange), (0,kRange), (0,lRange)



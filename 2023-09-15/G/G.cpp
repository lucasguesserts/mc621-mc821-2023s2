#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

using N = long long int;

N find_initial_x(N p, N w, N d) {
  N p_mod = p % d;
  N w_mod = w % d;
  //   if ((p_mod == 0) && (w_mod == 0)) {
  //     return N(1); // any number work
  //   }
  for (N x = 0; x <= d; ++x) {
    if (p_mod == ((w_mod * (x % d)) % d)) {
      return x;
    }
  }
  throw 0;
}

N find_s(N n, N p, N w, N d, N x0) {
  N sy = static_cast<N>(ceil((d * n - x0 * (w - d) + p) / ((w - d) * d)));
  N sp = static_cast<N>(floor((p - w * x0) / (w * d)));
  N s = min(sp, sy);
  return s;
}

N compute_x(N x0, N d, N s) {
  N x = x0 + s * d;
  return x;
}

N compute_y(N p, N w, N d, N x) {
  N y = (p - w * x) / d;
  if (y < 0) {
    throw 0;
  }
  return y;
}

N compute_z(N n, N x, N y) {
  N z = n - x - y;
  if (z < 0) {
    throw 0;
  }
  return z;
}

int main() {
  N n, p, w, d;
  cin >> n >> p >> w >> d;
  try {
    N x0 = find_initial_x(p, w, d);
    N s = find_s(n, p, w, d, x0);
    N x = compute_x(x0, d, s);
    N y = compute_y(p, w, d, x);
    N z = compute_z(n, x, y);
    cout << x << " " << y << " " << z << endl;
  } catch (...) {
    cout << -1 << endl;
  }
  return 0;
}

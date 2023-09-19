#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

using N = std::int64_t;
using D = double;

void egcd(N a, N b, N &d, N &x, N &y) {
  // base case
  if (b == 0) {
    d = a;
    x = 1;
    y = 0;
    return;
  }
  egcd(b, a % b, d, x, y);
  N x1 = y;
  N y1 = x - (a / b) * y;
  x = x1;
  y = y1;
  return;
}

N nfloor(D x) { return static_cast<N>(std::floor(x)); }

N nceil(D x) { return static_cast<N>(std::ceil(x)); }

void failure() {
  cout << "failed" << endl;
  return;
}

int main() {
  while (true) {
    N n(0);
    N n1(0), n2(0);
    D c1(0), c2(0);
    N d(0), x(0), y(0);
    cin >> n;
    if (n == 0) {
      return 0;
    }
    cin >> c1 >> n1;
    cin >> c2 >> n2;
    egcd(n1, n2, d, x, y);
    if (n % d != 0) {
      failure();
      continue;
    }
    const N t = n / d;
    const D k_min = nceil(-(static_cast<D>(x) * n) / n2);
    const D k_max = nfloor((static_cast<D>(y) * n) / n1);
    if (k_max < k_min) {
      failure();
      continue;
    }
    N k(0);
    const D p1 = n1 / c1;
    const D p2 = n2 / c2;
    if (p1 <= p2) {
        k = k_min;
    } else {
        k = k_max;
    }
    const N m1 = t * x + n2 / d * k;
    const N m2 = t * y - n1 / d * k;
    cout << m1 << " " << m2 << endl;
  }
}

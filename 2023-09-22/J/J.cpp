#include <iostream>
#include <vector>

using namespace std;

using I = long long int;
using VI = vector<I>;

constexpr I M = 998244353;

void egcd(I a, I b, I &d, I &x, I &y) {
  if (b == 0) {
    d = a;
    x = 1;
    y = 0;
    return;
  }
  egcd(b, a % b, d, x, y);
  I x1 = y;
  I y1 = x - (a / b) * y;
  x = x1;
  y = y1;
  return;
}

I mod_inv(I a) {
    I d, x, y;
    egcd(a, M, d, x, y);
    return x;
}

VI mod_inv(VI A) {
    VI INV(A.size(), 1);
    for (I i = 0; i < A.size(); ++i) {
        INV[i] = mod_inv(A[i]);
    }
    return INV;
}

VI fact(I n) {
    VI N(n+1, I(1));
    for (I i = 1; i <= n; ++i) {
        N[i] = (i * N[i - 1]) % M;
    }
    return N;
}

int main () {
    I n, k;
    cin >> n >> k;
    if (n < k) {
        cout << 0 << endl;
        return 0;
    }
    // n >= k
    auto FACT = fact(n);
    auto FACT_INV = mod_inv(FACT);
    I solution = 0;
    for (I m = 1; m <= n; ++m) {
      I c = n / m;
      if (c < k) {
        continue;
      }
      I p = FACT[c - 1];
      p *= FACT_INV[k - 1];
      p %= M;
      p *= FACT_INV[c - k];
      p %= M;
      solution += p;
      solution %= M;
    }
    if (solution < 0) {
        solution = (solution + M) % M;
    }
    cout << solution << endl;
    return 0;
}

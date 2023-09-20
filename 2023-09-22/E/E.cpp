#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using I = long long int;
using VI = vector<I>;

constexpr I M = 1000000007; // prime number

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

VI mod_inv(const VI &A) {
  VI INV(A.size(), 1);
  for (I i = 0; i < A.size(); ++i) {
    INV[i] = mod_inv(A[i]);
  }
  return INV;
}

VI fact(I n) {
  VI N(n + 1, I(1));
  for (I i = 1; i <= n; ++i) {
    N[i] = (i * N[i - 1]) % M;
  }
  return N;
}

void print(const VI &A) {
  for (const auto &a : A) {
    cout << a << ", ";
  }
  cout << endl;
}

int main() {
  I t;
  cin >> t;
  while (t--) {
    // data
    I n, k;
    cin >> n >> k;
    VI A;
    for (I i = 0; i < n; ++i) {
      I a;
      cin >> a;
      A.push_back(a);
    }
    // A, F, S
    //// A
    std::sort(A.begin(), A.end(),
              std::greater<>()); // sort A weakely decreasing
    //// F
    VI F;
    I ak = A[k - 1];
    auto it = A.begin();
    while ((*it != ak) && (it != A.end())) {
      F.push_back(*it);
      ++it;
    }
    //// S
    VI S;
    while ((*it == ak) && (it != A.end())) {
      S.push_back(*it);
      ++it;
    }
    // solution
    I phi = k - F.size();
    I sigma = S.size();
    auto FAC = fact(sigma);
    auto FACINV = mod_inv(FAC);
    I x = 1;
    x *= FAC[sigma];
    x %= M;
    x *= FACINV[sigma - phi];
    x %= M;
    x *= FACINV[phi];
    x %= M;
    if (x < 0) {
      x += 2 * M;
    }
    x %= M;
    cout << x << endl;
  }
  return 0;
}

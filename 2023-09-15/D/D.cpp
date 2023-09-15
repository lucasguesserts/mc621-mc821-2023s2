#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

using N = long int;
using VN = vector<N>;
using VVN = vector<vector<N>>;
using VB = vector<bool>;
using MN = map<N, N>;

N int_sqrt(N x) { return static_cast<N>(floor(sqrt(x))); }

N gcd(N x, N y) { return y == 0 ? x : gcd(y, x % y); }
N gcd(VN &A) {
  N x = A[0];
  N g = x;
  for (auto y : A) {
    g = gcd(g, y);
  }
  return g;
}

VN SoE(N n) {
  VN primes;
  VB numbers(n+1, true);
  numbers[0] = numbers[1] = false;
  for (auto i = 2; i <= n; ++i) {
    if (numbers[i]) {
      primes.push_back(i);
      for (auto j = i * i; j <= n; j += i) {
        numbers[j] = false;
      }
    }
  }
  return primes;
}

VN prime_factors(N x, VN &primes) {
  VN f;
  for (auto p : primes) {
    if (x % p == 0) {
      f.push_back(p);
      while (x % p == 0) {
        x /= p;
      }
    }
  }
  if (x != 1) {
    f.push_back(x);
  }
  return f;
}

MN count_factors(VVN & fs) {
  MN m;
  for (auto &f : fs) {
    for (auto &p : f) {
      if (m.count(p) == 0) {
        m[p] = 1;
      } else {
        m[p] += 1;
      }
    }
  }
  return m;
}

N max_count_present(MN & m) {
    N maximum = -1;
    for (auto & v : m) {
        maximum = max(maximum, v.second);
    }
    return maximum;
}

int main() {
  // data
  N n;
  VN A;
  // input
  cin >> n;
  A.reserve(n);
  for (auto i = 0; i < n; ++i) {
    N a;
    cin >> a;
    A.push_back(a);
  }
  // solution
  N g = gcd(A);
  transform(A.begin(), A.end(), A.begin(), [&g](N x) { return x / g; });
  g = gcd(A);
  N m = *max_element(A.begin(), A.end());
  N sieve_size = int_sqrt(m);
  VN primes = SoE(sieve_size);
  VVN fs;
  transform(A.begin(), A.end(), back_inserter(fs),
            [&primes](N x) { return prime_factors(x, primes); });
  MN fm = count_factors(fs);
  N most_present_factor_count = max_count_present(fm);
  // output
  N ans = most_present_factor_count == -1
    ? -1
    : n - most_present_factor_count;
  cout << ans << endl;
  return 0;
}

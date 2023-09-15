#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

using N = long long int;
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
  VB numbers(n + 1, true);
  numbers[0] = numbers[1] = false;
  for (auto i = N(2); i <= n; ++i) {
    if (numbers[i]) {
      primes.push_back(i);
      for (auto j = i * i; j <= n; j += i) {
        numbers[j] = false;
      }
    }
  }
  return primes;
}

N count_max_present_prime(VN &primes, VN &A) {
  N maximum = 0;
  for (auto &p : primes) {
    N count = 0;
    for (auto &a : A) {
      if (a % p == 0) {
        ++count;
      }
    }
    maximum = max(maximum, count);
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
  for (auto i = N(0); i < n; ++i) {
    N a;
    cin >> a;
    A.push_back(a);
  }
  // solution
  N g = gcd(A);
  transform(A.begin(), A.end(), A.begin(), [&g](N x) { return x / g; });
  N m = *max_element(A.begin(), A.end());
  VN primes = SoE(m+N(1));
  N most_present_factor_count = count_max_present_prime(primes, A);
  // output
  N answ = most_present_factor_count == 0 ? -1 : n - most_present_factor_count;
  cout << answ << endl;
  return 0;
}

#include <iostream>

using namespace std;

using N = long long int;

N find_smallest_divisor(N n) {
  for (N i = 1; i <= n; ++i) {
    if (n % i != 0) {
      return i - 1;
    }
  }
  return n;
}

int main() {
  N t;
  cin >> t;
  while (t--) {
    N n;
    cin >> n;
    N x = find_smallest_divisor(n);
    cout << x << endl;
  }
  return 0;
}

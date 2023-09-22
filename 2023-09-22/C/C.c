#include <stdio.h>

int main() {
  long long int n = 0;
  long long int digits;
  long long int mod;
  while (scanf("%lld", &n) == 1) {
    digits = 1;
    mod = 1 % n;
    while (mod != 0) {
      ++digits;
      mod = (mod * 10 + 1) % n;
    }
    printf("%lld\n", digits);
  }
  return 0;
}

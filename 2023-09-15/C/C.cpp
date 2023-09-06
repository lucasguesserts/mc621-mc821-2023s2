#include <iostream>
#include <bitset>
#include <vector>
#include <cstdint>

#define MAX_SIEVE_SIZE     33000    // > SQRT(MAXN) 

using namespace std;

vector<uint32_t>        _primes;
uint32_t                _sieve_size;
bitset<MAX_SIEVE_SIZE>  _is_prime;

void sieve(uint32_t sieve_limit) {
    _sieve_size = sieve_limit + 1;
    _is_prime.set();
    _is_prime[0] = _is_prime[1] = 0;
    for (uint32_t i = 0; i < _sieve_size; i++) {
        if (!_is_prime[i]) continue;
        _primes.push_back(i);
        for (uint32_t j = i*i; j < _sieve_size; j += i) _is_prime[j] = 0;
    }
}

/* Returns smallest prime divisor of n (n > 1).
 *
 * Requires having ran sieve up to sqrt(n) at least.
**/
uint32_t first_divisor(uint32_t n) {
    for (auto p : _primes) {
        if (p > n) break;
        if (n % p == 0)
            return p;
    }
    return n; // n is prime
}

/* Returns the biggest divisor of n, assuming n > 1. */
uint32_t biggest_divisor(uint32_t n) {
    return n/first_divisor(n);
}

int main() {
    sieve(MAX_SIEVE_SIZE);
    uint32_t n, ans;
    cin >> n;
    ans = (n == 1)? 0 : n - biggest_divisor(n);
    cout << ans << endl;

    return 0;
}

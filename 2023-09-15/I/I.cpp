#include <iostream>
#include <bitset>
#include <vector>
#include <cstdint>

#define MAX_SIEVE_SIZE      35000   // > SQRT(MAXN)

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

uint32_t count_prime_factors(uint32_t n) {
    uint32_t count = 0;
    for (auto p : _primes) {
        while (n % p == 0) {
            n /= p;
            count++;
        }
    }
    return (n != 1) ? count + 1 : count;
}

int main() {
    sieve(MAX_SIEVE_SIZE);
    uint32_t n;
    cin >> n;
    cout << count_prime_factors(n) << endl;
    return 0;
}

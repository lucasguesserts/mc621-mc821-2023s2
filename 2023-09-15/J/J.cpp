#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>

#define MAX_SIEVE_SIZE 10000001 // sieve up to 10^7

using namespace std;

vector<uint32_t> _primes;
uint32_t _sieve_size;
bitset<MAX_SIEVE_SIZE> _is_prime;

void sieve(uint32_t sieve_limit) {
    _sieve_size = sieve_limit + 1;
    _is_prime.set();
    _is_prime[0] = _is_prime[1] = 0;
    for (uint32_t i = 0; i < _sieve_size; i++) {
        if (!_is_prime[i]) continue;
        _primes.push_back(i);
        for (uint32_t j = i * i; j < _sieve_size; j += i)
            _is_prime[j] = 0;
    }
}

bool is_prime(uint64_t n) {
    if (n < _sieve_size) return (bool)_is_prime[n];
    for (auto p : _primes)
        if (!(n % p)) return false;
    return true;
}

uint32_t totient(uint32_t n) {
    uint32_t count = n;
    uint32_t original_n = n;
    for (auto p : _primes) {
        if (p * p > original_n) break;
        if (n % p == 0) count = count - count / p;
        while (n % p == 0)
            n = n / p;
    }
    if (n > 1) count = count - count / n;
    return count;
}

int main() {
    sieve(1 << 15);
    uint32_t n;
    while ((cin >> n) && n)
        cout << totient(n) << endl;

    return 0;
}

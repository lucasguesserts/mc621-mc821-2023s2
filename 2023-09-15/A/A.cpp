#include <iostream>
#include <bitset>
#include <vector>
#include <cstdint>

#define MAX_SIEVE_SIZE      40000   // > SQRT(MAXN) 

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

bool is_prime(uint64_t n) {
    if (n < _sieve_size) return _is_prime[n];
    for (auto p : _primes)
        if (!(n % p)) return false;
    return true;
}

int main() {
    sieve(MAX_SIEVE_SIZE);
    uint32_t n;
    while ((cin >> n) && n) {
        uint32_t candidate;
        for (candidate = 2*n + 1; !is_prime(candidate); candidate++);
        cout << candidate;
        if (!is_prime(n))
            cout << " (" << n << " is not prime)";
        cout << endl;
    }


    return 0;
}

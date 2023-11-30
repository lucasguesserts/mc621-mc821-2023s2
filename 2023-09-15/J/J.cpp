// ==================== LICENSE ====================

/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
*/

// ==================== Solution Description ====================

/*
# [Pascal](https://open.kattis.com/problems/pascal)

The solution is the Euler's Totient Function.

*/

// ==================== Code ====================

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

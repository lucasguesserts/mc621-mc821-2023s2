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
# [Enlarging Hash Tables](https://open.kattis.com/problems/enlarginghashtables)

One only needs to test $2n+1, 2n+2, \ldots$ for primality. Here we implement a solution using a sieve
up to $40000$ since $n$ can be up to $2^{30}-1$ and thus we should aim for a sieve up to a good margin
over $\sqrt{2n}$.

It should be noted that this is an easy problem that does not actually require the use of a sieve to pass.
*/

// ==================== Code ====================

#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>

#define MAX_SIEVE_SIZE 40000 // > SQRT(MAXN)

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
        for (candidate = 2 * n + 1; !is_prime(candidate); candidate++)
            ;
        cout << candidate;
        if (!is_prime(n))
            cout << " (" << n << " is not prime)";
        cout << endl;
    }

    return 0;
}

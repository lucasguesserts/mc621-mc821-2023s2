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
# [Last Digit](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1103)

In this problem, we are given a positive integer $N$, $1 \leq N \leq 2\cdot 10^{100}$,
and are tasked to output the last digit of the sum

$$ S_N = 1^1 + 2^2 + 3^3 + \ldots + N^N.$$

The above sum defines a sequence $S_1, S_2, \ldots$ with $S_1 = 1$ and
$S_N = S_{N-1} + N^N$.

Define the sequence $L_1, L_2, \ldots$ as $L_N = S_N \pmod{10}$, i.e. the last digit
of $S_N$. It is $L_N$ that we wish to compute.

We implement a function `last_digit_pow(a, b)` that returns $a^b \pmod{10}$. Then we
can compute many terms of the sequence $(L_i)_{i\geq 1}$ as such:

```
L[1] = 1
L[n] = (L[n-1] + last_digit_pow(n, n)) % 10
```

Tinkering with this sequence, we come to realize that

* `L[1] = L[101] = L[201] = ...`
* `L[2] = L[102] = L[202] = ...`

and so forth. It requires some combination of time, patience, and/or further
programming to realize the above pattern of repetition. It might not be hard
to prove it mathematically, but we haven't checked for that here.

With this, we only need to compute the first 100 hudred distinct values and check, for
each input, what case it falls into. (Namely, we check its value modulo 100 and
output the corresponding result from the table.)

For ease of coding, one may define `L[0] = L[100]` (which incidentally is equal to 0)
even though the sequence is not defined for index 0.
*/

// ==================== Code ====================

#include <cstdint>
#include <iostream>
#include <string>

#define PERIOD 100

using namespace std;

uint32_t lastdigit[PERIOD];

uint32_t last_digit_pow(uint32_t base, uint32_t exp) {
    if (exp == 0) return 1;
    uint32_t aux = last_digit_pow(base, exp / 2);
    if (exp % 2)
        return (aux * aux * base % 10);
    return (aux * aux % 10);
}

void compute_sequence() {
    lastdigit[0] = 0; // artificial definition; matches lastdigit[100] which is size of period
    for (int i = 1; i < PERIOD; i++)
        lastdigit[i] = (last_digit_pow(i, i) + lastdigit[i - 1]) % 10;
}

int main() {
    compute_sequence();
    string in;
    while ((cin >> in) && in != "0") {
        uint32_t n = 0, mult = 1, size = in.size();
        for (int i = 1; i <= size && i <= 2; mult *= 10, i++)
            n += (in[size - i] - '0') * mult;
        cout << lastdigit[n] << endl;
    }
    return 0;
}

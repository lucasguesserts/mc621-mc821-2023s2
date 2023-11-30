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
# [Codeforces 1091D. New Year and the Permutation Concatenation](https://codeforces.com/contest/1091/problem/D)

See the editorial, it is good.

## References

- [Editorial of the problem](https://codeforces.com/contest/1091/problem/D);
- [Next lexicographical permutation algorithm](https://www.nayuki.io/page/next-lexicographical-permutation-algorithm);
*/

// ==================== Code ====================

#include <iostream>
#include <vector>

using namespace std;

using I = long long int;
using VI = vector<I>;

constexpr I M = 998244353;

void egcd(I a, I b, I & d, I & x, I & y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        return;
    }
    egcd(b, a % b, d, x, y);
    I x1 = y;
    I y1 = x - (a / b) * y;
    x = x1;
    y = y1;
    return;
}

I mod_inv(I a) {
    I d, x, y;
    egcd(a, M, d, x, y);
    return x;
}

VI mod_inv(VI A) {
    VI INV(A.size(), 1);
    for (I i = 0; i < A.size(); ++i) {
        INV[i] = mod_inv(A[i]);
    }
    return INV;
}

VI fact(I n) {
    VI N(n + 1, I(1));
    for (I i = 1; i <= n; ++i) {
        N[i] = (i * N[i - 1]) % M;
    }
    return N;
}

int main() {
    I n;
    cin >> n;
    auto N = fact(n);
    auto NINV = mod_inv(N);
    I x;
    x = n * N[n];
    x %= M;
    for (I k = 1; k < n; ++k) {
        x -= (N[n] * NINV[k]);
        x %= M;
        if (x < 0) x += M;
        x %= M;
    }
    cout << x;
    return 0;
}

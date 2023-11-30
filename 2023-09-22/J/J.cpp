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
# [Codeforces 1359E - Modular Stability](https://codeforces.com/contest/1359/problem/E)

The array is stable if and only if all of its elements are multiple of its minimum.

1. select a minimum $m < n$;
2. there are $c = \left\lfloor\dfrac{n}{m}\right\rfloor$ candidate elements;
3. choose $k - 1$ out of $c - 1$ elements (the other element is $m$);
   1. this gives $\mathcal{C}_{c-1}^{k-1} = \dfrac{(c-1)!}{(k-1)! (c-k)!}$
   2. if $c < k$, then it is impossible to find a solution with the selected minimum;

## References

- [Codeforces tutorial](https://codeforces.com/blog/entry/78116)
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
    I n, k;
    cin >> n >> k;
    if (n < k) {
        cout << 0 << endl;
        return 0;
    }
    // n >= k
    auto FACT = fact(n);
    auto FACT_INV = mod_inv(FACT);
    I solution = 0;
    for (I m = 1; m <= n; ++m) {
        I c = n / m;
        if (c < k) {
            continue;
        }
        I p = FACT[c - 1];
        p *= FACT_INV[k - 1];
        p %= M;
        p *= FACT_INV[c - k];
        p %= M;
        solution += p;
        solution %= M;
    }
    if (solution < 0) {
        solution = (solution + M) % M;
    }
    cout << solution << endl;
    return 0;
}

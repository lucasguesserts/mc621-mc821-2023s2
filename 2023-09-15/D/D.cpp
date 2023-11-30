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
# [Row GCD](https://codeforces.com/problemset/problem/1458/A)

We have positive integers $a_1, a_2, \ldots, a_n$ and $b_1, b_2, \ldots, b_m$
and wish to find, for each $j = 1, 2, \ldots, m$, $G_j = gcd(a_1 + b_j, a_2 + b_j, \ldots, a_n + b_j)$.

Given that $gcd(a, b, c) = gcd(a, gcd(b, c))$, computing the GCD of $n$ numbers requires
$n$ calls to function `gcd`.

The straightforward solution (manually computing $O(nm)$ GCD's) is simply too expensive
since both $n$ and $m$ could be up to $2\cdot 10^5$ meaning $4\cdot 10^{10}$ calls to function
`gcd`.

The speedup this problem is looking for is as follows: realize that $gcd(a, b) = gcd(a, b-a)$.
Then

$$
\begin{align}
    G_j &= gcd(a_1 + b_j, a_2 + b_j, \ldots, a_n + b_j) \\
    &= gcd(a_1 + b_j, a_2 + b_j - (a_1 + b_j), \ldots, a_n + b_j - (a_1 + b_j)) \\
    &= gcd(a_1 + b_j, a_2 - a_1, \ldots, a_n - a_1)
\end{align}
$$

Thus, if we precompute $G_a = gcd(a_2 - a_1, a_3 - a_1, \ldots, a_n - a_1)$, then every
$G_j$ is simply

$$ G_j = gcd(a_1 + b_j, G_a) $$

so we can compute the whole output in only $O(n + m)$ calls to `gcd`.

A few traps:

* We could have $n=1$. In this case $GCD_a$ should be considered to be 0 rather than $a_1$;
* For each $i$, we could have $a_i - a_1 < 0$. There are a few different ways to deal with this, but
my favorite is to simply use $|a_i - a_1|$ because in the context of modular arithmetics the semantics
of C++'s `%` operator are confusing.
*/

// ==================== Code ====================

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

using I = int64_t;

I gcd(I a, I b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
    I len1, len2;
    I a0, a, diff, GCD_a, b;
    cin >> len1 >> len2;
    cin >> a0;
    GCD_a = 0;
    for (I i = 1; i < len1; i++) {
        cin >> a;
        diff = (a > a0) ? a - a0 : a0 - a;
        GCD_a = gcd(diff, GCD_a);
    }
    for (I i = 0; i < len2; i++) {
        cin >> b;
        cout << gcd(a0 + b, GCD_a) << " ";
    }
    cout << endl;
    return 0;
}

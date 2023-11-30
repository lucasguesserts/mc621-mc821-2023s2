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
# [Codeforces 1244C - The Football Season](https://codeforces.com/problemset/problem/1244/C)

## Problem Data

1. Input: $n, p, w, d \in \mathbb{Z}_+$
   1. $1 \leqslant n  \leqslant 10^{12}$
   2. $1 \leqslant p \leqslant 10^{17}$
   3. $1 \leqslant d < w \leqslant 10^{5}$
2. Output: $x, y, z \in \mathbb{Z}_+$
   1. Constraints:
      1. $wx + dy = p$
      2. $x + y + z = n$

## Computing $z$

$$
x + y + z = n
\quad\leftrightarrow\quad
z(x, y) = n - x - y
$$

So, if one computes $x$ and $y$, one can find $z$.

## Computing $y$

$$
wx + dy = p
\quad\leftrightarrow\quad
y(x) = \dfrac{p - wx}{d}
$$

Thus, if one computes $x$, one can find $z$.

## Computing $x$

### Initial Value

We want to find an $x$ such that $y = \dfrac{p - wx}{d}$ is integer. With some calculations, one finds that such $x$ must satisfy:

$$
p - wx \equiv 0 \quad (mod \ d)
\quad\leftrightarrow\quad
p \equiv wx \quad (mod \ d)
$$

such condition, in programming languages, we would write as:

```plain
(p % d) == ((w % d) (x % d)) % d
```

Since $1 \leqslant d < 10^{5}$, we can test all values of $x$ from $0$ to $d-1$. We will call $0 \leqslant x_0 \leqslant d$ the first value which satisfy the above condition.

Other values can be found with the function $x(s) = x_0 + ds, s \in \mathbb{Z}_+$.

If such value does not exist, then the problem does not have a solution.

### Constraint 1 of $x$

One must have:

$$x(s) + y(x(s)) \leqslant n$$

With some calculations, one finds that:

$$s \geqslant \dfrac{dn - x_0(w - d) + p}{d(w - d)}$$

So one can select:

$$
s_n
=
\left\lceil
    \dfrac
        {dn - x_0(w - d) + p}
        {d(w - d)}
\right\rceil
$$

### Constraint 2 of $x$

One must have:

$$w x(s) \leqslant p$$

With some calculations, one finds that:

$$s \leqslant \dfrac{p - w x_0}{wd}$$

So one can select:

$$
s_p
=
\left\lfloor
    \dfrac
        {p - w x_0}
        {wd}
\right\rfloor
$$

## Solution

Select $s = \min(s_n, s_p)$ and then compute $x = x_0 + ds$. With $x$, compute $y$, and with it, compute $z$. Finally, check if all values are positive. If yes, then that is a valid answer. If not, then there is no $x, y, z$ which satisfy the conditions of the problem.

*/

// ==================== Code ====================

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

using I = long long int;

int main() {
    I n, p, w, d;
    cin >> n >> p >> w >> d;
    try {
        // x0
        I x0 = -1;
        for (I x = 0; x <= d; ++x) {
            if ((p % d) == (((w % d) * (x % d)) % d)) {
                x0 = x;
                break;
            }
        }
        if (x0 == -1) {
            throw 0;
        }
        // s
        I sn = static_cast<I>(ceil((d * n - x0 * (w - d) + p) / ((w - d) * d)));
        I sp = static_cast<I>(floor((p - w * x0) / (w * d)));
        I s = min(sp, sn);
        // x
        I x = x0 + s * d;
        // y
        I y = (p - w * x) / d;
        if (y < 0) {
            throw 0;
        }
        // z
        I z = n - x - y;
        if (z < 0) {
            throw 0;
        }
        // output
        cout << x << " " << y << " " << z << endl;
    } catch (...) {
        cout << -1 << endl;
    }
    return 0;
}

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
# [UVa 10090 - Marbles](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1031)

1. Input:
   1. $n \in \mathbb{N}$ marbles;
   2. Box type 1:
      1. holds $n_1 \in \mathbb{N}$ marbles;
      2. costs $c_1 \in \mathbb{R}_+$;
   2. Box type 2:
      1. holds $n_2 \in \mathbb{N}$ marbles;
      2. costs $c_2 \in \mathbb{R}_+$;
2. Output:
   $$
    \begin{array}{ll}
        \min & c_1 m_1 + c_2 m_2\\
        s.t. & n_1 m_1 + n_2 m_2 = n
    \end{array}
   $$

## Linear Diophantine Equation with Two Unknowns

Let $d = gcd(n_1, n_2)$. Notice that

$$n_1 x + n_2 y = n$$

has a solution if and only if $d$ divides $n$, i.e. $n \text{ mod } d = 0$. In this case, define:

$$t = \dfrac{n}{d}$$

Let $x, y \in \mathbb{Z}$ be the solutions of

$$n_1 x + n_2 y = d$$

Thus:

$$n_1 t x + n_2 t y = t d = n$$

and so $x_0$ and $y_0$ are solutions of

$$
n_1 x_0 + n_2 y_0 = n \\
x_0 = tx \\
y_0 = ty
$$

And any other solution is of the form:

$$
\begin{array}{rcl}
    x' &=& x_0 + \dfrac{n_2}{d} k \\\\
    y' &=& y_0 - \dfrac{n_1}{d} k
\end{array}
$$

However, we want both $x', y'$ to be positive. Applying such conditions, we get:

$$
k_{\min} = - \dfrac{x n}{n_2} \leqslant k \leqslant \dfrac{y n}{n_1} = k_{\max}
$$

So, any $k \in [k_{\min}, k_{\max}]$ give us a valid solution for the problem.

## Optimization

Let $p_1 = \dfrac{n_1}{c_1}$ and  $p_2 = \dfrac{n_2}{c_2}$. If $p_1 \geqslant p_2$, then it is worth buying as many boxes of type 1 as possible. In such case, we want to choose $k = k_{\max}$. In the case $p_1 < p_2$, we want to choose $k = k_{\min}$. Thus:

$$
k = \begin{cases}
    \left\lfloor \dfrac{y n}{n_1} \right\rfloor, p_1 \geqslant p_2 \\\\
    \left\lceil - \dfrac{x n}{n_2} \right\rceil, p_1 < p_2
\end{cases}
$$

$$
m_1 = t x + \dfrac{n_2}{d} k
$$

$$
m_2 = t y - \dfrac{n_1}{d} k
$$
*/

// ==================== Code ====================

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

using N = std::int64_t;
using D = double;

void egcd(N a, N b, N & d, N & x, N & y) {
    // base case
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        return;
    }
    egcd(b, a % b, d, x, y);
    N x1 = y;
    N y1 = x - (a / b) * y;
    x = x1;
    y = y1;
    return;
}

N nfloor(D x) { return static_cast<N>(std::floor(x)); }

N nceil(D x) { return static_cast<N>(std::ceil(x)); }

void failure() {
    cout << "failed" << endl;
    return;
}

int main() {
    while (true) {
        N n(0);
        N n1(0), n2(0);
        D c1(0), c2(0);
        N d(0), x(0), y(0);
        cin >> n;
        if (n == 0) {
            return 0;
        }
        cin >> c1 >> n1;
        cin >> c2 >> n2;
        egcd(n1, n2, d, x, y);
        if (n % d != 0) {
            failure();
            continue;
        }
        const N t = n / d;
        const D k_min = nceil(-(static_cast<D>(x) * n) / n2);
        const D k_max = nfloor((static_cast<D>(y) * n) / n1);
        if (k_max < k_min) {
            failure();
            continue;
        }
        N k(0);
        const D p1 = n1 / c1;
        const D p2 = n2 / c2;
        if (p1 <= p2) {
            k = k_min;
        } else {
            k = k_max;
        }
        const N m1 = t * x + n2 / d * k;
        const N m2 = t * y - n1 / d * k;
        cout << m1 << " " << m2 << endl;
    }
}

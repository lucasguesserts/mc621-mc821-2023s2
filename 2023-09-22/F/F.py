"""
==================== LICENSE ====================

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

 ==================== Solution Description ====================

# [SPOJ REC - Recurrence](https://www.spoj.com/problems/REC/)

## Expression Expansion Approach

$$
\begin{array}{rcl}
f_0 &=& 1\\
f_1 &=& a + b\\
f_2 &=& a^2 +ab +b\\
f_3 &=& a^3 +a^2b + ab +b\\
&\dots&\\
f_j &=& a^j + \displaystyle\sum\limits_{i=1}^{j} a^{j-i}b
= a^j + b \left( \displaystyle\sum\limits_{i=0}^{j-1} a^{i} \right)
&\dots&\\
f_n &=& a^n + b \left( \displaystyle\sum\limits_{i=0}^{n-1} a^{i} \right)
\end{array}
$$

Notice that $\displaystyle\sum\limits_{i=0}^{n-1} a^{i}$ is a geometric progression with first $x_1$ term equals $1$ and ratio $q$ equals $a$. Using the GP sum equation below:

$$
S_n = x_1\ \dfrac{q^n -1}{q - 1}
$$

Then:

$$
\displaystyle\sum\limits_{i=0}^{n-1} a^{i}
=
\dfrac{a^n - 1}{a - 1}
$$

Finally, we get an expression for $f_n$:

$$
f_n = a^n + b \ \dfrac{a^n - 1}{a - 1}
$$

But now we face the problem of computing $f_n \% M$. The complicated part is to handle the $(a - 1)^{-1}$, and we cannot use the multiplicative inverse of the mod because it is not guaranteed that $\text{gcd}(a - 1, M) = 1$.

## Matrix Approach

Notice that one can write the recursion in the matrix format:

$$
\left[
\begin{array}{cc}
    1 & 0 \\
    1 & a
\end{array}
\right]
\left[
\begin{array}{c}
    b \\
    f_{j-1}
\end{array}
\right]
=
\left[
\begin{array}{c}
    b \\
    f_{j}
\end{array}
\right]
$$

So the solution for the problem is:

$$
\left[
\begin{array}{cc}
    1 & 0 \\
    1 & a
\end{array}
\right]^n

\left[
\begin{array}{c}
    b \\
    1
\end{array}
\right]
=
\left[
\begin{array}{c}
    b \\
    f_{n}
\end{array}
\right]
$$

This problem can thus be solved using Matrix exponentiation and mod:

### Multiplication

$$
\left[
\begin{array}{cc}
    1 & 0 \\
    x_{10} & x_{11}
\end{array}
\right]
\left[
\begin{array}{cc}
    1 & 0 \\
    y_{10} & y_{11}
\end{array}
\right]
=
\left[
\begin{array}{cc}
    1 & 0 \\
    x_{10} + x_{11} y_{10} & x_{11} y_{11}
\end{array}
\right]
$$

### Mod

$$
\left[
\begin{array}{cc}
    1 & 0 \\
    x_{10} & x_{11}
\end{array}
\right]
\% M
=
\left[
\begin{array}{cc}
    1 & 0 \\
    x_{10} \% M & x_{11} \% M
\end{array}
\right]
$$

### Exponentiation with Mod

$$
A^n \% M
=
\begin{cases}
Id \% M &,& n = 0 \\
0 &,& A = 0 \\
((A^{n/2} \% M) \cdot (A^{n/2} \% M)) \% M &,& n \text{ is even} \\
((A \% M) \cdot (A^{n - 1} \% M)) \% M &,& n \text{ is odd} \\

\end{cases}
$$

where $Id = \left[\begin{array}{cc}1 & 0 \\ 0 & 1\end{array}\right]$ is the identity matrix.

### Complexity

This solution takes $\mathcal{O}(\log n)$ computational time.
"""

# ==================== Code ====================

import sys

if sys.version_info[0] < 3:
    input_func = raw_input
else:
    input_func = input


class Matrix:
    def __init__(self, a_10, a_11):
        self.a_10 = a_10
        self.a_11 = a_11

    def prod(self, other):
        self.a_10 = self.a_10 + self.a_11 * other.a_10
        self.a_11 = self.a_11 * other.a_11
        return

    def mod(self, m):
        self.a_10 = self.a_10 % m
        self.a_11 = self.a_11 % m


def expM(A, y, m):
    # (A ^ y) % m
    if y == 0:
        return Matrix(0, 1)
    if y % 2 == 0:
        Z = expM(A, y // 2, M)
        Z.prod(Z)
        Z.mod(m)
        return Z
    else:
        Z1 = A
        Z2 = expM(A, y - 1, m)
        Z2.prod(Z1)
        Z2.mod(m)
        return Z2


if __name__ == "__main__":
    T = int(input_func())
    for t in range(T):
        a, b, n, M = map(int, input_func().split())
        if n == 0:
            print(1 % M)
            continue
        if a == 0:
            print(b % M)
            continue
        if a == 1:
            print((1 + n * b) % M)
            continue
        A = Matrix(1, a)
        AN = expM(A, n, M)
        ans = (AN.a_10 * b + AN.a_11) % M
        print(ans)

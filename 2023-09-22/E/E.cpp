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
# [Codeforces 1475E. Advertising Agency](https://codeforces.com/problemset/problem/1475/E)

Let:

1. $n,k \in \N$ with $k \leqslant n$;
2. $A = \left\langle a_1, \dots, a_n \right\rangle$;
3. $M = 10^9 + 7$;

Define $A'$ as $A$ sorted in weakly decreasing order:

$$
A' = \left\langle a'_1, \dots, a'_n \right\rangle
\quad\text{ with }
a'_i \geqslant a'_j \text{ when } i < j
\text{ (weakly decreasing) }
$$
If the problem was to take the best $k$ bloggers, one would simply take the first $k$ entries of $A'$. But one has to consider all the different possibilities which give the same impact.

It might be the case that there are many bloggers with $a'_k$ followers. Let's then break down $A'$ into two parts $F$ and $S$:

$$
F = \{a \in A' \ | \ a > a'_k\}
$$

$$
S = \{a \in A' \ | \ a = a'_k\}
$$

$F$ is our set of fixed bloggers, those which must be present for the choice to be optimal, and $S$ are the ones we can select since they have the same number of followers $a'_k$.

One has $\phi = k - |F|$ bloggers to select among $\sigma = |S|$ ones. Thus one can find the solution $x$ of the problem as being:

$$
x = \mathcal{C}_{\sigma}^{\phi} = \dfrac{\sigma!}{(\sigma - \phi)! \ \phi!}
$$

Fot the modulo:

$$
x \% M
=
\mathcal{C}_{\sigma}^{\phi} \% M
=
\sigma! \% M \ (\sigma - \phi)!^{-1} \ \phi!^{-1}
$$

where $y^{-1}$ is the modular inverse of $y$.

For the program, one can compute $\sigma! \% M$ in $\mathcal{O}(\sigma)$ time (store all values in a vector, computing the mod $M$ at each iteration), and with that result one can compute the other two modular inverses.
*/

// ==================== Code ====================

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using I = long long int;
using VI = vector<I>;

constexpr I M = 1000000007; // prime number

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

VI mod_inv(const VI & A) {
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

void print(const VI & A) {
    for (const auto & a : A) {
        cout << a << ", ";
    }
    cout << endl;
}

int main() {
    I t;
    cin >> t;
    while (t--) {
        // data
        I n, k;
        cin >> n >> k;
        VI A;
        for (I i = 0; i < n; ++i) {
            I a;
            cin >> a;
            A.push_back(a);
        }
        // A, F, S
        //// A
        std::sort(A.begin(), A.end(),
            std::greater<>()); // sort A weakely decreasing
        //// F
        VI F;
        I ak = A[k - 1];
        auto it = A.begin();
        while ((*it != ak) && (it != A.end())) {
            F.push_back(*it);
            ++it;
        }
        //// S
        VI S;
        while ((*it == ak) && (it != A.end())) {
            S.push_back(*it);
            ++it;
        }
        // solution
        I phi = k - F.size();
        I sigma = S.size();
        auto FAC = fact(sigma);
        auto FACINV = mod_inv(FAC);
        I x = 1;
        x *= FAC[sigma];
        x %= M;
        x *= FACINV[sigma - phi];
        x %= M;
        x *= FACINV[phi];
        x %= M;
        if (x < 0) {
            x += 2 * M;
        }
        x %= M;
        cout << x << endl;
    }
    return 0;
}

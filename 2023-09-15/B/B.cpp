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
# [Prsteni](https://open.kattis.com/problems/prsteni)

Imagine a point on the surface of the first ring. After one rotation, it has moved a distance equals to $2 \pi r_0$. Now imagine a point on the surface of the second ring. It will also move a distance equals to $2 \pi r_0$. How much is it in terms of angular movement? It is $\dfrac{2 \pi r_0}{2 \pi r_1} = \dfrac{r_0}{r_1}$.

For the other rings, it is exactly the same computation.

The problem ask one to compute the fraction in the reduced form. For that, one has to compute the greatest common divisor $g$ of both the numerator $r_0$ and denominator $r_i$, and then the answer is $\dfrac{r_0}{g}\Big/\dfrac{r_i}{g}$.

*/

// ==================== Code ====================

#include <iostream>

using namespace std;

using Number = long unsigned int;

Number gcd(const Number x, const Number y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    auto N = Number(0);
    auto r0 = Number(0);
    cin >> N;
    cin >> r0;
    for (auto i = 1u; i < N; ++i) {
        auto r = Number(0);
        cin >> r;
        const auto g = gcd(r, r0);
        cout << r0 / g << "/" << r / g << endl;
    }
    return 0;
}

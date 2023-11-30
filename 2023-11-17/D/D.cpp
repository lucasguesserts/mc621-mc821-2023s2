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
# [Amsterdam Distance](https://open.kattis.com/problems/amsterdamdistance)

Let's say that, in order to arrive at its destination, the friend walks $r_1$ units in the radial direction towards the center, then they walk $a$ units in the angular direction, and finally they walk $r_2$ units in the radial direction towards the outside. What is the total distance $D$ that the friend walks?

$$ D = R \ \dfrac{r_1}{N} + \left(R \ \dfrac{r}{N}\right) \ \left( \pi \ \dfrac{a}{M}\right) + R \ \dfrac{r_2}{N}$$

The first and third part are the radial distances and the middle one is the angular distance. Notice that $r$ is the radial position used in the angular displacement.

To solve the problem, i.e. to find the minimum distance the friend has to travel, one can iterate for $r = 0, \dots, \max(a_y, b_y)$ and check which one yields the minimum distance. For that, one uses: $r_1 = |a_y - r|$, $r_2 = |b_y - r|$, and $a = |a_x - b_x|$.

![](./figure.png)
*/

// ==================== Code ====================

#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

using I = int64_t;
using D = double;

I M, N;
D R;

D compute_distance(I r1, I r, I a, I r2) {
    D z = 0;
    z += R * (r1 / static_cast<D>(N));
    z += R * (r / static_cast<D>(N)) * M_PI * a / static_cast<D>(M);
    z += R * (r2 / static_cast<D>(N));
    return z;
}

int main() {
    cin >> M >> N >> R;
    I ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    D minimum = numeric_limits<D>::max();
    for (I i = 0; i <= max(ay, by); i++) {
        I r1 = abs(ay - i);
        I r2 = abs(by - i);
        I a = abs(ax - bx);
        auto z = compute_distance(r1, i, a, r2);
        minimum = min(minimum, z);
    }
    cout << setprecision(15) << minimum;
}

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
# [Codeforces 1178C - Tiles](https://mirror.codeforces.com/contest/1178/problem/C)

Make a grid and notice the following:

1. The first tile (top left) has 4 possible rotations;
2. The tiles on the top have 2 possible rotations;
3. The tiles on the left have 2 possible rotations;
4. All other tiles have their rotations defined by the previous ones;

The figure below shows the number of available rotations per tile:

![number of available rotations per tile](./fig.png)

Thus, the total number of tilings $P$ is given by:

$$
P = 4 \times 2^{w-1} \times 2^{h-1} = 2^{w} \times 2^{h}
$$

Finally, one needs an efficient way of computing $P \% M$:

$$
P \% M = (2^{w} \times 2^{h}) \% M = (2^{w} \% M) \times (2^{h} \% M)
$$

And:

$$
2^y \% M = \begin{cases}
1 &,& y = 0 \\
(2^{y/2} \% M)^2 \% M &,& y \text{ even} \\
(2 \times 2^{y-1}) \% M &,& y \text{ odd}
\end{cases}
$$
*/

// ==================== Code ====================

#include <iostream>

using namespace std;

using I = long long int;

constexpr I M = 998244353;

I exp(I y) {
    if (y == 0) {
        return I(1);
    } else if (y % 2 == 0) {
        I z = exp(y / 2);
        z *= z;
        z %= M;
        return z;
    } else {
        I z1 = exp(y - 1);
        I z = 2;
        z *= z1;
        z %= M;
        return z;
    }
}

int main() {
    I w, h;
    cin >> w >> h;
    I W = exp(w);
    I H = exp(h);
    I x = W * H;
    x %= M;
    cout << x;
    return 0;
}

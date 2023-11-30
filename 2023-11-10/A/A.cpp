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
# [Curse the Darkness](https://open.kattis.com/problems/cursethedarkness)

Let $b_x, b_y \in \mathbb{R}_+$ be the coordinates of the book and $c_x, c_y \in \mathbb{R}_+$ be the coordinates of a candle. If there is a candle for which $\sqrt{(b_x - c_x)^2 + (b_y - c_y)^2} \leq 8$, then output `light a candle`. Otherwise, output `curse the darkness`.

Complexity: $\mathcal{O}(n)$ where $n$ is the number of candles.

Obs: read all the input even if you find a value for which the condition above holds.
*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

using I = int64_t;
using R = double;

constexpr R EIGHT = 8.0;

int main() {
    I T;
    cin >> T;
    while (T--) {
        R BX, BY;
        I N;
        cin >> BX >> BY;
        cin >> N;
        bool found = false;
        for (I i = 0; i < N; ++i) {
            R CX, CY;
            cin >> CX >> CY;
            if (hypot(BX - CX, BY - CY) <= EIGHT) {
                found = true;
            }
        }
        if (found) {
            cout << "light a candle" << endl;
        } else {
            cout << "curse the darkness" << endl;
        }
    }
    return 0;
}

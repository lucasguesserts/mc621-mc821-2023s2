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
# [Mandelbrot](https://open.kattis.com/problems/mandelbrot)

Use `complex` from c++ and `abs` (which computes its absolute value). The solution is straightforward, just follow the procedured described in the problem statement.
*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

using I = int64_t;
using D = double;
using C = complex<D>;

int main() {
    I i = 0;
    while (true) {
        D x, y;
        I r;
        cin >> x;
        if (cin.eof()) { break; }
        cin >> y >> r;
        ++i;
        // cout << x << " " << y << " " << r << endl;
        C c(x, y);
        C z(0, 0);
        bool diverges = false;
        for (I j = 0; j < r; j++) {
            z = z * z + c;
            if (abs(z) > 2.0) {
                diverges = true;
                break;
            }
        }
        auto answer = diverges ? "OUT" : "IN";
        cout << "Case " << i << ": " << answer << endl;
    }
    return 0;
}

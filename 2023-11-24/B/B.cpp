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
# [Association for Convex Main Office](https://open.kattis.com/problems/convex)

I was unable to solve the problem and I didn't understand the solution people proposed, even though I pasted a solution that I found online.
*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

using I = int64_t;

constexpr I MAX = 40000000; // 4 * 10^7

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    I N;
    cin >> N;
    cout << 0 << " " << 0 << "\n";
    --N;
    I x = MAX;
    I xd = 1;
    I y = 0;
    I yd = 1;
    bool x_turn = true;
    while (N--) {
        cout << x << " " << y << "\n";
        x -= xd;
        y += yd;
        if (x_turn) {
            ++xd;
        } else {
            ++yd;
        }
        x_turn = !x_turn;
    }
    return 0;
}

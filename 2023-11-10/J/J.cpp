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
# [Kattis - Brownie Points I](https://open.kattis.com/problems/browniepoints)

Straightforward linear algorithm that checks each point's position relative to center.

1. Read the $n$ points into vector `P`;
2. Central point `r` is `P[n/2]`;
3. For each point `p` in `P`:
    - if `p` has either same `x` or `y` as central point `r`, it doens't count;
    - otherwise, if `p.x` and `p.y` are either BOTH GREATER or BOTH LESSER than `r.x` and `r.y` respectively, Stan scores;
    - otherwise, Ollie scores.*/

// ==================== Code ====================

#include <bits/stdc++.h>

#define SIGN(x) ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))

using namespace std;

struct point_i {
    int x, y;
    point_i() { x = y = 0; }
    point_i(int _x, int _y)
        : x(_x)
        , y(_y) {}
};

point_i read_point() {
    int x, y;
    cin >> x >> y;
    return point_i(x, y);
}

int main() {
    int n;
    while ((cin >> n) && n) {
        vector<point_i> points;
        for (int i = 0; i < n; i++)
            points.push_back(read_point());
        point_i center = points[n / 2];

        unsigned stan = 0, ollie = 0;
        for (auto p : points) {
            int relative_position = SIGN(p.x - center.x) * SIGN(p.y - center.y);
            if (relative_position == 1)
                stan++;
            else if (relative_position == -1)
                ollie++;
        }
        cout << stan << " " << ollie << endl;
    }
    return 0;
}

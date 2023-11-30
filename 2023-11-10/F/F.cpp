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
# [UVa 01595 - Symmetry](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4470)

Let $n$ be the size of our vector `P` of points. We want to determine whether `P` has $x$-axis
symmetry.

We start by sorting the points by smallest x-coordinate, breaking ties by smallest y-coordinate.

Thus, the leftmost and rightmost points (possibly tied with others) are
`P[0]` and `P[n-1]` respectively. Let $x_1$ and $x_n$ be their respective $x$ coordinates.
If `P` is $x$-symmetric, then the symmetry should be around

$$ \bar{x} = \frac{x_1 + x_n}{2} $$

which can be fractional. More precisely, it can be *half-integer*, since every coordinate in the input is integer.

Given a point $p = (x, y)$ in left side of `P`, we know that `P` is $x$-symmetric only if the *counterpart* $q$ of $p$ in `P`,
where

$$ q = (x + 2(\bar{x} - x) , y) = (2\bar{x} - x, y). $$

Therefore, we can completely avoid storing fractional coordinates, since we don't really need $\bar{x}$ (half-integer)
but really $2\bar{x}$ which is guaranteed to be integer.

The algorithm is the following:

1. sort `P` (as described above, first by smallest $x$-coordinate);

2. store every point in `P` in a set of known points, `S`;

3. for `i = 0, 1, 2, ..., n/2` (thus checkint the first $\lceil n/2 \rceil$ points):

    - let `q` be the counterpart of point `P[i]` as described by the formula above;

    - if `q` does not exist in `S`, then `P` is not symmetric: return `false`;

4. return `true`.*/

// ==================== Code ====================

#include <bits/stdc++.h>
using namespace std;

/*
    Adapting types and functions from Competitive Programming repo
    https://github.com/stevenhalim/cpbook-code/tree/master/ch7
*/

struct point_i {
    int x, y;
    point_i() { x = y = 0; }
    point_i(int _x, int _y)
        : x(_x)
        , y(_y) {}

    bool operator<(point_i other) const {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }

    bool operator==(point_i other) const {
        return (x == other.x && y == other.y);
    }
};

/*  Receives a vector of points.
    Returns true if the points have symmetry in the x-axis.
*/
bool x_symmetric(vector<point_i> points) {
    sort(points.begin(), points.end());

    set<point_i> existing_points;
    for (auto p : points)
        existing_points.insert(p);

    point_i leftmost = points[0],
            rightmost = points[points.size() - 1];

    int doubled_mid_x = leftmost.x + rightmost.x;

    // check first ceil(n/2) points for their counterparts
    for (int i = 0; i <= points.size() / 2; i++) {
        int sym_x = doubled_mid_x - points[i].x;
        auto counterpart = point_i(sym_x, points[i].y);
        if (existing_points.count(counterpart) == 0)
            return false;
    }
    return true;
}

int main() {
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int npoints;
        cin >> npoints;
        vector<point_i> P;
        P.reserve(npoints);
        while (npoints--) {
            int x, y;
            cin >> x >> y;
            P.push_back(point_i(x, y));
        }
        cout << (x_symmetric(P) ? "YES" : "NO") << endl;
    }
    return 0;
}

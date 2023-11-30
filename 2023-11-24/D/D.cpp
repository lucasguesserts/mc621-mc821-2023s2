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
# [UVa 11096 - Nails](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2037)

1. compute the convex hull of the given points;
2. compute the perimeter of the convex hull;
3. output the perimeter of the convex hull or the initial length of the wire, whichever is larger.
*/

// ==================== Code ====================

#include <bits/stdc++.h>
#include <iomanip>
#include <string>

using namespace std;

using I = int64_t;

// This is a copy of some methods available at
// https://github.com/stevenhalim/cpbook-code/blob/master/ch7/polygon.cpp

const double EPS = 1e-9;

struct point {
    double x, y; // only used if more precision is needed
    point() { x = y = 0.0; } // default constructor
    point(double _x, double _y)
        : x(_x)
        , y(_y) {} // user-defined
    bool operator==(point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    bool operator<(const point & p) const {
        return x < p.x || (abs(x - p.x) < EPS && y < p.y);
    }
};

struct vec {
    double x, y; // name: `vec' is different from STL vector
    vec(double _x, double _y)
        : x(_x)
        , y(_y) {}
};

vec toVec(point a, point b) { // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

double dist(point p1, point p2) { // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y);
} // return double

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

vector<point> CH_Andrew(vector<point> & Pts) { // overall O(n log n)
    int n = Pts.size(), k = 0;
    vector<point> H(2 * n);
    sort(Pts.begin(), Pts.end()); // sort the points by x/y
    for (int i = 0; i < n; ++i) { // build lower hull
        while ((k >= 2) && !ccw(H[k - 2], H[k - 1], Pts[i]))
            --k;
        H[k++] = Pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i) { // build upper hull
        while ((k >= t) && !ccw(H[k - 2], H[k - 1], Pts[i]))
            --k;
        H[k++] = Pts[i];
    }
    H.resize(k);
    return H;
}

void remove_duplicates(vector<point> & P) {
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
}

// returns the perimeter of polygon P, which is the sum of
// Euclidian distances of consecutive line segments (polygon edges)
double perimeter(const vector<point> & P) { // by ref for efficiency
    double ans = 0.0;
    for (int i = 0; i < (int)P.size() - 1; ++i) // note: P[n-1] = P[0]
        ans += dist(P[i], P[i + 1]); // as we duplicate P[0]
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    I T;
    cin >> T;
    while (T--) {
        I n;
        double LI;
        vector<point> P;
        cin >> LI >> n;
        P.resize(n);
        for (I i = 0; i < n; ++i) {
            cin >> P[i].x >> P[i].y;
        }
        vector<point> CH = CH_Andrew(P);
        auto L = max(LI, perimeter(CH));
        cout << fixed << setprecision(5) << L << '\n';
    }
    return 0;
}

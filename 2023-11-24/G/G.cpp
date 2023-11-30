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
# [Kattis cookiecutter - Cookie Cutter](https://open.kattis.com/problems/cookiecutter)

To rescale, one simply has to multiply all points by a given value. To move, one simply has to add a value to all points. The algorithm then is:

1. let $P$ be the polygon;
2. compute the area $PA$ of the polygon $P$;
3. compute the resize factor $s = \sqrt{\dfrac{A}{PA}}$;
4. multiply all points of $P$ by $s$;
5. find $x_{\min}, y_{\min}$, the minimum value of the coordinates $x$ and $y$ of the points of $P$, respectively;
6. subtract $x_{\min}$ from all $x$ coordinates and $y_{\min}$ from all $y$ coordinates of the points of $P$;
7. output the new points of $P$;
*/

// ==================== Code ====================

#include <bits/stdc++.h>
#include <ios>
#include <limits>

using namespace std;

// This is a partial copy of the file available at:
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

// returns the area of polygon P
double area(const vector<point> & P) {
    double ans = 0.0;
    for (int i = 0; i < (int)P.size() - 1; ++i) // Shoelace formula
        ans += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    return fabs(ans) / 2.0; // only do / 2.0 here
}

point find_min(const vector<point> & P) {
    point m = {numeric_limits<double>::max(), numeric_limits<double>::max()};
    for (const auto & p : P) {
        m.x = min(m.x, p.x);
        m.y = min(m.y, p.y);
    }
    return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // declaration
    int n;
    vector<point> P;
    double A;
    // input
    cin >> n;
    P.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i].x >> P[i].y;
    }
    P.push_back(P[0]);
    cin >> A;
    auto PA = area(P);
    auto resize_factor = sqrt(A / PA);
    for (auto & p : P) {
        p.x *= resize_factor;
        p.y *= resize_factor;
    }
    auto m = find_min(P);
    for (auto & p : P) {
        p.x -= m.x;
        p.y -= m.y;
    }
    P.pop_back();
    // output
    for (const auto & p : P) {
        printf("%.11lf %.11lf\n", p.x, p.y);
    }
    return 0;
}

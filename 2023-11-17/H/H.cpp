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
# [Kattis - Polygon Area](https://open.kattis.com/problems/polygonarea)

This is a direct application of the [Shoelace Formula](https://en.wikipedia.org/wiki/Shoelace_formula) for computing
the area of a polygon.

Simply put, if a polygon $P$ is described by the points $(x_0, y_0), \ldots, (x_{n-1}, y_{n-1})$, in either clockwise
or counterclockwise order, then

$$ \sum_{i=0}^{n-1} \left(x_iy_{i+1} - x_{i+1}y_i\right) $$

is 2 times the *signed area* of $P$. Here we are considering $(x_n, y_n) = (x_0, y_n)$.

In this problem, the coordinates are all integer and thus the above
formula gives an integer result (therefore, the actual area is half-integer).

The signed area of $A$ is its area with

* negative sign, if the points are in clockwise order;
* positive sign, otherwise.*/

// ==================== Code ====================

#include <bits/stdc++.h>
using namespace std;

struct point_i {
    int x, y;
    point_i() { x = y = 0.0; }
    point_i(int _x, int _y)
        : x(_x)
        , y(_y) {}
};

// returns signed area of polygon P (negative means points in clockwise)
double signed_area(const vector<point_i> & P) {
    int n = P.size();
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        ans += (P[i].x * P[j].y - P[j].x * P[i].y);
    }
    return ans / 2.0;
}

int main() {
    cout << fixed;
    cout << setprecision(1);
    int npoints;
    while ((cin >> npoints) && npoints) {
        vector<point_i> vertices(npoints);
        for (int i = 0; i < npoints; ++i) {
            int x, y;
            cin >> x >> y;
            vertices[i] = point_i(x, y);
        }
        double area = signed_area(vertices);
        if (area > 0)
            cout << "C";
        cout << "CW " << fabs(area) << endl;
    }
    return 0;
}

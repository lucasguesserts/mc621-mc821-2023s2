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
# [UVa 10263 - Railway](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1204)

The problem is as follows: for each test case, we begin by establishing a point of interest $p = (x, y)$.

Then, for a given $n$, we receive $n+1$ pairs $(x_0, y_0), (x_1, y_1), \ldots, (x_n, y_n)$ representing the $n$
line segments that form a railroad. (Notice that $(x_1, y_1)$ is the end of the first segment and the start of the second
one, and so on.)

Our task is to find the poinx $(x_c, y_c)$ in the railroad which minimizes the distance to our point of interest $p$.

The [*Competitive Programming* book by Halim, Halim, and Effendy](https://cpbook.net/) offers a codebase of useful
types, functions and implementations in different languages in their [open repository](https://github.com/stevenhalim/cpbook-code).
Using their code for lines and segments ([chapter 7](https://github.com/stevenhalim/cpbook-code/tree/master/ch7)), we have an
operation that directly solves this problem.

Function `distToLineSegment` receives a point `p`, two points `(a, b)` defining a segment, and a result point `c`.
It returns the minimum distance from `p` to `(a, b)` and stores the closest point of the segment in `c`.

All we have to do here is read the input carefully and store the minimum distance, along with the minimizing point.
At the end of each test case, we output the coordinates of the minimizing point.

## Possible difficulties

* Actually understanding the problem statement;

* Realizing that the given coordinates are not necessarily integer;

* Trimming the available code down to the bare essentials needed. (Optional)*/

// ==================== Code ====================

#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9;
const double EPS = 1e-9;

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y)
        : x(_x)
        , y(_y) {}
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line {
    double a, b, c;
};

struct vec {
    double x, y;
    vec(double _x, double _y)
        : x(_x)
        , y(_y) {}
};

vec toVec(const point & a, const point & b) {
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(const vec & v, double s) {
    return vec(v.x * s, v.y * s);
}

point translate(const point & p, const vec & v) {
    return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point & c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    // formula: c = a + u*ab
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c); // Euclidean distance
}

// returns the distance from p to the line segment ab defined by
// two points a and b (technically, a has to be different than b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point & c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { // closer to a
        c = point(a.x, a.y);
        return dist(p, a); // dist p to a
    }
    if (u > 1.0) { // closer to b
        c = point(b.x, b.y);
        return dist(p, b); // dist p to b
    }
    return distToLine(p, a, b, c); // use distToLine
}

int main() {
    double x, y;
    while (cin >> x >> y) {
        point p(x, y);

        int npoints;
        cin >> npoints;

        point a;
        cin >> a.x >> a.y;

        double min = INF;
        point closest;

        while (npoints--) {
            point b, c;
            cin >> b.x >> b.y;

            double dist = distToLineSegment(p, a, b, c);
            if (dist < min) {
                min = dist;
                closest = c;
            }

            a = b;
        }

        printf("%.4f\n%.4f\n", closest.x, closest.y);
    }
    return 0;
}

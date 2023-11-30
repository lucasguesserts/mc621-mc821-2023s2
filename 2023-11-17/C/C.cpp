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
# [UVa 10577 - Bounding Box](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1518)

We have an $n$-sides regular polygon, where we know $n$ and three distinct points.
With this, we can recover every vertex of the polygon. With that, it is a simple matter
of computing $x_{\min}$, $x_{\max}$, $y_{\min}$ and $y_{\max}$ of the vertices of the polygon, giving
a rectangular bounding box area of

$$ (x_{\max} - x_{\min})\cdot(y_{\max} - y_{\min}) .$$

It remains to discuss how to obtain the other vertices.

## Obtaining vertices from what we know from the input

There are many slightly different ways to do this, but one way follows:

First, compute the circumcircle of the 3 known points (treating them as vertices of a triangle).
This is the circumcircle of the whole polygon.
Let $(x_c, y_c)$ be the center of the circumcircle, and $r$ its radius;

We know that every vertex is located at

$$(x, y) = (x_c + r \cos{\theta}, y_c + r \sin{\theta})$$

where $\theta$ is the angle of the vector that goes from $(x_c, y_c)$ to $(x, y)$. We call this the
*central angle* of the vertex $(x,y)$.

Since this is a regular polygon, the central angle of consecutive vertices is evenly spaced by
a difference of $2\pi/n$. If we know the angle $\theta$ of a vertex $(x_0, y_0)$, then we can obtain all the
other vertices by computing

$$ (x_c + r \cos(\theta + 2\pi k/n), y_c + r \sin(\theta + 2\pi k/n)) $$

for $k = 1, 2, \ldots, n-1$.

We know three points and any of them can be used as the initial vertex $(x_0, y_0)$. The angle $\theta$ can
be obtained in a number of ways, such as

$$ \theta = \arccos{\frac{x_0 - x_c}{r}} .$$

The above observations give the algorithm below.

Given points $p_1$, $p_2$, $p_3$ of the $n$-sided regular polygon:

1. Compute center $(x_c, y_c)$ and radius $r$ of circumcircle of points $p_1, p_2, p_3$;

2. Compute $\theta = \arccos{(x_0 - x_c)/r}$ where $x_0$ is the $x$ of point $p_1$ (could be any of the three points);

3. For `k = 1..n-1`:
    - Compute new vertex $(x, y) = (x_c + r \cos(\theta + 2\pi k/n), y_c + r \sin(\theta + 2\pi k/n)) $

4. Let
    - $x_{\min}$, $y_{\min}$ be the minima of $(x, y)$ of the vertices;
    - $x_{\max}$, $y_{\max}$ be the maxima of $(x, y)$ of the vertices;

5. Output $(x_{\max} - x_{\min})\cdot(y_{\max} - y_{\min})$.
*/

// ==================== Code ====================

#include <bits/stdc++.h>
using namespace std;

/* Auxiliary functions from https://github.com/stevenhalim/cpbook-code/blob/master/ch7/ */

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

// assumption: the required points/lines functions have been written
// returns 1 if there is a circumCenter center, returns 0 otherwise
// if this function returns 1, ctr will be the circumCircle center
// and r is the same as rCircumCircle
int circumCircle(point p1, point p2, point p3, point & ctr, double & r) {
    double a = p2.x - p1.x, b = p2.y - p1.y;
    double c = p3.x - p1.x, d = p3.y - p1.y;
    double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
    double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
    double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
    if (fabs(g) < EPS) return 0;

    ctr.x = (d * e - b * f) / g;
    ctr.y = (a * f - c * e) / g;
    r = dist(p1, ctr); // r = distance from center to 1 of the 3 points
    return 1;
}

double bounding_box_area(point p1, point p2, point p3, int nvertices) {
    double r;
    point center;
    int res = circumCircle(p1, p2, p3, center, r);

    // theta: rotation angle with regard to circumcircle that gives the first point p1
    // (x1, y1) = (xcenter + r cos_theta, ycenter + r sin_theta)
    double cos_theta = (p1.x - center.x) / r;
    double theta = acos(cos_theta);

    double xmin = p1.x,
           xmax = p1.x,
           ymin = p1.y,
           ymax = p1.y;

    for (int i = 1; i < nvertices; i++) {
        double x = center.x + r * cos(theta + (2 * i * M_PI) / nvertices),
               y = center.y + r * sin(theta + (2 * i * M_PI) / nvertices);

        if (x < xmin)
            xmin = x;
        else if (x > xmax)
            xmax = x;

        if (y < ymin)
            ymin = y;
        else if (y > ymax)
            ymax = y;
    }

    return (xmax - xmin) * (ymax - ymin);
}

int main() {
    int nvertices;
    unsigned current_polygon = 0;
    while ((cin >> nvertices) && nvertices) {
        current_polygon++;
        double x, y;
        cin >> x >> y;
        point p1(x, y);
        cin >> x >> y;
        point p2(x, y);
        cin >> x >> y;
        point p3(x, y);
        double area = bounding_box_area(p1, p2, p3, nvertices);
        printf("Polygon %u: %.3lf\n", current_polygon, area);
    }
    return 0;
}

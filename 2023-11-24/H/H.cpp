#include <bits/stdc++.h>

using namespace std;

// This is a copy of the file available at
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

// returns the area of polygon P
double area(const vector<point> & P) {
    double ans = 0.0;
    for (int i = 0; i < (int)P.size() - 1; ++i) // Shoelace formula
        ans += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    return fabs(ans) / 2.0; // only do / 2.0 here
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) { // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns 1/0/-1 if point p is inside/on (vertex/edge)/outside of
// either convex/concave polygon P
int insidePolygon(point pt, const vector<point> & P) {
    int n = (int)P.size();
    if (n <= 3) return -1; // avoid point or line
    bool on_polygon = false;
    for (int i = 0; i < n - 1; ++i) // on vertex/edge?
        if (fabs(dist(P[i], pt) + dist(pt, P[i + 1]) - dist(P[i], P[i + 1])) < EPS)
            on_polygon = true;
    if (on_polygon) return 0; // pt is on polygon
    double sum = 0.0; // first = last point
    for (int i = 0; i < n - 1; ++i) {
        if (ccw(pt, P[i], P[i + 1]))
            sum += angle(P[i], pt, P[i + 1]); // left turn/ccw
        else
            sum -= angle(P[i], pt, P[i + 1]); // right turn/cw
    }
    return fabs(sum) > M_PI ? 1 : -1; // 360d->in, 0d->out
}

int main () {
    // declaration
    vector<point> triangle(3);
    int n;
    vector<point> trees;
    // input
    for (auto &p : triangle) {
        cin >> p.x >> p.y;
    }
    triangle.push_back(triangle[0]);
    cin >> n;
    trees.resize(n);
    for (auto &p : trees) {
        cin >> p.x >> p.y;
    }
    // solution
    const double area_triangle = area(triangle);
    int count_inside = 0;
    for (const auto &p : trees) {
        if (insidePolygon(p, triangle) >= 0) {
            ++count_inside;
        }
    }
    printf("%.1lf\n%d", area_triangle, count_inside);
    return 0;
}

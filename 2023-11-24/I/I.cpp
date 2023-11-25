#include <bits/stdc++.h>

using namespace std;

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

double find_longest_distance(const vector<point> & P) {
    double max_dist = 0;
    for (int i = 0; i < P.size(); i++) {
        for (int j = i + 1; j < P.size(); j++) {
            max_dist = max(max_dist, dist(P[i], P[j]));
        }
    }
    return max_dist;
}

int main () {
    int C;
    vector<point> P;
    cin >> C;
    P.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> P[i].x >> P[i].y;
    }
    vector<point> H = CH_Andrew(P);
    H.pop_back();
    const auto longest_distance = find_longest_distance(H);
    cout << fixed << setprecision(8) << longest_distance;
    return 0;
}

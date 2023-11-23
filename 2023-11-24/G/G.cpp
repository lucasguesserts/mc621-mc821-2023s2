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

int main () {
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

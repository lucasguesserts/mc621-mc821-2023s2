#include <bits/stdc++.h>
#include <limits>

using namespace std;

using I = int64_t;

// This is partially a copy of the file available at
// https://github.com/stevenhalim/cpbook-code/blob/master/ch7/polygon.cpp

const double EPS = 1e-9;

double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

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

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) { // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

pair<int, double> find_smallest_angle(const vector<point> & P) {
    auto min_angle = numeric_limits<double>::max();
    auto min_angle_index = numeric_limits<int>::max();
    for (int i = 0; i < P.size(); ++i) {
        auto alpha = angle(
            P[i],
            P[(i + 1) % P.size()],
            P[(i + 2) % P.size()]
        );
        if (alpha < min_angle) {
            min_angle = alpha;
            min_angle_index = i;
        }
    }
    return {min_angle_index, min_angle};
}

void cut(vector<point> & P) {
    while (true) {
        auto pr = find_smallest_angle(P);
        auto & min_angle_index = pr.first;
        auto & min_angle = pr.second;
        auto P_ = P;
        P_.erase(P_.begin() + (min_angle_index + 1) % P_.size());
        auto pr_ = find_smallest_angle(P_);
        auto & min_angle_index_ = pr_.first;
        auto & min_angle_ = pr_.second;
        if (min_angle_ < min_angle) {
            break;
        } else {
            P = P_;
        }
    }
    return;
}

int main() {
    while (true) {
        I n = 0;
        vector<point> P;
        cin >> n;
        if (n == 0) break;
        P.resize(n);
        for (auto & p : P) {
            cin >> p.x >> p.y;
        }
        cut(P);
        cout << P.size();
        for (auto & p : P) {
            cout << " " << p.x << " " << p.y;
        }
        cout << endl;
    }
    return 0;
}

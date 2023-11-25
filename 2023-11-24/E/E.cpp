#include <bits/stdc++.h>

using namespace std;

// This is a partial copy of the code available at:
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

vec normalized(point a, point b) {
    auto v = toVec(a, b);
    auto d = hypot(v.x, v.y);
    v.x /= d;
    v.y /= d;
    return v;
}

double dist(point p1, point p2) { // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y);
} // return double

double length(vector<point> & P) {
    double l = 0.0;
    for (auto i = 0u; i < P.size() - 1; ++i)
        l += dist(P[i], P[i + 1]);
    return l;
}

int main() {
    // variables
    int N;
    int NP, NT;
    vector<point> P;
    vector<point> T; // tree position
    cout << fixed << setprecision(2);
    // input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        // input
        cin >> NP >> NT;
        P.clear();
        P.resize(NP);
        T.clear();
        for (int j = 0; j < NP; j++) {
            cin >> P[j].x >> P[j].y;
        }
        // solution
        auto road_length = length(P);
        auto space = road_length / (NT - 1);
        auto space_to_cover = space;
        T.push_back(P[0]);
        auto last_point = T.back();
        for (auto j = 1u; j < P.size(); ++j) {
            while (true) {
                if (last_point == P[j]) {
                    break;
                }
                auto v_ = normalized(last_point, P[j]);
                v_.x *= space_to_cover;
                v_.y *= space_to_cover;
                auto candidate_point = point(last_point.x + v_.x, last_point.y + v_.y);
                auto distance_covered = dist(last_point, candidate_point);
                auto max_distance_to_cover = dist(last_point, P[j]);
                if (distance_covered > max_distance_to_cover + EPS) {
                    space_to_cover -= max_distance_to_cover;
                    last_point = P[j];
                    break;
                } else {
                    T.push_back(candidate_point);
                    last_point = T.back();
                    space_to_cover = space;
                }
            }
        }
        // output
        cout << "Road #" << i << ":" << endl;
        for (const auto & t : T) {
            cout << t.x << " " << t.y << endl;
        }
        cout << endl;
    }
    return 0;
}

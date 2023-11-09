#include <bits/stdc++.h>
using namespace std;

/*
    Adapting types and functions from Competitive Programming repo
    https://github.com/stevenhalim/cpbook-code/tree/master/ch7
*/

struct point_i {
    int x, y;
    point_i() { x = y = 0; }
    point_i(int _x, int _y) : x(_x), y(_y) {} 

    bool operator < (point_i other) const {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
    
    bool operator == (point_i other) const {
        return (x == other.x && y == other.y);
    }
};

/*  Receives a vector of points.
    Returns true if the points have symmetry in the x-axis.
*/
bool x_symmetric(vector<point_i> points) {
    sort(points.begin(), points.end());

    set<point_i> existing_points;
    for (auto p : points)
        existing_points.insert(p);
    
    point_i leftmost = points[0],
            rightmost = points[points.size()-1];

    int doubled_mid_x = leftmost.x + rightmost.x;

    // check first ceil(n/2) points for their counterparts
    for (int i = 0; i <= points.size()/2; i++) {
        int sym_x = doubled_mid_x - points[i].x;
        auto counterpart = point_i(sym_x, points[i].y);
        if (existing_points.count(counterpart) == 0)
            return false;
    }
    return true;
}

int main() {
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int npoints;
        cin >> npoints;
        vector<point_i> P;
        P.reserve(npoints);
        while (npoints--) {
            int x, y;
            cin >> x >> y;
            P.push_back(point_i(x, y));
        }
        cout << (x_symmetric(P) ? "YES" : "NO") << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct point_i {
    int x, y;
    point_i() { x = y = 0.0; }
    point_i(int _x, int _y) : x(_x), y(_y) {}
};

// returns signed area of polygon P (negative means points in clockwise)
double signed_area(const vector<point_i> & P) {
    int n = P.size();
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        ans += (P[i].x*P[j].y - P[j].x*P[i].y);
    }
    return ans/2.0;
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

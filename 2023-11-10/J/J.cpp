#include <bits/stdc++.h>

#define SIGN(x) ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))

using namespace std;

struct point_i {
    int x, y;
    point_i() { x = y = 0; }
    point_i(int _x, int _y) : x(_x), y(_y) {}
};

point_i read_point() {
    int x, y;
    cin >> x >> y;
    return point_i(x, y);
}

int main () {
    int n;
    while ((cin >> n) && n) {
        vector<point_i> points;
        for (int i = 0; i < n; i++)
            points.push_back(read_point());
        point_i center = points[n/2];

        unsigned stan = 0, ollie = 0;
        for (auto p : points) {
            int relative_position = SIGN(p.x - center.x)*SIGN(p.y - center.y);
            if (relative_position == 1)
                stan++;
            else if (relative_position == -1)
                ollie++;
        }
        cout << stan << " " << ollie << endl;
    }
    return 0;
}

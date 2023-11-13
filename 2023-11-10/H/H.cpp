#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9;
const double EPS = 1e-9;

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2) {
  return hypot(p1.x-p2.x, p1.y-p2.y);
}

struct line { double a, b, c; };

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(const point &a, const point &b) {
    return vec(b.x-a.x, b.y-a.y);
}
vec scale(const vec &v, double s) {
    return vec(v.x*s, v.y*s);
}

point translate(const point &p, const vec &v) {
    return point(p.x+v.x, p.y+v.y);
}

double dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); }

double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  // formula: c = a + u*ab
  c = translate(a, scale(ab, u));                // translate a to c
  return dist(p, c);                             // Euclidean distance
}

// returns the distance from p to the line segment ab defined by
// two points a and b (technically, a has to be different than b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) {                                 // closer to a
    c = point(a.x, a.y);
    return dist(p, a);                           // dist p to a
  }
  if (u > 1.0) {                                 // closer to b
    c = point(b.x, b.y);
    return dist(p, b);                           // dist p to b
  }
  return distToLine(p, a, b, c);                 // use distToLine
}

int main () {
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

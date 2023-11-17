#include <bits/stdc++.h>
using namespace std;

/* Auxiliary functions from https://github.com/stevenhalim/cpbook-code/blob/master/ch7/ */

const double EPS = 1e-9;

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
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
    double cos_theta = (p1.x - center.x)/r;
    double theta = acos(cos_theta); 

    double  xmin = p1.x,
            xmax = p1.x,
            ymin = p1.y,
            ymax = p1.y;

    for (int i = 1; i < nvertices; i++) {
        double  x = center.x + r*cos(theta + (2*i*M_PI)/nvertices),
                y = center.y + r*sin(theta + (2*i*M_PI)/nvertices);

        if (x < xmin)
            xmin = x;
        else if (x > xmax)
            xmax = x;

        if (y < ymin)
            ymin = y;
        else if (y > ymax)
            ymax = y;
    }
    

    return (xmax - xmin)*(ymax - ymin);
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

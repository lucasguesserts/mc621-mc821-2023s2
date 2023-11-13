#include <bits/stdc++.h>
using namespace std;

/*
    Using types and functions from Competitive Programming repo
    https://github.com/stevenhalim/cpbook-code/tree/master/ch7
*/

double DEG_to_RAD(double d) { return d*M_PI/180.0; }

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2) {
    return hypot(p1.x-p2.x, p1.y-p2.y);
}

/* Rounded distance of a point to the origin of the plane. */
uint64_t rounded_magnitude(point p) {
    return (uint64_t) (dist(p, point(0.0, 0.0)) + 0.5);
}

/*  Receives the number of commands to be read.
    Reads commands and returns final position (starting from origin). */
point pos_after_commands(int ncommands) {
    double  current_x = 0.0,
            current_y = 0.0;
    int current_angle = 0;
    while (ncommands--) {
        string command;
        int argument;
        cin >> command >> argument;
        switch(command[0]) {
            case 'f':
                current_x += argument*cos(DEG_to_RAD(current_angle));
                current_y += argument*sin(DEG_to_RAD(current_angle));
                break;
            case 'b': 
                current_x -= argument*cos(DEG_to_RAD(current_angle));
                current_y -= argument*sin(DEG_to_RAD(current_angle));
                break;
            case 'l':
                current_angle -= argument;
                break;
            case 'r':
                current_angle += argument;
                break;
        }
    }
    return point(current_x, current_y);
}

int main() {
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int ncommands;
        cin >> ncommands;
        point final_pos = pos_after_commands(ncommands);
        cout << rounded_magnitude(final_pos) << endl;
    }
    return 0;
}

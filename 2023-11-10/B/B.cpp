// ==================== LICENSE ====================

/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
*/

// ==================== Solution Description ====================

/*
# [Kattis - Logo](https://open.kattis.com/problems/logo)

This is a simple matter of simulating the commands and checking the distance
between the starting and final positions. For simplicity, we may consider the
initial position as being the origin and the initial angle as being zero.

To be more explicit, we start with `current_x = current_y = 0.0` and `current_angle = 0`.
(We may store the angle, in degrees, as an integer.)

When we read a command in the form `comm argument`, then:

* if `comm` is a displacement (either forward or backward), then `argument` is
the magnitude (hypothenuse) of the movement, and we update `current_x` and `current_y`
accordingly: by increasing (or decreasing) them by `argument*cos(theta)` and `argument*sin(theta)`
respectively, where `theta` is the `current_degree` in radians;

* if `comm` is a turn, then we simply update `current_angle` accordingly (increasing for
right turn, decreasing for left turn).*/

// ==================== Code ====================

#include <bits/stdc++.h>
using namespace std;

/*
    Using types and functions from Competitive Programming repo
    https://github.com/stevenhalim/cpbook-code/tree/master/ch7
*/

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y)
        : x(_x)
        , y(_y) {}
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

/* Rounded distance of a point to the origin of the plane. */
uint64_t rounded_magnitude(point p) {
    return (uint64_t)(dist(p, point(0.0, 0.0)) + 0.5);
}

/*  Receives the number of commands to be read.
    Reads commands and returns final position (starting from origin). */
point pos_after_commands(int ncommands) {
    double current_x = 0.0,
           current_y = 0.0;
    int current_angle = 0;
    while (ncommands--) {
        string command;
        int argument;
        cin >> command >> argument;
        switch (command[0]) {
        case 'f':
            current_x += argument * cos(DEG_to_RAD(current_angle));
            current_y += argument * sin(DEG_to_RAD(current_angle));
            break;
        case 'b':
            current_x -= argument * cos(DEG_to_RAD(current_angle));
            current_y -= argument * sin(DEG_to_RAD(current_angle));
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

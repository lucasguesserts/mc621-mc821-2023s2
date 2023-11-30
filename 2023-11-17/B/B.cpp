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
# [All Different Directions](https://open.kattis.com/problems/alldifferentdirections)

The problem is straight-forward: compute the final position for each person asked, take the average (componentwise), and then for each final position, compute the distance to the average value computed.

For this implementation, one used complex values (because the complex set is isomorphic to $\mathbb{R}^2$):

* Positions are represented by a complex value;
* Angles can be converted to a complex value using: $c = \cos(\theta) + i \sin(\theta)$;
* To rotate a complex number (rotate the angle being faced) by $\alpha$, multiply it by $c = \cos(\alpha) + i \sin(\alpha)$;
* To walk a distance $d$, simply add $d \cdot a$ to the current position, where $a$ is the current angle being faced (as a complex number);
*/

// ==================== Code ====================

#include <bits/stdc++.h>
#include <iomanip>
#include <sstream>

using namespace std;

using I = int64_t;
using VI = vector<I>;
using D = double;
using C = complex<D>;
using VC = vector<C>;

auto degree_to_angle(const double & degree) -> C {
    const auto theta = degree * M_PI / 180.0;
    return C(cos(theta), sin(theta));
}

auto average(const VC & positions) -> C {
    C sum(0, 0);
    for (const auto & position : positions) {
        sum += position;
    }
    return sum / static_cast<D>(positions.size());
}

auto get_worst_distance(const VC & positions, const C & average_position) -> D {
    D worse_distance = -1.0;
    for (const auto & position : positions) {
        const auto distance = abs(position - average_position);
        if (distance > worse_distance) {
            worse_distance = distance;
        }
    }
    return worse_distance;
}

int main() {
    while (true) {
        I n;
        scanf("%lld\n", &n);
        if (n == 0) {
            break;
        }
        string line;
        VC final_positions;
        for (I i = 0; i < n; ++i) {
            getline(cin, line);
            stringstream ss(line);
            string command;
            D x, y, t, d;
            C position, angle;
            ss >> x >> y;
            position = C(x, y);
            ss >> command;
            if (command != "start") {
                throw runtime_error("Expected 'start' command");
            }
            ss >> t;
            angle = degree_to_angle(t);
            while (!ss.eof()) {
                ss >> command;
                if (command == "turn") {
                    ss >> t;
                    angle *= degree_to_angle(t);
                } else if (command == "walk") {
                    ss >> d;
                    position += d * angle;
                } else {
                    throw runtime_error("Unknown command");
                }
            }
            final_positions.push_back(position);
        }
        const auto average_position = average(final_positions);
        const auto worst_distance = get_worst_distance(final_positions, average_position);
        cout << setprecision(6) << average_position.real() << " " << average_position.imag() << " " << worst_distance << endl;
    }
    return 0;
}

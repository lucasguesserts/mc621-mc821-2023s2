#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>

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

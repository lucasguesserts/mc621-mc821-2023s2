#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <ios>

using namespace std;

using I = int64_t;
using D = long double;
using VD = vector<D>;
using SD = set<D>;
using SI = set<I>;

// constexpr D _2_PI = 2 * M_PI;
constexpr I FULL_ROTATION = 360 * 60 * 60;

D seconds_to_radians(I seconds) {
    D degree = seconds / 3600.0;
    D radians = degree * M_PI / 180.0;
    return radians;
}

void print_solution(I angle, D radius) {
    D angle_radians = seconds_to_radians(angle);
    D area = radius * radius * angle_radians / 2.0;
    cout << area << endl;
}

int main () {
    I T;
    cin >> T;
    cout.precision(7);
    cout << fixed;
    while (T--) {
        I n, d, m, s;
        D r;
        cin >> r >> n >> d >> m >> s;
        I a = d * 3600 + m * 60 + s;
        if (n == 0 || n == 1) {
            print_solution(FULL_ROTATION, r);
            continue;
        }
        SI A;
        for (I i = 0; i < n; ++i) {
            D x = remainder(i * a, FULL_ROTATION);
            if (x < 0) {
                x += FULL_ROTATION;
            }
            if (A.count(x) > 0) {
                break;
            }
            A.insert(x);
        }
        SI A_diff;
        for (auto it = A.begin(); it != prev(A.end()); ++it) {
            auto next_it = next(it);
            A_diff.insert(*next_it - *it);
        }
        A_diff.insert((FULL_ROTATION - (*A.rbegin() - *A.begin())) % FULL_ROTATION);
        I A_max = *A_diff.crbegin(); // set is sorted, the last is the largest
        print_solution(A_max, r);
    }
    return 0;
}

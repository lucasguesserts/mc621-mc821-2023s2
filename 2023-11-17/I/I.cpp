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
# [Biggest Slice](https://open.kattis.com/problems/biggest)

The problem is actually simple:

1. mark the angles of each cut;
2. sort the angles;
3. compute the differences;
4. find the biggest difference;
5. compute the area for the biggest difference:
   $$ A = \pi r^2 \dfrac{\alpha}{2\pi} = \dfrac{r^2 \alpha}{2} $$
   where $\alpha$ is the angle of the biggest difference;

There are a few catches though:

1. when computing the differences, add an entry equals to `FULL_ROTATION - (last_angle - first_angle)`, being `last_angle, first_angle` the angles of the sorted differences. This is necessary because one may fully rotate the pizza many times;
2. if `n == 0`, then the area of the biggest slice is `PI * r * r`;
3. if `n == 1`, then the area of the biggest slice is still `PI * r * r`;
*/

// ==================== Code ====================

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

int main() {
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

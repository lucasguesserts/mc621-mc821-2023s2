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
# [Platforme](https://open.kattis.com/problems/platforme)

There are at most $100$ platforms and the time limit is $1 s$, which means that a naive implementation which visits every platform for every platform is enough.

The algorithm becomes very simple then:

1. Initialize $L = 0$, the total length of pillars needed to support all the platforms;
2. Add a platform to represent the floor: $G = \left\langle 0, 0, LIMIT \right\rangle$ (use $LIMIT = 10000$);
3. For each platform $p = \left\langle y, x_i, x_f \right\rangle$:
   1. Skip it if $y = 0$;
   2. Let $c = \left\langle y, x \right\rangle$ be the cell where the a pillar will be placed;
   3. Find a platform $p' = \left\langle y', x_i', x_f' \right\rangle$ which satisfy: $x_i' \leq x \leq x_f'-1$, $y' < y$ and $y'$ is the maximum possible;
   4. Increase $L$ by $y - y'$;
   5. Do the above procedure for the cell $\left\langle y, x_i \right\rangle$, and $\left\langle y, x_f - 1 \right\rangle$;

Notice that one has to be careful with the $-1$ in some places...
*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

using I = int64_t;

constexpr I LIMIT = 10000;

struct Platform {
    I y, xi, xf;

    Platform(I y, I xi, I xf)
        : y(y)
        , xi(xi)
        , xf(xf) {}
};

using VP = vector<Platform>;

struct Cell {
    I x, y;

    Cell(I x, I y)
        : x(x)
        , y(y) {}
};

auto find_support_platform(const Cell & cell, const VP & platforms) -> Platform {
    // guaranteed to find one
    Platform support_platform = Platform(LIMIT, LIMIT - 1, LIMIT); // ceil
    I minimum_vertical_distance = LIMIT + 1;
    for (const auto & platform : platforms) {
        if (!(cell.y > platform.y)) continue;
        const bool match_in_x = (platform.xi <= cell.x) && (cell.x <= platform.xf - 1);
        if (match_in_x) {
            const auto vertical_distance = cell.y - platform.y;
            if (vertical_distance < minimum_vertical_distance) {
                minimum_vertical_distance = vertical_distance;
                support_platform = platform;
            }
        }
    }
    return support_platform;
}

int main() {
    I N;
    cin >> N;
    VP platforms;
    for (I i = 0; i < N; ++i) {
        I y, xi, xf;
        cin >> y >> xi >> xf;
        platforms.emplace_back(y, xi, xf);
    }
    platforms.emplace_back(0, 0, LIMIT); // floor
    I pillars_length = 0;
    for (I i = 0; i < platforms.size() - 1; ++i) {
        const auto & p = platforms[i];
        if (p.y == 0) { continue; }
        { // left
            Cell cell(p.xi, p.y);
            const auto & support_platform = find_support_platform(cell, platforms);
            pillars_length += cell.y - support_platform.y;
        }
        { // right
            Cell cell(p.xf - 1, p.y);
            const auto & support_platform = find_support_platform(cell, platforms);
            pillars_length += cell.y - support_platform.y;
        }
    }
    cout << pillars_length;
    return 0;
}

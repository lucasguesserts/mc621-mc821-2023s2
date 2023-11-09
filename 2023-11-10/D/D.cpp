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

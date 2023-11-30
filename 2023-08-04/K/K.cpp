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
# [Luke is a Foodie](https://codeforces.com/problemset/problem/1704/B)

Consider the following input:

```plain
8 2
2 7 8 9 6 13 21 28
```

Let's map each number into two numbers: the lower and upper bound accepted for Luke to eat it:

```plain
2 -> [0, 4]
7 -> [5, 9]
8 -> [6, 10]
9 -> [7, 11]
6 -> [4, 8]
13 -> [11, 15]
21 -> [19, 23]
28 -> [26, 30]
```

Consider a lower bound `l = -oo` and an upper bound `u = +oo`, which define a range `[l, u]` of valid values for the food affinity. Initially, `l = -oo` and `u = +oo`. Now, for the range `[fl, fu]` of each food, we have two cases:

1. there is an intersection between the ranges, so choose `l = max{l, fl}` and `u = min{u, fu}`;
2. the intersection of the ranges is empty. For this case, one will need to reset the food affinity, so one will reset the bounds to `l = -oo` and `u = +oo`;

See the following example:

```plain
initialization: l = -oo, u = +00
2 -> [0, 4] -> l = 0, u = 4
7 -> [5, 9] -> incompatible with the current range
REINITIALIZE BOUNDS
initialization: l = -oo, u = +00
7 -> [5, 9] -> l = 5, u = 9
8 -> [6, 10] -> l = 6, u = 9
9 -> [7, 11] -> l = 7, u = 9
6 -> [4, 8] -> l = 7, u = 8
13 -> [11, 15] -> incompatible with the current range
REINITIALIZE BOUNDS
initialization: l = -oo, u = +00
13 -> [11, 15] -> l = 11, u = 15
21 -> [19, 23] -> incompatible with the current range
REINITIALIZE BOUNDS
initialization: l = -oo, u = +00
21 -> [19, 23] -> l = 19, u = 23
28 -> [26, 30] -> incompatible with the current range
REINITIALIZE BOUNDS
initialization: l = -oo, u = +00
28 -> [26, 30] -> l = 26, u = 30
```

In the end, the number of times the bounds were reset is the answer to the problem.
*/

// ==================== Code ====================

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

using Pile = vector<int>;

struct Bounds {
    int lower;
    int upper;

    Bounds(const int lower, const int upper)
        : lower(lower)
        , upper(upper){};

    Bounds()
        : lower(0)
        , upper(1000000000){};
};

using BoundVector = vector<Bounds>;

int get_number() {
    int t;
    cin >> t;
    return t;
}

Pile get_pile(const int pile_size) {
    Pile pile;
    pile.reserve(pile_size);
    for (auto i = 0u; i < pile_size; ++i) {
        int value;
        cin >> value;
        pile.push_back(value);
    }
    return pile;
}

BoundVector get_bounds(const Pile & pile, const int tolerance) {
    BoundVector bounds;
    bounds.reserve(pile.size());
    for (const auto & value : pile) {
        bounds.push_back({max(value - tolerance, 0), value + tolerance});
    }
    return bounds;
}

bool do_intervals_have_intersection(const Bounds & lhs, const Bounds & rhs) {
    return lhs.upper >= rhs.lower && rhs.upper >= lhs.lower;
}

void update_bounds(Bounds & bound, const Bounds food_bound) {
    bound.lower = max(bound.lower, food_bound.lower);
    bound.upper = min(bound.upper, food_bound.upper);
    return;
}

int main() {
    const auto number_of_cases = get_number();
    for (auto case_number = 0u; case_number < number_of_cases; ++case_number) {
        const auto pile_size = get_number();
        const auto tolerance = get_number();
        const auto pile = get_pile(pile_size);
        const auto pile_bounds = get_bounds(pile, tolerance);
        auto reset_counter = int{0};
        auto bounds = Bounds{};
        for (const auto & food_bounds : pile_bounds) {
            if (do_intervals_have_intersection(bounds, food_bounds)) {
                update_bounds(bounds, food_bounds);
            } else {
                bounds = food_bounds;
                ++reset_counter;
            }
        }
        cout << reset_counter << endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

using Pile = vector<int>;

struct Bounds {
    int lower;
    int upper;

    Bounds(const int lower, const int upper)
    : lower(lower), upper(upper) {};

    Bounds()
    : lower (0), upper(1000000000) {};
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

BoundVector get_bounds(const Pile& pile, const int tolerance) {
    BoundVector bounds;
    bounds.reserve(pile.size());
    for (const auto & value: pile) {
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
        for (const auto & food_bounds: pile_bounds) {
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

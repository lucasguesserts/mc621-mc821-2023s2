#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Number = unsigned int;
using Vector = std::vector<Number>;

Vector make_powers_of_two(const Number k) {
    auto current_value = Number(1);
    auto powers_of_two = Vector(k + 1);
    for (auto i = 0u; i < k + 1; ++i) {
        powers_of_two[i] = current_value;
        current_value *= 2;
    }
    return powers_of_two;
}

auto product(const Vector & lhs, const Vector::const_iterator rhs_it) -> Vector {
    auto result = Vector(lhs.size());
    for (auto i = 0u; i < lhs.size(); ++i) {
        result[i] = lhs[i] * rhs_it[i];
    }
    return result;
}

auto sequence_satisfy_condition(const Vector & sequence) -> bool {
    for (auto i = 0u; i < (sequence.size() - 1); ++i) {
        if (!(sequence[i] < sequence[i + 1])) {
            return false;
        }
    }
    return true;
}

int main () {
    auto number_of_test_cases = Number(0);
    cin >> number_of_test_cases;
    for (auto test_case = 0; test_case < number_of_test_cases; ++test_case) {
        // variables
        auto n = Number(0);
        auto k = Number(0);
        auto a = vector<Number>();;
        auto powers_of_two = vector<Number>();
        // input
        cin >> n >> k;
        a.resize(n);
        for (auto i = 0u; i < n; ++i) {
            cin >> a[i];
        }
        powers_of_two = make_powers_of_two(k);
        // solution
        auto indices_satisfying_condition_count = Number(0);
        for (auto i = 0u; i < (n - k); ++i) {
            auto transformed_subsequence = product(powers_of_two, a.begin() + i);
            if (sequence_satisfy_condition(transformed_subsequence)) {
                ++indices_satisfying_condition_count;
            }
        }
        // output
        cout << indices_satisfying_condition_count << endl;
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using Number = int;
using Size = int;
using Vector = std::vector<Number>;

auto find_indices(const Vector & sequence) -> Vector {
    auto indices = Vector();
    indices.push_back(0);
    for (auto i = 0u; i < (sequence.size() - 1); ++i) {
        if (!(sequence[i] < 2 * sequence[i + 1])) {
            indices.push_back(i);
            indices.push_back(i + 1);
        }
    }
    indices.push_back(sequence.size() - 1);
    return indices;
}

auto count_subsequences(const Size k, const Vector & indices) {
    auto count = Number(0);
    auto lower_bound = decltype(indices[0])(0);
    auto upper_bound = decltype(indices[0])(0);
    for (auto i = 0u; i < (indices.size() - 1); i += 2) {
        auto lower_bound = indices[i];
        auto upper_bound = indices[i + 1];
        const auto number_of_valid_subsequences = (upper_bound - lower_bound + 1) - (k + 1) + 1;
        if (number_of_valid_subsequences > 0) {
            count += number_of_valid_subsequences;
        }
    }
    return count;
}

int main() {
    auto number_of_test_cases = Number(0);
    cin >> number_of_test_cases;
    for (auto test_case = 0; test_case < number_of_test_cases; ++test_case) {
        // variables
        auto n = Number(0);
        auto k = Number(0);
        auto a = vector<Number>();
        // input
        cin >> n >> k;
        a.resize(n);
        for (auto i = 0u; i < n; ++i) {
            cin >> a[i];
        }
        // solution
        const auto partition_indices = find_indices(a);
        const auto indices_satisfying_condition_count = count_subsequences(k, partition_indices);
        // output
        cout << indices_satisfying_condition_count << endl;
    }
    return 0;
}

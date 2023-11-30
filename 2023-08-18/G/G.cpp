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
# [2^Sort](https://codeforces.com/problemset/problem/1692/G)

The condition

```plain
2^{0} . a_{i} < ... < 2^{k} . a_{i + k}
```

is equivalent to:

```plain
a_{i + j} < 2^{1} . a_{i + j + 1} , \forall j = 0, ..., (k - 1)
```

So one can partition the sequence `a_{1}, ..., a_{n}` in the indices which do not satisfy the condition above:

```plain
[lb_{1}, ub_{1}], ..., [lb_{m}, ub_{m}]
```

where `lb_{i} = ub_{i - 1} + 1` (and `ub_{i} = lb_{i + 1} - 1`) for `i = 2, ..., (m - 1)`, `lb_{1} = 1`, and `ub_{m} = n`.

Notice that, in the subsequence induced by the indices `[lb_{m}, ub_{m}]`, the condition holds. Furthermore, there are `(ub_{m} - lb_{m} + 1) - (k + 1) + 1` subsequences of length `k + 1` which satisfy the condition of the problem.

Thus, the answer for the problem is (notice that the `max` removes the negative values):

```plain
sum_{i = 1}^{m} max[(ub_{i} - lb_{i} + 1) - (k + 1) + 1, 0]
```
*/

// ==================== Code ====================

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

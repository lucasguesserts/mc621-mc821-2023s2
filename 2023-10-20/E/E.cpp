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
# [Kattis - Bridging Signals](https://open.kattis.com/problems/signals)

It is the [Longest Increasing Subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence) problem (solvable in `O(n log n)` time): given the signal mapping, requiring that there is no cross is the same as requiring that ports connect in increasing order.
*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

using I = int64_t;
using VI = vector<I>;

// https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn/
int maximum_increasing_subsequence(VI & seq) {
    VI sub;
    for (int x : seq) {
        if (sub.empty() || sub[sub.size() - 1] < x) {
            sub.push_back(x);
        } else {
            auto it = lower_bound(sub.begin(), sub.end(), x);
            *it = x;
        }
    }
    return sub.size();
}

int main() {
    I p = -1;
    VI a{};
    I s = -1;
    // input
    cin >> p;
    for (I i = 0; i < p; ++i) {
        I x;
        cin >> x;
        a.push_back(x);
    }
    // solution
    s = maximum_increasing_subsequence(a);
    // output
    cout << s;
    return 0;
}

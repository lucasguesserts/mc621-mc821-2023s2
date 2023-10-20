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

int main () {
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

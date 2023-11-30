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
# [UVa 760 - DNA Sequencing](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=701)

Use the DP algorithm for the Longest Common Subsequence problem (links below). However, instead of storing only the size of the substring, store the substring itself. Once the solution has been found, use the naive algorithm: go through all the table and find all subsequences that have the same size as the largest one. Store the subsequences in a set, so duplicates are ignored and the sequence is sorted.

## Links

* [geek for geek - Longest Common Subsequence](https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/);
* [wikipedia - Longest Common Subsequence](https://en.wikipedia.org/wiki/Longest_common_subsequence);
*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

set<string> LCS(const string & x, const string & y) {
    const int n = x.size();
    const int m = y.size();
    auto lcs = vector<vector<string>>(n + 1, vector<string>(m + 1, ""));
    // compute
    auto result = size_t(0);
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            if (i == 0 || j == 0) {
                lcs[i][j] = "";
            } else if (x[i - 1] == y[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + x[i - 1];
                result = max(result, lcs[i][j].size());
            } else lcs[i][j] = "";
        }
    }
    if (result == 0) {
        return {};
    }
    // find all
    set<string> longest_common_substrings;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            if (lcs[i][j].size() == result) {
                longest_common_substrings.insert(lcs[i][j]);
            }
        }
    }
    return longest_common_substrings;
}

int main() {
    bool first = true;
    while (true) {
        string lhs, rhs, newline;
        // input
        getline(cin, lhs);
        if (cin.eof()) {
            break;
        }
        if (!first) {
            cout << endl;
        }
        first = false;
        getline(cin, rhs);
        getline(cin, newline);
        // solution
        auto solution = LCS(lhs, rhs);
        // output
        // cout << solution << endl;
        if (solution.empty()) {
            cout << "No common sequence." << endl;
        } else {
            for (const auto & s : solution) {
                cout << s << endl;
            }
        }
    }
    return 0;
}

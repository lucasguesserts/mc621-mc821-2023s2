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

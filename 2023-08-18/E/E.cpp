#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<unsigned, vector<unsigned>> M;

vector<unsigned> solve(const unsigned n) {
    if (n == 1) {
        return M[1];
    } else if (n == 2) {
        return M[2];
    } else {
        unsigned min_len = 1000000000;
        for (auto i = 0u; i < (decltype(n)) floor(n/2.0); ++i) {
            auto l = solve(n-i);
            auto u = solve(i);

        }
    }
}

int main () {
    M[1] = {1};
    M[2] = {2, 1};
    auto n = unsigned{1};
    while (true) {
        // input
        cin >> n;
        if (n == 0) break;
        auto s = vector<decltype(n)>{n};
        // solution
        auto x = n;
        while (x != 1) {
            auto c = (decltype(n)) ceil(x/2.0);
            auto f = (decltype(n)) floor(x/2.0);
            s.push_back(c);
            if (c != f) {
                s.push_back(f);
            }
            x = f;
        }
        reverse(s.begin(), s.end());
        // output
        for (const auto & v : s) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}

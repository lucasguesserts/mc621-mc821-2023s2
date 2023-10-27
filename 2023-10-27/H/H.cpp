#include <bits/stdc++.h>
#include <limits>

using namespace std;

const string all_letters = "abcdefghijklmnopqrstuvwxyz";
const int inf = numeric_limits<int>::max();

using M = map<char, int>;

M init() {
    M m;
    for (const auto & c : all_letters) {
        m[c] = inf;
    }
    return m;
}

int main () {
    int T;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        auto m = init();
        int minimum_index = inf;
        for (int i = s.size() - 1; i >=0; --i) {
            auto it = m.find(s[i]);
            if (it->second == inf) {
                it->second = i;
                minimum_index = i;
            }
        }
        cout << s.substr(minimum_index, s.size() - minimum_index) << endl;
    }
    return 0;
}

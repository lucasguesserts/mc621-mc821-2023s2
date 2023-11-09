#include <bits/stdc++.h>

using namespace std;

string get_cycle(string s, int i) {
    s = s.substr(i) + s.substr(0, i);
    return s;
}

int find_min_cycle(const string s) {
    auto minimum = s;
    int i_min = 0;
    for (int i = 0; i < s.size(); i++) {
        auto cycle = get_cycle(s, i);
        if (cycle < minimum) {
            minimum = std::move(cycle);
            i_min = i;
        }
    }
    return i_min;
}

int main () {
    int T;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        auto i = find_min_cycle(s);
        cout << i + 1 << endl;
    }
    return 0;
}

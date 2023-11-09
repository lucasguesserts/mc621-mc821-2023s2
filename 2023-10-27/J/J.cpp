#include <bits/stdc++.h>

using namespace std;

using I = int64_t;
using VS = vector<string>;

bool has_prefix(const VS & a) {
    for (I i = 0; i < a.size() - 1; ++i) {
        if (a[i+1].find(a[i]) != string::npos) {
            return true;
        }
    }
    return false;
}

int main () {
    I T;
    cin >> T;
    while (T--) {
        I n;
        cin >> n;
        VS a(n);
        for (auto & ai : a) {
            cin >> ai;
        }
        sort(a.begin(), a.end());
        auto is_consistent = has_prefix(a) ? "NO" : "YES";
        cout << is_consistent << endl;
    }
    return 0;
}

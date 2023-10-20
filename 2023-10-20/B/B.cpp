#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

bool have_common_char(string s, string t) {
    unordered_set<char> set_s;
    for (auto c: s) set_s.insert(c);
    for (auto c: t)
        if (set_s.count(c))
            return true;
    return false;
}

int main () {
    int n; cin >> n;
    while (n--) {
        string s, t;
        cin >> s >> t;
        cout << (have_common_char(s, t)? "YES" : "NO") << endl;
    }
    return 0;
}

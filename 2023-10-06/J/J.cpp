#include <iostream>
#include <string>

using namespace std;

int solve(const string & s) {
    int l = 0;
    string rep = "";
    while (true) {
        rep += s[l];
        ++l;
        if (s.size() % l != 0) continue;
        string sub;
        for (int i = 0; i < s.size() / l; ++i) {
            sub += rep;
        }
        if (s == sub) {
            break;
        }
    }
    return l;
}

int main () {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
        if (N != 0) {
            cout << endl;
        }
    }
    return 0;
}

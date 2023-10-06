#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

using I = long long int;

I find_min_length(const string & s, const I b, const I e) {
    if (b > e) {
        return I(0);
    }
    else if (s[b] != s[e]) {
        return find_min_length(s, b+1, e-1);
    } else {
        return e - b + 1;
    }
}

int main() {
    I T, n;
    string s;
    cin >> T;
    while (T--) {
        if (cin.eof()) break;
        cin >> n;
        cin >> s;
        cout << find_min_length(s, 0, n-1) << endl;
    }
    return 0;
}

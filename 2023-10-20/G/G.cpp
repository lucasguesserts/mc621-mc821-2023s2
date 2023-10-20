#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool is_square(string s) {
    int n = s.length();
    if (n % 2) return false;
    for (int i = 0; i < n/2; i++)
        if (s[i] != s[n/2+i]) return false;
    return true;
}

int main () {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        string s;
        cin >> s;
        cout << (is_square(s) ? "YES" : "NO") << endl;
    }
    return 0;
}

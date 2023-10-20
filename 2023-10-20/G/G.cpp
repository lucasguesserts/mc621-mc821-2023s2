#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool is_square(string s) {
    int n = s.length();
    if (n % 2) return false;
    int i = 0, j = n/2;
    while (i < n/2 && j < n)
        if (s[i++] != s[j++]) return false;
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

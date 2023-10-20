#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_set>

using namespace std;

bool can_form_new(string s) {
    int n = s.length();
    unordered_set<char> unique_chars;
    for (int i = 0; i < n/2; i++)
        unique_chars.insert(s[i]);
    return unique_chars.size() > 1;
}

int main () {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        string palindrome;
        cin >> palindrome;
        cout << (can_form_new(palindrome) ? "YES" : "NO") << endl;
    }
    return 0;
}

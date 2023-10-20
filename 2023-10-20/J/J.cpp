#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool is_pangram(string s) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    unordered_set<char> found;
    for (auto c: s) found.insert(tolower(c));
    for (auto c: alphabet)
        if (!found.count(c))
            return false;
    return true;
}
int main () {
    int n;
    string in;
    cin >> n >> in;
    cout << (is_pangram(in) ? "YES" : "NO") << endl;
    return 0;
}

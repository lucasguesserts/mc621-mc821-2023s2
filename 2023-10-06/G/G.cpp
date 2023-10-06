#include <iostream>
#include <string>

using namespace std;

unsigned shortest_starting(string s, int len) {
    int first, last;
    for (first = 0, last = len-1; s[first++] != s[last--] && len; len -= 2);
    return len;
}

int main () {
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int len;
        string in;
        cin >> len >> in;
        cout << shortest_starting(in, len) << endl;
    }
    return 0;
}

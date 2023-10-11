#include <iostream>
#include <regex>

using namespace std;

int main() {
    int ncases;
    cin >> ncases;
    regex pattern("^[Mm]+[Ee]+[Oo]+[Ww]+$");
    while (ncases--) {
        int len;
        string in;
        cin >> len >> in;
        cout << (regex_search(in, pattern) ? "YES" : "NO") << endl;
    }
    return 0;
}


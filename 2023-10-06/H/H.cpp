#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main () {
    bool escaped = true;
    regex pattern("FBI");
    for (int i = 1; i <= 5; i++) {
        string s;
        cin >> s;
        if (regex_search(s, pattern)) {
            cout << i << " ";
            escaped = false;
        }
    }
    if (escaped)
        cout << "HE GOT AWAY!";
    cout << endl;
    return 0;
}

#include <iostream>
#include <string>

#define RES_0       "5.5957541127"
#define RES_1       "1.7320508076"
#define RES_2       "-0.2679491924"
#define RES_ODD     "-1.4226497308"
#define RES_EVEN    "-2.5773502692"

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        if (s == "0") cout << RES_0;
        else if (s == "1") cout << RES_1;
        else if (s == "2") cout << RES_2;
        else {
            unsigned last = s[s.size()-1] - '0';
            if (last % 2) cout << RES_ODD;
            else cout << RES_EVEN;
        }
        cout << endl;
    }
    return 0;
}

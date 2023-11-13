#include <bits/stdc++.h>

using namespace std;

using I = int64_t;
using R = double;

constexpr R EIGHT = 8.0;

int main() {
    I T;
    cin >> T;
    while (T--) {
        R BX, BY;
        I N;
        cin >> BX >> BY;
        cin >> N;
        bool found = false;
        for (I i = 0; i < N; ++i) {
            R CX, CY;
            cin >> CX >> CY;
            if (hypot(BX - CX, BY - CY) <= EIGHT) {
                found = true;
            }
        }
        if (found) {
            cout << "light a candle" << endl;
        } else {
            cout << "curse the darkness" << endl;
        }
    }
    return 0;
}

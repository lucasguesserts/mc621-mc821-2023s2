#include <bits/stdc++.h>

using namespace std;

using I = int64_t;
using D = double;
using C = complex<D>;

int main () {
    I i = 0;
    while (true) {
        D x, y;
        I r;
        cin >> x;
        if (cin.eof()) { break; }
        cin >> y >> r;
        ++i;
        // cout << x << " " << y << " " << r << endl;
        C c(x, y);
        C z(0, 0);
        bool diverges = false;
        for (I j = 0; j < r; j++) {
            z = z*z + c;
            if (abs(z) > 2.0) {
                diverges = true;
                break;
            }
        }
        auto answer = diverges ? "OUT" : "IN";
        cout << "Case " << i << ": " << answer << endl;
    }
    return 0;
}

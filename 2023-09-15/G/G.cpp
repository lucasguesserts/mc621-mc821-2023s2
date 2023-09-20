#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

using I = long long int;

int main() {
    I n, p, w, d;
    cin >> n >> p >> w >> d;
    try {
        // x0
        I x0 = -1;
        for (I x = 0; x <= d; ++x) {
            if ((p % d) == (((w % d) * (x % d)) % d)) {
                x0 = x;
                break;
            }
        }
        if (x0 == -1) {
            throw 0;
        }
        // s
        I sn = static_cast<I>(ceil((d * n - x0 * (w - d) + p) / ((w - d) * d)));
        I sp = static_cast<I>(floor((p - w * x0) / (w * d)));
        I s = min(sp, sn);
        // x
        I x = x0 + s * d;
        // y
        I y = (p - w * x) / d;
        if (y < 0) {
            throw 0;
        }
        // z
        I z = n - x - y;
        if (z < 0) {
            throw 0;
        }
        // output
        cout << x << " " << y << " " << z << endl;
    } catch (...) {
        cout << -1 << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

using I = int64_t;
using D = double;

I M, N;
D R;

D compute_distance(I r1, I r, I a, I r2) {
    D z = 0;
    z += R * (r1 / static_cast<D>(N));
    z += R * (r / static_cast<D>(N)) * M_PI * a / static_cast<D>(M);
    z += R * (r2 / static_cast<D>(N));
    return z;
}

int main() {
    cin >> M >> N >> R;
    I ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    D minimum = numeric_limits<D>::max();
    for (I i = 0; i <= max(ay, by); i++) {
        I r1 = abs(ay - i);
        I r2 = abs(by - i);
        I a = abs(ax - bx);
        auto z = compute_distance(r1, i, a, r2);
        minimum = min(minimum, z);
    }
    cout << setprecision(15) << minimum;
}

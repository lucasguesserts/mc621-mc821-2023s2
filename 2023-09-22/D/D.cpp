#include <iostream>
#include <vector>

using namespace std;

using I = long long int;
using VI = vector<I>;

constexpr I M = 998244353;

void egcd(I a, I b, I & d, I & x, I & y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        return;
    }
    egcd(b, a % b, d, x, y);
    I x1 = y;
    I y1 = x - (a / b) * y;
    x = x1;
    y = y1;
    return;
}

I mod_inv(I a) {
    I d, x, y;
    egcd(a, M, d, x, y);
    return x;
}

VI mod_inv(VI A) {
    VI INV(A.size(), 1);
    for (I i = 0; i < A.size(); ++i) {
        INV[i] = mod_inv(A[i]);
    }
    return INV;
}

VI fact(I n) {
    VI N(n + 1, I(1));
    for (I i = 1; i <= n; ++i) {
        N[i] = (i * N[i - 1]) % M;
    }
    return N;
}

int main() {
    I n;
    cin >> n;
    auto N = fact(n);
    auto NINV = mod_inv(N);
    I x;
    x = n * N[n];
    x %= M;
    for (I k = 1; k < n; ++k) {
        x -= (N[n] * NINV[k]);
        x %= M;
        if (x < 0) x += M;
        x %= M;
    }
    cout << x;
    return 0;
}

#include <iostream>

using namespace std;

using I = long long int;

constexpr I M = 998244353;

I exp(I y) {
    if (y == 0) {
        return I(1);
    } else if (y % 2 == 0) {
        I z = exp(y / 2);
        z *= z;
        z %= M;
        return z;
    } else {
        I z1 = exp(y - 1);
        I z = 2;
        z *= z1;
        z %= M;
        return z;
    }
}

int main() {
    I w, h;
    cin >> w >> h;
    I W = exp(w);
    I H = exp(h);
    I x = W * H;
    x %= M;
    cout << x;
    return 0;
}

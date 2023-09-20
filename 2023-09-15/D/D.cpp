#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

using I = int64_t;

I gcd(I a, I b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
    I len1, len2;
    I a0, a, diff, GCD_a, b;
    cin >> len1 >> len2;
    cin >> a0;
    GCD_a = 0;
    for (I i = 1; i < len1; i++) {
        cin >> a;
        diff = (a > a0) ? a - a0 : a0 - a;
        GCD_a = gcd(diff, GCD_a);
    }
    for (I i = 0; i < len2; i++) {
        cin >> b;
        cout << gcd(a0 + b, GCD_a) << " ";
    }
    cout << endl;
    return 0;
}

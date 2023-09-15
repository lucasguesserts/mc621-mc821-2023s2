#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdint>

#define MAXN    200000

using namespace std;

int64_t gcd(int64_t a, int64_t b) { return (b == 0) ? a : gcd(b, a%b); }

int main() {
    int len1, len2;
    int64_t a0, a, diff, GCD_a, b;
    cin >> len1 >> len2;
    cin >> a0;
    GCD_a = 0;
    for (int i = 1; i < len1; i++) {
        cin >> a;
        diff = (a > a0) ? a-a0 : a0-a;
        GCD_a = gcd(diff, GCD_a);
    }
    for (int i = 0; i < len2; i++) {
        cin >> b;
        cout << gcd(a0 + b, GCD_a) << " ";
    }
    cout << endl;
    return 0;
}

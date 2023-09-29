#include <iostream>

using namespace std;

using Number = long unsigned int;

Number gcd(const Number x, const Number y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    auto N = Number(0);
    auto r0 = Number(0);
    cin >> N;
    cin >> r0;
    for (auto i = 1u; i < N; ++i) {
        auto r = Number(0);
        cin >> r;
        const auto g = gcd(r, r0);
        cout << r0 / g << "/" << r / g << endl;
    }
    return 0;
}

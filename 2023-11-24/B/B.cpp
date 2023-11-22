#include <bits/stdc++.h>

using namespace std;

using I = int64_t;

constexpr I MAX = 40000000; // 4 * 10^7

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    I N;
    cin >> N;
    cout << 0 << " " << 0 << "\n";
    --N;
    I x = MAX;
    I xd = 1;
    I y = 0;
    I yd = 1;
    bool x_turn = true;
    while (N--) {
        cout << x << " " << y << "\n";
        x -= xd;
        y += yd;
        if (x_turn) {
            ++xd;
        } else {
            ++yd;
        }
        x_turn = !x_turn;
    }
    return 0;
}

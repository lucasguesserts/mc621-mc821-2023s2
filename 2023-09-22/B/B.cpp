#include <iostream>

using namespace std;

using N = long long int;

N gcd(N a, N b) { return b == 0 ? a : gcd(b, a % b); }

struct EGCD {

    N a, b, x, y, g;
    N r0, r1;
    N s0, s1;
    N t0, t1;

    EGCD(N a, N b)
        : a(a)
        , b(b) {
        r0 = a;
        r1 = b;
        s0 = 1;
        s1 = 0;
        t0 = 0;
        t1 = 1;
        while (r1 != 0) {
            N r_new = r0 % r1;
            N q_new = r0 / r1;
            N s_new = s0 - q_new * s1;
            N t_new = t0 - q_new * t1;
            r0 = r1;
            r1 = r_new;
            s0 = s1;
            s1 = s_new;
            t0 = t1;
            t1 = t_new;
        }
        g = r0;
        x = s0;
        y = t0;
    }

    bool check() { return a * x + b * y == g; }
};

struct OEGCD {

    N a, b, x, y, g;
    N r0, r1;
    N s0, s1;
    N t0, t1;

    OEGCD(N a, N b)
        : a(a)
        , b(b) {
        r0 = a;
        r1 = b;
        s0 = 1;
        s1 = 0;
        t0 = 0;
        t1 = 1;
        while (r1 != 0) {
            N r_new = r0 % r1;
            N q_new = r0 / r1;
            N s_new = s0 - q_new * s1;
            N t_new = t0 - q_new * t1;
            r0 = r1;
            r1 = r_new;
            s0 = s1;
            s1 = s_new;
            t0 = t1;
            t1 = t_new;
        }
        g = r0;
        x = s0;
        y = t0;
    }

    bool check() { return a * x + b * y == g; }
};

int main() {
    while (true) {
        N a, b;
        cin >> a;
        if (cin.eof())
            break;
        cin >> b;
        auto e = EGCD(a, b);
        cout << e.x << " " << e.y << " " << e.g << endl;
    }
    return 0;
}

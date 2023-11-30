// ==================== LICENSE ====================

/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
*/

// ==================== Solution Description ====================

/*
# [UVa - 10104 - Euclid Problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1045)

The solution is simply the Extended Euclidean Algorithm. The part about minimizing $|X| + |Y|$ is irrelevant because that only happens when $A$ is a multiple of $B$ (the actual case is that one is looking for $X$ and $Y$ such taht $AX + BY = 0$). In such case, the Extended Euclidean Algorithm will already give the right answer.

However, one must be careful with how the input is taken and when it ends (that is really the annoying part).

## Extended Euclidean Algorithm - References

* <https://brilliant.org/wiki/extended-euclidean-algorithm/>;
* <https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm>;
* <https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/>
*/

// ==================== Code ====================

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

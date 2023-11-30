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
# [10489 - Boxes of Chocolates](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1430)

The first problem is to understand the input.

Basically, each line which describes a box, one has to multiply all the values to get the total amount of chocolate.

For instance, the input:

```
7 3
6 8 9 3 4 100 98
7 87 64 23 12 88 44 99
3 65 48 76
```

means that each box of chocolate has the following content:

1. the box 1-th contains 8 boxes, which contains 9 boxes, which contains 3 boxes, which contains 4 boxes, which contains 100 boxes, which contains 98 chocolates; Total = 8467200 = prod([8 9 3 4 100 98])
2. ...
3. the box 3-th contains 65 boxes, which contains 48 boxes, which contains 76 chocolates; Total: 237120 chocolates;

The other relevant part of the problem is that, at each computation, one has to take the mudulo by $n$, so that there is no overflow.
*/

// ==================== Code ====================

#include <iostream>

using namespace std;

using N = long long int;

int main() {
    N t;
    cin >> t;
    while (t--) {
        N n = -1LL; // number of friends
        N b = -1LL; // number of box of chocolates
        cin >> n >> b;
        N C = 0LL; // number of chocolates (total)
        while (b--) {
            N c = 1LL; // number of chocolates in this box
            N k = 0LL;
            cin >> k;
            while (k--) {
                N a = 1LL; // a_i indicates the number of boxes the i-th box contains within it
                cin >> a;
                c *= a;
                c %= n;
            }
            C += c;
            C %= n;
        }
        cout << C % n << endl;
    }
    return 0;
}

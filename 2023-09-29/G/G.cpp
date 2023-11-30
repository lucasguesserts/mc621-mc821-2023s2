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
# [12464 - Professor Lazy, Ph.D.](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=733&page=show_problem&problem=3907)

The sequence is:

0. $a$
1. $b$
2. $\dfrac{1 + b}{a}$
3. $\dfrac{1 + \dfrac{1+b}{a}}{b} = \dfrac{a + b + 1}{ab}$
4. $\dfrac{1 + \dfrac{a+b+1}{ab}}{\dfrac{1+b}{a}} = \dfrac{a + 1}{b}$
5. $\dfrac{1 + \dfrac{a+1}{b}}{\dfrac{a+b+1}{ab}} = a$
6. $\dfrac{1 + a}{\dfrac{1 + a}{b}} = b$
7. $\dots$

Thus we only have to compute the first 5 values. Let $m = n \% 5$. Then $Q_n = Q_m$.

*/

// ==================== Code ====================

// https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%2012464%20-%20Professor%20Lazy%20PhD/src/UVa%2012464%20-%20Professor%20Lazy%20PhD.cpp

#include <cstdio>
using namespace std;

int main() {
    int a, b;
    long long n;

    while (scanf("%d %d %lld", &a, &b, &n), a || b || n) {
        n %= 5;

        if (n == 0)
            printf("%d\n", a);
        if (n == 1)
            printf("%d\n", b);
        if (n == 2)
            printf("%d\n", (1 + b) / a);
        if (n == 3)
            printf("%d\n", (1 + a + b) / (a * b));
        if (n == 4)
            printf("%d\n", (1 + a) / b);
    }

    return 0;
}

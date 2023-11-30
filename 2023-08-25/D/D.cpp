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
# [Living Sequence](https://codeforces.com/problemset/problem/1811/E)

We can think of the "living sequence" $1, 2, 3, 5, 6, 7, 9, 10, 11, 12, 13, 15, \ldots$
as being a representation of every positive integer in base 9, since we are only allowed
to use 9 different digits. However, instead of the standard choice of digits
0 through 8, we are actually using 0, 1, 2, 3, 5, 6, 7, 8, 9 to represent
respectively 0, 1, 2, 3, 4, 5, 6, 7, 8.

Thus, given $k$ in decimal representation, we are asked to output $k$ in
our custom representation in base 9. This conversion takes time proportional
to the length of the representation of $k$ in base 10, i.e. $O(\log k)$, which
is adequate since $k$ can go up to $10^{12}$.

Beware: the maximum number $k$ that can be given as input does not fit into
standard `unsigned` (32-bit). You may use `uint64_t` or other equivalent.
*/

// ==================== Code ====================

#include <cstdint>
#include <iostream>

using namespace std;

/*
   Prints a representation of k in base 9 with a custom digit set.
   Digits       0, 1, 2, 3, 5, 6, 7, 8, 9
   represent    0, 1, 2, 3, 4, 5, 6, 7, 8
   respectively.
*/
void show_number(uint64_t k) {
    unsigned rep[16];
    unsigned size = 0;
    while (k) {
        unsigned digit = k % 9;
        rep[size++] = (digit < 4) ? digit : digit + 1;
        k /= 9;
    }
    while (size)
        cout << rep[--size];
    cout << endl;
}

int main() {
    unsigned ncases;
    cin >> ncases;
    while (ncases--) {
        uint64_t k;
        cin >> k;
        show_number(k);
    }
    return 0;
}

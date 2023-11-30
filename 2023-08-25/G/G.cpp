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
# [Add One](https://codeforces.com/problemset/problem/1513/C)

One of the first things you may notice is that in this problem the number $n$
itself has no important "inherent" properties, and we only care about its digits (i.e.
its representation in base 10). The digits may be consider independently of each other.

In other words, consider the following example:
we wish to know the resulting length of the number 518 after applying the
operation 3 times.

We can simply compute (or look up) what are the resulting lengths of
applying the operation 3 times to the digits 5, 1, and 8. The lengths are respectively
1 (digit 5 turns into 8), 1 (digit 1 turns into 4), and 2 (digit 8 turns into 21),
summing up to a total length of 4.
(Easy to check manually: 518 -> 629 -> 7310 -> 8421.)

Imagine that we had a bidimensional table $t$ such that, for each digit $d$ from 0 to 9,
and each $m$, we would store in `t[d][m]` the result of operating $m$ times on
digit $d$, then each query would be easy to process: we would sum `t[d][m]`
for each digit $d$ of the input.

However, you may find that:

1. such a table $t$ carries a lot of redundancy, since `t[d][m] == t[d-1][m+1]`;
2. when computing the resulting length of digit $d$, there are two cases:
either $d+m < 10$ and the length remains 1; or $d + m \geq 10$ which means
the number 10 eventually appears in the sequence of operations.

The above ideas leads us to a more economical, unidimensional "reduced"
table $r$ such that, for each $m$, `r[m]` stores the result of applying
$m$ steps to the specific sequence `10`.

How do we compute $r$?

* `r[m] = 2` for each $0 \leq m \leq 8", since the length is maintained;
* `r[9] = 3`, since the resulting string is 109 (10 -> 21 -> 32 -> ... -> 98 -> 109);
* `r[m] = r[m-9] + r[m-10]` when $m \geq 10$. This is because in the initial string
    `10`, the `1` on the left becomes a `10` after 9 operations and the `0` on
    the right becomes a `10` after 10 operations.

This allows us to compute the table and thus answer each query quickly.
*/

// ==================== Code ====================

/* https://codeforces.com/problemset/problem/1513/C
 *
 * accepted!
 *
 **/

#include <cstdint>
#include <cstdio>
#include <iostream>

#define MAXM 200000
#define MODULO 1000000007
#define MAXLEN 10

using namespace std;

uint64_t r[MAXM + 1];

void compute_table() {
    int i;
    for (i = 0; i < 9; i++)
        r[i] = 2;
    r[9] = 3;
    for (i = 10; i <= MAXM; i++)
        r[i] = (r[i - 9] + r[i - 10]) % MODULO;
}

uint64_t compute_length(char * sequence, unsigned steps) {
    uint64_t total = 0;
    for (int i = 0; sequence[i]; i++) {
        unsigned digit = sequence[i] - '0';
        if (digit + steps < 10)
            total += 1;
        else
            total += r[(digit + steps) - 10];
        total = total % MODULO;
    }
    return total;
}

int main() {
    compute_table();
    unsigned ncases;
    cin >> ncases;
    while (ncases--) {
        char num[MAXLEN + 1];
        unsigned m;
        scanf("%s %u", num, &m);
        cout << compute_length(num, m) << endl;
    }
    return 0;
}

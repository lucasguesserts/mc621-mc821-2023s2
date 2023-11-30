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
# [Two Round Dances](https://codeforces.com/problemset/problem/1433/E)

There are $n$ people ($n$ even) who we want to separate into two groups of
same size (for each of the dances). This gives "$n$ choose 2" options for
the division, which is equal to $n!$.

Furthermore, given a division, we wish to count the possible permutations
of people inside each group. At first, each round would have $(n/2)!$ permutations, but
since we consider permutation $(1, 2, 3)$ equal to $(2, 3, 1)$ and $(3, 1, 2)$, we
have to divide that number by the number of participants of the round,
which is $n/2$.

Finally, since we are not distinguishing for the order in which the groups of
size $n/2$ dance, we have to divide our results by 2.

This amounts to

$$ \frac{n!}{(n/2)!^2}\frac{(n/2)!}{n/2}\frac{(n/2)!}{n/2}\frac{1}{2} $$

which simplifies to

$$ \frac{n!}{2 (n/2)^2}$$

distinct dances.

This can be further simplified, but pay attention to small $n$.
*/

// ==================== Code ====================

#include <cstdint>
#include <iostream>

/* https://codeforces.com/problemset/problem/1433/E
 *
 * accepted!
 *
 **/

#define MAXN 20

using namespace std;

int main() {
    uint64_t fact[MAXN];
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MAXN; i++)
        fact[i] = fact[i - 1] * i;

    int n;
    cin >> n;
    cout << ((2 * fact[n - 1]) / n) << endl;
}

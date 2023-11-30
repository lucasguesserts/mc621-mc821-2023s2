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
# [UVa 10405 - Longest Common Subsequence](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1346)

The Longest Common Subsequence (LCS) Problem is a classic problem in Computer Science
and applications such as computational biology. The classic solution to LCS is a
$\mathcal{O}(n^2)$ Dynamic Programming.

Let $A$, of length $n$, and $B$, of length $m$, be the strings we're trying to
match.

We build a table `t` of dimensions $n+1$ by $m+1$.

`t[i][j]` stores the maximum length of a common subsequence between the first
$i-1$ members of $A$ and the first $j-1$ members of $B$.

* `t[i][j] = 0` if either `i` or `j` is zero;
* If `A[i-1] == B[j-1]`, then `t[i][j] = t[i-1][j-1] + 1`;
* Otherwise, `A[i][j]` will be the best between `A[i-1][j]` and `A[i][j-1]`.

___

We can also solve this problem by employing the Needleman-Wunsch algorithm
to find an alignment of maximum score, where we give a score of:

* `0`, for insertions and deletions
* `+1`, for a match
* `-INFINITY`, for a mismatch

(This is also a quadratic DP solution.)

___

Whatever the chosen solution, beware that an empty string is a valid line
of input. Use `getline()` instead of `cin` in `C++`.

(Python's `input()` should be agnostic to this issue.)*/

// ==================== Code ====================

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 1000

int table[MAX + 1][MAX + 1];

unsigned lcs(string A, string B) {
    int n = A.size(), m = B.size();
    int i, j;

    memset(table, 0, sizeof table);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    return table[n][m];
}

int main() {
    string A, B;
    while (getline(cin, A)) {
        getline(cin, B);
        cout << lcs(A, B) << endl;
    }
    return 0;
}

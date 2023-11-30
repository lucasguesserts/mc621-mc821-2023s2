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
# [UVa 13146 - Edid Tistance](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5057)

Given an integer `t`, we are given `t` pair of strings.

For each pair $A, B$, we need to output the *edit distance* $d(A,B)$ between
$A$ and $B$.

This is a classic problem that can be solved using the Needleman-Wunsch algorithm
for string alignment. Chosing the scores

* Insertion and deletion: -1;
* Mismatch: -1;
* Match: 0;

Then the optimal value of string alignment between $A$ and $B$ will be $-d(A,B)$.

___

Beware of how the input should be read.
Depending on how you read the first line (number of test cases), you might get
an empty string if you try to get the first string using `getline()`. I wasn't
patient enough to think of an elegant solution to this and simply asked
`scanf()` to "eat" the `\n` for me.*/

// ==================== Code ====================

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

#define INDEL (-1)
#define MATCH (+0)
#define MISMATCH (-1)

int table[MAX + 1][MAX + 1];

int score(string A, string B) {
    int n = A.length(), m = B.length();
    int i, j;

    memset(table, 0, sizeof table);
    for (i = 1; i <= n; i++)
        table[i][0] = i * INDEL;
    for (j = 1; j <= m; j++)
        table[0][j] = j * INDEL;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            table[i][j] = table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? MATCH : MISMATCH); // cost for match or mismatches
            table[i][j] = max(table[i][j], table[i - 1][j] + INDEL); // delete
            table[i][j] = max(table[i][j], table[i][j - 1] + INDEL); // insert
        }
    }

    return table[n][m];
}

int main() {
    int ncases;
    scanf("%d\n", &ncases);
    while (ncases--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);
        cout << -score(A, B) << endl;
    }
    return 0;
}

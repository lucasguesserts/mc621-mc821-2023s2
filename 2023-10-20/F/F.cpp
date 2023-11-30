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
# [SPOJ IOIPALIN - Palindrome 2000](https://www.spoj.com/problems/IOIPALIN/)

Transforming a string into a palindrome can be viewed as a form of edit distance.

This problem can be solved by Needleman-Wunsch algorithm with appropriate scores for insertion, deletion,
match and mismatch.

The solution used here computes the LCS (based on Needleman-Wunsch) and substracts it from the
length of the original string to compute the needed additions.*/

// ==================== Code ====================

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define MAX 5000

#define INDEL (+0)
#define MATCH (+1)
#define MISMATCH (-(1 << 30))

int64_t table[MAX + 1][MAX + 1];

unsigned lcs_palindrome(string A, int n) {
    int i, j;
    string B(A);
    reverse(B.begin(), B.end());

    // cout << "comparing " << A << " and " << B << endl;

    memset(table, 0, sizeof table);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            table[i][j] = table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? MATCH : MISMATCH); // cost for match or mismatches
            table[i][j] = max(table[i][j], table[i - 1][j]);
            table[i][j] = max(table[i][j], table[i][j - 1]);
        }
    }

    return table[n][n];
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << n - lcs_palindrome(s, n) << endl;
    return 0;
}

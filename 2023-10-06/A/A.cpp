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
# [Quite a Problem](https://open.kattis.com/problems/quiteaproblem)

This problem asks us to read each line independently and then decide whether
it contains the word `PROBLEM` regardless of case.

We can simply use the KMP algorithm:

* We run the preprocessing with pattern `P = "PROBLEM"`
* We modify the algorithm itself to ignore case (in this code, we simply
compare each pair of characters in their upper case versions using the
function `toupper`)
*/

// ==================== Code ====================

#include <iostream>
#include <string>

#define MAX_N 100

using namespace std;

void kmpPreprocess(string P, int * b) {
    int i = 0, j = -1, m = P.size();
    b[0] = -1;
    while (i < m) {
        while ((j >= 0) && (P[i] != P[j]))
            j = b[j]; // different, reset j
        ++i;
        ++j;
        b[i] = j;
    }
}

bool kmpSearch(string P, string T, int * b) {
    int i = 0, j = 0,
        m = P.size(),
        n = T.size();
    while (i < n) {
        while ((j >= 0) && (toupper(T[i]) != toupper(P[j])))
            j = b[j]; // if different, reset j
        ++i;
        ++j;
        if (j == m)
            return true;
    }
    return false;
}

int main() {
    int table[MAX_N];
    string pattern = "PROBLEM";
    kmpPreprocess(pattern, table);

    string line;
    while (getline(cin, line))
        cout << (kmpSearch(pattern, line, table) ? "yes" : "no") << endl;
}

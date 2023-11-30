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
# [Codeforces 1619A - Square String?](https://codeforces.com/problemset/problem/1619/A)

Let `s` be our string, `n` its length.

Simply check whether `s[i] == s[n/2 + i]` for every `i` from `0` to `n/2-1`.
*/

// ==================== Code ====================

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

bool is_square(string s) {
    int n = s.length();
    if (n % 2) return false;
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n / 2 + i]) return false;
    return true;
}

int main() {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        string s;
        cin >> s;
        cout << (is_square(s) ? "YES" : "NO") << endl;
    }
    return 0;
}

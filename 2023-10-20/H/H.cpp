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
# [Codeforces 1832A - New Palindrome](https://codeforces.com/problemset/problem/1832/A)

We just need to check if the first half of the string has at least two unique characters.

If it does, we can swap them to form a new palindrome; otherwise, no new palindrome can be formed.*/

// ==================== Code ====================

#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool can_form_new(string s) {
    int n = s.length();
    unordered_set<char> unique_chars;
    for (int i = 0; i < n / 2; i++)
        unique_chars.insert(s[i]);
    return unique_chars.size() > 1;
}

int main() {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        string palindrome;
        cin >> palindrome;
        cout << (can_form_new(palindrome) ? "YES" : "NO") << endl;
    }
    return 0;
}

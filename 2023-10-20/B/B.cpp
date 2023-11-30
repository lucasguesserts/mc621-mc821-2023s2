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
# [1223B - String Equalization](https://codeforces.com/problemset/problem/1223/B)

Since the operation (making pair of characters equal) can be applied on both
$s$ and $t$ (the strings we are to make equal), the solution turns out to be
simple: so long as $s$ and $t$ have a character in common, they can be made
equal.

(Say they have `a` in common. Then both can be transformed into `aaaaa...`.)

This can be achieved in many ways within time limit, with the simplest probably
being to make a set with the contents of one of the strings and checking the
other string's characters for pertinence.
*/

// ==================== Code ====================

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool have_common_char(string s, string t) {
    unordered_set<char> set_s;
    for (auto c : s)
        set_s.insert(c);
    for (auto c : t)
        if (set_s.count(c))
            return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s, t;
        cin >> s >> t;
        cout << (have_common_char(s, t) ? "YES" : "NO") << endl;
    }
    return 0;
}

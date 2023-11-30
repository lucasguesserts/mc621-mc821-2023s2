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
# [Codeforces 1654 B - Prefix Removals](https://codeforces.com/problemset/problem/1654/B)

Let `s` be the input string of size `n` and `c_0` the first character. Notice that, if `c_0` repeats, then in the worst case, the longest prefix is `c_0` and it can be removed. In other words, one can remove the first letter of `s` if it repeats somewhere else in `s`.

To solve the problem, process the string from right (end) to left (beginning) and save the index of the last ocurrence of each character. Notice that such character cannot be removed. Then, take `i` as the smallest of those indices. The answer is the string `s[i..n]` (from the first character that cannot be removed to the end of the string).
*/

// ==================== Code ====================

#include <bits/stdc++.h>
#include <limits>

using namespace std;

const string all_letters = "abcdefghijklmnopqrstuvwxyz";
const int inf = numeric_limits<int>::max();

using M = map<char, int>;

M init() {
    M m;
    for (const auto & c : all_letters) {
        m[c] = inf;
    }
    return m;
}

int main() {
    int T;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        auto m = init();
        int minimum_index = inf;
        for (int i = s.size() - 1; i >= 0; --i) {
            auto it = m.find(s[i]);
            if (it->second == inf) {
                it->second = i;
                minimum_index = i;
            }
        }
        cout << s.substr(minimum_index, s.size() - minimum_index) << endl;
    }
    return 0;
}

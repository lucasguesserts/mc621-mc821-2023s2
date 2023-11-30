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
# [UVa 719 - Glass Beads](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=660)

This problem is actually easy. The only thing you need to do is to find the lexicographically smallest rotation of the string. To do so, evaluate all rotations and find the smallest one. The complexity of this algorithm is `O(n^2)` (`n` rotations, and each one requires one to create a string with size `n`).

The algorithm does not give a runtime error because the size of the strings is at most 10^4, so it takes around 10^8 operations (i.e. one second or so).

Obs: one tried to use the suffix array to solve this problem but for some reason it did not work (wrong answer).
*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

string get_cycle(string s, int i) {
    s = s.substr(i) + s.substr(0, i);
    return s;
}

int find_min_cycle(const string s) {
    auto minimum = s;
    int i_min = 0;
    for (int i = 0; i < s.size(); i++) {
        auto cycle = get_cycle(s, i);
        if (cycle < minimum) {
            minimum = std::move(cycle);
            i_min = i;
        }
    }
    return i_min;
}

int main() {
    int T;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        auto i = find_min_cycle(s);
        cout << i + 1 << endl;
    }
    return 0;
}

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
# [UVa - 11362 - Phone List](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2347)

1. get all strings in a list (vector in c++);
2. sort the list;
   1. notice that, if a number `x` is the prefix of another number `y`, then `x` comes right before `y` in the sorted list;
3. starting in the beginning of the list, check if the current number is in the next number;
   1. if it is, then the list is not consistent;
   2. if, for all numbers, it is not, then the list is consistent.
*/

// ==================== Code ====================

#include <bits/stdc++.h>

using namespace std;

using I = int64_t;
using VS = vector<string>;

bool has_prefix(const VS & a) {
    for (I i = 0; i < a.size() - 1; ++i) {
        if (a[i + 1].find(a[i]) != string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    I T;
    cin >> T;
    while (T--) {
        I n;
        cin >> n;
        VS a(n);
        for (auto & ai : a) {
            cin >> ai;
        }
        sort(a.begin(), a.end());
        auto is_consistent = has_prefix(a) ? "NO" : "YES";
        cout << is_consistent << endl;
    }
    return 0;
}

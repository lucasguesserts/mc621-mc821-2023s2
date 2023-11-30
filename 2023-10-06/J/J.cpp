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
# [UVa 455 - Periodic Strings](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=396)

Let $k \in \mathbb{Z}_+$ be a number. Take the prefix $f$ of the string $s$ of length $k$. Create a string $s'$ by concatenating the prefix $f$ till it has the size of $s$. If $f = s$, then $s$ has period $k$.

To solve the problem, start with $k = 1$ and check two conditions:

1. $len(s)$ is divisible by $k$;
2. $s$ is equals to $len(s) / k$ concatenations of $f$, where $f$ is the prefix of $s$ with size $k$;

The first $k$ for which both conditions hold is the answer of the problem.

*/

// ==================== Code ====================

#include <iostream>
#include <string>

using namespace std;

int solve(const string & s) {
    int l = 0;
    string rep = "";
    while (true) {
        rep += s[l];
        ++l;
        if (s.size() % l != 0) continue;
        string sub;
        for (int i = 0; i < s.size() / l; ++i) {
            sub += rep;
        }
        if (s == sub) {
            break;
        }
    }
    return l;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
        if (N != 0) {
            cout << endl;
        }
    }
    return 0;
}

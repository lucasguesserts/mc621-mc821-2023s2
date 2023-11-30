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
# [Codeforces 1791C - Prepend and Append](https://codeforces.com/problemset/problem/1791/C)

Let the string $s$ be:

$$ s = s_0 s_1 \dots s_{n-1} $$

Now one is looking for the first time in the string when characters in opposite positions are equal. Let $f$ be the function which give us the solution to the problem:

$$ f(s, b, e) = \begin{cases}
0, & \text{if } b > e \\
f(s, b+1, e-1), & \text{if } (s[b] \neq s[e]) \\
e - b + 1, & \text{otherwise}
\end{cases}$$

It is a recursive call which does not copy the string, it just searches through it. Complexity: $\mathcal{O}(n)$.
*/

// ==================== Code ====================

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

using I = long long int;

I find_min_length(const string & s, const I b, const I e) {
    if (b > e) {
        return I(0);
    } else if (s[b] != s[e]) {
        return find_min_length(s, b + 1, e - 1);
    } else {
        return e - b + 1;
    }
}

int main() {
    I T, n;
    string s;
    cin >> T;
    while (T--) {
        if (cin.eof()) break;
        cin >> n;
        cin >> s;
        cout << find_min_length(s, 0, n - 1) << endl;
    }
    return 0;
}

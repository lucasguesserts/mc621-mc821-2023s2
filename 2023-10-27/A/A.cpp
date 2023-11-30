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
# [Codeforces 1794A - Prefix and Suffix Array](https://codeforces.com/problemset/problem/1794/A)

For each given input, let $s$ be the string (which we don't know), of size $n$.
There are excatly two proper substrings of maximum length:

* the biggest proper prefix $p$, and
* the biggest proper suffix $s$

are both of size $n-1$.

Notice that $s$ is a palindrome if, and only if, $p$ and $s$ are the reverse
of each other (say, without loff of generality, if $s = p^R$.)

Upon reading the input, we cannot determine which of the "big substrings" is
$p$ or $s$, but that doesn't make a difference.
We simply do the following

1. Read every substring, saving the two "big" ones (length $n-1$) as $p$ and $s$;
2. Answer `YES` if $p = s^R$.*/

// ==================== Code ====================

#include <iostream>
#include <string>

using namespace std;

int main() {
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int n, found;
        string in, big[2];
        cin >> n;
        for (int i = found = 0; i < 2 * (n - 1); i++) {
            cin >> in;
            if (in.size() == n - 1)
                big[found++] = in;
        }
        cout << (big[0] == string(big[1].rbegin(), big[1].rend()) ? "YES" : "NO") << endl;
    }
    return 0;
}

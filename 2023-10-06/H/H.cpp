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
# [Avion](https://open.kattis.com/problems/avion)

For each of the 5 lines of input we just need to check if it contains `"FBI"` as
a substring. This can be done in a number of ways:

* In Python, a native `'FBI' in input()` would suffice;
* In languages with Regular Expression libraries, use regex with pattern `"FBI"`;
* KMP algorithm: initialize the fallback table with pattern `"FBI"` and perform
a boolean search (stops at first match, returning `true`);
* Maybe even naïve search is fine, but I haven't tested.*/

// ==================== Code ====================

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    bool escaped = true;
    regex pattern("FBI");
    for (int i = 1; i <= 5; i++) {
        string s;
        cin >> s;
        if (regex_search(s, pattern)) {
            cout << i << " ";
            escaped = false;
        }
    }
    if (escaped)
        cout << "HE GOT AWAY!";
    cout << endl;
    return 0;
}

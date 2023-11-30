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
# [Matching](https://codeforces.com/problemset/problem/1821/A)

This problem requires counting the amount of characters `?` in the input.
Each `?` multiplies the amount of combinations by 10, except for a `?` at the
very start of the string, since leading zeroes are not considered valid.

It is also important to discard the pattern if it starts with `0` -- it is
either zero (and we're counting POSITIVE matches) or an invalid pattern.
*/

// ==================== Code ====================

#include <iostream>

#define MAXLEN 5

using namespace std;

unsigned positive_combinations(char pattern[MAXLEN + 1], int start) {
    if (!pattern[start]) return 1;
    char c = pattern[start];
    unsigned this_position = 1;
    if (c == '?') this_position = (start) ? 10 : 9;
    else if (c == '0' && !start) return 0;
    return this_position * positive_combinations(pattern, start + 1);
}

int main() {
    int ncases;
    char input[MAXLEN + 1];
    cin >> ncases;
    while (ncases--) {
        cin >> input;
        cout << positive_combinations(input, 0) << endl;
    }
    return 0;
}

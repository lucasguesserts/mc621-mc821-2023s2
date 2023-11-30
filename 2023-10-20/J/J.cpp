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
# [Codeforces 520A - Pangram](https://codeforces.com/problemset/problem/520/A)

Simple enough solution: just check if every letter occurs in the string
(taking care to ignore case).

This could be achieved in many ways:

* add every found character to a set and then check the set for every letter;
* make every letter of the alphabet be a key in a frequency dictionary/map;
* do the same as the dictionary but with a 26 position array.*/

// ==================== Code ====================

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool is_pangram(string s) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    unordered_set<char> found;
    for (auto c : s)
        found.insert(tolower(c));
    for (auto c : alphabet)
        if (!found.count(c))
            return false;
    return true;
}
int main() {
    int n;
    string in;
    cin >> n >> in;
    cout << (is_pangram(in) ? "YES" : "NO") << endl;
    return 0;
}

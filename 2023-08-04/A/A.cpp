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
# [YES or YES?](https://codeforces.com/problemset/problem/1703/A)

The solution of this problem is as simple as checking each character of the input:

1. check if the first character is either `Y` or `y`;
2. check if the second character is either `E` or `e`;
3. check if the third character is either `S` or `s`;
4. if all of the above are true, then print `YES`, otherwise print `NO`;
*/

// ==================== Code ====================

#include <iostream>

using namespace std;

unsigned get_number_of_cases() {
    unsigned n;
    cin >> n;
    return n;
}

char * get_case_input() {
    auto c = new char[3];
    cin >> c[0] >> c[1] >> c[2];
    return c;
}

bool is_yes(const char * const c) {
    const bool y = c[0] == 'Y' || c[0] == 'y';
    const bool e = c[1] == 'E' || c[1] == 'e';
    const bool s = c[2] == 'S' || c[2] == 's';
    return y && e && s;
}

int main() {
    const unsigned n = get_number_of_cases();
    for (auto i = 0u; i < n; ++i) {
        const auto c = get_case_input();
        if (is_yes(c)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
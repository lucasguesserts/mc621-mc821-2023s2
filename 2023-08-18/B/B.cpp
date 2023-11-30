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
# [A. Modular Exponentiation](https://codeforces.com/problemset/problem/913/A)

The problem is quite simple, simply compute the remainder using the built-in function `%` of c++. There is a catch though: `n` may be too large for one to compute `2^n`. If that is the case, one can consider that `m < 2^n` so the answer for the problem is simply `m`.

But how to verify if `2^n` is too large to be computed? Well, if `n > floor(log2(MAX_INT))`, then one cannot compute `2^n`.
*/

// ==================== Code ====================

#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    const auto max_exponent = std::floor(std::log2(std::numeric_limits<long int>::max()));
    long int n, m;
    long int result;
    cin >> n >> m;
    if (n > max_exponent) {
        result = m;
    } else {
        result = m % static_cast<long int>(round(pow(2, n)));
    }
    cout << result;
    return 0;
}

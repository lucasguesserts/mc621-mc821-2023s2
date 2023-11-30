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
# [Raising Bacteria](https://codeforces.com/problemset/problem/579/A)

Given any positive integer `x`, one can write it as (one can prove by induction, but I am not going to prove it here):

```plain
x = a0 . 2^n + a1 . 2^(n-1) + ... + an . 2^0

a0, ..., an ∈ {0, 1}
```

The way to get the desired amount of bacterias is by putting only one each time and letting them grow. And with the above decomposition, we can know that we need to put `1` in the `i`-th day if `ai = 1`. Thus the answer is the number of `1`s in `a0, ..., an`.

To compute such number, one can start by finding the largest `n` such that `2^n <= x` (which can be computed as `pow(2, floor(log2(x)))`). Then we can subtract `2^n` from `x` and repeat the process until `x = 0`. The number of times we subtract `2^n` is the number of `1`s in the binary representation of `x`.
*/

// ==================== Code ====================

#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    auto x = unsigned{0};
    cin >> x;
    auto current_2_factor = unsigned{0};
    current_2_factor = static_cast<unsigned>(pow(2, floor(log2(x))));
    auto number_of_bacterias = unsigned{0};
    while (x != 0) {
        if (x >= current_2_factor) {
            ++number_of_bacterias;
            x -= current_2_factor;
        }
        current_2_factor /= 2;
    }
    cout << number_of_bacterias;
    return 0;
}

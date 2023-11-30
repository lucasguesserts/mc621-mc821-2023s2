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
# [Game with Board](https://codeforces.com/problemset/problem/1841/A)

## `n = 2`

```plain
1 1 <- Alice
2 <- Bob
```

Bob wins.

## `n = 3`

```plain
1 1 1 <- Alice
2 1 <- Bob

or

1 1 1 <- Alice
3 <- Bob
```

In all cases, Bob wins.

## `n = 4`

```plain
1 1 1 1 <- Alice
4 <- Bob

or

1 1 1 1 <- Alice
3 1 <- Bob

or

1 1 1 1 <- Alice
2 1 1 <- Bob
2 2 <- Alice
4 <- Bob
```

In all cases, Bob wins.

## `n >= 5`

```plain
1 1 ... 1 <- Alice
n-2 1 1 <- Bob
n-2 2 <- Alice
```

Alice can win in all cases if she plays optimally (which, by hypothesis, is the case). Thus, Alice wins.
*/

// ==================== Code ====================

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    auto number_of_test_cases = unsigned(0);
    cin >> number_of_test_cases;
    for (auto test_case_index = 0u; test_case_index < number_of_test_cases; ++test_case_index) {
        auto number_of_integers = unsigned(0);
        cin >> number_of_integers;
        if (number_of_integers < 5u) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
    return 0;
}

"""
==================== LICENSE ====================

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

 ==================== Solution Description ====================

# [Unlucky Numbers](https://codeforces.com/problemset/problem/1808/C)

[The solution](https://codeforces.com/contest/1808/submission/200077909) has been submitted by [Chromefish](https://codeforces.com/profile/Chromefish) and modified by me to make it more readable.

First, if `len(r) > len(l)`, it means that one can find a number `k` such that `l <= k <= r` and all digits of `k` are the same (e.g. `l = 123`, `r = 1234`, `k = 999`).

(The case `len(r) < len(l)` is not possible because `l <= r`).

Now consider that `len(r) == len(l)`. Let `l = l_1 l_2 ... l_n` and `r = r_1 r_2 ... r_n`. For `i = 1, ..., n`:

1. consider a number `j` in the range of valid values for the `i`-th digit: `l_i <= j <= r_i`;
2. consider `k = 0, ..., 9`, all the `10` digits that may come after the `i`-th digit;
3. create a number `x` which is the concatenation: `l_1, ..., l_{i}, j, k, k, ..., k` (the number of `k`'s is `n - i - 1`);
4. if `x` is in the range `[l, r]` and it is the best number found so far, keep it;

The above algorithm is `O(n)`, where `n` is the number of digits of `l` and `r` (notice that the loops of the steps 1 to 4 take, at most, 100 steps, i.e. a constant number of steps).
"""

# ==================== Code ====================

# https://codeforces.com/contest/1808/submission/200077909


def get_cost(a):
    return int(max(a)) - int(min(a))


number_of_test_cases = int(input())
for test_case_index in range(number_of_test_cases):
    l, r = input().split()
    if len(r) > len(l):
        print("9" * len(l))
    else:
        n = len(l)
        ans = l
        for i in range(n):
            for j in range(int(l[i]), int(r[i]) + 1):
                for k in range(10):
                    x = l[:i] + str(j) + str(k) * (n - i - 1)
                    if (l <= x <= r) and (get_cost(x) < get_cost(ans)):
                        ans = x
        print(ans)

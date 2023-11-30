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

# [Sum of Two Numbers](https://codeforces.com/problemset/problem/1788/B)

For each $n$, one may select a random integer $a$ uniformly from 1 to $n$.
Let $b = n - a$. If the difference in the sum of digits of $a$ and $b$ is bigger than 1, try again.
"""

# ==================== Code ====================

from random import seed, randint


def sum_of_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s


def randomly_select_pair(n):
    m = randint(1, n)
    return m, n - m


def select_good_pair(n):
    while True:
        a, b = randomly_select_pair(n)
        A = sum_of_digits(a)
        B = sum_of_digits(b)
        if abs(A - B) <= 1:
            return a, b


if __name__ == "__main__":
    seed(1)
    ncases = int(input())
    for _ in range(ncases):
        n = int(input())
        a, b = select_good_pair(n)
        print(a, b)

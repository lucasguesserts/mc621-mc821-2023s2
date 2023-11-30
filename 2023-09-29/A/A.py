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

# [Fibonacci Cycles](https://open.kattis.com/problems/fibonaccicycles)

We are given, for each test case, a positive integer $k$, $2 \leq k \leq 10^3$.
Since the question involves Fibonacci numbers modulo $k$, there are only
$k$ possible results (0 through $k-1$). Thus, before treating any test case
we precompute the first 1000 numbers of the Fibonacci sequence as these are
at most what we shall need.

Let $F_0 = 1, F_1 = 1, F_2 = 2, \ldots$ be the Fibonacci sequence.

Then, given $k$, we wish to find the minimum $i \geq 2$ such that there is some
$j > i$ with $F_i \equiv F_j \pmod{k}$. It suffices to maintain a table `t`
of size $k$ such that for each `r` we store in `t[r]` the first index $i$
such that $F_i \equiv r \pmod{k}$. We iterate through $F_2, F_3, \ldots$ and stop
when find an index $j$ with $F_j \pmod{k}$ already existing in the table.

Notice that we wish to output $i$ (index of the original occurence) rather
than $j$ (index of first repetition).
"""

# ==================== Code ====================

MAX_LEN = 1001  # integers modulo k have k distinct possible values
fib = [1, 1]


def first_repetition_modulo(k):
    first_appearance = [None] * k
    for i in range(2, len(fib)):
        value = fib[i] % k
        if first_appearance[value] is not None:
            return first_appearance[value]
        first_appearance[value] = i
    return -1


if __name__ == "__main__":
    while len(fib) < MAX_LEN:
        fib.append(fib[-1] + fib[-2])
    for _ in range(int(input())):
        print(first_repetition_modulo(int(input())))

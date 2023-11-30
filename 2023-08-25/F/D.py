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

# [ATOMS - Atoms in the Lab](https://www.spoj.com/problems/ATOMS/)

When an atom splits, it ceases to be 1 atom and turns into $K$ atoms.
Since there are $N$ atoms at first, the number of atoms after $T$ seconds will
be $N K^T$. We want to know the maximum value $T$ such that $N K^T \leq M$.

Thus, we want $T$ to be the integer log of $M/N$ on base $K$.
This requires being able to divide, multiply and compare big integers.
"""

# ==================== Code ====================


def intlog(num: int, base: int) -> int:
    steps = 0
    while num >= base:
        num //= base
        steps += 1
    return steps


def solve_case():
    initial_n, split_number, maximum_n = map(int, input().split())
    print(intlog(maximum_n // initial_n, split_number))


def main():
    ncases = int(input())
    for _ in range(ncases):
        solve_case()


if __name__ == "__main__":
    main()

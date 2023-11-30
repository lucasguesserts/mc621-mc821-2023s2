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

# [Rebellion](https://codeforces.com/problemset/problem/1746/B)

To make the sequence non-decreasing, one simply has to move all zeros to the beginning, and the ones to the end. To do so, iteratively, one will move the first one into the last zero, until there is no zero after any one.

Example:

```plain
0: *1* 1 0 0 1 0 0 1 1 1 *0*
1: *1* 0 0 1 0 *0* 1 1 1 1
2: 0 0 *1* *0* 1 1 1 1 1
2: 0 0 1 1 1 1 1 1

3 moves required.
```
"""

# ==================== Code ====================


def find_last_index(l, obj, end):
    i = end - 1
    while i >= 0:
        if l[i] == obj:
            return i
        else:
            i -= 1
    return None


def find_first_index(l, obj, start):
    i = start + 1
    while i < len(l):
        if l[i] == obj:
            return i
        else:
            i += 1
    return None


class Sequence:
    def __init__(self, a):
        self.a = a
        self.first_one = find_first_index(self.a, 1, -1)
        self.last_zero = find_last_index(self.a, 0, len(self.a))
        self.moves_count = 0
        self._solve()
        return

    def _make_move(self):
        self.moves_count += 1
        self.a[self.last_zero] = 1
        del self.a[self.first_one]
        self.first_one = find_first_index(self.a, 1, self.first_one - 1)
        self.last_zero = find_last_index(self.a, 0, self.last_zero - 1)
        return

    def _solve(self):
        while (
            (self.first_one is not None)
            and (self.last_zero is not None)
            and (self.first_one < self.last_zero)
        ):
            self._make_move()
        return


if __name__ == "__main__":
    number_of_cases = int(input())
    for _ in range(number_of_cases):
        n = int(input())
        a = [int(x) for x in input().split()]
        s = Sequence(a)
        print(s.moves_count)

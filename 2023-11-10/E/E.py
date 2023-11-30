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

# [Kattis - Unlock Pattern](https://open.kattis.com/problems/unlockpattern)

First we read the input storing a map (really a simple array suffices) of positions.
For instance, the example input

```
6 1 9
5 2 8
4 3 7
```

would be mapped as

* `pos[1] = (0, 1)`
* `pos[2] = (1, 1)`
* ...
* `pos[9] = (0, 2)`

where you'll notice we are treating the positions as 0-based matrix indices.

Then we simply go from one point to the next, accumulating the euclidean distance to output later.

We don't even have to worry about presentation here. The answer is judged not by textual diff but numerically by checking whether

`abs(given_output - correct_answer) < EPS`

for `EPS = 1e-6`."""

# ==================== Code ====================


def dist(p, q):
    return ((p[0] - q[0]) ** 2 + (p[1] - q[1]) ** 2) ** 0.5


if __name__ == "__main__":
    location = [None for i in range(10)]
    for i in range(3):
        row = list(map(int, input().split()))
        for j in range(3):
            location[row[j]] = (i, j)

    total_dist = 0.0
    for i in range(1, 9):
        total_dist += dist(location[i], location[i + 1])

    print(total_dist)

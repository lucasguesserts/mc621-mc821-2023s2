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

# [Toy Machine](https://codeforces.com/problemset/problem/1817/D)

First we note that the answer is not required to be optimal (e.g. minimize number of steps).

We consider three cases.

* The first case is when the target toy that we want to put in the leftmost place is directly above
the central obstacle. In this case, we simply go "DL" (Down, Left) in order for it to be placed correctly.

* The second case is when the target toy is to the left of the central obstacle.
We aim to reduce this to the above case by going "RDRU" (Right, Down, Right, Up) however many
times needed for the target toy to end up in the central position by going "R" one more time.

* The third case is when the target toy is to the right of the central obstacle.
In this case, we further break down into three movements in order to get into the second case.
    - First, we position the target toy in the *rightmost* place (i.e. directly opposed to the desired position)
    - Then, we make sure every toy is to the right of the central obstacle (filling the top and bottom rows in this
    region)
    - Finally, we go "LDRU" and then the target toy will be placed directly above the central obstacle by going "R" one final time.

Both the second case and the steps of the third case must be reflected upon by toying with the [simulation](https://assets.codeforces.com/files/56ff21637146a30d/game.html) that is provided.

## Lucas's Solution

Let:

1. `n` be the number of cells in a row (n odd);
2. `p = n-2` the number of pieces in a row;
3. `f = 1` the first piece;
4. `m = (p + 1) / 2 = (n - 1) / 2` the middle piece;
5. `b = m - 1 = (n - 3) / 2` the last piece before the middle one;
6. `a = m + 1 = (n + 1) / 2` the first piece after the middle one;
7. `l = p` the last piece;
8. `f <= k <= l` the target piece, the one to be moved to the leftmost position;

The algorithm is as follows:

1. if `k == m`: DL
2. if `f <= k <= b`: L + (k - 1) * DRUL
   1. L: move the first piece to the leftmost position;
   2. DRUL: each repetition moves the next piece to the leftmost position, and after `k - 1` repetitions, the `k`-th piece is in the leftmost position;
3. if `a <= k <= l`: R + (l - k) * DLUR + p * URDR + LDRURDL
   1. R: move the last piece to the rightmost position
   2. (l - k) * DLUR: each repetition moves the next piece to the rightmost position, and after `(l - k)` repetitions, the `k`-th piece is in the rightmost position;
   3. p * URDR: move all pieces to the right side of the middle obstacle, it is repeated `p` times so to be sure that all pieces have been moved;
   4. LDRURDL: move the rightmost piece to the leftmost position
"""

# ==================== Code ====================


def solve(n, k):
    p = n - 2
    f = 1
    m = (p + 1) / 2
    b = m - 1
    a = m + 1
    l = p
    if k == m:
        return "DL"
    elif f <= k <= b:
        return "L" + (k - 1) * "DRUL"
    else:
        return "R" + (l - k) * "DLUR" + p * "URDR" + "LDRURDL"


if __name__ == "__main__":
    n, k = map(int, input().split())
    solution = solve(n, k)
    print(solution)

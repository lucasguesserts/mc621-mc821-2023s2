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

# [Association for Convex Main Office](https://open.kattis.com/problems/convex)

I was unable to solve the problem and I didn't understand the solution people proposed, even though I pasted a solution that I found online.
"""

# ==================== Code ====================

# source: https://github.com/RussellDash332/kattis/blob/main/src/Association%20for%20Convex%20Main%20Office/convex.py

# MIT License

# Copyright (c) 2022 Russell Saerang

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


import sys

N = int(input())
if N == 3:
    print(0, 1), print(1, 1), print(1, 0), exit(0)
M = N // 4 + 1
X = 2 * 10**7
slopes = set()
s = 2
while len(slopes) < M:
    for dx in range(1, s):
        dy = s - dx
        d = gcd(dx, dy)
        slopes.add((dx // d, dy // d))
    s += 1
slopes = sorted(slopes, key=lambda x: -x[1] / x[0])
tx, ty = sum(i[0] for i in slopes), sum(i[1] for i in slopes)
sx, sy = -tx, 0
poly = []
for dx, dy in slopes:
    sx += dx
    sy += dy
    poly.append((sx + X, sy + X))
for dx, dy in map(lambda x: (x[0], -x[1]), slopes[::-1]):
    sx += dx
    sy += dy
    poly.append((sx + X, sy + X))
for dx, dy in map(lambda x: (-x[0], -x[1]), slopes):
    sx += dx
    sy += dy
    poly.append((sx + X, sy + X))
for dx, dy in map(lambda x: (-x[0], x[1]), slopes[::-1]):
    sx += dx
    sy += dy
    poly.append((sx + X, sy + X))
while len(poly) != N:
    poly.pop()
# print(f'polygon{tuple(poly)}')
sys.stdout.write("\n".join(map(lambda x: f"{x[0]} {x[1]}", poly)))

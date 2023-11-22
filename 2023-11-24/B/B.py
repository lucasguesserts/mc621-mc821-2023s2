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
    while b: a, b = b, a%b
    return a

import sys
N = int(input())
if N == 3: print(0, 1), print(1, 1), print(1, 0), exit(0)
M = N//4+1
X = 2*10**7
slopes = set()
s = 2
while len(slopes) < M:
    for dx in range(1, s):
        dy = s - dx
        d = gcd(dx, dy)
        slopes.add((dx//d, dy//d))
    s += 1
slopes = sorted(slopes, key=lambda x: -x[1]/x[0])
tx, ty = sum(i[0] for i in slopes), sum(i[1] for i in slopes)
sx, sy = -tx, 0
poly = []
for dx, dy in slopes: sx += dx; sy += dy; poly.append((sx+X, sy+X))
for dx, dy in map(lambda x: (x[0], -x[1]), slopes[::-1]): sx += dx; sy += dy; poly.append((sx+X, sy+X))
for dx, dy in map(lambda x: (-x[0], -x[1]), slopes): sx += dx; sy += dy; poly.append((sx+X, sy+X))
for dx, dy in map(lambda x: (-x[0], x[1]), slopes[::-1]): sx += dx; sy += dy; poly.append((sx+X, sy+X))
while len(poly) != N: poly.pop()
#print(f'polygon{tuple(poly)}')
sys.stdout.write('\n'.join(map(lambda x: f'{x[0]} {x[1]}', poly)))

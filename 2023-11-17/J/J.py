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

# [UVa 11281 - Triangular Pegs in Round Holes](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2256)

For each triangular peg, we must:

1. Determine the minimum diameter $d$ through which the peg can pass;
2. Check for every known hole if that hole has a diameter of at least $d$.

Let $a$, $b$, $c$ be the lenghts of the sides of the triangular face of the peg.
Suppose $a \leq b \leq c$.

Determining the minimum diameter $d$ has two cases. We can compute the circumradius $r$, which is the radius
of the circumcircle around the triangle. Then $2r$ is a candidate for minimum possible diameter. To compute
$r$, we use the formula

$$ r = abc/(4\cdot area(a, b, c)) $$

where $area(a, b, c)$ is the area of the triangle with side lengths of $a$, $b$, and $c$, which
can be computed many ways, such as [Heron's formula](https://en.wikipedia.org/wiki/Heron%27s_formula).

___

However, $2r$ might be an overestimation of how big the diamater really must be.
If the triangle is obtuse, then the hole only needs to have a diameter equal to (at least) the longest side $c$.

To check for this case, we study the relation between $a^2 + b^2$ and $c^2$. If the angle between
the sides of lengths $a$ and $b$ is exactly $90^o$, then we know the relation must be an equality.
If the angle is bigger than that, then $c^2$ should also be bigger, and the reciprocal also holds.

In other words,

$$ c^2 > a^2 + b^2$$

if and only if the triangle is obtuse, making this case easy to check for."""

# ==================== Code ====================

from math import sqrt


# returns the area of triangle with sides of lengths a, b, c
def triangle_area(a, b, c):
    s = (a + b + c) / 2
    return sqrt(s * (s - a) * (s - b) * (s - c))


# returns the radius of the circumcircle of triangle with sides of lengths a, b, c
def r_circumcircle(a, b, c):
    return a * b * c / (4 * triangle_area(a, b, c))


# returns true if triangle is obtuse, supposing side lengths a <= b <= c
def is_obtuse(a, b, c):
    return c * c > (a * a + b * b)


nholes = int(input())
holes = [float(x) for x in input().split()]
npegs = int(input())
pegnames = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for i in range(npegs):
    a, b, c = sorted(map(float, input().split()))
    minimum_diameter = c if is_obtuse(a, b, c) else 2 * r_circumcircle(a, b, c)
    fits = [str(j + 1) for j in range(nholes) if holes[j] >= minimum_diameter]
    print(f"Peg {pegnames[i]} will", end=" ")
    if fits == []:
        print("not fit into any holes")
    else:
        print("fit into hole(s): " + " ".join(fits))

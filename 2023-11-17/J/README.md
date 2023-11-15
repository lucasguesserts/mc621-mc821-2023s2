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

if and only if the triangle is obtuse, making this case easy to check for.
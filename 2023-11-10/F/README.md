# [UVa 01595 - Symmetry](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4470)

Let $n$ be the size of our vector `P` of points. We want to determine whether `P` has $x$-axis
symmetry.

We start by sorting the points by smallest x-coordinate, breaking ties by smallest y-coordinate.

Thus, the leftmost and rightmost points (possibly tied with others) are
`P[0]` and `P[n-1]` respectively. Let $x_1$ and $x_n$ be their respective $x$ coordinates.
If `P` is $x$-symmetric, then the symmetry should be around

$$ \bar{x} = \frac{x_1 + x_n}{2} $$

which can be fractional. More precisely, it can be *half-integer*, since every coordinate in the input is integer.

Given a point $p = (x, y)$ in left side of `P`, we know that `P` is $x$-symmetric only if the *counterpart* $q$ of $p$ in `P`,
where

$$ q = (x + 2(\bar{x} - x) , y) = (2\bar{x} - x, y). $$

Therefore, we can completely avoid storing fractional coordinates, since we don't really need $\bar{x}$ (half-integer)
but really $2\bar{x}$ which is guaranteed to be integer.

The algorithm is the following:

1. sort `P` (as described above, first by smallest $x$-coordinate);

2. store every point in `P` in a set of known points, `S`;

3. for `i = 0, 1, 2, ..., n/2` (thus checkint the first $\lceil n/2 \rceil$ points):

    - let `q` be the counterpart of point `P[i]` as described by the formula above;

    - if `q` does not exist in `S`, then `P` is not symmetric: return `false`;

4. return `true`.
# [UVa 10263 - Railway](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1204)

The problem is as follows: for each test case, we begin by establishing a point of interest $p = (x, y)$.

Then, for a given $n$, we receive $n+1$ pairs $(x_0, y_0), (x_1, y_1), \ldots, (x_n, y_n)$ representing the $n$
line segments that form a railroad. (Notice that $(x_1, y_1)$ is the end of the first segment and the start of the second
one, and so on.)

Our task is to find the poinx $(x_c, y_c)$ in the railroad which minimizes the distance to our point of interest $p$.

The [*Competitive Programming* book by Halim, Halim, and Effendy](https://cpbook.net/) offers a codebase of useful
types, functions and implementations in different languages in their [open repository](https://github.com/stevenhalim/cpbook-code).
Using their code for lines and segments ([chapter 7](https://github.com/stevenhalim/cpbook-code/tree/master/ch7)), we have an
operation that directly solves this problem.

Function `distToLineSegment` receives a point `p`, two points `(a, b)` defining a segment, and a result point `c`.
It returns the minimum distance from `p` to `(a, b)` and stores the closest point of the segment in `c`.

All we have to do here is read the input carefully and store the minimum distance, along with the minimizing point.
At the end of each test case, we output the coordinates of the minimizing point.

## Possible difficulties

* Actually understanding the problem statement;

* Realizing that the given coordinates are not necessarily integer;

* Trimming the available code down to the bare essentials needed. (Optional)
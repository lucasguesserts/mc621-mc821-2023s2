# [UVa 10577 - Bounding Box](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1518)

We have an $n$-sides regular polygon, where we know $n$ and three distinct points.
With this, we can recover every vertex of the polygon. With that, it is a simple matter
of computing $x_{\min}$, $x_{\max}$, $y_{\min}$ and $y_{\max}$ of the vertices of the polygon, giving
a rectangular bounding box area of

$$ (x_{\max} - x_{\min})\cdot(y_{\max} - y_{\min}) .$$

It remains to discuss how to obtain the other vertices.

## Obtaining vertices from what we know from the input

There are many slightly different ways to do this, but one way follows:

First, compute the circumcircle of the 3 known points (treating them as vertices of a triangle).
This is the circumcircle of the whole polygon.
Let $(x_c, y_c)$ be the center of the circumcircle, and $r$ its radius;

We know that every vertex is located at

$$(x, y) = (x_c + r \cos{\theta}, y_c + r \sin{\theta})$$

where $\theta$ is the angle of the vector that goes from $(x_c, y_c)$ to $(x, y)$. We call this the
*central angle* of the vertex $(x,y)$.

Since this is a regular polygon, the central angle of consecutive vertices is evenly spaced by
a difference of $2\pi/n$. If we know the angle $\theta$ of a vertex $(x_0, y_0)$, then we can obtain all the
other vertices by computing

$$ (x_c + r \cos(\theta + 2\pi k/n), y_c + r \sin(\theta + 2\pi k/n)) $$

for $k = 1, 2, \ldots, n-1$.

We know three points and any of them can be used as the initial vertex $(x_0, y_0)$. The angle $\theta$ can
be obtained in a number of ways, such as

$$ \theta = \arccos{\frac{x_0 - x_c}{r}} .$$

The above observations give the algorithm below.

Given points $p_1$, $p_2$, $p_3$ of the $n$-sided regular polygon:

1. Compute center $(x_c, y_c)$ and radius $r$ of circumcircle of points $p_1, p_2, p_3$;

2. Compute $\theta = \arccos{(x_0 - x_c)/r}$ where $x_0$ is the $x$ of point $p_1$ (could be any of the three points);

3. For `k = 1..n-1`:
    - Compute new vertex $(x, y) = (x_c + r \cos(\theta + 2\pi k/n), y_c + r \sin(\theta + 2\pi k/n)) $

4. Let
    - $x_{\min}$, $y_{\min}$ be the minima of $(x, y)$ of the vertices;
    - $x_{\max}$, $y_{\max}$ be the maxima of $(x, y)$ of the vertices;

5. Output $(x_{\max} - x_{\min})\cdot(y_{\max} - y_{\min})$.
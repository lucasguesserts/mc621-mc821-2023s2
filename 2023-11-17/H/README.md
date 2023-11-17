# [Kattis - Polygon Area](https://open.kattis.com/problems/polygonarea)

This is a direct application of the [Shoelace Formula](https://en.wikipedia.org/wiki/Shoelace_formula) for computing
the area of a polygon.

Simply put, if a polygon $P$ is described by the points $(x_0, y_0), \ldots, (x_{n-1}, y_{n-1})$, in either clockwise
or counterclockwise order, then

$$ \sum_{i=0}^{n-1} \left(x_iy_{i+1} - x_{i+1}y_i\right) $$

is 2 times the *signed area* of $P$. Here we are considering $(x_n, y_n) = (x_0, y_n)$.

In this problem, the coordinates are all integer and thus the above
formula gives an integer result (therefore, the actual area is half-integer).

The signed area of $A$ is its area with

* negative sign, if the points are in clockwise order;
* positive sign, otherwise.
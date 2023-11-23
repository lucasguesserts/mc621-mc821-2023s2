# [Kattis convexhull - Convex Hull](https://open.kattis.com/problems/convexhull)

Just compute the convex hull. Use any algorithm available in the literature.

Things to be careful:

1. there should not be duplicate points in the convex hull. Halim's algorithm does produce duplicate points (it repeates the first point). You need to remove them.
2. It must be in counter-clockwise order. Halim's `CH_Andrew` algorithm does just that (I don't know what `CH_Graham` does). But if you use another algorithm, you need to make sure that the points are in counter-clockwise order.

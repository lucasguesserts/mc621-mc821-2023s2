# [Kattis cookiecutter - Cookie Cutter](https://open.kattis.com/problems/cookiecutter)

To rescale, one simply has to multiply all points by a given value. To move, one simply has to add a value to all points. The algorithm then is:

1. let $P$ be the polygon;
2. compute the area $PA$ of the polygon $P$;
3. compute the resize factor $s = \sqrt{\dfrac{A}{PA}}$;
4. multiply all points of $P$ by $s$;
5. find $x_{\min}, y_{\min}$, the minimum value of the coordinates $x$ and $y$ of the points of $P$, respectively;
6. subtract $x_{\min}$ from all $x$ coordinates and $y_{\min}$ from all $y$ coordinates of the points of $P$;
7. output the new points of $P$;

# [Kattis - Estimating the Area of a Circle](https://open.kattis.com/problems/estimatingtheareaofacircle)

In this problem, given a radius $r$, a number of tested points $n$ and the
number $m$ of points that are inside the circle, we are to output both

* The actual area of the circle of radius $r$, which is $\pi r^2$;

* The area that would be estimated (without using $\pi$) by scaling the area of the circumscribed
square (which is $4r^2$) by the proportion of points that were verified to be
inside the circle (which is $p = m/n$). Thus the expression for the estimated
area is $4r^2 p$.
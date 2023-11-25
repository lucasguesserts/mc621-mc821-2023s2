# [Kattis roberthood - Robert Hood](https://open.kattis.com/problems/roberthood)

Ideally, one would like to compare all points with all points to find the longest distance. That would take $\mathcal{O}(n^2)$ time, which is too slow given that the size of the input is $2 \leq C \leq 10^5$.

A better approach is to do the following:

1. let $P$ be all the points;
2. compute $H$ the convex hull of $P$;
   1. this step takes $\mathcal{O}(|P| \log(|P|))$ time;
3. compare all points in $H$ to find the longest distance
   1. this step takes $\mathcal{O}(|H|^2)$ time;
   2. hopefully, $|H|$, the size of $H$, is much smaller than $|P|$, and the algorithm works;

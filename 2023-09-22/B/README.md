# [UVa - 10104 - Euclid Problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1045)

The solution is simply the Extended Euclidean Algorithm. The part about minimizing $|X| + |Y|$ is irrelevant because that only happens when $A$ is a multiple of $B$ (the actual case is that one is looking for $X$ and $Y$ such taht $AX + BY = 0$). In such case, the Extended Euclidean Algorithm will already give the right answer.

However, one must be careful with how the input is taken and when it ends (that is really the annoying part).

## Extended Euclidean Algorithm - References

* <https://brilliant.org/wiki/extended-euclidean-algorithm/>;
* <https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm>;
* <https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/>

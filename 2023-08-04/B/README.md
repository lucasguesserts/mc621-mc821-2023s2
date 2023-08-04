# [Tree Master](https://codeforces.com/problemset/problem/1806/E)

This mostly just requires storing the tree and performing the described
computation algorithm efficiently enough.

The challenge here is the fact that for each instance there may be a large
number of queries. As such, and considering that `f(x,y)` is dependent on
`f(p(x),p(y))` i.e. the computation for the parents of `x` and `y`, we employ
memoization.

This requires having a table that stores for each `x` and `y` *that are on the
same level on the tree* the result of `f(x,y)` if it has already been
computed.

Moreover, we do *not* want to store pairs for a level of the tree if said level
has $\Theta(n)$ nodes, since this yields $\Theta(n^2)$ pairs, which is too costly.
A strategy that can be employed is to store pairs only of levels populated by
at most $\sqrt{n}$ nodes, resulting in $n$ pairs to be stored.


# [Tree Master](https://codeforces.com/problemset/problem/1806/E)

## Please note that the current answer hasn't been accepted yet.

This mostly just requires storing the tree and performing the described
computation algorithm.

The challenge here is the fact that for each instance there may be a large
number of queries. As such, and considering that `f(x,y)` is dependent on
`f(p(x),p(y))` i.e. the computation for the parents of `x` and `y`, we employ
memoization.

This requires having a table that stores for each `x` and `y` *that are on the
same level on the tree* the result of `f(x,y)` if it has already been
computed.

Such a table is viable because its size is limited by `h*g`, where `h`
is the total height of the tree and `g` is its *girth*, i.e., number of nodes
in the most populated level.

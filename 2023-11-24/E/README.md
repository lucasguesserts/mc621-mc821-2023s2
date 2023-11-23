# [UVa - 11473 - Campus Roads](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=26&page=show_problem&problem=2468)

Although this problem doesn't seem to be complex, it has some annoying cases to cover.

The general idea is to put the trees uniformly distributed in the straight parts of the road. The problem is that the road can have curves. Sometimes one will have to consider the distance before a curve to put the next tree (really, that is the difficult part).

The algorithm becomes kinda complex just because one has to keep track of the last point where a tree was put and the distance from it to the next curve..

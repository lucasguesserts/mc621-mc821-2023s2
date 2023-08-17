# [Squawk Virus](https://open.kattis.com/problems/squawk)

This problem requires us to answer the following: given a graph $G$, a source vertex $s$ and an integer $t>0$,
how many paths of length~$t$ with source~$s$ exist in~$G$?

Solution:
* Let~$A$ be the adjacency matrix of~$G$;
* Then for each nonnegative integer $i$, and each pair of vertices~$x, y$, $A^i_{x,y}$ counts the $x,y$-paths
of length $i$;
* Therefore, the answer to the problem is $\sum_{u} A^t_{s,u}$, i.e., we compute $A^t$ and sum the contents
of line~$s$.

Ideally, one should use fast exponentiation for the third step, but it is not actually required by the
online judge, at least in C/C++.


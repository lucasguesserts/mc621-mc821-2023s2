# [11036 - Eventually Periodic Sequence](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1977)

The anooying part of the problem is to implement the two functions specified: $f$ and $F$

For $f$, create a stack to process the Reverse Polish Notation.

For $F$, make a recursive solution.

The other tricky part is with the $\% N$. There is one input for which the value of $f$ does not fit in a `int64_t`. Since all inputs end with $\% N$, the solution I proposed then is to compute the $\% N$ at each step of the computation of the value of $f$.

Finally, for the cycle detection, simply implement the Floyd (tortoise and hare) algorithm with some modifications.

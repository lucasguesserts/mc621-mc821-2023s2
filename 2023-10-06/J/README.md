# [UVa 455 - Periodic Strings](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=396)

Let $k \in \mathbb{Z}_+$ be a number. Take the prefix $f$ of the string $s$ of length $k$. Create a string $s'$ by concatenating the prefix $f$ till it has the size of $s$. If $f = s$, then $s$ has period $k$.

To solve the problem, start with $k = 1$ and check two conditions:

1. $len(s)$ is divisible by $k$;
2. $s$ is equals to $len(s) / k$ concatenations of $f$, where $f$ is the prefix of $s$ with size $k$;

The first $k$ for which both conditions hold is the answer of the problem.


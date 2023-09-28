# [Fibonacci Cycles](https://open.kattis.com/problems/fibonaccicycles)

We are given, for each test case, a positive integer $k$, $2 \leq k \leq 10^3$.
Since the question involves Fibonacci numbers modulo $k$, there are only
$k$ possible results (0 through $k-1$). Thus, before treating any test case
we precompute the first 1000 numbers of the Fibonacci sequence as these are
at most what we shall need.

Let $F_0 = 1, F_1 = 1, F_2 = 2, \ldots$ be the Fibonacci sequence.

Then, given $k$, we wish to find the minimum $i \geq 2$ such that there is some
$j > i$ with $F_i \equiv F_j \pmod{k}$. It suffices to maintain a table `t`
of size $k$ such that for each `r` we store in `t[r]` the first index $i$
such that $F_i \equiv r \pmod{k}$. We iterate through $F_2, F_3, \ldots$ and stop
when find an index $j$ with $F_j \pmod{k}$ already existing in the table.

Notice that we wish to output $i$ (index of the original occurence) rather
than $j$ (index of first repetition).

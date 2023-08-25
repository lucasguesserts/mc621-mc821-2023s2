# [Two Round Dances](https://codeforces.com/problemset/problem/1433/E)

There are $n$ people ($n$ even) who we want to separate into two groups of
same size (for each of the dances). This gives "$n$ choose 2" options for
the division, which is equal to $n!$.

Furthermore, given a division, we wish to count the possible permutations
of people inside each group. At first, each round would have $(n/2)!$ permutations, but
since we consider permutation $(1, 2, 3)$ equal to $(2, 3, 1)$ and $(3, 1, 2)$, we
have to divide that number by the number of participants of the round,
which is $n/2$.

Finally, since we are not distinguishing for the order in which the groups of
size $n/2$ dance, we have to divide our results by 2.

This amounts to

$$ \frac{n!}{(n/2)!^2}\frac{(n/2)!}{n/2}\frac{(n/2)!}{n/2}\frac{1}{2} $$

which simplifies to

$$ \frac{n!}{2 (n/2)^2}$$

distinct dances.

This can be further simplified, but pay attention to small $n$.

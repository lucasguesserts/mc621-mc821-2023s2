# [Beautiful Numbers](https://codeforces.com/problemset/problem/300/C)


Notice that we are interested the numbers with length equals `n` (requirement of the problem) with only the digits `a, b` (so they are good).

Suppose one has `n_a` digits `a` and `n_b` digits `b`. One can verify if any number with those digits is excellent by checking if `n_a * a + n_b * b` is good. If that is the case, well, using combinatorics, one knows how many numbers are excellent with those digits: `n! / (n_a! * n_b!) = C(n_a + n_b, n_a)`.

Now, to solve the problem, one has to iterate over all possible values of `n_a` and `n_b` such that `n_a + n_b = n` and sum the quantity of number which are excellent.

There is a catch: one has to efficiently compute the number of combinations modulo `10^9 + 7`.

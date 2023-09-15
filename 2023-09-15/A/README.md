# [Enlarging Hash Tables](https://open.kattis.com/problems/enlarginghashtables)

One only needs to test $2n+1, 2n+2, \ldots$ for primality. Here we implement a solution using a sieve
up to $40000$ since $n$ can be up to $2^{30}-1$ and thus we should aim for a sieve up to a good margin
over $\sqrt{2n}$.

It should be noted that this is an easy problem that does not actually require the use of a sieve to pass.

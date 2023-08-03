# [PolandBall and Hypothesis](https://codeforces.com/problemset/problem/755/A)

The problem statement pretty much gives an algorithm:

* we test each candidate solution from `m = 1` to at most `m = 1000`,
checking whether `n*m + 1` is prime.

* if the number is composite, we stop immediately and output `m` as our counterexample.

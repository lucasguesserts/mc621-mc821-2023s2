# [In Search of Truth (Hard Version)](https://codeforces.com/problemset/problem/1840/G2)

Let `a1,a2,…,an` be the numbers of the sectors in clockwise order, and let the arrow initially point to the sector with number a1.

First, let's make 999 queries of `+1`, then we will know the numbers of 1000 consecutive sectors. If `n < 1000`, then the number of the first query that gives the answer `a1` is the desired `n`.

If we did not find `n`, this means that `n >= 1000`. Let's save `a1,a2,…,a1000`. Now we will make queries of `+1000` until we get one of the numbers `a1,a2,…,a1000` as the answer. Note that we will need no more than `1000` queries of this type, after which it is easy to determine the number `n`.

Thus, we can determine the number `n` in no more than `999+1000 = 1999 <= 2023` queries.

source: [Codeforces Round #878 (Div.3) Editorial](https://codeforces.com/blog/entry/117060).

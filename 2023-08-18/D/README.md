# [Raising Bacteria](https://codeforces.com/problemset/problem/579/A)

Given any positive integer `x`, one can write it as (one can prove by induction, but I am not going to prove it here):

```plain
x = a0 . 2^n + a1 . 2^(n-1) + ... + an . 2^0

a0, ..., an ∈ {0, 1}
```

The way to get the desired amount of bacterias is by putting only one each time and letting them grow. And with the above decomposition, we can know that we need to put `1` in the `i`-th day if `ai = 1`. Thus the answer is the number of `1`s in `a0, ..., an`.

To compute such number, one can start by finding the largest `n` such that `2^n <= x` (which can be computed as `pow(2, floor(log2(x)))`). Then we can subtract `2^n` from `x` and repeat the process until `x = 0`. The number of times we subtract `2^n` is the number of `1`s in the binary representation of `x`.

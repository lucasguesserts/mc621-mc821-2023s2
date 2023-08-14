# [2^Sort](https://codeforces.com/problemset/problem/1692/G)

The condition

```plain
2^{0} . a_{i} < ... < 2^{k} . a_{i + k}
```

is equivalent to:

```plain
a_{i + j} < 2^{1} . a_{i + j + 1} , \forall j = 0, ..., (k - 1)
```

So one can partition the sequence `a_{1}, ..., a_{n}` in the indices which do not satisfy the condition above:

```plain
[lb_{1}, ub_{1}], ..., [lb_{m}, ub_{m}]
```

where `lb_{i} = ub_{i - 1} + 1` (and `ub_{i} = lb_{i + 1} - 1`) for `i = 2, ..., (m - 1)`, `lb_{1} = 1`, and `ub_{m} = n`.

Notice that, in the subsequence induced by the indices `[lb_{m}, ub_{m}]`, the condition holds. Furthermore, there are `(ub_{m} - lb_{m} + 1) - (k + 1) + 1` subsequences of length `k + 1` which satisfy the condition of the problem.

Thus, the answer for the problem is (notice that the `max` removes the negative values):

```plain
sum_{i = 1}^{m} max[(ub_{i} - lb_{i} + 1) - (k + 1) + 1, 0]
```

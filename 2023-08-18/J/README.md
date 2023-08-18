# [Festival Organization](https://codeforces.com/contest/717/problem/A)

Let:

1. `k`: the size of the groups of tours;
2. `l`: the minimum lenght of the tours;
3. `r`: the maximum lenght of the tours;

## Example

```plain
k = 2
l = 2
r = 3

tours of length 1: 0, 1
tours of length 2: 01, 10, 11
tours of length 3: 010, 110, 011, 101, 111

groups of 2 different tours of length 1: {0, 1}
groups of 2 different tours of length 2: {01, 10}, {01, 11}, {10, 11}
groups of 2 different tours of length 3: {010, 110}, {010, 011}, {010, 101}, {010, 111}, {110, 011}, {110, 101}, {110, 111}, {011, 101}, {011, 111}, {101, 111}

answer: 3 + 10 = 13
```

## Basic idea of the algorithm

```plain
N = 10^9 + 7
count = 0
for n = l to r:
    number of tours = number of valid tours of length n
    number of groups = number of groups of k different tours of length n
    count += number of groups % N
```

### number of groups of `k` different tours of length `n`

That is easy, it is just the number of combinations of `k` elements from `m = number of valid tours of length n: `m! / (k! * (m - k)!)`.

### number of valid tours of length `n`

Let:

1. `t(n)` be the number of valid tours of length `n`;
2. `c(i, n)` be the number of valid tours of length `n` that end with `i ∈ {0, 1}`;

Notice that:

1. `t(n) = c(0, n) + c(1, n)`
2. `c(0, n) = c(1, n - 1)`
   1. because by appending `0` to a valid tour of length `n - 1` which ends in `1`, we get a valid tour of length `n` which ends in `1`;
   2. notice also that appending `0` to a valid tour of length `n - 1` which ends in `0` does not give to one a valid tour;
3. `c(1, n) = c(1, n - 1) + c(0, n - 1) = t(n - 1)`
   1. because by appending `1` to a valid tour of length `n - 1`, we get a valid tour of length `n` which ends in `1`;

Thus:

```plain
c(1, n) = c(1, n - 1) + c(0, n - 1) = c(1, n - 1) + c(1, n - 2)
and
c(0, n) = c(1, n - 1)
```

And so we can compute `c(1, n)` using the [Fibonacci Sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence).

### Computing `c(1, n)` using the Fibonacci Sequence

[Fibonacci Sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence):

| f(0) | f(1) | f(2) | f(3) | f(4) | f(5) | f(6) | ... |
|------|------|------|------|------|------|------|-----|
| 0    | 1    | 1    | 2    | 3    | 5    | 8    | ... |

From the [example](#example) above, notice that:

| c(1, 1) | c(1, 2) | c(1, 3) | ... |
|---------|---------|---------|-----|
| 1       | 2       | 3       | ... |

Thus:

```plain
c(1, n) = f(n + 1)
c(0, n) = c(1, n - 1) = f(n)
```

## Open Problems

1. computing `m! / (k! * (m - k)!)` is expensive (`O(m)`) if `m` is large. Besides, in our algorithm, `m` is in the order of `number of valid tours of length r`, which is in the order of `a^r` (exponential) (`a` is any constant);
2. the algorithm proposed has complexity `O(r * a^r)`, but it is not fast enough for `r = 10^9`;

I have submitted the code and it failed for the input `1 1 1000000000000000000` (`r = 10^18`), as expected.

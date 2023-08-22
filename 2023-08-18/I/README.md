# [Beautiful Numbers](https://codeforces.com/problemset/problem/300/C)

## Combinatorial Solution

We are interested the numbers with length equals `n` (requirement of the problem) with only the digits `a, b` (so they are good).Suppose one has `k` digits `a` and `n - k` digits `b`. One can verify if any number with those digits is excellent by checking if `k * a + n_b * b` is good. If that is the case, well, using combinatorics, one knows how many of those numbers there are: `n! / (k! * n_b!) = C(n, k)`.

To solve the problem, one has to iterate over `k = 0, ..., n`. If the sum `k * a + (n - k) * b` is good, one has to accumulate the value `C(n, k)`.

There is a catch: the value `C(n, k)` may be VERY large, and so computing it is not fast. One has to find a way to compute it modulo `10^9 + 7` fast.

## Computing `C(n, k) % (10^9 + 7)` Efficiently

To solve it, we are going to use:

* [modular arithmetic](https://en.wikipedia.org/wiki/Modular_arithmetic)
    * `a % b = a mod b` is the remainder of the division of `a` by `b`;
    * `≡` is the symbol for modular congruence (same remainder). We write `a ≡ b (mod m)` if `a mod m = b mod m`;
    * `inv(a)` is the modular inverse of `a`, it is the value `x` which satisfy `a * x ≡ 1 (mod m)`. It is guarantee to exist when `a` and `m` are coprime (i.e. `gcd(a, m) = 1`);
* `N = 10^9 + 7 = 1000000007` is a prime number.

Notice that:

```plain
C(n, k) % N =
= n! / ((n - k)! * k!) % N
= n! % N * inv((n - k)! * k!) % N
```

Now one needs efficient ways of computing both parts of the last expression.

### Part I

```plain
n! % N =
= (n * (n - 1) * ... * 1) % N
= (n % N * (n - 1) % N * ... * 1 % N) % N
```

That takes `O(n)` time. However, one can compute all values `i % N` for `i = 1, ..., n` in `O(n)` once so that, when the value is required, it has already been computed.

### Part II

Let `K = (n - k)! * k!` (just to simplify the notation). By Fermat's Little Theorem:

```plain
K^(N-1) ≡ 1 (mod N)->
-> K^(N-1) * inv(K) ≡ inv(K) (mod N)
-> K^(N-2) * (K) * inv(K) ≡ inv(K) (mod N)
-> K^(N-2) ≡ inv(K) (mod N)
-> inv((n - k)! * k!) ≡ ((n - k)! * k!)^(N-2) (mod N)
```

Thus one can compute `inv((n - k)! * k!)` by computing `((n - k)! * k!)^(N-2)`. But notice that `((n - k)! * k!)^(N-2)` is a power of a number, and so one can compute it efficiently using [Fast Exponentiation](https://en.wikipedia.org/wiki/Exponentiation_by_squaring).

```plain
((n - k)! * k!)^(N-2) % N =
= (((n - k)! % N * k! % N) % N)^(N - 2) % N
```

Notice that the values `(n - k)! % N` and `k! % N` have already been computed in Part I, one can simply access them. Now, for the exponentiation, one can use the following recursive formula: let `X, Y \in \N*` (positive integers). Then:

```plain
X^(Y) % N = {
    (X^(Y / 2) % N * X^(Y / 2) % N) % N, if Y is even
    (X^(Y / 2) % N * X^(Y / 2) % N * X % N) % N, if Y is odd
}
```

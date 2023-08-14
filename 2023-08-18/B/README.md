# [A. Modular Exponentiation](https://codeforces.com/problemset/problem/913/A)

The problem is quite simple, simply compute the remainder using the built-in function `%` of c++. There is a catch though: `n` may be too large for one to compute `2^n`. If that is the case, one can consider that `m < 2^n` so the answer for the problem is simply `m`.

But how to verify if `2^n` is too large to be computed? Well, if `n > floor(log2(MAX_INT))`, then one cannot compute `2^n`.

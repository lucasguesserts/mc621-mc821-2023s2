# [Last Digit](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1103)

In this problem, we are given a positive integer $N$, $1 \leq N \leq 2\cdot 10^{100}$,
and are tasked to output the last digit of the sum

$$ S_N = 1^1 + 2^2 + 3^3 + \ldots + N^N.$$

The above sum defines a sequence $S_1, S_2, \ldots$ with $S_1 = 1$ and
$S_N = S_{N-1} + N^N$.

Define the sequence $L_1, L_2, \ldots$ as $L_N = S_N \pmod{10}$, i.e. the last digit
of $S_N$. It is $L_N$ that we wish to compute.

We implement a function `last_digit_pow(a, b)` that returns $a^b \pmod{10}$. Then we
can compute many terms of the sequence $(L_i)_{i\geq 1}$ as such:

```
L[1] = 1
L[n] = (L[n-1] + last_digit_pow(n, n)) % 10
```

Tinkering with this sequence, we come to realize that

* `L[1] = L[101] = L[201] = ...`
* `L[2] = L[102] = L[202] = ...`

and so forth. It requires some combination of time, patience, and/or further
programming to realize the above pattern of repetition. It might not be hard
to prove it mathematically, but we haven't checked for that here.

With this, we only need to compute the first 100 hudred distinct values and check, for
each input, what case it falls into. (Namely, we check its value modulo 100 and
output the corresponding result from the table.)

For ease of coding, one may define `L[0] = L[100]` (which incidentally is equal to 0)
even though the sequence is not defined for index 0.

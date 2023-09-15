# [Row GCD](https://codeforces.com/problemset/problem/1458/A)

We have positive integers $a_1, a_2, \ldots, a_n$ and $b_1, b_2, \ldots, b_m$
and wish to find, for each $j = 1, 2, \ldots, m$, $G_j = gcd(a_1 + b_j, a_2 + b_j, \ldots, a_n + b_j)$.

Given that $gcd(a, b, c) = gcd(a, gcd(b, c))$, computing the GCD of $n$ numbers requires
$n$ calls to function `gcd`.

The straightforward solution (manually computing $O(nm)$ GCD's) is simply too expensive
since both $n$ and $m$ could be up to $2\cdot 10^5$ meaning $4\cdot 10^{10}$ calls to function
`gcd`.

The speedup this problem is looking for is as follows: realize that $gcd(a, b) = gcd(a, b-a)$.
Then

$$
\begin{align}
    G_j &= gcd(a_1 + b_j, a_2 + b_j, \ldots, a_n + b_j) \\
    &= gcd(a_1 + b_j, a_2 + b_j - (a_1 + b_j), \ldots, a_n + b_j - (a_1 + b_j)) \\
    &= gcd(a_1 + b_j, a_2 - a_1, \ldots, a_n - a_1)
\end{align}
$$

Thus, if we precompute $G_a = gcd(a_2 - a_1, a_3 - a_1, \ldots, a_n - a_1)$, then every
$G_j$ is simply

$$ G_j = gcd(a_1 + b_j, G_a) $$

so we can compute the whole output in only $O(n + m)$ calls to `gcd`.

A few traps:

* We could have $n=1$. In this case $GCD_a$ should be considered to be 0 rather than $a_1$;
* For each $i$, we could have $a_i - a_1 < 0$. There are a few different ways to deal with this, but
my favorite is to simply use $|a_i - a_1|$ because in the context of modular arithmetics the semantics
of C++'s `%` operator are confusing.

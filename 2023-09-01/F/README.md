# [Tennis contest](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3888)

If we have $n$ trials of an event with probability $p$, the probability of
having *exactly* $k$ successes is

$$ p(n, k) = \binom{n}{k} p^k (1-p)^{n-k} $$

as we need $k$ successes, $n-k$ failures and there are $\binom{n}{k}$ orders
in which this may happen.

In this problem, we are interested in the following question: what is the
probability of having *at least* $n$ successes from $2n-1$ trials?

The answer is

$$ \sum_{k=n}^{2n-1} p(2n-1, k) $$

where $p(2n-1, k)$ is computed by the expression given in the beginning.

To make this fast, we memorize the already known binomial coefficients.

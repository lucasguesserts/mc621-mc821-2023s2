# [What is the Probability?](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=997)

First, notice that if $p = 0$ the problem becomes easy: no player has
any hope of winning, i.e. the probability is $0$ regardless of who is the
target player. Treat this case separately and assume $p > 0$ for the following
explanation.

There are infinitely many possible turns $1, 2, 3, \ldots$  in the game.
Turn $j$ is the winner with probability

$$ (1-p)^{j-1} p $$

i.e. it is necessary that the previous turns lose and $j$ wins. It is not
hard to verify that the sum of the above expression for every $j$ is 1, meaning
it makes sense as a probability function.

We have $N$ players, so for $i = {1, 2, \ldots, N}$, player $i$
wins if the winning turn is $i + kN$ for some integer $k\geq 0$.

Thus, defining $q := 1-p$, the probability of player $i$ winning is

$$
\begin{align\*}
    \sum_{k \geq 0} (1-p)^{i + kN -1} p
        &= \sum_{k \geq 0} p(1-p)^{i-1}\left((1-p)^N\right)^k \\
        &= q^{i-1} (1-q) \sum_{k\geq 0} (q^N)^k \\
        &= \frac{q^{i-1}(1-q)}{1-q^N}
\end{align\*}
$$

requiring only a straightforward implementation.
Remember once more that we are assuming $p > 0$ (and thus $1-q^N$ is nonzero).

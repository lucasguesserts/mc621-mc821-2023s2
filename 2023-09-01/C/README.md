# [What is the Probability?](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=997)

There are infinitely many possible turn $1, 2, 3, \ldots$  in the game.
Turn $j$ wins with probability

$$ (1-p)^{j-1} p $$

i.e. it is necessary that the previous turns lose and $j$ wins. It is not
hard to verify that the sum of the above expression for every $j$ is 1, meaning
it makes sense as a probability function.

We have $N$ players, and so we are going
to model it in this way: for each $i \in \{1, 2, \ldots, N\}$, player $i$
wins if the winning turn is $i + kN$ for any nonnegative integer $k$.

Thus, defining $q := 1-p$, the probability of player $i$ winning is

$$
\begin{align\*}
    \sum_{k \geq 0} (1-p)^{i + kN -1} p
        &= \sum_{k \geq 0} p(1-p)^{i-1}\left((1-p)^N\right)^k \\
        &= q^{i-1} (1-q) \sum_{k\geq 0} (q^N)^k \\
        &= \frac{q^{i-1}(1-q)}{1-q^N}
\end{align\*}
$$

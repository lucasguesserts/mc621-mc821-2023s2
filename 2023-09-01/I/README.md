# [God! Save me](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1718)

Let $l_1, l_2, \ldots, l_n$ be the tavel lengths associated with doors $1$
through $n$. As in the problem statement, a negative length represents a door
that leads back to the initial room.

Let $p_1, p_2, \ldots, p_n$ be the probabilities of the doors. Let

$$ p = \sum_{l_i > 0} p_i $$

i.e. $p$ is the probability that we successfully find the exit in any given
attempt. If $p = 0$, there is no way out and we output `God! Save me` as
required by the problem. From now on, assume $p > 0$ and thus that we eventually
find the exit.

To compute the expected length of travel, first notice that, from the starting
position, the expected length of one attempt (one "step") is

$$ L = \sum_{i=1}^n p_i |l_i| $$

which we can compute in real time as we read the input.

Let $T$ be the expected time we spend until we find the exit, which is the
number we wish to output.

After one step (with expected length $L$), we successfully get out with
probability $p$ and we go back to the start with probability $1-p$.
If we go back to the beginning, after that we expect to take $T$ more time
to find the exit.

So $T$ is the only solution of the equation

$$ T = L + (1-p)T $$

or simply

$$ T = L/p $$

again assuming $p > 0$.

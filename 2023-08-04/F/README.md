# [Dreamoon and WiFi](https://codeforces.com/problemset/problem/476/B)

## Compute the expected position based on the commands sent

This is based on the commands sent by Drazil to Dreamoon (first line of the input). Starting at `0`, add `1` for each `+` and `-1` for each `-`. The result is the expected position of Dreamoon.

## Compute the expected position based on the commands successfully received

This is based on the second line of the input and it does not consider the unrecognized commands (the `?`). As in the previous case, starting at `0`, add `1` for each `+` and `-1` for each `-`, and ignore any `?`. The result is the base position to be used for computing the probabilities.

## Compute the probability of each position

One can see the possible positions of Dreamoon as a binary tree. First, notice that the order in which the commands are received are irrelevant: the only thing that matters is the number of `+, -, ?`. Now consider how the binary tree is built: each node is characterized by three things: the number of `?` not yet considered, the position it is in, and the probability to be reached. If not all the `?` have been considered, then it has two branches:

1. one in the position `+1` with half of its probability and one less `?` to consider;
2. one in the position `-1` with half of its probability and one less `?` to consider;

If it is a leaf node, then one has to increase the probability that Dreamoon reaches the position of the leaf by the probability of the leaf (use a map for storing such values).

In the end, one just has to chech the probability that Dreamoon reaches the position computed based on the commands sent.

## A better way

### Idea

The ideia is, given the unknowns ?, to compute the number of interpretations of the signal that can get Dreamoon to the desired position and dive such value by the number of possible interpretations.

Suppose there are 4 unknowns and Dreamoon must get from the position 0 to the position 2. Then any interpretation must have a balance of two positives, and the rest must cancel each other. Thus, the signal must be "+++-" or any permutation of it. The number of possible interpretations is $2^N$, being $N$ the number of unknowns. Thus the answer is:
$$\dfrac{4!}{3!1!}\  / \ 2^4 = 0.25$$

### Algorithm

With the signal received, compute the "middle position" $p_m$. With the expected signal, compute the expected position $p_e$. Let $N$ be the number of unknow (?) signal received.

Let $D = |p_m - p_e|$ be the absolute difference of those positions. Then let $Z = N - D$ the signals that must cancel each other.

If $Z$ is odd, then it is impossible to cancel the remaining signals, which means that the probability to reach the desired position is zero. So, from now on, assume that $Z$ is even.

Notice that either the number of positive or negative signals must be $\dfrac{Z}{2}$, and the other must be $N - \dfrac{Z}{2}$. So the number of interpretations $C$ of the signal that can get Dreamoon to the desired position is given by (it is a permutation with repetitions):
$$C = \dfrac{N!}{\frac{Z}{2}! \left(N - \frac{Z}{2}\right)!}$$

Let $A$ be the number of possible interpretations:
$$A = 2^N$$

Thus, the answer of the problem is $\dfrac{C}{A}$.

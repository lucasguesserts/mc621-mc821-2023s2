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

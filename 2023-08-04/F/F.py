"""
==================== LICENSE ====================

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>

 ==================== Solution Description ====================

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
"""

# ==================== Code ====================


def compute_final_position(command_list):
    position = 0
    for command in command_list:
        if command == "+":
            position += 1
        elif command == "-":
            position -= 1
        else:
            continue
    return position


def compute_prob(n, k):
    acc = 1
    for i in range(k):
        acc *= n - i
        acc //= i + 1
    return acc / (2**n)


def probability(initial_position, final_position, number_of_steps):
    diff = final_position - initial_position
    if abs(diff) > number_of_steps:
        return 0.0
    positives = diff if diff >= 0 else 0
    steps_to_sum_zero = number_of_steps - abs(diff)
    if steps_to_sum_zero % 2 != 0:
        return 0.0
    positives += steps_to_sum_zero // 2
    return compute_prob(number_of_steps, positives)


if __name__ == "__main__":
    commands_sent = input()
    expected_position = compute_final_position(commands_sent)
    commands_received = input()
    middle_expected_position = compute_final_position(commands_received)
    number_of_unknowns = commands_received.count("?")
    print(
        "{:.12f}".format(
            probability(middle_expected_position, expected_position, number_of_unknowns)
        )
    )

# [Noldbach problem](https://codeforces.com/problemset/problem/17/A)

Definition: Let $n \in \mathbb{N}$ be a Noldbach Number if it is a prime number and there are other two consecutive prime numbers $x, y \in \mathbb{N}$ such that $n = x + y + 1$.

The constraints of the problem are: $n \in [2, 1000]$ and $k \in [0, 1000]$.

First, we are going to compute, for all prime numbers $n <= 1000$, if it is a Noldbach Number or not. Then, given the input, it is a simple matter of counting and checking the condition.

# [Happy Happy Prime Prime](https://open.kattis.com/problems/happyprime)

Given a number $n = d_0 d_1 \cdots d_k$ in base 10, let's define its
*happy successor*

$$ s(n) = \sum_{i=0}^k d_i^2. $$

We define the *happy sequence* of $n$ as

$$ n, s(n), s(s(n)), \ldots $$

which is an infinite sequence but for some numbers it reaches the number 1.
Since $s(1) = 1$, the rest of the sequence is all 1s in such cases.

In the terms of the problem statement, a number is *happy* if its happy sequence
reaches the number 1.

__For each test case we are given a candidate $m$ and need to decide if $m$ is both
*prime* and a *happy number*.__

* Checking primality is easy and here we run a sufficiently large sieve

* Checking if a number is happy is a matter of computing the happy
sequence checking for loops other than the desired loop
$1 \rightarrow 1 \rightarrow 1 \rightarrow \cdots$

Here we use Python's `set` to store known numbers from a happy sequence.
# [Codeforces 1855B - Longest Divisors Interval](https://codeforces.com/problemset/problem/1855/B)

The [editorial of codeforces](https://codeforces.com/blog/entry/118540) (written by [TheScrasse](https://codeforces.com/profile/TheScrasse)) is quite clear in its explanation. I will copy below for the sake of availability:

## Hint 1

What's the answer if $n$ is odd?

## Hint 2

Try to generalize Hint 1.

## Hint 3

What's the answer if $n$ is not a multiple of 3?

## Hint 4

If the $n$ is not a multiple of $x$, the answer is $<x$
If the answer is a multiple of $1, \dots, x$, the answer is $\geqslant x$.

## Solution

Suppose you find a valid interval $[l, r]$ . Note that the interval $[l, r]$  contains at least one multiple of $x$ for each $1 \leqslant x \leqslant r − l + 1$ (you can find it out by looking at the values in $[l, r]$ modulo $x$). Then, the interval $[1, r − l + 1]$ is also valid and has the same length.

So, it's enough to check intervals with $l = 1$, i.e., find the smallest $x$ that does not divide $n$. The answer is $x − 1$.

Complexity: $O(log(max \ n))$

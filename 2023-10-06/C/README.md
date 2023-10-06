# [Codeforces 1791C - Prepend and Append](https://codeforces.com/problemset/problem/1791/C)

Let the string $s$ be:

$$ s = s_0 s_1 \dots s_{n-1} $$

Now one is looking for the first time in the string when characters in opposite positions are equal. Let $f$ be the function which give us the solution to the problem:

$$ f(s, b, e) = \begin{cases}
0, & \text{if } b > e \\
f(s, b+1, e-1), & \text{if } (s[b] \neq s[e]) \\
e - b + 1, & \text{otherwise}
\end{cases}$$

It is a recursive call which does not copy the string, it just searches through it. Complexity: $\mathcal{O}(n)$.

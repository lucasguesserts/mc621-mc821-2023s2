# [Codeforces 1794A - Prefix and Suffix Array](https://codeforces.com/problemset/problem/1794/A)

For each given input, let $s$ be the string (which we don't know), of size $n$.
There are excatly two proper substrings of maximum length:

* the biggest proper prefix $p$, and
* the biggest proper suffix $s$

are both of size $n-1$.

Notice that $s$ is a palindrome if, and only if, $p$ and $s$ are the reverse
of each other (say, without loff of generality, if $s = p^R$.)

Upon reading the input, we cannot determine which of the "big substrings" is
$p$ or $s$, but that doesn't make a difference.
We simply do the following

1. Read every substring, saving the two "big" ones (length $n-1$) as $p$ and $s$;
2. Answer `YES` if $p = s^R$.
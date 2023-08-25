# [Add One](https://codeforces.com/problemset/problem/1513/C)

One of the first things you may notice is that in this problem the number $n$
itself has no important "inherent" properties, and we only care about its digits (i.e.
its representation in base 10). The digits may be consider independently of each other.

In other words, consider the following example:
we wish to know the resulting length of the number 518 after applying the
operation 3 times.

We can simply compute (or look up) what are the resulting lengths of
applying the operation 3 times to the digits 5, 1, and 8. The lengths are respectively
1 (digit 5 turns into 8), 1 (digit 1 turns into 4), and 2 (digit 8 turns into 21),
summing up to a total length of 4.
(Easy to check manually: 518 -> 629 -> 7310 -> 8421.)

Imagine that we had a bidimensional table $t$ such that, for each digit $d$ from 0 to 9,
and each $m$, we would store in `t[d][m]` the result of operating $m$ times on
digit $d$, then each query would be easy to process: we would sum `t[d][m]`
for each digit $d$ of the input.

However, you may find that:
    1. such a table $t$ carries a lot of redundancy, since `t[d][m] == t[d-1][m+1]`;
    2. when computing the resulting length of digit $d$, there are two cases:
either $d+m < 10$ and the length remains 1; or $d + m \geq 10$ which means
the number 10 eventually appears in the sequence of operations.

The above ideas leads us to a more economical, unidimensional "reduced"
table $r$ such that, for each $m$, `r[m]` stores the result of applying
$m$ steps to the specific sequence `10`.

How do we compute $r$?
    * `r[m] = 2` for each $0 \leq m \leq 8", since the length is maintained;
    * `r[9] = 3`, since the resulting string is 109 (10 -> 21 -> 32 -> ... -> 98 -> 109);
    * `r[m] = r[m-9] + r[m-10]` when $m \geq 10$. This is because in the initial string
    `10`, the `1` on the left becomes a `10` after 9 operations and the `0` on
    the right becomes a `10` after 10 operations.

This allows us to compute the table and thus answer each query quickly.

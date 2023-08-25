# [Living Sequence](https://codeforces.com/problemset/problem/1811/E)

We can think of the "living sequence" $1, 2, 3, 5, 6, 7, 9, 10, 11, 12, 13, 15, \ldots$
as being a representation of every positive integer in base 9, since we are only allowed
to use 9 different digits. However, instead of the standard choice of digits
0 through 8, we are actually using 0, 1, 2, 3, 5, 6, 7, 8, 9 to represent
respectively 0, 1, 2, 3, 4, 5, 6, 7, 8.

Thus, given $k$ in decimal representation, we are asked to output $k$ in
our custom representation in base 9. This conversion takes time proportional
to the length of the representation of $k$ in base 10, i.e. $O(\log k)$, which
is adequate since $k$ can go up to $10^{12}$.

Beware: the maximum number~$k$ that can be given as input does not fit into
standard `unsigned` (32-bit). You may use `uint64_t` or other equivalent.

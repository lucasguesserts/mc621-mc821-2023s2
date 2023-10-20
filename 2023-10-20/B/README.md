# [1223B - String Equalization](https://codeforces.com/problemset/problem/1223/B)

Since the operation (making pair of characters equal) can be applied on both
$s$ and $t$ (the strings we are to make equal), the solution turns out to be
simple: so long as $s$ and $t$ have a character in common, they can be made
equal.

(Say they have `a` in common. Then both can be transformed into `aaaaa...`.)

This can be achieved in many ways within time limit, with the simplest probably
being to make a set with the contents of one of the strings and checking the
other string's characters for pertinence.

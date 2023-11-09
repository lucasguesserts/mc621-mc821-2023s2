# [Codeforces 1654 B - Prefix Removals](https://codeforces.com/problemset/problem/1654/B)

Let `s` be the input string of size `n` and `c_0` the first character. Notice that, if `c_0` repeats, then in the worst case, the longest prefix is `c_0` and it can be removed. In other words, one can remove the first letter of `s` if it repeats somewhere else in `s`.

To solve the problem, process the string from right (end) to left (beginning) and save the index of the last ocurrence of each character. Notice that such character cannot be removed. Then, take `i` as the smallest of those indices. The answer is the string `s[i..n]` (from the first character that cannot be removed to the end of the string).

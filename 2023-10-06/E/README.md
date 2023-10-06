# [Codeforces 1430E - String Reversal](https://codeforces.com/problemset/problem/1430/E)

Consider the string `s = abcafag` (as an example).

1. map where each character should be in the reverse string:
   1. `[6, 5, 4, 3, 2, 1, 0]`;
2. for each char, find the last position where it occurs and swap them;
   1. character `a`: `[6, 5, 4, 3, 2, 1, 0]` $\rightarrow$ `[1, 5, 4, 3, 2, 6, 0]`
3. compute how many swap operations a sort needs;

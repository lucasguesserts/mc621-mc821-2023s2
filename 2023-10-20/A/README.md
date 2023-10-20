# [UVa 10405 - Longest Common Subsequence](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1346)

The Longest Common Subsequence (LCS) Problem is a classic problem in Computer Science
and applications such as computational biology. The classic solution to LCS is a
$\mathcal{O}(n^2)$ Dynamic Programming.

Let $A$, of length $n$, and $B$, of length $m$, be the strings we're trying to
match.

We build a table `t` of dimensions $n+1$ by $m+1$.

`t[i][j]` stores the maximum length of a common subsequence between the first
$i-1$ members of $A$ and the first $j-1$ members of $B$.

* `t[i][j] = 0` if either `i` or `j` is zero;
* If `A[i-1] == B[j-1]`, then `t[i][j] = t[i-1][j-1] + 1`;
* Otherwise, `A[i][j]` will be the best between `A[i-1][j]` and `A[i][j-1]`.

___

We can also solve this problem by employing the Needleman-Wunsch algorithm
to find an alignment of maximum score, where we give a score of:

* `0`, for insertions and deletions
* `+1`, for a match
* `-INFINITY`, for a mismatch

(This is also a quadratic DP solution.)

___

Whatever the chosen solution, beware that an empty string is a valid line
of input. Use `getline()` instead of `cin` in `C++`.

(Python's `input()` should be agnostic to this issue.)
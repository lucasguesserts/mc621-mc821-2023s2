# [Sum in Binary Tree](https://codeforces.com/problemset/problem/1843/C)

Solving this problem requires two things:
1. Realizing that the parent of node `i` is node `i//2` (i.e., `floor(i/2)`)
2. Having the means to deal with big integers, such as using Python's `int`,
Java's `BigInt` or implementing big integers in C++

Then a recursive solution is apparent.

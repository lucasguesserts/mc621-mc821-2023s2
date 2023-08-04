# [Rebellion](https://codeforces.com/problemset/problem/1746/B)

To make the sequence non-decreasing, one simply has to move all zeros to the beginning, and the ones to the end. To do so, iteratively, one will move the first one into the last zero, until there is no zero after any one.

Example:

```plain
0: *1* 1 0 0 1 0 0 1 1 1 *0*
1: *1* 0 0 1 0 *0* 1 1 1 1
2: 0 0 *1* *0* 1 1 1 1 1
2: 0 0 1 1 1 1 1 1

3 moves required.
```

# [UVa 719 - Glass Beads](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=660)

This problem is actually easy. The only thing you need to do is to find the lexicographically smallest rotation of the string. To do so, evaluate all rotations and find the smallest one. The complexity of this algorithm is `O(n^2)` (`n` rotations, and each one requires one to create a string with size `n`).

The algorithm does not give a runtime error because the size of the strings is at most 10^4, so it takes around 10^8 operations (i.e. one second or so).

Obs: one tried to use the suffix array to solve this problem but for some reason it did not work (wrong answer).

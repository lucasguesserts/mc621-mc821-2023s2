# [Dynasty Puzzles](https://codeforces.com/contest/192/problem/C)

Dynamic Programming solution with a 26x26 table such that, for each `i` and `j,
the number stored in `[i][j]` is the maximum size of dynasty found so far
starting with letter `i` and ending with letter `j`.

In this problem, a dynasty is valid only if it starts and ends with same letter.
As such, at the end of the program we read the main diagonal of the table
looking for the maximum number.

# [Unlucky Numbers](https://codeforces.com/problemset/problem/1808/C)

[The solution](https://codeforces.com/contest/1808/submission/200077909) has been submitted by [Chromefish](https://codeforces.com/profile/Chromefish) and modified by me to make it more readable.

First, if `len(r) > len(l)`, it means that one can find a number `k` such that `l <= k <= r` and all digits of `k` are the same (e.g. `l = 123`, `r = 1234`, `k = 999`).

(The case `len(r) < len(l)` is not possible because `l <= r`).

Now consider that `len(r) == len(l)`. Let `l = l_1 l_2 ... l_n` and `r = r_1 r_2 ... r_n`. For `i = 1, ..., n`:

1. consider a number `j` in the range of valid values for the `i`-th digit: `l_i <= j <= r_i`;
2. consider `k = 0, ..., 9`, all the `10` digits that may come after the `i`-th digit;
3. create a number `x` which is the concatenation: `l_1, ..., l_{i}, j, k, k, ..., k` (the number of `k`'s is `n - i - 1`);
4. if `x` is in the range `[l, r]` and it is the best number found so far, keep it;

The above algorithm is `O(n)`, where `n` is the number of digits of `l` and `r` (notice that the loops of the steps 1 to 4 take, at most, 100 steps, i.e. a constant number of steps).

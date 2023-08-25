# [Matching](https://codeforces.com/problemset/problem/1821/A)

This problem requires counting the amount of characters `?` in the input.
Each `?` multiplies the amount of combinations by 10, except for a `?` at the
very start of the string, since leading zeroes are not considered valid.

It is also important to discard the pattern if it starts with `0` -- it is
either zero (and we're counting POSITIVE matches) or an invalid pattern.

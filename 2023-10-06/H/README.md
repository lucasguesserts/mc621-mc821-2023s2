# [Avion](https://open.kattis.com/problems/avion)

For each of the 5 lines of input we just need to check if it contains `"FBI"` as
a substring. This can be done in a number of ways:

* In Python, a native `'FBI' in input()` would suffice;
* In languages with Regular Expression libraries, use regex with pattern `"FBI"`;
* KMP algorithm: initialize the fallback table with pattern `"FBI"` and perform
a boolean search (stops at first match, returning `true`);
* Maybe even naïve search is fine, but I haven't tested.
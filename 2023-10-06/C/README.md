# [Prepend and Append](https://codeforces.com/problemset/problem/1791/C)

Given an initial binary string `s`, the two possible operations give us

* `1s0`; or
* `0s1`.

Thus, to find out the smallest possible initial string given the final
result, we simply check for how many steps we can "shave off" the extremes
of the resulting string, i.e., how many pairs of differing bits are in either
end of the string.

For instance, if the result is `101110`, then the "shedding" process gives

1. 101110
2. 0111
3. 11

This last one has differing bits in either end, so it is the smallest
string and the answer in this case is its length `2`.

Of course, there is no need to actually transform the string. We can
simply maintain two indices, one starting from index `0` and going right,
the other starting at the last index of the string and going left.

When the two indices point to equal bits, we can stop the process.

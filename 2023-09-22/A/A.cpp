// ==================== LICENSE ====================

/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
*/

// ==================== Solution Description ====================

/*
# [Codeforces 1855B - Longest Divisors Interval](https://codeforces.com/problemset/problem/1855/B)

The [editorial of codeforces](https://codeforces.com/blog/entry/118540) (written by [TheScrasse](https://codeforces.com/profile/TheScrasse)) is quite clear in its explanation. I will copy below for the sake of availability:

## Hint 1

What's the answer if $n$ is odd?

## Hint 2

Try to generalize Hint 1.

## Hint 3

What's the answer if $n$ is not a multiple of 3?

## Hint 4

If the $n$ is not a multiple of $x$, the answer is $<x$
If the answer is a multiple of $1, \dots, x$, the answer is $\geqslant x$.

## Solution

Suppose you find a valid interval $[l, r]$ . Note that the interval $[l, r]$  contains at least one multiple of $x$ for each $1 \leqslant x \leqslant r − l + 1$ (you can find it out by looking at the values in $[l, r]$ modulo $x$). Then, the interval $[1, r − l + 1]$ is also valid and has the same length.

So, it's enough to check intervals with $l = 1$, i.e., find the smallest $x$ that does not divide $n$. The answer is $x − 1$.

Complexity: $O(log(max \ n))$
*/

// ==================== Code ====================

#include <iostream>

using namespace std;

using N = long long int;

N find_smallest_divisor(N n) {
    for (N i = 1; i <= n; ++i) {
        if (n % i != 0) {
            return i - 1;
        }
    }
    return n;
}

int main() {
    N t;
    cin >> t;
    while (t--) {
        N n;
        cin >> n;
        N x = find_smallest_divisor(n);
        cout << x << endl;
    }
    return 0;
}

"""
==================== LICENSE ====================

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

 ==================== Solution Description ====================

# [Happy Happy Prime Prime](https://open.kattis.com/problems/happyprime)

Given a number $n = d_0 d_1 \cdots d_k$ in base 10, let's define its
*happy successor*

$$ s(n) = \sum_{i=0}^k d_i^2. $$

We define the *happy sequence* of $n$ as

$$ n, s(n), s(s(n)), \ldots $$

which is an infinite sequence but for some numbers it reaches the number 1.
Since $s(1) = 1$, the rest of the sequence is all 1s in such cases.

In the terms of the problem statement, a number is *happy* if its happy sequence
reaches the number 1.

__For each test case we are given a candidate $m$ and need to decide if $m$ is both
*prime* and a *happy number*.__

* Checking primality is easy and here we run a sufficiently large sieve

* Checking if a number is happy is a matter of computing the happy
sequence checking for loops other than the desired loop
$1 \rightarrow 1 \rightarrow 1 \rightarrow \cdots$

Here we use Python's `set` to store known numbers from a happy sequence."""

# ==================== Code ====================

MAX = 10000
_isprime = [True] * (MAX + 1)
_ishappy = {1: True}


def run_sieve(limit=MAX):
    global _isprime
    _isprime[0] = _isprime[1] = False
    for i in range(2, 1 + limit):
        if not _isprime[i]:
            continue
        for j in range(i * i, 1 + limit, i):
            _isprime[j] = False


def is_prime(n):
    return _isprime[n] if n <= MAX else None


def successor(n):
    return sum(map(lambda x: x * x, map(int, list(str(n)))))


def is_happy(n):
    global _ishappy
    to_check = set()
    while n not in _ishappy:
        if n in to_check:
            _ishappy[n] = False  # we found a loop!
            break
        to_check.add(n)
        n = successor(n)
    while to_check:
        _ishappy[to_check.pop()] = _ishappy[n]
    return _ishappy[n]


if __name__ == "__main__":
    run_sieve()
    for _ in range(int(input())):
        case, n = map(int, input().split())
        print(f"{case} {n} " + ("YES" if is_prime(n) and is_happy(n) else "NO"))

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

# [RATS](https://open.kattis.com/problems/rats)

The logic here is not hard: given the initial number `K` and the maximum amount
of steps `M`, we simply perform the (at most) `M` steps of the RATS operation
to obtain each following number of the sequence. At each step we are required
to check

1. If the resulting number is part of the creeper sequence
i.e. is either in the form `1233+4444` or `5566+7777`. The patterns are
described in Regular Expression, with `c+` meaning that character `c` may
have one or more appearances. Thus `1233+4444` matches `12334444`, `123334444`, `1233334444`, ...

2. If the resulting number has already appeared, constituting a cycle.

Mostly, the trouble here is implementing all of the above ingredients:

* computing a step of RATS sequence;
* checking if a number matches one of the two creeper patterns;
* storing the known values to check for repetitions.

These are more easily done using good string functions, regular expressions and
a fast table like a map or hash table."""

# ==================== Code ====================

from re import search


def next_rats(current):
    s = current + int(str(current)[::-1])
    return int("".join(sorted(list(str(s)))))


def is_creeper(n):
    pattern1, pattern2 = "^1233+4444$", "^5566+7777$"
    n_str = str(n)
    return (search(pattern1, n_str) is not None) or (
        search(pattern2, n_str) is not None
    )


def case_result(init, max_steps):
    known_terms = set()
    current = init
    i = 1
    while i <= max_steps:
        if is_creeper(current):
            return f"C {i}"
        if current in known_terms:
            return f"R {i}"
        if i < max_steps:
            known_terms.add(current)
            current = next_rats(current)
        i += 1
    return str(current)


if __name__ == "__main__":
    for _ in range(int(input())):
        case, max_steps, init = map(int, input().split())
        print(f"{case} {case_result(init, max_steps)}")

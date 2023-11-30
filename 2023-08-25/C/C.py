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

# [Sum in Binary Tree](https://codeforces.com/problemset/problem/1843/C)

Solving this problem requires two things:
1. Realizing that the parent of node `i` is node `i//2` (i.e., `floor(i/2)`)
2. Having the means to deal with big integers, such as using Python's `int`,
Java's `BigInt` or implementing big integers in C++

Then a recursive solution is apparent.
"""

# ==================== Code ====================


def solution(vertex: int) -> int:
    if vertex == 1:
        return 1
    return vertex + solution(vertex // 2)


def main():
    ncases = int(input())
    for _ in range(ncases):
        print(solution(int(input())))


if __name__ == "__main__":
    main()

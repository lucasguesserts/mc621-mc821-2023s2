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

# [Krakovia](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1866)

The solution to this problem is to sum every entry in the group of friends' tab
at the bar, obtaining a total~$T$, and outputting the truncated result of
$T/F$, with $F$ being the number of friends.

The only obstacle is that the tab entries might be large numbers, and so we
are required to deal with big integers in some way. Solutions in Python
with its native `int` type, in Java with its `BigInt`, or C++ with a custom
big integer solution, should all work fine.
"""

# ==================== Code ====================


def main():
    case = 0
    while True:
        N, F = map(int, input().split())
        if N == 0 and F == 0:
            break
        case += 1
        total = 0
        for _ in range(N):
            total += int(input())
        print(f"Bill #{case} costs {total}: each friend should pay {total//F}")
        print()


if __name__ == "__main__":
    main()

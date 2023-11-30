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

# [Kattis - Sticky Situation](https://open.kattis.com/problems/stickysituation)

Lenghts $a \leq b \leq c$ can be the sides of a proper triangle if, and only if,

$$ c < a + b .$$

To check whether our collection of sticks can form a proper triangle, we begin by sorting them by length.
Each stick starting from index 2 can be a candidate "big side" $c$. Any of the smaller sticks are possible
candidates for the small sides, but we only need to check the best candidates for the inequality above:
the sticks immediately smaller than it. (They are the biggest "small sides" available and thus if they
fail we know the others would fail as well.)

So we check wheter `stick[i] < stick[i-1] + stick[i-2]` for every stick `i` from `2` to `n-1`. """

# ==================== Code ====================


def contains_proper_triangle(lengths):
    for i in range(2, len(lengths)):
        if lengths[i] < lengths[i - 1] + lengths[i - 2]:
            return True
    return False


nsticks = int(input())
sticks = sorted(map(int, input().split()))
if contains_proper_triangle(sticks):
    print("possible")
else:
    print("impossible")

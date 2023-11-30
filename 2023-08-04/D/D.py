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

# [Make Nonzero Sum (easy version)](https://codeforces.com/problemset/problem/1753/A1)

There are two main cases:
* if `n` is odd, there is no way of segmenting to achieve zero sum.
Let k be the amount of entries equal to `-1`. Then the overall sum of the
sequence is
$(n-k) + (-1)k = n-2k$,
which is an odd number. Since changing the partitions can only flip a `-1` to
a `1` or vice-versa (thus adding or subtracting 2),
partitioning can only change the overall sum by an even amount. Thus, if
the total sum is odd, it cannot be turned to 0 by partitioning.

* if `n` is even, we can always find a solution. The following proof gives
an algorithm. Let $q$ be such that $n = 2q$. We prove by induction in q.
    - $q = 1$. Then $n = 2$ and the sequence is just two numbers $a_1, a_2$.
    If $a_1 = a_2$, then only one segment is required: $(1, 2)$, containing
    the whole array and summing to $a_1 - a_2 = 0$.
    If $a_1 \neq a_2$, we have necessarily that $a_1 = -a_2$. Then we achieve sum zero with two segments: $(1,1)$
    and $(2,2)$. The first segment sums to $a_1$ and the second sums to
    $a_2 = -a_1$.

    - Let $q > 1$ and suppose that the assertion is proved for arrays of
    size $2(q-1)$. Our array has size $2(q+1)$. We divide our array into
    two pieces: the first is $a_1, a_2$, and the second is $a_3, \ldots, a_n$.
    The second subarray has a segmentation that sums to zero by induction
    hypothesis. The first subarray is comprised of two elements and we can
    apply the same procedure described above for $n=2$.

The above proof suggests a simple algorithm that tries to group the elements
by pairs, splitting the pairs when needed. The solution is always valid,
although the number of segments can be much higher than the minimum possible.

To achieve an partition with minimum amount of parts, Dynamic Programming is
probably required.
"""

# ==================== Code ====================


def treat_case():
    n = int(input())
    if n % 2 == 1:
        input()
        print(-1)
        return
    sequence = list(map(int, input().split()))
    segments = []
    for i in range(0, n, 2):
        if sequence[i] == sequence[i + 1]:
            segments.append((i + 1, i + 2))
        else:
            segments.append((i + 1, i + 1))
            segments.append((i + 2, i + 2))
    print(len(segments))
    for l, r in segments:
        print(l, r)


def main():
    ncases = int(input())
    for _ in range(ncases):
        treat_case()


main()

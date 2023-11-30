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

# [Customising the Track](https://codeforces.com/problemset/problem/1543/B)

Consider a track like the following one: `8 3 6 11 5 2 1 7 10 4`. Our goal is to minimize the differences, or in other words, we want to distribute all cars as evenly as possible. To do so, one should follow the steps below:

1. let `n = 10` be the number of tracks;
2. compute the sum of all values: `s = 8 + 3 + 6 + 11 + 5 + 2 + 1 + 7 + 10 + 4 = 57`;
3. compute remainder `r = s % n = 57 % 10 = 7`;
4. compute the quotient (integer division) `q = s // n = 57 // 10 = 5`;
5. put `q` cars in each track, and add to the first `r` tracks one more car, to get the distribution `6 6 6 6 6 6 6 5 5 5`;
6. compute the inconvenience of the track `i` and return it;

Notice that the above procedure elucidates an easier way to compute the inconvenience of the track without having to assemble the distribution. The only pert that really matters is the remaining cars, which are put into one track each. Thus the inconvenience can be computed as the number of tracks without extra cars times the number of tracks with the extra cars:

```plain
n = get_from_input
a = get_from_input
s = sum(a_i for i in range(n))
r = s % n
i = (n - r) + r
```
"""

# ==================== Code ====================

if __name__ == "__main__":
    number_of_cases = int(input())
    for _ in range(number_of_cases):
        number_of_tracks = int(input())
        cars_in_tracks = [int(x) for x in input().split()]
        total_number_of_cars = sum(cars_in_tracks)
        remainder = total_number_of_cars % number_of_tracks
        inconvenience = (number_of_tracks - remainder) * remainder
        print(inconvenience)

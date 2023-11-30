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

# [1459A - Red-Blue Shuffle](https://codeforces.com/problemset/problem/1459/A)

This problem seems hard at first, and it would be if one had to compute the number of cases in which red or blue wins, but in the end that is not necessary. Notice that, if there are more cards in which the red number is bigger, then red has more chance of winning (if it is the blue, then blue has more chance). If, however, the number of cards for which the red number is bigger is the same as the number of cards for which the blue number is bigger, then their chances are equal. Finally, notice that cards in which the red and blue numbers are equal don't influence.

"""

# ==================== Code ====================

if __name__ == "__main__":
    number_of_test_cases = int(input())
    for _ in range(number_of_test_cases):
        number_of_cards = int(input())
        r = list(map(int, input()))
        b = list(map(int, input()))
        m = [0, 0]
        for i in range(number_of_cards):
            if r[i] > b[i]:
                m[0] += 1
            if r[i] < b[i]:
                m[1] += 1
        if m[0] > m[1]:
            print("RED")
        elif m[0] < m[1]:
            print("BLUE")
        else:
            print("EQUAL")

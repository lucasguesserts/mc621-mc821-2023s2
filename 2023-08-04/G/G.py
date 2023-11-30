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

# [Dynasty Puzzles](https://codeforces.com/contest/192/problem/C)

Dynamic Programming solution with a 26x26 table such that, for each `i` and `j`,
the number stored in `[i][j]` is the maximum size of dynasty found so far
starting with letter `i` and ending with letter `j`.

In this problem, a dynasty is valid only if it starts and ends with same letter.
As such, at the end of the program we read the main diagonal of the table
looking for the maximum number.
"""

# ==================== Code ====================

all_letters = "abcdefghijklmnopqrstuvwxyz"

# maximum_dynasty[i][j] = maximum dynasty of names starting with i and ending with j
maximum_dynasty = {c: {c: -10000000 for c in all_letters} for c in all_letters}


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        name = input()
        first_letter = name[0]
        last_letter = name[-1]
        name_length = len(name)
        # does appending improve?
        for letter in all_letters:
            maximum_dynasty[letter][last_letter] = max(
                maximum_dynasty[letter][first_letter] + name_length,
                maximum_dynasty[letter][last_letter],
            )
        # should any dynasty be replaced?
        maximum_dynasty[first_letter][last_letter] = max(
            maximum_dynasty[first_letter][last_letter], name_length
        )

    # find the maximum dynasty
    # the one in the diagonal
    m = 0
    for i in all_letters:
        m = max(m, maximum_dynasty[i][i])
    print(m)

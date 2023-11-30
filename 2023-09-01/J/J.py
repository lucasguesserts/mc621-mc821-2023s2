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

# [In Search of Truth (Easy Version)](https://codeforces.com/contest/1840/problem/G1)

Let `a1,a2,…,an` be the numbers of the sectors in clockwise order, and let the arrow initially point to the sector with number a1.

First, let's make 999 queries of `+1`, then we will know the numbers of 1000 consecutive sectors. If `n < 1000`, then the number of the first query that gives the answer `a1` is the desired `n`.

If we did not find `n`, this means that `n >= 1000`. Let's save `a1,a2,…,a1000`. Now we will make queries of `+1000` until we get one of the numbers `a1,a2,…,a1000` as the answer. Note that we will need no more than `1000` queries of this type, after which it is easy to determine the number `n`.

Thus, we can determine the number `n` in no more than `999+1000 = 1999 <= 2023` queries.

source: [Codeforces Round #878 (Div.3) Editorial](https://codeforces.com/blog/entry/117060).
"""

# ==================== Code ====================


# TEST
# comment this part of the code when submitting
class Circle:
    def __init__(self):
        self.n = int(input())
        self.values = list(map(int, input().split()))
        self.arrow = 0
        self.query_count = 0
        self.query_limit = 2023
        return

    def value(self):
        return self.values[self.arrow]

    def query(self, k):
        self.query_count += 1
        if self.query_count > self.query_limit:
            raise Exception("number of queries limit exceeded")
        self.arrow += k
        self.arrow %= self.n
        return self.value()

    def check_solution(self, n):
        if n == self.n:
            print("Success")
        else:
            raise Exception(
                "Invalid value found. Provided "
                + str(n)
                + " but correct is "
                + str(self.n)
            )
        return


# # PRODUCTION
# # uncomment this part of the code when submitting
# class Circle:
#     def __init__(self):
#         self._read_value()
#         return

#     def value(self):
#         return self.v

#     def _read_value(self):
#         self.v = int(input())
#         return

#     def query(self, k):
#         if k > 0:
#             print("+ " + str(k))
#         else:
#             print("- " + str(k))
#         self._read_value()
#         return self.value()

#     def check_solution(self, n):
#         print("! " + str(n))
#         return


# 1. in the beginning of the program, create a Circle object
# 2. to make a query, call Circle.query: it will register your query and return the value the arrow points to
# 3. create your algorithm
# 4. after you have found a solution, comment the test class and uncomment the production one (they have the same interface)

if __name__ == "__main__":
    circle = Circle()
    # make 99 queries of `+1`
    a = [circle.value()]
    a1 = a[-1]
    for i in range(999):
        a.append(circle.query(1))
        if a[-1] == a1:
            circle.check_solution(i + 1)
            exit(0)
    # n >= 1000
    queries_count = 0
    while True:
        v = circle.query(1000)
        queries_count += 1
        if v in a:
            i = a.index(v)
            circle.check_solution(1000 + 1000 * queries_count - i - 1)
            exit(0)

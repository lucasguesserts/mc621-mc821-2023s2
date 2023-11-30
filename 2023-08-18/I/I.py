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

# [Kattis roberthood - Robert Hood](https://open.kattis.com/problems/roberthood)

Ideally, one would like to compare all points with all points to find the longest distance. That would take $\mathcal{O}(n^2)$ time, which is too slow given that the size of the input is $2 \leq C \leq 10^5$.

A better approach is to do the following:

1. let $P$ be all the points;
2. compute $H$ the convex hull of $P$;
   1. this step takes $\mathcal{O}(|P| \log(|P|))$ time;
3. compare all points in $H$ to find the longest distance
   1. this step takes $\mathcal{O}(|H|^2)$ time;
   2. hopefully, $|H|$, the size of $H$, is much smaller than $|P|$, and the algorithm works;

"""


class Combinator:
    def __init__(self, n, N):
        self.n = n
        self.N = N
        self._compute_factorials()

    def combination(self, k):
        # return C(n, k) % N = n! / (k! * n_b!) % N
        return (self.factorials[self.n] * self._inv(k)) % self.N

    def _compute_factorials(self):
        self.factorials = [1]
        for i in range(1, self.n + 1):
            self.factorials.append((self.factorials[i - 1] * i) % self.N)
        return

    def _fast_power(self, b, e):
        if e == 0:
            return 1
        elif e % 2 == 0:  # e even
            x = self._fast_power(b, e / 2)
            return (x * x) % self.N
        else:  # e odd
            x = self._fast_power(b, (e - 1) / 2)
            return (x * x * b) % self.N

    def _inv(self, k):
        base = (self.factorials[self.n - k] * self.factorials[k]) % self.N
        exponent = self.N - 2
        return self._fast_power(base, exponent)


class GoodNumbers:
    def __init__(self, first: str, second: str):
        self.first = first
        self.second = second
        self.all_good_numbers = self.first + self.second

    def is_good(self, x: int):
        for digit in str(x):
            if digit not in self.all_good_numbers:
                return False
        return True


if __name__ == "__main__":
    N = 10**9 + 7
    a, b, n = input().split()
    n = int(n)
    combinator = Combinator(n, N)
    good_numbers = GoodNumbers(a, b)
    count = 0
    for k in range(n + 1):
        number_of_as = k
        number_of_bs = n - k
        sum_of_digits = number_of_as * int(a) + number_of_bs * int(b)
        if good_numbers.is_good(sum_of_digits):
            count += combinator.combination(k)
            count %= N
    print(count, end="")

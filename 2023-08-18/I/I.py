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

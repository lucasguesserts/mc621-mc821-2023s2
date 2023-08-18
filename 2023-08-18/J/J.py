import math


N = 1_000_000_007


class Fibonacci:
    def __init__(self, n):
        self._f = [0, 1]
        for i in range(2, n + 2):
            self._f.append(self._f[i - 1] + self._f[i - 2])

    def __getitem__(self, n):
        return self._f[n]

    def c(self, i, j):
        # all valid tours of length j ending in i
        # i \in {0, 1}
        # 1 <= j <= n
        return self._f[j + i]


if __name__ == "__main__":
    k, l, r = map(int, input().split())
    fibonacci = Fibonacci(r)
    acc = 0
    for n in range(l, r + 1):
        all_valid_tours = fibonacci.c(1, n) + fibonacci.c(0, n)
        tours_k_groups = math.comb(all_valid_tours, k)
        acc += tours_k_groups
    print(acc % N, end="")

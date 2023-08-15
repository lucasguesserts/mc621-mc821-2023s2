import math

BIG_NUMBER = 10**9 + 7


def is_good(n: str, good_numbers: str) -> bool:
    for i in range(len(n)):
        if n[i] not in good_numbers:
            return False
    return True


if __name__ == "__main__":
    a, b, n = input().split()
    n = int(n)
    good_numbers = a + b
    count = 0
    for i in range(n + 1):
        number_of_as = i
        number_of_bs = n - i
        sum_of_digits = number_of_as * int(a) + number_of_bs * int(b)
        if is_good(str(sum_of_digits), good_numbers):
            count += math.factorial(n) // (
                math.factorial(number_of_as) * math.factorial(number_of_bs)
            )
            count %= BIG_NUMBER
    print(count, end="")

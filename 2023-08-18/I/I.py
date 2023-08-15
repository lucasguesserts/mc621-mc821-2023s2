def is_good(n: str, good_numbers: str) -> bool:
    for i in range(len(n)):
        if (n[i] not in good_numbers):
            return False
    return True

def is_excellent(n: str, good_numbers: str) -> bool:
    s = str(sum(map(int, n)))
    return is_good(n, good_numbers) and is_good(s, good_numbers)

if __name__ == "__main__":
    a, b, n = input().split()
    n = int(n)
    good_numbers = a + b
    count = 0
    for i in range(10**(n-1), 10**(n)):
        if (is_excellent(str(i), good_numbers)):
            count += 1
    print(count, end="")

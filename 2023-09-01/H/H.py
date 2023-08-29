from random import seed, randint

def sum_of_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

def randomly_select_pair(n):
    m = randint(1, n)
    return m, n-m

def select_good_pair(n):
    while True:
        a, b = randomly_select_pair(n)
        A = sum_of_digits(a)
        B = sum_of_digits(b)
        if abs(A-B) <= 1:
            return a, b

if __name__ == '__main__':
    seed(1)
    ncases = int(input())
    for _ in range(ncases):
        n = int(input())
        a, b = select_good_pair(n)
        print(a, b)


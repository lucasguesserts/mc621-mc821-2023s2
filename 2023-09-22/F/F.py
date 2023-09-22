import sys

if sys.version_info[0] < 3:
    input_func = raw_input
else:
    input_func = input

class Matrix:
    def __init__(self, a_10, a_11):
        self.a_10 = a_10
        self.a_11 = a_11

    def prod(self, other):
        self.a_10 = self.a_10 + self.a_11 * other.a_10
        self.a_11 = self.a_11 * other.a_11
        return

    def mod(self, m):
        self.a_10 = self.a_10 % m
        self.a_11 = self.a_11 % m

def expM(A, y, m):
    # (A ^ y) % m
    if y == 0: return Matrix(0, 1)
    if y % 2 == 0:
        Z = expM(A, y//2, M)
        Z.prod(Z)
        Z.mod(m)
        return Z
    else:
        Z1 = A
        Z2 = expM(A, y-1, m)
        Z2.prod(Z1)
        Z2.mod(m)
        return Z2


if __name__ == "__main__":
    T = int(input_func())
    for t in range(T):
        a, b, n, M = map(int, input_func().split())
        if n == 0:
            print(1 % M)
            continue
        if a == 0:
            print(b % M)
            continue
        if a == 1:
            print((1 + n * b) % M)
            continue
        A = Matrix(1, a)
        AN = expM(A, n, M)
        ans = (AN.a_10 * b + AN.a_11) % M
        print(ans)

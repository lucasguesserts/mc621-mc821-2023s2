MAX_LEN = 1001  # integers modulo k have k distinct possible values
fib = [ 1, 1 ]

def first_repetition_modulo(k):
    first_appearance = [ None ]*k
    for i in range(2, len(fib)):
        value = fib[i] % k
        if first_appearance[value] is not None:
            return first_appearance[value]
        first_appearance[value] = i
    return -1

if __name__ == '__main__':
    while len(fib) < MAX_LEN:
        fib.append(fib[-1] + fib[-2])
    for _ in range(int(input())):
        print(first_repetition_modulo(int(input())))

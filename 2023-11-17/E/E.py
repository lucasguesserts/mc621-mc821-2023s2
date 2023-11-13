if __name__ == '__main__':
    while True:
        a, b, c = sorted(map(int, input().split()))
        if (a, b, c) == (0, 0, 0):
            break
        if c*c == a*a + b*b:
            print('right')
        else:
            print('wrong')

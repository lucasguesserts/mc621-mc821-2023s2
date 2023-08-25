def main():
    case = 0
    while True:
        N, F = map(int, input().split())
        if N == 0 and F == 0:
            break
        case += 1
        total = 0
        for _ in range(N):
            total += int(input())
        print(f'Bill #{case} costs {total}: each friend should pay {total//F}')
        print()

if __name__ == '__main__':
    main()

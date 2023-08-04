def treat_case():
    n = int(input())
    if n % 2 == 1:
        input()
        print(-1)
        return
    sequence = list(map(int, input().split()))
    segments = []
    for i in range(0,n,2):
        if sequence[i] == sequence[i+1]:
            segments.append((i+1, i+2))
        else:
            segments.append((i+1, i+1))
            segments.append((i+2, i+2))
    print(len(segments))
    for (l, r) in segments:
        print(l, r)

def main():
    ncases = int(input())
    for _ in range(ncases):
        treat_case()

main()

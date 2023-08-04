def solve(n, k):
    s = ''
    center = n//2 
    if k != center:
        diff = center-k-1
        if k > center:
            diff = k-center-1
            s += 'LDLU'*diff + 'L' + 'DR' # coloca alvo no nicho superior direito
            s += 'URDR'*(n//2 - 1 - min(k-center, n-2-k))
            s += 'LDRU'
            diff = 0
        s += 'RDRU'*diff + 'R'
    s += 'DL'
    return s

def main():
    n, k = map(int, input().split())
    print(solve(n,k))

main()

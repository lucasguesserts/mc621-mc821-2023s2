def solve(n, k):
    p = n - 2
    f = 1
    m = (p + 1) / 2
    b = m - 1
    a = m + 1
    l = p
    if k == m:
        return "DL"
    elif f <= k <= b:
        return "L" + (k - 1) * "DRUL"
    else:
        return "R" + (l - k) * "DLUR" + p * "URDR" + "LDRURDL"


if __name__ == "__main__":
    n, k = map(int, input().split())
    solution = solve(n, k)
    print(solution)

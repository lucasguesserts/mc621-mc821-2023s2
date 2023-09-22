def egcd(a, b):
    r = [a, b]
    s = [1, 0]
    t = [0, 1]
    q = [None, None]
    while r[-1] != 0:
        q.append(r[-2] // r[-1])
        r.append(r[-2] % r[-1])
        s.append(s[-2] - q[-1] * s[-1])
        t.append(t[-2] - q[-1] * t[-1])
    return r, s, t, s


def p(r, s, t, q):
    a = r[0]
    b = r[1]
    x = s[-2]
    y = t[-2]
    g = r[-2]
    print(f"gcd({a}, {b}) = {g}")
    print(f"{x} * {a} + {y} * {b} = {g} ({a*x+b*y == g})")
    print(f"")


if __name__ == "__main__":
    ans = egcd(1914, 899)
    p(*ans)

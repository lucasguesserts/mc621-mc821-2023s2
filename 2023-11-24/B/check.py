def get_points():
    l = []
    while True:
        try:
            x, y = map(int, input().split())
            l.append((x, y))
        except EOFError:
            break
    return l

def cross_product(A):
    X1 = (A[1][0] - A[0][0])
    Y1 = (A[1][1] - A[0][1])
    X2 = (A[2][0] - A[0][0])
    Y2 = (A[2][1] - A[0][1])
    return (X1 * Y2 - Y1 * X2)

def check_convex(points):
    N = len(points)
    prev = 0
    curr = 0
    for i in range(N):
        temp = [points[i], points[(i + 1) % N], points[(i + 2) % N]]
        curr = cross_product(temp)
        if (curr != 0):
            if (curr * prev < 0):
                raise Exception("not convex")
            else:
                prev = curr

    return

def check_all_distinct(l):
    if len(set(l)) != len(l):
        raise Exception("not all distinct")
    return

def check_no_collinear(l):
    for a, b, c in zip(l, l[1:], l[2:]):
        alpha = (a[1] - b[1]) / (a[0] - b[0])
        y_ = alpha * (c[0] - b[0]) + b[1]
        if abs(c[1] - y_) < 0.00001:
            raise Exception("collinear points")
    return

def check_valid_range(l):
    MIN = 0
    MAX = 40_000_000
    for p in l:
        if MIN <= p[0] <= MAX and MIN <= p[1] <= MAX:
            continue
        else:
            raise Exception("invalid range")
    return


if __name__ == "__main__":
    l = get_points()
    try:
        check_all_distinct(l)
        check_valid_range(l)
        check_convex(l)
        check_no_collinear(l)
    except Exception as e:
        print(e)
    else:
        print("OK")


def dist(p, q):
    return ((p[0] - q[0])**2 + (p[1] - q[1])**2)**.5

if __name__ == '__main__':
    location = [ None for i in range(10) ]
    for i in range(3):
        row = list(map(int, input().split()))
        for j in range(3):
            location[row[j]] = (i, j)

    total_dist = 0.0
    for i in range(1, 9):
        total_dist += dist(location[i], location[i+1])

    print(total_dist)

# https://codeforces.com/contest/1808/submission/200077909


def get_cost(a):
    return int(max(a)) - int(min(a))

number_of_test_cases = int(input())
for test_case_index in range(number_of_test_cases):
    l, r = input().split()
    if len(r) > len(l):
        print("9" * len(l))
    else:
        n = len(l)
        ans = l
        for i in range(n):
            for j in range(int(l[i]), int(r[i]) + 1):
                for k in range(10):
                    x = l[:i] + str(j) + str(k) * (n - i - 1)
                    if (l <= x <= r) and (get_cost(x) < get_cost(ans)):
                        ans = x
        print(ans)

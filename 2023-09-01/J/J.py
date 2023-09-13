# TEST
# comment this part of the code when submitting
class Circle:
    def __init__(self):
        self.n = int(input())
        self.values = list(map(int, input().split()))
        self.arrow = 0
        self.query_count = 0
        self.query_limit = 2023
        return

    def value(self):
        return self.values[self.arrow]

    def query(self, k):
        self.query_count += 1
        if self.query_count > self.query_limit:
            raise Exception("number of queries limit exceeded")
        self.arrow += k
        self.arrow %= self.n
        return self.value()

    def check_solution(self, n):
        if (n == self.n):
            print("Success")
        else:
            raise Exception("Invalid value found. Provided " + str(n) + " but correct is " + str(self.n))
        return

# # PRODUCTION
# # uncomment this part of the code when submitting
# class Circle:
#     def __init__(self):
#         self._read_value()
#         return

#     def value(self):
#         return self.v

#     def _read_value(self):
#         self.v = int(input())
#         return

#     def query(self, k):
#         if k > 0:
#             print("+ " + str(k))
#         else:
#             print("- " + str(k))
#         self._read_value()
#         return self.value()

#     def check_solution(self, n):
#         print("! " + str(n))
#         return


# 1. in the beginning of the program, create a Circle object
# 2. to make a query, call Circle.query: it will register your query and return the value the arrow points to
# 3. create your algorithm
# 4. after you have found a solution, comment the test class and uncomment the production one (they have the same interface)

if __name__ == "__main__":
    circle = Circle()
    # make 99 queries of `+1`
    a = [circle.value()]
    a1 = a[-1]
    for i in range(999):
        a.append(circle.query(1))
        if a[-1] == a1:
            circle.check_solution(i + 1)
            exit(0)
    # n >= 1000
    queries_count = 0
    while True:
        v = circle.query(1000)
        queries_count += 1
        if v in a:
            i = a.index(v)
            circle.check_solution(1000 + 1000*queries_count - i - 1)
            exit(0)



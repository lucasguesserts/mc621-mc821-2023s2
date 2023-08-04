def find_last_index(l, obj, end):
    i = end - 1
    while i >= 0:
        if l[i] == obj:
            return i
        else:
            i -= 1
    return None

def find_first_index(l, obj, start):
    i = start + 1
    while i < len(l):
        if l[i] == obj:
            return i
        else:
            i += 1
    return None

class Sequence:
    def __init__(self, a):
        self.a = a
        self.first_one = find_first_index(self.a, 1, -1)
        self.last_zero = find_last_index(self.a, 0, len(self.a))
        self.moves_count = 0
        self._solve()
        return

    def _make_move(self):
        self.moves_count += 1
        self.a[self.last_zero] = 1
        del self.a[self.first_one]
        self.first_one = find_first_index(self.a, 1, self.first_one - 1)
        self.last_zero = find_last_index(self.a, 0, self.last_zero - 1)
        return

    def _solve(self):
        while (self.first_one is not None) and (self.last_zero is not None) and (self.first_one < self.last_zero):
            self._make_move()
        return

if __name__ == "__main__":
    number_of_cases = int(input())
    for _ in range(number_of_cases):
        n = int(input())
        a = [int(x) for x in input().split()]
        s = Sequence(a)
        print(s.moves_count)

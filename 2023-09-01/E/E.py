if __name__ == "__main__":
    number_of_test_cases = int(input())
    for _ in range(number_of_test_cases):
        number_of_cards = int(input())
        r = list(map(int, input()))
        b = list(map(int, input()))
        m = [0, 0]
        for i in range(number_of_cards):
            if r[i] > b[i]:
                m[0] += 1
            if r[i] < b[i]:
                m[1] += 1
        if m[0] > m[1]:
            print("RED")
        elif m[0] < m[1]:
            print("BLUE")
        else:
            print("EQUAL")

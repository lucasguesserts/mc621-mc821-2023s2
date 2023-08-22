all_letters = "abcdefghijklmnopqrstuvwxyz"

# maximum_dynasty[i][j] = maximum dynasty of names starting with i and ending with j
maximum_dynasty = {c: {c: -10000000 for c in all_letters} for c in all_letters}


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        name = input()
        first_letter = name[0]
        last_letter = name[-1]
        name_length = len(name)
        # does appending improve?
        for letter in all_letters:
            maximum_dynasty[letter][last_letter] = max(
                maximum_dynasty[letter][first_letter] + name_length,
                maximum_dynasty[letter][last_letter],
            )
        # should any dynasty be replaced?
        maximum_dynasty[first_letter][last_letter] = max(
            maximum_dynasty[first_letter][last_letter], name_length
        )

    # find the maximum dynasty
    # the one in the diagonal
    m = 0
    for i in all_letters:
        m = max(m, maximum_dynasty[i][i])
    print(m)

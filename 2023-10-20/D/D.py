# adapted from https://codeforces.com/blog/entry/68534

if __name__ == '__main__':
    s = input()
    n_w = 0
    n_wo = 0
    n_wow = 0
    prev_char = ''
    currente_char = ''
    for currente_char in s:
        if currente_char == 'o':
            n_wo += n_w
        elif currente_char == 'v' and prev_char == 'v':
            n_w += 1
            n_wow += n_wo
        prev_char = currente_char
    print(n_wow, end="")


from re import search

def next_rats(current):
    s = current + int(str(current)[::-1])
    return int(''.join(sorted(list(str(s)))))

def is_creeper(n):
    pattern1, pattern2 = '^1233+4444$', '^5566+7777$'
    n_str = str(n)
    return (search(pattern1, n_str) is not None) or (search(pattern2, n_str) is not None)

def case_result(init, max_steps):
    known_terms = set()
    current = init
    i = 1
    while i <= max_steps:
        if is_creeper(current):
            return f'C {i}'
        if current in known_terms:
            return f'R {i}'
        if i < max_steps:
            known_terms.add(current)
            current = next_rats(current)
        i += 1
    return str(current)

if __name__ == '__main__':
    for _ in range(int(input())):
        case, max_steps, init = map(int, input().split())
        print(f'{case} {case_result(init, max_steps)}')

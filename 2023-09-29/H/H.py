MAX = 10000
_isprime = [ True ]*(MAX+1)
_ishappy = { 1 : True }

def run_sieve(limit = MAX):
    global _isprime
    _isprime[0] = _isprime[1] = False
    for i in range(2, 1+limit):
        if not _isprime[i]:
            continue
        for j in range(i*i, 1+limit, i):
            _isprime[j] = False

def is_prime(n):
    return _isprime[n] if n <= MAX else None

def successor(n):
    return sum(map(lambda x : x*x, map(int, list(str(n)))))

def is_happy(n):
    global _ishappy
    to_check = set()
    while n not in _ishappy:
        if n in to_check:
            _ishappy[n] = False     # we found a loop!
            break
        to_check.add(n)
        n = successor(n)
    while to_check:
        _ishappy[to_check.pop()] = _ishappy[n]
    return _ishappy[n]

if __name__ == '__main__':
    run_sieve()
    for _ in range(int(input())):
        case, n = map(int, input().split())
        print(f'{case} {n} ' + ('YES' if is_prime(n) and is_happy(n) else 'NO'))

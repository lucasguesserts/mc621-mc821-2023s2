def intlog(num:int, base:int)->int:
    steps = 0
    while num >= base:
        num //= base
        steps += 1
    return steps
 
def solve_case():
    initial_n, split_number, maximum_n = map(int, input().split())
    print(intlog(maximum_n//initial_n, split_number))
 
def main():
    ncases = int(input())
    for _ in range(ncases):
        solve_case()
 
if __name__ == '__main__':
    main()
 

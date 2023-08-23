def solution(vertex: int)->int:
    if vertex == 1:
        return 1
    return vertex + solution(vertex//2)
 
def main():
    ncases = int(input())
    for _ in range(ncases):
        print(solution(int(input())))
 
if __name__ == '__main__':
    main()

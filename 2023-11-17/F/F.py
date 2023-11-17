def contains_proper_triangle(lengths):
    for i in range(2, len(lengths)):
        if lengths[i] < lengths[i-1] + lengths[i-2]:
            return True
    return False

nsticks = int(input())
sticks = sorted(map(int, input().split()))
if contains_proper_triangle(sticks):
    print('possible')
else:
    print('impossible')

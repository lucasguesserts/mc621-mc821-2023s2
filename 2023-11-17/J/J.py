from math import sqrt

# returns the area of triangle with sides of lengths a, b, c
def triangle_area(a, b, c):
    s = (a + b + c)/2
    return sqrt(s*(s-a)*(s-b)*(s-c))

# returns the radius of the circumcircle of triangle with sides of lengths a, b, c
def r_circumcircle(a, b, c):
    return a*b*c/(4*triangle_area(a, b, c))

# returns true if triangle is obtuse, supposing side lengths a <= b <= c
def is_obtuse(a, b, c):
    return c*c > (a*a + b*b)

nholes = int(input())
holes = [float(x) for x in input().split()]
npegs = int(input())
pegnames = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
for i in range(npegs):
    a, b, c = sorted(map(float, input().split()))
    minimum_diameter = c if is_obtuse(a, b, c) else 2*r_circumcircle(a, b, c)
    fits = [ str(j+1) for j in range(nholes) if holes[j] >= minimum_diameter ]
    print(f'Peg {pegnames[i]} will', end=' ')
    if fits == []:
        print('not fit into any holes')
    else:
        print('fit into hole(s): ' + ' '.join(fits))


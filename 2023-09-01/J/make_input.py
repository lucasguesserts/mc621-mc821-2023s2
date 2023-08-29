import random

with open("in.txt", "w") as file:
    n = random.randint(1, 1000000)
    a = list(range(1, n + 1))
    random.shuffle(a)
    print(n, file=file)
    for x in a:
        print(str(x) + " ", file=file, end="")

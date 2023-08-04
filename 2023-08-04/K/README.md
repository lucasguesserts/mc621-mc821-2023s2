# [Luke is a Foodie](https://codeforces.com/problemset/problem/1704/B)

Consider the following input:

```plain
8 2
2 7 8 9 6 13 21 28
```

Let's map each number into two numbers: the lower and upper bound accepted for Luke to eat it:

```plain
2 -> [0, 4]
7 -> [5, 9]
8 -> [6, 10]
9 -> [7, 11]
6 -> [4, 8]
13 -> [11, 15]
21 -> [19, 23]
28 -> [26, 30]
```

Consider a lower bound `l = -oo` and an upper bound `u = +oo`, which define a range `[l, u]` of valid values for the food affinity. Initially, `l = -oo` and `u = +oo`. Now, for the range `[fl, fu]` of each food, we have two cases:

1. there is an intersection between the ranges, so choose `l = max{l, fl}` and `u = min{u, fu}`;
2. the intersection of the ranges is empty. For this case, one will need to reset the food affinity, so one will reset the bounds to `l = -oo` and `u = +oo`;

See the following example:

```plain
initialization: l = -oo, u = +00
2 -> [0, 4] -> l = 0, u = 4
7 -> [5, 9] -> incompatible with the current range
REINITIALIZE BOUNDS
initialization: l = -oo, u = +00
7 -> [5, 9] -> l = 5, u = 9
8 -> [6, 10] -> l = 6, u = 9
9 -> [7, 11] -> l = 7, u = 9
6 -> [4, 8] -> l = 7, u = 8
13 -> [11, 15] -> incompatible with the current range
REINITIALIZE BOUNDS
initialization: l = -oo, u = +00
13 -> [11, 15] -> l = 11, u = 15
21 -> [19, 23] -> incompatible with the current range
REINITIALIZE BOUNDS
initialization: l = -oo, u = +00
21 -> [19, 23] -> l = 19, u = 23
28 -> [26, 30] -> incompatible with the current range
REINITIALIZE BOUNDS
initialization: l = -oo, u = +00
28 -> [26, 30] -> l = 26, u = 30
```

In the end, the number of times the bounds were reset is the answer to the problem.

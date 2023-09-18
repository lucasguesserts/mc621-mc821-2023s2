# [10489 - Boxes of Chocolates](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1430)

The first problem is to understand the input.

Basically, each line which describes a box, one has to multiply all the values to get the total amount of chocolate.

For instance, the input:

```
7 3
6 8 9 3 4 100 98
7 87 64 23 12 88 44 99
3 65 48 76
```

means that each box of chocolate has the following content:

1. the box 1-th contains 8 boxes, which contains 9 boxes, which contains 3 boxes, which contains 4 boxes, which contains 100 boxes, which contains 98 chocolates; Total = 8467200 = prod([8 9 3 4 100 98])
2. ...
3. the box 3-th contains 65 boxes, which contains 48 boxes, which contains 76 chocolates; Total: 237120 chocolates;

The other relevant part of the problem is that, at each computation, one has to take the mudulo by $n$, so that there is no overflow.

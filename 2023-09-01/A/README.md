# [Game with Board](https://codeforces.com/problemset/problem/1841/A)

## `n = 2`

```plain
1 1 <- Alice
2 <- Bob
```

Bob wins.

## `n = 3`

```plain
1 1 1 <- Alice
2 1 <- Bob

or

1 1 1 <- Alice
3 <- Bob
```

In all cases, Bob wins.

## `n = 4`

```plain
1 1 1 1 <- Alice
4 <- Bob

or

1 1 1 1 <- Alice
3 1 <- Bob

or

1 1 1 1 <- Alice
2 1 1 <- Bob
2 2 <- Alice
4 <- Bob
```

In all cases, Bob wins.

## `n >= 5`

```plain
1 1 ... 1 <- Alice
n-2 1 1 <- Bob
n-2 2 <- Alice
```

Alice can win in all cases if she plays optimally (which, by hypothesis, is the case). Thus, Alice wins.

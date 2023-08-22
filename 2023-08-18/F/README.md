# [Archer](https://codeforces.com/problemset/problem/312/B)

Let:

* `a/b`: be the probability that **SmallR** shoots the target;
* `c/d`: be the probability that **Zanoes** shoots the target;
* `p`: the probability that **SmallR** wins;

Since SmallR starts, its probability `p` of winning is:

> p = (SmallR shoots the target) OR (SmallR misses the target AND Zanoes misses the target AND SmallR shoots the target) OR (SmallR misses the target two times AND Zanoes misses the target two times AND SmallR shoots the target) OR ...

Which can be converted in the following calculation:

```plain
p = a/b + (1-a/b)*(1-c/d)*a/b + (1-a/b)^2*(1-c/d)^2*a/b + ...
  = (a/b) * sum_{i = 0 ... +oo}[(1-a/b)^i * (1-c/d)^i]
```

That is the infinite sum of a Geometric Progression with first term equals to `a/b` and ratio equals to `(1-a/b)*(1-c/d)`. Thus:

```plain
a1 = a/b
q = (1-a/b)*(1-c/d)
p = a1 / (1 - q)
```


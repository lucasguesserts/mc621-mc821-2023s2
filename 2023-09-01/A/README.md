# [12114 - Bachelor Arithmetic](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3266)

```plain
if (B == 1)
    print :-\

before = min(1, S/B)
after = min(1, (S-1)/(B-1))

if (after < before)
    print :-(
if (after > before)
    print :-)
if after == before
    print :-|
```

Yes, it is that simple!


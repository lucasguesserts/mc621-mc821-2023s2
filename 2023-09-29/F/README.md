# [RATS](https://open.kattis.com/problems/rats)

The logic here is not hard: given the initial number `K` and the maximum amount
of steps `M`, we simply perform the (at most) `M` steps of the RATS operation
to obtain each following number of the sequence. At each step we are required
to check

1. If the resulting number is part of the creeper sequence
i.e. is either in the form `1233+4444` or `5566+7777`. The patterns are
described in Regular Expression, with `c+` meaning that character `c` may
have one or more appearances. Thus `1233+4444` matches `12334444`, `123334444`, `1233334444`, ...

2. If the resulting number has already appeared, constituting a cycle.

Mostly, the trouble here is implementing all of the above ingredients:

* computing a step of RATS sequence;
* checking if a number matches one of the two creeper patterns;
* storing the known values to check for repetitions.

These are more easily done using good string functions, regular expressions and
a fast table like a map or hash table.
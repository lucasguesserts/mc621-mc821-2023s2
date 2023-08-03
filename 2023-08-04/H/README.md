# [Customising the Track](https://codeforces.com/problemset/problem/1543/B)

Consider a track like the following one: `8 3 6 11 5 2 1 7 10 4`. Our goal is to minimize the differences, or in other words, we want to distribute all cars as evenly as possible. To do so, one should follow the steps below:

1. let `n = 10` be the number of tracks;
2. compute the sum of all values: `s = 8 + 3 + 6 + 11 + 5 + 2 + 1 + 7 + 10 + 4 = 57`;
3. compute remainder `r = s % n = 57 % 10 = 7`;
4. compute the quotient (integer division) `q = s // n = 57 // 10 = 5`;
5. put `q` cars in each track, and add to the first `r` tracks one more car, to get the distribution `6 6 6 6 6 6 6 5 5 5`;
6. compute the inconvenience of the track `i` and return it;

Notice that the above procedure elucidates an easier way to compute the inconvenience of the track without having to assemble the distribution. The only pert that really matters is the remaining cars, which are put into one track each. Thus the inconvenience can be computed as the number of tracks without extra cars times the number of tracks with the extra cars:

```plain
n = get_from_input
a = get_from_input
s = sum(a_i for i in range(n))
r = s % n
i = (n - r) + r
```

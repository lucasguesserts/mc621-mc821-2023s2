# [Kattis - Brownie Points I](https://open.kattis.com/problems/browniepoints)

Straightforward linear algorithm that checks each point's position relative to center.

1. Read the $n$ points into vector `P`;
2. Central point `r` is `P[n/2]`;
3. For each point `p` in `P`:
    - if `p` has either same `x` or `y` as central point `r`, it doens't count;
    - otherwise, if `p.x` and `p.y` are either BOTH GREATER or BOTH LESSER than `r.x` and `r.y` respectively, Stan scores;
    - otherwise, Ollie scores.
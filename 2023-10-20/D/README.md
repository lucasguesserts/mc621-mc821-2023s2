# [Codeforces 1178/B - WOW Factor](https://codeforces.com/problemset/problem/1178/B)

keep three counts:

1. $n_{w}$: number of previous "w";
2. $n_{wo}$: number of previous "wo";
3. $n_{wow}$: number of previous "wow";

Now start from the beginning of the string:

1. if you find a $o$, then $n_{wo}$, the number of "wo", must be increased by $n_{w}$, the number of previous "w";
2. if you find a $w$ (i.e. both the current and the previous characters are a $v$), then the $n_{w}$, number of "w", must be increased by 1 and $n_{wow}$, the number of "wow", must be increased by the number of previous "wo";

The solution is $n_{wow}$ by the end of the algorithm. Complexity: $\mathcal{O}(n)$.

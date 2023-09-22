# [Codeforces 1359E - Modular Stability](https://codeforces.com/contest/1359/problem/E)

The array is stable if and only if all of its elements are multiple of its minimum.

1. select a minimum $m < n$;
2. there are $c = \left\lfloor\dfrac{n}{m}\right\rfloor$ candidate elements;
3. choose $k - 1$ out of $c - 1$ elements (the other element is $m$);
   1. this gives $\mathcal{C}_{c-1}^{k-1} = \dfrac{(c-1)!}{(k-1)! (c-k)!}$
   2. if $c < k$, then it is impossible to find a solution with the selected minimum;

## References

- [Codeforces tutorial](https://codeforces.com/blog/entry/78116)

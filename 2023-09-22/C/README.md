# [UVA 10127 - Ones](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1068)

The algorithm is very simple: for $k = 1, \dots$, check if the number $11\dots1$ ($k$ digits $1$) is multiple of $n$. If it is, output $k$.

One have to observe how to proceed with the computations though. Let $v_k$ be the value with $k$ ones. To compute $v_{k+1}$, one must do:

$$v_{k+1} = (10 \cdot v_k + 1) \% n$$

i.e. compute the modulo at every step.

## References

- <https://codingstrife.wordpress.com/2013/07/28/solution-uva10127-pc110504-ones/>

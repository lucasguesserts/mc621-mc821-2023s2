# [Codeforces 1244C - The Football Season](https://codeforces.com/problemset/problem/1244/C)

## Problem Data

1. Input: $n, p, w, d \in \Z_+$
   1. $1 \leqslant n  \leqslant 10^{12}$
   2. $1 \leqslant p \leqslant 10^{17}$
   3. $1 \leqslant d < w \leqslant 10^{5}$
2. Output: $x, y, z \in \Z_+$
   1. Constraints:
      1. $wx + dy = p$
      2. $x + y + z = n$

## Computing $z$

$$
x + y + z = n
\quad\leftrightarrow\quad
z(x, y) = n - x - y
$$

So, if one computes $x$ and $y$, one can find $z$.

## Computing $y$

$$
wx + dy = p
\quad\leftrightarrow\quad
y(x) = \dfrac{p - wx}{d}
$$

Thus, if one computes $x$, one can find $z$.

## Computing $x$

### Initial Value

We want to find an $x$ such that $y = \dfrac{p - wx}{d}$ is integer. With some calculations, one finds that such $x$ must satisfy:

$$
p - wx \equiv 0 \quad (mod \ d)
\quad\leftrightarrow\quad
p \equiv wx \quad (mod \ d)
$$

such condition, in programming languages, we would write as:

```plain
(p % d) == ((w % d) (x % d)) % d
```

Since $1 \leqslant d < 10^{5}$, we can test all values of $x$ from $0$ to $d-1$. We will call $0 \leqslant x_0 \leqslant d$ the first value which satisfy the above condition.

Other values can be found with the function $x(s) = x_0 + ds, s \in \Z_+$.

If such value does not exist, then the problem does not have a solution.

### Constraint 1 of $x$

One must have:

$$x(s) + y(x(s)) \leqslant n$$

With some calculations, one finds that:

$$s \geqslant \dfrac{dn - x_0(w - d) + p}{d(w - d)}$$

So one can select:

$$
s_n
=
\left\lceil
    \dfrac
        {dn - x_0(w - d) + p}
        {d(w - d)}
\right\rceil
$$

### Constraint 2 of $x$

One must have:

$$w x(s) \leqslant p$$

With some calculations, one finds that:

$$s \leqslant \dfrac{p - w x_0}{wd}$$

So one can select:

$$
s_p
=
\left\lfloor
    \dfrac
        {p - w x_0}
        {wd}
\right\rfloor
$$

## Solution

Select $s = \min(s_n, s_p)$ and then compute $x = x_0 + ds$. With $x$, compute $y$, and with it, compute $z$. Finally, check if all values are positive. If yes, then that is a valid answer. If not, then there is no $x, y, z$ which satisfy the conditions of the problem.


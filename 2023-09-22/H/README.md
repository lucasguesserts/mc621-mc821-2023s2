# [UVa 10090 - Marbles](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1031)

1. Input:
   1. $n \in \mathbb{N}$ marbles;
   2. Box type 1:
      1. holds $n_1 \in \mathbb{N}$ marbles;
      2. costs $c_1 \in \mathbb{R}_+$;
   2. Box type 2:
      1. holds $n_2 \in \mathbb{N}$ marbles;
      2. costs $c_2 \in \mathbb{R}_+$;
2. Output:
   $$
    \begin{array}{ll}
        \min & c_1 m_1 + c_2 m_2\\
        s.t. & n_1 m_1 + n_2 m_2 = n
    \end{array}
   $$

## Linear Diophantine Equation with Two Unknowns

Let $d = gcd(n_1, n_2)$. Notice that

$$n_1 x + n_2 y = n$$

has a solution if and only if $d$ divides $n$, i.e. $n \text{ mod } d = 0$. In this case, define:

$$t = \dfrac{n}{d}$$

Let $x, y \in \mathbb{Z}$ be the solutions of

$$n_1 x + n_2 y = d$$

Thus:

$$n_1 t x + n_2 t y = t d = n$$

and so $x_0$ and $y_0$ are solutions of

$$
n_1 x_0 + n_2 y_0 = n \\
x_0 = tx \\
y_0 = ty
$$

And any other solution is of the form:

$$
\begin{array}{rcl}
    x' &=& x_0 + \dfrac{n_2}{d} k \\\\
    y' &=& y_0 - \dfrac{n_1}{d} k
\end{array}
$$

However, we want both $x', y'$ to be positive. Applying such conditions, we get:

$$
k_{\min} = - \dfrac{x n}{n_2} \leqslant k \leqslant \dfrac{y n}{n_1} = k_{\max}
$$

So, any $k \in [k_{\min}, k_{\max}]$ give us a valid solution for the problem.

## Optimization

Let $p_1 = \dfrac{n_1}{c_1}$ and  $p_2 = \dfrac{n_2}{c_2}$. If $p_1 \geqslant p_2$, then it is worth buying as many boxes of type 1 as possible. In such case, we want to choose $k = k_{\max}$. In the case $p_1 < p_2$, we want to choose $k = k_{\min}$. Thus:

$$
k = \begin{cases}
    \left\lfloor \dfrac{y n}{n_1} \right\rfloor, p_1 \geqslant p_2 \\\\
    \left\lceil - \dfrac{x n}{n_2} \right\rceil, p_1 < p_2
\end{cases}
$$

$$
m_1 = t x + \dfrac{n_2}{d} k
$$

$$
m_2 = t y - \dfrac{n_1}{d} k
$$

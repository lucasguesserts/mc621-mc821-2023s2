# [SPOJ REC - Recurrence](https://www.spoj.com/problems/REC/)

## Expression Expansion Approach

$$
\begin{array}{rcl}
f_0 &=& 1\\
f_1 &=& a + b\\
f_2 &=& a^2 +ab +b\\
f_3 &=& a^3 +a^2b + ab +b\\
&\dots&\\
f_j &=& a^j + \displaystyle\sum\limits_{i=1}^{j} a^{j-i}b
= a^j + b \left( \displaystyle\sum\limits_{i=0}^{j-1} a^{i} \right)
&\dots&\\
f_n &=& a^n + b \left( \displaystyle\sum\limits_{i=0}^{n-1} a^{i} \right)
\end{array}
$$

Notice that $\displaystyle\sum\limits_{i=0}^{n-1} a^{i}$ is a geometric progression with first $x_1$ term equals $1$ and ratio $q$ equals $a$. Using the GP sum equation below:

$$
S_n = x_1\ \dfrac{q^n -1}{q - 1}
$$

Then:

$$
\displaystyle\sum\limits_{i=0}^{n-1} a^{i}
=
\dfrac{a^n - 1}{a - 1}
$$

Finally, we get an expression for $f_n$:

$$
f_n = a^n + b \ \dfrac{a^n - 1}{a - 1}
$$

But now we face the problem of computing $f_n \% M$. The complicated part is to handle the $(a - 1)^{-1}$, and we cannot use the multiplicative inverse of the mod because it is not guaranteed that $\text{gcd}(a - 1, M) = 1$.

## Matrix Approach

Notice that one can write the recursion in the matrix format:

$$
\left[
\begin{array}{cc}
    1 & 0 \\
    1 & a
\end{array}
\right]
\left[
\begin{array}{c}
    b \\
    f_{j-1}
\end{array}
\right]
=
\left[
\begin{array}{c}
    b \\
    f_{j}
\end{array}
\right]
$$

So the solution for the problem is:

$$
\left[
\begin{array}{cc}
    1 & 0 \\
    1 & a
\end{array}
\right]^n

\left[
\begin{array}{c}
    b \\
    1
\end{array}
\right]
=
\left[
\begin{array}{c}
    b \\
    f_{n}
\end{array}
\right]
$$

This problem can thus be solved using Matrix exponentiation and mod:

### Multiplication

$$
\left[
\begin{array}{cc}
    1 & 0 \\
    x_{10} & x_{11}
\end{array}
\right]
\left[
\begin{array}{cc}
    1 & 0 \\
    y_{10} & y_{11}
\end{array}
\right]
=
\left[
\begin{array}{cc}
    1 & 0 \\
    x_{10} + x_{11} y_{10} & x_{11} y_{11}
\end{array}
\right]
$$

### Mod

$$
\left[
\begin{array}{cc}
    1 & 0 \\
    x_{10} & x_{11}
\end{array}
\right]
\% M
=
\left[
\begin{array}{cc}
    1 & 0 \\
    x_{10} \% M & x_{11} \% M
\end{array}
\right]
$$

### Exponentiation with Mod

$$
A^n \% M
=
\begin{cases}
Id \% M &,& n = 0 \\
0 &,& A = 0 \\
((A^{n/2} \% M) \cdot (A^{n/2} \% M)) \% M &,& n \text{ is even} \\
((A \% M) \cdot (A^{n - 1} \% M)) \% M &,& n \text{ is odd} \\

\end{cases}
$$

where $Id = \left[\begin{array}{cc}1 & 0 \\ 0 & 1\end{array}\right]$ is the identity matrix.

### Complexity

This solution takes $\mathcal{O}(\log n)$ computational time.

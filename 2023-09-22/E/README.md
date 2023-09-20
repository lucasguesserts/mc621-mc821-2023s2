# [Codeforces 1475E. Advertising Agency](https://codeforces.com/problemset/problem/1475/E)

Let:

1. $n,k \in \N$ with $k \leqslant n$;
2. $A = \left\langle a_1, \dots, a_n \right\rangle$;
3. $M = 10^9 + 7$;

Define $A'$ as $A$ sorted in weakly decreasing order:

$$
A' = \left\langle a'_1, \dots, a'_n \right\rangle
\quad\text{ with }
a'_i \geqslant a'_j \text{ when } i < j
\text{ (weakly decreasing) }
$$
If the problem was to take the best $k$ bloggers, one would simply take the first $k$ entries of $A'$. But one has to consider all the different possibilities which give the same impact.

It might be the case that there are many bloggers with $a'_k$ followers. Let's then break down $A'$ into two parts $F$ and $S$:

$$
F = \{a \in A' \ | \ a > a'_k\}
$$

$$
S = \{a \in A' \ | \ a = a'_k\}
$$

$F$ is our set of fixed bloggers, those which must be present for the choice to be optimal, and $S$ are the ones we can select since they have the same number of followers $a'_k$.

One has $\phi = k - |F|$ bloggers to select among $\sigma = |S|$ ones. Thus one can find the solution $x$ of the problem as being:

$$
x = \mathcal{C}_{\sigma}^{\phi} = \dfrac{\sigma!}{(\sigma - \phi)! \ \phi!}
$$

Fot the modulo:

$$
x \% M
=
\mathcal{C}_{\sigma}^{\phi} \% M
=
\sigma! \% M \ (\sigma - \phi)!^{-1} \ \phi!^{-1}
$$

where $y^{-1}$ is the modular inverse of $y$.

For the program, one can compute $\sigma! \% M$ in $\mathcal{O}(\sigma)$ time (store all values in a vector, computing the mod $M$ at each iteration), and with that result one can compute the other two modular inverses.

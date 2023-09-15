# [Prsteni](https://open.kattis.com/problems/prsteni)

Imagine a point on the surface of the first ring. After one rotation, it has moved a distance equals to $2 \pi r_0$. Now imagine a point on the surface of the second ring. It will also move a distance equals to $2 \pi r_0$. How much is it in terms of angular movement? It is $\dfrac{2 \pi r_0}{2 \pi r_1} = \dfrac{r_0}{r_1}$.

For the other rings, it is exactly the same computation.

The problem ask one to compute the fraction in the reduced form. For that, one has to compute the greatest common divisor $g$ of both the numerator $r_0$ and denominator $r_i$, and then the answer is $\dfrac{r_0}{g}\Big/\dfrac{r_i}{g}$.


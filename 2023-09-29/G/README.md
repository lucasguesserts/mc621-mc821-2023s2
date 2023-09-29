# [12464 - Professor Lazy, Ph.D.](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=733&page=show_problem&problem=3907)

The sequence is:

0. $a$
1. $b$
2. $\dfrac{1 + b}{a}$
3. $\dfrac{1 + \dfrac{1+b}{a}}{b} = \dfrac{a + b + 1}{ab}$
4. $\dfrac{1 + \dfrac{a+b+1}{ab}}{\dfrac{1+b}{a}} = \dfrac{a + 1}{b}$
5. $\dfrac{1 + \dfrac{a+1}{b}}{\dfrac{a+b+1}{ab}} = a$
6. $\dfrac{1 + a}{\dfrac{1 + a}{b}} = b$
7. $\dots$

Thus we only have to compute the first 5 values. Let $m = n \% 5$. Then $Q_n = Q_m$.


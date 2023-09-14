# [10179 - Irreducable Basic Fractions](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=1120&mosmsg=Submission+received+with+ID+28767712)

## The Real Problem

At first, the problem seems easy to solve: given $n \in \mathbb{N}$, take the numbers $[0, n - 1] \subset \mathbb{N}$ and remove the ones which are multiples of the prime factors of $n$.

Doing it by brute force is not viable, that would require too many computations. But one just need to count, and that seems easy too: given the prime factor $p$ of $n$, the quantity of number in $[0, n - 1]$ which are multiples of $p$ is $\left\lfloor \dfrac{n - 1}{p} \right\rfloor$. Thus, counting those and subtracting from $n-1$ is enough, right?

Unfortunately, no, it is not. Given two prime factors $p_x, p_y$, with such procedure one would subtract the multiples of $p_x p_y$ twice. But even if one considers that, given another prime factor $p_z$, the multiples of $p_x p_y p_z$ would not be counted (they would be removed twice).

The solution for the problem is simple: let $n = p_1^{e_1} \cdot \dots p_k^{e_k}$. Any time one gets an odd number of prime factors, one will subtract the number of multiples of the least common multiple. And any time one gets an even number of prime factors, one will add.

The idea is that with the odd we are discarding the multiples considered twice (but we are also discarding some multiples twice), and with the even we are correcting the calculation.

## Algorithm

Let $n \in \mathbb{N}$ as in the statement of the problem. The algorithm is as follows:

1. compute the prime factorization of $n$:

   $$ n = p_1^{e_1} \cdot \dots p_k^{e_k} $$

2. get the set of such prime numbers:

   $$ s = \{ p_1, \dots, p_k \} $$

3. get the power set of those prime numbers:

   $$ S = \mathcal{P}(s) $$

4. for each set of $S$, compute the signed number of multiples that the least common factor of the numbers in $s$ have up to $n-1$:

   $$ M = \{(-1)^{|s|} \ \left\lfloor \dfrac{n - 1}{lcm(s)} \right\rfloor : s \in S\} $$

   1. for the set $s = \{e_1, \dots, e_j\}$, we have $lcm(s) = lcm(e_1, \dots, e_j)$, the least common multiple of all elements of the set $s$;
   2. $(-1)^{|s|}$ is equals to $1$ when $s$ has an even number of elements, and $-1$ when it has an odd number of elements;
   3. $\left\lfloor \dfrac{x}{y} \right\rfloor$ is the number of multiples of $y$ smaller or equals $x$ that exist;
5. compute the number of irreducible basic fractions as:

   $$ c = n - 1 + \displaystyle\sum\limits_{m \in M} v $$

   1. $n$ because there are $n$ valid fractions;
   2. $-1$ because $\frac{1}{n}$ is not considered a irreducible basic fractions;
   3. the terms $m \in M$ correspont to the multiples of the prime factors of $n$;

Some boundary conditions:

1. if `n == 1`, give `1` as answer;

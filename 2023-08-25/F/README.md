# [ATOMS - Atoms in the Lab](https://www.spoj.com/problems/ATOMS/)

When an atom splits, it ceases to be 1 atom and turns into $K$ atoms.
Since there are $N$ atoms at first, the number of atoms after $T$ seconds will
be $N K^T$. We want to know the maximum value $T$ such that $N K^T \leq M$.

Thus, we want $T$ to be the integer log of $M/N$ on base $K$.
This requires being able to divide, multiply and compare big integers.

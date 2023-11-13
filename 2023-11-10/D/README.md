# [Platforme](https://open.kattis.com/problems/platforme)

There are at most $100$ platforms and the time limit is $1 s$, which means that a naive implementation which visits every platform for every platform is enough.

The algorithm becomes very simple then:

1. Initialize $L = 0$, the total length of pillars needed to support all the platforms;
2. Add a platform to represent the floor: $G = \left\langle 0, 0, LIMIT \right\rangle$ (use $LIMIT = 10000$);
3. For each platform $p = \left\langle y, x_i, x_f \right\rangle$:
   1. Skip it if $y = 0$;
   2. Let $c = \left\langle y, x \right\rangle$ be the cell where the a pillar will be placed;
   3. Find a platform $p' = \left\langle y', x_i', x_f' \right\rangle$ which satisfy: $x_i' \leq x \leq x_f'-1$, $y' < y$ and $y'$ is the maximum possible;
   4. Increase $L$ by $y - y'$;
   5. Do the above procedure for the cell $\left\langle y, x_i \right\rangle$, and $\left\langle y, x_f - 1 \right\rangle$;

Notice that one has to be careful with the $-1$ in some places...

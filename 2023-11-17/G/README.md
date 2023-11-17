# [Kattis - Sanic](https://open.kattis.com/problems/sanic)

Sanic is a small unitary circle rolling against the inner wall of a big circle of radius $r \geq 1.1$.

When rolling, Sanic's center has a trajectory which is a circle concentric to the big circle and whose radius is $r-1$.
Since Sanic has no drag, his center travels as much as any fixed point of his circumference.

![Image showing a small (unitary) circle inside of big circle of radius r. When the small circle rolls inside the bigger one, its center describes a circle of radius r-1 concentric to the big circle.](./sanic.svg)

When Sanic completes the lap, his center will have travelled a distance of

$$ \Delta s = 2\pi(r-1) .$$

But each time Sanic's center travels $2\pi$ units, he will have completed one rotation, since by then
any fixed point in his circumference will have travelled around the whole circumference.

Hence, the amount of rotations he will perform is exactly

$$r-1.$$
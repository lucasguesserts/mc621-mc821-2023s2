# [Biggest Slice](https://open.kattis.com/problems/biggest)

The problem is actually simple:

1. mark the angles of each cut;
2. sort the angles;
3. compute the differences;
4. find the biggest difference;
5. compute the area for the biggest difference:
   $$ A = \pi r^2 \dfrac{\alpha}{2\pi} = \dfrac{r^2 \alpha}{2} $$
   where $\alpha$ is the angle of the biggest difference;

There are a few catches though:

1. when computing the differences, add an entry equals to `FULL_ROTATION - (last_angle - first_angle)`, being `last_angle, first_angle` the angles of the sorted differences. This is necessary because one may fully rotate the pizza many times;
2. if `n == 0`, then the area of the biggest slice is `PI * r * r`;
3. if `n == 1`, then the area of the biggest slice is still `PI * r * r`;

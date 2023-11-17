# [All Different Directions](https://open.kattis.com/problems/alldifferentdirections)

The problem is straight-forward: compute the final position for each person asked, take the average (componentwise), and then for each final position, compute the distance to the average value computed.

For this implementation, one used complex values (because the complex set is isomorphic to $\mathbb{R}^2$):

* Positions are represented by a complex value;
* Angles can be converted to a complex value using: $c = \cos(\theta) + i \sin(\theta)$;
* To rotate a complex number (rotate the angle being faced) by $\alpha$, multiply it by $c = \cos(\alpha) + i \sin(\alpha)$;
* To walk a distance $d$, simply add $d \cdot a$ to the current position, where $a$ is the current angle being faced (as a complex number);

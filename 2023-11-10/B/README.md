# [Kattis - Logo](https://open.kattis.com/problems/logo)

This is a simple matter of simulating the commands and checking the distance
between the starting and final positions. For simplicity, we may consider the
initial position as being the origin and the initial angle as being zero.

To be more explicit, we start with `current_x = current_y = 0.0` and `current_angle = 0`.
(We may store the angle, in degrees, as an integer.)

When we read a command in the form `comm argument`, then:

* if `comm` is a displacement (either forward or backward), then `argument` is
the magnitude (hypothenuse) of the movement, and we update `current_x` and `current_y`
accordingly: by increasing (or decreasing) them by `argument*cos(theta)` and `argument*sin(theta)`
respectively, where `theta` is the `current_degree` in radians;

* if `comm` is a turn, then we simply update `current_angle` accordingly (increasing for
right turn, decreasing for left turn).
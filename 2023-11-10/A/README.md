# [Curse the Darkness](https://open.kattis.com/problems/cursethedarkness)

Let $b_x, b_y \in \mathbb{R}_+$ be the coordinates of the book and $c_x, c_y \in \mathbb{R}_+$ be the coordinates of a candle. If there is a candle for which $\sqrt{(b_x - c_x)^2 + (b_y - c_y)^2} \leq 8$, then output `light a candle`. Otherwise, output `curse the darkness`.

Complexity: $\mathcal{O}(n)$ where $n$ is the number of candles.

Obs: read all the input even if you find a value for which the condition above holds.

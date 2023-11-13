# [Kattis - Unlock Pattern](https://open.kattis.com/problems/unlockpattern)

First we read the input storing a map (really a simple array suffices) of positions.
For instance, the example input

```
6 1 9
5 2 8
4 3 7
```

would be mapped as

* `pos[1] = (0, 1)`
* `pos[2] = (1, 1)`
* ...
* `pos[9] = (0, 2)`

where you'll notice we are treating the positions as 0-based matrix indices.

Then we simply go from one point to the next, accumulating the euclidean distance to output later.

We don't even have to worry about presentation here. The answer is judged not by textual diff but numerically by checking whether

`abs(given_output - correct_answer) < EPS`

for `EPS = 1e-6`.
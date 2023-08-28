# [542 - France '98](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=483)

The idea is to create a tree structure for the championship. In each node, one will store a list of countries, each one of them with its probability to reach that stage.

The way one combines two nodes is by considering the match between all countries of one node against all countries of the other node. Given:

* country `A` with probability `p_A`of being in that stage;
* country `B` with probability `p_B`of being in that stage;
* `p_AB` the probability that `A` wins against `B`;

then the probability that `A` is in the next stage is `sum_{B in the other node} p_A * p_B * p_AB`. In that way one can compute, for each country in the two nodes, the probability of being in the next stage.


```plain
[(Argentina, 0.87), (Brazil, 0.95)]--|
                                     |--[(Argentina, 0.64), (Brazil, 0.82), (Chile, 0.49), (Denmark, 0.12)]
[(Chile, 0.76), (Denmark, 0.25)]-----|
```

For storing and processing all that information, one can use a list of lists and, at each step, combine two adjacent lists. In the end, there will be one list containing all the countries.

The last thing required is to initialize the data. One can accomplish that by creating a list in which each element is a list containing a single country with probability `1.0`.

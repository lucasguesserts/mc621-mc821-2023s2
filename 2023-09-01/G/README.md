# [106 miles to Chicago](https://www.spoj.com/problems/CHICAGO/)

We want to find a maximum cost path in the graph.
Can be done modifying Dijktra or Floyd-Warshall algorithms.

Needed modifications:

* Instead of compounding edge values by addition, compound by multiplying;
* Instead of minimizing the total value (cost) of the path, maximize the
total value (probability).



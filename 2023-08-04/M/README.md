# [Toy Machine](https://codeforces.com/problemset/problem/1817/D)

First we note that the answer is not required to be optimal (e.g. minimize number of steps).

We consider three cases.

* The first case is when the target toy that we want to put in the leftmost place is directly above
the central obstacle. In this case, we simply go "DL" (Down, Left) in order for it to be placed correctly.

* The second case is when the target toy is to the left of the central obstacle.
We aim to reduce this to the above case by going "RDRU" (Right, Down, Right, Up) however many
times needed for the target toy to end up in the central position by going "R" one more time.

* The third case is when the target toy is to the right of the central obstacle.
In this case, we further break down into three movements in order to get into the second case.
    - First, we position the target toy in the *rightmost* place (i.e. directly opposed to the desired position)
    - Then, we make sure every toy is to the right of the central obstacle (filling the top and bottom rows in this
    region)
    - Finally, we go "LDRU" and then the target toy will be placed directly above the central obstacle by going "R" one final time.

Both the second case and the steps of the third case must be reflected upon by toying with the [simulation](https://assets.codeforces.com/files/56ff21637146a30d/game.html) that is provided.

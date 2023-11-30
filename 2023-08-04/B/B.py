"""
==================== LICENSE ====================

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>

 ==================== Solution Description ====================

# [Tree Master](https://codeforces.com/problemset/problem/1806/E)

This mostly just requires storing the tree and performing the described
computation algorithm efficiently enough.

The challenge here is the fact that for each instance there may be a large
number of queries. As such, and considering that `f(x,y)` is dependent on
`f(p(x),p(y))` i.e. the computation for the parents of `x` and `y`, we employ
memoization.

This requires having a table that stores for each `x` and `y` *that are on the
same level on the tree* the result of `f(x,y)` if it has already been
computed.

Moreover, we do *not* want to store pairs for a level of the tree if said level
has $\Theta(n)$ nodes, since this yields $\Theta(n^2)$ pairs, which is too costly.
A strategy that can be employed is to store pairs only of levels populated by
at most $\sqrt{n}$ nodes, resulting in $n$ pairs to be stored.

"""

# ==================== Code ====================

import math


class Node:
    def __init__(self, weight):
        self._weight = weight
        self._parent = None
        self._depth = None
        return

    @property
    def weight(self):
        return self._weight

    @property
    def parent(self):
        return self._parent

    @parent.setter
    def parent(self, parent):
        self._parent = parent
        self._depth = parent.depth + 1
        return

    @property
    def depth(self):
        return self._depth

    @depth.setter
    def depth(self, depth):
        self._depth = depth
        return


class Tree:
    def __init__(self, weights, parents):
        self.nodes = [Node(w) for w in weights]
        self.nodes[0].depth = 0
        for node, parent in zip(self.nodes[1:], parents):
            node.parent = self.nodes[parent]
        self.f_values = {}
        self._number_of_nodes_in_depth_threshold = math.sqrt(len(self.nodes))
        return

    def f(self, node_x, node_y):
        if (node_x is None) or (node_y is None):
            return 0
        node_x, node_y = sorted([node_x, node_y], key=lambda node: id(node))
        if node_x.depth > self._number_of_nodes_in_depth_threshold:
            return (node_x.weight * node_y.weight) + self.f(
                node_x.parent, node_y.parent
            )
        else:
            key = (node_x, node_y)
            if key not in self.f_values:
                self.f_values[key] = (node_x.weight * node_y.weight) + self.f(
                    node_x.parent, node_y.parent
                )
            return self.f_values[key]


if __name__ == "__main__":
    n, q = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    p = [int(x) - 1 for x in input().split()]
    tree = Tree(a, p)
    for _ in range(q):
        x, y = [int(x) - 1 for x in input().split()]
        node_x = tree.nodes[x]
        node_y = tree.nodes[y]
        print(tree.f(node_x, node_y))

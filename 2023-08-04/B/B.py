class Node:
    def __init__(self, weight):
        self._weight = weight
        self._parent = None
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
        return

class Tree:
    def __init__(self, weights, parents):
        self.nodes = [Node(w) for w in weights]
        for node, parent in zip(self.nodes[1:], parents):
            node.parent = self.nodes[parent]
        self.f_values = {}
        return

    def f(self, node_x, node_y):
        if node_x is None or node_y is None:
            return 0
        key = (node_x, node_y)
        if key not in self.f_values:
            self.f_values[key] = (node_x.weight * node_y.weight) + self.f(node_x.parent, node_y.parent)
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

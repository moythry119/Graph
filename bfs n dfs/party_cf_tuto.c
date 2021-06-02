We let an employee without a manager called as root. There's an edge from a manager to an employee that he/she manages.

First notice that the graph is a collection of directed trees. Hence, we can assign a depth label to each node - denoting the number of nodes on the simple path from the root to it. The answer is then the maximum depth a node has.

Why?

First, the answer is bounded below by this number because any pair of employees in this path cannot be in the same group. Second, since the graph is a tree, each node in the graph has a unique depth label assigned to it. Simply put all nodes with the same depth in the same group. It's fairly easy to see that no one will be the superior of another within a group, for otherwise their depths will not be equal.


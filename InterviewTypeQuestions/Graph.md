# Graph
## 1. Find If Graph is Tree:
Use Total Nodes = 2(Leaves - 1) [Handshaking Lemma]

## 2. Find If Graph is symmetric:
We simply need to check if both the child of root node are same individual trees.
```
Symmetric
     1
   /   \
  2     2
 / \   / \
3   4 4   3

Not Symmetric
    1
   / \
  2   2
   \   \
   3    3
```
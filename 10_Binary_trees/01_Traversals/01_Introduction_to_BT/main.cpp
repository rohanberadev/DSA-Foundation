#include <bits/stdc++.h>
using namespace std;

int countNodes(int i) { return 1 << (i - 1); }

// Link -
// https://bit.ly/3EsRmTM
// https://www.youtube.com/watch?v=_ANrF3FJm7I&ab_channel=takeUforward

/*

Full Binary Tree
- Either has 0 or 2 children.

          O
        /   \
       O     O
     /   \
    O     O

--------------------------------------------------------------------------

Complete Binary Tree
- All levels are compeletely filled except the last level.

          O
        /   \
       O     O
      / \   / \
     O   O O   O

--------------------------------------------------------------------------

Perfect Binary Tree
- All leaf nodes are at same level.

          O
        /   \
       O     O
      / \   / \
     O   O O   O

--------------------------------------------------------------------------

Balanced Binary Tree
- Height of tree at max of log(n).

n = 8
log(8) = 3 (at base 2).

         O
        / \
       O   O
      /
     O

--------------------------------------------------------------------------

Degenerate Tree or Skew Tree
- Every node has a single children.

         O
        /
       O
      /
     O

*/
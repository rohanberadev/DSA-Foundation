#include <bits/stdc++.h>
using namespace std;

// Time :- O(N)
// Space :- O(1)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (p == nullptr && q == nullptr) {
    return true;
  }

  if (p == nullptr)
    return false;
  if (q == nullptr)
    return false;
  if (p->val != q->val)
    return false;

  bool left = isSameTree(p->left, q->left);
  bool right = isSameTree(p->right, q->right);

  return left && right;
}

// Link -
// https://leetcode.com/problems/same-tree/
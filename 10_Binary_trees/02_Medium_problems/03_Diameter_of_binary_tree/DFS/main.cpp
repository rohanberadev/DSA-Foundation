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

int dfsheight(TreeNode *root, int &diameter) {
  if (root == nullptr) {
    return 0;
  }

  int lh = dfsheight(root->left, diameter);
  int rh = dfsheight(root->right, diameter);
  diameter = max(diameter, lh + rh);

  return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode *root) {
  int diameter = 0;
  dfsheight(root, diameter);
  return diameter;
}

// Link -
// https://leetcode.com/problems/diameter-of-binary-tree/
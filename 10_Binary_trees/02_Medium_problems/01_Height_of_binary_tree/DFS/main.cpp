#include <bits/stdc++.h>
using namespace std;

// Time :- O(N)
// Space :- O(height of BT)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

int maxDepth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  return 1 + max(lh, rh);
}

// Link -
// https://leetcode.com/problems/maximum-depth-of-binary-tree/